#include "i18n.hpp"
#include "en.hpp"
#include "pt_br.hpp"
#include <emscripten/val.h>

namespace
{
    I18n::Language currentLanguage = I18n::Language::English;
}

std::string languageCode(I18n::Language language)
{
    switch (language)
    {
        case I18n::Language::English:
            return "en";

        case I18n::Language::Portuguese:
            return "pt-BR";
    }

    return "en";
}

namespace I18n
{
    void setLanguage(Language language)
    {
        currentLanguage = language;

        auto localStorage = emscripten::val::global("window")["localStorage"];

        localStorage.call<void>(
            "setItem",
            emscripten::val("language"),
            emscripten::val(languageCode(language))
        );
    }

    Language language()
    {
        return currentLanguage;
    }

    void loadLanguage()
    {
        auto localStorage =
            emscripten::val::global("window")["localStorage"];

        const auto value =
            localStorage.call<emscripten::val>(
                "getItem",
                emscripten::val("language")
            );

        if (value.isNull() || value.isUndefined())
        {
            currentLanguage = Language::English;
            return;
        }

        const auto language = value.as<std::string>();

        if (language == "pt-BR")
            currentLanguage = Language::Portuguese;
        else
            currentLanguage = Language::English;
    }

    std::string tr(std::string_view key)
    {
        switch (currentLanguage)
        {
        case Language::English:
            return English::translate(key);
        
        case Language::Portuguese:
            return Portuguese::translate(key);
        }

        return {};
    }
}