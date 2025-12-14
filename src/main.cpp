#include <iostream>
#include <format>

#include "soc.h"
#include "detail/impl_helper.h"
#include "detail/cpu_impl.h"
#include "detail/cpu_registers.h"

using Registers = detail::Registers;

template<>
struct std::formatter<Registers>: std::formatter<std::string> 
{
    auto format(Registers reg, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format("PC: {}, A: {}, F:{}, B: {}, C:{}, D:{}, E:{}, H:{}, L:{}",
                        reg.pc, reg.a, reg.f, reg.b, reg.c, reg.d, reg.e, reg.h, reg.l)
            , ctx);
    }
};

std::ostream& operator<<(std::ostream& os, Registers const& reg)
{
    return os << std::format("{}", reg);
}

std::ostream& operator<<(std::ostream& os, Soc const& soc)
{
    const auto& reg = detail::ImplHelper::ExtractImpl(soc.m_cpu).GetRegister();
    return os << std::format("Registers: {}", reg);
}

int main()
{
    Soc soc;
    std::cout << soc << std::endl;
    soc.Step();
    std::cout << soc << std::endl;
}
