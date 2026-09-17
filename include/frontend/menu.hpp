#pragma once

#include <nui/frontend/elements.hpp>
#include <nui/frontend/attributes.hpp>

#include <string>
#include <vector>

class Menu
{
private:
    struct MenuItem
    {
        std::string translationKey;
        std::string desktopIconClass;
        std::string mobileIconClass;
        std::string path;
        bool isActive = false;
    };

    struct Skin
    {
        std::string name;
        std::string file;
    };

    Nui::ElementRenderer desktopNavItem(MenuItem const& item);
    Nui::ElementRenderer mobileNavItem(MenuItem const& item);
    Nui::ElementRenderer desktopLanguageItem();
    Nui::ElementRenderer mobileLanguageItem();
    Nui::ElementRenderer desktopSkinItem();
    Nui::ElementRenderer mobileSkinItem();

public:
    Nui::ElementRenderer render();
};
