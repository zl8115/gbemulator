#include "gb_emulator.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("GbEmulator steps the CPU and drives the Timer forward", "[gb_emulator]")
{
    gb::GbEmulator emu;

    for (int i = 0; i < 200; ++i)
        emu.Step();

    // The boot ROM starts executing immediately at address 0; each instruction costs at
    // least one M-cycle (4 T-cycles), so 200 steps is well over DIV's 256 T-cycle period.
    CHECK(emu.GetMmu().Read(0xFF04) != 0);
}

TEST_CASE("GbEmulator wires LoadRom through the Mmu-mapped Cartridge", "[gb_emulator]")
{
    gb::GbEmulator emu;

    std::vector<uint8_t> rom(0x8000, 0);
    std::fill(rom.begin() + 0x4000, rom.begin() + 0x8000, static_cast<uint8_t>(0x7A));
    rom[0x147] = 0; // ROM_ONLY

    emu.LoadRom(std::move(rom));

    CHECK(emu.GetMmu().Read(0x4000) == 0x7A);
}

TEST_CASE("GbEmulator wires Input through the Mmu-mapped P1 register", "[gb_emulator]")
{
    gb::GbEmulator emu;
    emu.GetInput().ButtonPressed(gb::GbButton::A);

    emu.GetMmu().Write(0xFF00, 0b00010000); // select buttons group
    emu.GetInput().Step();

    CHECK((emu.GetMmu().Read(0xFF00) & 0x01) != 0); // A pressed, reflected through the Mmu
}
