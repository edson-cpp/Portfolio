#include "frontend/i18n/en.hpp"
#include <unordered_map>

namespace I18n::English
{
std::string translate(std::string_view key)
    {
        static const std::unordered_map<std::string, std::string> translations{
            {"menu.home", "HOME"},
            {"menu.about", "ABOUT"},
            {"menu.portfolio", "PORTFOLIO"},
            {"menu.contact", "CONTACT"},
            {"menu.blog", "BLOG"},
            {"menu.skin", "SKIN"},

            {"menu.skin_item_yellow", "Yellow"},
            {"menu.skin_item_blue", "Blue"},
            {"menu.skin_item_blueviolet", "Blue Violet"},
            {"menu.skin_item_goldenrod", "Goldenrod"},
            {"menu.skin_item_green", "Green"},
            {"menu.skin_item_magenta", "Magenta"},
            {"menu.skin_item_orange", "Orange"},
            {"menu.skin_item_purple", "Purple"},
            {"menu.skin_item_red", "Red"},
            {"menu.skin_item_yellowgreen", "Yellow Green"},

            {"language.english", "English"},
            {"language.portuguese", "Português"},

            {"home.title", "I'm Edson Aguiar."},
            {"home.subtitle", "C++ Software Engineer"},
            {"home.description",
                "I'm a Brazilian based C++ software engineer focused on "
                "crafting clean & user-friendly experiences, I am passionate "
                "about building excellent software that improves the lives "
                "of those around me.\n"
                "I also have experience with Visual Basic, Delphi and Python"},
            {"home.more_about_me", "More About Me"},
            
            {"about.about", "about"},
            {"about.me", "me"},
            {"about.resume", "resume"},
            {"about.personal_information", "personal information"},
            
            {"about.first_name", "First name"},
            {"about.last_name", "Last name"},
            {"about.age", "Age"},
            {"about.years", "years"},
            {"about.nationality", "Nationality"},
            {"about.nationalityData", "Brazilian"},
            {"about.contract", "Contract"},
            {"about.contractData", "Available"},
            {"about.download_cv", "Download CV"},

            {"about.address", "Address"},
            {"about.addressData", "596, Terra Boa Street"},
            {"about.phone", "Phone"},
            {"about.languages", "Languages"},
            {"about.languagesData", "Portuguese(Native), English(Advanced)"},

            {"about.years_of", "years of"},
            {"about.experience", "experience"},
            {"about.completed", "completed"},
            {"about.projects", "projects"},
            
            {"about.my_skills", "My Skills"},
            {"about.leadership", "leadership"},
            {"about.proactivity", "proactivity"},
            {"about.architecture", "architecture"},

            {"about.ExperiencePeriod01", "Aug 2024 - Jun 2026"},
            {"about.ExperienceTitle01", "Senior Lead Engineer"},
            {"about.ExperienceCompany01", "Lins Ferrão Group"},
            {"about.ExperienceDescription01", "Analyze software projects and define technical approaches for implementation.\n"
                                    "Meet with stakeholders and development teams to discuss requirements and implementation details.\n"
                                    "Write project requirements and guide developers during implementation.\n"
                                    "Plan and manage team resource allocation and development tasks.\n"
                                    "Develop and maintain desktop and web applications for ERP and retail environments.\n"
                                    "Support technical decisions and troubleshoot complex production issues.\n"
                                    "Key result: Implemented monitoring and control tools for the integration system, "
                                    "significantly reducing overnight incidents."},

            {"about.ExperiencePeriod02", "Nov 2021 - Apr 2024"},
            {"about.ExperienceTitle02", "Software Engineer"},
            {"about.ExperienceCompany02", "LG Computers SA"},
            {"about.ExperienceDescription02", "Human Resources system development(VB6, VB.Net, C#, MSSQL, Oracle).\n"
                                    "Soap XML integration, API development to Soap connection.\n"
                                    "API development to connect to other systems of the company.\n"
                                    "Obtained results: Growing NPS from 51 to 55 between 2022 and 2023."},

            {"about.ExperiencePeriod03", "Nov 2019 - Nov 2021"},
            {"about.ExperienceTitle03", "Software Engineer"},
            {"about.ExperienceCompany03", "Linx Software"},
            {"about.ExperienceDescription03", "Gas station system development(Python, PostgreSQL).\n"
                                    "WebAPI integration via Json, integrated billet with banking automation.\n"
                                    "Issuance of Electronic Invoice, Tax Coupon, Inventory control, Purchase control with XML import.\n"
                                    "Control of sales front of retail cashier, Control of accounts payable and receivable.\n"
                                    "Obtained results: Reduction of the backlog by 15% in 2020."},

            {"about.ExperiencePeriod04", "Oct 2003 - Sep 2019"},
            {"about.ExperienceTitle04", "Software Engineer"},
            {"about.ExperienceCompany04", "Sage, M4, Cybersis, Jclan, Arj"},
            {"about.ExperienceDescription04", "Sage (2018 - 2019):** Maintenance and enhancement of "
                                    "enterprise systems using Delphi 7, VB6, and C#.\n"
                                    "M4 Informática (2016 - 2018):** Development and maintenance of "
                                    "ERP systems using Delphi 7 and XE5.\n"
                                    "Cybersis (2009 - 2015):** Development of ERP applications using "
                                    "VFP9, VB6, Java, and C++.\n"
                                    "Jclan (2007 - 2009):** Development of ERP applications using VFP9, Java, and Delphi 6.\n"
                                    "Arj (2005 - 2007):** Development of ERP applications using "
                                    "VFP9, VB6, and Java.\n"
                                    "Jclan (2003 - 2005):** Development of ERP applications using VFP9, Java, and Delphi 6.\n"
                                    "Development of financial, purchasing, inventory, invoicing, and accounting modules.\n"
                                    "Development and maintenance of SQL Server, MySQL, and Firebird databases.\n"
                                    "Integration with external systems through APIs, Web Services, SOAP, and XML.\n"
                                    "Requirements gathering and business process analysis in collaboration with users.\n"
                                    "Support and maintenance of ERP customizations and legacy systems.\n"
                                    "Documentation of business rules and technical specifications.\n"
                                    "Development of desktop applications and user interfaces.\n"
                                    "Maintenance of legacy systems.\n"
                                    "Bug fixing and feature enhancements.\n"
                                    "SQL query optimization.\n"
                                    "ERP system development using C++, C#, VB6, Delphi 7/XE5, Linux, xBase, MySQL, and MSSQL."},

            {"about.EducationPeriod01", "11/2015-01/2018"},
            {"about.EducationTitle01", "Degree in Systems Analysis and Development"},
            {"about.EducationCompany01", "Uninter"},
            {"about.EducationDescription01", "Academic projects: Development of a C++ project "
                                    "for Holy Church automation. "
                                    "(https://github.com/edson-cpp/ecclesia)\n"
                                    "2015/12 Entrepreneurship 80h 8.8, Computational Mathematics 80h 7.4\n"
                                    "2016/02 Business Communication 80h 7.5, Fundamentals of Information Systems 80h 7.5, Logical Reasoning 80h 9.3\n"
                                    "2016/04 Computer Network 80h 7.3, Operating Systems 80h 8.5\n"
                                    "2016/05 Computer Architecture 80h 7.6, Programming Logic and Algorithms 80h 8.9\n"
                                    "2016/07 Databases 80h 7.7, Data Structure 80h 8.6\n"
                                    "2016/09 Systems Analysis 80h 8.2, Programming Language 80h 8.8\n"
                                    "2016/10 Web Development Tools 80h 9.2, Human-Computer Interaction 80h 8.0\n"
                                    "2017/02 Software Engineering 80h 10.0, Object-Oriented Programming 80h 9.9\n"
                                    "2017/04 Information Technology Governance 80h 8.2, Legislation and Intellectual Property 80h 9.1\n"
                                    "2017/05 Project Management 80h 9.1, Financial Mathematics 80h 7.3\n"
                                    "2017/07 Information Systems Security 80h 8.3, Advanced Topics in Programming 80h 8.8\n"
                                    "2017/09 Visual Programming 80h 9.5, Database Management System 80h 9.4"},

            {"about.EducationPeriod02", "08/2023"},
            {"about.EducationTitle02", "Modern Qt Course with C++ for Linux and Windows"},
            {"about.EducationCompany02", "Udemy"},
            {"about.EducationDescription02", "How to Build Graphical Applications on Linux and Windows "
                                    "in a Practical, Simple, and Proper Way"},

            {"about.EducationPeriod03", "05/2023"},
            {"about.EducationTitle03", "Advanced Modern C++ Course"},
            {"about.EducationCompany03", "Udemy"},
            {"about.EducationDescription03", "Object-Oriented Programming with C++.\n"
                                    "Terminal-based graphical applications using Ncurses, "
                                    "CLI game development, GUI development with GTK+, "
                                    "database integration with MySQL and SQLite, web "
                                    "development with C++, and experience with additional "
                                    "libraries and frameworks."},

            {"about.EducationPeriod04", "07-08/2013"},
            {"about.EducationTitle04", "Development C++ with QT"},
            {"about.EducationCompany04", "Elaborata"},
            {"about.EducationDescription04", "Object-Oriented Programming with C++.\n"
                                    "GUI development with QT.\n"
                                    "Database integration with MySQL."},

            {"portfolio.my", "my"},
            {"portfolio.portfolio", "portfolio"},
            {"portfolio.projects", "projects"},

            {"contact.get_in", "get in"},
            {"contact.touch", "touch"},
            {"contact.contact", "contact"},

            {"contact.content_title", "don't be shy!"},
            {"contact.content_message", "Feel free to get in touch with me. "
                                    "I am always open to discussing new "
                                    "projects, creative ideas or opportunities "
                                    "to be part of your visions."},                        
            {"contact.content_mail_me", "mail me"},
            {"contact.content_call_me", "call me"},
            {"contact.content_contactForm_placeHolder", "YOUR NAME"},
            {"contact.content_contactForm_email", "YOUR EMAIL"},
            {"contact.content_contactForm_subject", "YOUR SUBJECT"},
            {"contact.content_contactForm_message", "YOUR MESSAGE"},
            {"contact.content_contactForm_sendMessage", "send message"},

            {"blog.my", "my"},
            {"blog.blog", "blog"},
            {"blog.posts", "posts"}
        };

        const auto it = translations.find(std::string(key));

        if (it != translations.end())
            return it->second;

        return {};
    }
}