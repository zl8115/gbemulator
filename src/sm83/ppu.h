#pragma once

class Mmu;

class Ppu
{
public:
    Ppu(Mmu& mmu);

private:
    Mmu& m_mmu;
};
