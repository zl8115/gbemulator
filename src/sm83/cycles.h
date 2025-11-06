#pragma once

struct MCycles;

inline constexpr unsigned int CLOCK_PER_MACHINE_CYCLE = 4;

struct CCycles
{
    CCycles(unsigned int clockCycles);
    operator MCycles() const;

    bool operator== (const CCycles& other) { return cycles == other.cycles; }
    bool operator!= (const CCycles& other) { return cycles != other.cycles; }
    bool operator<  (const CCycles& other) { return cycles < other.cycles; }
    bool operator>  (const CCycles& other) { return cycles > other.cycles; }
    bool operator<= (const CCycles& other) { return cycles <= other.cycles; }
    bool operator>= (const CCycles& other) { return cycles >= other.cycles; }

    CCycles& operator+=  (const CCycles& other) { cycles += other.cycles; return *this; }
    CCycles& operator-=  (const CCycles& other) { cycles -= other.cycles; return *this; }
    CCycles& operator%=  (const CCycles& other) { cycles %= other.cycles; return *this; }
    CCycles  operator+   (const CCycles& other) const { return CCycles(cycles + other.cycles); }
    CCycles  operator-   (const CCycles& other) const { return CCycles(cycles - other.cycles); }
    CCycles  operator*   (const CCycles& other) const { return CCycles(cycles * other.cycles); }

    unsigned int cycles;
};

struct MCycles
{
    MCycles(unsigned int machineCycles);
    operator CCycles() const;

    bool operator== (const MCycles& other) { return cycles == other.cycles; }
    bool operator!= (const MCycles& other) { return cycles != other.cycles; }
    bool operator<  (const MCycles& other) { return cycles < other.cycles; }
    bool operator>  (const MCycles& other) { return cycles > other.cycles; }
    bool operator<= (const MCycles& other) { return cycles <= other.cycles; }
    bool operator>= (const MCycles& other) { return cycles >= other.cycles; }

    MCycles& operator+=  (const MCycles& other) { cycles += other.cycles; return *this; }
    MCycles& operator-=  (const MCycles& other) { cycles -= other.cycles; return *this; }
    MCycles  operator+   (const MCycles& other) { return MCycles(cycles + other.cycles); }
    MCycles  operator-   (const MCycles& other) { return MCycles(cycles - other.cycles); }
    MCycles  operator*   (const MCycles& other) { return MCycles(cycles * other.cycles); }

    unsigned int cycles;
};

