#pragma once

#include "cpu.h"
#include "detail/impl_helper.h"
#include "detail/cpu/cpu_impl.h"
#include "detail/cpu/registers.h"

#include <format>

template<>
struct std::formatter<detail::Registers>: std::formatter<std::string> 
{
    auto format(const detail::Registers& reg, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format(
                "CPU Registers\n\n"
                "IME: {}\n"
                "AF : 0x{:02X} 0x{:02X}\n"
                "BC : 0x{:02X} 0x{:02X}\n"
                "DE : 0x{:02X} 0x{:02X}\n"
                "HL : 0x{:02X} 0x{:02X}\n"
                "PC : 0x{:04X}\n"
                "SP : 0x{:04X}\n",
                reg.ime, reg.a, reg.f, reg.b, reg.c, reg.d, reg.e, reg.h, reg.l, reg.pc, reg.sp)
            , ctx);
    }
};

template<>
struct std::formatter<detail::CpuState>: std::formatter<std::string> 
{
    auto format(const detail::CpuState& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format(
                "CPU State\n\n"
                "Halted            : {}\n"
                "HaltBug           : {}\n"
                "Interrrupt Pending: {}\n"
                "Branch Taken      : {}\n"
                "cb Opcode Cycles  : {}",
                obj.halted,
                obj.haltBug,
                obj.interruptPending,
                obj.branchTaken,
                obj.cbOpCodeCycles.cycles)
            , ctx);
    }
};

template<>
struct std::formatter<detail::CpuImpl>: std::formatter<std::string> 
{
    auto format(const detail::CpuImpl& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format(
                "CPU:\n"
                "------\n"
                "EI: {}\n"
                "------\n"
                "{}\n"
                "------\n"
                "{}\n",
                obj.GetEi(),
                obj.GetRegister(),
                obj.GetState())
            , ctx);
    }
};

template<>
struct std::formatter<Cpu>: std::formatter<std::string> 
{
    auto format(const Cpu& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format("{}", detail::ImplHelper::ExtractImpl(obj)) , ctx);
    }
};
