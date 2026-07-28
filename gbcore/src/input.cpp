#include "input.h"

#include "utils/bitmanip.h"

namespace gb {

void Input::ButtonPressed(GbButton button)
{
    switch (button)
    {
    case GbButton::Up:     m_pressedUp = true; break;
    case GbButton::Down:   m_pressedDown = true; break;
    case GbButton::Left:   m_pressedLeft = true; break;
    case GbButton::Right:  m_pressedRight = true; break;
    case GbButton::A:      m_pressedA = true; break;
    case GbButton::B:      m_pressedB = true; break;
    case GbButton::Select: m_pressedSelect = true; break;
    case GbButton::Start:  m_pressedStart = true; break;
    }
}

void Input::ButtonReleased(GbButton button)
{
    switch (button)
    {
    case GbButton::Up:     m_pressedUp = false; break;
    case GbButton::Down:   m_pressedDown = false; break;
    case GbButton::Left:   m_pressedLeft = false; break;
    case GbButton::Right:  m_pressedRight = false; break;
    case GbButton::A:      m_pressedA = false; break;
    case GbButton::B:      m_pressedB = false; break;
    case GbButton::Select: m_pressedSelect = false; break;
    case GbButton::Start:  m_pressedStart = false; break;
    }
}

void Input::Step()
{
    bool dPadSelect = !utils::CheckBit<4>(m_reg);
    bool buttonsSelect = !utils::CheckBit<5>(m_reg);

    if (dPadSelect)
    {
        utils::SetBitTo<0>(m_reg, m_pressedRight);
        utils::SetBitTo<1>(m_reg, m_pressedLeft);
        utils::SetBitTo<2>(m_reg, m_pressedUp);
        utils::SetBitTo<3>(m_reg, m_pressedDown);
    }
    else if (buttonsSelect)
    {
        utils::SetBitTo<0>(m_reg, m_pressedA);
        utils::SetBitTo<1>(m_reg, m_pressedB);
        utils::SetBitTo<2>(m_reg, m_pressedSelect);
        utils::SetBitTo<3>(m_reg, m_pressedStart);
    }
    else if (!dPadSelect && !buttonsSelect)
    {
        m_reg |= 0x0F;
    }
}

Reg8 Input::Read(const Address address) const
{
    return m_reg;
}

void Input::Write(const Address address, Reg8 byte)
{
    m_reg = byte;
}

} // namespace gb
