# Main SM83 CPU Library
add_library(Sm83 STATIC
    bootrom.h
    cpu.h
    cpu_cycles.h
    cpu_instructions.h
    cycles.h
    frame_buffer.h
    irenderer.h
    mmu.h
    ppu.h
    registers.h
    soc.h

    cpu.cpp
    cpu_cycles.cpp
    cpu_instructions.cpp
    cycles.cpp
    frame_buffer.cpp
    mmu.cpp
    ppu.cpp
    registers.cpp
    soc.cpp

    detail/mmu_impl.cpp
    detail/ppu_impl.cpp
)
target_include_directories(
    Sm83
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add Unittests
add_subdirectory(test)

