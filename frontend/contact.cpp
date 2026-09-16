#include "contact.hpp"
#include "i18n/i18n.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer ContactPage::render()
{
    using namespace Nui::Attributes;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        id = "contact"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "w-full"
        }(
            // Section Title
            Nui::Elements::div{
                Nui::Attributes::class_ = classSectionTitle
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ = classSectionTitleGetInTouch
                }(
                    Nui::Elements::span{}(
                        I18n::tr("contact.get_in") + " "
                    ),
                    Nui::Elements::span{
                        Nui::Attributes::class_ = "text-accent"
                    }(
                        I18n::tr("contact.touch")
                    )
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ = classSectionTitleContact
                }(
                    I18n::tr("contact.contact")
                )
            )
        )
    );
}
