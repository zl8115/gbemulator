import os
import pathlib
import json
import re
from string import Template

# https://github.com/SingleStepTests/sm83
REPO_PATH = os.getenv("SM83TestsPath")
TEST_DIR = os.path.join(REPO_PATH, "v1")
CPP_HEADER_TEMPLATE = Template("""// Based on https://github.com/SingleStepTests/sm83
// File: $test_file_name
#include <catch2/catch_test_macros.hpp>
#include "cpu.h"
""")

CPP_TEST_TEMPLATE = Template("""
TEST_CASE( "$test_name", "$test_suite" ) {
    // Setup
    Cpu cpu;
    cpu.ime = $ime;
    cpu.reg.a = $a;
    cpu.reg.b = $b;
    cpu.reg.c = $c;
    cpu.reg.d = $d;
    cpu.reg.e = $e;
    cpu.reg.f = $f;
    cpu.reg.h = $h;
    cpu.reg.l = $l;
    cpu.reg.pc = $pc;
    cpu.reg.sp = $sp;
$ram_lines

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.ime == $e_ime);
    CHECK(cpu.reg.a == $e_a);
    CHECK(cpu.reg.b == $e_b);
    CHECK(cpu.reg.c == $e_c);
    CHECK(cpu.reg.d == $e_d);
    CHECK(cpu.reg.e == $e_e);
    CHECK(cpu.reg.f == $e_f);
    CHECK(cpu.reg.h == $e_h);
    CHECK(cpu.reg.l == $e_l);
    CHECK(cpu.reg.pc == $e_pc);
    CHECK(cpu.reg.sp == $e_sp);
$expected_ram_lines
}
""")

test_files = filter(lambda p: re.search(r'^[0-5][0-9a-f].json', str(p.name)), pathlib.Path(TEST_DIR).iterdir())
for test_file in test_files:
    test_json = json.loads(test_file.read_text());
    out_file_name = test_file.stem + ".cpp"
    out_dir = pathlib.Path(__file__).parent.parent / "src" / "test"
    out_file = open(out_dir / out_file_name, "w")
    header_str = CPP_HEADER_TEMPLATE.substitute(test_file_name = test_file.name)
    out_file.write(header_str)

    for test in test_json:
        ram_entries = list()
        for entry in test["initial"].get("ram", []):
            ram_entries.append(f"    cpu.ram[{entry[0]}] = {entry[1]};")
        ram_lines = "\n".join(ram_entries)

        expected_ram_entries = list()
        for entry in test["final"].get("ram", []):
            expected_ram_entries.append(f"    REQUIRE(cpu.ram[{entry[0]}] == {entry[1]});")
        expected_ram_lines = "\n".join(expected_ram_entries)

        out_file.write(CPP_TEST_TEMPLATE.substitute(
            test_name = test["name"],
            test_suite = test_file.stem,

            pc = test["initial"]["pc"],
            sp = test["initial"]["sp"],
            a = test["initial"]["a"],
            b = test["initial"]["b"],
            c = test["initial"]["c"],
            d = test["initial"]["d"],
            e = test["initial"]["e"],
            f = test["initial"]["f"],
            h = test["initial"]["h"],
            l = test["initial"]["l"],
            ime = test["initial"]["ime"],
            ie = test["initial"]["ie"],
            ram_lines = ram_lines,

            e_pc = test["final"]["pc"],
            e_sp = test["final"]["sp"],
            e_a = test["final"]["a"],
            e_b = test["final"]["b"],
            e_c = test["final"]["c"],
            e_d = test["final"]["d"],
            e_e = test["final"]["e"],
            e_f = test["final"]["f"],
            e_h = test["final"]["h"],
            e_l = test["final"]["l"],
            e_ime = test["final"]["ime"],
            expected_ram_lines = expected_ram_lines,
        ))
    out_file.close()
