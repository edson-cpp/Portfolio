#pragma once

#include <nui/frontend/elements.hpp>

class ContactPage
{
private:
    std::string classSectionTitle = "mx-auto w-full relative py-80 text-center xs:px-25 xs:pt-16 xs:pb-14 "
                        "xs:bg-black-3 xs:border-b xs:border-black-4 xs:fixed xs:left-0 xs:right-0 xs:top-0 xs:z-20";
    std::string classSectionTitleGetInTouch = "text-fs-56 font-black font-Poppins uppercase "
                        "text-white m-0 xs:text-fs-26 xs:text-left xs:leading-lh-1.2";
    std::string classSectionTitleContact = "text-fs-110 absolute left-0 right-0 top-1/2 tracking-10 "
                        "leading-lh-0.7 font-extrabold text-muted -translate-y-1/2 uppercase xs:hidden";
    std::string classContent = "xl:max-w-1140 custom-md-3:max-w-[calc(100%-195px)] "
                        "lg:max-w-960 md:max-w-720 sm:max-w-540 xs:max-w-full mx-auto";
    std::string classContentContact = "relative font-Open-sans font-semibold "
                        "pl-50 pt-5 leading-lh-21 text-fs-15 xs:text-fs-14 mb-16";
    std::string classContentEmailIcon = "fa fa-envelope-open absolute left-0 "
                        "top-10 text-fs-33 text-accent";
    std::string classContentPhoneIcon = "fa fa-phone-square absolute left-0 "
                        "top-10 text-fs-39 text-accent";
    std::string classContentSocialNetwork = "social-item inline-block h-40 w-40 leading-lh-42 text-center "
                        "text-white transition duration-300 text-fs-17 mx-6 bg-black-2 rounded-full";
    std::string classContentContactFormField = "w-full bg-black-3 text-fs-15 text-white border border-solid "
                        "border-black py-11 px-26 mb-30 rounded-30 outline-0 transition duration-300 "
                        "placeholder:text-placeholder field-form";
    std::string classContentContactFormText = "bg-black-3 w-full text-white border border-solid border-black "
                        "h-160 py-12 px-26 overflow-hidden rounded-30 outline-0 transition "
                        "duration-300 field-form placeholder:text-placeholder";
    std::string classContentContactFormSendButton = "button overflow-hidden inline-block leading-lh-1.4 "
                        "rounded-30 text-ellipsis text-center align-middle select-none transition-all "
                        "duration-250 ease-in-out uppercase no-underline relative z-10 py-16 pr-70 pl-35 "
                        "text-fs-15 font-semibold text-white bg-transparent outline-0 "
                        "before:absolute before:-z-10 before:left-0 before:right-0 before:top-0 before:bottom-0 "
                        "before:translate-x-full hover:before:translate-x-0 before:transition "
                        "before:duration-300 before:ease-out";
    std::string classContentContactFormSendButtonIcon = "absolute -right-px bottom-0 w-55 h-55 flex items-center "
                        "justify-center rounded-full text-white text-fs-19 fa fa-send bg-accent";

    Nui::ElementRenderer contactDetail(
        const std::string& icon,
        const std::string& label,
        const std::string& value);    
    void sendEmail(Nui::val const& event);
    
public:
    Nui::ElementRenderer render();
};