#include "detail/catridge/catridge_impl.h"

#include "detail/catridge/mbc.h"
#include "detail/impl_helper.h"
#include "detail/catridge/bootrom.h"
#include "detail/memory/mmu_impl.h"
#include "detail/register_names.h"
#include "mmu.h"

#include <utility>
#include <cstring>

constexpr bool UseFixedMemory = true;
constexpr bool DoNotUseFixedMemory = false;

class Mmu;

namespace detail {

CatridgeImpl::CatridgeImpl(Mmu& mmu):
    m_ramEnable(false),
    m_bootRomEnabled(false),
    m_bankingMode(false),
    m_switchableBankSelect(0),
    m_ramBankSelect(0),
    m_romSize(2),
    m_ramSize(0),
    m_mapperChip(MapperChip::ROM_ONLY),
    m_pFixedRomBank(),
    m_pSwitchableRomBank(),
    m_pExternalRam(),
    m_bootRomReg(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_BOOT_ROM_MAPPING_CONTROL), std::bind(&CatridgeImpl::HandleBootRomRegWrite, this, std::placeholders::_1)),
    m_fixedRomBank(),
    m_switchableRomBank(),
    m_externalRam(),
    m_rom()
{
    using namespace std::placeholders;
    using MBC = CatridgeMemoryBlockController;

    auto fixedRomHandlerFunc = std::bind(&CatridgeImpl::HandleFixedRomWrite, this, _1, _2);
    m_pFixedRomBank = std::make_unique<MBC>(m_fixedRomBank, 0, m_fixedRomBank.size(), fixedRomHandlerFunc);

    auto switcherRomHandlerFunc = std::bind(&CatridgeImpl::HandleSwitchableRomWrite, this, _1, _2);
    m_pSwitchableRomBank = std::make_unique<MBC>(m_switchableRomBank, 0, m_switchableRomBank.size(), switcherRomHandlerFunc);

    auto externalRamHandlerFunc = std::bind(&CatridgeImpl::HandleExternalRamWrite, this, _1, _2);
    m_pExternalRam = std::make_unique<MBC>(m_externalRam, 0, m_externalRam.size(), externalRamHandlerFunc);

    ImplHelper::ExtractImpl(mmu).MapMemory(*this);
}

void CatridgeImpl::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
    ValidateRom();

    m_mapperChip = static_cast<MapperChip>(m_rom.at(0x0147));
    m_romSize = m_rom.at(0x148);
    m_ramSize = m_rom.at(0x149);

    std::memcpy(m_fixedRomBank.data(), m_rom.data(), m_fixedRomBank.size());
    LoadBootRom();
    SwitchFixedRom(UseFixedMemory, 0);
    SwitchSwitchableRom(DoNotUseFixedMemory, 0x4000); // Memory Bank 1
    SwitchExternalRam(UseFixedMemory, 0); // I don't actually know what to do with this...
}

void CatridgeImpl::LoadBootRom()
{
    m_bootRomEnabled = true;
    std::memcpy(m_fixedRomBank.data(), bootDMG.data(), bootDMG.size());
}

bool CatridgeImpl::IsLoaded() const
{
    return !m_rom.empty();
}

/*     ************** Private Methods *************     */
void CatridgeImpl::ValidateRom()
{
    // TODO: Validation
}

bool CatridgeImpl::HandleBootRomRegWrite(uint8_t value)
{
    if (m_bootRomEnabled && value != 0)
    {
        m_bootRomEnabled = false;
        SwitchRomBanks();
    }
    return true;
}

void CatridgeImpl::SwitchRomBanks()
{
    // We still want to switch out from the FixedMemory to DynamicMemory
    // to unload the bootrom, so we do not check if it is MapperChip::ROM_ONLY
    if (!IsLoaded())
    {
        return;
    }

    std::size_t adjustedBankSelection = ((m_switchableBankSelect & 0x1F) == 0)
        ? 0x1
        : m_switchableBankSelect & 0x1F;
    if (m_bankingMode)
    {
        adjustedBankSelection |= m_ramBankSelect & 0x3 << 6;
    }
    // TODO: Bit mask with maximum number of banks

    std::size_t offset = adjustedBankSelection * 0x4000;
    SwitchFixedRom(DoNotUseFixedMemory, 0);
    SwitchSwitchableRom(DoNotUseFixedMemory, offset);
}

void CatridgeImpl::SwitchRamBanks()
{
    if (!IsLoaded() || m_mapperChip == MapperChip::ROM_ONLY)
    {
        return;
    }
    std::size_t adjustedBankSelection = (m_ramBankSelect & 0x3);
    std::size_t offset = adjustedBankSelection * 0x4000;
    SwitchExternalRam(DoNotUseFixedMemory, offset);
}

namespace {

template <std::size_t N>
void SwitchMemoryBlock(
    MappedMemoryBlock& mappedMemoryBlock,
    MemoryBlock<N>& fixedMemoryBlock,
    std::vector<uint8_t>& dynamicMemoryBlock,
    bool useFixed,
    std::size_t offset)

{
    if (useFixed)
    {
        mappedMemoryBlock = MappedMemoryBlock(fixedMemoryBlock, 0, N);
        return;
    }
    mappedMemoryBlock = MappedMemoryBlock(dynamicMemoryBlock, offset, N);
}

} // namespace

void CatridgeImpl::SwitchFixedRom(bool useFixed, std::size_t offset)
{
    SwitchMemoryBlock(*m_pFixedRomBank, m_fixedRomBank, m_rom, useFixed, offset);
}

void CatridgeImpl::SwitchSwitchableRom(bool useFixed, std::size_t offset)
{
    SwitchMemoryBlock(*m_pSwitchableRomBank, m_switchableRomBank, m_rom, useFixed, offset);
}

void CatridgeImpl::SwitchExternalRam(bool useFixed, uint16_t offset)
{
    SwitchMemoryBlock(*m_pExternalRam, m_externalRam, m_rom, useFixed, offset);
}

bool CatridgeImpl::HandleFixedRomWrite(uint16_t address, uint8_t value)
{
    if (!IsLoaded())
        return true;

    if (address > 0x4000)
        return false;

    // Absolute addr range: 0x0000 - 0x1FFF
    if (address <= 0x1FFF)
    {
        m_ramEnable = (value & 0xA) == 0xA;
    }
    // Absolute addr range: 0x2000 - 0x3FFF
    else if (address <= 0x3FFF)
    {
        m_switchableBankSelect = 0;
        m_switchableBankSelect |= value & 0xF;
        SwitchRomBanks();
    }
    return false;
}

bool CatridgeImpl::HandleSwitchableRomWrite(uint16_t address, uint8_t value)
{
    if (!IsLoaded())
        return true;

    if (address > 0x4000)
        return false;

    // Absolute addr range: 0x4000 - 0x5FFF
    if (address <= 0x1FFF)
    {
        m_ramBankSelect = 0;
        m_ramBankSelect |= (value & 0b11);
    }

    // Absolute addr range: 0x6000 - 0x7FFF
    else if (address <= 0x3FFF)
    {
        // Switching banking mode enables "Advanced" bank switching for both ROM and RAM
        m_bankingMode = (value & 0x1);
        SwitchRomBanks();
    }
    SwitchRamBanks();
    return false;
}

bool CatridgeImpl::HandleExternalRamWrite(uint16_t address, uint8_t value)
{
    if (!IsLoaded())
        return true;

    return m_ramEnable;
}

} // namespace detail
