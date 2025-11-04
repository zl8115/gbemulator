#include "cpu_instructions.h"
#include "cpu_cycles.h"

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
    A, F, B, C, D, E, H, L,

    // Large Registers
    AF, BC, DE, HL, SP,

    // Inc/Dec Large Registers
    HLI, HLD,

    // Indirect Registers
    N, NN, IHL, Ne, SPe
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
concept SmallReg = T == R::A || T == R::F || T == R::B || T == R::C || T == R::D || T == R::E || T == R::H || T == R::L ||
    T == R::N || T == R::IHL;

template <R T>
concept LargeReg = T == R::BC || T == R::DE || T == R::HL || T == R::SP || T == R::AF ||
    T == R::NN;

template<R T>
concept HReg = T == R::A || T == R::C || T == R::N;

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

inline uint8_t ReadFlags(CpuState& state) { return state.reg.f; }

// Forward declaration
template <R Src> inline uint16_t ReadWord(CpuState& state) requires LargeReg<Src>;
template <> inline uint16_t ReadWord<R::HL>(CpuState& state);

template <R Src>
inline uint8_t Read(CpuState& state) requires SmallReg<Src>;
template <> inline uint8_t Read<R::A>(CpuState& state) { return state.reg.a; }
template <> inline uint8_t Read<R::F>(CpuState& state) { return state.reg.f; }
template <> inline uint8_t Read<R::B>(CpuState& state) { return state.reg.b; }
template <> inline uint8_t Read<R::C>(CpuState& state) { return state.reg.c; }
template <> inline uint8_t Read<R::D>(CpuState& state) { return state.reg.d; }
template <> inline uint8_t Read<R::E>(CpuState& state) { return state.reg.e; }
template <> inline uint8_t Read<R::H>(CpuState& state) { return state.reg.h; }
template <> inline uint8_t Read<R::L>(CpuState& state) { return state.reg.l; }
template <> inline uint8_t Read<R::N>(CpuState& state) { return state.mmu.Read(++state.reg.pc); }
template <> inline uint8_t Read<R::IHL>(CpuState& state) { return state.mmu.Read(ReadWord<R::HL>(state)); }

template <> inline uint16_t ReadWord<R::AF>(CpuState& state) { return ToWord(Read<R::A>(state), Read<R::F>(state)); }
template <> inline uint16_t ReadWord<R::BC>(CpuState& state) { return ToWord(Read<R::B>(state), Read<R::C>(state)); }
template <> inline uint16_t ReadWord<R::DE>(CpuState& state) { return ToWord(Read<R::D>(state), Read<R::E>(state)); }
template <> inline uint16_t ReadWord<R::HL>(CpuState& state) { return ToWord(Read<R::H>(state), Read<R::L>(state)); }
template <> inline uint16_t ReadWord<R::SP>(CpuState& state) { return state.reg.sp; }
template <> inline uint16_t ReadWord<R::NN>(CpuState& state) {
    auto lobyte = state.mmu.Read(++state.reg.pc);
    auto hibyte = state.mmu.Read(++state.reg.pc);
    return ToWord(hibyte, lobyte);
}

template <R Src>
inline uint16_t ReadH(CpuState& state) requires HReg<Src>;
template <> inline uint16_t ReadH<R::A>(CpuState& state) { return Read<R::A>(state); }
template <> inline uint16_t ReadH<R::N>(CpuState& state) { return state.mmu.Read(ToWord(0xFF, Read<R::N>(state))); }
template <> inline uint16_t ReadH<R::C>(CpuState& state) { return state.mmu.Read(ToWord(0xFF, Read<R::C>(state))); }

template <R Dst>
inline void Set(CpuState& state, uint8_t value) requires SmallReg<Dst>;
template <> inline void Set<R::A>(CpuState& state, uint8_t value) { state.reg.a = value; }
template <> inline void Set<R::F>(CpuState& state, uint8_t value) { state.reg.f = value & F::ALL; }
template <> inline void Set<R::B>(CpuState& state, uint8_t value) { state.reg.b = value; }
template <> inline void Set<R::C>(CpuState& state, uint8_t value) { state.reg.c = value; }
template <> inline void Set<R::D>(CpuState& state, uint8_t value) { state.reg.d = value; }
template <> inline void Set<R::E>(CpuState& state, uint8_t value) { state.reg.e = value; }
template <> inline void Set<R::H>(CpuState& state, uint8_t value) { state.reg.h = value; }
template <> inline void Set<R::L>(CpuState& state, uint8_t value) { state.reg.l = value; }
template <> inline void Set<R::IHL>(CpuState& state, uint8_t value) { state.mmu.Write(ReadWord<R::HL>(state), value); }

