#include <iostream>
#include <format>

#include "cpu.h"

template<>
struct std::formatter<Registers>: std::formatter<std::string> 
{
    auto format(Registers reg, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format("A: {}, F:{}, B: {}, C:{}, D:{}, E:{}, H:{}, L:{}",
                        reg.a, reg.f, reg.b, reg.c, reg.d, reg.e, reg.h, reg.l)
            , ctx);
    }
};

std::ostream& operator<<(std::ostream& os, Registers const& reg)
{
    return os << std::format("{}", reg);
}

std::ostream& operator<<(std::ostream& os, Cpu const& cpu)
{
    return os << std::format("PC: {}, Registers: {}", cpu.pc, cpu.reg);
}

int main()
{
    Cpu cpu;
    std::cout << cpu << std::endl;
    cpu.Step();
    std::cout << cpu << std::endl;
}
