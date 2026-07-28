#include "cartridge.h"

#include <catch2/catch_test_macros.hpp>

namespace {

// Builds a fake MBC1 ROM with `bankCount` 0x4000-byte banks, each bank filled
// with its own bank index so reads can be attributed to a specific bank.
std::vector<uint8_t> MakeFakeRom(std::size_t bankCount)
{
    std::vector<uint8_t> rom(bankCount * 0x4000, 0);
    for (std::size_t bank = 0; bank < bankCount; ++bank)
    {
        std::fill(rom.begin() + bank * 0x4000, rom.begin() + (bank + 1) * 0x4000, static_cast<uint8_t>(bank));
    }

    rom[0x147] = static_cast<uint8_t>(gb::MapperChip::MBC1);
    rom[0x148] = 0;
    rom[0x149] = 0;
    return rom;
}

} // namespace

TEST_CASE("Cartridge reads boot ROM until it is disabled", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));

    CHECK(cart.Read(0x0000) == 0x31); // First boot ROM byte
    CHECK(cart.Read(0x0000) != 0);    // Bank 0 is filled with 0, so this proves it's not cart data

    cart.Write(0xFF50, 1); // Disable boot ROM

    CHECK(cart.Read(0x0000) == 0); // Now reads bank 0 cart data
}

TEST_CASE("Cartridge fixed bank always reads bank 0", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));
    cart.Write(0xFF50, 1); // Disable boot ROM so we see raw cart data

    CHECK(cart.Read(0x1000) == 0);
}

TEST_CASE("Cartridge switches ROM banks via the bank-select register", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));

    cart.Write(0x2000, 2); // Select bank 2

    CHECK(cart.Read(0x4000) == 2);
}

TEST_CASE("Cartridge maps bank-select 0 to bank 1", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));

    cart.Write(0x2000, 0);

    CHECK(cart.Read(0x4000) == 1);
}

TEST_CASE("Cartridge advanced banking mode's upper ROM bank bits never apply (known bug, see plan.md)", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(8));

    cart.Write(0x2000, 1);    // Select bank 1 (lower bits)
    cart.Write(0x6000, 1);    // Enable advanced banking mode
    cart.Write(0x4000, 0b01); // Attempt to select upper bank bits -> bank 1 | (1 << 6) = 65

    // Due to the preserved operator-precedence bug, this still resolves to bank 1, not 65.
    CHECK(cart.Read(0x4000) == 1);
}

TEST_CASE("Cartridge external RAM ignores writes while RAM is disabled", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));

    cart.Write(0xA000, 0x42);
    CHECK(cart.Read(0xA000) == 0);
}

TEST_CASE("Cartridge external RAM is read/write once enabled", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));

    cart.Write(0x0000, 0x0A); // Enable RAM
    cart.Write(0xA000, 0x42);

    CHECK(cart.Read(0xA000) == 0x42);
}

TEST_CASE("Cartridge external RAM banks are independent", "[cartridge]")
{
    gb::Cartridge cart;
    cart.LoadRom(MakeFakeRom(4));
    cart.Write(0x0000, 0x0A); // Enable RAM

    cart.Write(0x4000, 0); // RAM bank 0
    cart.Write(0xA000, 0x11);

    cart.Write(0x4000, 1); // RAM bank 1
    cart.Write(0xA000, 0x22);

    cart.Write(0x4000, 0); // Back to RAM bank 0
    CHECK(cart.Read(0xA000) == 0x11);
}
