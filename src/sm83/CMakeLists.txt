# Main SM83 CPU Library
add_library(Sm83 STATIC
    cpu.h
    cpu_instructions.h
    registers.h

    cpu.cpp
    cpu_instructions.cpp
    registers.cpp)
target_include_directories(
    Sm83
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add Unittests
add_subdirectory(test)

