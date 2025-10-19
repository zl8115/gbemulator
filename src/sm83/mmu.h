#pragma once

#include <cstdint>

class Mmu {
public:
    Mmu();

    uint8_t Read(const uint16_t& address) const;
    void Write(const uint16_t& address, uint8_t byte);

private:
    uint8_t m_ram[0x10000];
};
