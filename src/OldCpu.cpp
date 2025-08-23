#include "OldCpu.h"
#include "Registers.h"
#include "formatters.h"

#include <cstdint>
#include <stdexcept>
#include <format>

uint8_t OldCPU::Execute(OldCPU::Instruction instruction, uint8_t target)
{
    switch (instruction)
    {
        case Instruction::ADD:
        {
            return Add(Registers::Target::A, m_reg.Get(static_cast<Registers::Target>(target)));
        }
        case Instruction::LD:
        {
            switch (target)
            {
                // case Registers::LoadTarget::D8_A:
                //     return Load(Registers::Target::D8, Registers::Target::A);
                // case Registers::LoadTarget::B_C:
                //     return Load(Registers::Target::B, Registers::Target::C);
                default:
                    throw std::runtime_error("Unknown LD targets");
            }
        }
        case Instruction::INC:
        {
            return Add(static_cast<Registers::Target>(target), 1);
        }
        default:
            throw std::runtime_error("Unsupported instruction");
    }
    return m_pc + 1;
}

void OldCPU::Step()
{
    auto instruction_byte = m_bus.ReadByte(m_pc);
    bool prefixed = instruction_byte == 0xCB;
    if (prefixed)
    {
        instruction_byte = m_bus.ReadByte(m_pc + 1);
    }

    auto [instruction, target] = InstructionFromByte(instruction_byte);
    if (instruction == Instruction::INVALID)
    {
        throw std::runtime_error("Unknown instruction found for: {}");
    }
    auto next_pc = Execute(instruction, target);
    m_pc = next_pc;
}


// std::function<uint8_t(void)> OldCPU::UnprefixedInstructionFromByte(uint8_t byte)
// {
//     switch (byte)
//     {
//         // case 0x02:
//         //     return {OldCPU::Instruction::INC, Registers::Target::BC};
//         case 0x06:
//             return std::bind(&OldCPU::Load<SRegTarget::B>, this);
//         // case 0x13:
//         //     return {OldCPU::Instruction::INC, OldCPU::RegisterTarget::DE};
//         case 0x41:
//             return std::bind(&OldCPU::Load<SRegTarget::B, SRegTarget::C>, this);
//     }
//     throw std::logic_error("Unsupported instruction byte code");
// }

// std::function<uint8_t(void)> OldCPU::PrefixedInstructionFromByte(uint8_t byte)
// {
//     switch (byte)
//     {
//         // case 0x00:
//         //     return {OldCPU::Instruction::RLC, SRegTarget::B};
//     }
//     throw std::logic_error("Unsupported instruction byte code");
// }


// std::function<uint8_t(void)> OldCPU::InstructionFromByte(uint8_t byte)
// {
//     if (byte == 0xCB)
//     {
//         auto instruction_byte = m_bus.ReadByte(++m_pc);
//         return PrefixedInstructionFromByte(instruction_byte);
//     }
//     else
//     {
//         return UnprefixedInstructionFromByte(byte);
//     }
// }

namespace {

std::pair<OldCPU::Instruction, Registers::Target> UnprefixedInstructionFromByte(uint8_t byte)
{
    switch (byte)
    {
        case 0x02:
            return {OldCPU::Instruction::INC, Registers::Target::BC};
        case 0x06:
            return {OldCPU::Instruction::LD, Registers::Target::BN};
        case 0x13:
            return {OldCPU::Instruction::INC, Registers::Target::DE};
        case 0x41:
            return {OldCPU::Instruction::LD, Registers::Target::BC};
    }
    throw std::logic_error("Unsupported instruction byte code");
}

std::pair<OldCPU::Instruction, Registers::Target> PrefixedInstructionFromByte(uint8_t byte)
{
    switch (byte)
    {
        case 0x00:
            return {OldCPU::Instruction::RLC, Registers::Target::B};
    }
    throw std::logic_error("Unsupported instruction byte code");
}
} // namespace

