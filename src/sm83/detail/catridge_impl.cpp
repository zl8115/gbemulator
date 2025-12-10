#include "detail/catridge_impl.h"

#include "detail/catridge_bootrom.h"
#include "detail/impl_helper.h"
#include "detail/mmu_impl.h"
#include "detail/mmu_mapped_memory.h"
#include "detail/mmu_reg_names.h"
#include "mmu.h"

#include <utility>

constexpr uint32_t BANK_SIZE = REGION_CATRIDGE_SWITCHABLE_END - REGION_CATRIDGE_SWITCHABLE_START + 1;

namespace detail {

CatridgeImpl::CatridgeImpl(Mmu& mmu):
    m_ramEnable(false),
    m_bootRomEnabled(false),
    m_bankSelected(0),
    m_rom(),
    m_mapperChip(MapperChip::ROM_ONLY),
    m_fixedRomBank(),
    m_switchableRomBank(),
    m_externalRam(),
    m_pFixedRomBank(std::make_unique<MappedMemoryBlock>(m_fixedRomBank, 0, m_fixedRomBank.size())),
    m_pSwitchableRomBank(std::make_unique<MappedMemoryBlock>(m_switchableRomBank, 0, m_switchableRomBank.size())),
    m_pExternalRam(std::make_unique<MappedMemoryBlock>(m_externalRam, 0, m_externalRam.size()))
{
    ImplHelper::ExtractImpl(mmu).MapMemory(*this);
}

void CatridgeImpl::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
    ValidateRom();
    m_mapperChip = static_cast<MapperChip>(m_rom.at(0x0147));
}

void CatridgeImpl::EnableBootRom(bool enable)
{
    m_bootRomEnabled = enable;
}

bool CatridgeImpl::IsLoaded() const
{
    return m_rom.empty();
}

void CatridgeImpl::ValidateRom()
{
    // TODO: Validation
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

} // namespace detail
