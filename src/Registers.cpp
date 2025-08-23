#include "Registers.h"

#include <stdexcept>

Registers::Registers()
: a(0), f(0), b(0), c(0),
  d(0), e(0), h(0), l(0)
{}

bool Registers::HasFlag(Flags flag) const
{
    return f & flag;
}

const uint8_t Registers::Get(Target target) const
{
    if (target == A)
    {
        return a;
    }
    else if (target == B)
    {
        return b;
    }
    else if (target == C)
    {
        return c;
    }
    else if (target == D)
    {
        return d;
    }
    else if (target == E)
    {
        return e;
    }
    else if (target == H)
    {
        return h;
    }
    else if (target == L)
    {
        return l;
    }
    else
    {
        throw std::runtime_error("Unexpected SingleRegisterTarget");
        // static_assert(false, "Unexpected SingleRegisterTarget");
    }
}

const uint16_t Registers::GetDouble(Target target) const
{
    uint16_t msb = 0, lsb = 0;
    if (target == BC)
    {
        msb = Get(B);
        lsb = Get(C);
    }
    else if (target == DE)
    {
        msb = Get(D);
        lsb = Get(E);
    }
    else if (target == HL)
    {
        msb = Get(H);
        lsb = Get(L);
    }
    else
    {
        throw std::runtime_error("Unexpected DoubleRegisterTarget");
        // static_assert(false, "Unexpected DoubleRegisterTarget");
    }
    return msb << 8 | lsb;
}

void Registers::Set(Target target, uint8_t value)
{
    if (target == A)
    {
        a = value;
    }
    else if (target == B)
    {
        b = value;
    }
    else if (target == C)
    {
        c = value;
    }
    else if (target == D)
    {
        d = value;
    }
    else if (target == E)
    {
        e = value;
    }
    else if (target == H)
    {
        h = value;
    }
    else if (target == L)
    {
        l = value;
    }
    else
    {
        throw std::runtime_error("Unexpected Target");
    }
}

void Registers::SetDouble(Target target, uint16_t value)
{
    uint8_t msb = value >> 8;
    uint8_t lsb = value;
    if (target == BC)
    {
        Set(B, msb);
        Set(C, lsb);
    }
    else if (target == DE)
    {
        Set(D, msb);
        Set(E, lsb);
    }
    else if (target == HL)
    {
        Set(H, msb);
        Set(L, lsb);
    }
    else
    {
        throw std::runtime_error("Unexpected DoubleRegisterTarget");
    }
}
