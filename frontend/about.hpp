#pragma once

#include <nui/frontend/elements.hpp>

class AboutPage
{
private:
    std::string classSectionTitle = "mx-auto w-full relative py-80 text-center xs:px-25 xs:pt-16 xs:pb-14 "
                        "xs:bg-black-3 xs:border-b xs:border-black-4 xs:fixed xs:left-0 xs:right-0 xs:top-0 xs:z-20";
    std::string classSectionTitleAboutMe = "text-fs-56 font-black font-Poppins uppercase "
                        "text-white m-0 xs:text-fs-26 xs:text-left xs:leading-lh-1.2";
    std::string classSectionTitleResume = "text-fs-110 absolute left-0 right-0 top-1/2 tracking-10 "
                        "leading-lh-0.7 font-extrabold text-muted -translate-y-1/2 uppercase xs:hidden";
    std::string classContentcontainer = "xl:max-w-1140 custom-md-3:max-w-[calc(100%-195px)] "
                        "lg:max-w-960 md:max-w-720 sm:max-w-540 xs:max-w-full mx-auto";
    std::string classContentcontainerPersonalInformationText = 
                        "uppercase text-fs-26 xs:text-fs-21 pb-22 text-white font-semibold";
    std::string classContentcontainerPersonalInformationColumn = 
                        "flex justify-between xs:justify-start font-Open-sans capitalize";
    std::string classContentcontainerPersonalInformationLeftColumn =
                        "basis-1/2 [&>div]:pb-20 [&>div:last-child]:pb-0 text-fs-15 xs:text-fs-14";
    std::string classContentcontainerPersonalInformationRightColumn = 
                        "basis-1/2 [&>div]:pb-20 [&>div:last-child]:pb-0 text-fs-15 xs:text-fs-14";
    std::string classContentcontainerMySkillsText = 
                        "uppercase text-fs-26 xs:text-fs-21 pb-48 text-white font-semibold text-center";
    std::string classContentcontainerPersonalInformationColumnDownloadCV = 
                        "button mt-30 overflow-hidden inline-block leading-lh-1.4 rounded-30 text-ellipsis text-center "
                        "align-middle select-none transition-all duration-250 ease-in-out uppercase no-underline relative "
                        "z-10 py-16 pr-70 pl-35 text-fs-15 font-semibold text-white bg-transparent outline-0 "
                        "before:absolute before:-z-10 before:left-0 before:right-0 before:top-0 before:bottom-0 "
                        "before:translate-x-full hover:before:translate-x-0 before:transition before:duration-300 "
                        "before:ease-out ";
    std::string classContentcontainerPersonalInformationColumnDownloadCVButton = 
                        "absolute -right-px bottom-0 w-55 h-55 flex items-center justify-center rounded-full "
                        "text-white text-fs-19 fa fa-download bg-accent";
    std::string classContentcontainerFactsSqr = "pt-20 xs:pt-15 pr-30 xs:pr-20 pb-25 xs:pb-20 "
                        "pl-40 xs:pl-25 border border-black-3 rounded-5 mb-30 xs:mb-25";
    std::string classContentcontainerFactsYears = "relative inline-block font-bold text-fs-50 "
                        "xs:text-fs-40 text-accent leading-lh-1.2 after:content-['+'] after:absolute "
                        "after:-right-24 after:text-fs-33 after:font-light after:top-2";
    std::string classContentcontainerFactsDescription = "relative xs:text-fs-14 uppercase pl-45 "
                        "xs:pl-0 xs:before:hidden font-Open-sans font-medium before:absolute before:left-0 "
                        "before:top-13 before:w-30 before:h-1 before:bg-black-5";

    int calculateAge();
    Nui::ElementRenderer skillCircle(int percent, const std::string& language);
    Nui::ElementRenderer personalInfo(const std::string& field, const std::string& info);
    Nui::ElementRenderer personalInfo(const std::string& field, const std::string& email, const std::string& subject);
    Nui::ElementRenderer downloadCV();
    Nui::ElementRenderer facts(int years, const std::string& firstLineDescription, const std::string& secondLineDescription);
    Nui::ElementRenderer resumeItem(std::string const& icon, std::string const& period,
        std::string const& title, std::string const& company, Nui::ElementRenderer description);
    Nui::ElementRenderer resumeDescription(std::string const& description);
    
public:
    Nui::ElementRenderer render();
};