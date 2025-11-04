#pragma once

#include <cstdint>
#include <vector>
#include <array>
#include <memory>

namespace detail {

class MmuImpl {
public:
    MmuImpl();

    uint8_t Read(const uint16_t address) const;
    void Write(const uint16_t address, uint8_t byte);
    void LoadRom(std::vector<uint8_t>&& romData);

private:
    void DmaTransfer(uint16_t address);

    std::unique_ptr<MmuImpl> m_pImpl;
    std::vector<uint8_t> m_rom;
    std::array<uint8_t, 0x10000> m_ram;
};

} // namespace detail
