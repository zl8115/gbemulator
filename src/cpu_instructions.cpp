#include "cpu.h"
#include "cpu_instructions.h"

#include <functional>
#include <stdexcept>

enum class ConditionFlags
{
    NONE = 0,
    NZ, NC,
    Z, C
};

enum class RegisterTargets
{
    INVALID = -1,
    NONE = 0,

    // Single Registers
    A, B, C, D, E, H, L,

    // Large Registers
    BC, DE, HL, SP,

    // Indirect Register
    IHL,

    // Inc/Dec Large Registers
    HLI, HLD,

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
using C = ConditionFlags;

template<R T>
concept SmallReg = T == R::A || T == R::B || T == R::C || T == R::D || T == R::E || T == R::H || T == R::L ||
    T == R::N || T == R::IHL;

template <R T>
concept LargeReg = T == R::BC || T == R::DE || T == R::HL || T == R::SP ||
    T == R::NN;

template <R T>
concept RegTarget = (SmallReg<T> || LargeReg<T>);

template <R T>
concept IncDecReg = T == R::HLI || T == R::HLD;

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

inline uint8_t ReadFlags(Cpu& cpu) { return cpu.reg.f; }

// Forward declaration
template <R Src> inline uint16_t ReadWord(Cpu& cpu) requires LargeReg<Src>;
template <> inline uint16_t ReadWord<R::HL>(Cpu& cpu);

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
template <> inline uint8_t Read<R::IHL>(Cpu& cpu) { return cpu.ram[ReadWord<R::HL>(cpu)]; }

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
template <> inline void Set<R::IHL>(Cpu& cpu, uint8_t value) { cpu.ram[ReadWord<R::HL>(cpu)] = value; }

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

/******************** Condition Check Functions ********************/

template <C Cnd>
inline bool ConditionCheck(Cpu& cpu);
template <> inline bool ConditionCheck<C::NONE>(Cpu& cpu) { return true; }
template <> inline bool ConditionCheck<C::NZ>(Cpu& cpu) { return !(cpu.reg.f & F::ZERO_FLAG); }
template <> inline bool ConditionCheck<C::NC>(Cpu& cpu) { return !(cpu.reg.f & F::CARRY_FLAG); }
template <> inline bool ConditionCheck<C::Z>(Cpu& cpu) { return cpu.reg.f & F::ZERO_FLAG; }
template <> inline bool ConditionCheck<C::C>(Cpu& cpu) { return cpu.reg.f & F::CARRY_FLAG; }

/******************** Cpu Instructions ********************/
/*     ************** Registry Ops *************     */

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

template <R Dst, R Src>
void Load(Cpu& cpu) requires IncDecReg<Dst> && SmallReg<Src>
{
    Load<R::HL, Src>(cpu);
    if constexpr(Dst == R::HLI)
    {
        SetWord<R::HL>(cpu, ReadWord<R::HL>(cpu) + 1);
    }
    else if constexpr(Dst == R::HLD)
    {
        SetWord<R::HL>(cpu, ReadWord<R::HL>(cpu) - 1);
    }
}

template <R Dst, R Src>
void Load(Cpu& cpu) requires SmallReg<Dst> && IncDecReg<Src>
{
    Load<Dst, R::HL>(cpu);
    if constexpr(Src == R::HLI)
    {
        SetWord<R::HL>(cpu, ReadWord<R::HL>(cpu) + 1);
    }
    else if constexpr(Src == R::HLD)
    {
        SetWord<R::HL>(cpu, ReadWord<R::HL>(cpu) - 1);
    }
}

template <R Dst>
void Add(Cpu& cpu, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value + value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value < ori_value)
        cpu.reg.f |= F::CARRY_FLAG;

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
void Add(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    Add<Dst>(cpu, Read<Src>(cpu));
}

template <R Dst, R Src>
void Add(Cpu& cpu) requires LargeReg<Dst> && LargeReg<Src>
{
    Add<Dst>(cpu, ReadWord<Src>(cpu));
}

template <R Dst, R Src>
void Adc(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t carry = (cpu.reg.f & F::CARRY_FLAG) ? 1 : 0;
    uint8_t value = Read<Src>(cpu);
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value + value + carry;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) + carry > 0xF)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value - carry < ori_value)
        cpu.reg.f |= F::CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst>
void Inc(Cpu& cpu) requires SmallReg<Dst>
{
    constexpr uint8_t value = 1;
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value + value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + value > 0xF)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
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

    cpu.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    cpu.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value)
        cpu.reg.f |= F::CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Sub(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    Sub<Dst>(cpu, Read<Src>(cpu));
}

template <R Dst, R Src>
void Sbc(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(cpu);
    uint8_t carry = (cpu.reg.f & F::CARRY_FLAG) ? 1 : 0;
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value - value - carry;

    cpu.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    cpu.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF) + carry)
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value + carry)
        cpu.reg.f |= F::CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst>
