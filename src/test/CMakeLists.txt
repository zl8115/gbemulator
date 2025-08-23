# include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)

add_executable(tests
    ../Cpu.cpp
    ../MemoryBus.cpp
    ../Registers.cpp
    ../CpuOperator.cpp
    ../CpuTranslator.cpp
    00.cpp
    01.cpp
    02.cpp
    03.cpp
    04.cpp
    test.cpp # solution to the original problem
)
target_link_libraries(
    tests
    PRIVATE Catch2::Catch2WithMain
            RapidJSON
            rapidjson)
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
