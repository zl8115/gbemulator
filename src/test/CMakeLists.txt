add_executable(tests
    ../cpu.cpp
    ../cpu_instructions.cpp
    ../registers.cpp
    00.cpp 01.cpp 02.cpp 03.cpp 04.cpp 05.cpp 06.cpp 07.cpp 08.cpp 09.cpp 0a.cpp 0b.cpp 0c.cpp 0d.cpp 0e.cpp 0f.cpp
    10.cpp 11.cpp 12.cpp 13.cpp 14.cpp 15.cpp 16.cpp 17.cpp 18.cpp 19.cpp 1a.cpp 1b.cpp 1c.cpp 1d.cpp 1e.cpp 1f.cpp
    20.cpp 21.cpp 22.cpp 23.cpp 24.cpp 25.cpp 26.cpp 27.cpp 28.cpp 29.cpp 2a.cpp 2b.cpp 2c.cpp 2d.cpp 2e.cpp 2f.cpp
    30.cpp 31.cpp 32.cpp 33.cpp 34.cpp 35.cpp 36.cpp 37.cpp 38.cpp 39.cpp 3a.cpp 3b.cpp 3c.cpp 3d.cpp 3e.cpp 3f.cpp
    40.cpp 41.cpp 42.cpp 43.cpp 44.cpp 45.cpp 46.cpp 47.cpp 48.cpp 49.cpp 4a.cpp 4b.cpp 4c.cpp 4d.cpp 4e.cpp 4f.cpp
    50.cpp 51.cpp 52.cpp 53.cpp 54.cpp 55.cpp 56.cpp 57.cpp 58.cpp 59.cpp 5a.cpp 5b.cpp 5c.cpp 5d.cpp 5e.cpp 5f.cpp
    60.cpp 61.cpp 62.cpp 63.cpp 64.cpp 65.cpp 66.cpp 67.cpp 68.cpp 69.cpp 6a.cpp 6b.cpp 6c.cpp 6d.cpp 6e.cpp 6f.cpp
)
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain)
target_precompile_headers(
    tests
    PRIVATE $<BUILD_INTERFACE:${Catch2_SOURCE_DIR}/src/catch2/catch_test_macros.hpp>
)
target_include_directories(
    tests
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)