template <R Dst>
inline void SetWord(CpuState& state, uint16_t value) requires LargeReg<Dst>;
template <> inline void SetWord<R::AF>(CpuState& state, uint16_t value) { Set<R::A>(state, Msb(value)); Set<R::F>(state, Lsb(value)); }
template <> inline void SetWord<R::BC>(CpuState& state, uint16_t value) { Set<R::B>(state, Msb(value)); Set<R::C>(state, Lsb(value)); }
template <> inline void SetWord<R::DE>(CpuState& state, uint16_t value) { Set<R::D>(state, Msb(value)); Set<R::E>(state, Lsb(value)); }
template <> inline void SetWord<R::HL>(CpuState& state, uint16_t value) { Set<R::H>(state, Msb(value)); Set<R::L>(state, Lsb(value)); }
template <> inline void SetWord<R::SP>(CpuState& state, uint16_t value) { state.reg.sp = value; }
template <> inline void SetWord<R::NN>(CpuState& state, uint16_t value) {
    auto nn = ReadWord<R::NN>(state);
    state.mmu.Write(nn, Lsb(value));
    state.mmu.Write(++nn, Msb(value));
}

template <R Src>
inline void SetH(CpuState& state, uint8_t value) requires HReg<Src>;
template <> inline void SetH<R::A>(CpuState& state, uint8_t value) { Set<R::A>(state, value); }
template <> inline void SetH<R::N>(CpuState& state, uint8_t value) { state.mmu.Write(ToWord(0xFF, Read<R::N>(state)), value); }
template <> inline void SetH<R::C>(CpuState& state, uint8_t value) { state.mmu.Write(ToWord(0xFF, Read<R::C>(state)), value); }

/******************** Condition Check Functions ********************/

template <C Cnd>
inline bool ConditionCheck(CpuState& state);
template <> inline bool ConditionCheck<C::NONE>(CpuState& state) { return true; }
template <> inline bool ConditionCheck<C::NZ>(CpuState& state) { return !(state.reg.f & F::ZERO_FLAG); }
template <> inline bool ConditionCheck<C::NC>(CpuState& state) { return !(state.reg.f & F::CARRY_FLAG); }
template <> inline bool ConditionCheck<C::Z>(CpuState& state) { return state.reg.f & F::ZERO_FLAG; }
template <> inline bool ConditionCheck<C::C>(CpuState& state) { return state.reg.f & F::CARRY_FLAG; }

/******************** Cpu Instructions ********************/
/*     ************** Registry Ops *************     */

template <R Dst, R Src>
void Load(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    Set<Dst>(state, Read<Src>(state));
    ++state.reg.pc;
}

template <R Dst, R Src>
void Load(CpuState& state) requires LargeReg<Dst> && LargeReg<Src>
{
    SetWord<Dst>(state, ReadWord<Src>(state));
    ++state.reg.pc;
}

// Indirect Load
template <R Dst, R Src>
void Load(CpuState& state) requires SmallReg<Dst> && LargeReg<Src>
{
    auto addr = ReadWord<Src>(state);
    Set<Dst>(state, state.mmu.Read(addr));
    ++state.reg.pc;
}

template <R Dst, R Src>
void Load(CpuState& state) requires LargeReg<Dst> && SmallReg<Src>
{
    auto addr = ReadWord<Dst>(state);
    state.mmu.Write(addr, Read<Src>(state));
    ++state.reg.pc;
}

template <R Dst, R Src>
void Load(CpuState& state) requires IncDecReg<Dst> && SmallReg<Src>
{
    Load<R::HL, Src>(state);
    if constexpr(Dst == R::HLI)
    {
        SetWord<R::HL>(state, ReadWord<R::HL>(state) + 1);
    }
    else if constexpr(Dst == R::HLD)
    {
        SetWord<R::HL>(state, ReadWord<R::HL>(state) - 1);
    }
}

