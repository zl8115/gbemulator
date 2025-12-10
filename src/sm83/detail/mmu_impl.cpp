#include "detail/mmu_impl.h"

#include "detail/catridge_impl.h"
#include "detail/mmu_mapped_memory.h"
#include "detail/mmu_reg_names.h"
#include "detail/ppu_impl.h"

#include <memory.h>
#include <stdexcept>

namespace detail {

MmuImpl::MmuImpl():
    m_testMode(false),
    m_romBankA(),
    m_romBankB(),
    m_videoRam(),
    m_externalRam(),
    m_workingRam(),
    m_echoRam(m_workingRam, 0, 0x1E00),
    m_objectAttributeMemory(),
    m_notUsable(),
    m_input(),
    m_highRam(),
    m_interruptEnable()
{
    memset(m_workingRam.data(), 0, m_workingRam.size());
    memset(m_notUsable.data(), 0, m_notUsable.size());
    memset(m_highRam.data(), 0, m_highRam.size());
}

uint8_t MmuImpl::Read(const uint16_t address) const
{
    uint16_t relativeAddress = address;
    if (address <= REGION_CATRIDGE_FIXED_END)
    {
        return m_romBankA.Read(relativeAddress);
    }

    if (address <= REGION_CATRIDGE_SWITCHABLE_END)
    {
        relativeAddress = address - REGION_CATRIDGE_SWITCHABLE_START;
        return m_romBankB.Read(relativeAddress);
    }

    if (address <= REGION_VRAM_END)
    {
        relativeAddress = address - REGION_VRAM_START;
        return m_videoRam.Read(relativeAddress);
    }

    if (address <= REGION_CATRIDGE_EXTERNAL_RAM_END)
    {
        relativeAddress = address - REGION_CATRIDGE_EXTERNAL_RAM_START;
        return m_externalRam.Read(relativeAddress);
    }

    if (address <= REGION_WORKING_RAM_END)
    {
        relativeAddress = address - REGION_WORKING_RAM_START;
        return m_workingRam.at(relativeAddress);
    }

    if (address <= REGION_ECHO_RAM_END)
    {
        relativeAddress = address - REGION_ECHO_RAM_START;
        return m_echoRam.Read(relativeAddress);
    }

    if (address <= REGION_OAM_END)
    {
        relativeAddress = address - REGION_OAM_START;
        return m_objectAttributeMemory.Read(relativeAddress);
    }

    if (address <= REGION_UNUSABLE_END)
    {
        // TODO: Log Error
        relativeAddress = address - REGION_UNUSABLE_START;
        return m_objectAttributeMemory.Read(relativeAddress);
    }

    if (address <= REGION_IO_REGISTERS_END)
    {
        relativeAddress = address - REGION_IO_REGISTERS_START;
        return m_input.at(relativeAddress);
    }

    if (address <= REGION_HIGH_RAM_END)
    {
        relativeAddress = address - REGION_HIGH_RAM_START;
        return m_highRam.at(relativeAddress);
    }

    if (address == REG_INTERUPT_ENABLE)
    {
        return m_interruptEnable;
    }

    throw std::out_of_range("Accessing address out of range");
}

void MmuImpl::Write(const uint16_t address, uint8_t byte)
{
    uint16_t relativeAddress = address;
    if (address <= REGION_CATRIDGE_FIXED_END)
    {
        m_romBankA.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_CATRIDGE_SWITCHABLE_END)
    {
        relativeAddress = address - REGION_CATRIDGE_SWITCHABLE_START;
        m_romBankB.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_VRAM_END)
    {
        relativeAddress = address - REGION_VRAM_START;
        m_videoRam.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_CATRIDGE_EXTERNAL_RAM_END)
    {
        relativeAddress = address - REGION_CATRIDGE_EXTERNAL_RAM_START;
        m_externalRam.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_WORKING_RAM_END)
    {
        relativeAddress = address - REGION_WORKING_RAM_START;
        m_workingRam.at(relativeAddress) = byte;
        return;
    }

    if (address <= REGION_ECHO_RAM_END)
    {
        // TODO: Log err
        relativeAddress = address - REGION_ECHO_RAM_START;
        m_echoRam.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_OAM_END)
    {
        relativeAddress = address - REGION_OAM_START;
        m_objectAttributeMemory.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_UNUSABLE_END)
    {
        // TODO: Log err
        relativeAddress = address - REGION_UNUSABLE_START;
        m_objectAttributeMemory.Write(relativeAddress, byte);
        return;
    }

    if (address <= REGION_IO_REGISTERS_END)
    {
        relativeAddress = address - REGION_IO_REGISTERS_START;
        m_input.at(relativeAddress) = byte;
        return;
    }

    if (address <= REGION_HIGH_RAM_END)
    {
        relativeAddress = address - REGION_HIGH_RAM_START;
        m_highRam.at(relativeAddress) = byte;

        if (address == REG_DMA_TRANSFER_ADDRESS)
        {
            DmaTransfer(byte);
        }
        return;
    }

    if (address == REG_INTERUPT_ENABLE)
    {
        m_interruptEnable = byte;
        return;
    }

    throw std::out_of_range("Accessing address out of range");
}

void MmuImpl::DmaTransfer(uint16_t address)
{
    if (m_testMode)
        return;

    uint16_t startAddress = address * 0x100;
    constexpr auto OAM_SIZE = REGION_OAM_END - REGION_OAM_START + 1;
    for (int ii = 0; ii < sizeof(uint8_t) * OAM_SIZE; ++ii)
    {
        m_objectAttributeMemory.Write(ii, Read(startAddress + ii));
    }
}

MappedRegister MmuImpl::GetMappedRegister(const uint16_t address)
{
    if (address < REGION_IO_REGISTERS_START || address > REGION_HIGH_RAM_END)
    {
        throw std::out_of_range("Attempting to map register out of range");
    }

    uint16_t relativeAddress = 0;
    if (address <= REGION_IO_REGISTERS_END)
    {
        relativeAddress = address - REGION_IO_REGISTERS_START;
        return MappedRegister(m_input.at(relativeAddress));
    }

    if (address <= REGION_HIGH_RAM_END)
    {
        relativeAddress = address - REGION_HIGH_RAM_START;
        return MappedRegister(m_highRam.at(relativeAddress));
    }

    throw std::out_of_range("Attempting to map register out of range");
}

void MmuImpl::MapMemory(const PpuImpl& ppu)
{
    m_videoRam = ppu.GetMemoryVram();
    m_objectAttributeMemory = ppu.GetMemoryOam();
}

void MmuImpl::MapMemory(const CatridgeImpl& catridge)
{
    m_romBankA = catridge.GetMemoryFixedRomBank();
    m_romBankB = catridge.GetMemorySwitchableRomBank();
    m_externalRam = catridge.GetMemoryExternalRam();
}

void MmuImpl::DisableTestMode()
{
    m_testMode = false;
    m_echoRam = MappedMemoryBlock(m_workingRam, 0, 0x1E00);
}

void MmuImpl::EnableTestMode()
{
    m_testMode = true;
    if (!m_fakeEchoRam.has_value())
    {
        m_fakeEchoRam.emplace();
        memset(m_fakeEchoRam->data(), 0, m_fakeEchoRam->size());
    }
    m_echoRam = MappedMemoryBlock(m_fakeEchoRam.value(), 0, 0x1E00);
}

} // namespace detail
