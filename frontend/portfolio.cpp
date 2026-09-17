#include "frontend/portfolio.hpp"
#include "frontend/i18n/i18n.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer PortfolioPage::render()
{
    using namespace Nui::Attributes;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        id = "portfolio"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "w-full"
        }(
            // Section Title
            Nui::Elements::div{
                Nui::Attributes::class_ = classSectionTitle
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ = classSectionTitleMyPortfolio
                }(
                    Nui::Elements::span{}(
                        I18n::tr("portfolio.my") + " "
                    ),
                    Nui::Elements::span{
                        Nui::Attributes::class_ = "text-accent"
                    }(
                        I18n::tr("portfolio.portfolio")
                    )
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ = classSectionTitleProjects
                }(
                    I18n::tr("portfolio.projects")
                )
            )
        )
    );
}
