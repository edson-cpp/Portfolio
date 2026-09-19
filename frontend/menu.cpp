#include "frontend/menu.hpp"
#include "frontend/i18n/i18n.hpp"
#include "frontend/router.hpp"

#include <string>
#include <vector>
#include <emscripten/val.h>

extern "C" void routeChanged();
bool skinOutsideClickSetup = false;

namespace
{
    std::string languageFlag()
    {
        if (I18n::language() == I18n::Language::Portuguese)
            return "assets/img/usa_flag.png";

        return "assets/img/br_flag.png";
    }

    std::string languageName()
    {
        if (I18n::language() == I18n::Language::Portuguese)
            return "English";

        return "Português";
    }

    std::string currentPath()
    {
        return emscripten::val::global("window")
            ["location"]
            ["pathname"]
            .as<std::string>();
    }

    void changeSkin(std::string const& file)
    {
        auto document = emscripten::val::global("document");
        auto skinCss = document.call<emscripten::val>(
            "getElementById", 
            std::string{"skin-css"}
        );

        skinCss.set(
            "href",
            "/assets/css/skins/" + file
        );

        auto localStorage = document["defaultView"]["localStorage"];

        localStorage.call<void>(
            "setItem",
            std::string{"portfolio-skin"},
            file
        );
    }
    
    std::string savedSkin()
    {
        auto document = emscripten::val::global("document");

        auto localStorage = document["defaultView"]["localStorage"];

        auto value = localStorage.call<emscripten::val>(
            "getItem",
            std::string{"portfolio-skin"}
        );

        if (value.isNull() || value.isUndefined())
            return "yellow.css";

        return value.as<std::string>();
    }

    void loadSavedSkin()
    {
        auto document = emscripten::val::global("document");

        auto skinCss = document.call<emscripten::val>(
            "getElementById",
            std::string{"skin-css"}
        );

        skinCss.set(
            "href",
            "/assets/css/skins/" + savedSkin()
        );
    }

    void toggleSkinPanel()
    {
        auto document = emscripten::val::global("document");

        auto panel = document.call<emscripten::val>(
            "getElementById",
            std::string{"skin-panel"}
        );

        panel["classList"].call<void>(
            "toggle",
            std::string{"skin-panel-visible"}
        );
    }

    void toggleMobileSkinPanel()
    {
        auto document = emscripten::val::global("document");

        auto panel = document.call<emscripten::val>(
            "getElementById",
            std::string{"mobile-skin-panel"}
        );

        panel["classList"].call<void>(
            "toggle",
            std::string{"hidden"}
        );
    }
}

Nui::ElementRenderer Menu::desktopNavItem(MenuItem const& item)
{
    using namespace Nui::Attributes;

    auto itemClass = std::string{
        "desktop-nav-element cursor-pointer w-50 h-50 relative "
        "flex items-center transition duration-300 my-20 mx-0 "
        "rounded-full bg-black-2"};
    if (item.isActive)
        itemClass += " active";

    return Nui::Elements::li{
        Nui::Attributes::class_ = itemClass,
        Nui::Attributes::onClick = [path = item.path]() {
            navigateTo(path);
        }
    }(
        Nui::Elements::i{
            Nui::Attributes::class_ = "fa " + item.desktopIconClass +
                " absolute left-0 right-0 mx-auto block text-center top-15 pointer-events-none text-fs-19"
        }(),
        Nui::Elements::div{
            Nui::Attributes::class_ = "group block p-0 w-50 h-50"
        }(
            Nui::Elements::h2{
                Nui::Attributes::class_ = "absolute text-center -z-10 block h-50 pr-25 pl-30 text-fs-15 right-0 opacity-0 text-white "
                    "leading-lh-50 font-medium transition-all duration-300 rounded-30 group-hover:opacity-100 "
                    "group-hover:right-27 group-hover:rounded-tl-30 group-hover:rounded-bl-30 "
                    "group-hover:rounded-tr-none group-hover:rounded-br-none"
            }(
                I18n::tr(item.translationKey)
            )
        )
    );
}

