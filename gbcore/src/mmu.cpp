#include "mmu.h"

#include "cartridge.h"
#include "input.h"
#include "mmu_register_names.h"
#include "ppu.h"
#include "timer.h"

namespace gb {

namespace {

constexpr bool IsTimerRegister(Address address)
{
    return address >= REG_DIVIDER_REGISTER && address <= REG_TIMER_CONTROL;
}

constexpr bool IsCartridgeRom(Address address)
{
    return address <= REGION_CATRIDGE_SWITCHABLE_END;
}

constexpr bool IsCartridgeExternalRam(Address address)
{
    return address >= REGION_CATRIDGE_EXTERNAL_RAM_START && address <= REGION_CATRIDGE_EXTERNAL_RAM_END;
}

constexpr bool IsVram(Address address)
{
    return address >= REGION_VRAM_START && address <= REGION_VRAM_END;
}

constexpr bool IsOam(Address address)
{
    return address >= REGION_OAM_START && address <= REGION_OAM_END;
}

constexpr bool IsPpuRegister(Address address)
{
    return address >= REG_LCD_CONTROL && address <= REG_WINDOW_POS_X && address != REG_DMA_TRANSFER_ADDRESS;
}

constexpr bool IsEchoRam(Address address)
{
    return address >= REGION_ECHO_RAM_START && address <= REGION_ECHO_RAM_END;
}

constexpr Address ECHO_RAM_OFFSET = REGION_ECHO_RAM_START - REGION_WORKING_RAM_START;

} // namespace

Reg8 Mmu::Read(const Address address) const
{
    if (m_cartridge && (IsCartridgeRom(address) || IsCartridgeExternalRam(address)))
        return m_cartridge->Read(address);

    if (m_ppu && (IsVram(address) || IsOam(address) || IsPpuRegister(address)))
        return m_ppu->Read(address);

    if (m_input && address == REG_P1_JOYPAD)
        return m_input->Read(address);

    if (m_timer && IsTimerRegister(address))
        return m_timer->Read(address);

    if (m_cartridge && address == REG_BOOT_ROM_MAPPING_CONTROL)
        return m_cartridge->Read(address);

    if (IsEchoRam(address))
        return m_memory[address - ECHO_RAM_OFFSET];

    return m_memory[address];
}

void Mmu::Write(const Address address, Reg8 byte)
{
    if (m_cartridge && (IsCartridgeRom(address) || IsCartridgeExternalRam(address)))
    {
        m_cartridge->Write(address, byte);
        return;
    }

    if (address == REG_DMA_TRANSFER_ADDRESS)
    {
        m_memory[address] = byte;
        if (m_ppu)
            PerformDmaTransfer(byte);
        return;
    }

    if (m_ppu && (IsVram(address) || IsOam(address) || IsPpuRegister(address)))
    {
        m_ppu->Write(address, byte);
        return;
    }

    if (m_input && address == REG_P1_JOYPAD)
    {
        m_input->Write(address, byte);
        return;
    }

    if (m_timer && IsTimerRegister(address))
    {
        m_timer->Write(address, byte);
        return;
    }

    if (m_cartridge && address == REG_BOOT_ROM_MAPPING_CONTROL)
    {
        m_cartridge->Write(address, byte);
        return;
    }

    if (IsEchoRam(address))
    {
        m_memory[address - ECHO_RAM_OFFSET] = byte;
        return;
    }

    m_memory[address] = byte;
}

void Mmu::PerformDmaTransfer(Reg8 sourceHighByte)
{
    constexpr Address OAM_SIZE = REGION_OAM_END - REGION_OAM_START + 1;
    Address sourceBase = static_cast<Address>(sourceHighByte) * 0x100;
    for (Address i = 0; i < OAM_SIZE; ++i)
    {
        m_ppu->Write(REGION_OAM_START + i, Read(sourceBase + i));
    }
}

void Mmu::MapTimer(Timer& timer)
{
    m_timer = &timer;
    timer.SetOverflowCallback([this] { SetInterruptFlag<InterruptType::TIMER>(); });
}

void Mmu::MapCartridge(Cartridge& cartridge)
{
    m_cartridge = &cartridge;
}

void Mmu::MapPpu(Ppu& ppu)
{
    m_ppu = &ppu;
}

void Mmu::MapInput(Input& input)
{
    m_input = &input;
}

} // namespace gb
