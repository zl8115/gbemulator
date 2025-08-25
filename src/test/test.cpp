#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_predicate.hpp>
#include "Cpu.h"

#include <fstream>
#include <filesystem>
#include <string>
#include <nlohmann/json.hpp>

using namespace std::string_literals;

using json = nlohmann::json;

const std::string TEST_DIR = "/home/zerongl/src/sm83/v1/"s;

Cpu LoadCpuFromJson(const json& data)
{
    Cpu cpu;
    cpu.pc = data["pc"].get<uint16_t>();
    cpu.sp = data["sp"].get<uint16_t>();
    // cpu.ime = data["ime"];
    cpu.reg.a = data["a"].get<uint8_t>();
    cpu.reg.b = data["b"].get<uint8_t>();
    cpu.reg.c = data["c"].get<uint8_t>();
    cpu.reg.d = data["d"].get<uint8_t>();
    cpu.reg.e = data["e"].get<uint8_t>();
    cpu.reg.f = data["f"].get<uint8_t>();
    cpu.reg.h = data["h"].get<uint8_t>();
    cpu.reg.l = data["l"].get<uint8_t>();
    for (auto& value: data["ram"])
    {
        uint16_t addr = value[0].get<uint16_t>();
        cpu.ram[addr] = value[1].get<uint8_t>();
    }
    return std::move(cpu);
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
            CHECK(cpu.pc == final["pc"].get<uint16_t>());
            CHECK(cpu.sp == final["sp"].get<uint16_t>());
            CHECK(cpu.reg.a == final["a"].get<uint8_t>());
            CHECK(cpu.reg.b == final["b"].get<uint8_t>());
            CHECK(cpu.reg.c == final["c"].get<uint8_t>());
            CHECK(cpu.reg.d == final["d"].get<uint8_t>());
            CHECK(cpu.reg.e == final["e"].get<uint8_t>());
            CHECK(cpu.reg.f == final["f"].get<uint8_t>());
            CHECK(cpu.reg.h == final["h"].get<uint8_t>());
            CHECK(cpu.reg.l == final["l"].get<uint8_t>());
            // CHECK(cpu.ime = final["ime"]);
            for (auto& value: final["ram"])
            {
                uint16_t addr = value[0].get<uint16_t>();
                CHECK(cpu.ram[addr] == value[1].get<uint8_t>());
            }
        }
    }
}

// TEST_CASE( "00", "tests" ) {
//     ::RunTestFromJson(TEST_DIR + "00.json");
// }

// TEST_CASE( "01", "tests" ) {
//     ::RunTestFromJson(TEST_DIR + "01.json");
// }

// TEST_CASE( "02", "tests" ) {
//     ::RunTestFromJson(TEST_DIR + "02.json");
// }

// TEST_CASE( "03", "tests" ) {
//     ::RunTestFromJson(TEST_DIR + "03.json");
// }

// TEST_CASE( "04", "tests" ) {
//     ::RunTestFromJson(TEST_DIR + "04.json");
// }
