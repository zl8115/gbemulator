#include "Registers.h"

#include <format>

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
