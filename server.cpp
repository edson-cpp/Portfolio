#include "httplib.h"

#include <filesystem>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <diretorio>\n";
        return 1;
    }

    const std::filesystem::path root = std::filesystem::absolute(argv[1]);

    if (!std::filesystem::is_directory(root)) {
        std::cerr << "Diretorio nao encontrado: "
                  << root << '\n';
        return 1;
    }

    httplib::Server svr;

    const auto index_file = root / "index.html";

    if (!std::filesystem::exists(index_file)) {
        std::cerr << "index.html nao encontrado: "
                  << index_file << '\n';
        return 1;
    }

    const auto serve_index =
        [&index_file](const httplib::Request&, httplib::Response& res)
    {
        res.set_file_content(index_file.string(), "text/html");
    };

    svr.Get("/", [](const httplib::Request&, httplib::Response& res)
    {
        res.set_redirect("/home");
    });

    svr.Get("/home", serve_index);
    svr.Get("/about", serve_index);
    svr.Get("/portfolio", serve_index);
    svr.Get("/contact", serve_index);
    svr.Get("/blog", serve_index);

    if (!svr.set_mount_point("/", root.string())) {
        std::cerr << "Erro ao montar: "
                  << root << '\n';
        return 1;
    }

    std::cout << "Root:   " << root << '\n';
    std::cout << "Serving: " << root << '\n';
    std::cout << "http://localhost:8000\n";

    svr.listen("0.0.0.0", 8000);

    return 0;
}