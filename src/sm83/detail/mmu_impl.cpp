#include "mmu_impl.h"
#include "mmu_reg_names.h"

#include <memory.h>

namespace detail {

MmuImpl::MmuImpl()
{}

uint8_t MmuImpl::Read(const uint16_t address) const
{
    return m_map.at(address);
}

void MmuImpl::Write(const uint16_t address, uint8_t byte)
{
    m_map.at(address) = byte;

    if (address == REG_DMA_TRANSFER_ADDRESS)
    {
        DmaTransfer(byte);
    }
}

void MmuImpl::DmaTransfer(uint16_t address)
{
    // TODO: Lock the MMU for the duration of the transfer

    uint16_t startAddress = address * 0x100;
    uint8_t* pSrc = m_map.data() + startAddress;
    uint8_t* pDst = m_map.data() + REGION_OAM_START;
    constexpr auto OAM_SIZE = REGION_OAM_END - REGION_OAM_START + 1;
    memcpy(pDst, pSrc, sizeof(uint8_t) * OAM_SIZE); // 0xA0 addresses
}

} // namespace detail