Nui::ElementRenderer Menu::mobileNavItem(MenuItem const& item)
{
    using namespace Nui::Attributes;

    auto itemClass = std::string{"mobile-nav-element relative pl-30"};
    if (item.isActive)
        itemClass += " active home-link";

    return Nui::Elements::li{
        Nui::Attributes::class_ = itemClass,
        Nui::Attributes::onClick = [path = item.path]() {
            navigateTo(path);
        }        
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "uppercase delay-2000 no-underline relative text-fs-26 xs:text-fs-18 py-14"
        }(
            Nui::Elements::i{
                Nui::Attributes::class_ = "fa " + item.mobileIconClass
            }(),
            Nui::Elements::span{
                Nui::Attributes::class_ = "absolute left-50 xs:left-35 font-normal"
            }(
                I18n::tr(item.translationKey)
            )
        )
    );
}

Nui::ElementRenderer Menu::render()
{
    using namespace Nui::Attributes;

    loadSavedSkin();

    const auto path = currentPath();

    std::vector<MenuItem> menuItems{
        {"menu.home", "fa-home", "fa-home", "/"},
        {"menu.about", "fa-user", "fa-user", "/about"},
        {"menu.portfolio", "fa-briefcase", "fa-folder-open", "/portfolio"},
        {"menu.contact", "fa-envelope-open", "fa-envelope-open", "/contact"},
        {"menu.blog", "fa-comments", "fa-comments", "/blog"}
    };

    std::vector<Nui::ElementRenderer> desktopItems;
    std::vector<Nui::ElementRenderer> mobileItems;
    desktopItems.reserve(menuItems.size());
    mobileItems.reserve(menuItems.size());

    for (auto& item : menuItems)
    {
        item.isActive = item.path == path;

        desktopItems.push_back(desktopNavItem(item));
        mobileItems.push_back(mobileNavItem(item));
    }
    desktopItems.push_back(desktopLanguageItem());
    mobileItems.push_back(mobileLanguageItem());
    desktopItems.push_back(desktopSkinItem());
    mobileItems.push_back(mobileSkinItem());

    return Nui::Elements::header{
        Nui::Attributes::id = "navbar-collapse-toggle",
        Nui::Attributes::class_ = "header from-lg:fixed from-lg:right-30 from-lg:bottom-0 from-lg:z-30 from-lg:flex "
            "from-lg:items-center from-lg:h-[calc(100vh-200px)] from-lg:top-100 from-lg:opacity-100 "
            "from-lg:transition from-lg:duration-300 from-lg:[&.hide-header]:z-0 "
            "from-lg:[&.hide-header]:opacity-0"
    }(
        Nui::Elements::ul{
            Nui::Attributes::id = "desktop-nav",
            Nui::Attributes::class_ = "icon-menu down-lg:hidden from-md:block uppercase"
        }(
            desktopItems
        ),
        Nui::Elements::nav{
            Nui::Attributes::class_ = "hidden down-md:block relative"
        }(
            Nui::Elements::div{
                Nui::Attributes::id = "menuToggle",
                Nui::Attributes::class_ = "fixed top-30 right-30 z-50 select-none pt-19 pl-16 w-54 h-54 rounded-5 bg-black-3 "
                    "xs:right-15 xs:top-4 xs:pb-13 xs:w-49 xs:h-49"
            }(
                Nui::Elements::input{
                    Nui::Attributes::id = "inputmobile",
                    Nui::Attributes::type = "checkbox",
                    Nui::Attributes::class_ = "h-54 w-54 absolute top-0 left-0 opacity-0 z-20 cursor-pointer peer"
                }(),
                Nui::Elements::span{
                    Nui::Attributes::class_ = "flex h-0.5 w-23 mb-5 relative bg-white z-10 rounded-3 origin-0 custom-transition "
                        "peer-checked:rotate-45 peer-checked:translate-x-1 peer-checked:translate-y-0"
                }(),
                Nui::Elements::span{
                    Nui::Attributes::class_ = "flex h-0.5 w-23 mb-5 relative bg-white z-10 rounded-3 origin-0-100 custom-transition "
                        "peer-checked:opacity-0 peer-checked:scale-0-2"
                }(),
                Nui::Elements::span{
                    Nui::Attributes::class_ = "flex h-0.5 w-23 mb-5 relative bg-white z-10 rounded-3 origin-0-100 custom-transition "
                        "peer-checked:-rotate-45 peer-checked:translate-x-2 peer-checked:translate-y-2"
                }(),
                Nui::Elements::ul{
                    Nui::Attributes::id = "mobile-nav",
                    Nui::Attributes::class_ = "fixed m-0 left-0 top-0 w-full h-full pt-60 bg-black-3 -translate-x-full ease-menu-mobile "
                        "duration-500 peer-checked:transform-none [&>li]:cursor-pointer [&>li]:after:absolute "
                        "[&>li]:after:h-px [&>li]:after:w-[calc(100%-60px)] [&>li]:after:bg-black-4 "
                        "[&>li]:after:left-30 [&>li:last-child]:after:hidden"
                }(
                    mobileItems
                )
            )
        )
    );
}

