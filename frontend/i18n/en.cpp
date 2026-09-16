#include "en.hpp"
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

            {"language.english", "English"},
            {"language.portuguese", "Português"},

            {"home.title", "I'm Edson Aguiar."},
            {"home.subtitle", "C++ Software Engineer"},
            {"home.description",
                "I'm a Brazilian based C++ software engineer focused on "
                "crafting clean & user-friendly experiences, I am passionate "
                "about building excellent software that improves the lives "
                "of those around me."},
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

            {"portfolio.my", "my"},
            {"portfolio.portfolio", "portfolio"},
            {"portfolio.projects", "projects"},

            {"contact.get_in", "get in"},
            {"contact.touch", "touch"},
            {"contact.contact", "contact"},

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