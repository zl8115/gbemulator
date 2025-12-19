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

    static const MmuImpl& ExtractImpl(const Mmu& mmu)
    {
        return *mmu.m_pImpl.get();
    }

    static CpuImpl& ExtractImpl(Cpu& cpu)
    {
        return *cpu.m_pImpl.get();
    }

    static const CpuImpl& ExtractImpl(const Cpu& cpu)
    {
        return *cpu.m_pImpl.get();
    }
};

} // namespace detail