Nui::ElementRenderer Menu::desktopLanguageItem()
{
    return Nui::Elements::li{
        Nui::Attributes::class_ =
            "desktop-nav-element cursor-pointer w-50 h-50 relative flex items-center "
            "transition duration-300 my-20 mx-0 rounded-full bg-black-2",
        Nui::Attributes::onClick = []() {
            if (I18n::language() == I18n::Language::Portuguese)
                I18n::setLanguage(I18n::Language::English);
            else
                I18n::setLanguage(I18n::Language::Portuguese);

            routeChanged();
        }            
    }(
        Nui::Elements::img{
            Nui::Attributes::src = languageFlag(),
            Nui::Attributes::style =
                "width: 32px; height: 24px; object-fit: contain;",
            Nui::Attributes::class_ =
                "absolute left-0 right-0 mx-auto block top-14 pointer-events-none"
        }(),
        Nui::Elements::div{
            Nui::Attributes::class_ = "group block p-0 w-50 h-50"
        }(
            Nui::Elements::h2{
                Nui::Attributes::class_ =
                    "absolute text-center -z-10 block h-50 pr-25 pl-30 "
                    "text-fs-15 right-0 opacity-0 text-white "
                    "leading-lh-50 font-medium transition-all duration-300 "
                    "rounded-30 group-hover:opacity-100 "
                    "group-hover:right-27 "
                    "group-hover:rounded-tl-30 group-hover:rounded-bl-30 "
                    "group-hover:rounded-tr-none group-hover:rounded-br-none"
            }(
                languageName()
            )
        )
    );
}

Nui::ElementRenderer Menu::mobileLanguageItem()
{
    return Nui::Elements::li{
        Nui::Attributes::class_ =
            "mobile-nav-element relative pl-30 cursor-pointer",

        Nui::Attributes::onClick = []() {
            if (I18n::language() == I18n::Language::Portuguese)
                I18n::setLanguage(I18n::Language::English);
            else
                I18n::setLanguage(I18n::Language::Portuguese);

            routeChanged();
        }
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ =
                "uppercase delay-2000 no-underline relative text-fs-26 xs:text-fs-18 py-14"
        }(
            Nui::Elements::img{
                Nui::Attributes::src = languageFlag(),
                Nui::Attributes::style =
                    "width: 32px; height: 24px; object-fit: contain; left: -7px",
                Nui::Attributes::class_ =
                    "absolute top-15 pointer-events-none"
            }(),
            Nui::Elements::span{
                Nui::Attributes::class_ = "font-normal",

                Nui::Attributes::style =
                    "display: inline-block; "
                    "margin-left: 35px;"
            }(
                languageName()
            )
        )
    );
}

