#include "impl_helper.h"
#include "catridge_impl.h"
#include "catridge_bootrom.h"
#include "detail/mmu_reg_names.h"
#include "mmu.h"
#include "detail/mmu_impl.h"

constexpr uint32_t BANK_SIZE = REGION_CATRIDGE_SWITCHABLE_END - REGION_CATRIDGE_SWITCHABLE_START + 1;

namespace detail {

CatridgeImpl::CatridgeImpl(Mmu& mmu):
    m_ramEnable(false),
    m_bootRomEnabled(false),
    m_bankSelected(0),
    m_rom(),
    m_mapperChip(MapperChip::ROM_ONLY),
    m_mappedRom(ImplHelper::ExtractImpl(mmu), REGION_CATRIDGE_FIXED_START, REGION_CATRIDGE_FIXED_END - REGION_CATRIDGE_FIXED_START + 1),
    m_externalRam(ImplHelper::ExtractImpl(mmu), REGION_CATRIDGE_EXTERNAL_RAM_START, REGION_CATRIDGE_EXTERNAL_RAM_END - REGION_CATRIDGE_EXTERNAL_RAM_START + 1)
{}

void CatridgeImpl::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
    ValidateRom();
    m_mapperChip = static_cast<MapperChip>(m_rom.at(0x0147));
}

uint8_t CatridgeImpl::Read(uint8_t address) const
{
    if (m_bootRomEnabled &&
       (address >= 0x0000 && address <= 0x00FF))
    {
        return bootDMG.at(address);
    }
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

} // namespace detail
