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