Nui::ElementRenderer Menu::desktopSkinItem()
{
    using namespace Nui::Attributes;

    std::vector<Skin> skins{
        {I18n::tr("menu.skin_item_yellow"), "yellow.css", "yellow"},
        {I18n::tr("menu.skin_item_blue"), "blue.css", "blue"},
        {I18n::tr("menu.skin_item_blueviolet"), "blueviolet.css", "blueviolet"},
        {I18n::tr("menu.skin_item_goldenrod"), "goldenrod.css", "goldenrod"},
        {I18n::tr("menu.skin_item_green"), "green.css", "green"},
        {I18n::tr("menu.skin_item_magenta"), "magenta.css", "magenta"},
        {I18n::tr("menu.skin_item_orange"), "orange.css", "orange"},
        {I18n::tr("menu.skin_item_purple"), "purple.css", "purple"},
        {I18n::tr("menu.skin_item_red"), "red.css", "red"},
        {I18n::tr("menu.skin_item_yellowgreen"), "yellowgreen.css", "yellowgreen"}
    };

    std::vector<Nui::ElementRenderer> skinItems;
    skinItems.reserve(skins.size());

    for (auto const& skin : skins)
    {
        skinItems.push_back(
            Nui::Elements::li{
                Nui::Attributes::class_ =
                    "skin-item cursor-pointer px-10 py-6 rounded-5 text-white "
                    "text-fs-14 "
                    "transition duration-200 whitespace-nowrap",

                Nui::Attributes::onClick = [file = skin.file]() {
                    changeSkin(file);
                    toggleSkinPanel();
                }
            }(
                // Color circle
                Nui::Elements::span{
                    Nui::Attributes::style =
                        "display: inline-block; "
                        "width: 12px; "
                        "height: 12px; "
                        "border-radius: 50%; "
                        "background-color: " + skin.color + "; "
                        "margin-right: 8px; "
                        "flex-shrink: 0;"
                }(),

                // Skin name
                Nui::Elements::span{}(
                    skin.name
                )
            )
        );
    }

    return Nui::Elements::li{
        Nui::Attributes::class_ =
            "desktop-nav-element cursor-pointer w-50 h-50 relative "
            "flex items-center transition duration-300 my-20 mx-0 "
            "rounded-full bg-black-2"
    }(
        // Skin button
        Nui::Elements::div{
            Nui::Attributes::id = "skin-button",

            Nui::Attributes::class_ =
                "w-50 h-50 relative flex items-center rounded-full",

            Nui::Attributes::onClick = []() {
                toggleSkinPanel();
            }
        }(
            Nui::Elements::i{
                Nui::Attributes::class_ =
                    "fa fa-paint-brush absolute left-0 right-0 mx-auto "
                    "block text-center top-15 pointer-events-none "
                    "text-fs-19"
            }(),
            Nui::Elements::div{
                Nui::Attributes::class_ = "group block p-0 w-50 h-50"
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ =
                        "absolute text-center -z-10 block h-50 pr-25 pl-30 "
                        "text-fs-15 right-0 opacity-0 text-white "
                        "leading-lh-50 font-medium transition-all duration-300 "
                        "rounded-30 group-hover:opacity-100 "
                        "group-hover:right-27 "
                        "group-hover:rounded-tl-30 group-hover:rounded-bl-30 "
                        "group-hover:rounded-tr-none group-hover:rounded-br-none"
                }(
                    I18n::tr("menu.skin")
                )
            )
        ),

        // Skin panel
        Nui::Elements::div{
            Nui::Attributes::id = "skin-panel",

            Nui::Attributes::class_ =
                "absolute bg-black-2 rounded-10 shadow-1 "
                "p-5 opacity-0 invisible "
                "translate-x-10 transition-all duration-300 "
                "pointer-events-none",

            Nui::Attributes::style =
                "right: 65px; "
                "bottom: 0; "
                "width: 150px;"
        }(
            Nui::Elements::ul{
                Nui::Attributes::class_ = "m-0 p-0"
            }(
                skinItems
            )
        )
    );
}

