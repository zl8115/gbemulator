#include <iostream>
#include <format>

#include "Cpu.h"
#include "formatters.h"

std::ostream& operator<<(std::ostream& os, Registers const& reg)
{
    return os << std::format("{}", reg);
}

int main()
{
    Cpu cpu;
    cpu.pc = 39227;
    cpu.sp = 41151;
    cpu.reg.a = 125;
    cpu.reg.b = 86;
    cpu.reg.c = 182;
    cpu.reg.d = 23;
    cpu.reg.e = 236;
    cpu.reg.f = 0;
    cpu.reg.h = 167;
    cpu.reg.l = 96;
    // cpu.ime = 1;
    // cpu.ie = 0;
    cpu.ram[39227] = 4;

    // Act
    std::cout << cpu << std::endl;
    cpu.Step();

    // Assert
    // REQUIRE(cpu.reg.a == 81);
    // REQUIRE(cpu.reg.b == 45);
    // REQUIRE(cpu.reg.c == 187);
    // REQUIRE(cpu.reg.d == 165);
    // REQUIRE(cpu.reg.e == 189);
    // REQUIRE(cpu.reg.f == 240);
    // REQUIRE(cpu.reg.h == 149);
    // REQUIRE(cpu.reg.l == 112);
    // REQUIRE(cpu.pc == 58881);
    // REQUIRE(cpu.sp == 12870);
    // // REQUIRE(cpu.ime = 0);
    // REQUIRE(cpu.ram[58878] == 1);
    // REQUIRE(cpu.ram[58879] == 187);
    // REQUIRE(cpu.ram[58880] == 45);
    std::cout << cpu << std::endl;

    // cpu.Step();
    // std::cout << cpu << std::endl;

    // std::cout << cpu << std::endl;
    // cpu.Execute(Cpu::Instruction::INC, Registers::Target::C);
    // std::cout << cpu << std::endl;
    // cpu.Execute(Cpu::Instruction::ADD, Registers::Target::C);
    // std::cout << cpu << std::endl;
    // throw std::runtime_error("Whoops");
}
