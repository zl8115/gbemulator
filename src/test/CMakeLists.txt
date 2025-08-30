add_executable(tests
    ../cpu.cpp
    ../cpu_instructions.cpp
    ../registers.cpp
    00.cpp
)
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain)
target_include_directories(
    tests
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)