template <R Dst, R Src>
void Load(CpuState& state) requires SmallReg<Dst> && IncDecReg<Src>
{
    Load<Dst, R::HL>(state);
    if constexpr(Src == R::HLI)
    {
        SetWord<R::HL>(state, ReadWord<R::HL>(state) + 1);
    }
    else if constexpr(Src == R::HLD)
    {
        SetWord<R::HL>(state, ReadWord<R::HL>(state) - 1);
    }
}

template <R Dst, R Src>
void Load(CpuState& state) requires (Dst == R::HL && Src == R::SPe)
{
    auto e = static_cast<int16_t>(static_cast<int8_t>(Read<R::N>(state)));
    uint16_t ori_value = state.reg.sp;
    uint16_t new_value = ori_value + e;
    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (((ori_value & 0xF) + (e & 0xF)) & 0x10)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (((ori_value & 0xFF) + (e & 0xFF)) & 0x100)
        state.reg.f |= F::CARRY_FLAG;
    SetWord<R::HL>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void LoadH(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    SetH<Dst>(state, ReadH<Src>(state));
    ++state.reg.pc;
}

template <R Dst>
void Add(CpuState& state, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value + value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value < ori_value)
        state.reg.f |= F::CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst>
void Add(CpuState& state, uint16_t value) requires LargeReg<Dst>
{
    auto ori_value = ReadWord<Dst>(state);
    uint16_t new_value = ori_value + value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG | F:: CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xFFF) + (value & 0xFFF) > 0xFFF)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value < ori_value)
        state.reg.f |= F::CARRY_FLAG;

    SetWord<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void Add(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    Add<Dst>(state, Read<Src>(state));
}

template <R Dst, R Src>
void Add(CpuState& state) requires LargeReg<Dst> && LargeReg<Src>
{
    Add<Dst>(state, ReadWord<Src>(state));
}

template <R Dst, R Src>
void Add(CpuState& state) requires (Dst == R::SP) && (Src == R::Ne)
{
    auto e = static_cast<int16_t>(static_cast<int8_t>(Read<R::N>(state)));
    uint16_t ori_value = state.reg.sp;
    uint16_t new_value = ori_value + e;
    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (((ori_value & 0xF) + (e & 0xF)) & 0x10)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (((ori_value & 0xFF) + (e & 0xFF)) & 0x100)
        state.reg.f |= F::CARRY_FLAG;
    state.reg.sp = new_value;
    ++state.reg.pc;
}

template <R Dst, R Src>
void Adc(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t carry = (state.reg.f & F::CARRY_FLAG) ? 1 : 0;
    uint8_t value = Read<Src>(state);
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value + value + carry;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) + carry > 0xF)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (new_value - carry < ori_value)
        state.reg.f |= F::CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst>
void Inc(CpuState& state) requires SmallReg<Dst>
{
    constexpr uint8_t value = 1;
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value + value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) + value > 0xF)
        state.reg.f |= F::HALF_CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst>
void Inc(CpuState& state) requires LargeReg<Dst>
{
    SetWord<Dst>(state, ReadWord<Dst>(state) + 1);
    ++state.reg.pc;
}

template <R Dst>
void Sub(CpuState& state, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value - value;

    state.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    state.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value)
        state.reg.f |= F::CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void Sub(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    Sub<Dst>(state, Read<Src>(state));
}

template <R Dst, R Src>
void Sbc(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(state);
    uint8_t carry = (state.reg.f & F::CARRY_FLAG) ? 1 : 0;
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value - value - carry;

    state.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    state.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF) + carry)
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value + carry)
        state.reg.f |= F::CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst>
void Dec(CpuState& state) requires SmallReg<Dst>
{
    constexpr uint8_t value = 1;
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value - value;

    state.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG);
    state.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        state.reg.f |= F::HALF_CARRY_FLAG;

    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst>
void Dec(CpuState& state) requires LargeReg<Dst>
{
    SetWord<Dst>(state, ReadWord<Dst>(state) - 1);
    ++state.reg.pc;
}

