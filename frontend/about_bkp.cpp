#include "about.hpp"
#include "i18n/i18n.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer AboutPage::render()
{
    using namespace Nui;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        Nui::Attributes::id = "about"
    }(

        // ============================================================
        // Section title
        // ============================================================

        Nui::Elements::div{
            Nui::Attributes::class_ =
                "mx-auto w-full relative py-80 text-center "
                "xs:px-25 xs:pt-16 xs:pb-14 xs:bg-black-3 "
                "xs:border-b xs:border-black-4 xs:fixed "
                "xs:left-0 xs:right-0 xs:top-0 xs:z-20"
        }(
            Nui::Elements::h2{
                Nui::Attributes::class_ =
                    "text-fs-56 font-black font-Poppins uppercase "
                    "text-white m-0 xs:text-fs-26 "
                    "xs:text-left xs:leading-lh-1.2"
            }(
                "about ",
                Nui::Elements::span{
                    Nui::Attributes::class_ = "text-accent"
                }(
                    "me"
                )
            ),

            Nui::Elements::span{
                Nui::Attributes::class_ =
                    "text-fs-110 absolute left-0 right-0 top-1/2 "
                    "tracking-10 leading-lh-0.7 font-extrabold "
                    "text-muted -translate-y-1/2 uppercase xs:hidden"
            }(
                "resume"
            )
        ),

        // ============================================================
        // Main container
        // ============================================================

        Nui::Elements::div{
            Nui::Attributes::class_ =
                "xl:max-w-1140 custom-md-3:max-w-[calc(100%-195px)] "
                "lg:max-w-960 md:max-w-720 sm:max-w-540 xs:max-w-full "
                "mx-auto"
        }(

            // ========================================================
            // Personal information + facts
            // ========================================================

            Nui::Elements::div{
                Nui::Attributes::class_ =
                    "flex flex-row down-lg:flex-col"
            }(

                // ====================================================
                // Personal Informations
                // ====================================================

                Nui::Elements::div{
                    Nui::Attributes::class_ =
                        "w-1/2 down-lg:w-full"
                }(

                    Nui::Elements::h3{
                        Nui::Attributes::class_ =
                            "text-fs-26 font-semibold uppercase "
                            "pb-22 mb-22 relative "
                            "before:absolute before:bottom-0 "
                            "before:left-0 before:w-40 before:h-3 "
                            "before:bg-accent"
                    }(
                        "Personal Informations"
                    ),

                    // Mobile picture
                    Nui::Elements::img{
                        Nui::Attributes::class_ =
                            "hidden down-lg:block xs:!hidden "
                            "rounded-full w-270 h-270 mx-auto mb-25 "
                            "border-4 border-solid border-black-3",
                        Nui::Attributes::src =
                            "assets/img/profile_photo_300x300.png",
                        Nui::Attributes::alt = "my picture"
                    }(),

                    Nui::Elements::div{
                        Nui::Attributes::class_ =
                            "flex flex-wrap"
                    }(

                        // Column 1
                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "w-1/2 xs:w-full"
                        }(
                            Nui::Elements::ul{}(
                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "First Name: "
                                    ),
                                    "Edson"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Last Name: "
                                    ),
                                    "Aguiar"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Age: "
                                    ),
                                    "52"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Nationality: "
                                    ),
                                    "Brazilian"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Freelance: "
                                    ),
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-accent"
                                    }(
                                        "Available"
                                    )
                                )
                            )
                        ),

                        // Column 2
                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "w-1/2 xs:w-full"
                        }(
                            Nui::Elements::ul{}(
                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Address: "
                                    ),
                                    "Brazil"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Phone: "
                                    ),
                                    "+55 41 99999-9999"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Email: "
                                    ),
                                    "edson@example.com"
                                ),

                                Nui::Elements::li{}(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "text-grey-6 mr-10"
                                    }(
                                        "Languages: "
                                    ),
                                    "Portuguese, English"
                                )
                            )
                        )
                    ),

                    // Download CV
                    Nui::Elements::div{
                        Nui::Attributes::class_ =
                            "mt-30"
                    }(
                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "button cursor-pointer overflow-hidden "
                                "inline-block leading-lh-1.4 rounded-30 "
                                "text-ellipsis text-center align-middle "
                                "select-none transition-all duration-250 "
                                "ease-in-out uppercase no-underline "
                                "relative z-10 py-16 pr-70 pl-35 "
                                "text-fs-15 font-semibold text-white "
                                "bg-transparent outline-0 "
                                "before:absolute before:-z-10 "
                                "before:left-0 before:right-0 before:top-0 "
                                "before:bottom-0 before:translate-x-full "
                                "hover:before:translate-x-0 "
                                "before:transition before:duration-300 "
                                "before:ease-out"
                        }(
                            Nui::Elements::span{
                                Nui::Attributes::class_ =
                                    "relative z-20 text-white"
                            }(
                                "Download CV"
                            ),

                            Nui::Elements::span{
                                Nui::Attributes::class_ =
                                    "absolute -right-px bottom-0 w-55 h-55 "
                                    "flex items-center justify-center "
                                    "rounded-full text-white text-fs-19 "
                                    "fa fa-download bg-accent"
                            }()
                        )
                    )
                ),

                // ====================================================
                // Facts
                // ====================================================

                Nui::Elements::div{
                    Nui::Attributes::class_ =
                        "w-1/2 down-lg:w-full down-lg:mt-50"
                }(
                    Nui::Elements::h3{
                        Nui::Attributes::class_ =
                            "text-fs-26 font-semibold uppercase "
                            "pb-22 mb-22 relative "
                            "before:absolute before:bottom-0 "
                            "before:left-0 before:w-40 before:h-3 "
                            "before:bg-accent"
                    }(
                        "Facts"
                    ),

                    Nui::Elements::div{
                        Nui::Attributes::class_ =
                            "flex flex-wrap"
                    }(

                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "w-1/2 xs:w-full"
                        }(
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "border border-solid "
                                    "border-black-3 rounded-10 "
                                    "py-20 px-30 mb-30"
                            }(
                                Nui::Elements::div{
                                    Nui::Attributes::class_ =
                                        "text-fs-40 text-accent "
                                        "font-semibold"
                                }(
                                    "20"
                                ),

                                Nui::Elements::p{
                                    Nui::Attributes::class_ =
                                        "m-0 uppercase font-Open-sans "
                                        "text-fs-13 leading-lh-1.4"
                                }(
                                    "Years of experience"
                                )
                            )
                        ),

                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "w-1/2 xs:w-full"
                        }(
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "border border-solid "
                                    "border-black-3 rounded-10 "
                                    "py-20 px-30 mb-30"
                            }(
                                Nui::Elements::div{
                                    Nui::Attributes::class_ =
                                        "text-fs-40 text-accent "
                                        "font-semibold"
                                }(
                                    "50"
                                ),

                                Nui::Elements::p{
                                    Nui::Attributes::class_ =
                                        "m-0 uppercase font-Open-sans "
                                        "text-fs-13 leading-lh-1.4"
                                }(
                                    "Projects done"
                                )
                            )
                        )
                    )
                )
            )
        )
    );
}