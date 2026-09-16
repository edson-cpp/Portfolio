#include "blog.hpp"
#include "i18n/i18n.hpp"

#include <nui/frontend/attributes.hpp>
#include <nui/frontend/elements.hpp>

Nui::ElementRenderer BlogPage::render()
{
    using namespace Nui::Attributes;

    return Nui::Elements::div{
        Nui::Attributes::class_ = "page page--current",
        id = "blog"
    }(
        Nui::Elements::div{
            Nui::Attributes::class_ = "w-full"
        }(
            // Section Title
            Nui::Elements::div{
                Nui::Attributes::class_ = classSectionTitle
            }(
                Nui::Elements::h2{
                    Nui::Attributes::class_ = classSectionTitleMyBlog
                }(
                    Nui::Elements::span{}(
                        I18n::tr("blog.my") + " "
                    ),
                    Nui::Elements::span{
                        Nui::Attributes::class_ = "text-accent"
                    }(
                        I18n::tr("blog.blog")
                    )
                ),

                Nui::Elements::span{
                    Nui::Attributes::class_ = classSectionTitlePosts
                }(
                    I18n::tr("blog.posts")
                )
            )
        )
    );
}
