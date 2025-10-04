import pathlib
import json
import re
import random
import argparse
from typing import Optional
from string import Template

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
    // cpu.ie = $ie;
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
    CHECK(cpu.ei == $e_ei);
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

def generate_tests(test_dir: pathlib.Path, tests_count: Optional[int]) -> None:
    # The test json files should match the pattern like '0f.json' or 'cb 9a.json'
    TEST_FILE_REGEX = re.compile(r'^([0-9a-f]|cb [0-2])[0-9a-f]\.json')

    test_files = filter(lambda p: TEST_FILE_REGEX.search(str(p.name)), pathlib.Path(test_dir).iterdir())
    for test_file in test_files:
        generate_test(test_file, tests_count)

def generate_test(test_file: pathlib.Path, tests_count: Optional[int]) -> None:
    # Load Json File
    test_json = json.loads(test_file.read_text());
    if ((tests_count is not None) and (tests_count > 0)):
        random.seed(83)
        test_json = random.sample(test_json, min(tests_count, len(test_json)))

    # Write output .cpp header
    out_file_name = test_file.stem + ".cpp"
    out_dir = pathlib.Path(__file__).parent.parent / "src" / "sm83" / "test"
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

            e_ei = test["final"].get("ei",0),
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

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        prog='codegen_tests.py',
        description='''
            Script to codegen the SM83 C++ unittests based on test json files from https://github.com/SingleStepTests/sm83.

            Example:
                codegen_tests.py ~/src/sm83/v1/ --test_count 100
        ''')
    parser.add_argument(
        'test_dir',
        help='Directory to the SM83 v1 tests (https://github.com/SingleStepTests/sm83). E.g. `~/src/sm83/v1/`',
        nargs='?',
        const=None,
        type=pathlib.Path)
    parser.add_argument(
        '-c',
        '--test_count',
        help='Number of tests per Test Case (opcode) to add. Each opcode has 1000 test cases which will make compilation slow. So you can reduce this to compile less. If None is specified, all test cases will be generated. Default is None.',
        nargs='?',
        const=None,
        type=int)

    args = parser.parse_args()
    return args

def main() -> None:
    args = parse_args()
    generate_tests(args.test_dir, args.test_count)

if __name__ == "__main__":
    main()
