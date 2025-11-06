#include "cycles.h"

#include <cmath>

CCycles::CCycles(unsigned int clockCycles):
    cycles(clockCycles)
{}

CCycles::operator MCycles() const
{
    return MCycles(std::ceil(cycles / 4.0f));
}

MCycles::MCycles(unsigned int machineCycles):
    cycles(machineCycles)
{}

MCycles::operator CCycles() const
{
    return CCycles(cycles * CLOCK_PER_MACHINE_CYCLE);
}
