#include "CpuOperator.h"
#include "Cpu.h"
#include <functional>
#include <iostream>

using I = Cpu::Instruction;
using R = Registers::Target;

template<R T>
concept SmallReg = T == R::A || T == R::B || T == R::C || T == R::D ||
    T == R::E || T == R::H || T == R::L;

template <R T>
concept LargeReg = T == R::BC || T == R::DE || T == R::HL;

template <R T>
concept RegTarget = (SmallReg<T> || LargeReg<T>);

// TODO: Consider this section
/*
uint8_t CpuOperator::Execute(Cpu& cpu, uint8_t opcode)
{
    switch (opcode)
    {
        case 0x02:
            return Add(cpu, Reg::BC, 1);
        case 0x06:
            return Load(cpu, Reg::BN, Reg::NONE); // TODO: Unimplemented?
        case 0x13:
            return Add(cpu, Reg::DE, 1);
        case 0x41:
            return Load(cpu, Reg::B, Reg::C);
    }
    throw std::logic_error("Unsupported instruction byte code");
    if (opcode == 0xCB)
    {
        // TODO: m_pc + 1 or ++m_pc?
        auto prefixedOpCode = cpu.m_bus.ReadByte(cpu.m_pc + 1);
        return ExecutePrefixed(cpu, prefixedOpCode);
    }
    return 0;
}

uint8_t CpuOperator::ExecutePrefixed(Cpu& cpu, uint8_t opcode)
{
    throw std::logic_error("Unsupported instruction byte code");
    return 0;
}
*/