Nui::ElementRenderer Menu::mobileSkinItem()
{
    using namespace Nui::Attributes;

    std::vector<Skin> skins{
        {I18n::tr("menu.skin_item_yellow"), "yellow.css", "yellow"},
        {I18n::tr("menu.skin_item_blue"), "blue.css", "blue"},
        {I18n::tr("menu.skin_item_blueviolet"), "blueviolet.css", "blueviolet"},
        {I18n::tr("menu.skin_item_goldenrod"), "goldenrod.css", "goldenrod"},
        {I18n::tr("menu.skin_item_green"), "green.css", "green"},
        {I18n::tr("menu.skin_item_magenta"), "magenta.css", "magenta"},
        {I18n::tr("menu.skin_item_orange"), "orange.css", "orange"},
        {I18n::tr("menu.skin_item_purple"), "purple.css", "purple"},
        {I18n::tr("menu.skin_item_red"), "red.css", "red"},
        {I18n::tr("menu.skin_item_yellowgreen"), "yellowgreen.css", "yellowgreen"}
    };

    std::vector<Nui::ElementRenderer> skinItems;
    skinItems.reserve(skins.size());

    for (auto const& skin : skins)
    {
        skinItems.push_back(
            Nui::Elements::li{
                Nui::Attributes::class_ =
                    "skin-item cursor-pointer px-10 py-12 rounded-5 text-white "
                    "text-fs-24 transition duration-200 whitespace-nowrap "
                    "flex items-center",

                Nui::Attributes::onClick = [file = skin.file]() {
                    changeSkin(file);
                    routeChanged();
                }
            }(
                Nui::Elements::span{
                    Nui::Attributes::style =
                        "display: inline-block; "
                        "width: 20px; "
                        "height: 20px; "
                        "border-radius: 50%; "
                        "background-color: " + skin.color + "; "
                        "margin-right: 10px; "
                        "flex-shrink: 0;"
                }(),

                Nui::Elements::span{}(
                    skin.name
                )
            )
        );
    }

    return Nui::Elements::li{
        Nui::Attributes::class_ =
            "mobile-nav-element relative pl-30 cursor-pointer"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ =
                "uppercase delay-2000 no-underline relative "
                "text-fs-26 xs:text-fs-18 py-14",

            Nui::Attributes::onClick = []() {
                auto document = emscripten::val::global("document");

                auto panel = document.call<emscripten::val>(
                    "getElementById",
                    std::string{"mobile-skin-panel"}
                );

                auto isHidden = panel["classList"].call<bool>(
                    "contains",
                    std::string{"hidden"}
                );

                if (isHidden)
                    toggleMobileSkinPanel();
            }
        }(
            Nui::Elements::i{
                Nui::Attributes::class_ =
                    "fa fa-paint-brush"
            }(),

            Nui::Elements::span{
                Nui::Attributes::class_ =
                    "absolute left-50 xs:left-35 font-normal"
            }(
                I18n::tr("menu.skin")
            )
        ),

        Nui::Elements::div{
            Nui::Attributes::id = "mobile-skin-panel",

            Nui::Attributes::class_ =
                "hidden bg-black-2 rounded-10 shadow-1 p-5 mt-5",

            Nui::Attributes::style =
                "width: 170px; "
                "margin-left: 150px; "
                "margin-top: -300px; "
                "position: relative; "
                "z-index: 1000; "
        }(
            Nui::Elements::ul{
                Nui::Attributes::class_ = "m-0 p-0"
            }(
                skinItems
            )
        )
    );
}