#include "soc.h"
#include "tester.h"

#include <nlohmann/json.hpp>
#include <catch2/catch_test_macros.hpp>

#include <fstream>

using json = nlohmann::json;

// The `tester` intends to reduce overhead of creating a
// Catch2 Dynamic Section. This is why it runs the test
// first and only if it fails, it creates a Dynamic Section
// and reruns the test. The code is rather repetitive,
// but they serve its simplistic purpose.

namespace {

Soc load_state(const json& initial)
{
    Soc soc;
    soc.m_mmu.ime = initial.value<std::uint8_t>("ime", 0);
    soc.m_mmu.ie = initial.value<std::uint8_t>("ie", 0);
    soc.m_reg.a = initial.value<std::uint8_t>("a", 0);
    soc.m_reg.b = initial.value<std::uint8_t>("b", 0);
    soc.m_reg.c = initial.value<std::uint8_t>("c", 0);
    soc.m_reg.d = initial.value<std::uint8_t>("d", 0);
    soc.m_reg.e = initial.value<std::uint8_t>("e", 0);
    soc.m_reg.f = initial.value<std::uint8_t>("f", 0);
    soc.m_reg.h = initial.value<std::uint8_t>("h", 0);
    soc.m_reg.l = initial.value<std::uint8_t>("l", 0);
    soc.m_reg.pc = initial.value<std::uint16_t>("pc", 0);
    soc.m_reg.sp = initial.value<std::uint16_t>("sp", 0);
    if (initial.contains("ram"))
    {
        int addr = 0;
        int value = 0;
        for (const auto& [_,v]: initial["ram"].items())
        {
            addr = v.at(0).get<int>();
            value = v.at(1).get<int>();
            soc.m_mmu.Write(addr, value);
        }
    }

    return soc;
}

bool check_final_state(const Soc& soc, json final)
{
    bool hasFailures = false;
    hasFailures |= soc.m_mmu.ime != final.value<std::uint8_t>("ime", 0);
    hasFailures |= soc.m_mmu.ei != final.value<std::uint8_t>("ei", 0);
    hasFailures |= soc.m_reg.a != final.value<std::uint8_t>("a", 0);
    hasFailures |= soc.m_reg.b != final.value<std::uint8_t>("b", 0);
    hasFailures |= soc.m_reg.c != final.value<std::uint8_t>("c", 0);
    hasFailures |= soc.m_reg.d != final.value<std::uint8_t>("d", 0);
    hasFailures |= soc.m_reg.e != final.value<std::uint8_t>("e", 0);
    hasFailures |= soc.m_reg.f != final.value<std::uint8_t>("f", 0);
    hasFailures |= soc.m_reg.h != final.value<std::uint8_t>("h", 0);
    hasFailures |= soc.m_reg.l != final.value<std::uint8_t>("l", 0);
    hasFailures |= soc.m_reg.pc != final.value<std::uint16_t>("pc", 0);
    hasFailures |= soc.m_reg.sp != final.value<std::uint16_t>("sp", 0);
    if (final.contains("ram"))
    {
        int addr = 0;
        int value = 0;
        for (const auto& [_,v]: final["ram"].items())
        {
            addr = v.at(0).get<int>();
            value = v.at(1).get<int>();
            hasFailures |= soc.m_mmu.Read(addr) != value;
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
    Soc soc = load_state(initial);
    auto cyclesTaken = soc.Step().cycles;
    if (!skipCyclesCheck && cyclesTaken != cycles.size())
        return false;
    return check_final_state(soc, final);
}

void run_dynamic_section_test(const json& test_case)
{
    const auto name = test_case.value<std::string>("name", "");
    const auto& initial = test_case["initial"];
    const auto& final = test_case["final"];
    const auto& cycles = test_case["cycles"];
    DYNAMIC_SECTION(name)
    {
        Soc soc = load_state(initial);
        auto cyclesTaken = soc.Step().cycles;
        INFO("Initial: " + nlohmann::to_string(initial));
        INFO("Final: " + nlohmann::to_string(final));

        // In the checks, we cast to int rather than uint8/16 to make the output comprehensible
        CHECK(static_cast<int>(soc.m_mmu.ime) == final.value<int>("ime", 0));
        CHECK(static_cast<int>(soc.m_mmu.ei) == final.value<int>("ei", 0));
        CHECK(static_cast<int>(soc.m_reg.a) == final.value<int>("a", 0));
        CHECK(static_cast<int>(soc.m_reg.b) == final.value<int>("b", 0));
        CHECK(static_cast<int>(soc.m_reg.c) == final.value<int>("c", 0));
        CHECK(static_cast<int>(soc.m_reg.d) == final.value<int>("d", 0));
        CHECK(static_cast<int>(soc.m_reg.e) == final.value<int>("e", 0));
        CHECK(static_cast<int>(soc.m_reg.f) == final.value<int>("f", 0));
        CHECK(static_cast<int>(soc.m_reg.h) == final.value<int>("h", 0));
        CHECK(static_cast<int>(soc.m_reg.l) == final.value<int>("l", 0));
        CHECK(static_cast<int>(soc.m_reg.pc) == final.value<int>("pc", 0));
        CHECK(static_cast<int>(soc.m_reg.sp) == final.value<int>("sp", 0));
        if (final.contains("ram"))
        {
            int addr = 0;
            int value = 0;
            for (const auto& [_,v]: final["ram"].items())
            {
                addr = v.at(0).get<int>();
                value = v.at(1).get<int>();
                CHECK(static_cast<int>(soc.m_mmu.Read(addr)) == value);
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
