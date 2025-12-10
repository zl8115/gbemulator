#pragma once

#include "mmu.h"

namespace detail
{

class ImplHelper {
public:
    static MmuImpl& ExtractImpl(Mmu& mmu)
    {
        return *mmu.m_pImpl.get();
    }
};

} // namespace detail
