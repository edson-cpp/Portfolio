#pragma once

#include <string>
#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>
#include <sstream>

void renderRoute();
void navigateTo(std::string const& path);
Nui::ElementRenderer resumeDescription(std::string const& description, bool withBulletPoint = true);