namespace {
void Noop(Cpu& cpu)
{
    ++cpu.pc;
    return;
}

template <R Src>
uint8_t& Get(Cpu& cpu) requires SmallReg<Src>
{
    if constexpr(Src == R::A)
        return cpu.reg.a;
    if constexpr(Src == R::B)
        return cpu.reg.b;
    if constexpr(Src == R::C)
        return cpu.reg.c;
    if constexpr(Src == R::D)
        return cpu.reg.d;
    if constexpr(Src == R::E)
        return cpu.reg.e;
    if constexpr(Src == R::H)
        return cpu.reg.h;
    if constexpr(Src == R::L)
        return cpu.reg.l;
}

template <R Src>
uint8_t& GetLo(Cpu& cpu) requires LargeReg<Src>
{
    if constexpr(Src == R::BC)
        return cpu.reg.c;
    if constexpr(Src == R::DE)
        return cpu.reg.e;
    if constexpr(Src == R::HL)
        return cpu.reg.l;
}

template <R Src>
uint8_t& GetHi(Cpu& cpu) requires LargeReg<Src>
{
    if constexpr(Src == R::BC)
        return cpu.reg.b;
    if constexpr(Src == R::DE)
        return cpu.reg.d;
    if constexpr(Src == R::HL)
        return cpu.reg.h;
}

template <R Dst>
void Set(Cpu& cpu, uint16_t value) requires SmallReg<Dst>
{
    Get<Dst>(cpu) = value;
}

template <R Dst>
void Set(Cpu& cpu, uint16_t value) requires LargeReg<Dst>
{
    uint8_t hibyte = value >> 8;
    uint8_t lobyte = value & 0xff;

    if constexpr(Dst == R::BC)
    {
        Set<R::B>(cpu, hibyte);
        Set<R::C>(cpu, lobyte);
    }
    else if constexpr(Dst == R::DE)
    {
        Set<R::D>(cpu, hibyte);
        Set<R::E>(cpu, lobyte);
    }
    else if constexpr(Dst == R::HL)
    {
        Set<R::H>(cpu, hibyte);
        Set<R::L>(cpu, lobyte);
    }
}

template <R Src>
uint16_t Read(Cpu& cpu) requires SmallReg<Src>
{
    return Get<Src>(cpu);
}

template <R Src>
uint16_t Read(Cpu& cpu) requires LargeReg<Src>
{
    // Wide Reads
    uint16_t res = 0;
    if constexpr(Src == R::BC)
    {
        res |= cpu.reg.b << 8;
        res |= cpu.reg.c;
    }
    if constexpr(Src == R::DE)
    {
        res |= cpu.reg.d << 8;
        res |= cpu.reg.e;
    }
    if constexpr(Src == R::HL)
    {
        res |= cpu.reg.h << 8;
        res |= cpu.reg.l;
    }
    return res;
}

template <R Dst, R Src>
void Load(Cpu& cpu) requires (Src == R::NN) && LargeReg<Dst>
{
    if constexpr(Dst == R::BC)
    {
        Set<R::C>(cpu, cpu.ram[++cpu.pc]);
        Set<R::B>(cpu, cpu.ram[++cpu.pc]);
    }
    else if constexpr(Dst == R::DE)
    {
        Set<R::E>(cpu, cpu.ram[++cpu.pc]);
        Set<R::D>(cpu, cpu.ram[++cpu.pc]);
    }
    else if constexpr(Dst == R::HL)
    {
        Set<R::L>(cpu, cpu.ram[++cpu.pc]);
        Set<R::H>(cpu, cpu.ram[++cpu.pc]);
    }
    ++cpu.pc;
}

template <R Dst, R Src>
void Load(Cpu& cpu) requires LargeReg<Dst> && SmallReg<Src>
{
    auto addr = Read<Dst>(cpu);
    cpu.ram[addr] = Read<Src>(cpu);
    ++cpu.pc;
}

template <R Dst, R Src>
void Add(Cpu& cpu)
{
    Add<Dst>(cpu, Read<Src>());
}

template <R Dst>
void Add(Cpu& cpu, uint8_t value) requires SmallReg<Dst>
{
    uint8_t ori_value = Read<Dst>(cpu);
    uint8_t new_value = ori_value + value;

    cpu.reg.f &= ~(Registers::Flags::NEGATE_FLAG | Registers::Flags::ZERO_FLAG | Registers::Flags::HALF_CARRY_FLAG) ;
    // cpu.reg.f = 0;
    if (new_value == 0)
        cpu.reg.f |= Registers::Flags::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        cpu.reg.f |= Registers::Flags::HALF_CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.pc;
}

template <R Dst>
void Add(Cpu& cpu, uint16_t value) requires LargeReg<Dst>
{
    uint16_t ori_value = Read<Dst>(cpu);
    uint16_t new_value = ori_value + value;

    cpu.reg.f &= !Registers::Flags::ALL;
    // cpu.reg.f = 0;
    if (new_value == 0)
        cpu.reg.f |= Registers::Flags::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        cpu.reg.f |= Registers::Flags::HALF_CARRY_FLAG;

    if (new_value < ori_value)
        cpu.reg.f |=  Registers::Flags::CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.pc;
}

template <R Dst>
void Inc(Cpu& cpu) requires SmallReg<Dst>
{
    Add<Dst>(cpu, 1);
}

template <R Dst>
void Inc(Cpu& cpu) requires LargeReg<Dst>
{
    auto& lobyte = GetLo<Dst>(cpu);
    ++lobyte;
    if (lobyte == 0)
    {
        ++GetHi<Dst>(cpu);
    }
    ++cpu.pc;
}

template <R Dst, R Src>
void Sub(Cpu& cpu)
{
    Sub<Dst>(cpu, Read<Src>());
}

template <R Dst>
void Sub(Cpu& cpu, uint16_t value)
{
    uint16_t ori_value = Read<Dst>(cpu);
    uint16_t new_value = ori_value - value;

    cpu.reg.f &= !Registers::Flags::ALL;
    cpu.reg.f |= Registers::Flags::NEGATE_FLAG; 
    if (new_value == 0)
        cpu.reg.f |= Registers::Flags::ZERO_FLAG;

    if ((ori_value & 0xF) - (value & 0xF) > 0xF)
        cpu.reg.f |= Registers::Flags::HALF_CARRY_FLAG;

    if (new_value > cpu.reg.a)
        cpu.reg.f |=  Registers::Flags::CARRY_FLAG;

    Set<Dst>(cpu, new_value);
    ++cpu.pc;
}

template <R Dst>
void Dec(Cpu& cpu)
{
    Sub<Dst>(cpu, 1);
}

} // namespace

