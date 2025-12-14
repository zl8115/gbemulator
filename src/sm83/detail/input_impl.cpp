#include "detail/input_impl.h"

#include "bitmanip.h"
#include "detail/impl_helper.h"
#include "detail/mmu_impl.h"
#include "detail/mmu_reg_names.h"

namespace detail {

InputImpl::InputImpl(Mmu& mmu):
    m_pressedUp(false),
    m_pressedDown(false),
    m_pressedLeft(false),
    m_pressedRight(false),
    m_pressedA(false),
    m_pressedB(false),
    m_pressedSelect(false),
    m_pressedStart(false),
    m_reg(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_P1_JOYPAD))
{}

void InputImpl::ButtonPressed(GbButton button)
{
    switch(button)
    {
        case GbButton::Up: m_pressedUp = true; break;
        case GbButton::Down: m_pressedDown = true; break;
        case GbButton::Left: m_pressedLeft = true; break;
        case GbButton::Right: m_pressedRight = true; break;
        case GbButton::A: m_pressedA = true; break;
        case GbButton::B: m_pressedB = true; break;
        case GbButton::Select: m_pressedSelect = true; break;
        case GbButton::Start: m_pressedStart = true; break;
    }
}

void InputImpl::ButtonReleased(GbButton button)
{
    switch(button)
    {
        case GbButton::Up: m_pressedUp = false; break;
        case GbButton::Down: m_pressedDown = false; break;
        case GbButton::Left: m_pressedLeft = false; break;
        case GbButton::Right: m_pressedRight = false; break;
        case GbButton::A: m_pressedA = false; break;
        case GbButton::B: m_pressedB = false; break;
        case GbButton::Select: m_pressedSelect = false; break;
        case GbButton::Start: m_pressedStart = false; break;
    }
}

void InputImpl::WriteInput()
{
    auto value = m_reg.Read();
    bool dPadSelect = !CheckBit<4>(value);
    bool buttonsSelect = !CheckBit<5>(value);

    if (dPadSelect)
    {
        SetBitTo<0>(value, m_pressedRight);
        SetBitTo<1>(value, m_pressedLeft);
        SetBitTo<2>(value, m_pressedUp);
        SetBitTo<3>(value, m_pressedDown);
    }
    else if (buttonsSelect)
    {
        SetBitTo<0>(value, m_pressedA);
        SetBitTo<1>(value, m_pressedB);
        SetBitTo<2>(value, m_pressedSelect);
        SetBitTo<3>(value, m_pressedStart);
    }
    else if (!dPadSelect && !buttonsSelect)
    {
        value |= 0x0F;
    }
    m_reg.Write(value);
}

} // namespace detail
