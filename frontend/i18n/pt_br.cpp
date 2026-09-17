#include "frontend/i18n/pt_br.hpp"
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
                "pessoas ao meu redor.\n"
                "Também tenho experiência com Visual Basic, Delphi e Python"},
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
            {"about.architecture", "Arquitetura"},

            {"about.ExperiencePeriod01", "Ago 2024 - Jun 2026"},
            {"about.ExperienceTitle01", "Engenheiro de Software Sênior"},
            {"about.ExperienceCompany01", "Grupo Lins Ferrão"},
            {"about.ExperienceDescription01", "Desenvolvimento e manutenção de aplicações ERP utilizando "
                                    "Delphi VCL (XE2, XE5 e RAD Studio 12) e Python.\n"
                                    "Analisar projetos de software e definir abordagens técnicas para implementação.\n"
                                    "Reunir-se com as áreas envolvidas e equipes de desenvolvimento para discutir "
                                    "requisitos e detalhes de implementação.\n"
                                    "Elaborar requisitos de projetos e orientar desenvolvedores durante a implementação.\n"
                                    "Planejar e gerenciar a alocação de recursos da equipe e as tarefas de desenvolvimento.\n"
                                    "Desenvolver e manter aplicações desktop e web para ambientes de ERP e varejo.\n"
                                    "Apoiar decisões técnicas e solucionar problemas complexos em produção.\n"
                                    "Principal resultado: Implementei ferramentas de monitoramento e controle no sistema de "
                                    "integração, reduzindo significativamente os incidentes durante a madrugada."},
            
            {"about.ExperiencePeriod02", "(Nov 2021 - Abr 2024"},
            {"about.ExperienceTitle02", "Engenheiro de Software"},
            {"about.ExperienceCompany02", "LG Lugar de Gente"},
            {"about.ExperienceDescription02", "Desenvolvimento e manutenção de módulos ERP de Recursos Humanos "
                                    "utilizando VB6, VB.NET, C#, SVN, SQL Server e Oracle.\n"
                                    "Desenvolver funcionalidades relacionadas à folha de pagamento, controle de ponto e benefícios.\n"
                                    "Implementar alterações no sistema para atender à legislação trabalhista brasileira "
                                    "e às exigências governamentais, incluindo o eSocial.\n"
                                    "Desenvolver e manter integrações de sistemas e web services.\n"
                                    "eSolucionar problemas em produção e realizar a manutenção de sistemas legados.\n"
                                    "Principal resultado: Contribuí para o aumento do NPS de 51 para 55 entre 2022 e 2023."},

            {"about.ExperiencePeriod03", "Nov 2019 - Nov 2021"},
            {"about.ExperienceTitle03", "Engenheiro de Software"},
            {"about.ExperienceCompany03", "Linx Software"},
            {"about.ExperienceDescription03", "Desenvolver e manter sistemas ERP e POS para postos de "
                                    "combustíveis e empresas do varejo usando Python e PostgreSQL.\n"
                                    "Desenvolver integrações com Web APIs utilizando JSON e integrar "
                                    "boletos bancários com sistemas de automação bancária.\n"
                                    "Desenvolver funcionalidades para emissão de documentos fiscais eletrônicos, "
                                    "documentos fiscais, contas a pagar e receber, estoque, compras e vendas.\n"
                                    "Solucionar problemas em produção e corrigir bugs em aplicações críticas para o negócio.\n"
                                    "Principal resultado: Reduzi o backlog de desenvolvimento em 15% em 2020."},

            {"about.ExperiencePeriod04", "Out 2003 - Set 2019"},
            {"about.ExperienceTitle04", "Engenheiro de Software"},
            {"about.ExperienceCompany04", "Sage, M4, Cybersis, Jclan, Arj"},
            {"about.ExperienceDescription04", "Sage (2018 - 2019):** Manutenção e evolução de sistemas corporativos "
                                    "utilizando Delphi 7, VB6 e C#.\n"
                                    "M4 Informática (2016 - 2018):** desenvolvimento e manutenção de sistemas "
                                    "ERP utilizando Delphi 7 e XE5.\n"
                                    "Cybersis (2009 - 2015):** Desenvolvimento de aplicações ERP em VFP9, VB6, Java e C++.\n"
                                    "Jclan (2007 - 2009):** Desenvolvimento de aplicações ERP em VFP9, Java e Delphi 6.\n"
                                    "Arj (2005 - 2007):** Desenvolvimento de aplicações ERP em VFP9, VB6, Java e C++.\n"
                                    "Jclan (2003 - 2005):** Desenvolvimento de aplicações ERP em VFP9, Java e Delphi 6.\n"
                                    "Desenvolvimento de módulos financeiros, compras, estoque, faturamento e contabilidade.\n"
                                    "Desenvolvimento e manutenção de bancos de dados SQL Server, MySQL e Firebird.\n"
                                    "Integração com sistemas externos por meio de APIs, WebServices, SOAP e XML.\n"
                                    "Levantamento de requisitos e análise de processos de negócio junto aos usuários.\n"
                                    "Suporte e manutenção de customizações ERP e sistemas legados.\n"
                                    "Documentação de regras de negócio e especificações técnicas.\n"
                                    "Desenvolvimento de interfaces desktop.\n"
                                    "Manutenção de sistemas legados.\n"
                                    "Correção de bugs e evolução de funcionalidades.\n"
                                    "Otimização de consultas SQL.\n"
                                    "Desenvolvimento de sistemas ERP usando C++, C# e VB6, Delphi 7 e XE5, Linux, xBase, MySQL, MSSQL."},

            {"about.EducationPeriod01", "11/2015-01/2018"},
            {"about.EducationTitle01", "Graduação em Análise e Desenvolvimento de Sistemas"},
            {"about.EducationCompany01", "Uninter"},
            {"about.EducationDescription01", "Projeto acadêmico: Desenvolvimento de um projeto "
                                    "em C++ para automação da Santa Igreja. "
                                    "(https://github.com/edson-cpp/ecclesia)\n"
                                    "2015/12 Empreendedorismo 80h 8.8, Matemática Computacional 80h 7.4\n"
                                    "2016/02 Comunicação Empresarial 80h 7.5, Fundamentos de Sistemas de Informação 80h 7.5, Raciocínio Lógico 80h 9.3\n"
                                    "2016/04 Redes de Computadores 80h 7.3, Sistemas Operacionais 80h 8.5\n"
                                    "2016/05 Arquitetura de Computadores 80h 7.6, Lógica de Programação e Algoritmos 80h 8.9\n"
                                    "2016/07 Banco de Dados 80h 7.7, Estrutura de Dados 80h 8.6\n"
                                    "2016/09 Análise de Sistemas 80h 8.2, Linguagem de Programação 80h 8.8\n"
                                    "2016/10 Ferramentas de Desenvolvimento WEB 80h 9.2, Interação Humano - Computador 80h 8.0\n"
                                    "2017/02 Engenharia de Software 80h 10.0, Programação Orientada a Objetos 80h 9.9\n"
                                    "2017/04 Governança de Tecnologia de Informação 80h 8.2, Legislação e Propriedade Intelectual 80h 9.1\n"
                                    "2017/05 Gestão de Projetos 80h 9.1, Matemática Financeira 80h 7.3\n"
                                    "2017/07 Segurança em Sistemas de Informação 80h 8.3, Tópicos Avançados em Programação 80h 8.8\n"
                                    "2017/09 Programação Visual 80h 9.5, Sistema Gerenciador de Banco de Dados 80h 9.4"},

            {"about.EducationPeriod02", "08/2023"},
            {"about.EducationTitle02", "Curso de Qt Moderno com C++ para Linux e Windows"},
            {"about.EducationCompany02", "Udemy"},
            {"about.EducationDescription02", "Como Desenvolver Aplicações Gráficas no Linux e no Windows "
                                    "de Forma Prática, Simples e Adequada "},

            {"about.EducationPeriod03", "05/2023"},
            {"about.EducationTitle03", "Curso de C++ Moderno Avançado"},
            {"about.EducationCompany03", "Udemy"},
            {"about.EducationDescription03", "Programação Orientada a Objetos com C++.\n"
                                    "Aplicações gráficas baseadas em terminal usando Ncurses, "
                                    "desenvolvimento de jogos em CLI, desenvolvimento de GUI com GTK+, "
                                    "integração de banco de dados com MySQL e SQLite, desenvolvimento "
                                    "web com C++, e experiência com bibliotecas e frameworks adicionais."},

            {"about.EducationPeriod04", "07-08/2013"},
            {"about.EducationTitle04", "Desenvolvimento C++ com QT"},
            {"about.EducationCompany04", "Elaborata"},
            {"about.EducationDescription04", "Programação Orientada a Objetos com C++.\n"
                                    "Desenvolvimento de GUI com QT.\n"
                                    "Integração de banco de dados com MySQL."},

            {"portfolio.my", "meu"},
            {"portfolio.portfolio", "portifólio"},
            {"portfolio.projects", "projetos"},

            {"contact.get_in", "Entre em"},
            {"contact.touch", "contato"},
            {"contact.contact", "contato"},

            {"blog.my", "meu"},
            {"blog.blog", "blog"},
            {"blog.posts", "postagens"}
        };

        const auto it = translations.find(std::string(key));

        if (it != translations.end())
            return it->second;

        return {};
    }
}