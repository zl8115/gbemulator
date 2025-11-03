#include "cpu.h"
#include "cpu_instructions.h"

#include <cstdint>

Cpu::Cpu(Mmu& mmu, Registers& reg):
    m_reg(reg),
    m_mmu(mmu),
    m_inst(mmu, reg)
{}

int Cpu::Execute(uint8_t opcode)
{
    return m_inst.Execute(opcode);
}

int Cpu::Step()
{
    auto opcode = m_mmu.Read(m_reg.pc);
    return Execute(opcode);
}
