#include "CpuTranslator.h"
#include <stdexcept>
#include <unordered_map>

using InstructionT = std::tuple<Cpu::Instruction, Registers::Target, Registers::Target>;
using I = Cpu::Instruction;
using R = Registers::Target;

static InstructionT s_InstructionMap[0x10][0x10] = {
    { /* 0x0x */
       /* 0x00 */ {I::NOOP, R::NONE, R::NONE},
       /* 0x01 */ {I::LOAD, R::BC,   R::NN},
       /* 0x02 */ {I::LOAD, R::BC,   R::A},
       /* 0x03 */ {I::INC,  R::BC,   R::NONE},
       /* 0x04 */ {I::INC,  R::B,    R::NONE},
       /* 0x05 */ {I::DEC,  R::B,    R::NONE},
       /* 0x06 */ {I::LOAD, R::B,    R::N},
       /* 0x07 */ {I::RLCA, R::NONE, R::NONE},
       /* 0x08 */ {I::LOAD, R::NN,   R::SP},
       /* 0x09 */ {I::ADD,  R::HL,   R::BC},
       /* 0x0a */ {I::LOAD, R::A,    R::BC},
       /* 0x0b */ {I::DEC,  R::BC,   R::NONE},
       /* 0x0c */ {I::INC,  R::C,    R::NONE},
       /* 0x0d */ {I::DEC,  R::C,    R::NONE},
       /* 0x0e */ {I::LOAD, R::C,    R::N},
       /* 0x0f */ {I::RRCA, R::NONE, R::NONE}
    },
    { /* 0x1x */
       /* 0x10 */ {I::STOP, R::NONE, R::NONE},
       /* 0x11 */ {I::LOAD, R::DE,   R::NN},
       /* 0x12 */ {I::LOAD, R::DE,   R::A},
       /* 0x13 */ {I::INC,  R::DE,   R::NONE},
       /* 0x14 */ {I::INC,  R::D,    R::NONE},
       /* 0x15 */ {I::DEC,  R::D,    R::NONE},
       /* 0x16 */ {I::LOAD, R::D,    R::N},
       /* 0x17 */ {I::RLA,  R::NONE, R::NONE},
       /* 0x18 */ {I::JR,   R::eJ,    R::NONE},
       /* 0x19 */ {I::ADD,  R::HL,   R::DE},
       /* 0x1a */ {I::LOAD, R::A,    R::DE},
       /* 0x1b */ {I::DEC,  R::DE,   R::NONE},
       /* 0x1c */ {I::INC,  R::E,    R::NONE},
       /* 0x1d */ {I::DEC,  R::E,    R::NONE},
       /* 0x1e */ {I::LOAD, R::E,    R::N},
       /* 0x1f */ {I::RRA,  R::NONE, R::NONE}
    },
    // TODO: Rest
};

InstructionT TranslateOpCode(uint8_t opcode)
{
    uint8_t hi = opcode >> 2;
    uint8_t lo = opcode & 0xff;
    return s_InstructionMap[hi][lo];
}

uint8_t ConvertCpuInstruction(InstructionT instructionSet)
{
    return ConvertCpuInstruction(std::get<0>(instructionSet), std::get<1>(instructionSet), std::get<2>(instructionSet));
}

static std::unordered_map<I, std::unordered_map<R, std::unordered_map<R, uint8_t>>> s_InstructionSetMap = {{
    {I::NOOP, {{R::NONE, {{R::NONE, 0x00}}}}},
    {I::STOP, {{R::NONE, {{R::NONE, 0x10}}}}},
    {I::HALT, {{R::NONE, {{R::NONE, 0x76}}}}},
    {I::DI,   {{R::NONE, {{R::NONE, 0xf3}}}}},
    {I::EI,   {{R::NONE, {{R::NONE, 0xfb}}}}},
    {I::LOAD, {
        {R::B, {
            {R::N, 0x06},
            {R::B, 0x40}, {R::C, 0x41}, {R::D, 0x42}, {R::E, 0x43}, {R::H, 0x44}, {R::L, 0x45}, {R::HL, 0x46}, {R::A, 0x47},
        }},
        {R::C, {
            {R::N, 0x0e},
            {R::B, 0x48}, {R::C, 0x49}, {R::D, 0x4a}, {R::E, 0x4b}, {R::H, 0x4c}, {R::L, 0x4d}, {R::HL, 0x4e}, {R::A, 0x4f},
        }},
        {R::D, {
            {R::N, 0x16},
            {R::B, 0x50}, {R::C, 0x51}, {R::D, 0x52}, {R::E, 0x53}, {R::H, 0x54}, {R::L, 0x55}, {R::HL, 0x56}, {R::A, 0x57},
        }},
        {R::E, {
            {R::N, 0x1e},
            {R::B, 0x58}, {R::C, 0x59}, {R::D, 0x5a}, {R::E, 0x5b}, {R::H, 0x5c}, {R::L, 0x5d}, {R::HL, 0x5e}, {R::A, 0x5f},
        }},
        {R::H, {
            {R::N, 0x26},
            {R::B, 0x60}, {R::C, 0x61}, {R::D, 0x62}, {R::E, 0x63}, {R::H, 0x64}, {R::L, 0x65}, {R::HL, 0x66}, {R::A, 0x67},
        }},
        {R::L, {
            {R::N, 0x2e},
            {R::B, 0x68}, {R::C, 0x69}, {R::D, 0x6a}, {R::E, 0x6b}, {R::H, 0x6c}, {R::L, 0x6d}, {R::HL, 0x6e}, {R::A, 0x6f},
        }},
        {R::HL, {
            {R::N, 0x36},
            {R::B, 0x70}, {R::C, 0x71}, {R::D, 0x72}, {R::E, 0x73}, {R::H, 0x74}, {R::L, 0x75},                {R::A, 0x77},
        }},
        {R::A, {
            {R::N, 0x3e},
            {R::BC, 0x0a}, {R::DE, 0x1a}, {R::HLP, 0x2a}, {R::HLM, 0x3a},
            {R::B, 0x78}, {R::C, 0x79}, {R::D, 0x7a}, {R::E, 0x7b}, {R::H, 0x7c}, {R::L, 0x7d}, {R::HL, 0x7e}, {R::A, 0x7f},
            {R::NN, 0xfa},
        }},
        {R::BC, {
            {R::NN, 0x01}, {R::A, 0x02},
        }},
        {R::DE, {
            {R::NN, 0x11}, {R::A, 0x12},
        }},
        {R::HL, {
            {R::NN, 0x21},
            {R::SPe, 0xf8},
        }},
        {R::SP, {
            {R::NN, 0x31},
            {R::HL, 0xf9},
        }},
        {R::HLP, {
            {R::A, 0x22},
        }},
        {R::HLM, {
            {R::A, 0x32},
        }},
        {R::NN, {
            {R::SP, 0x08},
            {R::A, 0xea},
        }},
    }}, // I::LOAD
}};

uint8_t ConvertCpuInstruction(Cpu::Instruction inst, Registers::Target src, Registers::Target dst)
{
    if (!s_InstructionSetMap.contains(inst))
    {
        throw std::runtime_error("Unable to find mapping for Instruction");
    }

    const auto& srcMap = s_InstructionSetMap.at(inst);
    if (!srcMap.contains(src))
    {
        throw std::runtime_error("Unable to find mapping for Register src target");
    }

    const auto& dstMap = srcMap.at(src);
    if (!dstMap.contains(dst))
    {
        throw std::runtime_error("Unable to find mapping for Register dst target");
    }
    return dstMap.at(dst);
}

