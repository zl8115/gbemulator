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
    cpu.pc = 16701;
    cpu.sp = 3350;
    cpu.reg.a = 199;
    cpu.reg.b = 79;
    cpu.reg.c = 6;
    cpu.reg.d = 5;
    cpu.reg.e = 239;
    cpu.reg.f = 16;
    cpu.reg.h = 227;
    cpu.reg.l = 181;
    // cpu.ime = 1;
    // cpu.ie = 0;
    cpu.ram[16701] = 8;
    cpu.ram[16702] = 3;
    cpu.ram[16703] = 194;
    cpu.ram[49667] = 0;
    cpu.ram[49668] = 0;

    // Act
    std::cout << cpu << std::endl;
    std::cout << cpu.ram[49667] << std::endl;
    std::cout << cpu.ram[49668] << std::endl;
    cpu.Step();
    std::cout << cpu.ram[49667] << std::endl;
    std::cout << cpu.ram[49668] << std::endl;

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
