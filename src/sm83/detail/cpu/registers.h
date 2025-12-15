#pragma once

#include <cstdint>

namespace detail {

class Registers
{
public:
    Registers()
    : ime(false),
      a(0), f(0), b(0), c(0),
      d(0), e(0), h(0), l(0),
      pc(0), sp(0)
    {}

    bool ime; // Interrupt Master Enable

    uint8_t a;
    uint8_t f;

    uint8_t b;
    uint8_t c;

    uint8_t d;
    uint8_t e;

    uint8_t h;
    uint8_t l;

    uint16_t pc;
    uint16_t sp;
};

} // namespace detail
