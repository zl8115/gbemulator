#pragma once

#include "types.h"

#include <array>
#include <cstdint>
#include <vector>

namespace gb {

// Only ROM_ONLY and MBC1 banking are actually implemented (see cartridge.cpp);
// the rest of the header's mapper-chip byte values are recognized but not acted on.
enum class MapperChip : uint8_t
{
    ROM_ONLY                       = 0x00,
    MBC1,
    MBC1_RAM,
    MBC1_RAM_BATTERY,
    MBC2                           = 0x05,
    MBC2_RAM,
    ROM_RAM                        = 0x08,
    ROM_RAM_BATTERY,
    MMM01                         = 0x0B,
    MMM01_RAM,
    MMM01_RAM_BATTERY,
    MBC3_TIMER_BATTERY             = 0x0F,
    MBC3_TIMER_RAM_BATTERY,
    MBC3,
    MBC3_RAM,
    MBC3_RAM_BATTERY,
    MBC5                           = 0x19,
    MBC5_RAM,
    MBC5_RAM_BATTERY,
    MBC5_RUMBLE,
    MBC5_RUMBLE_RAM,
    MBC5_RUMBLE_RAM_BATTERY,
    MBC6                           = 0x20,
    MBC7_SENSOR_RUMBLE_RAM_BATTERY = 0x22,
    POCKET_CAMERA                  = 0xFC,
    BANDAI_TAMA5,
    HUC3,
    HUC1_RAM_BATTERY,
};

class Cartridge
{
public:
    Cartridge() = default;

    void LoadRom(std::vector<uint8_t>&& romData);
    [[nodiscard]] bool IsLoaded() const;

    [[nodiscard]] Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

private:
    static constexpr std::size_t ROM_BANK_SIZE = 0x4000;
    static constexpr std::size_t RAM_BANK_SIZE = 0x2000;
    static constexpr std::size_t EXTERNAL_RAM_BANKS = 4; // matches MBC1's max (32KB)

    bool m_ramEnable = false;
    bool m_bootRomEnabled = false;
    bool m_bankingMode = false;
    Reg8 m_switchableBankSelect = 0;
    Reg8 m_ramBankSelect = 0;
    Reg8 m_romSize = 2;
    Reg8 m_ramSize = 0;
    MapperChip m_mapperChip = MapperChip::ROM_ONLY;

    std::vector<uint8_t> m_rom;
    std::array<uint8_t, RAM_BANK_SIZE * EXTERNAL_RAM_BANKS> m_externalRam{};
};

} // namespace gb
