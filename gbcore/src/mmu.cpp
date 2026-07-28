#include "mmu.h"

#include "mmu_register_names.h"
#include "timer.h"

namespace gb {

namespace {

constexpr bool IsTimerRegister(Address address)
{
    return address >= REG_DIVIDER_REGISTER && address <= REG_TIMER_CONTROL;
}

} // namespace

Reg8 Mmu::Read(const Address address) const
{
    if (m_timer && IsTimerRegister(address))
        return m_timer->Read(address);

    return m_memory[address];
}

void Mmu::Write(const Address address, Reg8 byte)
{
    if (m_timer && IsTimerRegister(address))
    {
        m_timer->Write(address, byte);
        return;
    }

    m_memory[address] = byte;
}

void Mmu::MapTimer(Timer& timer)
{
    m_timer = &timer;
    timer.SetOverflowCallback([this] { SetInterruptFlag<InterruptType::TIMER>(); });
}

} // namespace gb
