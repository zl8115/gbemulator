#pragma once

#include "mmu_mapped_memory.h"

#include <cstdint>
#include <vector>

class Mmu;

namespace detail {

enum class MapperChip: uint8_t
{
    ROM_ONLY                       = 0x00, // ROM ONLY
    MBC1,                                  // MBC1
    MBC1_RAM,                              // MBC1+RAM
    MBC1_RAM_BATTERY,                      // MBC1+RAM+BATTERY
    MBC2                           = 0x05, // MBC2
    MBC2_RAM,                              // MBC2+BATTERY
    ROM_RAM                        = 0x08, // ROM+RAM 11
    ROM_RAM_BATTERY,                       // ROM+RAM+BATTERY 11
    MMMO1                          = 0x0B, // MMM01
    MMMO1_RAM,                             // MMM01+RAM
    MMMO1_RAM_BATTERY,                     // MMM01+RAM+BATTERY
    MBC3_TIMER_BATTERY             = 0x0F, // MBC3+TIMER+BATTERY
    MBC3_TIMER_BATTERY_12,                 // MBC3+TIMER+RAM+BATTERY 12
    MBC3,                                  // MBC3
    MBC3_RAM,                              // MBC3+RAM 12
    MBC3_RAM_BATTERY,                      // MBC3+RAM+BATTERY 12
    MBC5                           = 0x19, // MBC5
    MBC5_RAM,                              // MBC5+RAM
    MBC5_RAM_BATTERY,                      // MBC5+RAM+BATTERY
    MBC5_RUMBLE,                           // MBC5+RUMBLE
    MBC5_RUMBLE_RAM,                       // MBC5+RUMBLE+RAM
    MBC5_RUMBLE_RAM_BATTERY,               // MBC5+RUMBLE+RAM+BATTERY
    MBC6                           = 0x20, // MBC6
    MBC7_SENSOR_RUMBLE_RAM_BATTERY = 0x22, // MBC7+SENSOR+RUMBLE+RAM+BATTERY
    POCKET_CAMERA                  = 0xFC, // POCKET CAMERA
    BANDAI_TAMA5,                          // BANDAI TAMA5
    HUC3,                                  // HuC3
    HUC1_RAM_BATTERY                       // HuC1+RAM+BATTERY
};

class CatridgeImpl
{
public:
    CatridgeImpl(Mmu& mmu);

    void LoadRom(std::vector<uint8_t>&& romData);
    uint8_t Read(uint8_t address) const;
    void Write(uint8_t address, uint8_t value);

    void EnableBootRom(bool enable);
    bool IsLoaded() const;

private:
    void ValidateRom();
    uint32_t GetBankOffset(uint8_t address) const;

    bool m_ramEnable;
    bool m_bootRomEnabled;
    uint8_t m_bankSelected;
    std::vector<uint8_t> m_rom;
    MapperChip m_mapperChip;
    MappedMemoryBlock m_mappedRom;
    MappedMemoryBlock m_externalRam;
};

} // namespace detail
