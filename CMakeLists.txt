cmake_minimum_required(VERSION 3.10)

project(
    GameBoyEmulator
    VERSION 0.0.1
    DESCRIPTION ""
    LANGUAGES CXX)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()
set(CMAKE_CXX_STANDARD_MINIMUM 20)

# Stolen from https://github.com/cpp-best-practices/cmake_template
# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
    src/main.cpp
    src/registers.cpp
    src/cpu.cpp
    src/cpu_instructions.cpp
)
