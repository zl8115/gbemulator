add_executable(gbtest
    src/test_cpu.cpp
    src/test_timer.cpp)

target_link_libraries(gbtest PRIVATE
    gbcore
    Catch2::Catch2WithMain)

include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(gbtest)
