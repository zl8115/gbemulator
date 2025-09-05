#include "cpu.h"
#include "cpu_instructions.h"

#include <functional>

enum class RegisterTargets
{
    INVALID = -1,
    NONE = 0,

    // Single Registers
    A, B, C, D, E, H, L,

    // Large Registers
    BC, DE, HL, SP,

    // Indirect Registers
    N, NN
};

enum RegisterFlags : uint8_t
{
    CARRY_FLAG      = 0x10,
    HALF_CARRY_FLAG = 0x20,
    NEGATE_FLAG     = 0x40,
    ZERO_FLAG       = 0x80,
    ALL             = 0xF0
};

using R = RegisterTargets;
using F = RegisterFlags;

template<R T>
concept SmallReg = T == R::A || T == R::B || T == R::C || T == R::D ||
    T == R::E || T == R::H || T == R::L || T == R::N;

template <R T>
concept LargeReg = T == R::BC || T == R::DE || T == R::HL || T == R::SP || T == R::NN;

template <R T>
concept RegTarget = (SmallReg<T> || LargeReg<T>);

/******************** Utility Functions ********************/

inline uint16_t ToWord(uint8_t hibyte, uint8_t lobyte)
{
    return (hibyte << 8) | lobyte;
}

inline uint8_t Lsb(uint16_t word)
{
    return static_cast<uint8_t>(word & 0xFF);
}

inline uint8_t Msb(uint16_t word)
{
    return word >> 8;
}

