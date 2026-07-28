#include "cartridge.h"

#include "detail/boot_rom.h"

#include <cstring>

namespace gb {

void Cartridge::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::move(romData);

    m_mapperChip = static_cast<MapperChip>(m_rom.at(0x0147));
    m_romSize = m_rom.at(0x148);
    m_ramSize = m_rom.at(0x149);

    m_bootRomEnabled = true;
}

bool Cartridge::IsLoaded() const
{
    return !m_rom.empty();
}

Reg8 Cartridge::Read(const Address address) const
{
    if (address <= 0x3FFF) // Fixed bank 0 (boot ROM overlays the first 0x100 bytes until disabled)
    {
        if (m_bootRomEnabled && address < detail::BOOT_ROM_DMG.size())
            return detail::BOOT_ROM_DMG[address];

        if (!IsLoaded())
            return 0xFF;

        return m_rom[address];
    }

    if (address <= 0x7FFF) // Switchable bank
    {
        if (!IsLoaded())
            return 0xFF;

        std::size_t bank = (m_switchableBankSelect == 0) ? 1 : m_switchableBankSelect;
        if (m_bankingMode)
        {
            // Preserved from the original: due to operator precedence this evaluates as
            // `m_ramBankSelect & (0x3 << 6)`, not `(m_ramBankSelect & 0x3) << 6`, so the
            // upper ROM bank bits never actually apply in "advanced" banking mode. See plan.md.
            bank |= m_ramBankSelect & 0x3 << 6;
        }

        std::size_t offset = bank * ROM_BANK_SIZE + (address - 0x4000);
        return offset < m_rom.size() ? m_rom[offset] : 0xFF;
    }

    if (address == 0xFF50) // Boot ROM disable register
    {
        return m_bootRomEnabled ? 0 : 1;
    }

    if (address >= 0xA000 && address <= 0xBFFF) // External RAM
    {
        std::size_t offset = (m_ramBankSelect & 0x3) * RAM_BANK_SIZE;
        return m_externalRam[offset + (address - 0xA000)];
    }

    return 0xFF;
}

void Cartridge::Write(const Address address, Reg8 byte)
{
    if (address <= 0x1FFF) // RAM enable
    {
        m_ramEnable = (byte & 0xA) == 0xA;
        return;
    }

    if (address <= 0x3FFF) // ROM bank select (lower 5 bits)
    {
        m_switchableBankSelect = byte & 0x1F;
        return;
    }

    if (address <= 0x5FFF) // RAM bank select / upper ROM bank bits
    {
        m_ramBankSelect = byte & 0b11;
        return;
    }

    if (address <= 0x7FFF) // Banking mode select
    {
        m_bankingMode = byte & 0x1;
        return;
    }

    if (address == 0xFF50) // Boot ROM disable register
    {
        if (m_bootRomEnabled && byte != 0)
            m_bootRomEnabled = false;
        return;
    }

    if (address >= 0xA000 && address <= 0xBFFF) // External RAM
    {
        if (!m_ramEnable)
            return;

        std::size_t offset = (m_ramBankSelect & 0x3) * RAM_BANK_SIZE;
        m_externalRam[offset + (address - 0xA000)] = byte;
    }
}

} // namespace gb
