#pragma once

#include <nui/frontend/elements.hpp>

class BlogPage
{
private:
    std::string classSectionTitle = "mx-auto w-full relative py-80 text-center xs:px-25 xs:pt-16 xs:pb-14 "
                        "xs:bg-black-3 xs:border-b xs:border-black-4 xs:fixed xs:left-0 xs:right-0 xs:top-0 xs:z-20";
    std::string classSectionTitleMyBlog = "text-fs-56 font-black font-Poppins uppercase "
                        "text-white m-0 xs:text-fs-26 xs:text-left xs:leading-lh-1.2";
    std::string classSectionTitlePosts = "text-fs-110 absolute left-0 right-0 top-1/2 tracking-10 "
                        "leading-lh-0.7 font-extrabold text-muted -translate-y-1/2 uppercase xs:hidden";
    
public:
    Nui::ElementRenderer render();
};