add_subdirectory(sm83)

# Test SM83 App
add_executable(Sm83TestApp
    main.cpp)
target_link_libraries(Sm83TestApp Sm83)
