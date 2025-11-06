add_library(SdlRenderer STATIC
    sdl_renderer.h
    sdl_renderer.cpp
)
target_link_libraries(
    SdlRenderer
    PRIVATE
    Sm83
    SDL3::SDL3
)
target_include_directories(
    SdlRenderer
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}

    PRIVATE
    $<BUILD_INTERFACE:${SDL3_SOURCE_DIR}/include>
)
