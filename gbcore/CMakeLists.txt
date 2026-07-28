# add_subdirectory(sm83)
# add_subdirectory(sdl_renderer)
# add_subdirectory(sdl_gbemulator)
# add_subdirectory(soc_inspector)

add_library(gbcore STATIC
    src/cartridge.cpp
    src/cpu.cpp
    src/frame_buffer.cpp
    src/gb_emulator.cpp
    src/input.cpp
    src/mmu.cpp
    src/ppu.cpp
    src/timer.cpp

    src/detail/cpu_opcode.cpp
    src/detail/cpu_opcode_cycles.cpp)

target_include_directories(gbcore PUBLIC include)
# target_link_directories(gbcore PUBLIC spdlog::spdlog)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
