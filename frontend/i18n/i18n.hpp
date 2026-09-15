#pragma once

#include <string>
#include <string_view>

namespace I18n
{
    enum class Language
    {
        English,
        Portuguese
    };

    void setLanguage(Language language);

    Language language();

    void loadLanguage();

    std::string tr(std::string_view key);
}