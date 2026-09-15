cmake_minimum_required(VERSION 3.28)

project(Portfolio VERSION 0.1.0)

add_subdirectory(nui nui-build)

add_executable(Portfolio
    frontend/main.cpp
    frontend/menu.cpp
    frontend/home.cpp
    frontend/about.cpp
    frontend/i18n/i18n.cpp
    frontend/i18n/en.cpp
    frontend/i18n/pt_br.cpp
)

target_link_libraries(Portfolio
    PRIVATE
        nui-frontend
)

if (EMSCRIPTEN)
    set(NUI_MODULE_BUILD_DIR "${CMAKE_BINARY_DIR}")

    file(GLOB_RECURSE PORTFOLIO_STATIC_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/static/*"
    )

    add_subdirectory(frontend)

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/package.json
        ${CMAKE_BINARY_DIR}/package.json
        COPYONLY
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/.parcelrc
        ${CMAKE_BINARY_DIR}/.parcelrc
        COPYONLY
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/static/Resume_Edson.pdf
        ${CMAKE_BINARY_DIR}/bin/Resume_Edson.pdf
        COPYONLY
    )

    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/static/Curriculo_Edson.pdf
        ${CMAKE_BINARY_DIR}/bin/Curriculo_Edson.pdf
        COPYONLY
    )

endif()

target_compile_features(Portfolio PRIVATE cxx_std_20)
