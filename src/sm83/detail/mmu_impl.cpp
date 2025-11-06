#include "mmu_impl.h"
#include "bootrom.h"

#include <iterator>
#include <memory.h>

constexpr uint16_t DMA_TRANSFER_ADDRESS = 0xFF46;
constexpr uint16_t OAM_START_ADDRESS = 0xFE00;
constexpr uint16_t OAM_END_ADDRESS = 0xFE9F;

namespace detail {

MmuImpl::MmuImpl()
{
    memset(m_ram.data(), 0, std::size(m_ram));
    memcpy(m_ram.data(), bootDMG.data(), std::size(bootDMG));
}

uint8_t MmuImpl::Read(const uint16_t address) const
{
    return m_ram.at(address);
}

void MmuImpl::Write(const uint16_t address, uint8_t byte)
{
    m_ram.at(address) = byte;

    if (address == DMA_TRANSFER_ADDRESS)
    {
        DmaTransfer(byte);
    }
}

void MmuImpl::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
    uint8_t chipType = m_rom.at(0x0147);
    if (chipType != static_cast<uint8_t>(MapperChip::ROM_ONLY))
    {
        throw std::runtime_error("Unsupported ROM with mapper chip type.");
    }

    if (m_rom.size() > 32768)
    {
        throw std::runtime_error("ROM (Only) is too large.");
    }

    memcpy(m_ram.data(), m_rom.data(), std::size(m_rom));
    memcpy(m_ram.data(), bootDMG.data(), std::size(bootDMG));
}

void MmuImpl::DmaTransfer(uint16_t address)
{
    // TODO: Lock the MMU for the duration of the transfer

    uint16_t startAddress = address * 0x100;
    uint8_t* pSrc = m_ram.data() + startAddress;
    uint8_t* pDst = m_ram.data() + OAM_START_ADDRESS;
    memcpy(pDst, pSrc, sizeof(uint8_t) * 160); // 0xA0 addresses
}

} // namespace detail