std::function<void(Cpu&)> s_Instructions[0x100] = {
    // 0x0X
    ::Noop, ::Load<R::BC, R::NN>, ::Load<R::BC, R::A>, ::Inc<R::BC>, ::Inc<R::B>, ::Dec<R::B>, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
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

void CpuOperator::Execute(Cpu& cpu, uint8_t opcode)
{
    s_Instructions[opcode](cpu);
    // auto [inst, src, dst] = TranslateOpCode(opcode);
    // Execute(cpu, inst, src, dst);
}

void CpuOperator::Execute(Cpu& cpu, Cpu::Instruction inst, Registers::Target src, Registers::Target dst)
{
    switch (inst)
    {
        case I::NOOP:
            Noop(cpu);
            break;
        case I::INC:
            Add(cpu, src, 1);
            break;
        case I::LOAD:
            Load(cpu, src, dst);
            break;
        case I::ADD:
            Add(cpu, R::A, cpu.ReadFromReg(src));
            break;
        default:
            throw std::logic_error("Unsupported instruction");
    }
    return;
    throw std::logic_error("Unsupported instruction");
}

// bool ShouldJump(const Registers& reg, Cpu::JumpTest test)
// {
//     switch (test)
//     {
//         case Cpu::JumpTest::NotZero:
//             return !reg.HasFlag(Registers::Flags::ZERO_FLAG);
//         case Cpu::JumpTest::Zero:
//             return reg.HasFlag(Registers::Flags::ZERO_FLAG);
//         case Cpu::JumpTest::NotCarry:
//             return !reg.HasFlag(Registers::Flags::CARRY_FLAG);
//         case Cpu::JumpTest::Carry:
//             return reg.HasFlag(Registers::Flags::ZERO_FLAG);
//         case Cpu::JumpTest::Always:
//             return true;
//     }
// }
//
// uint8_t CpuOperator::Jump(Cpu::JumpTest test)
// {
//     bool shouldJump = ShouldJump(m_reg, test);
//     if (!shouldJump)
//     {
//         return m_pc + 3;
//     }
//     // Gameboy is little endian, so m_pc + 2 is MSB.
//     uint16_t msb = m_bus.ReadByte(m_pc + 2);
//     uint16_t lsb = m_bus.ReadByte(m_pc + 1);
//     return (msb << 8) | lsb;
// }

void CpuOperator::Add(Cpu& cpu, Registers::Target target, uint8_t value)
{
    uint8_t ori_value = cpu.reg.Get(target);
    uint8_t new_value = ori_value + value;

    cpu.reg.f &= !Registers::Flags::ALL;
    if (new_value == 0)
        cpu.reg.f |= Registers::Flags::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        cpu.reg.f |= Registers::Flags::HALF_CARRY_FLAG;

    if (new_value < cpu.reg.a)
        cpu.reg.f |=  Registers::Flags::CARRY_FLAG;

    cpu.reg.Set(target, new_value);

    ++cpu.pc;
}

void CpuOperator::Load(Cpu& cpu, Registers::Target source, Registers::Target target)
{
    if (source == Registers::Target::D8)
    {
        auto addr = cpu.pc + 1;
        auto value = cpu.ram[addr];
        cpu.reg.Set(target, value);
        ++++cpu.pc;
    }
    else if (source == Registers::Target::HL)
    {
        auto addr = cpu.reg.GetDouble(Registers::Target::HL);
        auto value = cpu.ram[addr];
        cpu.reg.Set(target, value);
        ++++cpu.pc;
    }
    else if (source >= Registers::Target::A && source <= Registers::Target::L)
    {
        cpu.reg.Set(target, cpu.reg.Get(source));
        ++cpu.pc;
    }
    else 
    {
        throw std::runtime_error("LD: Unexpected target");
    }
}

void CpuOperator::Noop(Cpu& cpu)
{
    ++cpu.pc;
    return;
}