void Dec(Cpu& cpu) requires SmallReg<Dst>
{
    constexpr uint8_t value = 1;
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
void Dec(Cpu& cpu) requires LargeReg<Dst>
{
    SetWord<Dst>(cpu, ReadWord<Dst>(cpu) - 1);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void And(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(cpu);
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value & value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::CARRY_FLAG);
    cpu.reg.f |= F::HALF_CARRY_FLAG;
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;
    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Xor(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(cpu);
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value ^ value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;
    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Or(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(cpu);
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value | value;

    cpu.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;
    Set<Dst>(cpu, new_value);
    ++cpu.reg.pc;
}

template <R Dst, R Src>
void Cp(Cpu& cpu) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(cpu);
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value - value;

    cpu.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    cpu.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        cpu.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value)
        cpu.reg.f |= F::CARRY_FLAG;
    ++cpu.reg.pc;
}

template <R Dst>
void Pop(Cpu& cpu) requires LargeReg<Dst>
{
    auto lobyte = cpu.ram[cpu.reg.sp++];
    auto hibyte = cpu.ram[cpu.reg.sp++];
    SetWord<Dst>(cpu, ToWord(hibyte, lobyte));
    ++cpu.reg.pc;
}

template <R Dst>
void Push(Cpu& cpu) requires LargeReg<Dst>
{
    auto data = ReadWord<Dst>(cpu);
    cpu.ram[--cpu.reg.sp] = Msb(data);
    cpu.ram[--cpu.reg.sp] = Lsb(data);
    ++cpu.reg.pc;
}

/*     ************** Conditional Ops *************     */
template <C Cnd>
void RelativeJump(Cpu& cpu)
{
    int8_t e = cpu.ram[++cpu.reg.pc];
    if (ConditionCheck<Cnd>(cpu))
    {
        auto new_pc = cpu.reg.pc + e;
        cpu.reg.pc = new_pc;
    }
    ++cpu.reg.pc;
}

template <C Cnd>
void Jump(Cpu& cpu)
{
    auto lobyte = cpu.ram[++cpu.reg.pc];
    auto hibyte = cpu.ram[++cpu.reg.pc];
    ++cpu.reg.pc;
    if (ConditionCheck<Cnd>(cpu))
    {
        cpu.reg.pc = ToWord(hibyte,lobyte);
    }
}

template <C Cnd>
void Call(Cpu& cpu)
{
    auto lobyte = cpu.ram[++cpu.reg.pc];
    auto hibyte = cpu.ram[++cpu.reg.pc];
    ++cpu.reg.pc;
    if (ConditionCheck<Cnd>(cpu))
    {
        auto nn = ToWord(hibyte, lobyte);
        cpu.ram[--cpu.reg.sp] = Msb(cpu.reg.pc);
        cpu.ram[--cpu.reg.sp] = Lsb(cpu.reg.pc);
        cpu.reg.pc = nn;
    }
}

template <C Cnd>
void Ret(Cpu& cpu)
{
    ++cpu.reg.pc;
    if (ConditionCheck<Cnd>(cpu))
    {
        auto lobyte = cpu.ram[cpu.reg.sp++];
        auto hibyte = cpu.ram[cpu.reg.sp++];
        cpu.reg.pc = ToWord(hibyte, lobyte);
    }
}

/*     ************** Opcode Ops *************     */
template <uint8_t Op>
void Rst(Cpu& cpu)
{
    ++cpu.reg.pc;
    cpu.ram[--cpu.reg.sp] = Msb(cpu.reg.pc);
    cpu.ram[--cpu.reg.sp] = Lsb(cpu.reg.pc);
    cpu.reg.pc = Op;
}

/*     ************** Normal Ops *************     */
void Undef(Cpu& cpu)
{
    throw std::runtime_error("Undefined opcode");
}

void Noop(Cpu& cpu)
{
    ++cpu.reg.pc;
}

void Stop(Cpu& cpu)
{
    // TODO: Properly implement
    cpu.ime = 0;
    ++cpu.reg.pc;
}

void Halt(Cpu& cpu)
{
    // TODO: Properly implement
    if (cpu.ie & !cpu.ime)
      return;
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

void DAA(Cpu& cpu)
{
    uint8_t ori_value = Read<R::A>(cpu);
    uint8_t ori_flags = ReadFlags(cpu);
    bool isNegate = ori_flags & F::NEGATE_FLAG;
    bool isHalfCarry = ori_flags & F::HALF_CARRY_FLAG;
    bool isCarry = ori_flags & F::CARRY_FLAG;

    bool shouldCarry = false;
    uint8_t offset = 0;
    if ((!isNegate && ((ori_value & 0xF) > 0x09)) || isHalfCarry)
    {
        offset |= 0x06;
    }

    if ((!isNegate && (ori_value > 0x99)) || isCarry)
    {
        offset |= 0x60;
        shouldCarry = true;
    }

    uint8_t new_value = isNegate ? ori_value - offset : ori_value + offset;
    cpu.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        cpu.reg.f |= F::ZERO_FLAG;
    if (shouldCarry)
        cpu.reg.f |= F::CARRY_FLAG;
    Set<R::A>(cpu, new_value);
    ++cpu.reg.pc;
}

void CPL(Cpu& cpu)
{
    Set<R::A>(cpu, ~Read<R::A>(cpu));
    cpu.reg.f |= F::NEGATE_FLAG;
    cpu.reg.f |= F::HALF_CARRY_FLAG;
    ++cpu.reg.pc;
}

void SCF(Cpu& cpu)
{
    cpu.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG);
    cpu.reg.f |= F::CARRY_FLAG;
    ++cpu.reg.pc;
}

void CCF(Cpu& cpu)
{
    cpu.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG);
    cpu.reg.f ^= F::CARRY_FLAG;
    ++cpu.reg.pc;
}

