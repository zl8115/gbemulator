#pragma once
#include "types.h"

namespace gb {

struct Registers
{
    bool ime; // Interrupt Master Enable

    Reg8 a;
    Reg8 f;

    Reg8 b;
    Reg8 c;

    Reg8 d;
    Reg8 e;

    Reg8 h;
    Reg8 l;

    Reg16 pc;
    Reg16 sp;

    Registers()
    : ime(false),
      a(0), f(0), b(0), c(0),
      d(0), e(0), h(0), l(0),
      pc(0), sp(0)
    {}
};

} // namespace gb
