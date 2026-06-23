#pragma once

#include <cmath>

namespace gb {

struct MachineTag {};
struct ClockTag {};

inline constexpr unsigned int CLOCK_PER_MACHINE_CYCLE = 4;

template<typename T>
concept CycleUnit = std::same_as<T, MachineTag> || std::same_as<T, ClockTag>;

template <CycleUnit Unit>
struct Cycles
{
    unsigned int cycles;

    Cycles(unsigned int c):
        cycles(c)
    {}

    template <CycleUnit TargetUnit>
    [[nodiscard]] constexpr auto as() const
    {
        if constexpr(std::is_same_v<Unit, TargetUnit>)
            return *this;
        else if constexpr(std::is_same_v<Unit, ClockTag> && std::is_same_v<TargetUnit, MachineTag>)
            return Cycles<MachineTag>(std::ceil(cycles / 4.0f));
        else if constexpr(std::is_same_v<Unit, MachineTag> && std::is_same_v<TargetUnit, ClockTag>)
            return Cycles<MachineTag>(cycles * 4);
    }

    bool operator== (const Cycles& other) { return cycles == other.cycles; }
    bool operator!= (const Cycles& other) { return cycles != other.cycles; }
    bool operator<  (const Cycles& other) { return cycles < other.cycles; }
    bool operator>  (const Cycles& other) { return cycles > other.cycles; }
    bool operator<= (const Cycles& other) { return cycles <= other.cycles; }
    bool operator>= (const Cycles& other) { return cycles >= other.cycles; }

    Cycles& operator+=  (const Cycles& other) { cycles += other.cycles; return *this; }
    Cycles& operator-=  (const Cycles& other) { cycles -= other.cycles; return *this; }
    Cycles& operator%=  (const Cycles& other) { cycles %= other.cycles; return *this; }
    Cycles  operator+   (const Cycles& other) const { return Cycles(cycles + other.cycles); }
    Cycles  operator-   (const Cycles& other) const { return Cycles(cycles - other.cycles); }
    Cycles  operator*   (const Cycles& other) const { return Cycles(cycles * other.cycles); }
};

namespace literals {
inline namespace cycle_literals {

consteval Cycles<ClockTag> operator ""_cc(unsigned long long c) { return Cycles<ClockTag>{static_cast<unsigned int>(c)}; }
consteval Cycles<MachineTag> operator ""_mc(unsigned long long c) { return Cycles<MachineTag>{static_cast<unsigned int>(c)}; }

} // namespace cycle_literals
} // namespace literals
} // namespace gb
