#include "tester.h"

#include "soc.h"
#include "detail/impl_helper.h"
#include "detail/cpu_impl.h"
#include "detail/mmu_impl.h"
#include "detail/cpu_registers.h"

#include <nlohmann/json.hpp>
#include <catch2/catch_test_macros.hpp>

#include <fstream>
#include <iostream>

using json = nlohmann::json;

// The `tester` intends to reduce overhead of creating a
// Catch2 Dynamic Section. This is why it runs the test
// first and only if it fails, it creates a Dynamic Section
// and reruns the test. The code is rather repetitive,
// but they serve its simplistic purpose.

namespace {

void load_state(Registers& cpuReg, Mmu& mmu, const json& initial)
{
    // Some of the tests (e.g. CB 66 01FD) do not respect some of the MMU
    // Echo RAM / DMA transfer flags, so we need to enable the test mode
    detail::ImplHelper::ExtractImpl(mmu).EnableTestMode();

    mmu.ime = initial.value<std::uint8_t>("ime", 0);
    mmu.ie = initial.value<std::uint8_t>("ie", 0);
    cpuReg.a = initial.value<std::uint8_t>("a", 0);
    cpuReg.b = initial.value<std::uint8_t>("b", 0);
    cpuReg.c = initial.value<std::uint8_t>("c", 0);
    cpuReg.d = initial.value<std::uint8_t>("d", 0);
    cpuReg.e = initial.value<std::uint8_t>("e", 0);
    cpuReg.f = initial.value<std::uint8_t>("f", 0);
    cpuReg.h = initial.value<std::uint8_t>("h", 0);
    cpuReg.l = initial.value<std::uint8_t>("l", 0);
    cpuReg.pc = initial.value<std::uint16_t>("pc", 0);
    cpuReg.sp = initial.value<std::uint16_t>("sp", 0);

    if (initial.contains("ram"))
    {
        int addr = 0;
        int value = 0;
        for (const auto& [_,v]: initial["ram"].items())
        {
            addr = v.at(0).get<int>();
            value = v.at(1).get<int>();
            mmu.Write(addr, value);
        }
    }

    return;
}

bool check_final_state(Registers& cpuReg, Mmu& mmu, json final)
{
    bool hasFailures = false;
    hasFailures |= mmu.ime != final.value<std::uint8_t>("ime", 0);
    hasFailures |= mmu.ei != final.value<std::uint8_t>("ei", 0);
    hasFailures |= cpuReg.a != final.value<std::uint8_t>("a", 0);
    hasFailures |= cpuReg.b != final.value<std::uint8_t>("b", 0);
    hasFailures |= cpuReg.c != final.value<std::uint8_t>("c", 0);
    hasFailures |= cpuReg.d != final.value<std::uint8_t>("d", 0);
    hasFailures |= cpuReg.e != final.value<std::uint8_t>("e", 0);
    hasFailures |= cpuReg.f != final.value<std::uint8_t>("f", 0);
    hasFailures |= cpuReg.h != final.value<std::uint8_t>("h", 0);
    hasFailures |= cpuReg.l != final.value<std::uint8_t>("l", 0);
    hasFailures |= cpuReg.pc != final.value<std::uint16_t>("pc", 0);
    hasFailures |= cpuReg.sp != final.value<std::uint16_t>("sp", 0);
    if (final.contains("ram"))
    {
        int addr = 0;
        int value = 0;
        for (const auto& [_,v]: final["ram"].items())
        {
            addr = v.at(0).get<int>();
            value = v.at(1).get<int>();
            hasFailures |= mmu.Read(addr) != value;
        }
    }

    return !hasFailures;
}

bool test_case_will_pass(const json& test_case)
{
    const auto name = test_case.value<std::string>("name", "");
    // Skip cycle checks for HALT and STOP
    const bool skipCyclesCheck = name.starts_with("10") || name.starts_with("76");
    const auto& initial = test_case["initial"];
    const auto& final = test_case["final"];
    const auto& cycles = test_case["cycles"];

    Soc soc;
    Mmu& mmu = soc.m_mmu;
    Cpu& cpu = soc.m_cpu;
    Registers& reg = detail::ImplHelper::ExtractImpl(cpu).GetRegister();
    load_state(reg, mmu, initial);

    auto cyclesTaken = cpu.Step().cycles;
    if (!skipCyclesCheck && cyclesTaken != cycles.size())
        return false;
    return check_final_state(reg, mmu, final);
}

void run_dynamic_section_test(const json& test_case)
{
    const auto name = test_case.value<std::string>("name", "");
    const auto& initial = test_case["initial"];
    const auto& final = test_case["final"];
    const auto& cycles = test_case["cycles"];
    DYNAMIC_SECTION(name)
    {
        Soc soc;
        Mmu& mmu = soc.m_mmu;
        Cpu& cpu = soc.m_cpu;
        Registers& reg =detail::ImplHelper::ExtractImpl(cpu).GetRegister();
        load_state(reg, mmu, initial);
        std::cout << static_cast<int>(reg.h) << '|' << static_cast<int>(reg.l) << std::endl;
        std::cout << static_cast<int>(mmu.Read(52998)) << std::endl;
        std::cout << static_cast<int>(mmu.Read(52999)) << std::endl;
        std::cout << static_cast<int>(mmu.Read(61190)) << std::endl;

        auto cyclesTaken = cpu.Step().cycles;
        INFO("Initial: " + nlohmann::to_string(initial));
        INFO("Final: " + nlohmann::to_string(final));

        // In the checks, we cast to int rather than uint8/16 to make the output comprehensible
        CHECK(static_cast<int>(mmu.ime) == final.value<int>("ime", 0));
        CHECK(static_cast<int>(mmu.ei) == final.value<int>("ei", 0));
        CHECK(static_cast<int>(reg.a) == final.value<int>("a", 0));
        CHECK(static_cast<int>(reg.b) == final.value<int>("b", 0));
        CHECK(static_cast<int>(reg.c) == final.value<int>("c", 0));
        CHECK(static_cast<int>(reg.d) == final.value<int>("d", 0));
        CHECK(static_cast<int>(reg.e) == final.value<int>("e", 0));
        CHECK(static_cast<int>(reg.f) == final.value<int>("f", 0));
        CHECK(static_cast<int>(reg.h) == final.value<int>("h", 0));
        CHECK(static_cast<int>(reg.l) == final.value<int>("l", 0));
        CHECK(static_cast<int>(reg.pc) == final.value<int>("pc", 0));
        CHECK(static_cast<int>(reg.sp) == final.value<int>("sp", 0));
        if (final.contains("ram"))
        {
            int addr = 0;
            int value = 0;
            for (const auto& [_,v]: final["ram"].items())
            {
                addr = v.at(0).get<int>();
                value = v.at(1).get<int>();
                CHECK(static_cast<int>(mmu.Read(addr)) == value);
            }
        }
        CHECK(static_cast<int>(cyclesTaken) == cycles.size());
    }
}

} // namespace

void test_file(const std::string& test_file_path)
{
    std::ifstream f(test_file_path);
    json j = json::parse(f);

    for (auto& test_case: j)
    {
        if (!test_case_will_pass(test_case))
        {
            run_dynamic_section_test(test_case);
            break;
        }
    }
}
