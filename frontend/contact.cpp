#include "frontend/contact.hpp"
#include "frontend/i18n/i18n.hpp"

#include <string>
#include <emscripten/val.h>

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer ContactPage::render()
{
    using namespace Nui::Attributes;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        id = "contact"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "w-full"
        }(
            // Section Title
            Nui::Elements::div{
                Nui::Attributes::class_ = classSectionTitle
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ = classSectionTitleGetInTouch
                }(
                    Nui::Elements::span{}(
                        I18n::tr("contact.get_in") + " "
                    ),
                    Nui::Elements::span{
                        Nui::Attributes::class_ = "text-accent"
                    }(
                        I18n::tr("contact.touch")
                    )
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ = classSectionTitleContact
                }(
                    I18n::tr("contact.contact")
                )
            )
        ),

        // Content
        Nui::Elements::div{
            Nui::Attributes::class_ = classContent
        }(
            Nui::Elements::div{
                Nui::Attributes::class_ = "flex down-lg:flex-col"
            }(

                // Contact Details
                Nui::Elements::div{
                    Nui::Attributes::class_ = "w-1/3 down-lg:w-full px-16 xs:px-0"
                }(
                    Nui::Elements::h3{
                        Nui::Attributes::class_ = 
                            "text-fs-26 xs:text-fs-21 mb-16 font-semibold uppercase"
                    }(
                        I18n::tr("contact.content_title")
                    ),

                    Nui::Elements::p{
                        Nui::Attributes::class_ =
                            "mb-16 font-Open-sans text-fs-15 xs:text-fs-14"
                    }(
                        I18n::tr("contact.content_message")
                    ),

                    // Email
                    Nui::Elements::div{
                        Nui::Attributes::class_ = classContentContact
                    }(
                        Nui::Elements::i{
                            Nui::Attributes::class_ = classContentEmailIcon
                        }(),

                        Nui::Elements::span{
                            Nui::Attributes::class_ = "block opacity-80 uppercase font-normal"
                        }(
                            I18n::tr("contact.content_mail_me")
                        ),

                        Nui::Elements::a{
                            Nui::Attributes::class_ = "font-semibold",
                            href = "mailto:edson_vc@yahoo.com.br"
                        }(
                            "edson_vc@yahoo.com.br"
                        )
                    ),

                    // Phone
                    Nui::Elements::div{
                        Nui::Attributes::class_ = classContentContact
                    }(
                        Nui::Elements::i{
                            Nui::Attributes::class_ = classContentPhoneIcon
                        }(),

                        Nui::Elements::span{
                            Nui::Attributes::class_ = "block opacity-80 uppercase font-normal"
                        }(
                            I18n::tr("contact.content_call_me")
                        ),

                        Nui::Elements::a{
                            Nui::Attributes::href = "https://wa.me/5547920010473",
                            Nui::Attributes::target = "_blank",
                            Nui::Attributes::class_ = "text-primary"
                        }(
                            "+55 47 92001-0473"
                        )
                    ),

                    // Social networks
                    Nui::Elements::ul{
                        Nui::Attributes::class_ = "-ml-5 pt-4 mb-48"
                    }(
                        Nui::Elements::li{
                            Nui::Attributes::class_ = "inline-block"
                        }(
                            Nui::Elements::a{
                                Nui::Attributes::class_ = classContentSocialNetwork,
                                Nui::Attributes::href = "https://www.linkedin.com/in/edson-cpp/",
                                Nui::Attributes::target = "_blank"
                            }(
                                Nui::Elements::i{
                                    Nui::Attributes::class_ = "fa fa-linkedin"
                                }()
                            )
                        )
                    )
                ),

                // Contact Form
                Nui::Elements::div{
                    Nui::Attributes::class_ =
                        "w-2/3 down-lg:w-full px-16 down-lg:px-0"
                }(
                    Nui::Elements::form{
                        Nui::Attributes::class_ = "contactform",
                        Nui::Attributes::id = "contactform",
                        Nui::Attributes::onSubmit = [this](Nui::val const& event) {
                            sendEmail(event);
                        }                        
                    }(
                        Nui::Elements::div{
                            Nui::Attributes::class_ =
                                "flex flex-wrap font-normal"
                        }(
                            // Name
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "from-sm:w-1/3 down-sm:w-full px-16 xs:px-0"
                            }(
                                Nui::Elements::input{
                                    Nui::Attributes::type = "text",
                                    Nui::Attributes::name = "name",
                                    Nui::Attributes::autoComplete = "off",
                                    Nui::Attributes::placeHolder = I18n::tr("contact.content_contactForm_placeHolder"),
                                    Nui::Attributes::class_ = classContentContactFormField
                                }()
                            ),

                            // Email
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "from-sm:w-1/3 down-sm:w-full "
                                    "px-16 xs:px-0"
                            }(
                                Nui::Elements::input{
                                    Nui::Attributes::type = "email",
                                    Nui::Attributes::name = "email",
                                    Nui::Attributes::autoComplete = "off",
                                    Nui::Attributes::placeHolder = I18n::tr("contact.content_contactForm_email"),
                                    Nui::Attributes::class_ = classContentContactFormField
                                }()
                            ),

                            // Subject
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "from-sm:w-1/3 down-sm:w-full "
                                    "px-16 xs:px-0"
                            }(
                                Nui::Elements::input{
                                    Nui::Attributes::type = "text",
                                    Nui::Attributes::name = "subject",
                                    Nui::Attributes::autoComplete = "off",
                                    Nui::Attributes::placeHolder = I18n::tr("contact.content_contactForm_subject"),
                                    Nui::Attributes::class_ = classContentContactFormField
                                }()
                            ),

                            // Message
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "w-full px-16 xs:px-0"
                            }(
                                Nui::Elements::textarea{
                                    Nui::Attributes::name = "message",
                                    Nui::Attributes::placeHolder = I18n::tr("contact.content_contactForm_message"),
                                    Nui::Attributes::class_ = classContentContactFormText
                                }()
                            ),

                            // Send button
                            Nui::Elements::div{
                                Nui::Attributes::class_ =
                                    "w-full px-16 xs:px-0 mt-30"
                            }(
                                Nui::Elements::button{
                                    Nui::Attributes::type = "submit",
                                    Nui::Attributes::class_ = classContentContactFormSendButton
                                }(
                                    Nui::Elements::span{
                                        Nui::Attributes::class_ =
                                            "relative z-20 text-white"
                                    }(
                                        I18n::tr("contact.content_contactForm_sendMessage")
                                    ),

                                    Nui::Elements::span{
                                        Nui::Attributes::class_ = classContentContactFormSendButtonIcon
                                    }()
                                )
                            )
                        )
                    )
                )
            )
        )
    );
}

std::string urlEncode(std::string value)
{
    std::string result;

    for (const auto character : value)
    {
        if (character == ' ')
            result += "%20";
        else if (character == '\n')
            result += "%0A";
        else
            result += character;
    }

    return result;
}

void ContactPage::sendEmail(Nui::val const& event)
{
    event.call<void>("preventDefault");

    auto document = emscripten::val::global("document");
    auto form = document.call<emscripten::val>(
        "getElementById",
        emscripten::val("contactform")
    );

    const auto name =
        form["name"]["value"].as<std::string>();

    const auto email =
        form["email"]["value"].as<std::string>();

    const auto subject =
        form["subject"]["value"].as<std::string>();

    const auto message =
        form["message"]["value"].as<std::string>();

    const auto body =
        "Name: " + name + "\n"
        "Email: " + email + "\n\n"
        + message;

    const auto mailto =
        "mailto:edson_vc@yahoo.com.br"
        "?subject=" + urlEncode(subject)
        + "&body=" + urlEncode(body);

    auto window = emscripten::val::global("window");

    window.call<void>(
        "open",
        emscripten::val(mailto),
        emscripten::val("_blank")
    );
}
