#include "home.hpp"
#include "about.hpp"
#include "portfolio.hpp"
#include "contact.hpp"
#include "blog.hpp"
#include "i18n/i18n.hpp"
#include "router.hpp"
#include "menu.hpp"

#include <nui/core.hpp>
#include <nui/frontend/bindings.hpp>
#include <nui/frontend/dom/dom.hpp>

#include <emscripten/val.h>

#include <memory>
#include <string>

static std::unique_ptr<HomePage> homePage;
static std::unique_ptr<AboutPage> aboutPage;
static std::unique_ptr<PortfolioPage> portfolioPage;
static std::unique_ptr<ContactPage> contactPage;
static std::unique_ptr<BlogPage> blogPage;
static std::unique_ptr<Menu> menu;
static std::unique_ptr<Nui::Dom::Dom> dom;

std::string currentPath()
{
    return emscripten::val::global("window")
        ["location"]
        ["pathname"]
        .as<std::string>();
}

auto createBody()
{
    return Nui::Elements::body{
        Nui::Attributes::class_ =
            "home dark font-Poppins text-fs-16 text-white font-medium "
            "leading-lh-1.6 relative w-full h-full bg-black overflow-hidden"
    };
}

void renderRoute()
{
    const auto path = currentPath();

    menu = std::make_unique<Menu>();

    if (path == "/home" || path == "/")
    {
        homePage = std::make_unique<HomePage>();
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-full h-full pages overflow-hidden"
                }(
                    homePage->render()
                )
            )
        );
    }
    else if (path == "/about")
    {
        aboutPage = std::make_unique<AboutPage>();
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-full h-full pages overflow-hidden"
                }(
                    aboutPage->render()
                )
            )
        );
    }
    else if (path == "/portfolio")
    {
        portfolioPage = std::make_unique<PortfolioPage>();
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-full h-full pages overflow-hidden"
                }(
                    portfolioPage->render()
                )
            )
        );
    }
    else if (path == "/contact")
    {
        contactPage = std::make_unique<ContactPage>();
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-full h-full pages overflow-hidden"
                }(
                    contactPage->render()
                )
            )
        );
    }
    else if (path == "/blog")
    {
        blogPage = std::make_unique<BlogPage>();
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-full h-full pages overflow-hidden"
                }(
                    blogPage->render()
                )
            )
        );
    }
    else
    {
        dom->setBody(
            createBody()(
                menu->render(),

                Nui::Elements::h1{}(
                    "404 - Page not found"
                )
            )
        );
    }
}

extern "C" void frontendMain()
{
    I18n::loadLanguage();

    dom = std::make_unique<Nui::Dom::Dom>();

    renderRoute();
}

extern "C" void routeChanged()
{
    renderRoute();
}

EMSCRIPTEN_BINDINGS(nui_frontend)
{
    emscripten::function("main", &frontendMain);
    emscripten::function("routeChanged", &routeChanged);
}