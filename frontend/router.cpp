#include "router.hpp"

#include <emscripten/val.h>

extern "C" void routeChanged();

void navigateTo(std::string const& path)
{
    auto window = emscripten::val::global("window");

    window["history"].call<void>(
        "pushState",
        emscripten::val{},
        emscripten::val{},
        emscripten::val(path)
    );

    routeChanged();
}

Nui::ElementRenderer resumeDescription(std::string const& description, bool withBulletPoint)
{
    std::stringstream flux(description);
    std::string line;
    std::vector<Nui::ElementRenderer> lines;
    int lineNumber = 1;

    while (std::getline(flux, line))
    {
        if (withBulletPoint){
            lines.push_back(
                Nui::Elements::i{
                    Nui::Attributes::class_ = "fa fa-circle mr-8",
                    Nui::Attributes::style =
                        "font-size: 6px; vertical-align: middle;"
                }()
            );
        }

        lines.push_back(
            Nui::Elements::span{}(
                " " + line
            )
        );

        if (flux.peek() != EOF)
        {
            lines.push_back(
                Nui::Elements::br{}()
            );
        }
    }

    return Nui::Elements::p{
        Nui::Attributes::class_ =
            "font-Open-sans text-light-grey text-fs-14"
    }(
        std::move(lines)
    );
}