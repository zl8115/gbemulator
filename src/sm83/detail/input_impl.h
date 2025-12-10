#pragma once

#include "input.h"

#include "mmu.h"
#include "mmu_mapped_memory.h"

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
