#pragma once

#include "input_buttons.h"
#include "detail/memory/mapped_register.h"

class Mmu;

namespace detail {

class InputImpl
{
public:
    InputImpl(Mmu& mmu);

    void ButtonPressed(GbButton button);
    void ButtonReleased(GbButton button);
    void WriteInput();

private:
    bool m_pressedUp;
    bool m_pressedDown;
    bool m_pressedLeft;
    bool m_pressedRight;
    bool m_pressedA;
    bool m_pressedB;
    bool m_pressedSelect;
    bool m_pressedStart;
    MappedRegister m_reg;
};

} // namespace detail
