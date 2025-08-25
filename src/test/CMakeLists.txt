# include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)

add_executable(tests
    ../Cpu.cpp
    ../MemoryBus.cpp
    ../Registers.cpp
    ../CpuOperator.cpp
    ../CpuTranslator.cpp
    00.cpp 01.cpp 02.cpp 03.cpp 04.cpp 05.cpp 06.cpp 07.cpp 08.cpp 09.cpp 0a.cpp 0b.cpp 0c.cpp 0d.cpp 0e.cpp 0f.cpp
    10.cpp 11.cpp 12.cpp 13.cpp 14.cpp 15.cpp 16.cpp 17.cpp 18.cpp 19.cpp 1a.cpp 1b.cpp 1c.cpp 1d.cpp 1e.cpp 1f.cpp
    # test.cpp # solution to the original problem
)
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain
            nlohmann_json::nlohmann_json)
target_include_directories(
    tests
    PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
# catch_discover_tests(
#   tests
#   TEST_PREFIX
#   "unittests."
#   REPORTER
#   XML
#   OUTPUT_DIR
#   .
#   OUTPUT_PREFIX
#   "unittests."
#   OUTPUT_SUFFIX
#   .xml)
