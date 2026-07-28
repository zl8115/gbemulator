#include "ppu.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ppu transitions from HBLANK to OAM_SEARCH after one scanline", "[ppu]")
{
    gb::Ppu ppu; // lcdStatus defaults to 0 -> mode HBLANK (bits 0-1 = 00)

    ppu.Step(gb::CCycles{204});

    CHECK((ppu.Read(0xFF41) & 0b11) == static_cast<int>(gb::Ppu::Mode::OAM_SEARCH));
    CHECK(ppu.Read(0xFF44) == 1); // LY incremented
}

TEST_CASE("Ppu fires the VBLANK interrupt callback when LY reaches 144", "[ppu]")
{
    gb::Ppu ppu;
    bool vblankFired = false;
    ppu.SetVBlankInterruptCallback([&vblankFired] { vblankFired = true; });

    ppu.Write(0xFF44, 143); // LY = last visible line
    ppu.Step(gb::CCycles{204}); // finishes HBLANK of line 143 -> LY becomes 144 -> VBLANK

    CHECK(vblankFired);
    CHECK(ppu.Read(0xFF44) == 144);
    CHECK((ppu.Read(0xFF41) & 0b11) == static_cast<int>(gb::Ppu::Mode::VBLANK));
}

TEST_CASE("Ppu fires the mode-2 LCD STAT interrupt when selected", "[ppu]")
{
    gb::Ppu ppu;
    bool lcdFired = false;
    ppu.SetLcdInterruptCallback([&lcdFired] { lcdFired = true; });
    ppu.Write(0xFF41, 0b00100000); // Mode 2 (OAM) STAT interrupt select

    ppu.Step(gb::CCycles{204}); // HBLANK -> OAM_SEARCH transition (line 0 -> 1)

    CHECK(lcdFired);
}

TEST_CASE("Ppu wraps LY back to 0 after the last VBLANK line", "[ppu]")
{
    gb::Ppu ppu;
    ppu.Write(0xFF41, 0b01); // Mode VBLANK
    ppu.Write(0xFF44, 153);

    ppu.Step(gb::CCycles{456}); // CLOCKS_PER_SCANLINE = 80 + 172 + 204

    CHECK(ppu.Read(0xFF44) == 0);
    CHECK((ppu.Read(0xFF41) & 0b11) == static_cast<int>(gb::Ppu::Mode::OAM_SEARCH));
}

TEST_CASE("Ppu fires the LYC=LY STAT interrupt during the pixel-transfer-to-hblank transition", "[ppu]")
{
    gb::Ppu ppu;
    bool lcdFired = false;
    ppu.SetLcdInterruptCallback([&lcdFired] { lcdFired = true; });

    ppu.Write(0xFF44, 5); // LY = 5
    ppu.Write(0xFF45, 5); // LYC = 5
    ppu.Write(0xFF41, 0b01000010); // LYC int select (bit 6) + mode bits = OAM_SEARCH

    ppu.Step(gb::CCycles{80}); // OAM_SEARCH -> PIXEL_TRANSFER
    CHECK_FALSE(lcdFired);

    ppu.Step(gb::CCycles{172}); // PIXEL_TRANSFER -> HBLANK, LYC compare happens here

    CHECK(lcdFired);
    CHECK((ppu.Read(0xFF41) & 0b100) != 0); // STAT bit 2 (LYC=LY) set
}

TEST_CASE("Ppu VRAM and OAM are directly addressable", "[ppu]")
{
    gb::Ppu ppu;

    ppu.Write(0x8000, 0x42);
    CHECK(ppu.Read(0x8000) == 0x42);

    ppu.Write(0x9FFF, 0x24);
    CHECK(ppu.Read(0x9FFF) == 0x24);

    ppu.Write(0xFE00, 0x11);
    CHECK(ppu.Read(0xFE00) == 0x11);
}

TEST_CASE("Ppu display on/off toggles the expected LCDC bits", "[ppu]")
{
    gb::Ppu ppu;
    CHECK_FALSE(ppu.IsDisplayOn());

    ppu.SetDisplayOn();
    CHECK(ppu.IsDisplayOn());

    ppu.SetDisplayOff();
    CHECK_FALSE(ppu.IsDisplayOn());
}
