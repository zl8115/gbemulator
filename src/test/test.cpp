#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_predicate.hpp>
#include "Cpu.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <nlohmann/json.hpp>

using namespace std::string_literals;

using json = nlohmann::json;

const std::string TEST_DIR = "D:\\src\\sm83\\v1\\"s;

Cpu LoadCpuFromJson(const json& data)
{
    Cpu cpu;
    cpu.pc = data["pc"];
    cpu.sp = data["sp"];
    // cpu.ime = data["ime"];
    cpu.reg.a = data["a"];
    cpu.reg.b = data["b"];
    cpu.reg.c = data["c"];
    cpu.reg.d = data["d"];
    cpu.reg.e = data["e"];
    cpu.reg.f = data["f"];
    cpu.reg.h = data["h"];
    cpu.reg.l = data["l"];
    for (auto& value: data["ram"])
    {
        cpu.ram[value[0]] = value[1];
    }
    return cpu;
}

void RunTestFromJson(std::filesystem::path jsonFile)
{
    std::ifstream f(jsonFile);
    json data = json::parse(f);
    for (auto& [_, test_case]: data.items())
    {
        const std::string test_name = test_case["name"];
        SECTION(test_name)
        {
            // Setup
            Cpu cpu = LoadCpuFromJson(test_case["initial"]);

            // Act
            cpu.Step();

            // Assert
            auto& final = test_case["final"];
            CHECK(cpu.reg.a == final["a"]);
            CHECK(cpu.reg.b == final["b"]);
            CHECK(cpu.reg.c == final["c"]);
            CHECK(cpu.reg.d == final["d"]);
            CHECK(cpu.reg.e == final["e"]);
            CHECK(cpu.reg.f == final["f"]);
            CHECK(cpu.reg.h == final["h"]);
            CHECK(cpu.reg.l == final["l"]);
            CHECK(cpu.pc == final["pc"]);
            CHECK(cpu.sp == final["sp"]);
            // CHECK(cpu.ime = final["ime"]);
            for (auto& value: final["ram"])
            {
                cpu.ram[value[0]] = value[1];
            }
        }
    }
}

TEST_CASE( "00", "tests" ) {
    ::RunTestFromJson(TEST_DIR + "00.json");
}

TEST_CASE( "01", "tests" ) {
    ::RunTestFromJson(TEST_DIR + "01.json");
}

TEST_CASE( "02", "tests" ) {
    ::RunTestFromJson(TEST_DIR + "02.json");
}

TEST_CASE( "03", "tests" ) {
    ::RunTestFromJson(TEST_DIR + "03.json");
}

TEST_CASE( "04", "tests" ) {
    ::RunTestFromJson(TEST_DIR + "04.json");
}
