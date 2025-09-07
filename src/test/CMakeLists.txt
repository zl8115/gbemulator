add_executable(tests
    ../cpu.cpp
    ../cpu_instructions.cpp
    ../registers.cpp
    00.cpp 01.cpp 02.cpp 03.cpp 04.cpp 05.cpp 06.cpp 07.cpp 08.cpp 09.cpp 0a.cpp 0b.cpp 0c.cpp 0d.cpp 0e.cpp 0f.cpp
    10.cpp 11.cpp 12.cpp 13.cpp 14.cpp 15.cpp 16.cpp 17.cpp 18.cpp 19.cpp 1a.cpp 1b.cpp 1c.cpp 1d.cpp 1e.cpp 1f.cpp
)
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain)
target_include_directories(
    tests
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)
