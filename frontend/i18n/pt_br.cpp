#include "pt_br.hpp"
#include <unordered_map>

namespace I18n::Portuguese
{
    std::string translate(std::string_view key)
    {
        static const std::unordered_map<std::string, std::string> translations{
            {"menu.home", "INÍCIO"},
            {"menu.about", "SOBRE"},
            {"menu.portfolio", "PORTIFÓLIO"},
            {"menu.contact", "CONTATO"},
            {"menu.blog", "BLOG"},

            {"language.english", "English"},
            {"language.portuguese", "Português"},

            {"home.title", "Eu sou Edson Aguiar."},
            {"home.subtitle", "Engenheiro de Software C++"},
            {"home.description",
                "Sou um engenheiro de software brasileiro especializado em "
                "criar experiências limpas e fáceis de usar. Sou apaixonado por "
                "desenvolver excelentes softwares que melhoram a vida das "
                "pessoas ao meu redor."},
            {"home.more_about_me", "Mais Sobre Mim"},

            {"about.about", "Sobre"},
            {"about.me", "Mim"},
            {"about.resume", "Currículo"},
            {"about.personal_information", "Informações Pessoais"},
            
            {"about.first_name", "Primeiro Nome"},
            {"about.last_name", "Último Nome"},
            {"about.age", "Idade"},
            {"about.years", "anos"},
            {"about.nationality", "Nacionalidade"},
            {"about.nationalityData", "Brasileiro"},
            {"about.contract", "Contrato"},
            {"about.contractData", "Disponível"},
            {"about.download_cv", "Baixar CV"},

            {"about.address", "Endereço"},
            {"about.addressData", "Rua Terra Boa, 596"},
            {"about.phone", "Telefone"},
            {"about.languages", "Idiomas"},
            {"about.languagesData", "Português(Nativo), Inglês(Avançado)"},

            {"about.years_of", "anos de"},
            {"about.experience", "esperiência"},
            {"about.completed", "projetos"},
            {"about.projects", "completos"},
            
            {"about.my_skills", "Minhas Habilidades"},
            {"about.leadership", "Liderança"},
            {"about.proactivity", "Proatividade"},
            {"about.architecture", "Arquitetura"}
        };

        const auto it = translations.find(std::string(key));

        if (it != translations.end())
            return it->second;

        return {};
    }
}