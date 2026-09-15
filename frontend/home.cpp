#include "home.hpp"
#include "i18n/i18n.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer HomePage::render()
{
    using namespace Nui;
    using namespace Nui::Elements;
    using namespace Nui::Attributes;

    return Nui::Elements::div{
        class_ = "page page--current",
        id = "home"
    }(
        // Home background
        Nui::Elements::div{
            class_ = "bg-accent fixed w-full h-200prcnt -rotate-15 "
                     "-top-1/2 -left-83prcnt hidden from-lg:block"
        }(),

        // Home content
        Nui::Elements::div{
            class_ = "flex items-center h-screen w-full "
                     "down-lg:mx-auto down-lg:justify-center "
                     "xs:text-left down-lg:text-center"
        }(
            // Desktop image
            img{
                class_ = "hidden from-lg:block fixed w-1/3 "
                         "h-[calc(100vh-80px)] left-40 top-40 "
                         "rounded-30 shadow-1 object-cover",
                src = "assets/img/profile_photo.png",
                alt = "Profile photo"
            }(),

            // Content
            Nui::Elements::div{
                class_ = "from-lg:ml-100/3 from-lg:w-2/3"
            }(
                Nui::Elements::div{
                    class_ = "mx-auto max-w-550 custom-md-1:max-w-450"
                }(
                    // Mobile image
                    Nui::Elements::img{
                        class_ = "hidden down-lg:block rounded-full "
                                 "w-270 h-270 mx-auto mb-25 "
                                 "border-4 border-solid border-black-3",
                        src = "assets/img/profile_photo_300x300.png",
                        alt = "my picture"
                    }(),

                    // Information
                    Nui::Elements::h1{
                        class_ = "text-fs-51 text-accent font-Poppins relative "
                                 "uppercase font-bold leading-lh-62 pl-70 "
                                 "before:absolute before:left-0 before:top-29 "
                                 "before:h-4 before:w-40 before:rounded-10 "
                                 "custom-md-2:text-fs-42 "
                                 "down-xl:before:hidden down-xl:pl-0 "
                                 "custom-md-2:leading-lh-52 "
                                 "down-md:text-fs-38 down-md:leading-lh-48 "
                                 "down-md:mt-29 down-md:mb-13 "
                                 "xs:text-fs-29 xs:leading-lh-39 xs:mt-18"
                    }(
                        Nui::Elements::span{}(
                            I18n::tr("home.title")
                        ),

                        Nui::Elements::span{
                            class_ = "block text-white"
                        }(
                            I18n::tr("home.subtitle")
                        )
                    ),

                    p{
                        class_ = "font-Open-sans mt-15 mb-28 leading-lh-35 "
                                 "down-lg:mt-2.5 down-lg:mb-23 "
                                 "down-lg:text-fs-15 down-lg:leading-lh-30"
                    }(
                        I18n::tr("home.description")
                    ),

                    // More About Me
                    Nui::Elements::div{
                        id = "link-about",
                        class_ = "button cursor-pointer overflow-hidden inline-block "
                                 "leading-lh-1.4 rounded-30 text-ellipsis text-center "
                                 "align-middle select-none transition-all duration-250 "
                                 "ease-in-out uppercase no-underline relative z-10 "
                                 "py-16 pr-70 pl-35 text-fs-15 font-semibold "
                                 "text-white bg-transparent outline-0 "
                                 "before:absolute before:-z-10 before:left-0 "
                                 "before:right-0 before:top-0 before:bottom-0 "
                                 "before:translate-x-full hover:before:translate-x-0 "
                                 "before:transition before:duration-300 before:ease-out"
                    }(
                        Nui::Elements::span{
                            class_ = "relative z-20 text-white"
                        }(
                            I18n::tr("home.more_about_me")
                        ),

                        Nui::Elements::span{
                            class_ = "absolute -right-px bottom-0 w-55 h-55 "
                                     "flex items-center justify-center rounded-full "
                                     "text-white text-fs-19 fa fa-arrow-right bg-accent"
                        }()
                    )
                )
            )
        )
    );
}