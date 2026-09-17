#include "frontend/about.hpp"
#include "frontend/i18n/i18n.hpp"
#include <chrono>
#include <ctime>
#include <string>
#include "frontend/router.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer AboutPage::render()
{
    const std::string email = "edson_vc@yahoo.com.br";
    const std::string subject = "Contact%20from%20Portfolio";

    using namespace Nui::Attributes;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        id = "about"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "w-full"
        }(
            // Section Title
            Nui::Elements::div{
                Nui::Attributes::class_ = classSectionTitle
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ = classSectionTitleAboutMe
                }(
                    Nui::Elements::span{}(
                        I18n::tr("about.about") + " "
                    ),
                    Nui::Elements::span{
                        Nui::Attributes::class_ = "text-accent"
                    }(
                        I18n::tr("about.me")
                    )
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ = classSectionTitleResume
                }(
                    I18n::tr("about.resume")
                )
            ),

            // Content container
            Nui::Elements::div{
                Nui::Attributes::class_ = classContentcontainer
            }(
                Nui::Elements::div{
                    Nui::Attributes::class_ = "flex flex-row down-lg:flex-col"
                }(
                    // Personal Information
                    Nui::Elements::div{
                        Nui::Attributes::class_ = "xl:basis-1/2 lg:basis-5/12 down-lg:basis-full"
                    }(
                        Nui::Elements::h3{
                            Nui::Attributes::class_ = classContentcontainerPersonalInformationText
                        }(
                            I18n::tr("about.personal_information")
                        ),

                        Nui::Elements::div{
                            Nui::Attributes::class_ = classContentcontainerPersonalInformationColumn
                        }(
                            // Left column
                            Nui::Elements::div{
                                Nui::Attributes::class_ = classContentcontainerPersonalInformationLeftColumn
                            }(
                                personalInfo(I18n::tr("about.first_name"), "Edson"),
                                personalInfo(I18n::tr("about.last_name"), "Aguiar"),
                                personalInfo(I18n::tr("about.age"),
                                    std::to_string(calculateAge()) + " " + I18n::tr("about.years")),
                                personalInfo(I18n::tr("about.nationality"), I18n::tr("about.nationalityData")),
                                personalInfo(I18n::tr("about.contract"), I18n::tr("about.contractData")),
                                downloadCV()
                            ),

                            // Right column
                            Nui::Elements::div{
                                Nui::Attributes::class_ = classContentcontainerPersonalInformationRightColumn
                            }(
                                personalInfo(I18n::tr("about.address"), I18n::tr("about.addressData")),
                                personalInfo(I18n::tr("about.phone"), "+55 (47)92001-0473"),
                                personalInfo("E-mail", email, subject),
                                personalInfo("Telegram", "@EdsonAguiar_1974"),
                                personalInfo(I18n::tr("about.languages"), I18n::tr("about.languagesData"))
                            )
                        )
                    ),

                    // Facts
                    Nui::Elements::div{
                        Nui::Attributes::class_ = "xl:basis-1/2 lg:basis-7/12 down-lg:basis-full down-lg:mt-50"
                    }(
                        Nui::Elements::div{
                            Nui::Attributes::class_ = "flex down-lg:-mx-15 flex-wrap"
                        }(
                            facts(22, I18n::tr("about.years_of"), I18n::tr("about.experience")),
                            facts(20, I18n::tr("about.completed"), I18n::tr("about.projects"))
                        )
                    )
                ),

                Nui::Elements::hr{
                    Nui::Attributes::class_ = "border-t border-solid border-t-black-3 mx-auto max-w-40prcent mt-70 mb-55"
                }(),

                Nui::Elements::h3{
                    Nui::Attributes::class_ = classContentcontainerMySkillsText
                }(
                    I18n::tr("about.my_skills")
                ),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "flex flex-wrap down-lg:-mx-15"
                }(
                    skillCircle(75, "C++"),
                    skillCircle(50, ".NET"),
                    skillCircle(90, "SQL"),
                    skillCircle(25, "PYTHON")
                ),

                Nui::Elements::div{
                    Nui::Attributes::class_ = "flex flex-wrap down-lg:-mx-15"
                }(
                    skillCircle(80, "LINUX"),
                    skillCircle(50, I18n::tr("about.leadership")),
                    skillCircle(65, I18n::tr("about.proactivity")),
                    skillCircle(45, I18n::tr("about.architecture"))
                ),

                Nui::Elements::hr{
                    Nui::Attributes::class_ =
                        "border-t border-solid border-t-black-3 mx-auto "
                        "max-w-40prcent mt-35 mb-55"
                }(),

                Nui::Elements::h3{
                    Nui::Attributes::class_ =
                        "uppercase text-fs-26 xs:text-fs-21 pb-48 "
                        "text-white font-semibold text-center"
                }(
                    "Experience & Education"
                ),

                Nui::Elements::div{
                    Nui::Attributes::class_ =
                        "flex down-sm:flex-col from-sm:mb-40"
                }(
                    // Experience
                    Nui::Elements::div{
                        Nui::Attributes::class_ =
                            "w-1/2 down-sm:w-full"
                    }(
                        Nui::Elements::ul{}(

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.ExperiencePeriod01"),
                                I18n::tr("about.ExperienceTitle01"),
                                I18n::tr("about.ExperienceLeadership01"),
                                resumeDescription(I18n::tr("about.ExperienceDescription01"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.ExperiencePeriod02"),
                                I18n::tr("about.ExperienceTitle02"),
                                I18n::tr("about.ExperienceLeadership02"),
                                resumeDescription(I18n::tr("about.ExperienceDescription02"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.ExperiencePeriod03"),
                                I18n::tr("about.ExperienceTitle03"),
                                I18n::tr("about.ExperienceLeadership03"),
                                resumeDescription(I18n::tr("about.ExperienceDescription03"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.ExperiencePeriod04"),
                                I18n::tr("about.ExperienceTitle04"),
                                I18n::tr("about.ExperienceLeadership04"),
                                resumeDescription(I18n::tr("about.ExperienceDescription04"))
                            )
                        )
                    ),

                    // Education
                    Nui::Elements::div{
                        Nui::Attributes::class_ =
                            "w-1/2 down-sm:w-full"
                    }(
                        Nui::Elements::ul{}(

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.EducationPeriod01"),
                                I18n::tr("about.EducationTitle01"),
                                I18n::tr("about.EducationLeadership01"),
                                resumeDescription(I18n::tr("about.EducationDescription01"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.EducationPeriod02"),
                                I18n::tr("about.EducationTitle02"),
                                I18n::tr("about.EducationLeadership02"),
                                resumeDescription(I18n::tr("about.EducationDescription02"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.EducationPeriod03"),
                                I18n::tr("about.EducationTitle03"),
                                I18n::tr("about.EducationLeadership03"),
                                resumeDescription(I18n::tr("about.EducationDescription03"))
                            ),

                            resumeItem(
                                "fa-briefcase",
                                I18n::tr("about.EducationPeriod04"),
                                I18n::tr("about.EducationTitle04"),
                                I18n::tr("about.EducationLeadership04"),
                                resumeDescription(I18n::tr("about.EducationDescription04"))
                            )
                        )
                    )
                )
            )
        )
    );
}

int AboutPage::calculateAge()
{
    const int birthYear = 1974;
    const int birthMonth = 3;
    const int birthDay = 2;

    const auto now = std::chrono::system_clock::now();
    const std::time_t time = std::chrono::system_clock::to_time_t(now);
    const std::tm* today = std::localtime(&time);

    int age = today->tm_year + 1900 - birthYear;

    const int currentMonth = today->tm_mon + 1;
    const int currentDay = today->tm_mday;

    if (currentMonth < birthMonth ||
        (currentMonth == birthMonth && currentDay < birthDay))
    {
        --age;
    }

    return age;
}

Nui::ElementRenderer AboutPage::skillCircle(int percent, const std::string& language)
{
    return Nui::Elements::div{
        Nui::Attributes::class_ = "w-1/4 mb-48 down-sm:w-1/2 xs:mb-16"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ =
                std::format("c100 p{} float-none mx-auto bg-black-3", percent)
        }(
            Nui::Elements::span{}(
                std::format("{}%", percent)
            ),
            Nui::Elements::div{
                Nui::Attributes::class_ = "slice"
            }(
                Nui::Elements::div{
                    Nui::Attributes::class_ = "bar"
                }(),
                Nui::Elements::div{
                    Nui::Attributes::class_ = "fill"
                }()
            )
        ),

        Nui::Elements::h6{
            Nui::Attributes::class_ = "uppercase font-Open-sans text-center mt-24 xs:mt-8"
        }(
            language
        )
    );
}

Nui::ElementRenderer AboutPage::personalInfo(const std::string& field, const std::string& info)
{
    return Nui::Elements::div{}(
        Nui::Elements::span{
            Nui::Attributes::class_ = "opacity-80"
        }(
            std::format("{} :", field)
        ),
        Nui::Elements::span{
            Nui::Attributes::class_ = "xs:block custom-md-2:block font-semibold"
        }(
            std::format(" {}", info)
        )
    );
}

Nui::ElementRenderer AboutPage::personalInfo(const std::string& field, const std::string& email, const std::string& subject)
{
    return Nui::Elements::div{}(
        Nui::Elements::span{
            Nui::Attributes::class_ = "opacity-80"
        }(
            std::format("{} :", field)
        ),
        Nui::Elements::a{
            Nui::Attributes::class_ = "xs:block custom-md-2:block font-semibold",
            Nui::Attributes::style =
                "text-transform: lowercase;",
            Nui::Attributes::href =
                "mailto:" + email + "?subject=" + subject,
            Nui::Attributes::target = "_blank"
        }(
            std::format(" {}", email)
        )
    );
}

Nui::ElementRenderer AboutPage::downloadCV()
{
    // Download CV
    return Nui::Elements::a{
        Nui::Attributes::id = "link-about",
        Nui::Attributes::href = I18n::language() == I18n::Language::English ? "Resume_Edson.pdf" : "Curriculo_Edson.pdf",
        Nui::Attributes::target = "_blank",
        Nui::Attributes::class_ = classContentcontainerPersonalInformationColumnDownloadCV
    }(
        Nui::Elements::span{
            Nui::Attributes::class_ = "relative z-20 text-white"
        }(
            I18n::tr("about.download_cv")
        ),

        Nui::Elements::span{
            Nui::Attributes::class_ = classContentcontainerPersonalInformationColumnDownloadCVButton
        }()
    );
}

Nui::ElementRenderer AboutPage::facts(int years, const std::string& firstLineDescription, const std::string& secondLineDescription)
{
    return Nui::Elements::div{
        Nui::Attributes::class_ = "w-1/2 px-15"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = classContentcontainerFactsSqr
        }(
            Nui::Elements::h3{
                Nui::Attributes::class_ = classContentcontainerFactsYears
            }(
                years
            ),
            Nui::Elements::p{
                Nui::Attributes::class_ = classContentcontainerFactsDescription
            }(
                Nui::Elements::span{}(
                    firstLineDescription
                ),
                Nui::Elements::span{
                    Nui::Attributes::class_ = "block"
                }(
                    secondLineDescription
                )
            )
        )
    );
}

Nui::ElementRenderer AboutPage::resumeItem(
    std::string const& icon,
    std::string const& period,
    std::string const& title,
    std::string const& company,
    Nui::ElementRenderer description)
{
    return Nui::Elements::li{
        Nui::Attributes::class_ =
            "relative pr-20 pl-60 mb-50 after:absolute after:top-0 "
            "after:left-20 after:bg-black-4 after:w-1 after:h-full"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ =
                "bg-accent w-40 h-40 absolute left-0 leading-lh-40 "
                "text-center z-10 rounded-full text-white"
        }(
            Nui::Elements::i{
                Nui::Attributes::class_ = "fa " + icon
            }()
        ),

        Nui::Elements::span{
            Nui::Attributes::class_ =
                "text-white text-fs-12 py-1 px-10 inline-block mb-12 "
                "rounded-20 font-semibold bg-black-3 opacity-80 "
                "font-Open-sans uppercase"
        }(
            period
        ),

        Nui::Elements::h5{
            Nui::Attributes::class_ =
                "uppercase text-fs-18 mt-7 mb-10"
        }(
            std::vector<Nui::ElementRenderer>{
                Nui::Elements::span{}(
                    title
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ =
                        "opacity-80 font-semibold text-fs-15 relative pl-26 "
                        "font-Open-sans before:absolute before:w-10 before:h-2 "
                        "before:bg-white before:left-7 before:top-9 before:opacity-80"
                }(
                    company
                )
            }
        ),

        description
    );
}