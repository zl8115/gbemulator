add_subdirectory(sm83)
add_subdirectory(sdl_renderer)
add_subdirectory(sdl_gbemulator)

# Test SM83 App
add_executable(Sm83TestApp
    main.cpp)
target_link_libraries(Sm83TestApp Sm83)
