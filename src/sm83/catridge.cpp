#include "catridge.h"
#include "detail/catridge/catridge_impl.h"

#include <utility>

Catridge::Catridge(Mmu& mmu)
    : m_pImpl(std::make_unique<detail::CatridgeImpl>(mmu))
{}

Catridge::~Catridge() = default;
Catridge::Catridge(Catridge&&) noexcept = default;
Catridge& Catridge::operator=(Catridge&&) noexcept = default;

void Catridge::LoadRom(std::vector<uint8_t>&& romData)
{
    m_pImpl->LoadRom(std::forward<std::vector<uint8_t>>(romData));
}

bool Catridge::IsLoaded() const
{
    return m_pImpl->IsLoaded();
}
