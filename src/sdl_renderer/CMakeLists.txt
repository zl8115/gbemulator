add_library(SdlRenderer STATIC
    asset_renderer.h
    sdl_renderer.h

    asset_renderer.cpp
    sdl_renderer.cpp
    sdl_helpers.cpp
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