namespace {

/******************** Basic Memory Bus Functions ********************/

template <R Src>
inline uint8_t Read(Cpu& cpu) requires SmallReg<Src>;
template <> inline uint8_t Read<R::A>(Cpu& cpu) { return cpu.reg.a; }
template <> inline uint8_t Read<R::B>(Cpu& cpu) { return cpu.reg.b; }
template <> inline uint8_t Read<R::C>(Cpu& cpu) { return cpu.reg.c; }
template <> inline uint8_t Read<R::D>(Cpu& cpu) { return cpu.reg.d; }
template <> inline uint8_t Read<R::E>(Cpu& cpu) { return cpu.reg.e; }
template <> inline uint8_t Read<R::H>(Cpu& cpu) { return cpu.reg.h; }
template <> inline uint8_t Read<R::L>(Cpu& cpu) { return cpu.reg.l; }
template <> inline uint8_t Read<R::N>(Cpu& cpu) { return cpu.ram[++cpu.reg.pc]; }

template <R Src>
inline uint16_t ReadWord(Cpu& cpu) requires LargeReg<Src>;
template <> inline uint16_t ReadWord<R::BC>(Cpu& cpu) { return ToWord(Read<R::B>(cpu), Read<R::C>(cpu)); }
template <> inline uint16_t ReadWord<R::DE>(Cpu& cpu) { return ToWord(Read<R::D>(cpu), Read<R::E>(cpu)); }
template <> inline uint16_t ReadWord<R::HL>(Cpu& cpu) { return ToWord(Read<R::H>(cpu), Read<R::L>(cpu)); }
template <> inline uint16_t ReadWord<R::SP>(Cpu& cpu) { return cpu.reg.sp; }
template <> inline uint16_t ReadWord<R::NN>(Cpu& cpu) {
    auto lobyte = cpu.ram[++cpu.reg.pc];
    auto hibyte = cpu.ram[++cpu.reg.pc];
    return ToWord(hibyte, lobyte);
}

template <R Dst>
inline void Set(Cpu& cpu, uint8_t value) requires SmallReg<Dst>;
template <> inline void Set<R::A>(Cpu& cpu, uint8_t value) { cpu.reg.a = value; }
template <> inline void Set<R::B>(Cpu& cpu, uint8_t value) { cpu.reg.b = value; }
template <> inline void Set<R::C>(Cpu& cpu, uint8_t value) { cpu.reg.c = value; }
template <> inline void Set<R::D>(Cpu& cpu, uint8_t value) { cpu.reg.d = value; }
template <> inline void Set<R::E>(Cpu& cpu, uint8_t value) { cpu.reg.e = value; }
template <> inline void Set<R::H>(Cpu& cpu, uint8_t value) { cpu.reg.h = value; }
template <> inline void Set<R::L>(Cpu& cpu, uint8_t value) { cpu.reg.l = value; }

template <R Dst>
inline void SetWord(Cpu& cpu, uint16_t value) requires LargeReg<Dst>;
template <> inline void SetWord<R::BC>(Cpu& cpu, uint16_t value) { Set<R::B>(cpu, Msb(value)); Set<R::C>(cpu, Lsb(value)); }
template <> inline void SetWord<R::DE>(Cpu& cpu, uint16_t value) { Set<R::D>(cpu, Msb(value)); Set<R::E>(cpu, Lsb(value)); }
template <> inline void SetWord<R::HL>(Cpu& cpu, uint16_t value) { Set<R::H>(cpu, Msb(value)); Set<R::L>(cpu, Lsb(value)); }
template <> inline void SetWord<R::SP>(Cpu& cpu, uint16_t value) { cpu.reg.sp = value; }
template <> inline void SetWord<R::NN>(Cpu& cpu, uint16_t value) {
    auto nn = ReadWord<R::NN>(cpu);
    cpu.ram[nn] = Lsb(value);
    cpu.ram[++nn] = Msb(value);
}

/******************** Cpu Instructions ********************/

template <R Dst, R Src>
void Load(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    Set<Dst>(cpu, Read<Src>(cpu));
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Load(Cpu& cpu) requires LargeReg<Dst> && LargeReg<Src>
{
    SetWord<Dst>(cpu, ReadWord<Src>(cpu));
    ++cpu.reg.pc;
}

// Indirect Load
template <R Dst, R Src>
void Load(Cpu& cpu) requires SmallReg<Dst> && LargeReg<Src>
{
    auto addr = ReadWord<Src>(cpu);
    Set<Dst>(cpu, cpu.ram[addr]);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Load(Cpu& cpu) requires LargeReg<Dst> && SmallReg<Src>
{
    auto addr = ReadWord<Dst>(cpu);
    cpu.ram[addr] = Read<Src>(cpu);
    ++cpu.reg.pc;
}

template <R Dst>
void Add(Cpu& cpu, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value + value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst>
void Add(Cpu& cpu, uint16_t value) requires LargeReg<Dst>
{
    auto ori_value = ReadWord<Dst>(cpu);
    uint16_t new_value = ori_value + value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG | F:: CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xFFF) + (value & 0xFFF) > 0xFFF)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value < ori_value)
        cpu.reg.f |= F::CARRY_FLAG;

    SetWord<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Add(Cpu& cpu) requires SmallReg<Dst>
{
    Add<Dst>(cpu, Read<Src>());
}

template <R Dst, R Src>
void Add(Cpu& cpu) requires LargeReg<Dst>
{
    Add<Dst>(cpu, ReadWord<Src>(cpu));
}

template <R Dst>
void Inc(Cpu& cpu) requires SmallReg<Dst>
{
    Add<Dst>(cpu, 1);
}

template <R Dst>
void Inc(Cpu& cpu) requires LargeReg<Dst>
{
    SetWord<Dst>(cpu, ReadWord<Dst>(cpu) + 1);
    ++cpu.reg.pc;
}

template <R Dst>
void Sub(Cpu& cpu, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value - value;

    cpu.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG);
    cpu.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst>
void Dec(Cpu& cpu) requires SmallReg<Dst>
{
    Sub<Dst>(cpu, 1);
}

template <R Dst>
void Dec(Cpu& cpu) requires LargeReg<Dst>
{
    SetWord<Dst>(cpu, ReadWord<Dst>(cpu) - 1);
    ++cpu.reg.pc;
}

void Noop(Cpu& cpu)
{
    ++cpu.reg.pc;
}

void RLCA(Cpu& cpu)
{
    cpu.reg.f &= ~(F::ALL);
    uint8_t b7 = (cpu.reg.a >> 7) & 1;
    if (b7)
    {
        cpu.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = cpu.reg.a << 1 | b7;
    Set<R::A>(cpu, value);
    ++cpu.reg.pc;
}

void RLA(Cpu& cpu)
{
    bool c = cpu.reg.f & F::CARRY_FLAG;
    cpu.reg.f &= ~(F::ALL);
    uint8_t b7 = (cpu.reg.a >> 7) & 1;
    if (b7)
    {
        cpu.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = cpu.reg.a << 1 | c;
    Set<R::A>(cpu, value);
    ++cpu.reg.pc;
}

void RRCA(Cpu& cpu)
{
    cpu.reg.f &= ~(F::ALL);
    uint8_t b0 = cpu.reg.a & 0x1;
    if (b0)
    {
        cpu.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = cpu.reg.a >> 1 | (b0 << 7);
    Set<R::A>(cpu, value);
    ++cpu.reg.pc;
}

void RRA(Cpu& cpu)
{
    bool c = cpu.reg.f & F::CARRY_FLAG;
    cpu.reg.f &= ~(F::ALL);
    uint8_t b0 = cpu.reg.a & 1;
    if (b0)
    {
        cpu.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = cpu.reg.a >> 1 | (c << 7);
    Set<R::A>(cpu, value);
    ++cpu.reg.pc;
}

} // namespace

std::function<void(Cpu&)> s_Instructions[0x100] = {
    // 0x0X
    ::Noop, ::Load<R::BC,R::NN>, ::Load<R::BC,R::A>, ::Inc<R::BC>, ::Inc<R::B>, ::Dec<R::B>, ::Load<R::B,R::N>, ::RLCA, ::Load<R::NN,R::SP>, ::Add<R::HL,R::BC>, ::Load<R::A,R::BC>, ::Dec<R::BC>, ::Inc<R::C>, ::Dec<R::C>, ::Load<R::C,R::N>, ::RRCA,
    // 0x1X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x2X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x3X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x4X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x5X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x6X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x7X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x8X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x9X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xaX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xbX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xcX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xdX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xeX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xfX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
};

void CpuInstructions::Execute(Cpu& cpu, uint8_t opcode)
{
    s_Instructions[opcode](cpu);
}
