target_sources(Portfolio
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/home.cpp
)

target_include_directories(Portfolio
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../include
)

target_link_libraries(Portfolio
    PRIVATE
        nui-frontend
)

set(PREJS_FILE
    ${CMAKE_CURRENT_LIST_DIR}/js/module.js
)

nui_prepare_emscripten_target(
    TARGET
        Portfolio
    NO_INLINE
    OBSERVED_BUNDLE_FILES
        ${PORTFOLIO_STATIC_FILES}
    PARCEL_ARGS
    PREJS
        ${PREJS_FILE}
    EMSCRIPTEN_LINK_OPTIONS
        -sEXPORTED_FUNCTIONS=_frontendMain
        -O2
        -sALLOW_MEMORY_GROWTH=1
    EMSCRIPTEN_COMPILE_OPTIONS
        -O3
)