void RetI(Cpu& cpu)
{
    auto Z = cpu.ram[cpu.reg.sp++];
    auto W = cpu.ram[cpu.reg.sp++];
    cpu.reg.pc = ToWord(W,Z);
    cpu.ime = 1;
}

} // namespace

std::function<void(Cpu&)> s_Instructions[0x100] = {
    // 0x0X
    ::Noop, ::Load<R::BC,R::NN>, ::Load<R::BC,R::A>, ::Inc<R::BC>, ::Inc<R::B>, ::Dec<R::B>, ::Load<R::B,R::N>, ::RLCA, ::Load<R::NN,R::SP>, ::Add<R::HL,R::BC>, ::Load<R::A,R::BC>, ::Dec<R::BC>, ::Inc<R::C>, ::Dec<R::C>, ::Load<R::C,R::N>, ::RRCA,
    // 0x1X
    ::Noop, ::Load<R::DE,R::NN>, ::Load<R::DE,R::A>, ::Inc<R::DE>, ::Inc<R::D>, ::Dec<R::D>, ::Load<R::D,R::N>, ::RLA, ::RelativeJump<C::NONE>, ::Add<R::HL,R::DE>, ::Load<R::A,R::DE>, ::Dec<R::DE>, ::Inc<R::E>, ::Dec<R::E>, ::Load<R::E,R::N>, ::RRA,
    // 0x2X
    ::RelativeJump<C::NZ>, ::Load<R::HL,R::NN>, ::Load<R::HLI,R::A>, ::Inc<R::HL>, ::Inc<R::H>, ::Dec<R::H>, ::Load<R::H,R::N>, ::DAA, ::RelativeJump<C::Z>, ::Add<R::HL,R::HL>, ::Load<R::A,R::HLI>, ::Dec<R::HL>, ::Inc<R::L>, ::Dec<R::L>, ::Load<R::L,R::N>, ::CPL,
    // 0x3X
    ::RelativeJump<C::NC>, ::Load<R::SP,R::NN>, ::Load<R::HLD,R::A>, ::Inc<R::SP>, ::Inc<R::IHL>, ::Dec<R::IHL>, ::Load<R::HL,R::N>, ::SCF, ::RelativeJump<C::C>, ::Add<R::HL,R::SP>, ::Load<R::A,R::HLD>, ::Dec<R::SP>, ::Inc<R::A>, ::Dec<R::A>, ::Load<R::A,R::N>, ::CCF,
    // 0x4X
    ::Load<R::B,R::B>, ::Load<R::B,R::C>, ::Load<R::B,R::D>, ::Load<R::B,R::E>, ::Load<R::B,R::H>, ::Load<R::B,R::L>, ::Load<R::B,R::IHL>, ::Load<R::B,R::A>, ::Load<R::C,R::B>, ::Load<R::C,R::C>, ::Load<R::C,R::D>, ::Load<R::C,R::E>, ::Load<R::C,R::H>, ::Load<R::C,R::L>, ::Load<R::C,R::IHL>, ::Load<R::C,R::A>,
    // 0x5X
    ::Load<R::D,R::B>, ::Load<R::D,R::C>, ::Load<R::D,R::D>, ::Load<R::D,R::E>, ::Load<R::D,R::H>, ::Load<R::D,R::L>, ::Load<R::D,R::IHL>, ::Load<R::D,R::A>, ::Load<R::E,R::B>, ::Load<R::E,R::C>, ::Load<R::E,R::D>, ::Load<R::E,R::E>, ::Load<R::E,R::H>, ::Load<R::E,R::L>, ::Load<R::E,R::IHL>, ::Load<R::E,R::A>,
    // 0x6X
    ::Load<R::H,R::B>, ::Load<R::H,R::C>, ::Load<R::H,R::D>, ::Load<R::H,R::E>, ::Load<R::H,R::H>, ::Load<R::H,R::L>, ::Load<R::H,R::IHL>, ::Load<R::H,R::A>, ::Load<R::L,R::B>, ::Load<R::L,R::C>, ::Load<R::L,R::D>, ::Load<R::L,R::E>, ::Load<R::L,R::H>, ::Load<R::L,R::L>, ::Load<R::L,R::IHL>, ::Load<R::L,R::A>,
    // 0x7X
    ::Load<R::IHL,R::B>, ::Load<R::IHL,R::C>, ::Load<R::IHL,R::D>, ::Load<R::IHL,R::E>, ::Load<R::IHL,R::H>, ::Load<R::IHL,R::L>, ::Halt, ::Load<R::IHL,R::A>, ::Load<R::A,R::B>, ::Load<R::A,R::C>, ::Load<R::A,R::D>, ::Load<R::A,R::E>, ::Load<R::A,R::H>, ::Load<R::A,R::L>, ::Load<R::A,R::IHL>, ::Load<R::A,R::A>,
    // 0x8X
    ::Add<R::A,R::B>, ::Add<R::A,R::C>, ::Add<R::A,R::D>, ::Add<R::A,R::E>, ::Add<R::A,R::H>, ::Add<R::A,R::L>, ::Add<R::A,R::IHL>, ::Add<R::A,R::A>, ::Adc<R::A,R::B>, ::Adc<R::A,R::C>, ::Adc<R::A,R::D>, ::Adc<R::A,R::E>, ::Adc<R::A,R::H>, ::Adc<R::A,R::L>, ::Adc<R::A,R::IHL>, ::Adc<R::A,R::A>,
    // 0x9X
    ::Sub<R::A,R::B>, ::Sub<R::A,R::C>, ::Sub<R::A,R::D>, ::Sub<R::A,R::E>, ::Sub<R::A,R::H>, ::Sub<R::A,R::L>, ::Sub<R::A,R::IHL>, ::Sub<R::A,R::A>, ::Sbc<R::A,R::B>, ::Sbc<R::A,R::C>, ::Sbc<R::A,R::D>, ::Sbc<R::A,R::E>, ::Sbc<R::A,R::H>, ::Sbc<R::A,R::L>, ::Sbc<R::A,R::IHL>, ::Sbc<R::A,R::A>,
    // 0xaX
    ::And<R::A,R::B>, ::And<R::A,R::C>, ::And<R::A,R::D>, ::And<R::A,R::E>, ::And<R::A,R::H>, ::And<R::A,R::L>, ::And<R::A,R::IHL>, ::And<R::A,R::A>, ::Xor<R::A,R::B>, ::Xor<R::A,R::C>, ::Xor<R::A,R::D>, ::Xor<R::A,R::E>, ::Xor<R::A,R::H>, ::Xor<R::A,R::L>, ::Xor<R::A,R::IHL>, ::Xor<R::A,R::A>,
    // 0xbX
    ::Or<R::A,R::B>, ::Or<R::A,R::C>, ::Or<R::A,R::D>, ::Or<R::A,R::E>, ::Or<R::A,R::H>, ::Or<R::A,R::L>, ::Or<R::A,R::IHL>, ::Or<R::A,R::A>, ::Cp<R::A,R::B>, ::Cp<R::A,R::C>, ::Cp<R::A,R::D>, ::Cp<R::A,R::E>, ::Cp<R::A,R::H>, ::Cp<R::A,R::L>, ::Cp<R::A,R::IHL>, ::Cp<R::A,R::A>,
    // 0xcX
    ::Ret<C::NZ>, ::Pop<R::BC>, ::Jump<C::NZ>, ::Jump<C::NONE>, ::Call<C::NZ>, ::Push<R::BC>, ::Add<R::A,R::N>, ::Rst<0x00>, ::Ret<C::Z>, ::Ret<C::NONE>, ::Jump<C::Z>, ::Noop /* TODO */, ::Call<C::Z>, ::Call<C::NONE>, ::Adc<R::A,R::N>, ::Rst<0x08>,
    // 0xdX
    ::Ret<C::NC>, ::Pop<R::DE>, ::Jump<C::NC>, ::Undef, ::Call<C::NC>, ::Push<R::DE>, ::Sub<R::A,R::N>, ::Rst<0x10>, ::Ret<C::C>, ::RetI, ::Jump<C::C>, ::Undef, ::Call<C::C>, ::Undef, ::Sbc<R::A,R::N>, ::Rst<0x18>,
    // 0xeX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xfX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
};

void CpuInstructions::Execute(Cpu& cpu, uint8_t opcode)
{
    s_Instructions[opcode](cpu);
}
