#pragma once

#include <cstdint>
#include <vector>
#include <array>

namespace detail {

class MmuImpl {
public:
    friend class MappedRegister;
    friend class MappedMemoryBlock;

    MmuImpl();

    uint8_t Read(const uint16_t address) const;
    void Write(const uint16_t address, uint8_t byte);

private:
    void DmaTransfer(uint16_t address);

    std::array<uint8_t, 0x10000> m_map;
};

} // namespace detail