std::pair<OldCPU::Instruction, Registers::Target> OldCPU::InstructionFromByte(uint8_t byte)
{
    if (byte == 0xCB)
    {
        auto instruction_byte = m_bus.ReadByte(++m_pc);
        return PrefixedInstructionFromByte(instruction_byte);
    }
    else
    {
        return UnprefixedInstructionFromByte(byte);
    }
}

uint8_t OldCPU::Add(Registers::Target target, uint8_t value)
{
    uint8_t ori_value = m_reg.Get(target);
    uint8_t new_value = ori_value + value;

    m_reg.f &= !Registers::Flags::ALL;
    if (new_value == 0)
        m_reg.f |= Registers::Flags::ZERO_FLAG;

    if ((ori_value & 0xF) + (value & 0xF) > 0xF)
        m_reg.f |= Registers::Flags::HALF_CARRY_FLAG;

    if (new_value < m_reg.a)
        m_reg.f |=  Registers::Flags::CARRY_FLAG;

    m_reg.Set(target, new_value);

    return m_pc + 1;
}

uint8_t OldCPU::Load(Registers::Target source, Registers::Target target)
{
    if (source == Registers::Target::D8)
    {
        auto value = m_bus.ReadByte(m_pc + 1);
        m_reg.Set(target, value);
        return m_pc + 2;
    }
    else if (source == Registers::Target::HL)
    {
        auto addr = m_reg.GetDouble(Registers::Target::HL);
        auto value = m_bus.ReadByte(addr);
        m_reg.Set(target, value);
        return m_pc + 2;
    }
    else if (source >= Registers::Target::A && source <= Registers::Target::L)
    {
        m_reg.Set(target, m_reg.Get(source));
        return m_pc + 1;
    }
    else 
    {
        throw std::runtime_error("LD: Unexpected target");
    }
}

// uint8_t OldCPU::Add(uint8_t value)
// {
//     uint8_t new_value = m_reg.a + value;
//
//     m_reg.f &= !Registers::Flags::ALL;
//     if (new_value == 0)
//         m_reg.f |= Registers::Flags::ZERO_FLAG;
//
//     if ((m_reg.a & 0xF) + (value & 0xF) > 0)
//         m_reg.f |= Registers::Flags::HALF_CARRY_FLAG;
//
//     if (new_value < m_reg.a)
//         m_reg.f |=  Registers::Flags::CARRY_FLAG;
//
//     return new_value;
// }

bool ShouldJump(const Registers& reg, OldCPU::JumpTest test)
{
    switch (test)
    {
        case OldCPU::JumpTest::NotZero:
            return !reg.HasFlag(Registers::Flags::ZERO_FLAG);
        case OldCPU::JumpTest::Zero:
            return reg.HasFlag(Registers::Flags::ZERO_FLAG);
        case OldCPU::JumpTest::NotCarry:
            return !reg.HasFlag(Registers::Flags::CARRY_FLAG);
        case OldCPU::JumpTest::Carry:
            return reg.HasFlag(Registers::Flags::ZERO_FLAG);
        case OldCPU::JumpTest::Always:
            return true;
    }
}

uint8_t OldCPU::Jump(OldCPU::JumpTest test)
{
    bool shouldJump = ShouldJump(m_reg, test);
    if (!shouldJump)
    {
        return m_pc + 3;
    }
    // Gameboy is little endian, so m_pc + 2 is MSB.
    uint16_t msb = m_bus.ReadByte(m_pc + 2);
    uint16_t lsb = m_bus.ReadByte(m_pc + 1);
    return (msb << 8) | lsb;
}

uint8_t OldCPU::ReadFromReg(Registers::Target target)
{
    return m_reg.Get(target);
}

std::ostream& operator<<(std::ostream& os, OldCPU const& cpu)
{
    return os << std::format("Registers: {}", cpu.m_reg);
}
