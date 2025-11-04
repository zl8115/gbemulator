#pragma once

#include <cstdint>
#include <vector>
#include <array>

class Mmu {
public:
    Mmu();

    uint8_t Read(const uint16_t address) const;
    void Write(const uint16_t address, uint8_t byte);
    void LoadRom(std::vector<uint8_t>&& romData);

    uint8_t& At(uint16_t address);
    uint8_t const& At(uint16_t address) const;

    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;

private:
    std::vector<uint8_t> m_rom;
    std::array<uint8_t, 0x10000> m_ram;
};