template <R Dst, R Src>
void And(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(state);
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value & value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::CARRY_FLAG);
    state.reg.f |= F::HALF_CARRY_FLAG;
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;
    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void Xor(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(state);
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value ^ value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;
    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void Or(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(state);
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value | value;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;
    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template <R Dst, R Src>
void Cp(CpuState& state) requires SmallReg<Dst> && SmallReg<Src>
{
    uint8_t value = Read<Src>(state);
    uint8_t ori_value = Read<Dst>(state);
    uint8_t new_value = ori_value - value;

    state.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    state.reg.f |= F::NEGATE_FLAG;
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;

    if ((ori_value & 0xF) < (value & 0xF))
        state.reg.f |= F::HALF_CARRY_FLAG;

    if (ori_value < new_value)
        state.reg.f |= F::CARRY_FLAG;
    ++state.reg.pc;
}

template <R Dst>
void Pop(CpuState& state) requires LargeReg<Dst>
{
    auto lobyte = state.mmu.Read(state.reg.sp++);
    auto hibyte = state.mmu.Read(state.reg.sp++);;
    SetWord<Dst>(state, ToWord(hibyte, lobyte));
    ++state.reg.pc;
}

template <R Dst>
void Push(CpuState& state) requires LargeReg<Dst>
{
    auto data = ReadWord<Dst>(state);
    state.mmu.Write(--state.reg.sp, Msb(data));
    state.mmu.Write(--state.reg.sp, Lsb(data));
    ++state.reg.pc;
}

/*     ************** Conditional Ops *************     */
template <C Cnd>
void RelativeJump(CpuState& state)
{
    int8_t e = state.mmu.Read(++state.reg.pc);
    if (ConditionCheck<Cnd>(state))
    {
        state.branchTaken = true;
        auto new_pc = state.reg.pc + e;
        state.reg.pc = new_pc;
    }
    ++state.reg.pc;
}

template <C Cnd>
void Jump(CpuState& state)
{
    auto lobyte = state.mmu.Read(++state.reg.pc);
    auto hibyte = state.mmu.Read(++state.reg.pc);
    ++state.reg.pc;
    if (ConditionCheck<Cnd>(state))
    {
        state.branchTaken = true;
        state.reg.pc = ToWord(hibyte,lobyte);
    }
}

template <R Dst>
void Jump(CpuState& state) requires (Dst == R::HL)
{
    state.reg.pc = ReadWord<R::HL>(state);
}

template <C Cnd>
void Call(CpuState& state)
{
    auto lobyte = state.mmu.Read(++state.reg.pc);
    auto hibyte = state.mmu.Read(++state.reg.pc);
    ++state.reg.pc;
    if (ConditionCheck<Cnd>(state))
    {
        state.branchTaken = true;
        auto nn = ToWord(hibyte, lobyte);
        state.mmu.Write(--state.reg.sp, Msb(state.reg.pc));
        state.mmu.Write(--state.reg.sp, Lsb(state.reg.pc));
        state.reg.pc = nn;
    }
}

template <C Cnd>
void Ret(CpuState& state)
{
    ++state.reg.pc;
    if (ConditionCheck<Cnd>(state))
    {
        state.branchTaken = true;
        auto lobyte = state.mmu.Read(state.reg.sp++);
        auto hibyte = state.mmu.Read(state.reg.sp++);
        state.reg.pc = ToWord(hibyte, lobyte);
    }
}

/*     ************** Opcode Ops *************     */
template <uint8_t Op>
void Rst(CpuState& state)
{
    ++state.reg.pc;
    state.mmu.Write(--state.reg.sp, Msb(state.reg.pc));
    state.mmu.Write(--state.reg.sp, Lsb(state.reg.pc));
    state.reg.pc = Op;
}


/*     ************** Normal Ops *************     */
void Undef(CpuState& state)
{
    throw std::runtime_error("Undefined opcode");
}

void Noop(CpuState& state)
{
    ++state.reg.pc;
}

void Stop(CpuState& state)
{
    // TODO: Properly implement
    state.mmu.ime = 0;
    ++state.reg.pc;
}

void Halt(CpuState& state)
{
    constexpr int interrupt_flag = 0;     // TODO: Properly implement

    if ((state.mmu.ime == 0) && (state.mmu.ie & interrupt_flag) != 0)
      return;
    ++state.reg.pc;
}

/*     ************** Bit Ops *************     */
void RLCA(CpuState& state)
{
    state.reg.f &= ~(F::ALL);
    uint8_t b7 = (state.reg.a >> 7) & 1;
    if (b7)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = state.reg.a << 1 | b7;
    Set<R::A>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void RLC(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b7 = (ori_value >> 7) & 1;

    uint8_t value = ori_value << 1 | b7;

    state.reg.f &= ~(F::ALL);
    if (b7)
    {
        state.reg.f |= F::CARRY_FLAG;
    }
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

void RLA(CpuState& state)
{
    bool c = state.reg.f & F::CARRY_FLAG;
    state.reg.f &= ~(F::ALL);
    uint8_t b7 = (state.reg.a >> 7) & 1;
    if (b7)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = state.reg.a << 1 | c;
    Set<R::A>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void RL(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b7 = (ori_value >> 7) & 1;

    bool c = state.reg.f & F::CARRY_FLAG;
    uint8_t value = ori_value << 1 | c;

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    if (b7)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

void RRCA(CpuState& state)
{
    state.reg.f &= ~(F::ALL);
    uint8_t b0 = state.reg.a & 0x1;
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = state.reg.a >> 1 | (b0 << 7);
    Set<R::A>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void RRC(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b0 = ori_value & 0x1;
    uint8_t value = ori_value >> 1 | (b0 << 7);

    state.reg.f &= ~(F::ALL);
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

void RRA(CpuState& state)
{
    bool c = state.reg.f & F::CARRY_FLAG;
    state.reg.f &= ~(F::ALL);
    uint8_t b0 = state.reg.a & 1;
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    uint8_t value = state.reg.a >> 1 | (c << 7);
    Set<R::A>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void RR(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b0 = ori_value & 1;

    bool c = state.reg.f & F::CARRY_FLAG;
    uint8_t value = ori_value >> 1 | (c << 7);

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void SLA(CpuState& state)
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b7 = ori_value >> 7;

    uint8_t value = ori_value << 1;

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    if (b7)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void SRA(CpuState& state)
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b0 = ori_value & 0x01;
    uint8_t b7 = ori_value & 0x80;

    uint8_t value = b7 | (ori_value >> 1);

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void Swap(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t value = (ori_value << 4) | (ori_value >> 4);

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

template<R Dst>
void SRL(CpuState& state) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(state);
    uint8_t b0 = ori_value & 1;
    uint8_t value = (ori_value >> 1);

    state.reg.f &= ~(F::ALL);
    if (value == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    if (b0)
    {
        state.reg.f |= F::CARRY_FLAG;
    }

    Set<Dst>(state, value);
    ++state.reg.pc;
}

template<int Bit, R Dst>
void BIT(CpuState& state) requires (Bit >= 0 && Bit < 8) && SmallReg<Dst>
{
    uint8_t value = Read<Dst>(state);
    constexpr uint8_t bitMask = 1 << Bit;

    state.reg.f &= ~(F::NEGATE_FLAG | F::ZERO_FLAG);
    state.reg.f |= F::HALF_CARRY_FLAG;
    if ((value & bitMask) == 0)
    {
        state.reg.f |= F::ZERO_FLAG;
    }
    ++state.reg.pc;
}

template<int Bit, R Dst>
void RES(CpuState& state) requires (Bit >= 0 && Bit < 8) && SmallReg<Dst>
{
    constexpr uint8_t bitMask = 1 << Bit;
    uint8_t new_value = Read<Dst>(state) & ~bitMask;
    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

template<int Bit, R Dst>
void SET(CpuState& state) requires (Bit >= 0 && Bit < 8) && SmallReg<Dst>
{
    constexpr uint8_t bitMask = 1 << Bit;
    uint8_t new_value = Read<Dst>(state) | bitMask;
    Set<Dst>(state, new_value);
    ++state.reg.pc;
}

/*     ************** Arithmetic/Logical Ops *************     */
void DAA(CpuState& state)
{
    uint8_t ori_value = Read<R::A>(state);
    uint8_t ori_flags = ReadFlags(state);
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
    state.reg.f &= ~(F::ZERO_FLAG | F::HALF_CARRY_FLAG | F::CARRY_FLAG);
    if (new_value == 0)
        state.reg.f |= F::ZERO_FLAG;
    if (shouldCarry)
        state.reg.f |= F::CARRY_FLAG;
    Set<R::A>(state, new_value);
    ++state.reg.pc;
}

void CPL(CpuState& state)
{
    Set<R::A>(state, ~Read<R::A>(state));
    state.reg.f |= F::NEGATE_FLAG;
    state.reg.f |= F::HALF_CARRY_FLAG;
    ++state.reg.pc;
}

void SCF(CpuState& state)
{
    state.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG);
    state.reg.f |= F::CARRY_FLAG;
    ++state.reg.pc;
}

void CCF(CpuState& state)
{
    state.reg.f &= ~(F::NEGATE_FLAG | F::HALF_CARRY_FLAG);
    state.reg.f ^= F::CARRY_FLAG;
    ++state.reg.pc;
}

/*     ************** Misc Ops *************     */
void RetI(CpuState& state)
{
    auto Z = state.mmu.Read(state.reg.sp++);
    auto W = state.mmu.Read(state.reg.sp++);
    state.reg.pc = ToWord(W,Z);
    state.mmu.ime = 1;
}

void DisI(CpuState& state)
{
    state.mmu.ime = 0;
    ++state.reg.pc;
}

void EnaI(CpuState& state)
{
    // TODO: Properly implement
    state.mmu.ei = 1;
    ++state.reg.pc;
}

} // namespace

void CbOp(CpuState& state); // Forward Declaration

std::function<void(CpuState&)> s_Instructions[0x100] = {
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
    ::Ret<C::NZ>, ::Pop<R::BC>, ::Jump<C::NZ>, ::Jump<C::NONE>, ::Call<C::NZ>, ::Push<R::BC>, ::Add<R::A,R::N>, ::Rst<0x00>, ::Ret<C::Z>, ::Ret<C::NONE>, ::Jump<C::Z>, ::CbOp, ::Call<C::Z>, ::Call<C::NONE>, ::Adc<R::A,R::N>, ::Rst<0x08>,
    // 0xdX
    ::Ret<C::NC>, ::Pop<R::DE>, ::Jump<C::NC>, ::Undef, ::Call<C::NC>, ::Push<R::DE>, ::Sub<R::A,R::N>, ::Rst<0x10>, ::Ret<C::C>, ::RetI, ::Jump<C::C>, ::Undef, ::Call<C::C>, ::Undef, ::Sbc<R::A,R::N>, ::Rst<0x18>,
    // 0xeX
    ::LoadH<R::N,R::A>, ::Pop<R::HL>, ::LoadH<R::C,R::A>, ::Undef, ::Undef, ::Push<R::HL>, ::And<R::A,R::N>, ::Rst<0x20>, ::Add<R::SP,R::Ne>, ::Jump<R::HL>, ::Load<R::NN,R::A>, ::Undef, ::Undef, ::Undef, ::Xor<R::A,R::N>, ::Rst<0x28>,
    // 0xfX
    ::LoadH<R::A,R::N>, ::Pop<R::AF>, ::LoadH<R::A,R::C>, ::DisI, ::Undef, ::Push<R::AF>, ::Or<R::A,R::N>, ::Rst<0x30>, ::Load<R::HL,R::SPe>, ::Load<R::SP,R::HL>, ::Load<R::A,R::NN>, ::EnaI, ::Undef, ::Undef, ::Cp<R::A,R::N>, ::Rst<0x38>,
};

std::function<void(CpuState&)> s_CbInstructions[0x100] = {
    // 0x0X
    ::RLC<R::B>, ::RLC<R::C>, ::RLC<R::D>, ::RLC<R::E>, ::RLC<R::H>, ::RLC<R::L>, ::RLC<R::IHL>, ::RLC<R::A>,  ::RRC<R::B>, ::RRC<R::C>, ::RRC<R::D>, ::RRC<R::E>, ::RRC<R::H>, ::RRC<R::L>, ::RRC<R::IHL>, ::RRC<R::A>,
    // 0x1X
    ::RL<R::B>, ::RL<R::C>, ::RL<R::D>, ::RL<R::E>, ::RL<R::H>, ::RL<R::L>, ::RL<R::IHL>, ::RL<R::A>,  ::RR<R::B>, ::RR<R::C>, ::RR<R::D>, ::RR<R::E>, ::RR<R::H>, ::RR<R::L>, ::RR<R::IHL>, ::RR<R::A>,
    // 0x2X
    ::SLA<R::B>, ::SLA<R::C>, ::SLA<R::D>, ::SLA<R::E>, ::SLA<R::H>, ::SLA<R::L>, ::SLA<R::IHL>, ::SLA<R::A>,  ::SRA<R::B>, ::SRA<R::C>, ::SRA<R::D>, ::SRA<R::E>, ::SRA<R::H>, ::SRA<R::L>, ::SRA<R::IHL>, ::SRA<R::A>,
    // 0x3X
    ::Swap<R::B>, ::Swap<R::C>, ::Swap<R::D>, ::Swap<R::E>, ::Swap<R::H>, ::Swap<R::L>, ::Swap<R::IHL>, ::Swap<R::A>,  ::SRL<R::B>, ::SRL<R::C>, ::SRL<R::D>, ::SRL<R::E>, ::SRL<R::H>, ::SRL<R::L>, ::SRL<R::IHL>, ::SRL<R::A>,
    // 0x4X
    ::BIT<0,R::B>, ::BIT<0,R::C>, ::BIT<0,R::D>, ::BIT<0,R::E>, ::BIT<0,R::H>, ::BIT<0,R::L>, ::BIT<0,R::IHL>, ::BIT<0,R::A>,  ::BIT<1,R::B>, ::BIT<1,R::C>, ::BIT<1,R::D>, ::BIT<1,R::E>, ::BIT<1,R::H>, ::BIT<1,R::L>, ::BIT<1,R::IHL>, ::BIT<1,R::A>,
    // 0x5X
    ::BIT<2,R::B>, ::BIT<2,R::C>, ::BIT<2,R::D>, ::BIT<2,R::E>, ::BIT<2,R::H>, ::BIT<2,R::L>, ::BIT<2,R::IHL>, ::BIT<2,R::A>,  ::BIT<3,R::B>, ::BIT<3,R::C>, ::BIT<3,R::D>, ::BIT<3,R::E>, ::BIT<3,R::H>, ::BIT<3,R::L>, ::BIT<3,R::IHL>, ::BIT<3,R::A>,
    // 0x6X
    ::BIT<4,R::B>, ::BIT<4,R::C>, ::BIT<4,R::D>, ::BIT<4,R::E>, ::BIT<4,R::H>, ::BIT<4,R::L>, ::BIT<4,R::IHL>, ::BIT<4,R::A>,  ::BIT<5,R::B>, ::BIT<5,R::C>, ::BIT<5,R::D>, ::BIT<5,R::E>, ::BIT<5,R::H>, ::BIT<5,R::L>, ::BIT<5,R::IHL>, ::BIT<5,R::A>,
    // 0x7X
    ::BIT<6,R::B>, ::BIT<6,R::C>, ::BIT<6,R::D>, ::BIT<6,R::E>, ::BIT<6,R::H>, ::BIT<6,R::L>, ::BIT<6,R::IHL>, ::BIT<6,R::A>,  ::BIT<7,R::B>, ::BIT<7,R::C>, ::BIT<7,R::D>, ::BIT<7,R::E>, ::BIT<7,R::H>, ::BIT<7,R::L>, ::BIT<7,R::IHL>, ::BIT<7,R::A>,
    // 0x8X
    ::RES<0,R::B>, ::RES<0,R::C>, ::RES<0,R::D>, ::RES<0,R::E>, ::RES<0,R::H>, ::RES<0,R::L>, ::RES<0,R::IHL>, ::RES<0,R::A>,  ::RES<1,R::B>, ::RES<1,R::C>, ::RES<1,R::D>, ::RES<1,R::E>, ::RES<1,R::H>, ::RES<1,R::L>, ::RES<1,R::IHL>, ::RES<1,R::A>,
    // 0x9X
    ::RES<2,R::B>, ::RES<2,R::C>, ::RES<2,R::D>, ::RES<2,R::E>, ::RES<2,R::H>, ::RES<2,R::L>, ::RES<2,R::IHL>, ::RES<2,R::A>,  ::RES<3,R::B>, ::RES<3,R::C>, ::RES<3,R::D>, ::RES<3,R::E>, ::RES<3,R::H>, ::RES<3,R::L>, ::RES<3,R::IHL>, ::RES<3,R::A>,
    // 0xaX
    ::RES<4,R::B>, ::RES<4,R::C>, ::RES<4,R::D>, ::RES<4,R::E>, ::RES<4,R::H>, ::RES<4,R::L>, ::RES<4,R::IHL>, ::RES<4,R::A>,  ::RES<5,R::B>, ::RES<5,R::C>, ::RES<5,R::D>, ::RES<5,R::E>, ::RES<5,R::H>, ::RES<5,R::L>, ::RES<5,R::IHL>, ::RES<5,R::A>,
    // 0xbX
    ::RES<6,R::B>, ::RES<6,R::C>, ::RES<6,R::D>, ::RES<6,R::E>, ::RES<6,R::H>, ::RES<6,R::L>, ::RES<6,R::IHL>, ::RES<6,R::A>,  ::RES<7,R::B>, ::RES<7,R::C>, ::RES<7,R::D>, ::RES<7,R::E>, ::RES<7,R::H>, ::RES<7,R::L>, ::RES<7,R::IHL>, ::RES<7,R::A>,
    // 0xcX
    ::SET<0,R::B>, ::SET<0,R::C>, ::SET<0,R::D>, ::SET<0,R::E>, ::SET<0,R::H>, ::SET<0,R::L>, ::SET<0,R::IHL>, ::SET<0,R::A>,  ::SET<1,R::B>, ::SET<1,R::C>, ::SET<1,R::D>, ::SET<1,R::E>, ::SET<1,R::H>, ::SET<1,R::L>, ::SET<1,R::IHL>, ::SET<1,R::A>,
    // 0xdX
    ::SET<2,R::B>, ::SET<2,R::C>, ::SET<2,R::D>, ::SET<2,R::E>, ::SET<2,R::H>, ::SET<2,R::L>, ::SET<2,R::IHL>, ::SET<2,R::A>,  ::SET<3,R::B>, ::SET<3,R::C>, ::SET<3,R::D>, ::SET<3,R::E>, ::SET<3,R::H>, ::SET<3,R::L>, ::SET<3,R::IHL>, ::SET<3,R::A>,
    // 0xeX
    ::SET<4,R::B>, ::SET<4,R::C>, ::SET<4,R::D>, ::SET<4,R::E>, ::SET<4,R::H>, ::SET<4,R::L>, ::SET<4,R::IHL>, ::SET<4,R::A>,  ::SET<5,R::B>, ::SET<5,R::C>, ::SET<5,R::D>, ::SET<5,R::E>, ::SET<5,R::H>, ::SET<5,R::L>, ::SET<5,R::IHL>, ::SET<5,R::A>,
    // 0xfX
    ::SET<6,R::B>, ::SET<6,R::C>, ::SET<6,R::D>, ::SET<6,R::E>, ::SET<6,R::H>, ::SET<6,R::L>, ::SET<6,R::IHL>, ::SET<6,R::A>,  ::SET<7,R::B>, ::SET<7,R::C>, ::SET<7,R::D>, ::SET<7,R::E>, ::SET<7,R::H>, ::SET<7,R::L>, ::SET<7,R::IHL>, ::SET<7,R::A>,
};

CpuInstructions::CpuInstructions(Mmu& mmu, Registers& reg):
    m_state({mmu, reg, false, false})
{}

MCycles CpuInstructions::Execute(uint8_t opcode)
{
    m_state.cbOpCodeCycles = {0};
    m_state.branchTaken = false;

    s_Instructions[opcode](m_state);
    if (m_state.cbOpCodeCycles.cycles != 0)
    {
        return m_state.cbOpCodeCycles;
    }
    if (m_state.branchTaken)
    {
        return s_ConditionalOpCodeCycles[opcode];
    }
    return s_OpCodeCycles[opcode];
}

void CbOp(CpuState& state)
{
    uint8_t cbOpcode = state.mmu.Read(++state.reg.pc);
    state.cbOpCodeCycles = s_CbOpcodeCycles[cbOpcode];
    s_CbInstructions[cbOpcode](state);
}
