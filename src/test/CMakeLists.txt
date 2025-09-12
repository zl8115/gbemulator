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
    70.cpp 71.cpp 72.cpp 73.cpp 74.cpp 75.cpp 76.cpp 77.cpp 78.cpp 79.cpp 7a.cpp 7b.cpp 7c.cpp 7d.cpp 7e.cpp 7f.cpp
    80.cpp 81.cpp 82.cpp 83.cpp 84.cpp 85.cpp 86.cpp 87.cpp 88.cpp 89.cpp 8a.cpp 8b.cpp 8c.cpp 8d.cpp 8e.cpp 8f.cpp
    90.cpp 91.cpp 92.cpp 93.cpp 94.cpp 95.cpp 96.cpp 97.cpp 98.cpp 99.cpp 9a.cpp 9b.cpp 9c.cpp 9d.cpp 9e.cpp 9f.cpp
    a0.cpp a1.cpp a2.cpp a3.cpp a4.cpp a5.cpp a6.cpp a7.cpp a8.cpp a9.cpp aa.cpp ab.cpp ac.cpp ad.cpp ae.cpp af.cpp
    b0.cpp b1.cpp b2.cpp b3.cpp b4.cpp b5.cpp b6.cpp b7.cpp b8.cpp b9.cpp ba.cpp bb.cpp bc.cpp bd.cpp be.cpp bf.cpp
    c0.cpp c1.cpp c2.cpp c3.cpp c4.cpp c5.cpp c6.cpp c7.cpp c8.cpp c9.cpp ca.cpp        cc.cpp cd.cpp ce.cpp cf.cpp
    d0.cpp d1.cpp d2.cpp        d4.cpp d5.cpp d6.cpp d7.cpp d8.cpp d9.cpp da.cpp        dc.cpp        de.cpp df.cpp
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
