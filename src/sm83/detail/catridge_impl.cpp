#include "detail/catridge_impl.h"

#include "detail/catridge_bootrom.h"
#include "detail/impl_helper.h"
#include "detail/mmu_impl.h"
#include "detail/mmu_mapped_memory.h"
#include "detail/mmu_reg_names.h"
#include "mmu.h"

#include <utility>
#include <cstring>

constexpr uint32_t BANK_SIZE = REGION_CATRIDGE_SWITCHABLE_END - REGION_CATRIDGE_SWITCHABLE_START + 1;

namespace detail {

CatridgeImpl::CatridgeImpl(Mmu& mmu):
    m_ramEnable(false),
    m_bootRomEnabled(false),
    m_bankingMode(false),
    m_switchableBankSelect(0),
    m_ramBankSelect(0),
    m_romSize(2),
    m_ramSize(2),
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
}

void CatridgeImpl::LoadBootRom()
{
    m_bootRomEnabled = true;
    std::memcpy(m_fixedRomBank.data(), bootDMG.data(), bootDMG.size());

    MappedMemoryBlock& fixedRomBank = *m_pFixedRomBank;
    fixedRomBank = MappedMemoryBlock(m_rom, 0, m_fixedRomBank.size());
}

bool CatridgeImpl::IsLoaded() const
{
    return !m_rom.empty();
}

WeakMappedMemoryBlock CatridgeImpl::GetMemoryFixedRomBank() const
{
    return WeakMappedMemoryBlock(m_pFixedRomBank);
}

WeakMappedMemoryBlock CatridgeImpl::GetMemorySwitchableRomBank() const
{
    return WeakMappedMemoryBlock(m_pSwitchableRomBank);
}

WeakMappedMemoryBlock CatridgeImpl::GetMemoryExternalRam() const
{
    return WeakMappedMemoryBlock(m_pExternalRam);
}

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
    if (!IsLoaded() || m_mapperChip == MapperChip::ROM_ONLY)
    {
        return;
    }

    std::size_t adjustedBankSelection = ((m_switchableBankSelect & 0x1F) == 0)
        ? 0x1
        : m_switchableBankSelect & 0x1F;
    if (!m_bankingMode)
    {
        adjustedBankSelection |= m_ramBankSelect & 0x3 << 6;
    }
    // TODO: Bit mask with maximum number of banks

    std::size_t offset = adjustedBankSelection * 0x4000;

    MappedMemoryBlock& externalRam = *m_pExternalRam;
    externalRam = MappedMemoryBlock(m_externalRam, offset, m_externalRam.size());
}

void CatridgeImpl::SwitchRamBanks()
{
    if (!IsLoaded() || m_mapperChip == MapperChip::ROM_ONLY)
    {
        return;
    }

    if (!m_bankingMode)
    {
        SwitchRomBanks();
        return;
    }

    std::size_t adjustedBankSelection = (m_ramBankSelect & 0x3);
    std::size_t offset = adjustedBankSelection * 0x4000;

    MappedMemoryBlock& fixedRomBank = *m_pFixedRomBank;
    fixedRomBank = MappedMemoryBlock(m_rom, offset, m_fixedRomBank.size());

    MappedMemoryBlock& switchableRomBank = *m_pSwitchableRomBank;
    switchableRomBank = MappedMemoryBlock(m_rom, offset, m_switchableRomBank.size());
}

bool CatridgeImpl::HandleFixedRomWrite(uint16_t address, uint8_t value)
{
    if (!IsLoaded())
        return true;

    if (address <= 0x1FFF)
    {
        m_ramEnable = (value & 0xA) == 0xA;
    }
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

    // Absolute addr range: 0x4000 - 0x5FFF
    if (address <= 0x1FFF)
    {
        m_ramBankSelect = 0;
        m_ramBankSelect |= (value & 0b11);
        SwitchRamBanks();
    }
    // Absolute addr range: 0x4000 - 0x5FFF
    else if (address <= 0x3FFF)
    {
        m_ramBankSelect = 0;
        m_bankingMode = (value & 0x1);
        SwitchRamBanks();
    }
    return false;
}

bool CatridgeImpl::HandleExternalRamWrite(uint16_t address, uint8_t value)
{
    if (!IsLoaded())
        return true;

    return m_ramEnable;
}

} // namespace detail
