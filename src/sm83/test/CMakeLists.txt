include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)

# Configure absolute path for the Sm83 test json files
set(SM83_TEST_DIR ${sm83testcases_SOURCE_DIR}/v1/)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/test_files.cpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/test_files.cpp
    @ONLY
)

add_executable(Sm83Tests
    tester.h

    tester.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/test_files.cpp
)
target_link_libraries(
    Sm83Tests
    PRIVATE
    Sm83
    nlohmann_json::nlohmann_json
    Catch2::Catch2WithMain
)
target_include_directories(
    Sm83Tests
    PRIVATE
    $<BUILD_INTERFACE:${Sm83}/detail>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${nlohmann_json_SOURCE_DIR}/include>
)
target_precompile_headers(
    Sm83Tests
    PRIVATE $<BUILD_INTERFACE:${Catch2_SOURCE_DIR}/src/catch2/catch_test_macros.hpp>
)
catch_discover_tests(Sm83Tests)
