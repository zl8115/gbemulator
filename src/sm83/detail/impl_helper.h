#pragma once

#include "cpu.h"
#include "mmu.h"

namespace detail
{

class ImplHelper {
public:
    static MmuImpl& ExtractImpl(Mmu& mmu)
    {
        return *mmu.m_pImpl.get();
    }

    static CpuImpl& ExtractImpl(Cpu& cpu)
    {
        return *cpu.m_pImpl.get();
    }

    static const CpuImpl& ExtractImpl(Cpu const& cpu)
    {
        return *cpu.m_pImpl.get();
    }
};

} // namespace detail
