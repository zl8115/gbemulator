# Main SM83 CPU Library
add_library(Sm83 STATIC
    cpu.h
    cycles.h
    frame_buffer.h
    irenderer.h
    input.h
    mmu.h
    ppu.h
    soc.h

    catridge.cpp
    cpu.cpp
    cycles.cpp
    frame_buffer.cpp
    input.cpp
    mmu.cpp
    ppu.cpp
    soc.cpp

    detail/logger.cpp
    detail/catridge/catridge_impl.cpp
    detail/cpu/cpu_impl.cpp
    detail/cpu/opcode_cycles.cpp
    detail/cpu/timer.cpp
    detail/input/input_impl.cpp
    detail/memory/mmu_impl.cpp
    detail/video/ppu_impl.cpp
)
target_include_directories(
    Sm83
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add Unittests
add_subdirectory(test)
