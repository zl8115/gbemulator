#pragma once

#include <cstdint>
#include <vector>

class Mmu {
public:
    Mmu();

    uint8_t Read(const uint16_t& address) const;
    void Write(const uint16_t& address, uint8_t byte);

    void LoadRom(std::vector<uint8_t>&& romData);

private:
    std::vector<uint8_t> m_rom;
    uint8_t m_ram[0x10000];
};
