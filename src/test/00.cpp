// Based on https://github.com/SingleStepTests/sm83
// File: 00.json
#include <catch2/catch_test_macros.hpp>
#include "cpu.h"

TEST_CASE( "00 0000", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19935;
    cpu.reg.sp = 59438;
    cpu.reg.a = 110;
    cpu.reg.b = 185;
    cpu.reg.c = 144;
    cpu.reg.d = 208;
    cpu.reg.e = 190;
    cpu.reg.f = 240;
    cpu.reg.h = 131;
    cpu.reg.l = 147;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19935] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 110);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 144);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 131);
    CHECK(cpu.reg.l == 147);
    CHECK(cpu.reg.pc == 19936);
    // CHECK(cpu.reg.sp == 59438);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19935] == 0);
}

TEST_CASE( "00 0001", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45419;
    cpu.reg.sp = 3350;
    cpu.reg.a = 26;
    cpu.reg.b = 96;
    cpu.reg.c = 116;
    cpu.reg.d = 79;
    cpu.reg.e = 213;
    cpu.reg.f = 0;
    cpu.reg.h = 108;
    cpu.reg.l = 242;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[45419] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 26);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 108);
    CHECK(cpu.reg.l == 242);
    CHECK(cpu.reg.pc == 45420);
    // CHECK(cpu.reg.sp == 3350);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[45419] == 0);
}

TEST_CASE( "00 0002", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26586;
    cpu.reg.sp = 35564;
    cpu.reg.a = 181;
    cpu.reg.b = 149;
    cpu.reg.c = 97;
    cpu.reg.d = 205;
    cpu.reg.e = 6;
    cpu.reg.f = 160;
    cpu.reg.h = 64;
    cpu.reg.l = 166;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26586] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 181);
    CHECK(cpu.reg.b == 149);
    CHECK(cpu.reg.c == 97);
    CHECK(cpu.reg.d == 205);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 64);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 26587);
    // CHECK(cpu.reg.sp == 35564);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26586] == 0);
}

TEST_CASE( "00 0003", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64987;
    cpu.reg.sp = 2168;
    cpu.reg.a = 177;
    cpu.reg.b = 52;
    cpu.reg.c = 4;
    cpu.reg.d = 126;
    cpu.reg.e = 37;
    cpu.reg.f = 224;
    cpu.reg.h = 177;
    cpu.reg.l = 231;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[64987] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 177);
    CHECK(cpu.reg.b == 52);
    CHECK(cpu.reg.c == 4);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 177);
    CHECK(cpu.reg.l == 231);
    CHECK(cpu.reg.pc == 64988);
    // CHECK(cpu.reg.sp == 2168);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64987] == 0);
}

TEST_CASE( "00 0004", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23298;
    cpu.reg.sp = 24490;
    cpu.reg.a = 120;
    cpu.reg.b = 69;
    cpu.reg.c = 14;
    cpu.reg.d = 2;
    cpu.reg.e = 174;
    cpu.reg.f = 144;
    cpu.reg.h = 191;
    cpu.reg.l = 40;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[23298] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 69);
    CHECK(cpu.reg.c == 14);
    CHECK(cpu.reg.d == 2);
    CHECK(cpu.reg.e == 174);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 23299);
    // CHECK(cpu.reg.sp == 24490);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[23298] == 0);
}

TEST_CASE( "00 0005", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33187;
    cpu.reg.sp = 37254;
    cpu.reg.a = 137;
    cpu.reg.b = 166;
    cpu.reg.c = 32;
    cpu.reg.d = 82;
    cpu.reg.e = 10;
    cpu.reg.f = 0;
    cpu.reg.h = 255;
    cpu.reg.l = 223;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[33187] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 137);
    CHECK(cpu.reg.b == 166);
    CHECK(cpu.reg.c == 32);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 10);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 255);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 33188);
    // CHECK(cpu.reg.sp == 37254);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33187] == 0);
}

TEST_CASE( "00 0006", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64482;
    cpu.reg.sp = 5021;
    cpu.reg.a = 245;
    cpu.reg.b = 79;
    cpu.reg.c = 10;
    cpu.reg.d = 183;
    cpu.reg.e = 177;
    cpu.reg.f = 176;
    cpu.reg.h = 192;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[64482] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 245);
    CHECK(cpu.reg.b == 79);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 177);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 192);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 64483);
    // CHECK(cpu.reg.sp == 5021);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64482] == 0);
}

TEST_CASE( "00 0007", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55460;
    cpu.reg.sp = 27520;
    cpu.reg.a = 120;
    cpu.reg.b = 96;
    cpu.reg.c = 72;
    cpu.reg.d = 54;
    cpu.reg.e = 179;
    cpu.reg.f = 80;
    cpu.reg.h = 39;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[55460] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 179);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 39);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 55461);
    // CHECK(cpu.reg.sp == 27520);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[55460] == 0);
}

TEST_CASE( "00 0008", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11082;
    cpu.reg.sp = 13333;
    cpu.reg.a = 205;
    cpu.reg.b = 140;
    cpu.reg.c = 214;
    cpu.reg.d = 177;
    cpu.reg.e = 240;
    cpu.reg.f = 192;
    cpu.reg.h = 43;
    cpu.reg.l = 19;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[11082] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 205);
    CHECK(cpu.reg.b == 140);
    CHECK(cpu.reg.c == 214);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 43);
    CHECK(cpu.reg.l == 19);
    CHECK(cpu.reg.pc == 11083);
    // CHECK(cpu.reg.sp == 13333);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11082] == 0);
}

TEST_CASE( "00 0009", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31662;
    cpu.reg.sp = 40933;
    cpu.reg.a = 131;
    cpu.reg.b = 174;
    cpu.reg.c = 62;
    cpu.reg.d = 41;
    cpu.reg.e = 32;
    cpu.reg.f = 48;
    cpu.reg.h = 139;
    cpu.reg.l = 64;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[31662] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 131);
    CHECK(cpu.reg.b == 174);
    CHECK(cpu.reg.c == 62);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 64);
    CHECK(cpu.reg.pc == 31663);
    // CHECK(cpu.reg.sp == 40933);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31662] == 0);
}

TEST_CASE( "00 000A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23980;
    cpu.reg.sp = 16903;
    cpu.reg.a = 200;
    cpu.reg.b = 137;
    cpu.reg.c = 127;
    cpu.reg.d = 135;
    cpu.reg.e = 80;
    cpu.reg.f = 128;
    cpu.reg.h = 203;
    cpu.reg.l = 249;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[23980] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 200);
    CHECK(cpu.reg.b == 137);
    CHECK(cpu.reg.c == 127);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 80);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 23981);
    // CHECK(cpu.reg.sp == 16903);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[23980] == 0);
}

TEST_CASE( "00 000B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20256;
    cpu.reg.sp = 63358;
    cpu.reg.a = 191;
    cpu.reg.b = 56;
    cpu.reg.c = 173;
    cpu.reg.d = 134;
    cpu.reg.e = 203;
    cpu.reg.f = 32;
    cpu.reg.h = 116;
    cpu.reg.l = 173;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[20256] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 134);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 116);
    CHECK(cpu.reg.l == 173);
    CHECK(cpu.reg.pc == 20257);
    // CHECK(cpu.reg.sp == 63358);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20256] == 0);
}

TEST_CASE( "00 000C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62549;
    cpu.reg.sp = 20920;
    cpu.reg.a = 129;
    cpu.reg.b = 184;
    cpu.reg.c = 223;
    cpu.reg.d = 210;
    cpu.reg.e = 77;
    cpu.reg.f = 64;
    cpu.reg.h = 148;
    cpu.reg.l = 61;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[62549] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 129);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 223);
    CHECK(cpu.reg.d == 210);
    CHECK(cpu.reg.e == 77);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 148);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 62550);
    // CHECK(cpu.reg.sp == 20920);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62549] == 0);
}

TEST_CASE( "00 000D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62697;
    cpu.reg.sp = 59370;
    cpu.reg.a = 103;
    cpu.reg.b = 161;
    cpu.reg.c = 175;
    cpu.reg.d = 25;
    cpu.reg.e = 180;
    cpu.reg.f = 128;
    cpu.reg.h = 85;
    cpu.reg.l = 240;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62697] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 161);
    CHECK(cpu.reg.c == 175);
    CHECK(cpu.reg.d == 25);
    CHECK(cpu.reg.e == 180);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 85);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 62698);
    // CHECK(cpu.reg.sp == 59370);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62697] == 0);
}

TEST_CASE( "00 000E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5393;
    cpu.reg.sp = 64479;
    cpu.reg.a = 182;
    cpu.reg.b = 239;
    cpu.reg.c = 11;
    cpu.reg.d = 233;
    cpu.reg.e = 129;
    cpu.reg.f = 0;
    cpu.reg.h = 186;
    cpu.reg.l = 26;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[5393] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 182);
    CHECK(cpu.reg.b == 239);
    CHECK(cpu.reg.c == 11);
    CHECK(cpu.reg.d == 233);
    CHECK(cpu.reg.e == 129);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 26);
    CHECK(cpu.reg.pc == 5394);
    // CHECK(cpu.reg.sp == 64479);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5393] == 0);
}

TEST_CASE( "00 000F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49176;
    cpu.reg.sp = 47408;
    cpu.reg.a = 237;
    cpu.reg.b = 192;
    cpu.reg.c = 157;
    cpu.reg.d = 124;
    cpu.reg.e = 226;
    cpu.reg.f = 112;
    cpu.reg.h = 141;
    cpu.reg.l = 203;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[49176] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 237);
    CHECK(cpu.reg.b == 192);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 124);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 203);
    CHECK(cpu.reg.pc == 49177);
    // CHECK(cpu.reg.sp == 47408);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[49176] == 0);
}

TEST_CASE( "00 0010", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 770;
    cpu.reg.sp = 10749;
    cpu.reg.a = 70;
    cpu.reg.b = 218;
    cpu.reg.c = 125;
    cpu.reg.d = 24;
    cpu.reg.e = 123;
    cpu.reg.f = 32;
    cpu.reg.h = 124;
    cpu.reg.l = 53;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[770] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 70);
    CHECK(cpu.reg.b == 218);
    CHECK(cpu.reg.c == 125);
    CHECK(cpu.reg.d == 24);
    CHECK(cpu.reg.e == 123);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 124);
    CHECK(cpu.reg.l == 53);
    CHECK(cpu.reg.pc == 771);
    // CHECK(cpu.reg.sp == 10749);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[770] == 0);
}

TEST_CASE( "00 0011", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28794;
    cpu.reg.sp = 35909;
    cpu.reg.a = 244;
    cpu.reg.b = 217;
    cpu.reg.c = 162;
    cpu.reg.d = 178;
    cpu.reg.e = 50;
    cpu.reg.f = 0;
    cpu.reg.h = 21;
    cpu.reg.l = 205;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[28794] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 217);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 21);
    CHECK(cpu.reg.l == 205);
    CHECK(cpu.reg.pc == 28795);
    // CHECK(cpu.reg.sp == 35909);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28794] == 0);
}

TEST_CASE( "00 0012", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40769;
    cpu.reg.sp = 28955;
    cpu.reg.a = 213;
    cpu.reg.b = 207;
    cpu.reg.c = 26;
    cpu.reg.d = 93;
    cpu.reg.e = 147;
    cpu.reg.f = 240;
    cpu.reg.h = 102;
    cpu.reg.l = 172;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[40769] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 213);
    CHECK(cpu.reg.b == 207);
    CHECK(cpu.reg.c == 26);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 147);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 102);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 40770);
    // CHECK(cpu.reg.sp == 28955);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40769] == 0);
}

TEST_CASE( "00 0013", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35949;
    cpu.reg.sp = 23293;
    cpu.reg.a = 110;
    cpu.reg.b = 202;
    cpu.reg.c = 94;
    cpu.reg.d = 27;
    cpu.reg.e = 254;
    cpu.reg.f = 96;
    cpu.reg.h = 197;
    cpu.reg.l = 241;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[35949] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 110);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 94);
    CHECK(cpu.reg.d == 27);
    CHECK(cpu.reg.e == 254);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 197);
    CHECK(cpu.reg.l == 241);
    CHECK(cpu.reg.pc == 35950);
    // CHECK(cpu.reg.sp == 23293);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[35949] == 0);
}

TEST_CASE( "00 0014", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8625;
    cpu.reg.sp = 17724;
    cpu.reg.a = 156;
    cpu.reg.b = 211;
    cpu.reg.c = 171;
    cpu.reg.d = 52;
    cpu.reg.e = 191;
    cpu.reg.f = 224;
    cpu.reg.h = 52;
    cpu.reg.l = 154;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[8625] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 156);
    CHECK(cpu.reg.b == 211);
    CHECK(cpu.reg.c == 171);
    CHECK(cpu.reg.d == 52);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 52);
    CHECK(cpu.reg.l == 154);
    CHECK(cpu.reg.pc == 8626);
    // CHECK(cpu.reg.sp == 17724);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8625] == 0);
}

TEST_CASE( "00 0015", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8664;
    cpu.reg.sp = 11359;
    cpu.reg.a = 140;
    cpu.reg.b = 31;
    cpu.reg.c = 232;
    cpu.reg.d = 104;
    cpu.reg.e = 85;
    cpu.reg.f = 0;
    cpu.reg.h = 49;
    cpu.reg.l = 102;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[8664] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 49);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 8665);
    // CHECK(cpu.reg.sp == 11359);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8664] == 0);
}

TEST_CASE( "00 0016", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55546;
    cpu.reg.sp = 62671;
    cpu.reg.a = 166;
    cpu.reg.b = 45;
    cpu.reg.c = 148;
    cpu.reg.d = 89;
    cpu.reg.e = 152;
    cpu.reg.f = 192;
    cpu.reg.h = 233;
    cpu.reg.l = 212;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[55546] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 166);
    CHECK(cpu.reg.b == 45);
    CHECK(cpu.reg.c == 148);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 152);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 233);
    CHECK(cpu.reg.l == 212);
    CHECK(cpu.reg.pc == 55547);
    // CHECK(cpu.reg.sp == 62671);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[55546] == 0);
}

TEST_CASE( "00 0017", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39138;
    cpu.reg.sp = 12575;
    cpu.reg.a = 48;
    cpu.reg.b = 106;
    cpu.reg.c = 20;
    cpu.reg.d = 136;
    cpu.reg.e = 171;
    cpu.reg.f = 208;
    cpu.reg.h = 60;
    cpu.reg.l = 137;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39138] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 20);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 137);
    CHECK(cpu.reg.pc == 39139);
    // CHECK(cpu.reg.sp == 12575);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39138] == 0);
}

TEST_CASE( "00 0018", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37766;
    cpu.reg.sp = 61260;
    cpu.reg.a = 1;
    cpu.reg.b = 154;
    cpu.reg.c = 107;
    cpu.reg.d = 40;
    cpu.reg.e = 34;
    cpu.reg.f = 224;
    cpu.reg.h = 98;
    cpu.reg.l = 17;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[37766] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 1);
    CHECK(cpu.reg.b == 154);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 40);
    CHECK(cpu.reg.e == 34);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 98);
    CHECK(cpu.reg.l == 17);
    CHECK(cpu.reg.pc == 37767);
    // CHECK(cpu.reg.sp == 61260);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37766] == 0);
}

TEST_CASE( "00 0019", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6571;
    cpu.reg.sp = 6106;
    cpu.reg.a = 159;
    cpu.reg.b = 124;
    cpu.reg.c = 166;
    cpu.reg.d = 212;
    cpu.reg.e = 208;
    cpu.reg.f = 80;
    cpu.reg.h = 164;
    cpu.reg.l = 182;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6571] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 159);
    CHECK(cpu.reg.b == 124);
    CHECK(cpu.reg.c == 166);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 208);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 6572);
    // CHECK(cpu.reg.sp == 6106);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6571] == 0);
}

TEST_CASE( "00 001A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28485;
    cpu.reg.sp = 32432;
    cpu.reg.a = 254;
    cpu.reg.b = 225;
    cpu.reg.c = 47;
    cpu.reg.d = 197;
    cpu.reg.e = 236;
    cpu.reg.f = 0;
    cpu.reg.h = 128;
    cpu.reg.l = 146;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[28485] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 254);
    CHECK(cpu.reg.b == 225);
    CHECK(cpu.reg.c == 47);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 128);
    CHECK(cpu.reg.l == 146);
    CHECK(cpu.reg.pc == 28486);
    // CHECK(cpu.reg.sp == 32432);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28485] == 0);
}

TEST_CASE( "00 001B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56137;
    cpu.reg.sp = 8508;
    cpu.reg.a = 244;
    cpu.reg.b = 71;
    cpu.reg.c = 71;
    cpu.reg.d = 141;
    cpu.reg.e = 98;
    cpu.reg.f = 144;
    cpu.reg.h = 106;
    cpu.reg.l = 114;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56137] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 71);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 141);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 114);
    CHECK(cpu.reg.pc == 56138);
    // CHECK(cpu.reg.sp == 8508);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56137] == 0);
}

TEST_CASE( "00 001C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43455;
    cpu.reg.sp = 50291;
    cpu.reg.a = 14;
    cpu.reg.b = 68;
    cpu.reg.c = 44;
    cpu.reg.d = 67;
    cpu.reg.e = 247;
    cpu.reg.f = 128;
    cpu.reg.h = 22;
    cpu.reg.l = 2;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[43455] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 68);
    CHECK(cpu.reg.c == 44);
    CHECK(cpu.reg.d == 67);
    CHECK(cpu.reg.e == 247);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 22);
    CHECK(cpu.reg.l == 2);
    CHECK(cpu.reg.pc == 43456);
    // CHECK(cpu.reg.sp == 50291);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43455] == 0);
}

TEST_CASE( "00 001D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41456;
    cpu.reg.sp = 23805;
    cpu.reg.a = 215;
    cpu.reg.b = 35;
    cpu.reg.c = 207;
    cpu.reg.d = 163;
    cpu.reg.e = 232;
    cpu.reg.f = 192;
    cpu.reg.h = 8;
    cpu.reg.l = 60;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[41456] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 35);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 163);
    CHECK(cpu.reg.e == 232);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 8);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 41457);
    // CHECK(cpu.reg.sp == 23805);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[41456] == 0);
}

TEST_CASE( "00 001E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 459;
    cpu.reg.sp = 17893;
    cpu.reg.a = 174;
    cpu.reg.b = 58;
    cpu.reg.c = 116;
    cpu.reg.d = 230;
    cpu.reg.e = 13;
    cpu.reg.f = 112;
    cpu.reg.h = 135;
    cpu.reg.l = 196;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[459] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 174);
    CHECK(cpu.reg.b == 58);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 13);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 135);
    CHECK(cpu.reg.l == 196);
    CHECK(cpu.reg.pc == 460);
    // CHECK(cpu.reg.sp == 17893);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[459] == 0);
}

TEST_CASE( "00 001F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 957;
    cpu.reg.sp = 29102;
    cpu.reg.a = 238;
    cpu.reg.b = 24;
    cpu.reg.c = 200;
    cpu.reg.d = 53;
    cpu.reg.e = 140;
    cpu.reg.f = 80;
    cpu.reg.h = 162;
    cpu.reg.l = 61;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[957] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 24);
    CHECK(cpu.reg.c == 200);
    CHECK(cpu.reg.d == 53);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 958);
    // CHECK(cpu.reg.sp == 29102);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[957] == 0);
}

TEST_CASE( "00 0020", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8862;
    cpu.reg.sp = 43034;
    cpu.reg.a = 157;
    cpu.reg.b = 152;
    cpu.reg.c = 216;
    cpu.reg.d = 251;
    cpu.reg.e = 63;
    cpu.reg.f = 112;
    cpu.reg.h = 245;
    cpu.reg.l = 7;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[8862] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 157);
    CHECK(cpu.reg.b == 152);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 7);
    CHECK(cpu.reg.pc == 8863);
    // CHECK(cpu.reg.sp == 43034);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8862] == 0);
}

TEST_CASE( "00 0021", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60259;
    cpu.reg.sp = 6438;
    cpu.reg.a = 119;
    cpu.reg.b = 146;
    cpu.reg.c = 246;
    cpu.reg.d = 116;
    cpu.reg.e = 170;
    cpu.reg.f = 240;
    cpu.reg.h = 255;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[60259] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 119);
    CHECK(cpu.reg.b == 146);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 116);
    CHECK(cpu.reg.e == 170);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 255);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 60260);
    // CHECK(cpu.reg.sp == 6438);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60259] == 0);
}

TEST_CASE( "00 0022", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61058;
    cpu.reg.sp = 29057;
    cpu.reg.a = 191;
    cpu.reg.b = 13;
    cpu.reg.c = 76;
    cpu.reg.d = 42;
    cpu.reg.e = 76;
    cpu.reg.f = 112;
    cpu.reg.h = 154;
    cpu.reg.l = 232;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[61058] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 13);
    CHECK(cpu.reg.c == 76);
    CHECK(cpu.reg.d == 42);
    CHECK(cpu.reg.e == 76);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 232);
    CHECK(cpu.reg.pc == 61059);
    // CHECK(cpu.reg.sp == 29057);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61058] == 0);
}

TEST_CASE( "00 0023", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54988;
    cpu.reg.sp = 6210;
    cpu.reg.a = 105;
    cpu.reg.b = 155;
    cpu.reg.c = 16;
    cpu.reg.d = 192;
    cpu.reg.e = 190;
    cpu.reg.f = 0;
    cpu.reg.h = 67;
    cpu.reg.l = 236;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[54988] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 105);
    CHECK(cpu.reg.b == 155);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 192);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 236);
    CHECK(cpu.reg.pc == 54989);
    // CHECK(cpu.reg.sp == 6210);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54988] == 0);
}

TEST_CASE( "00 0024", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26233;
    cpu.reg.sp = 43533;
    cpu.reg.a = 208;
    cpu.reg.b = 53;
    cpu.reg.c = 34;
    cpu.reg.d = 138;
    cpu.reg.e = 43;
    cpu.reg.f = 144;
    cpu.reg.h = 88;
    cpu.reg.l = 76;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26233] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 53);
    CHECK(cpu.reg.c == 34);
    CHECK(cpu.reg.d == 138);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 88);
    CHECK(cpu.reg.l == 76);
    CHECK(cpu.reg.pc == 26234);
    // CHECK(cpu.reg.sp == 43533);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26233] == 0);
}

TEST_CASE( "00 0025", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64445;
    cpu.reg.sp = 36225;
    cpu.reg.a = 24;
    cpu.reg.b = 50;
    cpu.reg.c = 168;
    cpu.reg.d = 46;
    cpu.reg.e = 221;
    cpu.reg.f = 0;
    cpu.reg.h = 165;
    cpu.reg.l = 29;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64445] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 24);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 168);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 221);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 165);
    CHECK(cpu.reg.l == 29);
    CHECK(cpu.reg.pc == 64446);
    // CHECK(cpu.reg.sp == 36225);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64445] == 0);
}

TEST_CASE( "00 0026", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61082;
    cpu.reg.sp = 54382;
    cpu.reg.a = 8;
    cpu.reg.b = 21;
    cpu.reg.c = 192;
    cpu.reg.d = 215;
    cpu.reg.e = 65;
    cpu.reg.f = 224;
    cpu.reg.h = 75;
    cpu.reg.l = 182;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61082] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 21);
    CHECK(cpu.reg.c == 192);
    CHECK(cpu.reg.d == 215);
    CHECK(cpu.reg.e == 65);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 61083);
    // CHECK(cpu.reg.sp == 54382);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61082] == 0);
}

TEST_CASE( "00 0027", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46017;
    cpu.reg.sp = 17079;
    cpu.reg.a = 80;
    cpu.reg.b = 48;
    cpu.reg.c = 222;
    cpu.reg.d = 193;
    cpu.reg.e = 183;
    cpu.reg.f = 80;
    cpu.reg.h = 189;
    cpu.reg.l = 105;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[46017] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 80);
    CHECK(cpu.reg.b == 48);
    CHECK(cpu.reg.c == 222);
    CHECK(cpu.reg.d == 193);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 189);
    CHECK(cpu.reg.l == 105);
    CHECK(cpu.reg.pc == 46018);
    // CHECK(cpu.reg.sp == 17079);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46017] == 0);
}

TEST_CASE( "00 0028", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39127;
    cpu.reg.sp = 37447;
    cpu.reg.a = 163;
    cpu.reg.b = 240;
    cpu.reg.c = 161;
    cpu.reg.d = 10;
    cpu.reg.e = 172;
    cpu.reg.f = 0;
    cpu.reg.h = 80;
    cpu.reg.l = 104;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[39127] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 163);
    CHECK(cpu.reg.b == 240);
    CHECK(cpu.reg.c == 161);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 172);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 104);
    CHECK(cpu.reg.pc == 39128);
    // CHECK(cpu.reg.sp == 37447);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39127] == 0);
}

TEST_CASE( "00 0029", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63493;
    cpu.reg.sp = 527;
    cpu.reg.a = 4;
    cpu.reg.b = 31;
    cpu.reg.c = 199;
    cpu.reg.d = 87;
    cpu.reg.e = 188;
    cpu.reg.f = 112;
    cpu.reg.h = 253;
    cpu.reg.l = 131;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63493] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 4);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 199);
    CHECK(cpu.reg.d == 87);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 253);
    CHECK(cpu.reg.l == 131);
    CHECK(cpu.reg.pc == 63494);
    // CHECK(cpu.reg.sp == 527);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63493] == 0);
}

TEST_CASE( "00 002A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27531;
    cpu.reg.sp = 50085;
    cpu.reg.a = 197;
    cpu.reg.b = 197;
    cpu.reg.c = 160;
    cpu.reg.d = 156;
    cpu.reg.e = 103;
    cpu.reg.f = 176;
    cpu.reg.h = 26;
    cpu.reg.l = 58;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[27531] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 160);
    CHECK(cpu.reg.d == 156);
    CHECK(cpu.reg.e == 103);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 58);
    CHECK(cpu.reg.pc == 27532);
    // CHECK(cpu.reg.sp == 50085);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27531] == 0);
}

TEST_CASE( "00 002B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44306;
    cpu.reg.sp = 4828;
    cpu.reg.a = 126;
    cpu.reg.b = 16;
    cpu.reg.c = 225;
    cpu.reg.d = 50;
    cpu.reg.e = 68;
    cpu.reg.f = 144;
    cpu.reg.h = 151;
    cpu.reg.l = 57;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44306] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 126);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 225);
    CHECK(cpu.reg.d == 50);
    CHECK(cpu.reg.e == 68);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 151);
    CHECK(cpu.reg.l == 57);
    CHECK(cpu.reg.pc == 44307);
    // CHECK(cpu.reg.sp == 4828);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44306] == 0);
}

TEST_CASE( "00 002C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50204;
    cpu.reg.sp = 2587;
    cpu.reg.a = 62;
    cpu.reg.b = 4;
    cpu.reg.c = 77;
    cpu.reg.d = 64;
    cpu.reg.e = 191;
    cpu.reg.f = 48;
    cpu.reg.h = 177;
    cpu.reg.l = 99;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[50204] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 77);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 177);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 50205);
    // CHECK(cpu.reg.sp == 2587);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50204] == 0);
}

TEST_CASE( "00 002D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11747;
    cpu.reg.sp = 1995;
    cpu.reg.a = 99;
    cpu.reg.b = 199;
    cpu.reg.c = 35;
    cpu.reg.d = 232;
    cpu.reg.e = 18;
    cpu.reg.f = 192;
    cpu.reg.h = 2;
    cpu.reg.l = 214;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[11747] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 199);
    CHECK(cpu.reg.c == 35);
    CHECK(cpu.reg.d == 232);
    CHECK(cpu.reg.e == 18);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 2);
    CHECK(cpu.reg.l == 214);
    CHECK(cpu.reg.pc == 11748);
    // CHECK(cpu.reg.sp == 1995);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11747] == 0);
}

TEST_CASE( "00 002E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23335;
    cpu.reg.sp = 30171;
    cpu.reg.a = 49;
    cpu.reg.b = 242;
    cpu.reg.c = 136;
    cpu.reg.d = 161;
    cpu.reg.e = 158;
    cpu.reg.f = 160;
    cpu.reg.h = 141;
    cpu.reg.l = 211;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[23335] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 49);
    CHECK(cpu.reg.b == 242);
    CHECK(cpu.reg.c == 136);
    CHECK(cpu.reg.d == 161);
    CHECK(cpu.reg.e == 158);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 211);
    CHECK(cpu.reg.pc == 23336);
    // CHECK(cpu.reg.sp == 30171);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[23335] == 0);
}

TEST_CASE( "00 002F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44375;
    cpu.reg.sp = 35847;
    cpu.reg.a = 25;
    cpu.reg.b = 183;
    cpu.reg.c = 41;
    cpu.reg.d = 33;
    cpu.reg.e = 48;
    cpu.reg.f = 32;
    cpu.reg.h = 217;
    cpu.reg.l = 48;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44375] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 217);
    CHECK(cpu.reg.l == 48);
    CHECK(cpu.reg.pc == 44376);
    // CHECK(cpu.reg.sp == 35847);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44375] == 0);
}

TEST_CASE( "00 0030", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19570;
    cpu.reg.sp = 61341;
    cpu.reg.a = 252;
    cpu.reg.b = 54;
    cpu.reg.c = 249;
    cpu.reg.d = 175;
    cpu.reg.e = 195;
    cpu.reg.f = 112;
    cpu.reg.h = 218;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[19570] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 252);
    CHECK(cpu.reg.b == 54);
    CHECK(cpu.reg.c == 249);
    CHECK(cpu.reg.d == 175);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 19571);
    // CHECK(cpu.reg.sp == 61341);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19570] == 0);
}

TEST_CASE( "00 0031", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58674;
    cpu.reg.sp = 46978;
    cpu.reg.a = 29;
    cpu.reg.b = 190;
    cpu.reg.c = 5;
    cpu.reg.d = 75;
    cpu.reg.e = 140;
    cpu.reg.f = 112;
    cpu.reg.h = 225;
    cpu.reg.l = 169;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[58674] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 75);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 58675);
    // CHECK(cpu.reg.sp == 46978);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58674] == 0);
}

TEST_CASE( "00 0032", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26652;
    cpu.reg.sp = 29514;
    cpu.reg.a = 140;
    cpu.reg.b = 214;
    cpu.reg.c = 196;
    cpu.reg.d = 250;
    cpu.reg.e = 222;
    cpu.reg.f = 112;
    cpu.reg.h = 3;
    cpu.reg.l = 88;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26652] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 214);
    CHECK(cpu.reg.c == 196);
    CHECK(cpu.reg.d == 250);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 3);
    CHECK(cpu.reg.l == 88);
    CHECK(cpu.reg.pc == 26653);
    // CHECK(cpu.reg.sp == 29514);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26652] == 0);
}

TEST_CASE( "00 0033", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53392;
    cpu.reg.sp = 8206;
    cpu.reg.a = 34;
    cpu.reg.b = 11;
    cpu.reg.c = 238;
    cpu.reg.d = 47;
    cpu.reg.e = 100;
    cpu.reg.f = 0;
    cpu.reg.h = 54;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[53392] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 34);
    CHECK(cpu.reg.b == 11);
    CHECK(cpu.reg.c == 238);
    CHECK(cpu.reg.d == 47);
    CHECK(cpu.reg.e == 100);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 54);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 53393);
    // CHECK(cpu.reg.sp == 8206);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53392] == 0);
}

TEST_CASE( "00 0034", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48118;
    cpu.reg.sp = 5021;
    cpu.reg.a = 67;
    cpu.reg.b = 38;
    cpu.reg.c = 35;
    cpu.reg.d = 168;
    cpu.reg.e = 146;
    cpu.reg.f = 208;
    cpu.reg.h = 24;
    cpu.reg.l = 151;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48118] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 67);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 35);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 146);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 151);
    CHECK(cpu.reg.pc == 48119);
    // CHECK(cpu.reg.sp == 5021);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48118] == 0);
}

TEST_CASE( "00 0035", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34166;
    cpu.reg.sp = 46683;
    cpu.reg.a = 18;
    cpu.reg.b = 38;
    cpu.reg.c = 190;
    cpu.reg.d = 137;
    cpu.reg.e = 210;
    cpu.reg.f = 144;
    cpu.reg.h = 180;
    cpu.reg.l = 160;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[34166] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 137);
    CHECK(cpu.reg.e == 210);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 34167);
    // CHECK(cpu.reg.sp == 46683);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34166] == 0);
}

TEST_CASE( "00 0036", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13523;
    cpu.reg.sp = 16787;
    cpu.reg.a = 128;
    cpu.reg.b = 249;
    cpu.reg.c = 107;
    cpu.reg.d = 151;
    cpu.reg.e = 168;
    cpu.reg.f = 144;
    cpu.reg.h = 60;
    cpu.reg.l = 218;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[13523] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 249);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 151);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 218);
    CHECK(cpu.reg.pc == 13524);
    // CHECK(cpu.reg.sp == 16787);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13523] == 0);
}

TEST_CASE( "00 0037", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31190;
    cpu.reg.sp = 41069;
    cpu.reg.a = 120;
    cpu.reg.b = 153;
    cpu.reg.c = 9;
    cpu.reg.d = 56;
    cpu.reg.e = 200;
    cpu.reg.f = 224;
    cpu.reg.h = 99;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[31190] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 153);
    CHECK(cpu.reg.c == 9);
    CHECK(cpu.reg.d == 56);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 31191);
    // CHECK(cpu.reg.sp == 41069);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31190] == 0);
}

TEST_CASE( "00 0038", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20319;
    cpu.reg.sp = 42069;
    cpu.reg.a = 191;
    cpu.reg.b = 10;
    cpu.reg.c = 235;
    cpu.reg.d = 65;
    cpu.reg.e = 16;
    cpu.reg.f = 48;
    cpu.reg.h = 113;
    cpu.reg.l = 215;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[20319] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 10);
    CHECK(cpu.reg.c == 235);
    CHECK(cpu.reg.d == 65);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 113);
    CHECK(cpu.reg.l == 215);
    CHECK(cpu.reg.pc == 20320);
    // CHECK(cpu.reg.sp == 42069);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20319] == 0);
}

TEST_CASE( "00 0039", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61716;
    cpu.reg.sp = 924;
    cpu.reg.a = 139;
    cpu.reg.b = 0;
    cpu.reg.c = 230;
    cpu.reg.d = 49;
    cpu.reg.e = 158;
    cpu.reg.f = 176;
    cpu.reg.h = 242;
    cpu.reg.l = 65;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61716] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 0);
    CHECK(cpu.reg.c == 230);
    CHECK(cpu.reg.d == 49);
    CHECK(cpu.reg.e == 158);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 65);
    CHECK(cpu.reg.pc == 61717);
    // CHECK(cpu.reg.sp == 924);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61716] == 0);
}

TEST_CASE( "00 003A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36563;
    cpu.reg.sp = 21294;
    cpu.reg.a = 0;
    cpu.reg.b = 110;
    cpu.reg.c = 251;
    cpu.reg.d = 38;
    cpu.reg.e = 72;
    cpu.reg.f = 240;
    cpu.reg.h = 218;
    cpu.reg.l = 184;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[36563] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 0);
    CHECK(cpu.reg.b == 110);
    CHECK(cpu.reg.c == 251);
    CHECK(cpu.reg.d == 38);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 184);
    CHECK(cpu.reg.pc == 36564);
    // CHECK(cpu.reg.sp == 21294);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36563] == 0);
}

TEST_CASE( "00 003B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43653;
    cpu.reg.sp = 7533;
    cpu.reg.a = 184;
    cpu.reg.b = 203;
    cpu.reg.c = 243;
    cpu.reg.d = 45;
    cpu.reg.e = 67;
    cpu.reg.f = 240;
    cpu.reg.h = 156;
    cpu.reg.l = 62;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43653] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 203);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 45);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 43654);
    // CHECK(cpu.reg.sp == 7533);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43653] == 0);
}

TEST_CASE( "00 003C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27641;
    cpu.reg.sp = 57202;
    cpu.reg.a = 78;
    cpu.reg.b = 198;
    cpu.reg.c = 137;
    cpu.reg.d = 58;
    cpu.reg.e = 237;
    cpu.reg.f = 144;
    cpu.reg.h = 200;
    cpu.reg.l = 15;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[27641] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 198);
    CHECK(cpu.reg.c == 137);
    CHECK(cpu.reg.d == 58);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 200);
    CHECK(cpu.reg.l == 15);
    CHECK(cpu.reg.pc == 27642);
    // CHECK(cpu.reg.sp == 57202);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[27641] == 0);
}

TEST_CASE( "00 003D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2148;
    cpu.reg.sp = 44544;
    cpu.reg.a = 25;
    cpu.reg.b = 185;
    cpu.reg.c = 150;
    cpu.reg.d = 118;
    cpu.reg.e = 18;
    cpu.reg.f = 0;
    cpu.reg.h = 69;
    cpu.reg.l = 4;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[2148] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 118);
    CHECK(cpu.reg.e == 18);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 4);
    CHECK(cpu.reg.pc == 2149);
    // CHECK(cpu.reg.sp == 44544);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[2148] == 0);
}

TEST_CASE( "00 003E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26852;
    cpu.reg.sp = 10923;
    cpu.reg.a = 250;
    cpu.reg.b = 144;
    cpu.reg.c = 219;
    cpu.reg.d = 196;
    cpu.reg.e = 134;
    cpu.reg.f = 224;
    cpu.reg.h = 214;
    cpu.reg.l = 54;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26852] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 250);
    CHECK(cpu.reg.b == 144);
    CHECK(cpu.reg.c == 219);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 134);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 214);
    CHECK(cpu.reg.l == 54);
    CHECK(cpu.reg.pc == 26853);
    // CHECK(cpu.reg.sp == 10923);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26852] == 0);
}

TEST_CASE( "00 003F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14239;
    cpu.reg.sp = 44087;
    cpu.reg.a = 99;
    cpu.reg.b = 30;
    cpu.reg.c = 88;
    cpu.reg.d = 95;
    cpu.reg.e = 106;
    cpu.reg.f = 80;
    cpu.reg.h = 49;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[14239] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 30);
    CHECK(cpu.reg.c == 88);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 106);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 49);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 14240);
    // CHECK(cpu.reg.sp == 44087);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14239] == 0);
}

TEST_CASE( "00 0040", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20942;
    cpu.reg.sp = 4392;
    cpu.reg.a = 81;
    cpu.reg.b = 19;
    cpu.reg.c = 35;
    cpu.reg.d = 190;
    cpu.reg.e = 62;
    cpu.reg.f = 160;
    cpu.reg.h = 252;
    cpu.reg.l = 243;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[20942] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 19);
    CHECK(cpu.reg.c == 35);
    CHECK(cpu.reg.d == 190);
    CHECK(cpu.reg.e == 62);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 243);
    CHECK(cpu.reg.pc == 20943);
    // CHECK(cpu.reg.sp == 4392);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20942] == 0);
}

TEST_CASE( "00 0041", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28317;
    cpu.reg.sp = 34403;
    cpu.reg.a = 125;
    cpu.reg.b = 124;
    cpu.reg.c = 2;
    cpu.reg.d = 224;
    cpu.reg.e = 253;
    cpu.reg.f = 0;
    cpu.reg.h = 251;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28317] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 125);
    CHECK(cpu.reg.b == 124);
    CHECK(cpu.reg.c == 2);
    CHECK(cpu.reg.d == 224);
    CHECK(cpu.reg.e == 253);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 251);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 28318);
    // CHECK(cpu.reg.sp == 34403);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28317] == 0);
}

TEST_CASE( "00 0042", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50923;
    cpu.reg.sp = 42663;
    cpu.reg.a = 143;
    cpu.reg.b = 68;
    cpu.reg.c = 69;
    cpu.reg.d = 200;
    cpu.reg.e = 159;
    cpu.reg.f = 80;
    cpu.reg.h = 162;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[50923] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 68);
    CHECK(cpu.reg.c == 69);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 50924);
    // CHECK(cpu.reg.sp == 42663);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[50923] == 0);
}

TEST_CASE( "00 0043", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65098;
    cpu.reg.sp = 29182;
    cpu.reg.a = 212;
    cpu.reg.b = 137;
    cpu.reg.c = 123;
    cpu.reg.d = 96;
    cpu.reg.e = 218;
    cpu.reg.f = 48;
    cpu.reg.h = 2;
    cpu.reg.l = 109;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[65098] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 137);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 96);
    CHECK(cpu.reg.e == 218);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 2);
    CHECK(cpu.reg.l == 109);
    CHECK(cpu.reg.pc == 65099);
    // CHECK(cpu.reg.sp == 29182);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[65098] == 0);
}

TEST_CASE( "00 0044", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8650;
    cpu.reg.sp = 30491;
    cpu.reg.a = 207;
    cpu.reg.b = 128;
    cpu.reg.c = 66;
    cpu.reg.d = 39;
    cpu.reg.e = 2;
    cpu.reg.f = 64;
    cpu.reg.h = 176;
    cpu.reg.l = 36;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[8650] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 207);
    CHECK(cpu.reg.b == 128);
    CHECK(cpu.reg.c == 66);
    CHECK(cpu.reg.d == 39);
    CHECK(cpu.reg.e == 2);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 176);
    CHECK(cpu.reg.l == 36);
    CHECK(cpu.reg.pc == 8651);
    // CHECK(cpu.reg.sp == 30491);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8650] == 0);
}

TEST_CASE( "00 0045", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57880;
    cpu.reg.sp = 13695;
    cpu.reg.a = 238;
    cpu.reg.b = 96;
    cpu.reg.c = 41;
    cpu.reg.d = 36;
    cpu.reg.e = 106;
    cpu.reg.f = 144;
    cpu.reg.h = 237;
    cpu.reg.l = 238;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[57880] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 36);
    CHECK(cpu.reg.e == 106);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 237);
    CHECK(cpu.reg.l == 238);
    CHECK(cpu.reg.pc == 57881);
    // CHECK(cpu.reg.sp == 13695);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57880] == 0);
}

TEST_CASE( "00 0046", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20778;
    cpu.reg.sp = 64051;
    cpu.reg.a = 248;
    cpu.reg.b = 98;
    cpu.reg.c = 190;
    cpu.reg.d = 8;
    cpu.reg.e = 121;
    cpu.reg.f = 112;
    cpu.reg.h = 185;
    cpu.reg.l = 246;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[20778] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 248);
    CHECK(cpu.reg.b == 98);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 8);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 185);
    CHECK(cpu.reg.l == 246);
    CHECK(cpu.reg.pc == 20779);
    // CHECK(cpu.reg.sp == 64051);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20778] == 0);
}

TEST_CASE( "00 0047", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58380;
    cpu.reg.sp = 50773;
    cpu.reg.a = 167;
    cpu.reg.b = 8;
    cpu.reg.c = 66;
    cpu.reg.d = 225;
    cpu.reg.e = 26;
    cpu.reg.f = 80;
    cpu.reg.h = 182;
    cpu.reg.l = 225;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[58380] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 167);
    CHECK(cpu.reg.b == 8);
    CHECK(cpu.reg.c == 66);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 26);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 225);
    CHECK(cpu.reg.pc == 58381);
    // CHECK(cpu.reg.sp == 50773);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58380] == 0);
}

TEST_CASE( "00 0048", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15533;
    cpu.reg.sp = 33117;
    cpu.reg.a = 67;
    cpu.reg.b = 60;
    cpu.reg.c = 237;
    cpu.reg.d = 121;
    cpu.reg.e = 105;
    cpu.reg.f = 96;
    cpu.reg.h = 96;
    cpu.reg.l = 0;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15533] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 67);
    CHECK(cpu.reg.b == 60);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 121);
    CHECK(cpu.reg.e == 105);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 96);
    CHECK(cpu.reg.l == 0);
    CHECK(cpu.reg.pc == 15534);
    // CHECK(cpu.reg.sp == 33117);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15533] == 0);
}

TEST_CASE( "00 0049", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63320;
    cpu.reg.sp = 45053;
    cpu.reg.a = 44;
    cpu.reg.b = 22;
    cpu.reg.c = 215;
    cpu.reg.d = 24;
    cpu.reg.e = 128;
    cpu.reg.f = 64;
    cpu.reg.h = 234;
    cpu.reg.l = 111;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63320] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 44);
    CHECK(cpu.reg.b == 22);
    CHECK(cpu.reg.c == 215);
    CHECK(cpu.reg.d == 24);
    CHECK(cpu.reg.e == 128);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 234);
    CHECK(cpu.reg.l == 111);
    CHECK(cpu.reg.pc == 63321);
    // CHECK(cpu.reg.sp == 45053);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63320] == 0);
}

TEST_CASE( "00 004A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45077;
    cpu.reg.sp = 46846;
    cpu.reg.a = 143;
    cpu.reg.b = 208;
    cpu.reg.c = 244;
    cpu.reg.d = 121;
    cpu.reg.e = 16;
    cpu.reg.f = 32;
    cpu.reg.h = 75;
    cpu.reg.l = 181;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[45077] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 244);
    CHECK(cpu.reg.d == 121);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 181);
    CHECK(cpu.reg.pc == 45078);
    // CHECK(cpu.reg.sp == 46846);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[45077] == 0);
}

TEST_CASE( "00 004B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21954;
    cpu.reg.sp = 15503;
    cpu.reg.a = 65;
    cpu.reg.b = 238;
    cpu.reg.c = 157;
    cpu.reg.d = 174;
    cpu.reg.e = 5;
    cpu.reg.f = 80;
    cpu.reg.h = 38;
    cpu.reg.l = 166;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21954] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 65);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 174);
    CHECK(cpu.reg.e == 5);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 21955);
    // CHECK(cpu.reg.sp == 15503);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21954] == 0);
}

TEST_CASE( "00 004C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29238;
    cpu.reg.sp = 27872;
    cpu.reg.a = 80;
    cpu.reg.b = 215;
    cpu.reg.c = 155;
    cpu.reg.d = 37;
    cpu.reg.e = 137;
    cpu.reg.f = 224;
    cpu.reg.h = 252;
    cpu.reg.l = 25;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[29238] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 80);
    CHECK(cpu.reg.b == 215);
    CHECK(cpu.reg.c == 155);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 137);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 25);
    CHECK(cpu.reg.pc == 29239);
    // CHECK(cpu.reg.sp == 27872);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29238] == 0);
}

TEST_CASE( "00 004D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38237;
    cpu.reg.sp = 18015;
    cpu.reg.a = 232;
    cpu.reg.b = 94;
    cpu.reg.c = 13;
    cpu.reg.d = 140;
    cpu.reg.e = 102;
    cpu.reg.f = 240;
    cpu.reg.h = 70;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[38237] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 232);
    CHECK(cpu.reg.b == 94);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 140);
    CHECK(cpu.reg.e == 102);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 70);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 38238);
    // CHECK(cpu.reg.sp == 18015);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38237] == 0);
}

TEST_CASE( "00 004E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53792;
    cpu.reg.sp = 11354;
    cpu.reg.a = 37;
    cpu.reg.b = 200;
    cpu.reg.c = 169;
    cpu.reg.d = 177;
    cpu.reg.e = 226;
    cpu.reg.f = 112;
    cpu.reg.h = 8;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53792] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 37);
    CHECK(cpu.reg.b == 200);
    CHECK(cpu.reg.c == 169);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 8);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 53793);
    // CHECK(cpu.reg.sp == 11354);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53792] == 0);
}

TEST_CASE( "00 004F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46386;
    cpu.reg.sp = 38589;
    cpu.reg.a = 83;
    cpu.reg.b = 216;
    cpu.reg.c = 56;
    cpu.reg.d = 178;
    cpu.reg.e = 94;
    cpu.reg.f = 240;
    cpu.reg.h = 208;
    cpu.reg.l = 67;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46386] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 83);
    CHECK(cpu.reg.b == 216);
    CHECK(cpu.reg.c == 56);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 94);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 208);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 46387);
    // CHECK(cpu.reg.sp == 38589);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46386] == 0);
}

TEST_CASE( "00 0050", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10931;
    cpu.reg.sp = 30039;
    cpu.reg.a = 95;
    cpu.reg.b = 17;
    cpu.reg.c = 203;
    cpu.reg.d = 118;
    cpu.reg.e = 89;
    cpu.reg.f = 80;
    cpu.reg.h = 243;
    cpu.reg.l = 62;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[10931] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 95);
    CHECK(cpu.reg.b == 17);
    CHECK(cpu.reg.c == 203);
    CHECK(cpu.reg.d == 118);
    CHECK(cpu.reg.e == 89);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 10932);
    // CHECK(cpu.reg.sp == 30039);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10931] == 0);
}

TEST_CASE( "00 0051", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14155;
    cpu.reg.sp = 46901;
    cpu.reg.a = 254;
    cpu.reg.b = 87;
    cpu.reg.c = 184;
    cpu.reg.d = 138;
    cpu.reg.e = 96;
    cpu.reg.f = 0;
    cpu.reg.h = 214;
    cpu.reg.l = 81;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[14155] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 254);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 138);
    CHECK(cpu.reg.e == 96);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 214);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 14156);
    // CHECK(cpu.reg.sp == 46901);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14155] == 0);
}

TEST_CASE( "00 0052", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20892;
    cpu.reg.sp = 7590;
    cpu.reg.a = 68;
    cpu.reg.b = 114;
    cpu.reg.c = 221;
    cpu.reg.d = 86;
    cpu.reg.e = 24;
    cpu.reg.f = 128;
    cpu.reg.h = 219;
    cpu.reg.l = 154;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[20892] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 114);
    CHECK(cpu.reg.c == 221);
    CHECK(cpu.reg.d == 86);
    CHECK(cpu.reg.e == 24);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 219);
    CHECK(cpu.reg.l == 154);
    CHECK(cpu.reg.pc == 20893);
    // CHECK(cpu.reg.sp == 7590);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20892] == 0);
}

TEST_CASE( "00 0053", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15048;
    cpu.reg.sp = 27354;
    cpu.reg.a = 247;
    cpu.reg.b = 114;
    cpu.reg.c = 150;
    cpu.reg.d = 66;
    cpu.reg.e = 253;
    cpu.reg.f = 32;
    cpu.reg.h = 53;
    cpu.reg.l = 119;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15048] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 114);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 253);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 119);
    CHECK(cpu.reg.pc == 15049);
    // CHECK(cpu.reg.sp == 27354);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15048] == 0);
}

TEST_CASE( "00 0054", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46147;
    cpu.reg.sp = 36966;
    cpu.reg.a = 47;
    cpu.reg.b = 229;
    cpu.reg.c = 8;
    cpu.reg.d = 6;
    cpu.reg.e = 39;
    cpu.reg.f = 64;
    cpu.reg.h = 75;
    cpu.reg.l = 119;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[46147] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 47);
    CHECK(cpu.reg.b == 229);
    CHECK(cpu.reg.c == 8);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 39);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 119);
    CHECK(cpu.reg.pc == 46148);
    // CHECK(cpu.reg.sp == 36966);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46147] == 0);
}

TEST_CASE( "00 0055", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33903;
    cpu.reg.sp = 60720;
    cpu.reg.a = 194;
    cpu.reg.b = 253;
    cpu.reg.c = 19;
    cpu.reg.d = 185;
    cpu.reg.e = 129;
    cpu.reg.f = 64;
    cpu.reg.h = 248;
    cpu.reg.l = 111;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[33903] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 253);
    CHECK(cpu.reg.c == 19);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 129);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 248);
    CHECK(cpu.reg.l == 111);
    CHECK(cpu.reg.pc == 33904);
    // CHECK(cpu.reg.sp == 60720);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33903] == 0);
}

TEST_CASE( "00 0056", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36172;
    cpu.reg.sp = 40599;
    cpu.reg.a = 164;
    cpu.reg.b = 148;
    cpu.reg.c = 75;
    cpu.reg.d = 130;
    cpu.reg.e = 220;
    cpu.reg.f = 224;
    cpu.reg.h = 180;
    cpu.reg.l = 154;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[36172] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 148);
    CHECK(cpu.reg.c == 75);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 220);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 154);
    CHECK(cpu.reg.pc == 36173);
    // CHECK(cpu.reg.sp == 40599);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36172] == 0);
}

TEST_CASE( "00 0057", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51977;
    cpu.reg.sp = 27551;
    cpu.reg.a = 146;
    cpu.reg.b = 197;
    cpu.reg.c = 65;
    cpu.reg.d = 194;
    cpu.reg.e = 178;
    cpu.reg.f = 144;
    cpu.reg.h = 220;
    cpu.reg.l = 110;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[51977] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 146);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 65);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 220);
    CHECK(cpu.reg.l == 110);
    CHECK(cpu.reg.pc == 51978);
    // CHECK(cpu.reg.sp == 27551);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[51977] == 0);
}

TEST_CASE( "00 0058", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52617;
    cpu.reg.sp = 63726;
    cpu.reg.a = 255;
    cpu.reg.b = 80;
    cpu.reg.c = 46;
    cpu.reg.d = 208;
    cpu.reg.e = 114;
    cpu.reg.f = 32;
    cpu.reg.h = 76;
    cpu.reg.l = 128;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[52617] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 255);
    CHECK(cpu.reg.b == 80);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 76);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 52618);
    // CHECK(cpu.reg.sp == 63726);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52617] == 0);
}

TEST_CASE( "00 0059", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57059;
    cpu.reg.sp = 8387;
    cpu.reg.a = 221;
    cpu.reg.b = 82;
    cpu.reg.c = 96;
    cpu.reg.d = 33;
    cpu.reg.e = 194;
    cpu.reg.f = 240;
    cpu.reg.h = 0;
    cpu.reg.l = 140;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[57059] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 82);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 194);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 57060);
    // CHECK(cpu.reg.sp == 8387);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57059] == 0);
}

TEST_CASE( "00 005A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60079;
    cpu.reg.sp = 55511;
    cpu.reg.a = 54;
    cpu.reg.b = 79;
    cpu.reg.c = 141;
    cpu.reg.d = 22;
    cpu.reg.e = 198;
    cpu.reg.f = 0;
    cpu.reg.h = 235;
    cpu.reg.l = 142;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60079] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 54);
    CHECK(cpu.reg.b == 79);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 198);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 235);
    CHECK(cpu.reg.l == 142);
    CHECK(cpu.reg.pc == 60080);
    // CHECK(cpu.reg.sp == 55511);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60079] == 0);
}

TEST_CASE( "00 005B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43319;
    cpu.reg.sp = 19279;
    cpu.reg.a = 108;
    cpu.reg.b = 193;
    cpu.reg.c = 154;
    cpu.reg.d = 133;
    cpu.reg.e = 155;
    cpu.reg.f = 32;
    cpu.reg.h = 75;
    cpu.reg.l = 208;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[43319] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 108);
    CHECK(cpu.reg.b == 193);
    CHECK(cpu.reg.c == 154);
    CHECK(cpu.reg.d == 133);
    CHECK(cpu.reg.e == 155);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 208);
    CHECK(cpu.reg.pc == 43320);
    // CHECK(cpu.reg.sp == 19279);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43319] == 0);
}

TEST_CASE( "00 005C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45686;
    cpu.reg.sp = 5440;
    cpu.reg.a = 37;
    cpu.reg.b = 140;
    cpu.reg.c = 248;
    cpu.reg.d = 47;
    cpu.reg.e = 33;
    cpu.reg.f = 48;
    cpu.reg.h = 28;
    cpu.reg.l = 134;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[45686] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 37);
    CHECK(cpu.reg.b == 140);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 47);
    CHECK(cpu.reg.e == 33);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 134);
    CHECK(cpu.reg.pc == 45687);
    // CHECK(cpu.reg.sp == 5440);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[45686] == 0);
}

TEST_CASE( "00 005D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10372;
    cpu.reg.sp = 60451;
    cpu.reg.a = 74;
    cpu.reg.b = 149;
    cpu.reg.c = 160;
    cpu.reg.d = 64;
    cpu.reg.e = 213;
    cpu.reg.f = 144;
    cpu.reg.h = 67;
    cpu.reg.l = 128;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[10372] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 74);
    CHECK(cpu.reg.b == 149);
    CHECK(cpu.reg.c == 160);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 10373);
    // CHECK(cpu.reg.sp == 60451);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10372] == 0);
}

TEST_CASE( "00 005E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35515;
    cpu.reg.sp = 15141;
    cpu.reg.a = 122;
    cpu.reg.b = 211;
    cpu.reg.c = 246;
    cpu.reg.d = 234;
    cpu.reg.e = 229;
    cpu.reg.f = 16;
    cpu.reg.h = 62;
    cpu.reg.l = 16;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35515] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 122);
    CHECK(cpu.reg.b == 211);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 229);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 62);
    CHECK(cpu.reg.l == 16);
    CHECK(cpu.reg.pc == 35516);
    // CHECK(cpu.reg.sp == 15141);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35515] == 0);
}

TEST_CASE( "00 005F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63379;
    cpu.reg.sp = 24030;
    cpu.reg.a = 52;
    cpu.reg.b = 97;
    cpu.reg.c = 75;
    cpu.reg.d = 152;
    cpu.reg.e = 90;
    cpu.reg.f = 112;
    cpu.reg.h = 254;
    cpu.reg.l = 70;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[63379] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 52);
    CHECK(cpu.reg.b == 97);
    CHECK(cpu.reg.c == 75);
    CHECK(cpu.reg.d == 152);
    CHECK(cpu.reg.e == 90);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 254);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 63380);
    // CHECK(cpu.reg.sp == 24030);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[63379] == 0);
}

TEST_CASE( "00 0060", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13628;
    cpu.reg.sp = 16323;
    cpu.reg.a = 32;
    cpu.reg.b = 59;
    cpu.reg.c = 162;
    cpu.reg.d = 130;
    cpu.reg.e = 214;
    cpu.reg.f = 192;
    cpu.reg.h = 243;
    cpu.reg.l = 141;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[13628] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 32);
    CHECK(cpu.reg.b == 59);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 214);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 141);
    CHECK(cpu.reg.pc == 13629);
    // CHECK(cpu.reg.sp == 16323);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13628] == 0);
}

TEST_CASE( "00 0061", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 534;
    cpu.reg.sp = 41494;
    cpu.reg.a = 93;
    cpu.reg.b = 76;
    cpu.reg.c = 126;
    cpu.reg.d = 48;
    cpu.reg.e = 217;
    cpu.reg.f = 176;
    cpu.reg.h = 209;
    cpu.reg.l = 62;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[534] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 93);
    CHECK(cpu.reg.b == 76);
    CHECK(cpu.reg.c == 126);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 535);
    // CHECK(cpu.reg.sp == 41494);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[534] == 0);
}

TEST_CASE( "00 0062", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62128;
    cpu.reg.sp = 30096;
    cpu.reg.a = 10;
    cpu.reg.b = 129;
    cpu.reg.c = 175;
    cpu.reg.d = 123;
    cpu.reg.e = 43;
    cpu.reg.f = 112;
    cpu.reg.h = 22;
    cpu.reg.l = 59;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[62128] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 175);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 22);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 62129);
    // CHECK(cpu.reg.sp == 30096);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62128] == 0);
}

TEST_CASE( "00 0063", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37468;
    cpu.reg.sp = 57870;
    cpu.reg.a = 155;
    cpu.reg.b = 16;
    cpu.reg.c = 193;
    cpu.reg.d = 1;
    cpu.reg.e = 67;
    cpu.reg.f = 32;
    cpu.reg.h = 56;
    cpu.reg.l = 180;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37468] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 155);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 193);
    CHECK(cpu.reg.d == 1);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 56);
    CHECK(cpu.reg.l == 180);
    CHECK(cpu.reg.pc == 37469);
    // CHECK(cpu.reg.sp == 57870);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37468] == 0);
}

TEST_CASE( "00 0064", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42230;
    cpu.reg.sp = 60001;
    cpu.reg.a = 217;
    cpu.reg.b = 219;
    cpu.reg.c = 210;
    cpu.reg.d = 190;
    cpu.reg.e = 69;
    cpu.reg.f = 16;
    cpu.reg.h = 220;
    cpu.reg.l = 7;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[42230] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 217);
    CHECK(cpu.reg.b == 219);
    CHECK(cpu.reg.c == 210);
    CHECK(cpu.reg.d == 190);
    CHECK(cpu.reg.e == 69);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 220);
    CHECK(cpu.reg.l == 7);
    CHECK(cpu.reg.pc == 42231);
    // CHECK(cpu.reg.sp == 60001);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42230] == 0);
}

TEST_CASE( "00 0065", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19780;
    cpu.reg.sp = 42946;
    cpu.reg.a = 62;
    cpu.reg.b = 180;
    cpu.reg.c = 164;
    cpu.reg.d = 231;
    cpu.reg.e = 231;
    cpu.reg.f = 112;
    cpu.reg.h = 199;
    cpu.reg.l = 195;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[19780] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 180);
    CHECK(cpu.reg.c == 164);
    CHECK(cpu.reg.d == 231);
    CHECK(cpu.reg.e == 231);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 199);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 19781);
    // CHECK(cpu.reg.sp == 42946);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19780] == 0);
}

TEST_CASE( "00 0066", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2134;
    cpu.reg.sp = 25151;
    cpu.reg.a = 95;
    cpu.reg.b = 95;
    cpu.reg.c = 0;
    cpu.reg.d = 108;
    cpu.reg.e = 199;
    cpu.reg.f = 128;
    cpu.reg.h = 122;
    cpu.reg.l = 119;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[2134] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 95);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 0);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 122);
    CHECK(cpu.reg.l == 119);
    CHECK(cpu.reg.pc == 2135);
    // CHECK(cpu.reg.sp == 25151);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2134] == 0);
}

TEST_CASE( "00 0067", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2935;
    cpu.reg.sp = 37620;
    cpu.reg.a = 134;
    cpu.reg.b = 90;
    cpu.reg.c = 123;
    cpu.reg.d = 229;
    cpu.reg.e = 30;
    cpu.reg.f = 16;
    cpu.reg.h = 164;
    cpu.reg.l = 96;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[2935] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 134);
    CHECK(cpu.reg.b == 90);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 30);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 96);
    CHECK(cpu.reg.pc == 2936);
    // CHECK(cpu.reg.sp == 37620);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[2935] == 0);
}

TEST_CASE( "00 0068", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32823;
    cpu.reg.sp = 34988;
    cpu.reg.a = 87;
    cpu.reg.b = 51;
    cpu.reg.c = 4;
    cpu.reg.d = 97;
    cpu.reg.e = 48;
    cpu.reg.f = 176;
    cpu.reg.h = 126;
    cpu.reg.l = 233;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32823] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 87);
    CHECK(cpu.reg.b == 51);
    CHECK(cpu.reg.c == 4);
    CHECK(cpu.reg.d == 97);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 126);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 32824);
    // CHECK(cpu.reg.sp == 34988);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32823] == 0);
}

TEST_CASE( "00 0069", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29447;
    cpu.reg.sp = 53699;
    cpu.reg.a = 52;
    cpu.reg.b = 255;
    cpu.reg.c = 173;
    cpu.reg.d = 184;
    cpu.reg.e = 48;
    cpu.reg.f = 64;
    cpu.reg.h = 180;
    cpu.reg.l = 193;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[29447] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 52);
    CHECK(cpu.reg.b == 255);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 193);
    CHECK(cpu.reg.pc == 29448);
    // CHECK(cpu.reg.sp == 53699);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29447] == 0);
}

TEST_CASE( "00 006A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15175;
    cpu.reg.sp = 25801;
    cpu.reg.a = 182;
    cpu.reg.b = 25;
    cpu.reg.c = 218;
    cpu.reg.d = 126;
    cpu.reg.e = 14;
    cpu.reg.f = 112;
    cpu.reg.h = 254;
    cpu.reg.l = 113;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[15175] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 182);
    CHECK(cpu.reg.b == 25);
    CHECK(cpu.reg.c == 218);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 14);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 254);
    CHECK(cpu.reg.l == 113);
    CHECK(cpu.reg.pc == 15176);
    // CHECK(cpu.reg.sp == 25801);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[15175] == 0);
}

TEST_CASE( "00 006B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39616;
    cpu.reg.sp = 56232;
    cpu.reg.a = 55;
    cpu.reg.b = 4;
    cpu.reg.c = 128;
    cpu.reg.d = 54;
    cpu.reg.e = 90;
    cpu.reg.f = 240;
    cpu.reg.h = 155;
    cpu.reg.l = 40;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[39616] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 55);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 90);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 155);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 39617);
    // CHECK(cpu.reg.sp == 56232);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39616] == 0);
}

TEST_CASE( "00 006C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42887;
    cpu.reg.sp = 41289;
    cpu.reg.a = 221;
    cpu.reg.b = 33;
    cpu.reg.c = 220;
    cpu.reg.d = 62;
    cpu.reg.e = 136;
    cpu.reg.f = 144;
    cpu.reg.h = 242;
    cpu.reg.l = 41;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[42887] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 33);
    CHECK(cpu.reg.c == 220);
    CHECK(cpu.reg.d == 62);
    CHECK(cpu.reg.e == 136);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 42888);
    // CHECK(cpu.reg.sp == 41289);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42887] == 0);
}

TEST_CASE( "00 006D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6922;
    cpu.reg.sp = 57045;
    cpu.reg.a = 2;
    cpu.reg.b = 47;
    cpu.reg.c = 41;
    cpu.reg.d = 154;
    cpu.reg.e = 66;
    cpu.reg.f = 240;
    cpu.reg.h = 197;
    cpu.reg.l = 174;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[6922] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 66);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 197);
    CHECK(cpu.reg.l == 174);
    CHECK(cpu.reg.pc == 6923);
    // CHECK(cpu.reg.sp == 57045);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[6922] == 0);
}

TEST_CASE( "00 006E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49341;
    cpu.reg.sp = 30064;
    cpu.reg.a = 225;
    cpu.reg.b = 72;
    cpu.reg.c = 21;
    cpu.reg.d = 254;
    cpu.reg.e = 234;
    cpu.reg.f = 144;
    cpu.reg.h = 160;
    cpu.reg.l = 122;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49341] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 225);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 21);
    CHECK(cpu.reg.d == 254);
    CHECK(cpu.reg.e == 234);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 122);
    CHECK(cpu.reg.pc == 49342);
    // CHECK(cpu.reg.sp == 30064);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49341] == 0);
}

TEST_CASE( "00 006F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26323;
    cpu.reg.sp = 14518;
    cpu.reg.a = 184;
    cpu.reg.b = 207;
    cpu.reg.c = 29;
    cpu.reg.d = 233;
    cpu.reg.e = 16;
    cpu.reg.f = 176;
    cpu.reg.h = 127;
    cpu.reg.l = 187;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[26323] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 207);
    CHECK(cpu.reg.c == 29);
    CHECK(cpu.reg.d == 233);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 127);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 26324);
    // CHECK(cpu.reg.sp == 14518);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26323] == 0);
}

TEST_CASE( "00 0070", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11118;
    cpu.reg.sp = 43605;
    cpu.reg.a = 212;
    cpu.reg.b = 54;
    cpu.reg.c = 237;
    cpu.reg.d = 160;
    cpu.reg.e = 207;
    cpu.reg.f = 16;
    cpu.reg.h = 155;
    cpu.reg.l = 83;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[11118] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 54);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 160);
    CHECK(cpu.reg.e == 207);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 155);
    CHECK(cpu.reg.l == 83);
    CHECK(cpu.reg.pc == 11119);
    // CHECK(cpu.reg.sp == 43605);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11118] == 0);
}

TEST_CASE( "00 0071", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28621;
    cpu.reg.sp = 9385;
    cpu.reg.a = 196;
    cpu.reg.b = 41;
    cpu.reg.c = 106;
    cpu.reg.d = 221;
    cpu.reg.e = 56;
    cpu.reg.f = 144;
    cpu.reg.h = 96;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28621] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 196);
    CHECK(cpu.reg.b == 41);
    CHECK(cpu.reg.c == 106);
    CHECK(cpu.reg.d == 221);
    CHECK(cpu.reg.e == 56);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 96);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 28622);
    // CHECK(cpu.reg.sp == 9385);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28621] == 0);
}

TEST_CASE( "00 0072", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57983;
    cpu.reg.sp = 4651;
    cpu.reg.a = 221;
    cpu.reg.b = 221;
    cpu.reg.c = 218;
    cpu.reg.d = 61;
    cpu.reg.e = 72;
    cpu.reg.f = 96;
    cpu.reg.h = 154;
    cpu.reg.l = 143;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[57983] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 221);
    CHECK(cpu.reg.c == 218);
    CHECK(cpu.reg.d == 61);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 143);
    CHECK(cpu.reg.pc == 57984);
    // CHECK(cpu.reg.sp == 4651);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57983] == 0);
}

TEST_CASE( "00 0073", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5838;
    cpu.reg.sp = 24534;
    cpu.reg.a = 193;
    cpu.reg.b = 29;
    cpu.reg.c = 112;
    cpu.reg.d = 109;
    cpu.reg.e = 185;
    cpu.reg.f = 64;
    cpu.reg.h = 226;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[5838] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 193);
    CHECK(cpu.reg.b == 29);
    CHECK(cpu.reg.c == 112);
    CHECK(cpu.reg.d == 109);
    CHECK(cpu.reg.e == 185);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 226);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 5839);
    // CHECK(cpu.reg.sp == 24534);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5838] == 0);
}

TEST_CASE( "00 0074", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19490;
    cpu.reg.sp = 42307;
    cpu.reg.a = 48;
    cpu.reg.b = 10;
    cpu.reg.c = 182;
    cpu.reg.d = 114;
    cpu.reg.e = 167;
    cpu.reg.f = 224;
    cpu.reg.h = 165;
    cpu.reg.l = 55;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[19490] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 10);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 167);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 165);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 19491);
    // CHECK(cpu.reg.sp == 42307);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19490] == 0);
}

TEST_CASE( "00 0075", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21772;
    cpu.reg.sp = 32623;
    cpu.reg.a = 156;
    cpu.reg.b = 197;
    cpu.reg.c = 68;
    cpu.reg.d = 178;
    cpu.reg.e = 220;
    cpu.reg.f = 80;
    cpu.reg.h = 233;
    cpu.reg.l = 139;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21772] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 156);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 68);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 220);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 233);
    CHECK(cpu.reg.l == 139);
    CHECK(cpu.reg.pc == 21773);
    // CHECK(cpu.reg.sp == 32623);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21772] == 0);
}

TEST_CASE( "00 0076", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41913;
    cpu.reg.sp = 11758;
    cpu.reg.a = 172;
    cpu.reg.b = 50;
    cpu.reg.c = 229;
    cpu.reg.d = 219;
    cpu.reg.e = 173;
    cpu.reg.f = 160;
    cpu.reg.h = 239;
    cpu.reg.l = 240;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[41913] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 172);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 229);
    CHECK(cpu.reg.d == 219);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 239);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 41914);
    // CHECK(cpu.reg.sp == 11758);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[41913] == 0);
}

TEST_CASE( "00 0077", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57654;
    cpu.reg.sp = 40884;
    cpu.reg.a = 239;
    cpu.reg.b = 46;
    cpu.reg.c = 90;
    cpu.reg.d = 215;
    cpu.reg.e = 153;
    cpu.reg.f = 32;
    cpu.reg.h = 69;
    cpu.reg.l = 158;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[57654] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 239);
    CHECK(cpu.reg.b == 46);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 215);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 158);
    CHECK(cpu.reg.pc == 57655);
    // CHECK(cpu.reg.sp == 40884);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57654] == 0);
}

TEST_CASE( "00 0078", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12273;
    cpu.reg.sp = 6367;
    cpu.reg.a = 174;
    cpu.reg.b = 185;
    cpu.reg.c = 115;
    cpu.reg.d = 42;
    cpu.reg.e = 115;
    cpu.reg.f = 64;
    cpu.reg.h = 177;
    cpu.reg.l = 255;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[12273] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 174);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 115);
    CHECK(cpu.reg.d == 42);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 177);
    CHECK(cpu.reg.l == 255);
    CHECK(cpu.reg.pc == 12274);
    // CHECK(cpu.reg.sp == 6367);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12273] == 0);
}

TEST_CASE( "00 0079", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8060;
    cpu.reg.sp = 13225;
    cpu.reg.a = 119;
    cpu.reg.b = 22;
    cpu.reg.c = 62;
    cpu.reg.d = 46;
    cpu.reg.e = 106;
    cpu.reg.f = 128;
    cpu.reg.h = 133;
    cpu.reg.l = 18;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[8060] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 119);
    CHECK(cpu.reg.b == 22);
    CHECK(cpu.reg.c == 62);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 106);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 133);
    CHECK(cpu.reg.l == 18);
    CHECK(cpu.reg.pc == 8061);
    // CHECK(cpu.reg.sp == 13225);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8060] == 0);
}

TEST_CASE( "00 007A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18286;
    cpu.reg.sp = 8500;
    cpu.reg.a = 34;
    cpu.reg.b = 64;
    cpu.reg.c = 31;
    cpu.reg.d = 185;
    cpu.reg.e = 68;
    cpu.reg.f = 16;
    cpu.reg.h = 232;
    cpu.reg.l = 247;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[18286] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 34);
    CHECK(cpu.reg.b == 64);
    CHECK(cpu.reg.c == 31);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 68);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 247);
    CHECK(cpu.reg.pc == 18287);
    // CHECK(cpu.reg.sp == 8500);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18286] == 0);
}

TEST_CASE( "00 007B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35420;
    cpu.reg.sp = 25759;
    cpu.reg.a = 246;
    cpu.reg.b = 238;
    cpu.reg.c = 107;
    cpu.reg.d = 21;
    cpu.reg.e = 202;
    cpu.reg.f = 96;
    cpu.reg.h = 7;
    cpu.reg.l = 138;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35420] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 246);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 21);
    CHECK(cpu.reg.e == 202);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 7);
    CHECK(cpu.reg.l == 138);
    CHECK(cpu.reg.pc == 35421);
    // CHECK(cpu.reg.sp == 25759);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35420] == 0);
}

TEST_CASE( "00 007C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46316;
    cpu.reg.sp = 57065;
    cpu.reg.a = 216;
    cpu.reg.b = 32;
    cpu.reg.c = 117;
    cpu.reg.d = 196;
    cpu.reg.e = 128;
    cpu.reg.f = 48;
    cpu.reg.h = 90;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[46316] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 216);
    CHECK(cpu.reg.b == 32);
    CHECK(cpu.reg.c == 117);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 128);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 90);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 46317);
    // CHECK(cpu.reg.sp == 57065);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46316] == 0);
}

TEST_CASE( "00 007D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5336;
    cpu.reg.sp = 15737;
    cpu.reg.a = 111;
    cpu.reg.b = 129;
    cpu.reg.c = 15;
    cpu.reg.d = 53;
    cpu.reg.e = 237;
    cpu.reg.f = 176;
    cpu.reg.h = 90;
    cpu.reg.l = 234;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5336] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 111);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 15);
    CHECK(cpu.reg.d == 53);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 90);
    CHECK(cpu.reg.l == 234);
    CHECK(cpu.reg.pc == 5337);
    // CHECK(cpu.reg.sp == 15737);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5336] == 0);
}

TEST_CASE( "00 007E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21858;
    cpu.reg.sp = 45612;
    cpu.reg.a = 70;
    cpu.reg.b = 39;
    cpu.reg.c = 207;
    cpu.reg.d = 204;
    cpu.reg.e = 37;
    cpu.reg.f = 80;
    cpu.reg.h = 252;
    cpu.reg.l = 223;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21858] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 70);
    CHECK(cpu.reg.b == 39);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 204);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 21859);
    // CHECK(cpu.reg.sp == 45612);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21858] == 0);
}

TEST_CASE( "00 007F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28534;
    cpu.reg.sp = 10331;
    cpu.reg.a = 139;
    cpu.reg.b = 211;
    cpu.reg.c = 137;
    cpu.reg.d = 239;
    cpu.reg.e = 95;
    cpu.reg.f = 128;
    cpu.reg.h = 19;
    cpu.reg.l = 56;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28534] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 211);
    CHECK(cpu.reg.c == 137);
    CHECK(cpu.reg.d == 239);
    CHECK(cpu.reg.e == 95);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 19);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 28535);
    // CHECK(cpu.reg.sp == 10331);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28534] == 0);
}

TEST_CASE( "00 0080", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27672;
    cpu.reg.sp = 61364;
    cpu.reg.a = 132;
    cpu.reg.b = 20;
    cpu.reg.c = 97;
    cpu.reg.d = 253;
    cpu.reg.e = 229;
    cpu.reg.f = 0;
    cpu.reg.h = 172;
    cpu.reg.l = 55;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[27672] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 132);
    CHECK(cpu.reg.b == 20);
    CHECK(cpu.reg.c == 97);
    CHECK(cpu.reg.d == 253);
    CHECK(cpu.reg.e == 229);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 172);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 27673);
    // CHECK(cpu.reg.sp == 61364);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27672] == 0);
}

TEST_CASE( "00 0081", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34102;
    cpu.reg.sp = 64450;
    cpu.reg.a = 188;
    cpu.reg.b = 57;
    cpu.reg.c = 101;
    cpu.reg.d = 43;
    cpu.reg.e = 188;
    cpu.reg.f = 176;
    cpu.reg.h = 225;
    cpu.reg.l = 136;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34102] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 188);
    CHECK(cpu.reg.b == 57);
    CHECK(cpu.reg.c == 101);
    CHECK(cpu.reg.d == 43);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 136);
    CHECK(cpu.reg.pc == 34103);
    // CHECK(cpu.reg.sp == 64450);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34102] == 0);
}

TEST_CASE( "00 0082", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19979;
    cpu.reg.sp = 48343;
    cpu.reg.a = 104;
    cpu.reg.b = 95;
    cpu.reg.c = 242;
    cpu.reg.d = 64;
    cpu.reg.e = 80;
    cpu.reg.f = 96;
    cpu.reg.h = 183;
    cpu.reg.l = 59;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19979] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 104);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 242);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 80);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 183);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 19980);
    // CHECK(cpu.reg.sp == 48343);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19979] == 0);
}

TEST_CASE( "00 0083", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14215;
    cpu.reg.sp = 53947;
    cpu.reg.a = 4;
    cpu.reg.b = 62;
    cpu.reg.c = 177;
    cpu.reg.d = 251;
    cpu.reg.e = 115;
    cpu.reg.f = 0;
    cpu.reg.h = 140;
    cpu.reg.l = 127;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[14215] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 4);
    CHECK(cpu.reg.b == 62);
    CHECK(cpu.reg.c == 177);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 14216);
    // CHECK(cpu.reg.sp == 53947);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[14215] == 0);
}

TEST_CASE( "00 0084", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60025;
    cpu.reg.sp = 55372;
    cpu.reg.a = 10;
    cpu.reg.b = 128;
    cpu.reg.c = 218;
    cpu.reg.d = 48;
    cpu.reg.e = 164;
    cpu.reg.f = 144;
    cpu.reg.h = 25;
    cpu.reg.l = 136;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60025] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 128);
    CHECK(cpu.reg.c == 218);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 164);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 25);
    CHECK(cpu.reg.l == 136);
    CHECK(cpu.reg.pc == 60026);
    // CHECK(cpu.reg.sp == 55372);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60025] == 0);
}

TEST_CASE( "00 0085", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36070;
    cpu.reg.sp = 39393;
    cpu.reg.a = 217;
    cpu.reg.b = 85;
    cpu.reg.c = 237;
    cpu.reg.d = 64;
    cpu.reg.e = 135;
    cpu.reg.f = 112;
    cpu.reg.h = 106;
    cpu.reg.l = 223;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[36070] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 217);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 135);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 36071);
    // CHECK(cpu.reg.sp == 39393);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36070] == 0);
}

TEST_CASE( "00 0086", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20826;
    cpu.reg.sp = 11432;
    cpu.reg.a = 140;
    cpu.reg.b = 222;
    cpu.reg.c = 119;
    cpu.reg.d = 4;
    cpu.reg.e = 237;
    cpu.reg.f = 112;
    cpu.reg.h = 149;
    cpu.reg.l = 183;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[20826] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 222);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 4);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 183);
    CHECK(cpu.reg.pc == 20827);
    // CHECK(cpu.reg.sp == 11432);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20826] == 0);
}

TEST_CASE( "00 0087", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7409;
    cpu.reg.sp = 63435;
    cpu.reg.a = 211;
    cpu.reg.b = 165;
    cpu.reg.c = 68;
    cpu.reg.d = 41;
    cpu.reg.e = 208;
    cpu.reg.f = 80;
    cpu.reg.h = 66;
    cpu.reg.l = 195;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7409] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 211);
    CHECK(cpu.reg.b == 165);
    CHECK(cpu.reg.c == 68);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 208);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 66);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 7410);
    // CHECK(cpu.reg.sp == 63435);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7409] == 0);
}

TEST_CASE( "00 0088", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27664;
    cpu.reg.sp = 61593;
    cpu.reg.a = 138;
    cpu.reg.b = 87;
    cpu.reg.c = 113;
    cpu.reg.d = 24;
    cpu.reg.e = 240;
    cpu.reg.f = 32;
    cpu.reg.h = 125;
    cpu.reg.l = 140;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[27664] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 138);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 113);
    CHECK(cpu.reg.d == 24);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 27665);
    // CHECK(cpu.reg.sp == 61593);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27664] == 0);
}

TEST_CASE( "00 0089", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43961;
    cpu.reg.sp = 10677;
    cpu.reg.a = 222;
    cpu.reg.b = 82;
    cpu.reg.c = 128;
    cpu.reg.d = 183;
    cpu.reg.e = 41;
    cpu.reg.f = 96;
    cpu.reg.h = 141;
    cpu.reg.l = 250;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[43961] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 222);
    CHECK(cpu.reg.b == 82);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 41);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 43962);
    // CHECK(cpu.reg.sp == 10677);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43961] == 0);
}

TEST_CASE( "00 008A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3492;
    cpu.reg.sp = 35347;
    cpu.reg.a = 141;
    cpu.reg.b = 133;
    cpu.reg.c = 70;
    cpu.reg.d = 200;
    cpu.reg.e = 149;
    cpu.reg.f = 32;
    cpu.reg.h = 249;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[3492] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 70);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 149);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 249);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 3493);
    // CHECK(cpu.reg.sp == 35347);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3492] == 0);
}

TEST_CASE( "00 008B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62692;
    cpu.reg.sp = 59126;
    cpu.reg.a = 93;
    cpu.reg.b = 71;
    cpu.reg.c = 184;
    cpu.reg.d = 39;
    cpu.reg.e = 19;
    cpu.reg.f = 208;
    cpu.reg.h = 173;
    cpu.reg.l = 72;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62692] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 93);
    CHECK(cpu.reg.b == 71);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 39);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 173);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 62693);
    // CHECK(cpu.reg.sp == 59126);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62692] == 0);
}

TEST_CASE( "00 008C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64533;
    cpu.reg.sp = 38653;
    cpu.reg.a = 15;
    cpu.reg.b = 239;
    cpu.reg.c = 97;
    cpu.reg.d = 179;
    cpu.reg.e = 203;
    cpu.reg.f = 128;
    cpu.reg.h = 124;
    cpu.reg.l = 219;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[64533] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 239);
    CHECK(cpu.reg.c == 97);
    CHECK(cpu.reg.d == 179);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 124);
    CHECK(cpu.reg.l == 219);
    CHECK(cpu.reg.pc == 64534);
    // CHECK(cpu.reg.sp == 38653);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64533] == 0);
}

TEST_CASE( "00 008D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11858;
    cpu.reg.sp = 54016;
    cpu.reg.a = 224;
    cpu.reg.b = 235;
    cpu.reg.c = 39;
    cpu.reg.d = 61;
    cpu.reg.e = 21;
    cpu.reg.f = 0;
    cpu.reg.h = 77;
    cpu.reg.l = 145;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[11858] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 224);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 39);
    CHECK(cpu.reg.d == 61);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 77);
    CHECK(cpu.reg.l == 145);
    CHECK(cpu.reg.pc == 11859);
    // CHECK(cpu.reg.sp == 54016);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11858] == 0);
}

TEST_CASE( "00 008E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21612;
    cpu.reg.sp = 50076;
    cpu.reg.a = 125;
    cpu.reg.b = 215;
    cpu.reg.c = 141;
    cpu.reg.d = 64;
    cpu.reg.e = 251;
    cpu.reg.f = 32;
    cpu.reg.h = 10;
    cpu.reg.l = 206;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21612] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 125);
    CHECK(cpu.reg.b == 215);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 251);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 10);
    CHECK(cpu.reg.l == 206);
    CHECK(cpu.reg.pc == 21613);
    // CHECK(cpu.reg.sp == 50076);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21612] == 0);
}

TEST_CASE( "00 008F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14800;
    cpu.reg.sp = 32909;
    cpu.reg.a = 143;
    cpu.reg.b = 115;
    cpu.reg.c = 14;
    cpu.reg.d = 148;
    cpu.reg.e = 169;
    cpu.reg.f = 32;
    cpu.reg.h = 60;
    cpu.reg.l = 216;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[14800] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 115);
    CHECK(cpu.reg.c == 14);
    CHECK(cpu.reg.d == 148);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 14801);
    // CHECK(cpu.reg.sp == 32909);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14800] == 0);
}

TEST_CASE( "00 0090", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8373;
    cpu.reg.sp = 57496;
    cpu.reg.a = 122;
    cpu.reg.b = 33;
    cpu.reg.c = 187;
    cpu.reg.d = 211;
    cpu.reg.e = 173;
    cpu.reg.f = 32;
    cpu.reg.h = 240;
    cpu.reg.l = 227;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[8373] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 122);
    CHECK(cpu.reg.b == 33);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 211);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 240);
    CHECK(cpu.reg.l == 227);
    CHECK(cpu.reg.pc == 8374);
    // CHECK(cpu.reg.sp == 57496);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8373] == 0);
}

TEST_CASE( "00 0091", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36764;
    cpu.reg.sp = 53841;
    cpu.reg.a = 151;
    cpu.reg.b = 208;
    cpu.reg.c = 86;
    cpu.reg.d = 30;
    cpu.reg.e = 16;
    cpu.reg.f = 208;
    cpu.reg.h = 53;
    cpu.reg.l = 224;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[36764] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 151);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 86);
    CHECK(cpu.reg.d == 30);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 224);
    CHECK(cpu.reg.pc == 36765);
    // CHECK(cpu.reg.sp == 53841);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36764] == 0);
}

TEST_CASE( "00 0092", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58943;
    cpu.reg.sp = 12378;
    cpu.reg.a = 144;
    cpu.reg.b = 231;
    cpu.reg.c = 211;
    cpu.reg.d = 190;
    cpu.reg.e = 159;
    cpu.reg.f = 128;
    cpu.reg.h = 61;
    cpu.reg.l = 167;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[58943] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 144);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 190);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 61);
    CHECK(cpu.reg.l == 167);
    CHECK(cpu.reg.pc == 58944);
    // CHECK(cpu.reg.sp == 12378);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58943] == 0);
}

TEST_CASE( "00 0093", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25684;
    cpu.reg.sp = 64977;
    cpu.reg.a = 21;
    cpu.reg.b = 222;
    cpu.reg.c = 242;
    cpu.reg.d = 178;
    cpu.reg.e = 66;
    cpu.reg.f = 240;
    cpu.reg.h = 147;
    cpu.reg.l = 125;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25684] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 222);
    CHECK(cpu.reg.c == 242);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 66);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 125);
    CHECK(cpu.reg.pc == 25685);
    // CHECK(cpu.reg.sp == 64977);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25684] == 0);
}

TEST_CASE( "00 0094", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32792;
    cpu.reg.sp = 15340;
    cpu.reg.a = 13;
    cpu.reg.b = 165;
    cpu.reg.c = 28;
    cpu.reg.d = 71;
    cpu.reg.e = 86;
    cpu.reg.f = 112;
    cpu.reg.h = 175;
    cpu.reg.l = 91;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32792] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 13);
    CHECK(cpu.reg.b == 165);
    CHECK(cpu.reg.c == 28);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 86);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 175);
    CHECK(cpu.reg.l == 91);
    CHECK(cpu.reg.pc == 32793);
    // CHECK(cpu.reg.sp == 15340);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32792] == 0);
}

TEST_CASE( "00 0095", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31396;
    cpu.reg.sp = 8556;
    cpu.reg.a = 223;
    cpu.reg.b = 73;
    cpu.reg.c = 38;
    cpu.reg.d = 33;
    cpu.reg.e = 195;
    cpu.reg.f = 32;
    cpu.reg.h = 23;
    cpu.reg.l = 20;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[31396] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 223);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 38);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 23);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 31397);
    // CHECK(cpu.reg.sp == 8556);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[31396] == 0);
}

TEST_CASE( "00 0096", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53306;
    cpu.reg.sp = 438;
    cpu.reg.a = 84;
    cpu.reg.b = 217;
    cpu.reg.c = 127;
    cpu.reg.d = 128;
    cpu.reg.e = 0;
    cpu.reg.f = 0;
    cpu.reg.h = 121;
    cpu.reg.l = 67;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[53306] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 217);
    CHECK(cpu.reg.c == 127);
    CHECK(cpu.reg.d == 128);
    CHECK(cpu.reg.e == 0);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 121);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 53307);
    // CHECK(cpu.reg.sp == 438);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53306] == 0);
}

TEST_CASE( "00 0097", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54520;
    cpu.reg.sp = 36217;
    cpu.reg.a = 111;
    cpu.reg.b = 222;
    cpu.reg.c = 134;
    cpu.reg.d = 172;
    cpu.reg.e = 69;
    cpu.reg.f = 176;
    cpu.reg.h = 82;
    cpu.reg.l = 31;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54520] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 111);
    CHECK(cpu.reg.b == 222);
    CHECK(cpu.reg.c == 134);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 69);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 82);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 54521);
    // CHECK(cpu.reg.sp == 36217);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54520] == 0);
}

TEST_CASE( "00 0098", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28572;
    cpu.reg.sp = 6868;
    cpu.reg.a = 16;
    cpu.reg.b = 210;
    cpu.reg.c = 232;
    cpu.reg.d = 240;
    cpu.reg.e = 116;
    cpu.reg.f = 16;
    cpu.reg.h = 4;
    cpu.reg.l = 29;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28572] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 16);
    CHECK(cpu.reg.b == 210);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 240);
    CHECK(cpu.reg.e == 116);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 4);
    CHECK(cpu.reg.l == 29);
    CHECK(cpu.reg.pc == 28573);
    // CHECK(cpu.reg.sp == 6868);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28572] == 0);
}

TEST_CASE( "00 0099", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31513;
    cpu.reg.sp = 9959;
    cpu.reg.a = 244;
    cpu.reg.b = 107;
    cpu.reg.c = 209;
    cpu.reg.d = 92;
    cpu.reg.e = 204;
    cpu.reg.f = 16;
    cpu.reg.h = 184;
    cpu.reg.l = 36;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[31513] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 209);
    CHECK(cpu.reg.d == 92);
    CHECK(cpu.reg.e == 204);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 36);
    CHECK(cpu.reg.pc == 31514);
    // CHECK(cpu.reg.sp == 9959);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31513] == 0);
}

TEST_CASE( "00 009A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21214;
    cpu.reg.sp = 22769;
    cpu.reg.a = 219;
    cpu.reg.b = 55;
    cpu.reg.c = 173;
    cpu.reg.d = 19;
    cpu.reg.e = 36;
    cpu.reg.f = 224;
    cpu.reg.h = 74;
    cpu.reg.l = 117;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21214] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 219);
    CHECK(cpu.reg.b == 55);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 19);
    CHECK(cpu.reg.e == 36);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 74);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 21215);
    // CHECK(cpu.reg.sp == 22769);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21214] == 0);
}

TEST_CASE( "00 009B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 406;
    cpu.reg.sp = 11213;
    cpu.reg.a = 96;
    cpu.reg.b = 133;
    cpu.reg.c = 240;
    cpu.reg.d = 179;
    cpu.reg.e = 147;
    cpu.reg.f = 96;
    cpu.reg.h = 75;
    cpu.reg.l = 106;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[406] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 179);
    CHECK(cpu.reg.e == 147);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 407);
    // CHECK(cpu.reg.sp == 11213);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[406] == 0);
}

TEST_CASE( "00 009C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42081;
    cpu.reg.sp = 45762;
    cpu.reg.a = 184;
    cpu.reg.b = 130;
    cpu.reg.c = 246;
    cpu.reg.d = 68;
    cpu.reg.e = 145;
    cpu.reg.f = 0;
    cpu.reg.h = 139;
    cpu.reg.l = 65;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[42081] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 130);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 145);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 65);
    CHECK(cpu.reg.pc == 42082);
    // CHECK(cpu.reg.sp == 45762);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42081] == 0);
}

TEST_CASE( "00 009D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38284;
    cpu.reg.sp = 53039;
    cpu.reg.a = 128;
    cpu.reg.b = 176;
    cpu.reg.c = 181;
    cpu.reg.d = 154;
    cpu.reg.e = 203;
    cpu.reg.f = 160;
    cpu.reg.h = 184;
    cpu.reg.l = 179;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[38284] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 176);
    CHECK(cpu.reg.c == 181);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 38285);
    // CHECK(cpu.reg.sp == 53039);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38284] == 0);
}

TEST_CASE( "00 009E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41200;
    cpu.reg.sp = 23226;
    cpu.reg.a = 207;
    cpu.reg.b = 220;
    cpu.reg.c = 90;
    cpu.reg.d = 229;
    cpu.reg.e = 171;
    cpu.reg.f = 144;
    cpu.reg.h = 218;
    cpu.reg.l = 83;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[41200] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 207);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 83);
    CHECK(cpu.reg.pc == 41201);
    // CHECK(cpu.reg.sp == 23226);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41200] == 0);
}

TEST_CASE( "00 009F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49474;
    cpu.reg.sp = 48059;
    cpu.reg.a = 206;
    cpu.reg.b = 66;
    cpu.reg.c = 65;
    cpu.reg.d = 16;
    cpu.reg.e = 84;
    cpu.reg.f = 192;
    cpu.reg.h = 99;
    cpu.reg.l = 29;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49474] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 65);
    CHECK(cpu.reg.d == 16);
    CHECK(cpu.reg.e == 84);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 29);
    CHECK(cpu.reg.pc == 49475);
    // CHECK(cpu.reg.sp == 48059);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49474] == 0);
}

TEST_CASE( "00 00A0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 620;
    cpu.reg.sp = 40917;
    cpu.reg.a = 132;
    cpu.reg.b = 139;
    cpu.reg.c = 118;
    cpu.reg.d = 200;
    cpu.reg.e = 97;
    cpu.reg.f = 0;
    cpu.reg.h = 87;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[620] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 132);
    CHECK(cpu.reg.b == 139);
    CHECK(cpu.reg.c == 118);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 87);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 621);
    // CHECK(cpu.reg.sp == 40917);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[620] == 0);
}

TEST_CASE( "00 00A1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34331;
    cpu.reg.sp = 40186;
    cpu.reg.a = 35;
    cpu.reg.b = 128;
    cpu.reg.c = 24;
    cpu.reg.d = 166;
    cpu.reg.e = 95;
    cpu.reg.f = 208;
    cpu.reg.h = 106;
    cpu.reg.l = 117;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[34331] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 35);
    CHECK(cpu.reg.b == 128);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 166);
    CHECK(cpu.reg.e == 95);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 34332);
    // CHECK(cpu.reg.sp == 40186);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34331] == 0);
}

TEST_CASE( "00 00A2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18510;
    cpu.reg.sp = 4323;
    cpu.reg.a = 176;
    cpu.reg.b = 160;
    cpu.reg.c = 143;
    cpu.reg.d = 197;
    cpu.reg.e = 173;
    cpu.reg.f = 16;
    cpu.reg.h = 138;
    cpu.reg.l = 137;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[18510] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 176);
    CHECK(cpu.reg.b == 160);
    CHECK(cpu.reg.c == 143);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 138);
    CHECK(cpu.reg.l == 137);
    CHECK(cpu.reg.pc == 18511);
    // CHECK(cpu.reg.sp == 4323);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18510] == 0);
}

TEST_CASE( "00 00A3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41808;
    cpu.reg.sp = 60021;
    cpu.reg.a = 140;
    cpu.reg.b = 104;
    cpu.reg.c = 84;
    cpu.reg.d = 220;
    cpu.reg.e = 141;
    cpu.reg.f = 16;
    cpu.reg.h = 238;
    cpu.reg.l = 126;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[41808] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 104);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 220);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 238);
    CHECK(cpu.reg.l == 126);
    CHECK(cpu.reg.pc == 41809);
    // CHECK(cpu.reg.sp == 60021);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41808] == 0);
}

TEST_CASE( "00 00A4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42915;
    cpu.reg.sp = 17332;
    cpu.reg.a = 17;
    cpu.reg.b = 45;
    cpu.reg.c = 176;
    cpu.reg.d = 59;
    cpu.reg.e = 105;
    cpu.reg.f = 96;
    cpu.reg.h = 170;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[42915] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 17);
    CHECK(cpu.reg.b == 45);
    CHECK(cpu.reg.c == 176);
    CHECK(cpu.reg.d == 59);
    CHECK(cpu.reg.e == 105);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 42916);
    // CHECK(cpu.reg.sp == 17332);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42915] == 0);
}

TEST_CASE( "00 00A5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52184;
    cpu.reg.sp = 59046;
    cpu.reg.a = 20;
    cpu.reg.b = 84;
    cpu.reg.c = 237;
    cpu.reg.d = 37;
    cpu.reg.e = 136;
    cpu.reg.f = 176;
    cpu.reg.h = 209;
    cpu.reg.l = 50;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[52184] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 20);
    CHECK(cpu.reg.b == 84);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 136);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 50);
    CHECK(cpu.reg.pc == 52185);
    // CHECK(cpu.reg.sp == 59046);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52184] == 0);
}

TEST_CASE( "00 00A6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33861;
    cpu.reg.sp = 31649;
    cpu.reg.a = 6;
    cpu.reg.b = 65;
    cpu.reg.c = 216;
    cpu.reg.d = 11;
    cpu.reg.e = 217;
    cpu.reg.f = 64;
    cpu.reg.h = 31;
    cpu.reg.l = 81;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[33861] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 6);
    CHECK(cpu.reg.b == 65);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 11);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 31);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 33862);
    // CHECK(cpu.reg.sp == 31649);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33861] == 0);
}

TEST_CASE( "00 00A7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23618;
    cpu.reg.sp = 25964;
    cpu.reg.a = 15;
    cpu.reg.b = 109;
    cpu.reg.c = 86;
    cpu.reg.d = 49;
    cpu.reg.e = 54;
    cpu.reg.f = 144;
    cpu.reg.h = 225;
    cpu.reg.l = 102;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[23618] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 86);
    CHECK(cpu.reg.d == 49);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 23619);
    // CHECK(cpu.reg.sp == 25964);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[23618] == 0);
}

TEST_CASE( "00 00A8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37785;
    cpu.reg.sp = 35304;
    cpu.reg.a = 132;
    cpu.reg.b = 251;
    cpu.reg.c = 120;
    cpu.reg.d = 89;
    cpu.reg.e = 124;
    cpu.reg.f = 128;
    cpu.reg.h = 234;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37785] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 132);
    CHECK(cpu.reg.b == 251);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 234);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 37786);
    // CHECK(cpu.reg.sp == 35304);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37785] == 0);
}

TEST_CASE( "00 00A9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51207;
    cpu.reg.sp = 1928;
    cpu.reg.a = 218;
    cpu.reg.b = 97;
    cpu.reg.c = 245;
    cpu.reg.d = 47;
    cpu.reg.e = 206;
    cpu.reg.f = 32;
    cpu.reg.h = 87;
    cpu.reg.l = 249;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[51207] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 97);
    CHECK(cpu.reg.c == 245);
    CHECK(cpu.reg.d == 47);
    CHECK(cpu.reg.e == 206);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 87);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 51208);
    // CHECK(cpu.reg.sp == 1928);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[51207] == 0);
}

TEST_CASE( "00 00AA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64087;
    cpu.reg.sp = 62713;
    cpu.reg.a = 90;
    cpu.reg.b = 218;
    cpu.reg.c = 9;
    cpu.reg.d = 206;
    cpu.reg.e = 160;
    cpu.reg.f = 144;
    cpu.reg.h = 68;
    cpu.reg.l = 177;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64087] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 90);
    CHECK(cpu.reg.b == 218);
    CHECK(cpu.reg.c == 9);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 68);
    CHECK(cpu.reg.l == 177);
    CHECK(cpu.reg.pc == 64088);
    // CHECK(cpu.reg.sp == 62713);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64087] == 0);
}

TEST_CASE( "00 00AB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50678;
    cpu.reg.sp = 58620;
    cpu.reg.a = 165;
    cpu.reg.b = 47;
    cpu.reg.c = 100;
    cpu.reg.d = 102;
    cpu.reg.e = 37;
    cpu.reg.f = 16;
    cpu.reg.h = 116;
    cpu.reg.l = 49;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[50678] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 165);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 100);
    CHECK(cpu.reg.d == 102);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 116);
    CHECK(cpu.reg.l == 49);
    CHECK(cpu.reg.pc == 50679);
    // CHECK(cpu.reg.sp == 58620);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[50678] == 0);
}

TEST_CASE( "00 00AC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60557;
    cpu.reg.sp = 62211;
    cpu.reg.a = 245;
    cpu.reg.b = 224;
    cpu.reg.c = 116;
    cpu.reg.d = 200;
    cpu.reg.e = 33;
    cpu.reg.f = 192;
    cpu.reg.h = 14;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60557] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 245);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 33);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 14);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 60558);
    // CHECK(cpu.reg.sp == 62211);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60557] == 0);
}

TEST_CASE( "00 00AD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33724;
    cpu.reg.sp = 31326;
    cpu.reg.a = 250;
    cpu.reg.b = 15;
    cpu.reg.c = 29;
    cpu.reg.d = 94;
    cpu.reg.e = 5;
    cpu.reg.f = 224;
    cpu.reg.h = 186;
    cpu.reg.l = 153;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[33724] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 250);
    CHECK(cpu.reg.b == 15);
    CHECK(cpu.reg.c == 29);
    CHECK(cpu.reg.d == 94);
    CHECK(cpu.reg.e == 5);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 33725);
    // CHECK(cpu.reg.sp == 31326);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33724] == 0);
}

TEST_CASE( "00 00AE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30438;
    cpu.reg.sp = 33823;
    cpu.reg.a = 18;
    cpu.reg.b = 132;
    cpu.reg.c = 233;
    cpu.reg.d = 75;
    cpu.reg.e = 41;
    cpu.reg.f = 240;
    cpu.reg.h = 217;
    cpu.reg.l = 149;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[30438] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 132);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 75);
    CHECK(cpu.reg.e == 41);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 217);
    CHECK(cpu.reg.l == 149);
    CHECK(cpu.reg.pc == 30439);
    // CHECK(cpu.reg.sp == 33823);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30438] == 0);
}

TEST_CASE( "00 00AF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38938;
    cpu.reg.sp = 44750;
    cpu.reg.a = 18;
    cpu.reg.b = 7;
    cpu.reg.c = 237;
    cpu.reg.d = 31;
    cpu.reg.e = 229;
    cpu.reg.f = 208;
    cpu.reg.h = 156;
    cpu.reg.l = 174;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[38938] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 7);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 229);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 174);
    CHECK(cpu.reg.pc == 38939);
    // CHECK(cpu.reg.sp == 44750);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38938] == 0);
}

TEST_CASE( "00 00B0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5035;
    cpu.reg.sp = 14832;
    cpu.reg.a = 248;
    cpu.reg.b = 220;
    cpu.reg.c = 33;
    cpu.reg.d = 206;
    cpu.reg.e = 120;
    cpu.reg.f = 192;
    cpu.reg.h = 162;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[5035] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 248);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 33);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 120);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 5036);
    // CHECK(cpu.reg.sp == 14832);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5035] == 0);
}

TEST_CASE( "00 00B1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57445;
    cpu.reg.sp = 25003;
    cpu.reg.a = 57;
    cpu.reg.b = 24;
    cpu.reg.c = 141;
    cpu.reg.d = 62;
    cpu.reg.e = 94;
    cpu.reg.f = 0;
    cpu.reg.h = 24;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[57445] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 57);
    CHECK(cpu.reg.b == 24);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 62);
    CHECK(cpu.reg.e == 94);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 57446);
    // CHECK(cpu.reg.sp == 25003);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57445] == 0);
}

TEST_CASE( "00 00B2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3487;
    cpu.reg.sp = 43587;
    cpu.reg.a = 69;
    cpu.reg.b = 149;
    cpu.reg.c = 143;
    cpu.reg.d = 103;
    cpu.reg.e = 204;
    cpu.reg.f = 96;
    cpu.reg.h = 59;
    cpu.reg.l = 13;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[3487] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 149);
    CHECK(cpu.reg.c == 143);
    CHECK(cpu.reg.d == 103);
    CHECK(cpu.reg.e == 204);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 59);
    CHECK(cpu.reg.l == 13);
    CHECK(cpu.reg.pc == 3488);
    // CHECK(cpu.reg.sp == 43587);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3487] == 0);
}

TEST_CASE( "00 00B3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16823;
    cpu.reg.sp = 30706;
    cpu.reg.a = 177;
    cpu.reg.b = 101;
    cpu.reg.c = 94;
    cpu.reg.d = 134;
    cpu.reg.e = 118;
    cpu.reg.f = 64;
    cpu.reg.h = 45;
    cpu.reg.l = 30;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[16823] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 177);
    CHECK(cpu.reg.b == 101);
    CHECK(cpu.reg.c == 94);
    CHECK(cpu.reg.d == 134);
    CHECK(cpu.reg.e == 118);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 45);
    CHECK(cpu.reg.l == 30);
    CHECK(cpu.reg.pc == 16824);
    // CHECK(cpu.reg.sp == 30706);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16823] == 0);
}

TEST_CASE( "00 00B4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9584;
    cpu.reg.sp = 48711;
    cpu.reg.a = 177;
    cpu.reg.b = 245;
    cpu.reg.c = 230;
    cpu.reg.d = 59;
    cpu.reg.e = 218;
    cpu.reg.f = 0;
    cpu.reg.h = 185;
    cpu.reg.l = 80;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9584] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 177);
    CHECK(cpu.reg.b == 245);
    CHECK(cpu.reg.c == 230);
    CHECK(cpu.reg.d == 59);
    CHECK(cpu.reg.e == 218);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 185);
    CHECK(cpu.reg.l == 80);
    CHECK(cpu.reg.pc == 9585);
    // CHECK(cpu.reg.sp == 48711);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9584] == 0);
}

TEST_CASE( "00 00B5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19830;
    cpu.reg.sp = 50514;
    cpu.reg.a = 94;
    cpu.reg.b = 214;
    cpu.reg.c = 151;
    cpu.reg.d = 82;
    cpu.reg.e = 31;
    cpu.reg.f = 208;
    cpu.reg.h = 139;
    cpu.reg.l = 31;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[19830] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 214);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 31);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 19831);
    // CHECK(cpu.reg.sp == 50514);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19830] == 0);
}

TEST_CASE( "00 00B6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53924;
    cpu.reg.sp = 14367;
    cpu.reg.a = 206;
    cpu.reg.b = 66;
    cpu.reg.c = 30;
    cpu.reg.d = 85;
    cpu.reg.e = 163;
    cpu.reg.f = 224;
    cpu.reg.h = 148;
    cpu.reg.l = 119;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53924] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 30);
    CHECK(cpu.reg.d == 85);
    CHECK(cpu.reg.e == 163);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 148);
    CHECK(cpu.reg.l == 119);
    CHECK(cpu.reg.pc == 53925);
    // CHECK(cpu.reg.sp == 14367);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53924] == 0);
}

TEST_CASE( "00 00B7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16657;
    cpu.reg.sp = 52530;
    cpu.reg.a = 229;
    cpu.reg.b = 28;
    cpu.reg.c = 131;
    cpu.reg.d = 20;
    cpu.reg.e = 231;
    cpu.reg.f = 160;
    cpu.reg.h = 149;
    cpu.reg.l = 210;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[16657] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 229);
    CHECK(cpu.reg.b == 28);
    CHECK(cpu.reg.c == 131);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 231);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 210);
    CHECK(cpu.reg.pc == 16658);
    // CHECK(cpu.reg.sp == 52530);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16657] == 0);
}

TEST_CASE( "00 00B8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39961;
    cpu.reg.sp = 5356;
    cpu.reg.a = 199;
    cpu.reg.b = 46;
    cpu.reg.c = 198;
    cpu.reg.d = 90;
    cpu.reg.e = 72;
    cpu.reg.f = 240;
    cpu.reg.h = 16;
    cpu.reg.l = 220;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[39961] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 199);
    CHECK(cpu.reg.b == 46);
    CHECK(cpu.reg.c == 198);
    CHECK(cpu.reg.d == 90);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 16);
    CHECK(cpu.reg.l == 220);
    CHECK(cpu.reg.pc == 39962);
    // CHECK(cpu.reg.sp == 5356);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39961] == 0);
}

TEST_CASE( "00 00B9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60694;
    cpu.reg.sp = 41453;
    cpu.reg.a = 26;
    cpu.reg.b = 225;
    cpu.reg.c = 173;
    cpu.reg.d = 0;
    cpu.reg.e = 73;
    cpu.reg.f = 96;
    cpu.reg.h = 2;
    cpu.reg.l = 109;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[60694] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 26);
    CHECK(cpu.reg.b == 225);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 0);
    CHECK(cpu.reg.e == 73);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 2);
    CHECK(cpu.reg.l == 109);
    CHECK(cpu.reg.pc == 60695);
    // CHECK(cpu.reg.sp == 41453);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60694] == 0);
}

TEST_CASE( "00 00BA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15370;
    cpu.reg.sp = 14007;
    cpu.reg.a = 79;
    cpu.reg.b = 74;
    cpu.reg.c = 93;
    cpu.reg.d = 140;
    cpu.reg.e = 160;
    cpu.reg.f = 208;
    cpu.reg.h = 129;
    cpu.reg.l = 185;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15370] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 79);
    CHECK(cpu.reg.b == 74);
    CHECK(cpu.reg.c == 93);
    CHECK(cpu.reg.d == 140);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 129);
    CHECK(cpu.reg.l == 185);
    CHECK(cpu.reg.pc == 15371);
    // CHECK(cpu.reg.sp == 14007);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15370] == 0);
}

TEST_CASE( "00 00BB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24106;
    cpu.reg.sp = 33717;
    cpu.reg.a = 158;
    cpu.reg.b = 193;
    cpu.reg.c = 180;
    cpu.reg.d = 210;
    cpu.reg.e = 246;
    cpu.reg.f = 80;
    cpu.reg.h = 104;
    cpu.reg.l = 60;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[24106] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 158);
    CHECK(cpu.reg.b == 193);
    CHECK(cpu.reg.c == 180);
    CHECK(cpu.reg.d == 210);
    CHECK(cpu.reg.e == 246);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 104);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 24107);
    // CHECK(cpu.reg.sp == 33717);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[24106] == 0);
}

TEST_CASE( "00 00BC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53446;
    cpu.reg.sp = 31814;
    cpu.reg.a = 245;
    cpu.reg.b = 38;
    cpu.reg.c = 63;
    cpu.reg.d = 188;
    cpu.reg.e = 38;
    cpu.reg.f = 112;
    cpu.reg.h = 121;
    cpu.reg.l = 242;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53446] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 245);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 63);
    CHECK(cpu.reg.d == 188);
    CHECK(cpu.reg.e == 38);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 121);
    CHECK(cpu.reg.l == 242);
    CHECK(cpu.reg.pc == 53447);
    // CHECK(cpu.reg.sp == 31814);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53446] == 0);
}

TEST_CASE( "00 00BD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 89;
    cpu.reg.sp = 63468;
    cpu.reg.a = 146;
    cpu.reg.b = 235;
    cpu.reg.c = 6;
    cpu.reg.d = 10;
    cpu.reg.e = 143;
    cpu.reg.f = 32;
    cpu.reg.h = 77;
    cpu.reg.l = 100;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[89] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 146);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 6);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 143);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 77);
    CHECK(cpu.reg.l == 100);
    CHECK(cpu.reg.pc == 90);
    // CHECK(cpu.reg.sp == 63468);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[89] == 0);
}

TEST_CASE( "00 00BE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10209;
    cpu.reg.sp = 34100;
    cpu.reg.a = 20;
    cpu.reg.b = 236;
    cpu.reg.c = 192;
    cpu.reg.d = 128;
    cpu.reg.e = 136;
    cpu.reg.f = 64;
    cpu.reg.h = 172;
    cpu.reg.l = 180;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[10209] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 20);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 192);
    CHECK(cpu.reg.d == 128);
    CHECK(cpu.reg.e == 136);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 172);
    CHECK(cpu.reg.l == 180);
    CHECK(cpu.reg.pc == 10210);
    // CHECK(cpu.reg.sp == 34100);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10209] == 0);
}

TEST_CASE( "00 00BF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61006;
    cpu.reg.sp = 9838;
    cpu.reg.a = 253;
    cpu.reg.b = 231;
    cpu.reg.c = 26;
    cpu.reg.d = 65;
    cpu.reg.e = 208;
    cpu.reg.f = 112;
    cpu.reg.h = 86;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[61006] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 253);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 26);
    CHECK(cpu.reg.d == 65);
    CHECK(cpu.reg.e == 208);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 86);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 61007);
    // CHECK(cpu.reg.sp == 9838);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[61006] == 0);
}

TEST_CASE( "00 00C0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48275;
    cpu.reg.sp = 3346;
    cpu.reg.a = 147;
    cpu.reg.b = 186;
    cpu.reg.c = 184;
    cpu.reg.d = 79;
    cpu.reg.e = 108;
    cpu.reg.f = 144;
    cpu.reg.h = 75;
    cpu.reg.l = 150;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[48275] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 147);
    CHECK(cpu.reg.b == 186);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 108);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 150);
    CHECK(cpu.reg.pc == 48276);
    // CHECK(cpu.reg.sp == 3346);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48275] == 0);
}

TEST_CASE( "00 00C1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32861;
    cpu.reg.sp = 25393;
    cpu.reg.a = 110;
    cpu.reg.b = 159;
    cpu.reg.c = 84;
    cpu.reg.d = 114;
    cpu.reg.e = 166;
    cpu.reg.f = 240;
    cpu.reg.h = 61;
    cpu.reg.l = 223;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32861] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 110);
    CHECK(cpu.reg.b == 159);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 166);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 61);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 32862);
    // CHECK(cpu.reg.sp == 25393);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32861] == 0);
}

TEST_CASE( "00 00C2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31304;
    cpu.reg.sp = 60374;
    cpu.reg.a = 103;
    cpu.reg.b = 200;
    cpu.reg.c = 247;
    cpu.reg.d = 35;
    cpu.reg.e = 153;
    cpu.reg.f = 208;
    cpu.reg.h = 103;
    cpu.reg.l = 37;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[31304] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 200);
    CHECK(cpu.reg.c == 247);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 103);
    CHECK(cpu.reg.l == 37);
    CHECK(cpu.reg.pc == 31305);
    // CHECK(cpu.reg.sp == 60374);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31304] == 0);
}

TEST_CASE( "00 00C3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4184;
    cpu.reg.sp = 44943;
    cpu.reg.a = 86;
    cpu.reg.b = 156;
    cpu.reg.c = 221;
    cpu.reg.d = 222;
    cpu.reg.e = 136;
    cpu.reg.f = 192;
    cpu.reg.h = 243;
    cpu.reg.l = 45;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[4184] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 86);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 221);
    CHECK(cpu.reg.d == 222);
    CHECK(cpu.reg.e == 136);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 45);
    CHECK(cpu.reg.pc == 4185);
    // CHECK(cpu.reg.sp == 44943);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[4184] == 0);
}

TEST_CASE( "00 00C4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3100;
    cpu.reg.sp = 33771;
    cpu.reg.a = 72;
    cpu.reg.b = 90;
    cpu.reg.c = 177;
    cpu.reg.d = 162;
    cpu.reg.e = 95;
    cpu.reg.f = 240;
    cpu.reg.h = 166;
    cpu.reg.l = 164;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[3100] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 72);
    CHECK(cpu.reg.b == 90);
    CHECK(cpu.reg.c == 177);
    CHECK(cpu.reg.d == 162);
    CHECK(cpu.reg.e == 95);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 164);
    CHECK(cpu.reg.pc == 3101);
    // CHECK(cpu.reg.sp == 33771);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3100] == 0);
}

TEST_CASE( "00 00C5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25841;
    cpu.reg.sp = 52895;
    cpu.reg.a = 129;
    cpu.reg.b = 104;
    cpu.reg.c = 151;
    cpu.reg.d = 13;
    cpu.reg.e = 32;
    cpu.reg.f = 64;
    cpu.reg.h = 145;
    cpu.reg.l = 191;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25841] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 129);
    CHECK(cpu.reg.b == 104);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 13);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 145);
    CHECK(cpu.reg.l == 191);
    CHECK(cpu.reg.pc == 25842);
    // CHECK(cpu.reg.sp == 52895);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25841] == 0);
}

TEST_CASE( "00 00C6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21842;
    cpu.reg.sp = 55033;
    cpu.reg.a = 81;
    cpu.reg.b = 217;
    cpu.reg.c = 139;
    cpu.reg.d = 12;
    cpu.reg.e = 25;
    cpu.reg.f = 16;
    cpu.reg.h = 177;
    cpu.reg.l = 222;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[21842] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 217);
    CHECK(cpu.reg.c == 139);
    CHECK(cpu.reg.d == 12);
    CHECK(cpu.reg.e == 25);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 177);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 21843);
    // CHECK(cpu.reg.sp == 55033);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21842] == 0);
}

TEST_CASE( "00 00C7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44069;
    cpu.reg.sp = 39937;
    cpu.reg.a = 168;
    cpu.reg.b = 75;
    cpu.reg.c = 196;
    cpu.reg.d = 28;
    cpu.reg.e = 229;
    cpu.reg.f = 128;
    cpu.reg.h = 249;
    cpu.reg.l = 130;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[44069] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 168);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 196);
    CHECK(cpu.reg.d == 28);
    CHECK(cpu.reg.e == 229);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 249);
    CHECK(cpu.reg.l == 130);
    CHECK(cpu.reg.pc == 44070);
    // CHECK(cpu.reg.sp == 39937);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44069] == 0);
}

TEST_CASE( "00 00C8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24548;
    cpu.reg.sp = 39260;
    cpu.reg.a = 37;
    cpu.reg.b = 190;
    cpu.reg.c = 17;
    cpu.reg.d = 239;
    cpu.reg.e = 63;
    cpu.reg.f = 96;
    cpu.reg.h = 231;
    cpu.reg.l = 186;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[24548] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 37);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 239);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 231);
    CHECK(cpu.reg.l == 186);
    CHECK(cpu.reg.pc == 24549);
    // CHECK(cpu.reg.sp == 39260);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[24548] == 0);
}

TEST_CASE( "00 00C9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 911;
    cpu.reg.sp = 13826;
    cpu.reg.a = 150;
    cpu.reg.b = 95;
    cpu.reg.c = 157;
    cpu.reg.d = 234;
    cpu.reg.e = 62;
    cpu.reg.f = 112;
    cpu.reg.h = 38;
    cpu.reg.l = 7;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[911] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 150);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 62);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 7);
    CHECK(cpu.reg.pc == 912);
    // CHECK(cpu.reg.sp == 13826);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[911] == 0);
}

TEST_CASE( "00 00CA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65472;
    cpu.reg.sp = 24256;
    cpu.reg.a = 63;
    cpu.reg.b = 40;
    cpu.reg.c = 111;
    cpu.reg.d = 66;
    cpu.reg.e = 15;
    cpu.reg.f = 208;
    cpu.reg.h = 74;
    cpu.reg.l = 70;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[65472] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 40);
    CHECK(cpu.reg.c == 111);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 15);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 74);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 65473);
    // CHECK(cpu.reg.sp == 24256);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[65472] == 0);
}

TEST_CASE( "00 00CB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39858;
    cpu.reg.sp = 24949;
    cpu.reg.a = 143;
    cpu.reg.b = 202;
    cpu.reg.c = 128;
    cpu.reg.d = 68;
    cpu.reg.e = 193;
    cpu.reg.f = 16;
    cpu.reg.h = 154;
    cpu.reg.l = 216;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39858] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 193);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 39859);
    // CHECK(cpu.reg.sp == 24949);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39858] == 0);
}

TEST_CASE( "00 00CC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30098;
    cpu.reg.sp = 44042;
    cpu.reg.a = 62;
    cpu.reg.b = 109;
    cpu.reg.c = 62;
    cpu.reg.d = 154;
    cpu.reg.e = 173;
    cpu.reg.f = 240;
    cpu.reg.h = 161;
    cpu.reg.l = 253;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[30098] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 62);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 30099);
    // CHECK(cpu.reg.sp == 44042);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30098] == 0);
}

TEST_CASE( "00 00CD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27206;
    cpu.reg.sp = 20074;
    cpu.reg.a = 37;
    cpu.reg.b = 14;
    cpu.reg.c = 40;
    cpu.reg.d = 240;
    cpu.reg.e = 71;
    cpu.reg.f = 0;
    cpu.reg.h = 109;
    cpu.reg.l = 22;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[27206] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 37);
    CHECK(cpu.reg.b == 14);
    CHECK(cpu.reg.c == 40);
    CHECK(cpu.reg.d == 240);
    CHECK(cpu.reg.e == 71);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 109);
    CHECK(cpu.reg.l == 22);
    CHECK(cpu.reg.pc == 27207);
    // CHECK(cpu.reg.sp == 20074);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27206] == 0);
}

TEST_CASE( "00 00CE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19396;
    cpu.reg.sp = 10275;
    cpu.reg.a = 193;
    cpu.reg.b = 129;
    cpu.reg.c = 54;
    cpu.reg.d = 32;
    cpu.reg.e = 54;
    cpu.reg.f = 192;
    cpu.reg.h = 249;
    cpu.reg.l = 221;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19396] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 193);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 54);
    CHECK(cpu.reg.d == 32);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 249);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 19397);
    // CHECK(cpu.reg.sp == 10275);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19396] == 0);
}

TEST_CASE( "00 00CF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6040;
    cpu.reg.sp = 19490;
    cpu.reg.a = 152;
    cpu.reg.b = 209;
    cpu.reg.c = 65;
    cpu.reg.d = 187;
    cpu.reg.e = 166;
    cpu.reg.f = 64;
    cpu.reg.h = 74;
    cpu.reg.l = 2;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6040] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 152);
    CHECK(cpu.reg.b == 209);
    CHECK(cpu.reg.c == 65);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 166);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 74);
    CHECK(cpu.reg.l == 2);
    CHECK(cpu.reg.pc == 6041);
    // CHECK(cpu.reg.sp == 19490);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6040] == 0);
}

TEST_CASE( "00 00D0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42745;
    cpu.reg.sp = 34423;
    cpu.reg.a = 117;
    cpu.reg.b = 228;
    cpu.reg.c = 234;
    cpu.reg.d = 2;
    cpu.reg.e = 209;
    cpu.reg.f = 176;
    cpu.reg.h = 141;
    cpu.reg.l = 105;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[42745] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 234);
    CHECK(cpu.reg.d == 2);
    CHECK(cpu.reg.e == 209);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 105);
    CHECK(cpu.reg.pc == 42746);
    // CHECK(cpu.reg.sp == 34423);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42745] == 0);
}

TEST_CASE( "00 00D1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65054;
    cpu.reg.sp = 23860;
    cpu.reg.a = 23;
    cpu.reg.b = 28;
    cpu.reg.c = 17;
    cpu.reg.d = 109;
    cpu.reg.e = 41;
    cpu.reg.f = 0;
    cpu.reg.h = 228;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[65054] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 23);
    CHECK(cpu.reg.b == 28);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 109);
    CHECK(cpu.reg.e == 41);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 228);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 65055);
    // CHECK(cpu.reg.sp == 23860);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[65054] == 0);
}

TEST_CASE( "00 00D2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14404;
    cpu.reg.sp = 64681;
    cpu.reg.a = 50;
    cpu.reg.b = 150;
    cpu.reg.c = 141;
    cpu.reg.d = 73;
    cpu.reg.e = 105;
    cpu.reg.f = 224;
    cpu.reg.h = 203;
    cpu.reg.l = 167;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[14404] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 150);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 105);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 167);
    CHECK(cpu.reg.pc == 14405);
    // CHECK(cpu.reg.sp == 64681);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[14404] == 0);
}

TEST_CASE( "00 00D3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7255;
    cpu.reg.sp = 41921;
    cpu.reg.a = 162;
    cpu.reg.b = 63;
    cpu.reg.c = 81;
    cpu.reg.d = 111;
    cpu.reg.e = 21;
    cpu.reg.f = 240;
    cpu.reg.h = 173;
    cpu.reg.l = 70;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7255] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 162);
    CHECK(cpu.reg.b == 63);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 111);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 173);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 7256);
    // CHECK(cpu.reg.sp == 41921);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7255] == 0);
}

TEST_CASE( "00 00D4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43058;
    cpu.reg.sp = 44175;
    cpu.reg.a = 10;
    cpu.reg.b = 228;
    cpu.reg.c = 183;
    cpu.reg.d = 121;
    cpu.reg.e = 91;
    cpu.reg.f = 240;
    cpu.reg.h = 110;
    cpu.reg.l = 57;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[43058] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 121);
    CHECK(cpu.reg.e == 91);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 110);
    CHECK(cpu.reg.l == 57);
    CHECK(cpu.reg.pc == 43059);
    // CHECK(cpu.reg.sp == 44175);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43058] == 0);
}

TEST_CASE( "00 00D5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 851;
    cpu.reg.sp = 3064;
    cpu.reg.a = 49;
    cpu.reg.b = 2;
    cpu.reg.c = 44;
    cpu.reg.d = 87;
    cpu.reg.e = 104;
    cpu.reg.f = 240;
    cpu.reg.h = 236;
    cpu.reg.l = 82;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[851] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 49);
    CHECK(cpu.reg.b == 2);
    CHECK(cpu.reg.c == 44);
    CHECK(cpu.reg.d == 87);
    CHECK(cpu.reg.e == 104);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 82);
    CHECK(cpu.reg.pc == 852);
    // CHECK(cpu.reg.sp == 3064);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[851] == 0);
}

TEST_CASE( "00 00D6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44216;
    cpu.reg.sp = 27238;
    cpu.reg.a = 26;
    cpu.reg.b = 177;
    cpu.reg.c = 46;
    cpu.reg.d = 175;
    cpu.reg.e = 142;
    cpu.reg.f = 192;
    cpu.reg.h = 204;
    cpu.reg.l = 251;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44216] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 26);
    CHECK(cpu.reg.b == 177);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 175);
    CHECK(cpu.reg.e == 142);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 204);
    CHECK(cpu.reg.l == 251);
    CHECK(cpu.reg.pc == 44217);
    // CHECK(cpu.reg.sp == 27238);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44216] == 0);
}

TEST_CASE( "00 00D7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10389;
    cpu.reg.sp = 64317;
    cpu.reg.a = 23;
    cpu.reg.b = 238;
    cpu.reg.c = 93;
    cpu.reg.d = 245;
    cpu.reg.e = 182;
    cpu.reg.f = 176;
    cpu.reg.h = 82;
    cpu.reg.l = 186;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[10389] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 23);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 93);
    CHECK(cpu.reg.d == 245);
    CHECK(cpu.reg.e == 182);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 82);
    CHECK(cpu.reg.l == 186);
    CHECK(cpu.reg.pc == 10390);
    // CHECK(cpu.reg.sp == 64317);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10389] == 0);
}

TEST_CASE( "00 00D8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34312;
    cpu.reg.sp = 25283;
    cpu.reg.a = 25;
    cpu.reg.b = 49;
    cpu.reg.c = 178;
    cpu.reg.d = 185;
    cpu.reg.e = 180;
    cpu.reg.f = 240;
    cpu.reg.h = 45;
    cpu.reg.l = 214;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[34312] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 178);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 180);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 45);
    CHECK(cpu.reg.l == 214);
    CHECK(cpu.reg.pc == 34313);
    // CHECK(cpu.reg.sp == 25283);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34312] == 0);
}

TEST_CASE( "00 00D9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63728;
    cpu.reg.sp = 48011;
    cpu.reg.a = 84;
    cpu.reg.b = 129;
    cpu.reg.c = 12;
    cpu.reg.d = 130;
    cpu.reg.e = 189;
    cpu.reg.f = 32;
    cpu.reg.h = 187;
    cpu.reg.l = 254;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63728] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 189);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 187);
    CHECK(cpu.reg.l == 254);
    CHECK(cpu.reg.pc == 63729);
    // CHECK(cpu.reg.sp == 48011);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63728] == 0);
}

TEST_CASE( "00 00DA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5203;
    cpu.reg.sp = 34121;
    cpu.reg.a = 183;
    cpu.reg.b = 102;
    cpu.reg.c = 48;
    cpu.reg.d = 231;
    cpu.reg.e = 152;
    cpu.reg.f = 112;
    cpu.reg.h = 188;
    cpu.reg.l = 68;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5203] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 102);
    CHECK(cpu.reg.c == 48);
    CHECK(cpu.reg.d == 231);
    CHECK(cpu.reg.e == 152);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 68);
    CHECK(cpu.reg.pc == 5204);
    // CHECK(cpu.reg.sp == 34121);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5203] == 0);
}

TEST_CASE( "00 00DB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15845;
    cpu.reg.sp = 54365;
    cpu.reg.a = 25;
    cpu.reg.b = 179;
    cpu.reg.c = 94;
    cpu.reg.d = 93;
    cpu.reg.e = 58;
    cpu.reg.f = 176;
    cpu.reg.h = 143;
    cpu.reg.l = 150;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15845] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 179);
    CHECK(cpu.reg.c == 94);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 58);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 143);
    CHECK(cpu.reg.l == 150);
    CHECK(cpu.reg.pc == 15846);
    // CHECK(cpu.reg.sp == 54365);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15845] == 0);
}

TEST_CASE( "00 00DC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21633;
    cpu.reg.sp = 32397;
    cpu.reg.a = 1;
    cpu.reg.b = 54;
    cpu.reg.c = 106;
    cpu.reg.d = 121;
    cpu.reg.e = 67;
    cpu.reg.f = 32;
    cpu.reg.h = 95;
    cpu.reg.l = 33;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[21633] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 1);
    CHECK(cpu.reg.b == 54);
    CHECK(cpu.reg.c == 106);
    CHECK(cpu.reg.d == 121);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 95);
    CHECK(cpu.reg.l == 33);
    CHECK(cpu.reg.pc == 21634);
    // CHECK(cpu.reg.sp == 32397);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21633] == 0);
}

TEST_CASE( "00 00DD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42412;
    cpu.reg.sp = 6438;
    cpu.reg.a = 4;
    cpu.reg.b = 171;
    cpu.reg.c = 52;
    cpu.reg.d = 14;
    cpu.reg.e = 74;
    cpu.reg.f = 96;
    cpu.reg.h = 255;
    cpu.reg.l = 53;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[42412] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 4);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 52);
    CHECK(cpu.reg.d == 14);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 255);
    CHECK(cpu.reg.l == 53);
    CHECK(cpu.reg.pc == 42413);
    // CHECK(cpu.reg.sp == 6438);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42412] == 0);
}

TEST_CASE( "00 00DE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32154;
    cpu.reg.sp = 42673;
    cpu.reg.a = 189;
    cpu.reg.b = 47;
    cpu.reg.c = 208;
    cpu.reg.d = 239;
    cpu.reg.e = 133;
    cpu.reg.f = 208;
    cpu.reg.h = 105;
    cpu.reg.l = 109;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32154] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 189);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 208);
    CHECK(cpu.reg.d == 239);
    CHECK(cpu.reg.e == 133);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 105);
    CHECK(cpu.reg.l == 109);
    CHECK(cpu.reg.pc == 32155);
    // CHECK(cpu.reg.sp == 42673);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32154] == 0);
}

TEST_CASE( "00 00DF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54376;
    cpu.reg.sp = 31634;
    cpu.reg.a = 131;
    cpu.reg.b = 116;
    cpu.reg.c = 36;
    cpu.reg.d = 28;
    cpu.reg.e = 92;
    cpu.reg.f = 64;
    cpu.reg.h = 43;
    cpu.reg.l = 216;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54376] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 131);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 36);
    CHECK(cpu.reg.d == 28);
    CHECK(cpu.reg.e == 92);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 43);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 54377);
    // CHECK(cpu.reg.sp == 31634);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54376] == 0);
}

TEST_CASE( "00 00E0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22082;
    cpu.reg.sp = 39465;
    cpu.reg.a = 88;
    cpu.reg.b = 238;
    cpu.reg.c = 232;
    cpu.reg.d = 44;
    cpu.reg.e = 230;
    cpu.reg.f = 240;
    cpu.reg.h = 208;
    cpu.reg.l = 188;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[22082] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 88);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 44);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 208);
    CHECK(cpu.reg.l == 188);
    CHECK(cpu.reg.pc == 22083);
    // CHECK(cpu.reg.sp == 39465);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22082] == 0);
}

TEST_CASE( "00 00E1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62192;
    cpu.reg.sp = 63276;
    cpu.reg.a = 118;
    cpu.reg.b = 176;
    cpu.reg.c = 132;
    cpu.reg.d = 93;
    cpu.reg.e = 163;
    cpu.reg.f = 64;
    cpu.reg.h = 59;
    cpu.reg.l = 107;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62192] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 176);
    CHECK(cpu.reg.c == 132);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 163);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 59);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 62193);
    // CHECK(cpu.reg.sp == 63276);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62192] == 0);
}

TEST_CASE( "00 00E2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43152;
    cpu.reg.sp = 45535;
    cpu.reg.a = 1;
    cpu.reg.b = 137;
    cpu.reg.c = 96;
    cpu.reg.d = 225;
    cpu.reg.e = 157;
    cpu.reg.f = 0;
    cpu.reg.h = 159;
    cpu.reg.l = 132;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43152] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 1);
    CHECK(cpu.reg.b == 137);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 157);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 159);
    CHECK(cpu.reg.l == 132);
    CHECK(cpu.reg.pc == 43153);
    // CHECK(cpu.reg.sp == 45535);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43152] == 0);
}

TEST_CASE( "00 00E3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47512;
    cpu.reg.sp = 33463;
    cpu.reg.a = 197;
    cpu.reg.b = 247;
    cpu.reg.c = 249;
    cpu.reg.d = 73;
    cpu.reg.e = 43;
    cpu.reg.f = 224;
    cpu.reg.h = 18;
    cpu.reg.l = 27;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47512] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 247);
    CHECK(cpu.reg.c == 249);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 18);
    CHECK(cpu.reg.l == 27);
    CHECK(cpu.reg.pc == 47513);
    // CHECK(cpu.reg.sp == 33463);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47512] == 0);
}

TEST_CASE( "00 00E4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7903;
    cpu.reg.sp = 48290;
    cpu.reg.a = 3;
    cpu.reg.b = 12;
    cpu.reg.c = 202;
    cpu.reg.d = 15;
    cpu.reg.e = 174;
    cpu.reg.f = 160;
    cpu.reg.h = 24;
    cpu.reg.l = 40;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7903] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 12);
    CHECK(cpu.reg.c == 202);
    CHECK(cpu.reg.d == 15);
    CHECK(cpu.reg.e == 174);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 7904);
    // CHECK(cpu.reg.sp == 48290);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7903] == 0);
}

TEST_CASE( "00 00E5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46164;
    cpu.reg.sp = 17620;
    cpu.reg.a = 138;
    cpu.reg.b = 32;
    cpu.reg.c = 114;
    cpu.reg.d = 123;
    cpu.reg.e = 93;
    cpu.reg.f = 224;
    cpu.reg.h = 218;
    cpu.reg.l = 147;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[46164] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 138);
    CHECK(cpu.reg.b == 32);
    CHECK(cpu.reg.c == 114);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 93);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 147);
    CHECK(cpu.reg.pc == 46165);
    // CHECK(cpu.reg.sp == 17620);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46164] == 0);
}

TEST_CASE( "00 00E6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46707;
    cpu.reg.sp = 5713;
    cpu.reg.a = 42;
    cpu.reg.b = 188;
    cpu.reg.c = 240;
    cpu.reg.d = 99;
    cpu.reg.e = 83;
    cpu.reg.f = 32;
    cpu.reg.h = 209;
    cpu.reg.l = 91;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[46707] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 188);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 99);
    CHECK(cpu.reg.e == 83);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 91);
    CHECK(cpu.reg.pc == 46708);
    // CHECK(cpu.reg.sp == 5713);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46707] == 0);
}

TEST_CASE( "00 00E7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24620;
    cpu.reg.sp = 10154;
    cpu.reg.a = 111;
    cpu.reg.b = 218;
    cpu.reg.c = 180;
    cpu.reg.d = 72;
    cpu.reg.e = 232;
    cpu.reg.f = 64;
    cpu.reg.h = 29;
    cpu.reg.l = 87;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[24620] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 111);
    CHECK(cpu.reg.b == 218);
    CHECK(cpu.reg.c == 180);
    CHECK(cpu.reg.d == 72);
    CHECK(cpu.reg.e == 232);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 29);
    CHECK(cpu.reg.l == 87);
    CHECK(cpu.reg.pc == 24621);
    // CHECK(cpu.reg.sp == 10154);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[24620] == 0);
}

TEST_CASE( "00 00E8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26923;
    cpu.reg.sp = 29555;
    cpu.reg.a = 238;
    cpu.reg.b = 203;
    cpu.reg.c = 12;
    cpu.reg.d = 171;
    cpu.reg.e = 117;
    cpu.reg.f = 48;
    cpu.reg.h = 232;
    cpu.reg.l = 160;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[26923] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 203);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 171);
    CHECK(cpu.reg.e == 117);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 26924);
    // CHECK(cpu.reg.sp == 29555);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26923] == 0);
}

TEST_CASE( "00 00E9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14836;
    cpu.reg.sp = 59230;
    cpu.reg.a = 247;
    cpu.reg.b = 183;
    cpu.reg.c = 227;
    cpu.reg.d = 34;
    cpu.reg.e = 32;
    cpu.reg.f = 64;
    cpu.reg.h = 71;
    cpu.reg.l = 58;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[14836] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 34);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 58);
    CHECK(cpu.reg.pc == 14837);
    // CHECK(cpu.reg.sp == 59230);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14836] == 0);
}

TEST_CASE( "00 00EA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52128;
    cpu.reg.sp = 30702;
    cpu.reg.a = 188;
    cpu.reg.b = 199;
    cpu.reg.c = 72;
    cpu.reg.d = 248;
    cpu.reg.e = 58;
    cpu.reg.f = 192;
    cpu.reg.h = 191;
    cpu.reg.l = 238;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[52128] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 188);
    CHECK(cpu.reg.b == 199);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 248);
    CHECK(cpu.reg.e == 58);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 238);
    CHECK(cpu.reg.pc == 52129);
    // CHECK(cpu.reg.sp == 30702);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52128] == 0);
}

TEST_CASE( "00 00EB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64182;
    cpu.reg.sp = 9451;
    cpu.reg.a = 142;
    cpu.reg.b = 245;
    cpu.reg.c = 134;
    cpu.reg.d = 127;
    cpu.reg.e = 9;
    cpu.reg.f = 16;
    cpu.reg.h = 69;
    cpu.reg.l = 183;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64182] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 142);
    CHECK(cpu.reg.b == 245);
    CHECK(cpu.reg.c == 134);
    CHECK(cpu.reg.d == 127);
    CHECK(cpu.reg.e == 9);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 183);
    CHECK(cpu.reg.pc == 64183);
    // CHECK(cpu.reg.sp == 9451);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64182] == 0);
}

TEST_CASE( "00 00EC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43038;
    cpu.reg.sp = 57812;
    cpu.reg.a = 95;
    cpu.reg.b = 164;
    cpu.reg.c = 230;
    cpu.reg.d = 51;
    cpu.reg.e = 190;
    cpu.reg.f = 112;
    cpu.reg.h = 166;
    cpu.reg.l = 200;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[43038] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 95);
    CHECK(cpu.reg.b == 164);
    CHECK(cpu.reg.c == 230);
    CHECK(cpu.reg.d == 51);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 43039);
    // CHECK(cpu.reg.sp == 57812);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43038] == 0);
}

TEST_CASE( "00 00ED", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11563;
    cpu.reg.sp = 30518;
    cpu.reg.a = 227;
    cpu.reg.b = 110;
    cpu.reg.c = 2;
    cpu.reg.d = 34;
    cpu.reg.e = 153;
    cpu.reg.f = 144;
    cpu.reg.h = 120;
    cpu.reg.l = 145;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[11563] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 227);
    CHECK(cpu.reg.b == 110);
    CHECK(cpu.reg.c == 2);
    CHECK(cpu.reg.d == 34);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 145);
    CHECK(cpu.reg.pc == 11564);
    // CHECK(cpu.reg.sp == 30518);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11563] == 0);
}

TEST_CASE( "00 00EE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12145;
    cpu.reg.sp = 28484;
    cpu.reg.a = 71;
    cpu.reg.b = 253;
    cpu.reg.c = 24;
    cpu.reg.d = 112;
    cpu.reg.e = 16;
    cpu.reg.f = 176;
    cpu.reg.h = 240;
    cpu.reg.l = 3;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[12145] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 71);
    CHECK(cpu.reg.b == 253);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 112);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 240);
    CHECK(cpu.reg.l == 3);
    CHECK(cpu.reg.pc == 12146);
    // CHECK(cpu.reg.sp == 28484);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12145] == 0);
}

TEST_CASE( "00 00EF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44991;
    cpu.reg.sp = 31546;
    cpu.reg.a = 18;
    cpu.reg.b = 59;
    cpu.reg.c = 92;
    cpu.reg.d = 237;
    cpu.reg.e = 28;
    cpu.reg.f = 16;
    cpu.reg.h = 125;
    cpu.reg.l = 155;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44991] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 59);
    CHECK(cpu.reg.c == 92);
    CHECK(cpu.reg.d == 237);
    CHECK(cpu.reg.e == 28);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 155);
    CHECK(cpu.reg.pc == 44992);
    // CHECK(cpu.reg.sp == 31546);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44991] == 0);
}

TEST_CASE( "00 00F0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41558;
    cpu.reg.sp = 50280;
    cpu.reg.a = 45;
    cpu.reg.b = 157;
    cpu.reg.c = 235;
    cpu.reg.d = 0;
    cpu.reg.e = 131;
    cpu.reg.f = 176;
    cpu.reg.h = 230;
    cpu.reg.l = 136;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[41558] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 45);
    CHECK(cpu.reg.b == 157);
    CHECK(cpu.reg.c == 235);
    CHECK(cpu.reg.d == 0);
    CHECK(cpu.reg.e == 131);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 230);
    CHECK(cpu.reg.l == 136);
    CHECK(cpu.reg.pc == 41559);
    // CHECK(cpu.reg.sp == 50280);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41558] == 0);
}

TEST_CASE( "00 00F1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28019;
    cpu.reg.sp = 38996;
    cpu.reg.a = 205;
    cpu.reg.b = 190;
    cpu.reg.c = 28;
    cpu.reg.d = 135;
    cpu.reg.e = 147;
    cpu.reg.f = 208;
    cpu.reg.h = 118;
    cpu.reg.l = 117;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[28019] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 205);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 28);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 147);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 118);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 28020);
    // CHECK(cpu.reg.sp == 38996);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28019] == 0);
}

TEST_CASE( "00 00F2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61863;
    cpu.reg.sp = 18874;
    cpu.reg.a = 244;
    cpu.reg.b = 72;
    cpu.reg.c = 92;
    cpu.reg.d = 216;
    cpu.reg.e = 141;
    cpu.reg.f = 192;
    cpu.reg.h = 127;
    cpu.reg.l = 189;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[61863] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 92);
    CHECK(cpu.reg.d == 216);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 127);
    CHECK(cpu.reg.l == 189);
    CHECK(cpu.reg.pc == 61864);
    // CHECK(cpu.reg.sp == 18874);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61863] == 0);
}

TEST_CASE( "00 00F3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5048;
    cpu.reg.sp = 17096;
    cpu.reg.a = 243;
    cpu.reg.b = 173;
    cpu.reg.c = 96;
    cpu.reg.d = 145;
    cpu.reg.e = 171;
    cpu.reg.f = 144;
    cpu.reg.h = 215;
    cpu.reg.l = 52;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[5048] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 243);
    CHECK(cpu.reg.b == 173);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 145);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 215);
    CHECK(cpu.reg.l == 52);
    CHECK(cpu.reg.pc == 5049);
    // CHECK(cpu.reg.sp == 17096);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5048] == 0);
}

TEST_CASE( "00 00F4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38824;
    cpu.reg.sp = 55252;
    cpu.reg.a = 29;
    cpu.reg.b = 240;
    cpu.reg.c = 31;
    cpu.reg.d = 37;
    cpu.reg.e = 184;
    cpu.reg.f = 176;
    cpu.reg.h = 196;
    cpu.reg.l = 134;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[38824] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 240);
    CHECK(cpu.reg.c == 31);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 184);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 196);
    CHECK(cpu.reg.l == 134);
    CHECK(cpu.reg.pc == 38825);
    // CHECK(cpu.reg.sp == 55252);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[38824] == 0);
}

TEST_CASE( "00 00F5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40504;
    cpu.reg.sp = 47131;
    cpu.reg.a = 228;
    cpu.reg.b = 55;
    cpu.reg.c = 86;
    cpu.reg.d = 117;
    cpu.reg.e = 83;
    cpu.reg.f = 112;
    cpu.reg.h = 12;
    cpu.reg.l = 168;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[40504] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 228);
    CHECK(cpu.reg.b == 55);
    CHECK(cpu.reg.c == 86);
    CHECK(cpu.reg.d == 117);
    CHECK(cpu.reg.e == 83);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 168);
    CHECK(cpu.reg.pc == 40505);
    // CHECK(cpu.reg.sp == 47131);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40504] == 0);
}

TEST_CASE( "00 00F6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22550;
    cpu.reg.sp = 11753;
    cpu.reg.a = 206;
    cpu.reg.b = 57;
    cpu.reg.c = 233;
    cpu.reg.d = 5;
    cpu.reg.e = 55;
    cpu.reg.f = 160;
    cpu.reg.h = 92;
    cpu.reg.l = 213;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[22550] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 57);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 5);
    CHECK(cpu.reg.e == 55);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 92);
    CHECK(cpu.reg.l == 213);
    CHECK(cpu.reg.pc == 22551);
    // CHECK(cpu.reg.sp == 11753);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22550] == 0);
}

TEST_CASE( "00 00F7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13580;
    cpu.reg.sp = 32165;
    cpu.reg.a = 150;
    cpu.reg.b = 112;
    cpu.reg.c = 60;
    cpu.reg.d = 244;
    cpu.reg.e = 203;
    cpu.reg.f = 96;
    cpu.reg.h = 37;
    cpu.reg.l = 93;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[13580] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 150);
    CHECK(cpu.reg.b == 112);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 37);
    CHECK(cpu.reg.l == 93);
    CHECK(cpu.reg.pc == 13581);
    // CHECK(cpu.reg.sp == 32165);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13580] == 0);
}

TEST_CASE( "00 00F8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33276;
    cpu.reg.sp = 12365;
    cpu.reg.a = 69;
    cpu.reg.b = 242;
    cpu.reg.c = 215;
    cpu.reg.d = 146;
    cpu.reg.e = 98;
    cpu.reg.f = 224;
    cpu.reg.h = 178;
    cpu.reg.l = 79;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[33276] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 242);
    CHECK(cpu.reg.c == 215);
    CHECK(cpu.reg.d == 146);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 79);
    CHECK(cpu.reg.pc == 33277);
    // CHECK(cpu.reg.sp == 12365);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33276] == 0);
}

TEST_CASE( "00 00F9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32648;
    cpu.reg.sp = 26971;
    cpu.reg.a = 150;
    cpu.reg.b = 181;
    cpu.reg.c = 70;
    cpu.reg.d = 107;
    cpu.reg.e = 172;
    cpu.reg.f = 176;
    cpu.reg.h = 107;
    cpu.reg.l = 16;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32648] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 150);
    CHECK(cpu.reg.b == 181);
    CHECK(cpu.reg.c == 70);
    CHECK(cpu.reg.d == 107);
    CHECK(cpu.reg.e == 172);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 107);
    CHECK(cpu.reg.l == 16);
    CHECK(cpu.reg.pc == 32649);
    // CHECK(cpu.reg.sp == 26971);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32648] == 0);
}

TEST_CASE( "00 00FA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38886;
    cpu.reg.sp = 52131;
    cpu.reg.a = 170;
    cpu.reg.b = 208;
    cpu.reg.c = 244;
    cpu.reg.d = 101;
    cpu.reg.e = 59;
    cpu.reg.f = 48;
    cpu.reg.h = 101;
    cpu.reg.l = 22;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[38886] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 170);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 244);
    CHECK(cpu.reg.d == 101);
    CHECK(cpu.reg.e == 59);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 101);
    CHECK(cpu.reg.l == 22);
    CHECK(cpu.reg.pc == 38887);
    // CHECK(cpu.reg.sp == 52131);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[38886] == 0);
}

TEST_CASE( "00 00FB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33249;
    cpu.reg.sp = 35545;
    cpu.reg.a = 127;
    cpu.reg.b = 240;
    cpu.reg.c = 188;
    cpu.reg.d = 199;
    cpu.reg.e = 88;
    cpu.reg.f = 224;
    cpu.reg.h = 193;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[33249] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 127);
    CHECK(cpu.reg.b == 240);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 199);
    CHECK(cpu.reg.e == 88);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 193);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 33250);
    // CHECK(cpu.reg.sp == 35545);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33249] == 0);
}

TEST_CASE( "00 00FC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3878;
    cpu.reg.sp = 24888;
    cpu.reg.a = 104;
    cpu.reg.b = 208;
    cpu.reg.c = 171;
    cpu.reg.d = 66;
    cpu.reg.e = 51;
    cpu.reg.f = 32;
    cpu.reg.h = 171;
    cpu.reg.l = 249;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[3878] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 104);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 171);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 51);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 171);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 3879);
    // CHECK(cpu.reg.sp == 24888);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3878] == 0);
}

TEST_CASE( "00 00FD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50350;
    cpu.reg.sp = 6326;
    cpu.reg.a = 138;
    cpu.reg.b = 76;
    cpu.reg.c = 207;
    cpu.reg.d = 133;
    cpu.reg.e = 97;
    cpu.reg.f = 16;
    cpu.reg.h = 246;
    cpu.reg.l = 226;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[50350] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 138);
    CHECK(cpu.reg.b == 76);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 133);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 246);
    CHECK(cpu.reg.l == 226);
    CHECK(cpu.reg.pc == 50351);
    // CHECK(cpu.reg.sp == 6326);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50350] == 0);
}

TEST_CASE( "00 00FE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7677;
    cpu.reg.sp = 58382;
    cpu.reg.a = 131;
    cpu.reg.b = 49;
    cpu.reg.c = 35;
    cpu.reg.d = 55;
    cpu.reg.e = 37;
    cpu.reg.f = 80;
    cpu.reg.h = 122;
    cpu.reg.l = 98;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[7677] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 131);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 35);
    CHECK(cpu.reg.d == 55);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 122);
    CHECK(cpu.reg.l == 98);
    CHECK(cpu.reg.pc == 7678);
    // CHECK(cpu.reg.sp == 58382);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7677] == 0);
}

TEST_CASE( "00 00FF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58576;
    cpu.reg.sp = 12921;
    cpu.reg.a = 247;
    cpu.reg.b = 210;
    cpu.reg.c = 192;
    cpu.reg.d = 197;
    cpu.reg.e = 48;
    cpu.reg.f = 128;
    cpu.reg.h = 120;
    cpu.reg.l = 117;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[58576] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 210);
    CHECK(cpu.reg.c == 192);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 58577);
    // CHECK(cpu.reg.sp == 12921);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58576] == 0);
}

TEST_CASE( "00 0100", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26334;
    cpu.reg.sp = 12034;
    cpu.reg.a = 33;
    cpu.reg.b = 92;
    cpu.reg.c = 239;
    cpu.reg.d = 37;
    cpu.reg.e = 201;
    cpu.reg.f = 64;
    cpu.reg.h = 182;
    cpu.reg.l = 180;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[26334] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 33);
    CHECK(cpu.reg.b == 92);
    CHECK(cpu.reg.c == 239);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 201);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 180);
    CHECK(cpu.reg.pc == 26335);
    // CHECK(cpu.reg.sp == 12034);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26334] == 0);
}

TEST_CASE( "00 0101", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43632;
    cpu.reg.sp = 49186;
    cpu.reg.a = 29;
    cpu.reg.b = 186;
    cpu.reg.c = 250;
    cpu.reg.d = 79;
    cpu.reg.e = 236;
    cpu.reg.f = 160;
    cpu.reg.h = 7;
    cpu.reg.l = 46;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[43632] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 186);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 7);
    CHECK(cpu.reg.l == 46);
    CHECK(cpu.reg.pc == 43633);
    // CHECK(cpu.reg.sp == 49186);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43632] == 0);
}

TEST_CASE( "00 0102", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43636;
    cpu.reg.sp = 49977;
    cpu.reg.a = 88;
    cpu.reg.b = 73;
    cpu.reg.c = 74;
    cpu.reg.d = 243;
    cpu.reg.e = 198;
    cpu.reg.f = 0;
    cpu.reg.h = 251;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43636] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 88);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 74);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 198);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 251);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 43637);
    // CHECK(cpu.reg.sp == 49977);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43636] == 0);
}

TEST_CASE( "00 0103", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29229;
    cpu.reg.sp = 21625;
    cpu.reg.a = 128;
    cpu.reg.b = 77;
    cpu.reg.c = 187;
    cpu.reg.d = 153;
    cpu.reg.e = 56;
    cpu.reg.f = 208;
    cpu.reg.h = 107;
    cpu.reg.l = 124;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29229] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 77);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 153);
    CHECK(cpu.reg.e == 56);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 107);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 29230);
    // CHECK(cpu.reg.sp == 21625);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29229] == 0);
}

TEST_CASE( "00 0104", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36886;
    cpu.reg.sp = 33727;
    cpu.reg.a = 27;
    cpu.reg.b = 156;
    cpu.reg.c = 4;
    cpu.reg.d = 82;
    cpu.reg.e = 150;
    cpu.reg.f = 144;
    cpu.reg.h = 186;
    cpu.reg.l = 143;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[36886] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 27);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 4);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 150);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 143);
    CHECK(cpu.reg.pc == 36887);
    // CHECK(cpu.reg.sp == 33727);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36886] == 0);
}

TEST_CASE( "00 0105", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61296;
    cpu.reg.sp = 55902;
    cpu.reg.a = 166;
    cpu.reg.b = 163;
    cpu.reg.c = 123;
    cpu.reg.d = 173;
    cpu.reg.e = 17;
    cpu.reg.f = 32;
    cpu.reg.h = 34;
    cpu.reg.l = 14;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61296] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 166);
    CHECK(cpu.reg.b == 163);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 173);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 34);
    CHECK(cpu.reg.l == 14);
    CHECK(cpu.reg.pc == 61297);
    // CHECK(cpu.reg.sp == 55902);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61296] == 0);
}

TEST_CASE( "00 0106", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28202;
    cpu.reg.sp = 36260;
    cpu.reg.a = 249;
    cpu.reg.b = 32;
    cpu.reg.c = 17;
    cpu.reg.d = 139;
    cpu.reg.e = 250;
    cpu.reg.f = 240;
    cpu.reg.h = 213;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[28202] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 249);
    CHECK(cpu.reg.b == 32);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 139);
    CHECK(cpu.reg.e == 250);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 213);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 28203);
    // CHECK(cpu.reg.sp == 36260);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28202] == 0);
}

TEST_CASE( "00 0107", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42946;
    cpu.reg.sp = 50720;
    cpu.reg.a = 215;
    cpu.reg.b = 66;
    cpu.reg.c = 59;
    cpu.reg.d = 184;
    cpu.reg.e = 2;
    cpu.reg.f = 192;
    cpu.reg.h = 50;
    cpu.reg.l = 120;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[42946] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 59);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 2);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 50);
    CHECK(cpu.reg.l == 120);
    CHECK(cpu.reg.pc == 42947);
    // CHECK(cpu.reg.sp == 50720);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42946] == 0);
}

TEST_CASE( "00 0108", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57164;
    cpu.reg.sp = 52831;
    cpu.reg.a = 250;
    cpu.reg.b = 155;
    cpu.reg.c = 123;
    cpu.reg.d = 13;
    cpu.reg.e = 166;
    cpu.reg.f = 80;
    cpu.reg.h = 104;
    cpu.reg.l = 104;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[57164] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 250);
    CHECK(cpu.reg.b == 155);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 13);
    CHECK(cpu.reg.e == 166);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 104);
    CHECK(cpu.reg.l == 104);
    CHECK(cpu.reg.pc == 57165);
    // CHECK(cpu.reg.sp == 52831);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57164] == 0);
}

TEST_CASE( "00 0109", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33986;
    cpu.reg.sp = 42151;
    cpu.reg.a = 94;
    cpu.reg.b = 187;
    cpu.reg.c = 142;
    cpu.reg.d = 189;
    cpu.reg.e = 255;
    cpu.reg.f = 144;
    cpu.reg.h = 219;
    cpu.reg.l = 20;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[33986] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 187);
    CHECK(cpu.reg.c == 142);
    CHECK(cpu.reg.d == 189);
    CHECK(cpu.reg.e == 255);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 219);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 33987);
    // CHECK(cpu.reg.sp == 42151);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[33986] == 0);
}

TEST_CASE( "00 010A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21511;
    cpu.reg.sp = 54722;
    cpu.reg.a = 149;
    cpu.reg.b = 0;
    cpu.reg.c = 85;
    cpu.reg.d = 62;
    cpu.reg.e = 210;
    cpu.reg.f = 176;
    cpu.reg.h = 164;
    cpu.reg.l = 78;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[21511] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 149);
    CHECK(cpu.reg.b == 0);
    CHECK(cpu.reg.c == 85);
    CHECK(cpu.reg.d == 62);
    CHECK(cpu.reg.e == 210);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 78);
    CHECK(cpu.reg.pc == 21512);
    // CHECK(cpu.reg.sp == 54722);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21511] == 0);
}

TEST_CASE( "00 010B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38640;
    cpu.reg.sp = 41022;
    cpu.reg.a = 70;
    cpu.reg.b = 36;
    cpu.reg.c = 149;
    cpu.reg.d = 15;
    cpu.reg.e = 3;
    cpu.reg.f = 0;
    cpu.reg.h = 9;
    cpu.reg.l = 73;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[38640] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 70);
    CHECK(cpu.reg.b == 36);
    CHECK(cpu.reg.c == 149);
    CHECK(cpu.reg.d == 15);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 9);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 38641);
    // CHECK(cpu.reg.sp == 41022);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[38640] == 0);
}

TEST_CASE( "00 010C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39340;
    cpu.reg.sp = 12462;
    cpu.reg.a = 124;
    cpu.reg.b = 231;
    cpu.reg.c = 71;
    cpu.reg.d = 212;
    cpu.reg.e = 168;
    cpu.reg.f = 64;
    cpu.reg.h = 138;
    cpu.reg.l = 158;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[39340] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 124);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 138);
    CHECK(cpu.reg.l == 158);
    CHECK(cpu.reg.pc == 39341);
    // CHECK(cpu.reg.sp == 12462);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39340] == 0);
}

TEST_CASE( "00 010D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8820;
    cpu.reg.sp = 62651;
    cpu.reg.a = 48;
    cpu.reg.b = 65;
    cpu.reg.c = 49;
    cpu.reg.d = 57;
    cpu.reg.e = 61;
    cpu.reg.f = 224;
    cpu.reg.h = 120;
    cpu.reg.l = 158;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[8820] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 65);
    CHECK(cpu.reg.c == 49);
    CHECK(cpu.reg.d == 57);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 158);
    CHECK(cpu.reg.pc == 8821);
    // CHECK(cpu.reg.sp == 62651);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8820] == 0);
}

TEST_CASE( "00 010E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62175;
    cpu.reg.sp = 28324;
    cpu.reg.a = 42;
    cpu.reg.b = 210;
    cpu.reg.c = 45;
    cpu.reg.d = 169;
    cpu.reg.e = 122;
    cpu.reg.f = 128;
    cpu.reg.h = 40;
    cpu.reg.l = 138;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62175] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 210);
    CHECK(cpu.reg.c == 45);
    CHECK(cpu.reg.d == 169);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 40);
    CHECK(cpu.reg.l == 138);
    CHECK(cpu.reg.pc == 62176);
    // CHECK(cpu.reg.sp == 28324);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62175] == 0);
}

TEST_CASE( "00 010F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10458;
    cpu.reg.sp = 36488;
    cpu.reg.a = 210;
    cpu.reg.b = 104;
    cpu.reg.c = 236;
    cpu.reg.d = 123;
    cpu.reg.e = 0;
    cpu.reg.f = 32;
    cpu.reg.h = 52;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[10458] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 104);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 0);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 52);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 10459);
    // CHECK(cpu.reg.sp == 36488);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10458] == 0);
}

TEST_CASE( "00 0110", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54058;
    cpu.reg.sp = 58928;
    cpu.reg.a = 199;
    cpu.reg.b = 73;
    cpu.reg.c = 137;
    cpu.reg.d = 121;
    cpu.reg.e = 86;
    cpu.reg.f = 192;
    cpu.reg.h = 60;
    cpu.reg.l = 200;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54058] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 199);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 137);
    CHECK(cpu.reg.d == 121);
    CHECK(cpu.reg.e == 86);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 54059);
    // CHECK(cpu.reg.sp == 58928);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54058] == 0);
}

TEST_CASE( "00 0111", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42917;
    cpu.reg.sp = 26089;
    cpu.reg.a = 172;
    cpu.reg.b = 175;
    cpu.reg.c = 115;
    cpu.reg.d = 196;
    cpu.reg.e = 20;
    cpu.reg.f = 48;
    cpu.reg.h = 146;
    cpu.reg.l = 59;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[42917] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 172);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 115);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 20);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 146);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 42918);
    // CHECK(cpu.reg.sp == 26089);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42917] == 0);
}

TEST_CASE( "00 0112", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7953;
    cpu.reg.sp = 36887;
    cpu.reg.a = 184;
    cpu.reg.b = 253;
    cpu.reg.c = 119;
    cpu.reg.d = 217;
    cpu.reg.e = 87;
    cpu.reg.f = 32;
    cpu.reg.h = 109;
    cpu.reg.l = 163;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[7953] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 253);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 217);
    CHECK(cpu.reg.e == 87);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 109);
    CHECK(cpu.reg.l == 163);
    CHECK(cpu.reg.pc == 7954);
    // CHECK(cpu.reg.sp == 36887);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7953] == 0);
}

TEST_CASE( "00 0113", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18831;
    cpu.reg.sp = 18743;
    cpu.reg.a = 50;
    cpu.reg.b = 166;
    cpu.reg.c = 241;
    cpu.reg.d = 201;
    cpu.reg.e = 34;
    cpu.reg.f = 0;
    cpu.reg.h = 16;
    cpu.reg.l = 2;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[18831] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 166);
    CHECK(cpu.reg.c == 241);
    CHECK(cpu.reg.d == 201);
    CHECK(cpu.reg.e == 34);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 16);
    CHECK(cpu.reg.l == 2);
    CHECK(cpu.reg.pc == 18832);
    // CHECK(cpu.reg.sp == 18743);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18831] == 0);
}

TEST_CASE( "00 0114", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62550;
    cpu.reg.sp = 47572;
    cpu.reg.a = 201;
    cpu.reg.b = 103;
    cpu.reg.c = 51;
    cpu.reg.d = 223;
    cpu.reg.e = 91;
    cpu.reg.f = 176;
    cpu.reg.h = 178;
    cpu.reg.l = 101;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62550] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 201);
    CHECK(cpu.reg.b == 103);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 91);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 62551);
    // CHECK(cpu.reg.sp == 47572);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62550] == 0);
}

TEST_CASE( "00 0115", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61568;
    cpu.reg.sp = 2806;
    cpu.reg.a = 41;
    cpu.reg.b = 93;
    cpu.reg.c = 23;
    cpu.reg.d = 186;
    cpu.reg.e = 5;
    cpu.reg.f = 192;
    cpu.reg.h = 247;
    cpu.reg.l = 61;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61568] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 41);
    CHECK(cpu.reg.b == 93);
    CHECK(cpu.reg.c == 23);
    CHECK(cpu.reg.d == 186);
    CHECK(cpu.reg.e == 5);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 61569);
    // CHECK(cpu.reg.sp == 2806);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61568] == 0);
}

TEST_CASE( "00 0116", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5523;
    cpu.reg.sp = 2962;
    cpu.reg.a = 89;
    cpu.reg.b = 40;
    cpu.reg.c = 58;
    cpu.reg.d = 216;
    cpu.reg.e = 99;
    cpu.reg.f = 224;
    cpu.reg.h = 19;
    cpu.reg.l = 128;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[5523] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 89);
    CHECK(cpu.reg.b == 40);
    CHECK(cpu.reg.c == 58);
    CHECK(cpu.reg.d == 216);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 19);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 5524);
    // CHECK(cpu.reg.sp == 2962);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5523] == 0);
}

TEST_CASE( "00 0117", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57315;
    cpu.reg.sp = 15878;
    cpu.reg.a = 128;
    cpu.reg.b = 235;
    cpu.reg.c = 225;
    cpu.reg.d = 231;
    cpu.reg.e = 10;
    cpu.reg.f = 144;
    cpu.reg.h = 211;
    cpu.reg.l = 99;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[57315] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 225);
    CHECK(cpu.reg.d == 231);
    CHECK(cpu.reg.e == 10);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 211);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 57316);
    // CHECK(cpu.reg.sp == 15878);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57315] == 0);
}

TEST_CASE( "00 0118", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14324;
    cpu.reg.sp = 51822;
    cpu.reg.a = 158;
    cpu.reg.b = 2;
    cpu.reg.c = 138;
    cpu.reg.d = 27;
    cpu.reg.e = 225;
    cpu.reg.f = 144;
    cpu.reg.h = 242;
    cpu.reg.l = 37;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[14324] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 158);
    CHECK(cpu.reg.b == 2);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 27);
    CHECK(cpu.reg.e == 225);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 37);
    CHECK(cpu.reg.pc == 14325);
    // CHECK(cpu.reg.sp == 51822);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14324] == 0);
}

TEST_CASE( "00 0119", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1708;
    cpu.reg.sp = 56311;
    cpu.reg.a = 223;
    cpu.reg.b = 195;
    cpu.reg.c = 55;
    cpu.reg.d = 244;
    cpu.reg.e = 103;
    cpu.reg.f = 80;
    cpu.reg.h = 239;
    cpu.reg.l = 188;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[1708] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 223);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 55);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 103);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 239);
    CHECK(cpu.reg.l == 188);
    CHECK(cpu.reg.pc == 1709);
    // CHECK(cpu.reg.sp == 56311);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1708] == 0);
}

TEST_CASE( "00 011A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39558;
    cpu.reg.sp = 54678;
    cpu.reg.a = 69;
    cpu.reg.b = 111;
    cpu.reg.c = 255;
    cpu.reg.d = 223;
    cpu.reg.e = 203;
    cpu.reg.f = 16;
    cpu.reg.h = 202;
    cpu.reg.l = 83;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[39558] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 111);
    CHECK(cpu.reg.c == 255);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 202);
    CHECK(cpu.reg.l == 83);
    CHECK(cpu.reg.pc == 39559);
    // CHECK(cpu.reg.sp == 54678);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39558] == 0);
}

TEST_CASE( "00 011B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65043;
    cpu.reg.sp = 7100;
    cpu.reg.a = 247;
    cpu.reg.b = 43;
    cpu.reg.c = 27;
    cpu.reg.d = 134;
    cpu.reg.e = 37;
    cpu.reg.f = 32;
    cpu.reg.h = 71;
    cpu.reg.l = 177;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[65043] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 43);
    CHECK(cpu.reg.c == 27);
    CHECK(cpu.reg.d == 134);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 177);
    CHECK(cpu.reg.pc == 65044);
    // CHECK(cpu.reg.sp == 7100);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[65043] == 0);
}

TEST_CASE( "00 011C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42856;
    cpu.reg.sp = 62970;
    cpu.reg.a = 151;
    cpu.reg.b = 253;
    cpu.reg.c = 248;
    cpu.reg.d = 109;
    cpu.reg.e = 81;
    cpu.reg.f = 32;
    cpu.reg.h = 57;
    cpu.reg.l = 14;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[42856] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 151);
    CHECK(cpu.reg.b == 253);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 109);
    CHECK(cpu.reg.e == 81);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 57);
    CHECK(cpu.reg.l == 14);
    CHECK(cpu.reg.pc == 42857);
    // CHECK(cpu.reg.sp == 62970);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42856] == 0);
}

TEST_CASE( "00 011D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10164;
    cpu.reg.sp = 41167;
    cpu.reg.a = 184;
    cpu.reg.b = 226;
    cpu.reg.c = 76;
    cpu.reg.d = 151;
    cpu.reg.e = 240;
    cpu.reg.f = 64;
    cpu.reg.h = 32;
    cpu.reg.l = 151;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[10164] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 226);
    CHECK(cpu.reg.c == 76);
    CHECK(cpu.reg.d == 151);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 32);
    CHECK(cpu.reg.l == 151);
    CHECK(cpu.reg.pc == 10165);
    // CHECK(cpu.reg.sp == 41167);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10164] == 0);
}

TEST_CASE( "00 011E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63943;
    cpu.reg.sp = 58580;
    cpu.reg.a = 62;
    cpu.reg.b = 115;
    cpu.reg.c = 221;
    cpu.reg.d = 131;
    cpu.reg.e = 104;
    cpu.reg.f = 16;
    cpu.reg.h = 234;
    cpu.reg.l = 73;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63943] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 115);
    CHECK(cpu.reg.c == 221);
    CHECK(cpu.reg.d == 131);
    CHECK(cpu.reg.e == 104);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 234);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 63944);
    // CHECK(cpu.reg.sp == 58580);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63943] == 0);
}

TEST_CASE( "00 011F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57059;
    cpu.reg.sp = 47221;
    cpu.reg.a = 113;
    cpu.reg.b = 190;
    cpu.reg.c = 16;
    cpu.reg.d = 48;
    cpu.reg.e = 47;
    cpu.reg.f = 0;
    cpu.reg.h = 48;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[57059] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 113);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 47);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 48);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 57060);
    // CHECK(cpu.reg.sp == 47221);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57059] == 0);
}

TEST_CASE( "00 0120", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52606;
    cpu.reg.sp = 49223;
    cpu.reg.a = 131;
    cpu.reg.b = 215;
    cpu.reg.c = 50;
    cpu.reg.d = 39;
    cpu.reg.e = 188;
    cpu.reg.f = 32;
    cpu.reg.h = 167;
    cpu.reg.l = 24;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[52606] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 131);
    CHECK(cpu.reg.b == 215);
    CHECK(cpu.reg.c == 50);
    CHECK(cpu.reg.d == 39);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 24);
    CHECK(cpu.reg.pc == 52607);
    // CHECK(cpu.reg.sp == 49223);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52606] == 0);
}

TEST_CASE( "00 0121", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25706;
    cpu.reg.sp = 37289;
    cpu.reg.a = 153;
    cpu.reg.b = 238;
    cpu.reg.c = 44;
    cpu.reg.d = 246;
    cpu.reg.e = 81;
    cpu.reg.f = 80;
    cpu.reg.h = 130;
    cpu.reg.l = 121;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25706] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 44);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 81);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 130);
    CHECK(cpu.reg.l == 121);
    CHECK(cpu.reg.pc == 25707);
    // CHECK(cpu.reg.sp == 37289);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25706] == 0);
}

TEST_CASE( "00 0122", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16775;
    cpu.reg.sp = 52918;
    cpu.reg.a = 94;
    cpu.reg.b = 195;
    cpu.reg.c = 166;
    cpu.reg.d = 127;
    cpu.reg.e = 194;
    cpu.reg.f = 176;
    cpu.reg.h = 55;
    cpu.reg.l = 124;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[16775] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 166);
    CHECK(cpu.reg.d == 127);
    CHECK(cpu.reg.e == 194);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 55);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 16776);
    // CHECK(cpu.reg.sp == 52918);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16775] == 0);
}

TEST_CASE( "00 0123", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32066;
    cpu.reg.sp = 21264;
    cpu.reg.a = 57;
    cpu.reg.b = 175;
    cpu.reg.c = 11;
    cpu.reg.d = 168;
    cpu.reg.e = 186;
    cpu.reg.f = 240;
    cpu.reg.h = 117;
    cpu.reg.l = 74;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32066] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 57);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 11);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 186);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 117);
    CHECK(cpu.reg.l == 74);
    CHECK(cpu.reg.pc == 32067);
    // CHECK(cpu.reg.sp == 21264);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32066] == 0);
}

TEST_CASE( "00 0124", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54480;
    cpu.reg.sp = 3168;
    cpu.reg.a = 163;
    cpu.reg.b = 185;
    cpu.reg.c = 12;
    cpu.reg.d = 21;
    cpu.reg.e = 178;
    cpu.reg.f = 192;
    cpu.reg.h = 56;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54480] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 163);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 21);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 56);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 54481);
    // CHECK(cpu.reg.sp == 3168);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54480] == 0);
}

TEST_CASE( "00 0125", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9693;
    cpu.reg.sp = 65354;
    cpu.reg.a = 8;
    cpu.reg.b = 191;
    cpu.reg.c = 94;
    cpu.reg.d = 71;
    cpu.reg.e = 97;
    cpu.reg.f = 80;
    cpu.reg.h = 139;
    cpu.reg.l = 77;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9693] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 94);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 77);
    CHECK(cpu.reg.pc == 9694);
    // CHECK(cpu.reg.sp == 65354);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9693] == 0);
}

TEST_CASE( "00 0126", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36937;
    cpu.reg.sp = 10788;
    cpu.reg.a = 34;
    cpu.reg.b = 226;
    cpu.reg.c = 90;
    cpu.reg.d = 170;
    cpu.reg.e = 78;
    cpu.reg.f = 192;
    cpu.reg.h = 122;
    cpu.reg.l = 94;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[36937] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 34);
    CHECK(cpu.reg.b == 226);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 170);
    CHECK(cpu.reg.e == 78);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 122);
    CHECK(cpu.reg.l == 94);
    CHECK(cpu.reg.pc == 36938);
    // CHECK(cpu.reg.sp == 10788);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36937] == 0);
}

TEST_CASE( "00 0127", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26467;
    cpu.reg.sp = 18333;
    cpu.reg.a = 12;
    cpu.reg.b = 155;
    cpu.reg.c = 82;
    cpu.reg.d = 235;
    cpu.reg.e = 113;
    cpu.reg.f = 48;
    cpu.reg.h = 245;
    cpu.reg.l = 125;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[26467] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 12);
    CHECK(cpu.reg.b == 155);
    CHECK(cpu.reg.c == 82);
    CHECK(cpu.reg.d == 235);
    CHECK(cpu.reg.e == 113);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 125);
    CHECK(cpu.reg.pc == 26468);
    // CHECK(cpu.reg.sp == 18333);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26467] == 0);
}

TEST_CASE( "00 0128", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11522;
    cpu.reg.sp = 44773;
    cpu.reg.a = 156;
    cpu.reg.b = 9;
    cpu.reg.c = 101;
    cpu.reg.d = 221;
    cpu.reg.e = 133;
    cpu.reg.f = 176;
    cpu.reg.h = 245;
    cpu.reg.l = 103;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[11522] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 156);
    CHECK(cpu.reg.b == 9);
    CHECK(cpu.reg.c == 101);
    CHECK(cpu.reg.d == 221);
    CHECK(cpu.reg.e == 133);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 103);
    CHECK(cpu.reg.pc == 11523);
    // CHECK(cpu.reg.sp == 44773);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11522] == 0);
}

TEST_CASE( "00 0129", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11727;
    cpu.reg.sp = 13565;
    cpu.reg.a = 2;
    cpu.reg.b = 205;
    cpu.reg.c = 225;
    cpu.reg.d = 251;
    cpu.reg.e = 216;
    cpu.reg.f = 128;
    cpu.reg.h = 137;
    cpu.reg.l = 16;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[11727] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 225);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 216);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 137);
    CHECK(cpu.reg.l == 16);
    CHECK(cpu.reg.pc == 11728);
    // CHECK(cpu.reg.sp == 13565);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11727] == 0);
}

TEST_CASE( "00 012A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56575;
    cpu.reg.sp = 31167;
    cpu.reg.a = 220;
    cpu.reg.b = 11;
    cpu.reg.c = 34;
    cpu.reg.d = 251;
    cpu.reg.e = 169;
    cpu.reg.f = 176;
    cpu.reg.h = 152;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56575] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 220);
    CHECK(cpu.reg.b == 11);
    CHECK(cpu.reg.c == 34);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 152);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 56576);
    // CHECK(cpu.reg.sp == 31167);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56575] == 0);
}

TEST_CASE( "00 012B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43481;
    cpu.reg.sp = 59842;
    cpu.reg.a = 168;
    cpu.reg.b = 145;
    cpu.reg.c = 201;
    cpu.reg.d = 115;
    cpu.reg.e = 206;
    cpu.reg.f = 208;
    cpu.reg.h = 186;
    cpu.reg.l = 73;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[43481] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 168);
    CHECK(cpu.reg.b == 145);
    CHECK(cpu.reg.c == 201);
    CHECK(cpu.reg.d == 115);
    CHECK(cpu.reg.e == 206);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 43482);
    // CHECK(cpu.reg.sp == 59842);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43481] == 0);
}

TEST_CASE( "00 012C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9549;
    cpu.reg.sp = 62047;
    cpu.reg.a = 247;
    cpu.reg.b = 49;
    cpu.reg.c = 23;
    cpu.reg.d = 130;
    cpu.reg.e = 9;
    cpu.reg.f = 32;
    cpu.reg.h = 80;
    cpu.reg.l = 206;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[9549] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 23);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 9);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 206);
    CHECK(cpu.reg.pc == 9550);
    // CHECK(cpu.reg.sp == 62047);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9549] == 0);
}

TEST_CASE( "00 012D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11920;
    cpu.reg.sp = 5380;
    cpu.reg.a = 208;
    cpu.reg.b = 183;
    cpu.reg.c = 40;
    cpu.reg.d = 90;
    cpu.reg.e = 25;
    cpu.reg.f = 0;
    cpu.reg.h = 156;
    cpu.reg.l = 152;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[11920] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 40);
    CHECK(cpu.reg.d == 90);
    CHECK(cpu.reg.e == 25);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 152);
    CHECK(cpu.reg.pc == 11921);
    // CHECK(cpu.reg.sp == 5380);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11920] == 0);
}

TEST_CASE( "00 012E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 280;
    cpu.reg.sp = 6622;
    cpu.reg.a = 124;
    cpu.reg.b = 197;
    cpu.reg.c = 216;
    cpu.reg.d = 119;
    cpu.reg.e = 49;
    cpu.reg.f = 32;
    cpu.reg.h = 94;
    cpu.reg.l = 101;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[280] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 124);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 119);
    CHECK(cpu.reg.e == 49);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 94);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 281);
    // CHECK(cpu.reg.sp == 6622);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[280] == 0);
}

TEST_CASE( "00 012F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17918;
    cpu.reg.sp = 11961;
    cpu.reg.a = 142;
    cpu.reg.b = 224;
    cpu.reg.c = 183;
    cpu.reg.d = 222;
    cpu.reg.e = 225;
    cpu.reg.f = 208;
    cpu.reg.h = 125;
    cpu.reg.l = 187;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[17918] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 142);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 222);
    CHECK(cpu.reg.e == 225);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 17919);
    // CHECK(cpu.reg.sp == 11961);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17918] == 0);
}

TEST_CASE( "00 0130", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2192;
    cpu.reg.sp = 52585;
    cpu.reg.a = 157;
    cpu.reg.b = 156;
    cpu.reg.c = 104;
    cpu.reg.d = 135;
    cpu.reg.e = 245;
    cpu.reg.f = 176;
    cpu.reg.h = 156;
    cpu.reg.l = 233;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[2192] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 157);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 104);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 245);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 2193);
    // CHECK(cpu.reg.sp == 52585);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2192] == 0);
}

TEST_CASE( "00 0131", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41322;
    cpu.reg.sp = 19414;
    cpu.reg.a = 118;
    cpu.reg.b = 94;
    cpu.reg.c = 129;
    cpu.reg.d = 239;
    cpu.reg.e = 226;
    cpu.reg.f = 96;
    cpu.reg.h = 112;
    cpu.reg.l = 182;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[41322] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 94);
    CHECK(cpu.reg.c == 129);
    CHECK(cpu.reg.d == 239);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 41323);
    // CHECK(cpu.reg.sp == 19414);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41322] == 0);
}

TEST_CASE( "00 0132", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35215;
    cpu.reg.sp = 43496;
    cpu.reg.a = 141;
    cpu.reg.b = 76;
    cpu.reg.c = 255;
    cpu.reg.d = 232;
    cpu.reg.e = 55;
    cpu.reg.f = 144;
    cpu.reg.h = 75;
    cpu.reg.l = 22;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[35215] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 76);
    CHECK(cpu.reg.c == 255);
    CHECK(cpu.reg.d == 232);
    CHECK(cpu.reg.e == 55);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 22);
    CHECK(cpu.reg.pc == 35216);
    // CHECK(cpu.reg.sp == 43496);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35215] == 0);
}

TEST_CASE( "00 0133", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35483;
    cpu.reg.sp = 56337;
    cpu.reg.a = 38;
    cpu.reg.b = 116;
    cpu.reg.c = 128;
    cpu.reg.d = 212;
    cpu.reg.e = 81;
    cpu.reg.f = 192;
    cpu.reg.h = 194;
    cpu.reg.l = 73;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35483] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 38);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 81);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 194);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 35484);
    // CHECK(cpu.reg.sp == 56337);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35483] == 0);
}

TEST_CASE( "00 0134", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55819;
    cpu.reg.sp = 41195;
    cpu.reg.a = 45;
    cpu.reg.b = 86;
    cpu.reg.c = 243;
    cpu.reg.d = 223;
    cpu.reg.e = 54;
    cpu.reg.f = 48;
    cpu.reg.h = 167;
    cpu.reg.l = 79;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[55819] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 45);
    CHECK(cpu.reg.b == 86);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 79);
    CHECK(cpu.reg.pc == 55820);
    // CHECK(cpu.reg.sp == 41195);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[55819] == 0);
}

TEST_CASE( "00 0135", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11014;
    cpu.reg.sp = 62878;
    cpu.reg.a = 72;
    cpu.reg.b = 39;
    cpu.reg.c = 10;
    cpu.reg.d = 11;
    cpu.reg.e = 230;
    cpu.reg.f = 208;
    cpu.reg.h = 236;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[11014] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 72);
    CHECK(cpu.reg.b == 39);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 11);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 11015);
    // CHECK(cpu.reg.sp == 62878);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11014] == 0);
}

TEST_CASE( "00 0136", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43427;
    cpu.reg.sp = 58911;
    cpu.reg.a = 241;
    cpu.reg.b = 107;
    cpu.reg.c = 84;
    cpu.reg.d = 200;
    cpu.reg.e = 252;
    cpu.reg.f = 48;
    cpu.reg.h = 90;
    cpu.reg.l = 211;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43427] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 241);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 252);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 90);
    CHECK(cpu.reg.l == 211);
    CHECK(cpu.reg.pc == 43428);
    // CHECK(cpu.reg.sp == 58911);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43427] == 0);
}

TEST_CASE( "00 0137", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49200;
    cpu.reg.sp = 51538;
    cpu.reg.a = 63;
    cpu.reg.b = 228;
    cpu.reg.c = 184;
    cpu.reg.d = 198;
    cpu.reg.e = 27;
    cpu.reg.f = 208;
    cpu.reg.h = 188;
    cpu.reg.l = 42;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49200] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 198);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 49201);
    // CHECK(cpu.reg.sp == 51538);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49200] == 0);
}

TEST_CASE( "00 0138", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1423;
    cpu.reg.sp = 14115;
    cpu.reg.a = 167;
    cpu.reg.b = 242;
    cpu.reg.c = 231;
    cpu.reg.d = 100;
    cpu.reg.e = 74;
    cpu.reg.f = 160;
    cpu.reg.h = 184;
    cpu.reg.l = 225;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[1423] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 167);
    CHECK(cpu.reg.b == 242);
    CHECK(cpu.reg.c == 231);
    CHECK(cpu.reg.d == 100);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 225);
    CHECK(cpu.reg.pc == 1424);
    // CHECK(cpu.reg.sp == 14115);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1423] == 0);
}

TEST_CASE( "00 0139", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18135;
    cpu.reg.sp = 62305;
    cpu.reg.a = 19;
    cpu.reg.b = 228;
    cpu.reg.c = 229;
    cpu.reg.d = 58;
    cpu.reg.e = 216;
    cpu.reg.f = 224;
    cpu.reg.h = 171;
    cpu.reg.l = 70;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[18135] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 19);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 229);
    CHECK(cpu.reg.d == 58);
    CHECK(cpu.reg.e == 216);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 171);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 18136);
    // CHECK(cpu.reg.sp == 62305);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18135] == 0);
}

TEST_CASE( "00 013A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48893;
    cpu.reg.sp = 35982;
    cpu.reg.a = 44;
    cpu.reg.b = 183;
    cpu.reg.c = 64;
    cpu.reg.d = 68;
    cpu.reg.e = 114;
    cpu.reg.f = 80;
    cpu.reg.h = 12;
    cpu.reg.l = 41;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48893] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 44);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 48894);
    // CHECK(cpu.reg.sp == 35982);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48893] == 0);
}

TEST_CASE( "00 013B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15047;
    cpu.reg.sp = 38561;
    cpu.reg.a = 36;
    cpu.reg.b = 16;
    cpu.reg.c = 62;
    cpu.reg.d = 82;
    cpu.reg.e = 124;
    cpu.reg.f = 224;
    cpu.reg.h = 150;
    cpu.reg.l = 97;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[15047] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 36);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 62);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 150);
    CHECK(cpu.reg.l == 97);
    CHECK(cpu.reg.pc == 15048);
    // CHECK(cpu.reg.sp == 38561);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15047] == 0);
}

TEST_CASE( "00 013C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10369;
    cpu.reg.sp = 23777;
    cpu.reg.a = 98;
    cpu.reg.b = 187;
    cpu.reg.c = 64;
    cpu.reg.d = 43;
    cpu.reg.e = 49;
    cpu.reg.f = 176;
    cpu.reg.h = 199;
    cpu.reg.l = 193;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10369] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 98);
    CHECK(cpu.reg.b == 187);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 43);
    CHECK(cpu.reg.e == 49);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 199);
    CHECK(cpu.reg.l == 193);
    CHECK(cpu.reg.pc == 10370);
    // CHECK(cpu.reg.sp == 23777);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10369] == 0);
}

TEST_CASE( "00 013D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9555;
    cpu.reg.sp = 54346;
    cpu.reg.a = 248;
    cpu.reg.b = 207;
    cpu.reg.c = 226;
    cpu.reg.d = 212;
    cpu.reg.e = 71;
    cpu.reg.f = 32;
    cpu.reg.h = 85;
    cpu.reg.l = 85;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[9555] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 248);
    CHECK(cpu.reg.b == 207);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 71);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 85);
    CHECK(cpu.reg.l == 85);
    CHECK(cpu.reg.pc == 9556);
    // CHECK(cpu.reg.sp == 54346);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9555] == 0);
}

TEST_CASE( "00 013E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21888;
    cpu.reg.sp = 56548;
    cpu.reg.a = 195;
    cpu.reg.b = 4;
    cpu.reg.c = 166;
    cpu.reg.d = 98;
    cpu.reg.e = 101;
    cpu.reg.f = 32;
    cpu.reg.h = 196;
    cpu.reg.l = 202;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21888] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 195);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 166);
    CHECK(cpu.reg.d == 98);
    CHECK(cpu.reg.e == 101);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 196);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 21889);
    // CHECK(cpu.reg.sp == 56548);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21888] == 0);
}

TEST_CASE( "00 013F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60539;
    cpu.reg.sp = 13715;
    cpu.reg.a = 141;
    cpu.reg.b = 184;
    cpu.reg.c = 51;
    cpu.reg.d = 133;
    cpu.reg.e = 144;
    cpu.reg.f = 48;
    cpu.reg.h = 52;
    cpu.reg.l = 75;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[60539] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 133);
    CHECK(cpu.reg.e == 144);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 52);
    CHECK(cpu.reg.l == 75);
    CHECK(cpu.reg.pc == 60540);
    // CHECK(cpu.reg.sp == 13715);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60539] == 0);
}

TEST_CASE( "00 0140", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54893;
    cpu.reg.sp = 16705;
    cpu.reg.a = 143;
    cpu.reg.b = 132;
    cpu.reg.c = 36;
    cpu.reg.d = 5;
    cpu.reg.e = 178;
    cpu.reg.f = 240;
    cpu.reg.h = 43;
    cpu.reg.l = 51;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54893] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 132);
    CHECK(cpu.reg.c == 36);
    CHECK(cpu.reg.d == 5);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 43);
    CHECK(cpu.reg.l == 51);
    CHECK(cpu.reg.pc == 54894);
    // CHECK(cpu.reg.sp == 16705);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54893] == 0);
}

TEST_CASE( "00 0141", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3717;
    cpu.reg.sp = 1716;
    cpu.reg.a = 175;
    cpu.reg.b = 96;
    cpu.reg.c = 152;
    cpu.reg.d = 16;
    cpu.reg.e = 22;
    cpu.reg.f = 160;
    cpu.reg.h = 32;
    cpu.reg.l = 241;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[3717] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 175);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 16);
    CHECK(cpu.reg.e == 22);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 32);
    CHECK(cpu.reg.l == 241);
    CHECK(cpu.reg.pc == 3718);
    // CHECK(cpu.reg.sp == 1716);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3717] == 0);
}

TEST_CASE( "00 0142", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59855;
    cpu.reg.sp = 32845;
    cpu.reg.a = 238;
    cpu.reg.b = 77;
    cpu.reg.c = 241;
    cpu.reg.d = 223;
    cpu.reg.e = 173;
    cpu.reg.f = 16;
    cpu.reg.h = 100;
    cpu.reg.l = 107;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[59855] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 77);
    CHECK(cpu.reg.c == 241);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 100);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 59856);
    // CHECK(cpu.reg.sp == 32845);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59855] == 0);
}

TEST_CASE( "00 0143", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65179;
    cpu.reg.sp = 26510;
    cpu.reg.a = 99;
    cpu.reg.b = 234;
    cpu.reg.c = 232;
    cpu.reg.d = 34;
    cpu.reg.e = 96;
    cpu.reg.f = 64;
    cpu.reg.h = 218;
    cpu.reg.l = 236;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[65179] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 234);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 34);
    CHECK(cpu.reg.e == 96);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 236);
    CHECK(cpu.reg.pc == 65180);
    // CHECK(cpu.reg.sp == 26510);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[65179] == 0);
}

TEST_CASE( "00 0144", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32564;
    cpu.reg.sp = 27779;
    cpu.reg.a = 233;
    cpu.reg.b = 157;
    cpu.reg.c = 125;
    cpu.reg.d = 127;
    cpu.reg.e = 103;
    cpu.reg.f = 48;
    cpu.reg.h = 148;
    cpu.reg.l = 40;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32564] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 233);
    CHECK(cpu.reg.b == 157);
    CHECK(cpu.reg.c == 125);
    CHECK(cpu.reg.d == 127);
    CHECK(cpu.reg.e == 103);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 148);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 32565);
    // CHECK(cpu.reg.sp == 27779);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32564] == 0);
}

TEST_CASE( "00 0145", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32196;
    cpu.reg.sp = 21484;
    cpu.reg.a = 139;
    cpu.reg.b = 185;
    cpu.reg.c = 223;
    cpu.reg.d = 21;
    cpu.reg.e = 202;
    cpu.reg.f = 240;
    cpu.reg.h = 155;
    cpu.reg.l = 153;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32196] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 223);
    CHECK(cpu.reg.d == 21);
    CHECK(cpu.reg.e == 202);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 155);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 32197);
    // CHECK(cpu.reg.sp == 21484);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32196] == 0);
}

TEST_CASE( "00 0146", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5315;
    cpu.reg.sp = 10090;
    cpu.reg.a = 22;
    cpu.reg.b = 202;
    cpu.reg.c = 126;
    cpu.reg.d = 185;
    cpu.reg.e = 209;
    cpu.reg.f = 112;
    cpu.reg.h = 230;
    cpu.reg.l = 52;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5315] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 22);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 126);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 209);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 230);
    CHECK(cpu.reg.l == 52);
    CHECK(cpu.reg.pc == 5316);
    // CHECK(cpu.reg.sp == 10090);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5315] == 0);
}

TEST_CASE( "00 0147", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10898;
    cpu.reg.sp = 61676;
    cpu.reg.a = 49;
    cpu.reg.b = 195;
    cpu.reg.c = 149;
    cpu.reg.d = 243;
    cpu.reg.e = 35;
    cpu.reg.f = 112;
    cpu.reg.h = 97;
    cpu.reg.l = 56;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10898] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 49);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 149);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 35);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 97);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 10899);
    // CHECK(cpu.reg.sp == 61676);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10898] == 0);
}

TEST_CASE( "00 0148", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19388;
    cpu.reg.sp = 2362;
    cpu.reg.a = 140;
    cpu.reg.b = 28;
    cpu.reg.c = 34;
    cpu.reg.d = 95;
    cpu.reg.e = 30;
    cpu.reg.f = 0;
    cpu.reg.h = 2;
    cpu.reg.l = 145;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[19388] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 28);
    CHECK(cpu.reg.c == 34);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 30);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 2);
    CHECK(cpu.reg.l == 145);
    CHECK(cpu.reg.pc == 19389);
    // CHECK(cpu.reg.sp == 2362);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19388] == 0);
}

TEST_CASE( "00 0149", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8009;
    cpu.reg.sp = 14648;
    cpu.reg.a = 9;
    cpu.reg.b = 103;
    cpu.reg.c = 216;
    cpu.reg.d = 187;
    cpu.reg.e = 108;
    cpu.reg.f = 144;
    cpu.reg.h = 191;
    cpu.reg.l = 160;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[8009] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 9);
    CHECK(cpu.reg.b == 103);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 108);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 8010);
    // CHECK(cpu.reg.sp == 14648);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8009] == 0);
}

TEST_CASE( "00 014A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56588;
    cpu.reg.sp = 29595;
    cpu.reg.a = 105;
    cpu.reg.b = 85;
    cpu.reg.c = 60;
    cpu.reg.d = 18;
    cpu.reg.e = 49;
    cpu.reg.f = 16;
    cpu.reg.h = 97;
    cpu.reg.l = 204;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56588] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 105);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 18);
    CHECK(cpu.reg.e == 49);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 97);
    CHECK(cpu.reg.l == 204);
    CHECK(cpu.reg.pc == 56589);
    // CHECK(cpu.reg.sp == 29595);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56588] == 0);
}

TEST_CASE( "00 014B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1049;
    cpu.reg.sp = 17189;
    cpu.reg.a = 107;
    cpu.reg.b = 80;
    cpu.reg.c = 30;
    cpu.reg.d = 91;
    cpu.reg.e = 141;
    cpu.reg.f = 0;
    cpu.reg.h = 122;
    cpu.reg.l = 31;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[1049] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 107);
    CHECK(cpu.reg.b == 80);
    CHECK(cpu.reg.c == 30);
    CHECK(cpu.reg.d == 91);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 122);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 1050);
    // CHECK(cpu.reg.sp == 17189);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[1049] == 0);
}

TEST_CASE( "00 014C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49765;
    cpu.reg.sp = 34806;
    cpu.reg.a = 149;
    cpu.reg.b = 243;
    cpu.reg.c = 154;
    cpu.reg.d = 126;
    cpu.reg.e = 83;
    cpu.reg.f = 128;
    cpu.reg.h = 114;
    cpu.reg.l = 172;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[49765] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 149);
    CHECK(cpu.reg.b == 243);
    CHECK(cpu.reg.c == 154);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 83);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 114);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 49766);
    // CHECK(cpu.reg.sp == 34806);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[49765] == 0);
}

TEST_CASE( "00 014D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54405;
    cpu.reg.sp = 8771;
    cpu.reg.a = 41;
    cpu.reg.b = 106;
    cpu.reg.c = 189;
    cpu.reg.d = 92;
    cpu.reg.e = 232;
    cpu.reg.f = 96;
    cpu.reg.h = 14;
    cpu.reg.l = 213;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54405] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 41);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 189);
    CHECK(cpu.reg.d == 92);
    CHECK(cpu.reg.e == 232);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 14);
    CHECK(cpu.reg.l == 213);
    CHECK(cpu.reg.pc == 54406);
    // CHECK(cpu.reg.sp == 8771);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54405] == 0);
}

TEST_CASE( "00 014E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4841;
    cpu.reg.sp = 26704;
    cpu.reg.a = 41;
    cpu.reg.b = 43;
    cpu.reg.c = 120;
    cpu.reg.d = 218;
    cpu.reg.e = 132;
    cpu.reg.f = 112;
    cpu.reg.h = 224;
    cpu.reg.l = 5;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4841] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 41);
    CHECK(cpu.reg.b == 43);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 218);
    CHECK(cpu.reg.e == 132);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 224);
    CHECK(cpu.reg.l == 5);
    CHECK(cpu.reg.pc == 4842);
    // CHECK(cpu.reg.sp == 26704);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4841] == 0);
}

TEST_CASE( "00 014F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53529;
    cpu.reg.sp = 12806;
    cpu.reg.a = 200;
    cpu.reg.b = 12;
    cpu.reg.c = 130;
    cpu.reg.d = 184;
    cpu.reg.e = 155;
    cpu.reg.f = 64;
    cpu.reg.h = 166;
    cpu.reg.l = 98;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[53529] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 200);
    CHECK(cpu.reg.b == 12);
    CHECK(cpu.reg.c == 130);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 155);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 98);
    CHECK(cpu.reg.pc == 53530);
    // CHECK(cpu.reg.sp == 12806);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53529] == 0);
}

TEST_CASE( "00 0150", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5432;
    cpu.reg.sp = 6502;
    cpu.reg.a = 0;
    cpu.reg.b = 208;
    cpu.reg.c = 146;
    cpu.reg.d = 186;
    cpu.reg.e = 147;
    cpu.reg.f = 128;
    cpu.reg.h = 207;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[5432] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 0);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 186);
    CHECK(cpu.reg.e == 147);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 207);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 5433);
    // CHECK(cpu.reg.sp == 6502);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5432] == 0);
}

TEST_CASE( "00 0151", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9322;
    cpu.reg.sp = 37765;
    cpu.reg.a = 193;
    cpu.reg.b = 210;
    cpu.reg.c = 174;
    cpu.reg.d = 12;
    cpu.reg.e = 74;
    cpu.reg.f = 128;
    cpu.reg.h = 67;
    cpu.reg.l = 114;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9322] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 193);
    CHECK(cpu.reg.b == 210);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 12);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 114);
    CHECK(cpu.reg.pc == 9323);
    // CHECK(cpu.reg.sp == 37765);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9322] == 0);
}

TEST_CASE( "00 0152", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30312;
    cpu.reg.sp = 17799;
    cpu.reg.a = 82;
    cpu.reg.b = 102;
    cpu.reg.c = 150;
    cpu.reg.d = 172;
    cpu.reg.e = 215;
    cpu.reg.f = 144;
    cpu.reg.h = 194;
    cpu.reg.l = 35;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[30312] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 82);
    CHECK(cpu.reg.b == 102);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 215);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 194);
    CHECK(cpu.reg.l == 35);
    CHECK(cpu.reg.pc == 30313);
    // CHECK(cpu.reg.sp == 17799);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30312] == 0);
}

TEST_CASE( "00 0153", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17123;
    cpu.reg.sp = 4453;
    cpu.reg.a = 137;
    cpu.reg.b = 20;
    cpu.reg.c = 107;
    cpu.reg.d = 216;
    cpu.reg.e = 107;
    cpu.reg.f = 160;
    cpu.reg.h = 76;
    cpu.reg.l = 216;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[17123] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 137);
    CHECK(cpu.reg.b == 20);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 216);
    CHECK(cpu.reg.e == 107);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 76);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 17124);
    // CHECK(cpu.reg.sp == 4453);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17123] == 0);
}

TEST_CASE( "00 0154", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5494;
    cpu.reg.sp = 49085;
    cpu.reg.a = 83;
    cpu.reg.b = 29;
    cpu.reg.c = 253;
    cpu.reg.d = 119;
    cpu.reg.e = 160;
    cpu.reg.f = 96;
    cpu.reg.h = 91;
    cpu.reg.l = 22;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[5494] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 83);
    CHECK(cpu.reg.b == 29);
    CHECK(cpu.reg.c == 253);
    CHECK(cpu.reg.d == 119);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 91);
    CHECK(cpu.reg.l == 22);
    CHECK(cpu.reg.pc == 5495);
    // CHECK(cpu.reg.sp == 49085);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5494] == 0);
}

TEST_CASE( "00 0155", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5263;
    cpu.reg.sp = 35499;
    cpu.reg.a = 243;
    cpu.reg.b = 169;
    cpu.reg.c = 41;
    cpu.reg.d = 137;
    cpu.reg.e = 62;
    cpu.reg.f = 32;
    cpu.reg.h = 166;
    cpu.reg.l = 89;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5263] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 243);
    CHECK(cpu.reg.b == 169);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 137);
    CHECK(cpu.reg.e == 62);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 89);
    CHECK(cpu.reg.pc == 5264);
    // CHECK(cpu.reg.sp == 35499);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5263] == 0);
}

TEST_CASE( "00 0156", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40915;
    cpu.reg.sp = 45786;
    cpu.reg.a = 128;
    cpu.reg.b = 31;
    cpu.reg.c = 182;
    cpu.reg.d = 132;
    cpu.reg.e = 124;
    cpu.reg.f = 112;
    cpu.reg.h = 130;
    cpu.reg.l = 89;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40915] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 132);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 130);
    CHECK(cpu.reg.l == 89);
    CHECK(cpu.reg.pc == 40916);
    // CHECK(cpu.reg.sp == 45786);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40915] == 0);
}

TEST_CASE( "00 0157", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9630;
    cpu.reg.sp = 14514;
    cpu.reg.a = 182;
    cpu.reg.b = 151;
    cpu.reg.c = 84;
    cpu.reg.d = 41;
    cpu.reg.e = 68;
    cpu.reg.f = 96;
    cpu.reg.h = 108;
    cpu.reg.l = 225;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[9630] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 182);
    CHECK(cpu.reg.b == 151);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 68);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 108);
    CHECK(cpu.reg.l == 225);
    CHECK(cpu.reg.pc == 9631);
    // CHECK(cpu.reg.sp == 14514);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9630] == 0);
}

TEST_CASE( "00 0158", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22888;
    cpu.reg.sp = 11074;
    cpu.reg.a = 243;
    cpu.reg.b = 178;
    cpu.reg.c = 205;
    cpu.reg.d = 101;
    cpu.reg.e = 203;
    cpu.reg.f = 48;
    cpu.reg.h = 142;
    cpu.reg.l = 114;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[22888] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 243);
    CHECK(cpu.reg.b == 178);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 101);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 142);
    CHECK(cpu.reg.l == 114);
    CHECK(cpu.reg.pc == 22889);
    // CHECK(cpu.reg.sp == 11074);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22888] == 0);
}

TEST_CASE( "00 0159", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46434;
    cpu.reg.sp = 22708;
    cpu.reg.a = 155;
    cpu.reg.b = 225;
    cpu.reg.c = 24;
    cpu.reg.d = 175;
    cpu.reg.e = 115;
    cpu.reg.f = 128;
    cpu.reg.h = 96;
    cpu.reg.l = 121;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[46434] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 155);
    CHECK(cpu.reg.b == 225);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 175);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 96);
    CHECK(cpu.reg.l == 121);
    CHECK(cpu.reg.pc == 46435);
    // CHECK(cpu.reg.sp == 22708);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46434] == 0);
}

TEST_CASE( "00 015A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25251;
    cpu.reg.sp = 57489;
    cpu.reg.a = 176;
    cpu.reg.b = 243;
    cpu.reg.c = 96;
    cpu.reg.d = 208;
    cpu.reg.e = 144;
    cpu.reg.f = 144;
    cpu.reg.h = 8;
    cpu.reg.l = 172;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[25251] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 176);
    CHECK(cpu.reg.b == 243);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 144);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 8);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 25252);
    // CHECK(cpu.reg.sp == 57489);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25251] == 0);
}

TEST_CASE( "00 015B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15709;
    cpu.reg.sp = 44051;
    cpu.reg.a = 187;
    cpu.reg.b = 11;
    cpu.reg.c = 197;
    cpu.reg.d = 85;
    cpu.reg.e = 21;
    cpu.reg.f = 16;
    cpu.reg.h = 204;
    cpu.reg.l = 84;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15709] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 187);
    CHECK(cpu.reg.b == 11);
    CHECK(cpu.reg.c == 197);
    CHECK(cpu.reg.d == 85);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 204);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 15710);
    // CHECK(cpu.reg.sp == 44051);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15709] == 0);
}

TEST_CASE( "00 015C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54333;
    cpu.reg.sp = 7954;
    cpu.reg.a = 26;
    cpu.reg.b = 119;
    cpu.reg.c = 172;
    cpu.reg.d = 32;
    cpu.reg.e = 183;
    cpu.reg.f = 80;
    cpu.reg.h = 118;
    cpu.reg.l = 100;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54333] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 26);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 172);
    CHECK(cpu.reg.d == 32);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 118);
    CHECK(cpu.reg.l == 100);
    CHECK(cpu.reg.pc == 54334);
    // CHECK(cpu.reg.sp == 7954);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54333] == 0);
}

TEST_CASE( "00 015D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21900;
    cpu.reg.sp = 1377;
    cpu.reg.a = 219;
    cpu.reg.b = 75;
    cpu.reg.c = 223;
    cpu.reg.d = 239;
    cpu.reg.e = 142;
    cpu.reg.f = 48;
    cpu.reg.h = 214;
    cpu.reg.l = 106;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[21900] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 219);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 223);
    CHECK(cpu.reg.d == 239);
    CHECK(cpu.reg.e == 142);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 214);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 21901);
    // CHECK(cpu.reg.sp == 1377);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21900] == 0);
}

TEST_CASE( "00 015E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29241;
    cpu.reg.sp = 49637;
    cpu.reg.a = 248;
    cpu.reg.b = 47;
    cpu.reg.c = 185;
    cpu.reg.d = 228;
    cpu.reg.e = 79;
    cpu.reg.f = 0;
    cpu.reg.h = 7;
    cpu.reg.l = 40;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29241] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 248);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 185);
    CHECK(cpu.reg.d == 228);
    CHECK(cpu.reg.e == 79);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 7);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 29242);
    // CHECK(cpu.reg.sp == 49637);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29241] == 0);
}

TEST_CASE( "00 015F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64192;
    cpu.reg.sp = 1769;
    cpu.reg.a = 153;
    cpu.reg.b = 156;
    cpu.reg.c = 185;
    cpu.reg.d = 111;
    cpu.reg.e = 171;
    cpu.reg.f = 64;
    cpu.reg.h = 46;
    cpu.reg.l = 22;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64192] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 185);
    CHECK(cpu.reg.d == 111);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 46);
    CHECK(cpu.reg.l == 22);
    CHECK(cpu.reg.pc == 64193);
    // CHECK(cpu.reg.sp == 1769);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64192] == 0);
}

TEST_CASE( "00 0160", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7181;
    cpu.reg.sp = 51402;
    cpu.reg.a = 75;
    cpu.reg.b = 226;
    cpu.reg.c = 75;
    cpu.reg.d = 11;
    cpu.reg.e = 215;
    cpu.reg.f = 16;
    cpu.reg.h = 148;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7181] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 75);
    CHECK(cpu.reg.b == 226);
    CHECK(cpu.reg.c == 75);
    CHECK(cpu.reg.d == 11);
    CHECK(cpu.reg.e == 215);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 148);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 7182);
    // CHECK(cpu.reg.sp == 51402);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7181] == 0);
}

TEST_CASE( "00 0161", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45926;
    cpu.reg.sp = 59756;
    cpu.reg.a = 8;
    cpu.reg.b = 130;
    cpu.reg.c = 104;
    cpu.reg.d = 65;
    cpu.reg.e = 244;
    cpu.reg.f = 96;
    cpu.reg.h = 226;
    cpu.reg.l = 237;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[45926] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 130);
    CHECK(cpu.reg.c == 104);
    CHECK(cpu.reg.d == 65);
    CHECK(cpu.reg.e == 244);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 226);
    CHECK(cpu.reg.l == 237);
    CHECK(cpu.reg.pc == 45927);
    // CHECK(cpu.reg.sp == 59756);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[45926] == 0);
}

TEST_CASE( "00 0162", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28416;
    cpu.reg.sp = 16947;
    cpu.reg.a = 202;
    cpu.reg.b = 185;
    cpu.reg.c = 197;
    cpu.reg.d = 35;
    cpu.reg.e = 57;
    cpu.reg.f = 16;
    cpu.reg.h = 50;
    cpu.reg.l = 99;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[28416] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 202);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 197);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 57);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 50);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 28417);
    // CHECK(cpu.reg.sp == 16947);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28416] == 0);
}

TEST_CASE( "00 0163", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28956;
    cpu.reg.sp = 60418;
    cpu.reg.a = 45;
    cpu.reg.b = 40;
    cpu.reg.c = 124;
    cpu.reg.d = 7;
    cpu.reg.e = 237;
    cpu.reg.f = 16;
    cpu.reg.h = 132;
    cpu.reg.l = 242;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28956] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 45);
    CHECK(cpu.reg.b == 40);
    CHECK(cpu.reg.c == 124);
    CHECK(cpu.reg.d == 7);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 132);
    CHECK(cpu.reg.l == 242);
    CHECK(cpu.reg.pc == 28957);
    // CHECK(cpu.reg.sp == 60418);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28956] == 0);
}

TEST_CASE( "00 0164", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10887;
    cpu.reg.sp = 38146;
    cpu.reg.a = 66;
    cpu.reg.b = 21;
    cpu.reg.c = 215;
    cpu.reg.d = 82;
    cpu.reg.e = 156;
    cpu.reg.f = 16;
    cpu.reg.h = 225;
    cpu.reg.l = 207;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[10887] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 21);
    CHECK(cpu.reg.c == 215);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 156);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 207);
    CHECK(cpu.reg.pc == 10888);
    // CHECK(cpu.reg.sp == 38146);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10887] == 0);
}

TEST_CASE( "00 0165", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34144;
    cpu.reg.sp = 1494;
    cpu.reg.a = 128;
    cpu.reg.b = 178;
    cpu.reg.c = 236;
    cpu.reg.d = 212;
    cpu.reg.e = 190;
    cpu.reg.f = 32;
    cpu.reg.h = 252;
    cpu.reg.l = 195;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34144] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 178);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 34145);
    // CHECK(cpu.reg.sp == 1494);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34144] == 0);
}

TEST_CASE( "00 0166", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34802;
    cpu.reg.sp = 32612;
    cpu.reg.a = 62;
    cpu.reg.b = 89;
    cpu.reg.c = 51;
    cpu.reg.d = 143;
    cpu.reg.e = 171;
    cpu.reg.f = 208;
    cpu.reg.h = 209;
    cpu.reg.l = 148;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[34802] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 143);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 148);
    CHECK(cpu.reg.pc == 34803);
    // CHECK(cpu.reg.sp == 32612);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34802] == 0);
}

TEST_CASE( "00 0167", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25340;
    cpu.reg.sp = 6010;
    cpu.reg.a = 164;
    cpu.reg.b = 234;
    cpu.reg.c = 250;
    cpu.reg.d = 140;
    cpu.reg.e = 21;
    cpu.reg.f = 32;
    cpu.reg.h = 81;
    cpu.reg.l = 201;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[25340] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 234);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 140);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 81);
    CHECK(cpu.reg.l == 201);
    CHECK(cpu.reg.pc == 25341);
    // CHECK(cpu.reg.sp == 6010);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25340] == 0);
}

TEST_CASE( "00 0168", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49903;
    cpu.reg.sp = 10010;
    cpu.reg.a = 2;
    cpu.reg.b = 1;
    cpu.reg.c = 187;
    cpu.reg.d = 210;
    cpu.reg.e = 167;
    cpu.reg.f = 80;
    cpu.reg.h = 85;
    cpu.reg.l = 195;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[49903] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 1);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 210);
    CHECK(cpu.reg.e == 167);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 85);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 49904);
    // CHECK(cpu.reg.sp == 10010);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[49903] == 0);
}

TEST_CASE( "00 0169", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30953;
    cpu.reg.sp = 23925;
    cpu.reg.a = 21;
    cpu.reg.b = 31;
    cpu.reg.c = 50;
    cpu.reg.d = 222;
    cpu.reg.e = 0;
    cpu.reg.f = 160;
    cpu.reg.h = 30;
    cpu.reg.l = 217;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[30953] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 50);
    CHECK(cpu.reg.d == 222);
    CHECK(cpu.reg.e == 0);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 30);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 30954);
    // CHECK(cpu.reg.sp == 23925);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30953] == 0);
}

TEST_CASE( "00 016A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15013;
    cpu.reg.sp = 6896;
    cpu.reg.a = 71;
    cpu.reg.b = 117;
    cpu.reg.c = 64;
    cpu.reg.d = 119;
    cpu.reg.e = 228;
    cpu.reg.f = 80;
    cpu.reg.h = 120;
    cpu.reg.l = 195;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[15013] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 71);
    CHECK(cpu.reg.b == 117);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 119);
    CHECK(cpu.reg.e == 228);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 15014);
    // CHECK(cpu.reg.sp == 6896);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15013] == 0);
}

TEST_CASE( "00 016B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44975;
    cpu.reg.sp = 4707;
    cpu.reg.a = 245;
    cpu.reg.b = 88;
    cpu.reg.c = 248;
    cpu.reg.d = 125;
    cpu.reg.e = 61;
    cpu.reg.f = 208;
    cpu.reg.h = 236;
    cpu.reg.l = 228;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[44975] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 245);
    CHECK(cpu.reg.b == 88);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 125);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 228);
    CHECK(cpu.reg.pc == 44976);
    // CHECK(cpu.reg.sp == 4707);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44975] == 0);
}

TEST_CASE( "00 016C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64313;
    cpu.reg.sp = 3081;
    cpu.reg.a = 118;
    cpu.reg.b = 34;
    cpu.reg.c = 3;
    cpu.reg.d = 35;
    cpu.reg.e = 61;
    cpu.reg.f = 128;
    cpu.reg.h = 206;
    cpu.reg.l = 108;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64313] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 34);
    CHECK(cpu.reg.c == 3);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 108);
    CHECK(cpu.reg.pc == 64314);
    // CHECK(cpu.reg.sp == 3081);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64313] == 0);
}

TEST_CASE( "00 016D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12686;
    cpu.reg.sp = 7344;
    cpu.reg.a = 122;
    cpu.reg.b = 53;
    cpu.reg.c = 8;
    cpu.reg.d = 136;
    cpu.reg.e = 187;
    cpu.reg.f = 48;
    cpu.reg.h = 157;
    cpu.reg.l = 187;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[12686] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 122);
    CHECK(cpu.reg.b == 53);
    CHECK(cpu.reg.c == 8);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 187);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 157);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 12687);
    // CHECK(cpu.reg.sp == 7344);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12686] == 0);
}

TEST_CASE( "00 016E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20928;
    cpu.reg.sp = 64664;
    cpu.reg.a = 196;
    cpu.reg.b = 215;
    cpu.reg.c = 235;
    cpu.reg.d = 189;
    cpu.reg.e = 187;
    cpu.reg.f = 176;
    cpu.reg.h = 44;
    cpu.reg.l = 254;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[20928] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 196);
    CHECK(cpu.reg.b == 215);
    CHECK(cpu.reg.c == 235);
    CHECK(cpu.reg.d == 189);
    CHECK(cpu.reg.e == 187);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 44);
    CHECK(cpu.reg.l == 254);
    CHECK(cpu.reg.pc == 20929);
    // CHECK(cpu.reg.sp == 64664);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20928] == 0);
}

TEST_CASE( "00 016F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13192;
    cpu.reg.sp = 55165;
    cpu.reg.a = 221;
    cpu.reg.b = 244;
    cpu.reg.c = 47;
    cpu.reg.d = 76;
    cpu.reg.e = 221;
    cpu.reg.f = 32;
    cpu.reg.h = 71;
    cpu.reg.l = 201;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[13192] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 47);
    CHECK(cpu.reg.d == 76);
    CHECK(cpu.reg.e == 221);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 201);
    CHECK(cpu.reg.pc == 13193);
    // CHECK(cpu.reg.sp == 55165);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[13192] == 0);
}

TEST_CASE( "00 0170", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38701;
    cpu.reg.sp = 63609;
    cpu.reg.a = 14;
    cpu.reg.b = 117;
    cpu.reg.c = 151;
    cpu.reg.d = 191;
    cpu.reg.e = 27;
    cpu.reg.f = 48;
    cpu.reg.h = 151;
    cpu.reg.l = 139;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[38701] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 117);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 191);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 151);
    CHECK(cpu.reg.l == 139);
    CHECK(cpu.reg.pc == 38702);
    // CHECK(cpu.reg.sp == 63609);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38701] == 0);
}

TEST_CASE( "00 0171", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36816;
    cpu.reg.sp = 19742;
    cpu.reg.a = 80;
    cpu.reg.b = 152;
    cpu.reg.c = 29;
    cpu.reg.d = 19;
    cpu.reg.e = 38;
    cpu.reg.f = 240;
    cpu.reg.h = 167;
    cpu.reg.l = 231;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[36816] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 80);
    CHECK(cpu.reg.b == 152);
    CHECK(cpu.reg.c == 29);
    CHECK(cpu.reg.d == 19);
    CHECK(cpu.reg.e == 38);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 231);
    CHECK(cpu.reg.pc == 36817);
    // CHECK(cpu.reg.sp == 19742);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36816] == 0);
}

TEST_CASE( "00 0172", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34471;
    cpu.reg.sp = 11351;
    cpu.reg.a = 31;
    cpu.reg.b = 196;
    cpu.reg.c = 69;
    cpu.reg.d = 169;
    cpu.reg.e = 1;
    cpu.reg.f = 128;
    cpu.reg.h = 205;
    cpu.reg.l = 197;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34471] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 31);
    CHECK(cpu.reg.b == 196);
    CHECK(cpu.reg.c == 69);
    CHECK(cpu.reg.d == 169);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 205);
    CHECK(cpu.reg.l == 197);
    CHECK(cpu.reg.pc == 34472);
    // CHECK(cpu.reg.sp == 11351);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34471] == 0);
}

TEST_CASE( "00 0173", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51795;
    cpu.reg.sp = 49723;
    cpu.reg.a = 120;
    cpu.reg.b = 58;
    cpu.reg.c = 82;
    cpu.reg.d = 113;
    cpu.reg.e = 42;
    cpu.reg.f = 192;
    cpu.reg.h = 127;
    cpu.reg.l = 97;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[51795] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 58);
    CHECK(cpu.reg.c == 82);
    CHECK(cpu.reg.d == 113);
    CHECK(cpu.reg.e == 42);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 127);
    CHECK(cpu.reg.l == 97);
    CHECK(cpu.reg.pc == 51796);
    // CHECK(cpu.reg.sp == 49723);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[51795] == 0);
}

TEST_CASE( "00 0174", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44811;
    cpu.reg.sp = 37669;
    cpu.reg.a = 249;
    cpu.reg.b = 98;
    cpu.reg.c = 30;
    cpu.reg.d = 227;
    cpu.reg.e = 183;
    cpu.reg.f = 32;
    cpu.reg.h = 72;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[44811] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 249);
    CHECK(cpu.reg.b == 98);
    CHECK(cpu.reg.c == 30);
    CHECK(cpu.reg.d == 227);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 72);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 44812);
    // CHECK(cpu.reg.sp == 37669);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44811] == 0);
}

TEST_CASE( "00 0175", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47458;
    cpu.reg.sp = 64096;
    cpu.reg.a = 41;
    cpu.reg.b = 109;
    cpu.reg.c = 32;
    cpu.reg.d = 96;
    cpu.reg.e = 193;
    cpu.reg.f = 128;
    cpu.reg.h = 36;
    cpu.reg.l = 229;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47458] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 41);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 32);
    CHECK(cpu.reg.d == 96);
    CHECK(cpu.reg.e == 193);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 36);
    CHECK(cpu.reg.l == 229);
    CHECK(cpu.reg.pc == 47459);
    // CHECK(cpu.reg.sp == 64096);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47458] == 0);
}

TEST_CASE( "00 0176", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21655;
    cpu.reg.sp = 21902;
    cpu.reg.a = 69;
    cpu.reg.b = 105;
    cpu.reg.c = 13;
    cpu.reg.d = 219;
    cpu.reg.e = 159;
    cpu.reg.f = 240;
    cpu.reg.h = 225;
    cpu.reg.l = 47;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21655] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 219);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 47);
    CHECK(cpu.reg.pc == 21656);
    // CHECK(cpu.reg.sp == 21902);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21655] == 0);
}

TEST_CASE( "00 0177", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21345;
    cpu.reg.sp = 17794;
    cpu.reg.a = 210;
    cpu.reg.b = 87;
    cpu.reg.c = 241;
    cpu.reg.d = 30;
    cpu.reg.e = 49;
    cpu.reg.f = 112;
    cpu.reg.h = 226;
    cpu.reg.l = 105;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[21345] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 241);
    CHECK(cpu.reg.d == 30);
    CHECK(cpu.reg.e == 49);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 226);
    CHECK(cpu.reg.l == 105);
    CHECK(cpu.reg.pc == 21346);
    // CHECK(cpu.reg.sp == 17794);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21345] == 0);
}

TEST_CASE( "00 0178", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58029;
    cpu.reg.sp = 32682;
    cpu.reg.a = 84;
    cpu.reg.b = 42;
    cpu.reg.c = 19;
    cpu.reg.d = 115;
    cpu.reg.e = 38;
    cpu.reg.f = 32;
    cpu.reg.h = 94;
    cpu.reg.l = 9;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[58029] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 19);
    CHECK(cpu.reg.d == 115);
    CHECK(cpu.reg.e == 38);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 94);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 58030);
    // CHECK(cpu.reg.sp == 32682);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58029] == 0);
}

TEST_CASE( "00 0179", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61759;
    cpu.reg.sp = 38493;
    cpu.reg.a = 83;
    cpu.reg.b = 38;
    cpu.reg.c = 161;
    cpu.reg.d = 170;
    cpu.reg.e = 207;
    cpu.reg.f = 176;
    cpu.reg.h = 243;
    cpu.reg.l = 42;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[61759] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 83);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 161);
    CHECK(cpu.reg.d == 170);
    CHECK(cpu.reg.e == 207);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 61760);
    // CHECK(cpu.reg.sp == 38493);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61759] == 0);
}

TEST_CASE( "00 017A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52160;
    cpu.reg.sp = 11975;
    cpu.reg.a = 252;
    cpu.reg.b = 243;
    cpu.reg.c = 240;
    cpu.reg.d = 43;
    cpu.reg.e = 151;
    cpu.reg.f = 192;
    cpu.reg.h = 161;
    cpu.reg.l = 208;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[52160] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 252);
    CHECK(cpu.reg.b == 243);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 43);
    CHECK(cpu.reg.e == 151);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 208);
    CHECK(cpu.reg.pc == 52161);
    // CHECK(cpu.reg.sp == 11975);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52160] == 0);
}

TEST_CASE( "00 017B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22966;
    cpu.reg.sp = 3609;
    cpu.reg.a = 66;
    cpu.reg.b = 124;
    cpu.reg.c = 24;
    cpu.reg.d = 17;
    cpu.reg.e = 94;
    cpu.reg.f = 0;
    cpu.reg.h = 25;
    cpu.reg.l = 172;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[22966] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 124);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 17);
    CHECK(cpu.reg.e == 94);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 25);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 22967);
    // CHECK(cpu.reg.sp == 3609);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22966] == 0);
}

TEST_CASE( "00 017C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45056;
    cpu.reg.sp = 31951;
    cpu.reg.a = 247;
    cpu.reg.b = 235;
    cpu.reg.c = 239;
    cpu.reg.d = 159;
    cpu.reg.e = 156;
    cpu.reg.f = 16;
    cpu.reg.h = 26;
    cpu.reg.l = 12;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[45056] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 247);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 239);
    CHECK(cpu.reg.d == 159);
    CHECK(cpu.reg.e == 156);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 12);
    CHECK(cpu.reg.pc == 45057);
    // CHECK(cpu.reg.sp == 31951);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[45056] == 0);
}

TEST_CASE( "00 017D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22869;
    cpu.reg.sp = 26465;
    cpu.reg.a = 141;
    cpu.reg.b = 206;
    cpu.reg.c = 170;
    cpu.reg.d = 246;
    cpu.reg.e = 183;
    cpu.reg.f = 176;
    cpu.reg.h = 140;
    cpu.reg.l = 49;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22869] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 206);
    CHECK(cpu.reg.c == 170);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 49);
    CHECK(cpu.reg.pc == 22870);
    // CHECK(cpu.reg.sp == 26465);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22869] == 0);
}

TEST_CASE( "00 017E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25160;
    cpu.reg.sp = 38047;
    cpu.reg.a = 218;
    cpu.reg.b = 41;
    cpu.reg.c = 216;
    cpu.reg.d = 183;
    cpu.reg.e = 23;
    cpu.reg.f = 160;
    cpu.reg.h = 181;
    cpu.reg.l = 67;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25160] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 41);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 23);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 181);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 25161);
    // CHECK(cpu.reg.sp == 38047);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25160] == 0);
}

TEST_CASE( "00 017F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40451;
    cpu.reg.sp = 63546;
    cpu.reg.a = 168;
    cpu.reg.b = 5;
    cpu.reg.c = 231;
    cpu.reg.d = 215;
    cpu.reg.e = 198;
    cpu.reg.f = 144;
    cpu.reg.h = 163;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[40451] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 168);
    CHECK(cpu.reg.b == 5);
    CHECK(cpu.reg.c == 231);
    CHECK(cpu.reg.d == 215);
    CHECK(cpu.reg.e == 198);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 163);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 40452);
    // CHECK(cpu.reg.sp == 63546);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40451] == 0);
}

TEST_CASE( "00 0180", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16929;
    cpu.reg.sp = 36367;
    cpu.reg.a = 42;
    cpu.reg.b = 235;
    cpu.reg.c = 232;
    cpu.reg.d = 185;
    cpu.reg.e = 110;
    cpu.reg.f = 224;
    cpu.reg.h = 45;
    cpu.reg.l = 11;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[16929] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 110);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 45);
    CHECK(cpu.reg.l == 11);
    CHECK(cpu.reg.pc == 16930);
    // CHECK(cpu.reg.sp == 36367);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16929] == 0);
}

TEST_CASE( "00 0181", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51375;
    cpu.reg.sp = 62051;
    cpu.reg.a = 142;
    cpu.reg.b = 72;
    cpu.reg.c = 228;
    cpu.reg.d = 252;
    cpu.reg.e = 241;
    cpu.reg.f = 144;
    cpu.reg.h = 206;
    cpu.reg.l = 125;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[51375] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 142);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 228);
    CHECK(cpu.reg.d == 252);
    CHECK(cpu.reg.e == 241);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 125);
    CHECK(cpu.reg.pc == 51376);
    // CHECK(cpu.reg.sp == 62051);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[51375] == 0);
}

TEST_CASE( "00 0182", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63354;
    cpu.reg.sp = 2892;
    cpu.reg.a = 190;
    cpu.reg.b = 56;
    cpu.reg.c = 64;
    cpu.reg.d = 173;
    cpu.reg.e = 138;
    cpu.reg.f = 192;
    cpu.reg.h = 106;
    cpu.reg.l = 244;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[63354] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 190);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 173);
    CHECK(cpu.reg.e == 138);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 244);
    CHECK(cpu.reg.pc == 63355);
    // CHECK(cpu.reg.sp == 2892);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63354] == 0);
}

TEST_CASE( "00 0183", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63885;
    cpu.reg.sp = 58584;
    cpu.reg.a = 102;
    cpu.reg.b = 107;
    cpu.reg.c = 95;
    cpu.reg.d = 104;
    cpu.reg.e = 186;
    cpu.reg.f = 112;
    cpu.reg.h = 80;
    cpu.reg.l = 75;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[63885] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 102);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 95);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 186);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 75);
    CHECK(cpu.reg.pc == 63886);
    // CHECK(cpu.reg.sp == 58584);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[63885] == 0);
}

TEST_CASE( "00 0184", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48460;
    cpu.reg.sp = 5442;
    cpu.reg.a = 128;
    cpu.reg.b = 64;
    cpu.reg.c = 86;
    cpu.reg.d = 20;
    cpu.reg.e = 6;
    cpu.reg.f = 32;
    cpu.reg.h = 8;
    cpu.reg.l = 166;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[48460] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 64);
    CHECK(cpu.reg.c == 86);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 8);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 48461);
    // CHECK(cpu.reg.sp == 5442);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48460] == 0);
}

TEST_CASE( "00 0185", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39041;
    cpu.reg.sp = 29982;
    cpu.reg.a = 17;
    cpu.reg.b = 42;
    cpu.reg.c = 232;
    cpu.reg.d = 22;
    cpu.reg.e = 188;
    cpu.reg.f = 128;
    cpu.reg.h = 243;
    cpu.reg.l = 36;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39041] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 17);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 36);
    CHECK(cpu.reg.pc == 39042);
    // CHECK(cpu.reg.sp == 29982);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39041] == 0);
}

TEST_CASE( "00 0186", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50381;
    cpu.reg.sp = 11145;
    cpu.reg.a = 185;
    cpu.reg.b = 93;
    cpu.reg.c = 125;
    cpu.reg.d = 194;
    cpu.reg.e = 102;
    cpu.reg.f = 224;
    cpu.reg.h = 164;
    cpu.reg.l = 197;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[50381] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 185);
    CHECK(cpu.reg.b == 93);
    CHECK(cpu.reg.c == 125);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 102);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 197);
    CHECK(cpu.reg.pc == 50382);
    // CHECK(cpu.reg.sp == 11145);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50381] == 0);
}

TEST_CASE( "00 0187", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59297;
    cpu.reg.sp = 5441;
    cpu.reg.a = 4;
    cpu.reg.b = 39;
    cpu.reg.c = 211;
    cpu.reg.d = 170;
    cpu.reg.e = 192;
    cpu.reg.f = 96;
    cpu.reg.h = 85;
    cpu.reg.l = 204;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[59297] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 4);
    CHECK(cpu.reg.b == 39);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 170);
    CHECK(cpu.reg.e == 192);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 85);
    CHECK(cpu.reg.l == 204);
    CHECK(cpu.reg.pc == 59298);
    // CHECK(cpu.reg.sp == 5441);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[59297] == 0);
}

TEST_CASE( "00 0188", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22494;
    cpu.reg.sp = 50173;
    cpu.reg.a = 129;
    cpu.reg.b = 235;
    cpu.reg.c = 245;
    cpu.reg.d = 95;
    cpu.reg.e = 51;
    cpu.reg.f = 112;
    cpu.reg.h = 7;
    cpu.reg.l = 166;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22494] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 129);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 245);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 51);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 7);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 22495);
    // CHECK(cpu.reg.sp == 50173);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22494] == 0);
}

TEST_CASE( "00 0189", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36751;
    cpu.reg.sp = 26852;
    cpu.reg.a = 215;
    cpu.reg.b = 220;
    cpu.reg.c = 193;
    cpu.reg.d = 124;
    cpu.reg.e = 237;
    cpu.reg.f = 192;
    cpu.reg.h = 242;
    cpu.reg.l = 141;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[36751] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 193);
    CHECK(cpu.reg.d == 124);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 141);
    CHECK(cpu.reg.pc == 36752);
    // CHECK(cpu.reg.sp == 26852);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36751] == 0);
}

TEST_CASE( "00 018A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9454;
    cpu.reg.sp = 35315;
    cpu.reg.a = 200;
    cpu.reg.b = 139;
    cpu.reg.c = 73;
    cpu.reg.d = 191;
    cpu.reg.e = 61;
    cpu.reg.f = 224;
    cpu.reg.h = 94;
    cpu.reg.l = 123;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[9454] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 200);
    CHECK(cpu.reg.b == 139);
    CHECK(cpu.reg.c == 73);
    CHECK(cpu.reg.d == 191);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 94);
    CHECK(cpu.reg.l == 123);
    CHECK(cpu.reg.pc == 9455);
    // CHECK(cpu.reg.sp == 35315);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9454] == 0);
}

TEST_CASE( "00 018B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 65013;
    cpu.reg.sp = 25069;
    cpu.reg.a = 78;
    cpu.reg.b = 7;
    cpu.reg.c = 159;
    cpu.reg.d = 95;
    cpu.reg.e = 188;
    cpu.reg.f = 80;
    cpu.reg.h = 65;
    cpu.reg.l = 30;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[65013] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 7);
    CHECK(cpu.reg.c == 159);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 65);
    CHECK(cpu.reg.l == 30);
    CHECK(cpu.reg.pc == 65014);
    // CHECK(cpu.reg.sp == 25069);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[65013] == 0);
}

TEST_CASE( "00 018C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13505;
    cpu.reg.sp = 42197;
    cpu.reg.a = 175;
    cpu.reg.b = 132;
    cpu.reg.c = 164;
    cpu.reg.d = 234;
    cpu.reg.e = 85;
    cpu.reg.f = 48;
    cpu.reg.h = 125;
    cpu.reg.l = 239;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[13505] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 175);
    CHECK(cpu.reg.b == 132);
    CHECK(cpu.reg.c == 164);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 239);
    CHECK(cpu.reg.pc == 13506);
    // CHECK(cpu.reg.sp == 42197);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13505] == 0);
}

TEST_CASE( "00 018D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30423;
    cpu.reg.sp = 55715;
    cpu.reg.a = 138;
    cpu.reg.b = 193;
    cpu.reg.c = 169;
    cpu.reg.d = 135;
    cpu.reg.e = 141;
    cpu.reg.f = 240;
    cpu.reg.h = 212;
    cpu.reg.l = 176;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[30423] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 138);
    CHECK(cpu.reg.b == 193);
    CHECK(cpu.reg.c == 169);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 212);
    CHECK(cpu.reg.l == 176);
    CHECK(cpu.reg.pc == 30424);
    // CHECK(cpu.reg.sp == 55715);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30423] == 0);
}

TEST_CASE( "00 018E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61567;
    cpu.reg.sp = 1013;
    cpu.reg.a = 96;
    cpu.reg.b = 66;
    cpu.reg.c = 41;
    cpu.reg.d = 215;
    cpu.reg.e = 238;
    cpu.reg.f = 48;
    cpu.reg.h = 149;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[61567] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 215);
    CHECK(cpu.reg.e == 238);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 61568);
    // CHECK(cpu.reg.sp == 1013);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[61567] == 0);
}

TEST_CASE( "00 018F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26176;
    cpu.reg.sp = 50485;
    cpu.reg.a = 38;
    cpu.reg.b = 220;
    cpu.reg.c = 212;
    cpu.reg.d = 149;
    cpu.reg.e = 133;
    cpu.reg.f = 128;
    cpu.reg.h = 166;
    cpu.reg.l = 202;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[26176] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 38);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 212);
    CHECK(cpu.reg.d == 149);
    CHECK(cpu.reg.e == 133);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 26177);
    // CHECK(cpu.reg.sp == 50485);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26176] == 0);
}

TEST_CASE( "00 0190", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46105;
    cpu.reg.sp = 34099;
    cpu.reg.a = 174;
    cpu.reg.b = 177;
    cpu.reg.c = 15;
    cpu.reg.d = 200;
    cpu.reg.e = 254;
    cpu.reg.f = 144;
    cpu.reg.h = 128;
    cpu.reg.l = 31;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[46105] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 174);
    CHECK(cpu.reg.b == 177);
    CHECK(cpu.reg.c == 15);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 254);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 128);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 46106);
    // CHECK(cpu.reg.sp == 34099);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46105] == 0);
}

TEST_CASE( "00 0191", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8755;
    cpu.reg.sp = 9465;
    cpu.reg.a = 227;
    cpu.reg.b = 51;
    cpu.reg.c = 90;
    cpu.reg.d = 16;
    cpu.reg.e = 16;
    cpu.reg.f = 224;
    cpu.reg.h = 175;
    cpu.reg.l = 133;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[8755] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 227);
    CHECK(cpu.reg.b == 51);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 16);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 175);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 8756);
    // CHECK(cpu.reg.sp == 9465);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8755] == 0);
}

TEST_CASE( "00 0192", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62102;
    cpu.reg.sp = 25069;
    cpu.reg.a = 147;
    cpu.reg.b = 98;
    cpu.reg.c = 41;
    cpu.reg.d = 201;
    cpu.reg.e = 119;
    cpu.reg.f = 144;
    cpu.reg.h = 87;
    cpu.reg.l = 207;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62102] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 147);
    CHECK(cpu.reg.b == 98);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 201);
    CHECK(cpu.reg.e == 119);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 87);
    CHECK(cpu.reg.l == 207);
    CHECK(cpu.reg.pc == 62103);
    // CHECK(cpu.reg.sp == 25069);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62102] == 0);
}

TEST_CASE( "00 0193", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6938;
    cpu.reg.sp = 26435;
    cpu.reg.a = 35;
    cpu.reg.b = 26;
    cpu.reg.c = 253;
    cpu.reg.d = 9;
    cpu.reg.e = 243;
    cpu.reg.f = 64;
    cpu.reg.h = 80;
    cpu.reg.l = 175;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6938] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 35);
    CHECK(cpu.reg.b == 26);
    CHECK(cpu.reg.c == 253);
    CHECK(cpu.reg.d == 9);
    CHECK(cpu.reg.e == 243);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 6939);
    // CHECK(cpu.reg.sp == 26435);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6938] == 0);
}

TEST_CASE( "00 0194", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46594;
    cpu.reg.sp = 2518;
    cpu.reg.a = 103;
    cpu.reg.b = 120;
    cpu.reg.c = 155;
    cpu.reg.d = 207;
    cpu.reg.e = 191;
    cpu.reg.f = 128;
    cpu.reg.h = 186;
    cpu.reg.l = 236;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46594] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 120);
    CHECK(cpu.reg.c == 155);
    CHECK(cpu.reg.d == 207);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 236);
    CHECK(cpu.reg.pc == 46595);
    // CHECK(cpu.reg.sp == 2518);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46594] == 0);
}

TEST_CASE( "00 0195", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13461;
    cpu.reg.sp = 59299;
    cpu.reg.a = 139;
    cpu.reg.b = 205;
    cpu.reg.c = 81;
    cpu.reg.d = 156;
    cpu.reg.e = 1;
    cpu.reg.f = 160;
    cpu.reg.h = 41;
    cpu.reg.l = 221;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[13461] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 156);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 41);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 13462);
    // CHECK(cpu.reg.sp == 59299);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13461] == 0);
}

TEST_CASE( "00 0196", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38032;
    cpu.reg.sp = 7036;
    cpu.reg.a = 238;
    cpu.reg.b = 7;
    cpu.reg.c = 190;
    cpu.reg.d = 198;
    cpu.reg.e = 23;
    cpu.reg.f = 192;
    cpu.reg.h = 136;
    cpu.reg.l = 61;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[38032] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 7);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 198);
    CHECK(cpu.reg.e == 23);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 38033);
    // CHECK(cpu.reg.sp == 7036);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38032] == 0);
}

TEST_CASE( "00 0197", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28558;
    cpu.reg.sp = 58009;
    cpu.reg.a = 39;
    cpu.reg.b = 66;
    cpu.reg.c = 206;
    cpu.reg.d = 226;
    cpu.reg.e = 178;
    cpu.reg.f = 80;
    cpu.reg.h = 112;
    cpu.reg.l = 67;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[28558] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 39);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 206);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 28559);
    // CHECK(cpu.reg.sp == 58009);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28558] == 0);
}

TEST_CASE( "00 0198", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29017;
    cpu.reg.sp = 827;
    cpu.reg.a = 249;
    cpu.reg.b = 146;
    cpu.reg.c = 107;
    cpu.reg.d = 3;
    cpu.reg.e = 115;
    cpu.reg.f = 16;
    cpu.reg.h = 161;
    cpu.reg.l = 78;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29017] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 249);
    CHECK(cpu.reg.b == 146);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 3);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 78);
    CHECK(cpu.reg.pc == 29018);
    // CHECK(cpu.reg.sp == 827);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29017] == 0);
}

TEST_CASE( "00 0199", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60080;
    cpu.reg.sp = 59907;
    cpu.reg.a = 147;
    cpu.reg.b = 62;
    cpu.reg.c = 236;
    cpu.reg.d = 143;
    cpu.reg.e = 173;
    cpu.reg.f = 176;
    cpu.reg.h = 215;
    cpu.reg.l = 100;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[60080] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 147);
    CHECK(cpu.reg.b == 62);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 143);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 215);
    CHECK(cpu.reg.l == 100);
    CHECK(cpu.reg.pc == 60081);
    // CHECK(cpu.reg.sp == 59907);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60080] == 0);
}

TEST_CASE( "00 019A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20535;
    cpu.reg.sp = 59767;
    cpu.reg.a = 171;
    cpu.reg.b = 202;
    cpu.reg.c = 44;
    cpu.reg.d = 152;
    cpu.reg.e = 245;
    cpu.reg.f = 144;
    cpu.reg.h = 35;
    cpu.reg.l = 174;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[20535] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 171);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 44);
    CHECK(cpu.reg.d == 152);
    CHECK(cpu.reg.e == 245);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 35);
    CHECK(cpu.reg.l == 174);
    CHECK(cpu.reg.pc == 20536);
    // CHECK(cpu.reg.sp == 59767);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20535] == 0);
}

TEST_CASE( "00 019B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25007;
    cpu.reg.sp = 57614;
    cpu.reg.a = 68;
    cpu.reg.b = 224;
    cpu.reg.c = 162;
    cpu.reg.d = 59;
    cpu.reg.e = 236;
    cpu.reg.f = 16;
    cpu.reg.h = 1;
    cpu.reg.l = 102;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[25007] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 59);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 1);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 25008);
    // CHECK(cpu.reg.sp == 57614);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25007] == 0);
}

TEST_CASE( "00 019C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46223;
    cpu.reg.sp = 28449;
    cpu.reg.a = 240;
    cpu.reg.b = 151;
    cpu.reg.c = 16;
    cpu.reg.d = 101;
    cpu.reg.e = 252;
    cpu.reg.f = 208;
    cpu.reg.h = 201;
    cpu.reg.l = 126;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[46223] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 240);
    CHECK(cpu.reg.b == 151);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 101);
    CHECK(cpu.reg.e == 252);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 201);
    CHECK(cpu.reg.l == 126);
    CHECK(cpu.reg.pc == 46224);
    // CHECK(cpu.reg.sp == 28449);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46223] == 0);
}

TEST_CASE( "00 019D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 714;
    cpu.reg.sp = 51134;
    cpu.reg.a = 122;
    cpu.reg.b = 113;
    cpu.reg.c = 171;
    cpu.reg.d = 202;
    cpu.reg.e = 195;
    cpu.reg.f = 16;
    cpu.reg.h = 4;
    cpu.reg.l = 18;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[714] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 122);
    CHECK(cpu.reg.b == 113);
    CHECK(cpu.reg.c == 171);
    CHECK(cpu.reg.d == 202);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 4);
    CHECK(cpu.reg.l == 18);
    CHECK(cpu.reg.pc == 715);
    // CHECK(cpu.reg.sp == 51134);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[714] == 0);
}

TEST_CASE( "00 019E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49441;
    cpu.reg.sp = 12893;
    cpu.reg.a = 254;
    cpu.reg.b = 249;
    cpu.reg.c = 52;
    cpu.reg.d = 143;
    cpu.reg.e = 159;
    cpu.reg.f = 112;
    cpu.reg.h = 38;
    cpu.reg.l = 194;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49441] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 254);
    CHECK(cpu.reg.b == 249);
    CHECK(cpu.reg.c == 52);
    CHECK(cpu.reg.d == 143);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 194);
    CHECK(cpu.reg.pc == 49442);
    // CHECK(cpu.reg.sp == 12893);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49441] == 0);
}

TEST_CASE( "00 019F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8807;
    cpu.reg.sp = 61852;
    cpu.reg.a = 234;
    cpu.reg.b = 73;
    cpu.reg.c = 129;
    cpu.reg.d = 203;
    cpu.reg.e = 222;
    cpu.reg.f = 128;
    cpu.reg.h = 99;
    cpu.reg.l = 80;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[8807] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 234);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 129);
    CHECK(cpu.reg.d == 203);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 80);
    CHECK(cpu.reg.pc == 8808);
    // CHECK(cpu.reg.sp == 61852);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8807] == 0);
}

TEST_CASE( "00 01A0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19882;
    cpu.reg.sp = 55300;
    cpu.reg.a = 89;
    cpu.reg.b = 169;
    cpu.reg.c = 84;
    cpu.reg.d = 68;
    cpu.reg.e = 65;
    cpu.reg.f = 32;
    cpu.reg.h = 31;
    cpu.reg.l = 238;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[19882] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 89);
    CHECK(cpu.reg.b == 169);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 65);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 31);
    CHECK(cpu.reg.l == 238);
    CHECK(cpu.reg.pc == 19883);
    // CHECK(cpu.reg.sp == 55300);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19882] == 0);
}

TEST_CASE( "00 01A1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37852;
    cpu.reg.sp = 39242;
    cpu.reg.a = 2;
    cpu.reg.b = 205;
    cpu.reg.c = 227;
    cpu.reg.d = 145;
    cpu.reg.e = 68;
    cpu.reg.f = 96;
    cpu.reg.h = 112;
    cpu.reg.l = 206;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37852] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 145);
    CHECK(cpu.reg.e == 68);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 206);
    CHECK(cpu.reg.pc == 37853);
    // CHECK(cpu.reg.sp == 39242);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37852] == 0);
}

TEST_CASE( "00 01A2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29057;
    cpu.reg.sp = 62021;
    cpu.reg.a = 139;
    cpu.reg.b = 106;
    cpu.reg.c = 146;
    cpu.reg.d = 240;
    cpu.reg.e = 124;
    cpu.reg.f = 0;
    cpu.reg.h = 1;
    cpu.reg.l = 176;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[29057] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 240);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 1);
    CHECK(cpu.reg.l == 176);
    CHECK(cpu.reg.pc == 29058);
    // CHECK(cpu.reg.sp == 62021);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29057] == 0);
}

TEST_CASE( "00 01A3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1898;
    cpu.reg.sp = 47431;
    cpu.reg.a = 250;
    cpu.reg.b = 207;
    cpu.reg.c = 163;
    cpu.reg.d = 114;
    cpu.reg.e = 147;
    cpu.reg.f = 224;
    cpu.reg.h = 44;
    cpu.reg.l = 192;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[1898] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 250);
    CHECK(cpu.reg.b == 207);
    CHECK(cpu.reg.c == 163);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 147);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 44);
    CHECK(cpu.reg.l == 192);
    CHECK(cpu.reg.pc == 1899);
    // CHECK(cpu.reg.sp == 47431);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[1898] == 0);
}

TEST_CASE( "00 01A4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10282;
    cpu.reg.sp = 27424;
    cpu.reg.a = 253;
    cpu.reg.b = 48;
    cpu.reg.c = 47;
    cpu.reg.d = 46;
    cpu.reg.e = 1;
    cpu.reg.f = 16;
    cpu.reg.h = 119;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[10282] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 253);
    CHECK(cpu.reg.b == 48);
    CHECK(cpu.reg.c == 47);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 119);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 10283);
    // CHECK(cpu.reg.sp == 27424);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10282] == 0);
}

TEST_CASE( "00 01A5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32219;
    cpu.reg.sp = 60534;
    cpu.reg.a = 165;
    cpu.reg.b = 66;
    cpu.reg.c = 234;
    cpu.reg.d = 89;
    cpu.reg.e = 1;
    cpu.reg.f = 128;
    cpu.reg.h = 161;
    cpu.reg.l = 8;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32219] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 165);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 234);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 8);
    CHECK(cpu.reg.pc == 32220);
    // CHECK(cpu.reg.sp == 60534);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32219] == 0);
}

TEST_CASE( "00 01A6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28805;
    cpu.reg.sp = 27959;
    cpu.reg.a = 74;
    cpu.reg.b = 67;
    cpu.reg.c = 71;
    cpu.reg.d = 252;
    cpu.reg.e = 97;
    cpu.reg.f = 64;
    cpu.reg.h = 162;
    cpu.reg.l = 133;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28805] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 74);
    CHECK(cpu.reg.b == 67);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 252);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 28806);
    // CHECK(cpu.reg.sp == 27959);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28805] == 0);
}

TEST_CASE( "00 01A7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15491;
    cpu.reg.sp = 21796;
    cpu.reg.a = 175;
    cpu.reg.b = 81;
    cpu.reg.c = 59;
    cpu.reg.d = 169;
    cpu.reg.e = 217;
    cpu.reg.f = 80;
    cpu.reg.h = 179;
    cpu.reg.l = 40;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[15491] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 175);
    CHECK(cpu.reg.b == 81);
    CHECK(cpu.reg.c == 59);
    CHECK(cpu.reg.d == 169);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 179);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 15492);
    // CHECK(cpu.reg.sp == 21796);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15491] == 0);
}

TEST_CASE( "00 01A8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36009;
    cpu.reg.sp = 19093;
    cpu.reg.a = 44;
    cpu.reg.b = 85;
    cpu.reg.c = 20;
    cpu.reg.d = 155;
    cpu.reg.e = 86;
    cpu.reg.f = 96;
    cpu.reg.h = 21;
    cpu.reg.l = 155;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[36009] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 44);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 20);
    CHECK(cpu.reg.d == 155);
    CHECK(cpu.reg.e == 86);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 21);
    CHECK(cpu.reg.l == 155);
    CHECK(cpu.reg.pc == 36010);
    // CHECK(cpu.reg.sp == 19093);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36009] == 0);
}

TEST_CASE( "00 01A9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28184;
    cpu.reg.sp = 4950;
    cpu.reg.a = 21;
    cpu.reg.b = 227;
    cpu.reg.c = 92;
    cpu.reg.d = 94;
    cpu.reg.e = 140;
    cpu.reg.f = 144;
    cpu.reg.h = 236;
    cpu.reg.l = 240;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28184] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 227);
    CHECK(cpu.reg.c == 92);
    CHECK(cpu.reg.d == 94);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 28185);
    // CHECK(cpu.reg.sp == 4950);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28184] == 0);
}

TEST_CASE( "00 01AA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6868;
    cpu.reg.sp = 15704;
    cpu.reg.a = 183;
    cpu.reg.b = 232;
    cpu.reg.c = 78;
    cpu.reg.d = 87;
    cpu.reg.e = 248;
    cpu.reg.f = 240;
    cpu.reg.h = 102;
    cpu.reg.l = 21;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[6868] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 232);
    CHECK(cpu.reg.c == 78);
    CHECK(cpu.reg.d == 87);
    CHECK(cpu.reg.e == 248);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 102);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 6869);
    // CHECK(cpu.reg.sp == 15704);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[6868] == 0);
}

TEST_CASE( "00 01AB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7977;
    cpu.reg.sp = 2256;
    cpu.reg.a = 160;
    cpu.reg.b = 101;
    cpu.reg.c = 246;
    cpu.reg.d = 122;
    cpu.reg.e = 139;
    cpu.reg.f = 112;
    cpu.reg.h = 187;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[7977] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 160);
    CHECK(cpu.reg.b == 101);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 122);
    CHECK(cpu.reg.e == 139);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 187);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 7978);
    // CHECK(cpu.reg.sp == 2256);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7977] == 0);
}

TEST_CASE( "00 01AC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48075;
    cpu.reg.sp = 33169;
    cpu.reg.a = 170;
    cpu.reg.b = 50;
    cpu.reg.c = 1;
    cpu.reg.d = 73;
    cpu.reg.e = 102;
    cpu.reg.f = 224;
    cpu.reg.h = 54;
    cpu.reg.l = 147;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48075] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 170);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 1);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 102);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 54);
    CHECK(cpu.reg.l == 147);
    CHECK(cpu.reg.pc == 48076);
    // CHECK(cpu.reg.sp == 33169);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48075] == 0);
}

TEST_CASE( "00 01AD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 394;
    cpu.reg.sp = 11614;
    cpu.reg.a = 232;
    cpu.reg.b = 146;
    cpu.reg.c = 90;
    cpu.reg.d = 81;
    cpu.reg.e = 244;
    cpu.reg.f = 192;
    cpu.reg.h = 147;
    cpu.reg.l = 245;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[394] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 232);
    CHECK(cpu.reg.b == 146);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 81);
    CHECK(cpu.reg.e == 244);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 245);
    CHECK(cpu.reg.pc == 395);
    // CHECK(cpu.reg.sp == 11614);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[394] == 0);
}

TEST_CASE( "00 01AE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39023;
    cpu.reg.sp = 19719;
    cpu.reg.a = 50;
    cpu.reg.b = 153;
    cpu.reg.c = 49;
    cpu.reg.d = 244;
    cpu.reg.e = 46;
    cpu.reg.f = 144;
    cpu.reg.h = 187;
    cpu.reg.l = 238;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39023] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 153);
    CHECK(cpu.reg.c == 49);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 46);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 187);
    CHECK(cpu.reg.l == 238);
    CHECK(cpu.reg.pc == 39024);
    // CHECK(cpu.reg.sp == 19719);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39023] == 0);
}

TEST_CASE( "00 01AF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52614;
    cpu.reg.sp = 50188;
    cpu.reg.a = 42;
    cpu.reg.b = 234;
    cpu.reg.c = 43;
    cpu.reg.d = 209;
    cpu.reg.e = 169;
    cpu.reg.f = 48;
    cpu.reg.h = 175;
    cpu.reg.l = 247;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[52614] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 234);
    CHECK(cpu.reg.c == 43);
    CHECK(cpu.reg.d == 209);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 175);
    CHECK(cpu.reg.l == 247);
    CHECK(cpu.reg.pc == 52615);
    // CHECK(cpu.reg.sp == 50188);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52614] == 0);
}

TEST_CASE( "00 01B0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43194;
    cpu.reg.sp = 60067;
    cpu.reg.a = 67;
    cpu.reg.b = 103;
    cpu.reg.c = 166;
    cpu.reg.d = 66;
    cpu.reg.e = 76;
    cpu.reg.f = 192;
    cpu.reg.h = 38;
    cpu.reg.l = 123;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[43194] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 67);
    CHECK(cpu.reg.b == 103);
    CHECK(cpu.reg.c == 166);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 76);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 123);
    CHECK(cpu.reg.pc == 43195);
    // CHECK(cpu.reg.sp == 60067);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43194] == 0);
}

TEST_CASE( "00 01B1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47113;
    cpu.reg.sp = 51236;
    cpu.reg.a = 228;
    cpu.reg.b = 249;
    cpu.reg.c = 1;
    cpu.reg.d = 31;
    cpu.reg.e = 239;
    cpu.reg.f = 16;
    cpu.reg.h = 191;
    cpu.reg.l = 151;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[47113] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 228);
    CHECK(cpu.reg.b == 249);
    CHECK(cpu.reg.c == 1);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 239);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 151);
    CHECK(cpu.reg.pc == 47114);
    // CHECK(cpu.reg.sp == 51236);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[47113] == 0);
}

TEST_CASE( "00 01B2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26374;
    cpu.reg.sp = 766;
    cpu.reg.a = 205;
    cpu.reg.b = 172;
    cpu.reg.c = 133;
    cpu.reg.d = 156;
    cpu.reg.e = 162;
    cpu.reg.f = 240;
    cpu.reg.h = 109;
    cpu.reg.l = 69;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[26374] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 205);
    CHECK(cpu.reg.b == 172);
    CHECK(cpu.reg.c == 133);
    CHECK(cpu.reg.d == 156);
    CHECK(cpu.reg.e == 162);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 109);
    CHECK(cpu.reg.l == 69);
    CHECK(cpu.reg.pc == 26375);
    // CHECK(cpu.reg.sp == 766);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26374] == 0);
}

TEST_CASE( "00 01B3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1775;
    cpu.reg.sp = 22635;
    cpu.reg.a = 12;
    cpu.reg.b = 133;
    cpu.reg.c = 180;
    cpu.reg.d = 19;
    cpu.reg.e = 215;
    cpu.reg.f = 240;
    cpu.reg.h = 69;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[1775] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 12);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 180);
    CHECK(cpu.reg.d == 19);
    CHECK(cpu.reg.e == 215);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 1776);
    // CHECK(cpu.reg.sp == 22635);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1775] == 0);
}

TEST_CASE( "00 01B4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46204;
    cpu.reg.sp = 24515;
    cpu.reg.a = 236;
    cpu.reg.b = 92;
    cpu.reg.c = 118;
    cpu.reg.d = 73;
    cpu.reg.e = 8;
    cpu.reg.f = 224;
    cpu.reg.h = 80;
    cpu.reg.l = 110;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46204] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 236);
    CHECK(cpu.reg.b == 92);
    CHECK(cpu.reg.c == 118);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 8);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 110);
    CHECK(cpu.reg.pc == 46205);
    // CHECK(cpu.reg.sp == 24515);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46204] == 0);
}

TEST_CASE( "00 01B5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26122;
    cpu.reg.sp = 45240;
    cpu.reg.a = 17;
    cpu.reg.b = 83;
    cpu.reg.c = 231;
    cpu.reg.d = 230;
    cpu.reg.e = 172;
    cpu.reg.f = 160;
    cpu.reg.h = 99;
    cpu.reg.l = 73;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[26122] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 17);
    CHECK(cpu.reg.b == 83);
    CHECK(cpu.reg.c == 231);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 172);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 26123);
    // CHECK(cpu.reg.sp == 45240);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26122] == 0);
}

TEST_CASE( "00 01B6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11930;
    cpu.reg.sp = 38202;
    cpu.reg.a = 57;
    cpu.reg.b = 140;
    cpu.reg.c = 142;
    cpu.reg.d = 188;
    cpu.reg.e = 191;
    cpu.reg.f = 80;
    cpu.reg.h = 36;
    cpu.reg.l = 216;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[11930] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 57);
    CHECK(cpu.reg.b == 140);
    CHECK(cpu.reg.c == 142);
    CHECK(cpu.reg.d == 188);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 36);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 11931);
    // CHECK(cpu.reg.sp == 38202);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11930] == 0);
}

TEST_CASE( "00 01B7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26137;
    cpu.reg.sp = 45287;
    cpu.reg.a = 88;
    cpu.reg.b = 64;
    cpu.reg.c = 108;
    cpu.reg.d = 89;
    cpu.reg.e = 22;
    cpu.reg.f = 80;
    cpu.reg.h = 128;
    cpu.reg.l = 45;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26137] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 88);
    CHECK(cpu.reg.b == 64);
    CHECK(cpu.reg.c == 108);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 22);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 128);
    CHECK(cpu.reg.l == 45);
    CHECK(cpu.reg.pc == 26138);
    // CHECK(cpu.reg.sp == 45287);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26137] == 0);
}

TEST_CASE( "00 01B8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63452;
    cpu.reg.sp = 61568;
    cpu.reg.a = 56;
    cpu.reg.b = 66;
    cpu.reg.c = 162;
    cpu.reg.d = 205;
    cpu.reg.e = 246;
    cpu.reg.f = 0;
    cpu.reg.h = 182;
    cpu.reg.l = 75;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[63452] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 205);
    CHECK(cpu.reg.e == 246);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 75);
    CHECK(cpu.reg.pc == 63453);
    // CHECK(cpu.reg.sp == 61568);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[63452] == 0);
}

TEST_CASE( "00 01B9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47397;
    cpu.reg.sp = 57895;
    cpu.reg.a = 153;
    cpu.reg.b = 233;
    cpu.reg.c = 105;
    cpu.reg.d = 168;
    cpu.reg.e = 175;
    cpu.reg.f = 224;
    cpu.reg.h = 52;
    cpu.reg.l = 101;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[47397] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 233);
    CHECK(cpu.reg.c == 105);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 175);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 52);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 47398);
    // CHECK(cpu.reg.sp == 57895);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47397] == 0);
}

TEST_CASE( "00 01BA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54930;
    cpu.reg.sp = 60190;
    cpu.reg.a = 68;
    cpu.reg.b = 133;
    cpu.reg.c = 13;
    cpu.reg.d = 14;
    cpu.reg.e = 121;
    cpu.reg.f = 176;
    cpu.reg.h = 254;
    cpu.reg.l = 54;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54930] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 14);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 254);
    CHECK(cpu.reg.l == 54);
    CHECK(cpu.reg.pc == 54931);
    // CHECK(cpu.reg.sp == 60190);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54930] == 0);
}

TEST_CASE( "00 01BB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1493;
    cpu.reg.sp = 32093;
    cpu.reg.a = 191;
    cpu.reg.b = 239;
    cpu.reg.c = 90;
    cpu.reg.d = 185;
    cpu.reg.e = 19;
    cpu.reg.f = 32;
    cpu.reg.h = 28;
    cpu.reg.l = 221;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[1493] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 239);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 1494);
    // CHECK(cpu.reg.sp == 32093);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[1493] == 0);
}

TEST_CASE( "00 01BC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53816;
    cpu.reg.sp = 46799;
    cpu.reg.a = 175;
    cpu.reg.b = 38;
    cpu.reg.c = 12;
    cpu.reg.d = 168;
    cpu.reg.e = 66;
    cpu.reg.f = 144;
    cpu.reg.h = 208;
    cpu.reg.l = 221;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[53816] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 175);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 66);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 208);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 53817);
    // CHECK(cpu.reg.sp == 46799);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53816] == 0);
}

TEST_CASE( "00 01BD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22799;
    cpu.reg.sp = 11012;
    cpu.reg.a = 161;
    cpu.reg.b = 143;
    cpu.reg.c = 188;
    cpu.reg.d = 150;
    cpu.reg.e = 217;
    cpu.reg.f = 160;
    cpu.reg.h = 222;
    cpu.reg.l = 129;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[22799] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 161);
    CHECK(cpu.reg.b == 143);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 150);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 222);
    CHECK(cpu.reg.l == 129);
    CHECK(cpu.reg.pc == 22800);
    // CHECK(cpu.reg.sp == 11012);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22799] == 0);
}

TEST_CASE( "00 01BE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52909;
    cpu.reg.sp = 39939;
    cpu.reg.a = 234;
    cpu.reg.b = 221;
    cpu.reg.c = 36;
    cpu.reg.d = 54;
    cpu.reg.e = 99;
    cpu.reg.f = 112;
    cpu.reg.h = 138;
    cpu.reg.l = 223;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[52909] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 234);
    CHECK(cpu.reg.b == 221);
    CHECK(cpu.reg.c == 36);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 138);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 52910);
    // CHECK(cpu.reg.sp == 39939);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52909] == 0);
}

TEST_CASE( "00 01BF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32674;
    cpu.reg.sp = 26237;
    cpu.reg.a = 36;
    cpu.reg.b = 223;
    cpu.reg.c = 183;
    cpu.reg.d = 227;
    cpu.reg.e = 167;
    cpu.reg.f = 192;
    cpu.reg.h = 140;
    cpu.reg.l = 54;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32674] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 36);
    CHECK(cpu.reg.b == 223);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 227);
    CHECK(cpu.reg.e == 167);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 54);
    CHECK(cpu.reg.pc == 32675);
    // CHECK(cpu.reg.sp == 26237);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32674] == 0);
}

TEST_CASE( "00 01C0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54592;
    cpu.reg.sp = 37701;
    cpu.reg.a = 204;
    cpu.reg.b = 229;
    cpu.reg.c = 184;
    cpu.reg.d = 125;
    cpu.reg.e = 219;
    cpu.reg.f = 224;
    cpu.reg.h = 252;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54592] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 204);
    CHECK(cpu.reg.b == 229);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 125);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 54593);
    // CHECK(cpu.reg.sp == 37701);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54592] == 0);
}

TEST_CASE( "00 01C1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27374;
    cpu.reg.sp = 61522;
    cpu.reg.a = 14;
    cpu.reg.b = 74;
    cpu.reg.c = 198;
    cpu.reg.d = 206;
    cpu.reg.e = 236;
    cpu.reg.f = 176;
    cpu.reg.h = 60;
    cpu.reg.l = 35;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[27374] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 74);
    CHECK(cpu.reg.c == 198);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 35);
    CHECK(cpu.reg.pc == 27375);
    // CHECK(cpu.reg.sp == 61522);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27374] == 0);
}

TEST_CASE( "00 01C2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 713;
    cpu.reg.sp = 30244;
    cpu.reg.a = 81;
    cpu.reg.b = 120;
    cpu.reg.c = 11;
    cpu.reg.d = 22;
    cpu.reg.e = 17;
    cpu.reg.f = 192;
    cpu.reg.h = 141;
    cpu.reg.l = 112;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[713] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 120);
    CHECK(cpu.reg.c == 11);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 112);
    CHECK(cpu.reg.pc == 714);
    // CHECK(cpu.reg.sp == 30244);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[713] == 0);
}

TEST_CASE( "00 01C3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59073;
    cpu.reg.sp = 10154;
    cpu.reg.a = 28;
    cpu.reg.b = 1;
    cpu.reg.c = 95;
    cpu.reg.d = 71;
    cpu.reg.e = 244;
    cpu.reg.f = 64;
    cpu.reg.h = 160;
    cpu.reg.l = 79;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[59073] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 28);
    CHECK(cpu.reg.b == 1);
    CHECK(cpu.reg.c == 95);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 244);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 79);
    CHECK(cpu.reg.pc == 59074);
    // CHECK(cpu.reg.sp == 10154);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59073] == 0);
}

TEST_CASE( "00 01C4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46980;
    cpu.reg.sp = 55764;
    cpu.reg.a = 56;
    cpu.reg.b = 30;
    cpu.reg.c = 254;
    cpu.reg.d = 36;
    cpu.reg.e = 39;
    cpu.reg.f = 32;
    cpu.reg.h = 202;
    cpu.reg.l = 243;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46980] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 30);
    CHECK(cpu.reg.c == 254);
    CHECK(cpu.reg.d == 36);
    CHECK(cpu.reg.e == 39);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 202);
    CHECK(cpu.reg.l == 243);
    CHECK(cpu.reg.pc == 46981);
    // CHECK(cpu.reg.sp == 55764);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46980] == 0);
}

TEST_CASE( "00 01C5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47317;
    cpu.reg.sp = 38135;
    cpu.reg.a = 8;
    cpu.reg.b = 203;
    cpu.reg.c = 230;
    cpu.reg.d = 110;
    cpu.reg.e = 97;
    cpu.reg.f = 208;
    cpu.reg.h = 210;
    cpu.reg.l = 165;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[47317] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 203);
    CHECK(cpu.reg.c == 230);
    CHECK(cpu.reg.d == 110);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 210);
    CHECK(cpu.reg.l == 165);
    CHECK(cpu.reg.pc == 47318);
    // CHECK(cpu.reg.sp == 38135);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47317] == 0);
}

TEST_CASE( "00 01C6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62654;
    cpu.reg.sp = 14269;
    cpu.reg.a = 188;
    cpu.reg.b = 182;
    cpu.reg.c = 127;
    cpu.reg.d = 102;
    cpu.reg.e = 90;
    cpu.reg.f = 176;
    cpu.reg.h = 246;
    cpu.reg.l = 214;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[62654] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 188);
    CHECK(cpu.reg.b == 182);
    CHECK(cpu.reg.c == 127);
    CHECK(cpu.reg.d == 102);
    CHECK(cpu.reg.e == 90);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 246);
    CHECK(cpu.reg.l == 214);
    CHECK(cpu.reg.pc == 62655);
    // CHECK(cpu.reg.sp == 14269);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62654] == 0);
}

TEST_CASE( "00 01C7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9818;
    cpu.reg.sp = 1952;
    cpu.reg.a = 218;
    cpu.reg.b = 201;
    cpu.reg.c = 173;
    cpu.reg.d = 180;
    cpu.reg.e = 65;
    cpu.reg.f = 208;
    cpu.reg.h = 93;
    cpu.reg.l = 206;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[9818] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 201);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 180);
    CHECK(cpu.reg.e == 65);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 93);
    CHECK(cpu.reg.l == 206);
    CHECK(cpu.reg.pc == 9819);
    // CHECK(cpu.reg.sp == 1952);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9818] == 0);
}

TEST_CASE( "00 01C8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62189;
    cpu.reg.sp = 53532;
    cpu.reg.a = 6;
    cpu.reg.b = 62;
    cpu.reg.c = 153;
    cpu.reg.d = 69;
    cpu.reg.e = 121;
    cpu.reg.f = 160;
    cpu.reg.h = 32;
    cpu.reg.l = 20;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62189] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 6);
    CHECK(cpu.reg.b == 62);
    CHECK(cpu.reg.c == 153);
    CHECK(cpu.reg.d == 69);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 32);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 62190);
    // CHECK(cpu.reg.sp == 53532);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62189] == 0);
}

TEST_CASE( "00 01C9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64895;
    cpu.reg.sp = 57455;
    cpu.reg.a = 198;
    cpu.reg.b = 60;
    cpu.reg.c = 107;
    cpu.reg.d = 6;
    cpu.reg.e = 192;
    cpu.reg.f = 16;
    cpu.reg.h = 26;
    cpu.reg.l = 255;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64895] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 60);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 192);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 255);
    CHECK(cpu.reg.pc == 64896);
    // CHECK(cpu.reg.sp == 57455);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64895] == 0);
}

TEST_CASE( "00 01CA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2442;
    cpu.reg.sp = 50703;
    cpu.reg.a = 181;
    cpu.reg.b = 75;
    cpu.reg.c = 87;
    cpu.reg.d = 215;
    cpu.reg.e = 46;
    cpu.reg.f = 96;
    cpu.reg.h = 147;
    cpu.reg.l = 110;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[2442] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 181);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 87);
    CHECK(cpu.reg.d == 215);
    CHECK(cpu.reg.e == 46);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 110);
    CHECK(cpu.reg.pc == 2443);
    // CHECK(cpu.reg.sp == 50703);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[2442] == 0);
}

TEST_CASE( "00 01CB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10832;
    cpu.reg.sp = 49725;
    cpu.reg.a = 8;
    cpu.reg.b = 1;
    cpu.reg.c = 252;
    cpu.reg.d = 241;
    cpu.reg.e = 71;
    cpu.reg.f = 208;
    cpu.reg.h = 221;
    cpu.reg.l = 254;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[10832] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 1);
    CHECK(cpu.reg.c == 252);
    CHECK(cpu.reg.d == 241);
    CHECK(cpu.reg.e == 71);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 221);
    CHECK(cpu.reg.l == 254);
    CHECK(cpu.reg.pc == 10833);
    // CHECK(cpu.reg.sp == 49725);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10832] == 0);
}

TEST_CASE( "00 01CC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44799;
    cpu.reg.sp = 57100;
    cpu.reg.a = 60;
    cpu.reg.b = 57;
    cpu.reg.c = 83;
    cpu.reg.d = 226;
    cpu.reg.e = 220;
    cpu.reg.f = 224;
    cpu.reg.h = 114;
    cpu.reg.l = 72;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44799] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 60);
    CHECK(cpu.reg.b == 57);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 220);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 114);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 44800);
    // CHECK(cpu.reg.sp == 57100);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44799] == 0);
}

TEST_CASE( "00 01CD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28888;
    cpu.reg.sp = 39082;
    cpu.reg.a = 102;
    cpu.reg.b = 180;
    cpu.reg.c = 84;
    cpu.reg.d = 108;
    cpu.reg.e = 1;
    cpu.reg.f = 192;
    cpu.reg.h = 172;
    cpu.reg.l = 156;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28888] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 102);
    CHECK(cpu.reg.b == 180);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 172);
    CHECK(cpu.reg.l == 156);
    CHECK(cpu.reg.pc == 28889);
    // CHECK(cpu.reg.sp == 39082);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28888] == 0);
}

TEST_CASE( "00 01CE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17332;
    cpu.reg.sp = 61411;
    cpu.reg.a = 8;
    cpu.reg.b = 240;
    cpu.reg.c = 51;
    cpu.reg.d = 40;
    cpu.reg.e = 160;
    cpu.reg.f = 80;
    cpu.reg.h = 66;
    cpu.reg.l = 60;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[17332] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 240);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 40);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 66);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 17333);
    // CHECK(cpu.reg.sp == 61411);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[17332] == 0);
}

TEST_CASE( "00 01CF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60925;
    cpu.reg.sp = 21872;
    cpu.reg.a = 198;
    cpu.reg.b = 91;
    cpu.reg.c = 152;
    cpu.reg.d = 1;
    cpu.reg.e = 140;
    cpu.reg.f = 80;
    cpu.reg.h = 196;
    cpu.reg.l = 140;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[60925] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 91);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 1);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 196);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 60926);
    // CHECK(cpu.reg.sp == 21872);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60925] == 0);
}

TEST_CASE( "00 01D0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47601;
    cpu.reg.sp = 57633;
    cpu.reg.a = 171;
    cpu.reg.b = 73;
    cpu.reg.c = 162;
    cpu.reg.d = 131;
    cpu.reg.e = 63;
    cpu.reg.f = 144;
    cpu.reg.h = 21;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[47601] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 171);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 131);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 21);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 47602);
    // CHECK(cpu.reg.sp == 57633);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47601] == 0);
}

TEST_CASE( "00 01D1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22115;
    cpu.reg.sp = 65039;
    cpu.reg.a = 3;
    cpu.reg.b = 191;
    cpu.reg.c = 31;
    cpu.reg.d = 144;
    cpu.reg.e = 34;
    cpu.reg.f = 144;
    cpu.reg.h = 252;
    cpu.reg.l = 123;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[22115] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 31);
    CHECK(cpu.reg.d == 144);
    CHECK(cpu.reg.e == 34);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 123);
    CHECK(cpu.reg.pc == 22116);
    // CHECK(cpu.reg.sp == 65039);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22115] == 0);
}

TEST_CASE( "00 01D2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28796;
    cpu.reg.sp = 63895;
    cpu.reg.a = 38;
    cpu.reg.b = 219;
    cpu.reg.c = 183;
    cpu.reg.d = 168;
    cpu.reg.e = 5;
    cpu.reg.f = 192;
    cpu.reg.h = 154;
    cpu.reg.l = 209;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28796] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 38);
    CHECK(cpu.reg.b == 219);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 5);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 209);
    CHECK(cpu.reg.pc == 28797);
    // CHECK(cpu.reg.sp == 63895);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28796] == 0);
}

TEST_CASE( "00 01D3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43557;
    cpu.reg.sp = 52016;
    cpu.reg.a = 217;
    cpu.reg.b = 35;
    cpu.reg.c = 5;
    cpu.reg.d = 48;
    cpu.reg.e = 174;
    cpu.reg.f = 176;
    cpu.reg.h = 176;
    cpu.reg.l = 153;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43557] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 217);
    CHECK(cpu.reg.b == 35);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 174);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 176);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 43558);
    // CHECK(cpu.reg.sp == 52016);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43557] == 0);
}

TEST_CASE( "00 01D4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5128;
    cpu.reg.sp = 61158;
    cpu.reg.a = 84;
    cpu.reg.b = 119;
    cpu.reg.c = 44;
    cpu.reg.d = 186;
    cpu.reg.e = 108;
    cpu.reg.f = 176;
    cpu.reg.h = 29;
    cpu.reg.l = 210;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5128] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 44);
    CHECK(cpu.reg.d == 186);
    CHECK(cpu.reg.e == 108);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 29);
    CHECK(cpu.reg.l == 210);
    CHECK(cpu.reg.pc == 5129);
    // CHECK(cpu.reg.sp == 61158);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5128] == 0);
}

TEST_CASE( "00 01D5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12435;
    cpu.reg.sp = 14317;
    cpu.reg.a = 144;
    cpu.reg.b = 18;
    cpu.reg.c = 86;
    cpu.reg.d = 204;
    cpu.reg.e = 169;
    cpu.reg.f = 192;
    cpu.reg.h = 178;
    cpu.reg.l = 171;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[12435] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 144);
    CHECK(cpu.reg.b == 18);
    CHECK(cpu.reg.c == 86);
    CHECK(cpu.reg.d == 204);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 171);
    CHECK(cpu.reg.pc == 12436);
    // CHECK(cpu.reg.sp == 14317);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12435] == 0);
}

TEST_CASE( "00 01D6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28300;
    cpu.reg.sp = 18710;
    cpu.reg.a = 13;
    cpu.reg.b = 191;
    cpu.reg.c = 144;
    cpu.reg.d = 152;
    cpu.reg.e = 104;
    cpu.reg.f = 192;
    cpu.reg.h = 184;
    cpu.reg.l = 156;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[28300] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 13);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 144);
    CHECK(cpu.reg.d == 152);
    CHECK(cpu.reg.e == 104);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 156);
    CHECK(cpu.reg.pc == 28301);
    // CHECK(cpu.reg.sp == 18710);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28300] == 0);
}

TEST_CASE( "00 01D7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 494;
    cpu.reg.sp = 28347;
    cpu.reg.a = 91;
    cpu.reg.b = 235;
    cpu.reg.c = 184;
    cpu.reg.d = 18;
    cpu.reg.e = 171;
    cpu.reg.f = 224;
    cpu.reg.h = 38;
    cpu.reg.l = 99;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[494] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 91);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 18);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 495);
    // CHECK(cpu.reg.sp == 28347);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[494] == 0);
}

TEST_CASE( "00 01D8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53053;
    cpu.reg.sp = 61410;
    cpu.reg.a = 68;
    cpu.reg.b = 4;
    cpu.reg.c = 227;
    cpu.reg.d = 67;
    cpu.reg.e = 50;
    cpu.reg.f = 176;
    cpu.reg.h = 28;
    cpu.reg.l = 173;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[53053] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 67);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 173);
    CHECK(cpu.reg.pc == 53054);
    // CHECK(cpu.reg.sp == 61410);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53053] == 0);
}

TEST_CASE( "00 01D9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50287;
    cpu.reg.sp = 4459;
    cpu.reg.a = 117;
    cpu.reg.b = 142;
    cpu.reg.c = 17;
    cpu.reg.d = 221;
    cpu.reg.e = 61;
    cpu.reg.f = 192;
    cpu.reg.h = 207;
    cpu.reg.l = 209;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[50287] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 142);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 221);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 207);
    CHECK(cpu.reg.l == 209);
    CHECK(cpu.reg.pc == 50288);
    // CHECK(cpu.reg.sp == 4459);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50287] == 0);
}

TEST_CASE( "00 01DA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59591;
    cpu.reg.sp = 22571;
    cpu.reg.a = 168;
    cpu.reg.b = 219;
    cpu.reg.c = 37;
    cpu.reg.d = 33;
    cpu.reg.e = 175;
    cpu.reg.f = 240;
    cpu.reg.h = 45;
    cpu.reg.l = 67;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[59591] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 168);
    CHECK(cpu.reg.b == 219);
    CHECK(cpu.reg.c == 37);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 175);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 45);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 59592);
    // CHECK(cpu.reg.sp == 22571);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[59591] == 0);
}

TEST_CASE( "00 01DB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38708;
    cpu.reg.sp = 15646;
    cpu.reg.a = 232;
    cpu.reg.b = 108;
    cpu.reg.c = 123;
    cpu.reg.d = 61;
    cpu.reg.e = 64;
    cpu.reg.f = 96;
    cpu.reg.h = 71;
    cpu.reg.l = 116;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[38708] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 232);
    CHECK(cpu.reg.b == 108);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 61);
    CHECK(cpu.reg.e == 64);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 116);
    CHECK(cpu.reg.pc == 38709);
    // CHECK(cpu.reg.sp == 15646);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[38708] == 0);
}

TEST_CASE( "00 01DC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39999;
    cpu.reg.sp = 38279;
    cpu.reg.a = 136;
    cpu.reg.b = 181;
    cpu.reg.c = 76;
    cpu.reg.d = 5;
    cpu.reg.e = 245;
    cpu.reg.f = 176;
    cpu.reg.h = 250;
    cpu.reg.l = 139;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39999] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 136);
    CHECK(cpu.reg.b == 181);
    CHECK(cpu.reg.c == 76);
    CHECK(cpu.reg.d == 5);
    CHECK(cpu.reg.e == 245);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 250);
    CHECK(cpu.reg.l == 139);
    CHECK(cpu.reg.pc == 40000);
    // CHECK(cpu.reg.sp == 38279);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39999] == 0);
}

TEST_CASE( "00 01DD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 285;
    cpu.reg.sp = 62899;
    cpu.reg.a = 14;
    cpu.reg.b = 217;
    cpu.reg.c = 229;
    cpu.reg.d = 104;
    cpu.reg.e = 72;
    cpu.reg.f = 48;
    cpu.reg.h = 209;
    cpu.reg.l = 165;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[285] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 217);
    CHECK(cpu.reg.c == 229);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 165);
    CHECK(cpu.reg.pc == 286);
    // CHECK(cpu.reg.sp == 62899);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[285] == 0);
}

TEST_CASE( "00 01DE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15996;
    cpu.reg.sp = 18347;
    cpu.reg.a = 169;
    cpu.reg.b = 22;
    cpu.reg.c = 245;
    cpu.reg.d = 165;
    cpu.reg.e = 112;
    cpu.reg.f = 144;
    cpu.reg.h = 74;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[15996] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 169);
    CHECK(cpu.reg.b == 22);
    CHECK(cpu.reg.c == 245);
    CHECK(cpu.reg.d == 165);
    CHECK(cpu.reg.e == 112);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 74);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 15997);
    // CHECK(cpu.reg.sp == 18347);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[15996] == 0);
}

TEST_CASE( "00 01DF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1165;
    cpu.reg.sp = 26432;
    cpu.reg.a = 10;
    cpu.reg.b = 203;
    cpu.reg.c = 191;
    cpu.reg.d = 104;
    cpu.reg.e = 217;
    cpu.reg.f = 80;
    cpu.reg.h = 166;
    cpu.reg.l = 72;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[1165] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 203);
    CHECK(cpu.reg.c == 191);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 166);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 1166);
    // CHECK(cpu.reg.sp == 26432);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[1165] == 0);
}

TEST_CASE( "00 01E0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21146;
    cpu.reg.sp = 15133;
    cpu.reg.a = 50;
    cpu.reg.b = 58;
    cpu.reg.c = 142;
    cpu.reg.d = 124;
    cpu.reg.e = 177;
    cpu.reg.f = 48;
    cpu.reg.h = 255;
    cpu.reg.l = 56;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21146] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 58);
    CHECK(cpu.reg.c == 142);
    CHECK(cpu.reg.d == 124);
    CHECK(cpu.reg.e == 177);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 255);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 21147);
    // CHECK(cpu.reg.sp == 15133);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21146] == 0);
}

TEST_CASE( "00 01E1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30330;
    cpu.reg.sp = 5530;
    cpu.reg.a = 215;
    cpu.reg.b = 5;
    cpu.reg.c = 188;
    cpu.reg.d = 162;
    cpu.reg.e = 38;
    cpu.reg.f = 160;
    cpu.reg.h = 137;
    cpu.reg.l = 35;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30330] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 5);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 162);
    CHECK(cpu.reg.e == 38);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 137);
    CHECK(cpu.reg.l == 35);
    CHECK(cpu.reg.pc == 30331);
    // CHECK(cpu.reg.sp == 5530);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30330] == 0);
}

TEST_CASE( "00 01E2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2834;
    cpu.reg.sp = 10555;
    cpu.reg.a = 103;
    cpu.reg.b = 46;
    cpu.reg.c = 103;
    cpu.reg.d = 163;
    cpu.reg.e = 3;
    cpu.reg.f = 112;
    cpu.reg.h = 220;
    cpu.reg.l = 120;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[2834] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 46);
    CHECK(cpu.reg.c == 103);
    CHECK(cpu.reg.d == 163);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 220);
    CHECK(cpu.reg.l == 120);
    CHECK(cpu.reg.pc == 2835);
    // CHECK(cpu.reg.sp == 10555);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2834] == 0);
}

TEST_CASE( "00 01E3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43180;
    cpu.reg.sp = 34115;
    cpu.reg.a = 79;
    cpu.reg.b = 247;
    cpu.reg.c = 72;
    cpu.reg.d = 174;
    cpu.reg.e = 142;
    cpu.reg.f = 32;
    cpu.reg.h = 247;
    cpu.reg.l = 81;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43180] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 79);
    CHECK(cpu.reg.b == 247);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 174);
    CHECK(cpu.reg.e == 142);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 43181);
    // CHECK(cpu.reg.sp == 34115);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43180] == 0);
}

TEST_CASE( "00 01E4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63654;
    cpu.reg.sp = 15037;
    cpu.reg.a = 71;
    cpu.reg.b = 103;
    cpu.reg.c = 73;
    cpu.reg.d = 90;
    cpu.reg.e = 51;
    cpu.reg.f = 208;
    cpu.reg.h = 12;
    cpu.reg.l = 108;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[63654] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 71);
    CHECK(cpu.reg.b == 103);
    CHECK(cpu.reg.c == 73);
    CHECK(cpu.reg.d == 90);
    CHECK(cpu.reg.e == 51);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 108);
    CHECK(cpu.reg.pc == 63655);
    // CHECK(cpu.reg.sp == 15037);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63654] == 0);
}

TEST_CASE( "00 01E5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60009;
    cpu.reg.sp = 48732;
    cpu.reg.a = 39;
    cpu.reg.b = 20;
    cpu.reg.c = 24;
    cpu.reg.d = 208;
    cpu.reg.e = 154;
    cpu.reg.f = 96;
    cpu.reg.h = 26;
    cpu.reg.l = 20;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[60009] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 39);
    CHECK(cpu.reg.b == 20);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 154);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 60010);
    // CHECK(cpu.reg.sp == 48732);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60009] == 0);
}

TEST_CASE( "00 01E6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34638;
    cpu.reg.sp = 18035;
    cpu.reg.a = 66;
    cpu.reg.b = 143;
    cpu.reg.c = 188;
    cpu.reg.d = 115;
    cpu.reg.e = 107;
    cpu.reg.f = 176;
    cpu.reg.h = 106;
    cpu.reg.l = 147;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[34638] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 143);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 115);
    CHECK(cpu.reg.e == 107);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 147);
    CHECK(cpu.reg.pc == 34639);
    // CHECK(cpu.reg.sp == 18035);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34638] == 0);
}

TEST_CASE( "00 01E7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35738;
    cpu.reg.sp = 20162;
    cpu.reg.a = 144;
    cpu.reg.b = 250;
    cpu.reg.c = 236;
    cpu.reg.d = 190;
    cpu.reg.e = 242;
    cpu.reg.f = 224;
    cpu.reg.h = 80;
    cpu.reg.l = 45;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[35738] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 144);
    CHECK(cpu.reg.b == 250);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 190);
    CHECK(cpu.reg.e == 242);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 45);
    CHECK(cpu.reg.pc == 35739);
    // CHECK(cpu.reg.sp == 20162);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35738] == 0);
}

TEST_CASE( "00 01E8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64468;
    cpu.reg.sp = 13017;
    cpu.reg.a = 228;
    cpu.reg.b = 48;
    cpu.reg.c = 26;
    cpu.reg.d = 100;
    cpu.reg.e = 78;
    cpu.reg.f = 48;
    cpu.reg.h = 53;
    cpu.reg.l = 141;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64468] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 228);
    CHECK(cpu.reg.b == 48);
    CHECK(cpu.reg.c == 26);
    CHECK(cpu.reg.d == 100);
    CHECK(cpu.reg.e == 78);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 141);
    CHECK(cpu.reg.pc == 64469);
    // CHECK(cpu.reg.sp == 13017);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64468] == 0);
}

TEST_CASE( "00 01E9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53311;
    cpu.reg.sp = 47347;
    cpu.reg.a = 29;
    cpu.reg.b = 37;
    cpu.reg.c = 151;
    cpu.reg.d = 78;
    cpu.reg.e = 196;
    cpu.reg.f = 224;
    cpu.reg.h = 174;
    cpu.reg.l = 116;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[53311] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 37);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 78);
    CHECK(cpu.reg.e == 196);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 174);
    CHECK(cpu.reg.l == 116);
    CHECK(cpu.reg.pc == 53312);
    // CHECK(cpu.reg.sp == 47347);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53311] == 0);
}

TEST_CASE( "00 01EA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6758;
    cpu.reg.sp = 17696;
    cpu.reg.a = 199;
    cpu.reg.b = 199;
    cpu.reg.c = 79;
    cpu.reg.d = 158;
    cpu.reg.e = 173;
    cpu.reg.f = 128;
    cpu.reg.h = 188;
    cpu.reg.l = 117;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6758] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 199);
    CHECK(cpu.reg.b == 199);
    CHECK(cpu.reg.c == 79);
    CHECK(cpu.reg.d == 158);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 6759);
    // CHECK(cpu.reg.sp == 17696);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6758] == 0);
}

TEST_CASE( "00 01EB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3542;
    cpu.reg.sp = 24797;
    cpu.reg.a = 212;
    cpu.reg.b = 135;
    cpu.reg.c = 81;
    cpu.reg.d = 202;
    cpu.reg.e = 168;
    cpu.reg.f = 112;
    cpu.reg.h = 174;
    cpu.reg.l = 73;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[3542] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 202);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 174);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 3543);
    // CHECK(cpu.reg.sp == 24797);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3542] == 0);
}

TEST_CASE( "00 01EC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6444;
    cpu.reg.sp = 21990;
    cpu.reg.a = 167;
    cpu.reg.b = 58;
    cpu.reg.c = 111;
    cpu.reg.d = 70;
    cpu.reg.e = 83;
    cpu.reg.f = 112;
    cpu.reg.h = 152;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[6444] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 167);
    CHECK(cpu.reg.b == 58);
    CHECK(cpu.reg.c == 111);
    CHECK(cpu.reg.d == 70);
    CHECK(cpu.reg.e == 83);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 152);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 6445);
    // CHECK(cpu.reg.sp == 21990);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6444] == 0);
}

TEST_CASE( "00 01ED", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59797;
    cpu.reg.sp = 4334;
    cpu.reg.a = 103;
    cpu.reg.b = 50;
    cpu.reg.c = 102;
    cpu.reg.d = 3;
    cpu.reg.e = 122;
    cpu.reg.f = 112;
    cpu.reg.h = 178;
    cpu.reg.l = 250;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[59797] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 102);
    CHECK(cpu.reg.d == 3);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 59798);
    // CHECK(cpu.reg.sp == 4334);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[59797] == 0);
}

TEST_CASE( "00 01EE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63474;
    cpu.reg.sp = 52726;
    cpu.reg.a = 56;
    cpu.reg.b = 192;
    cpu.reg.c = 92;
    cpu.reg.d = 177;
    cpu.reg.e = 69;
    cpu.reg.f = 144;
    cpu.reg.h = 242;
    cpu.reg.l = 165;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63474] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 192);
    CHECK(cpu.reg.c == 92);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 69);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 165);
    CHECK(cpu.reg.pc == 63475);
    // CHECK(cpu.reg.sp == 52726);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63474] == 0);
}

TEST_CASE( "00 01EF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64789;
    cpu.reg.sp = 10284;
    cpu.reg.a = 44;
    cpu.reg.b = 81;
    cpu.reg.c = 250;
    cpu.reg.d = 234;
    cpu.reg.e = 169;
    cpu.reg.f = 128;
    cpu.reg.h = 212;
    cpu.reg.l = 84;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64789] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 44);
    CHECK(cpu.reg.b == 81);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 212);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 64790);
    // CHECK(cpu.reg.sp == 10284);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64789] == 0);
}

TEST_CASE( "00 01F0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54614;
    cpu.reg.sp = 29554;
    cpu.reg.a = 192;
    cpu.reg.b = 218;
    cpu.reg.c = 63;
    cpu.reg.d = 82;
    cpu.reg.e = 32;
    cpu.reg.f = 96;
    cpu.reg.h = 185;
    cpu.reg.l = 48;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54614] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 192);
    CHECK(cpu.reg.b == 218);
    CHECK(cpu.reg.c == 63);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 185);
    CHECK(cpu.reg.l == 48);
    CHECK(cpu.reg.pc == 54615);
    // CHECK(cpu.reg.sp == 29554);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54614] == 0);
}

TEST_CASE( "00 01F1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12629;
    cpu.reg.sp = 48250;
    cpu.reg.a = 173;
    cpu.reg.b = 39;
    cpu.reg.c = 158;
    cpu.reg.d = 185;
    cpu.reg.e = 101;
    cpu.reg.f = 160;
    cpu.reg.h = 32;
    cpu.reg.l = 5;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[12629] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 173);
    CHECK(cpu.reg.b == 39);
    CHECK(cpu.reg.c == 158);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 101);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 32);
    CHECK(cpu.reg.l == 5);
    CHECK(cpu.reg.pc == 12630);
    // CHECK(cpu.reg.sp == 48250);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12629] == 0);
}

TEST_CASE( "00 01F2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11017;
    cpu.reg.sp = 56477;
    cpu.reg.a = 46;
    cpu.reg.b = 249;
    cpu.reg.c = 250;
    cpu.reg.d = 10;
    cpu.reg.e = 145;
    cpu.reg.f = 48;
    cpu.reg.h = 69;
    cpu.reg.l = 117;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[11017] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 46);
    CHECK(cpu.reg.b == 249);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 145);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 117);
    CHECK(cpu.reg.pc == 11018);
    // CHECK(cpu.reg.sp == 56477);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11017] == 0);
}

TEST_CASE( "00 01F3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43105;
    cpu.reg.sp = 37886;
    cpu.reg.a = 197;
    cpu.reg.b = 64;
    cpu.reg.c = 207;
    cpu.reg.d = 225;
    cpu.reg.e = 60;
    cpu.reg.f = 192;
    cpu.reg.h = 53;
    cpu.reg.l = 178;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43105] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 64);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 60);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 178);
    CHECK(cpu.reg.pc == 43106);
    // CHECK(cpu.reg.sp == 37886);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43105] == 0);
}

TEST_CASE( "00 01F4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6128;
    cpu.reg.sp = 16414;
    cpu.reg.a = 109;
    cpu.reg.b = 227;
    cpu.reg.c = 23;
    cpu.reg.d = 202;
    cpu.reg.e = 39;
    cpu.reg.f = 160;
    cpu.reg.h = 188;
    cpu.reg.l = 29;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[6128] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 109);
    CHECK(cpu.reg.b == 227);
    CHECK(cpu.reg.c == 23);
    CHECK(cpu.reg.d == 202);
    CHECK(cpu.reg.e == 39);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 29);
    CHECK(cpu.reg.pc == 6129);
    // CHECK(cpu.reg.sp == 16414);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6128] == 0);
}

TEST_CASE( "00 01F5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44123;
    cpu.reg.sp = 44857;
    cpu.reg.a = 15;
    cpu.reg.b = 161;
    cpu.reg.c = 200;
    cpu.reg.d = 22;
    cpu.reg.e = 179;
    cpu.reg.f = 176;
    cpu.reg.h = 151;
    cpu.reg.l = 81;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44123] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 161);
    CHECK(cpu.reg.c == 200);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 179);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 151);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 44124);
    // CHECK(cpu.reg.sp == 44857);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44123] == 0);
}

TEST_CASE( "00 01F6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55873;
    cpu.reg.sp = 47219;
    cpu.reg.a = 152;
    cpu.reg.b = 182;
    cpu.reg.c = 217;
    cpu.reg.d = 48;
    cpu.reg.e = 69;
    cpu.reg.f = 128;
    cpu.reg.h = 88;
    cpu.reg.l = 47;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[55873] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 152);
    CHECK(cpu.reg.b == 182);
    CHECK(cpu.reg.c == 217);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 69);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 88);
    CHECK(cpu.reg.l == 47);
    CHECK(cpu.reg.pc == 55874);
    // CHECK(cpu.reg.sp == 47219);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[55873] == 0);
}

TEST_CASE( "00 01F7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22157;
    cpu.reg.sp = 35355;
    cpu.reg.a = 18;
    cpu.reg.b = 122;
    cpu.reg.c = 206;
    cpu.reg.d = 54;
    cpu.reg.e = 185;
    cpu.reg.f = 144;
    cpu.reg.h = 162;
    cpu.reg.l = 129;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[22157] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 122);
    CHECK(cpu.reg.c == 206);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 185);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 129);
    CHECK(cpu.reg.pc == 22158);
    // CHECK(cpu.reg.sp == 35355);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[22157] == 0);
}

TEST_CASE( "00 01F8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6797;
    cpu.reg.sp = 46101;
    cpu.reg.a = 2;
    cpu.reg.b = 60;
    cpu.reg.c = 214;
    cpu.reg.d = 228;
    cpu.reg.e = 95;
    cpu.reg.f = 192;
    cpu.reg.h = 225;
    cpu.reg.l = 5;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6797] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 60);
    CHECK(cpu.reg.c == 214);
    CHECK(cpu.reg.d == 228);
    CHECK(cpu.reg.e == 95);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 5);
    CHECK(cpu.reg.pc == 6798);
    // CHECK(cpu.reg.sp == 46101);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6797] == 0);
}

TEST_CASE( "00 01F9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56121;
    cpu.reg.sp = 47091;
    cpu.reg.a = 135;
    cpu.reg.b = 43;
    cpu.reg.c = 248;
    cpu.reg.d = 142;
    cpu.reg.e = 4;
    cpu.reg.f = 80;
    cpu.reg.h = 0;
    cpu.reg.l = 45;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[56121] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 135);
    CHECK(cpu.reg.b == 43);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 142);
    CHECK(cpu.reg.e == 4);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 45);
    CHECK(cpu.reg.pc == 56122);
    // CHECK(cpu.reg.sp == 47091);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[56121] == 0);
}

TEST_CASE( "00 01FA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26428;
    cpu.reg.sp = 1908;
    cpu.reg.a = 228;
    cpu.reg.b = 112;
    cpu.reg.c = 164;
    cpu.reg.d = 226;
    cpu.reg.e = 248;
    cpu.reg.f = 0;
    cpu.reg.h = 206;
    cpu.reg.l = 229;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[26428] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 228);
    CHECK(cpu.reg.b == 112);
    CHECK(cpu.reg.c == 164);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 248);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 229);
    CHECK(cpu.reg.pc == 26429);
    // CHECK(cpu.reg.sp == 1908);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26428] == 0);
}

TEST_CASE( "00 01FB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24868;
    cpu.reg.sp = 2839;
    cpu.reg.a = 99;
    cpu.reg.b = 37;
    cpu.reg.c = 129;
    cpu.reg.d = 253;
    cpu.reg.e = 12;
    cpu.reg.f = 240;
    cpu.reg.h = 65;
    cpu.reg.l = 200;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[24868] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 37);
    CHECK(cpu.reg.c == 129);
    CHECK(cpu.reg.d == 253);
    CHECK(cpu.reg.e == 12);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 65);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 24869);
    // CHECK(cpu.reg.sp == 2839);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[24868] == 0);
}

TEST_CASE( "00 01FC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59126;
    cpu.reg.sp = 23948;
    cpu.reg.a = 7;
    cpu.reg.b = 110;
    cpu.reg.c = 33;
    cpu.reg.d = 46;
    cpu.reg.e = 57;
    cpu.reg.f = 32;
    cpu.reg.h = 138;
    cpu.reg.l = 41;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[59126] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 7);
    CHECK(cpu.reg.b == 110);
    CHECK(cpu.reg.c == 33);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 57);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 138);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 59127);
    // CHECK(cpu.reg.sp == 23948);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59126] == 0);
}

TEST_CASE( "00 01FD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52113;
    cpu.reg.sp = 29178;
    cpu.reg.a = 97;
    cpu.reg.b = 89;
    cpu.reg.c = 128;
    cpu.reg.d = 96;
    cpu.reg.e = 111;
    cpu.reg.f = 192;
    cpu.reg.h = 180;
    cpu.reg.l = 231;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[52113] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 97);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 96);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 231);
    CHECK(cpu.reg.pc == 52114);
    // CHECK(cpu.reg.sp == 29178);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52113] == 0);
}

TEST_CASE( "00 01FE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4052;
    cpu.reg.sp = 23691;
    cpu.reg.a = 55;
    cpu.reg.b = 97;
    cpu.reg.c = 146;
    cpu.reg.d = 181;
    cpu.reg.e = 82;
    cpu.reg.f = 160;
    cpu.reg.h = 13;
    cpu.reg.l = 253;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[4052] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 55);
    CHECK(cpu.reg.b == 97);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 181);
    CHECK(cpu.reg.e == 82);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 13);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 4053);
    // CHECK(cpu.reg.sp == 23691);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[4052] == 0);
}

TEST_CASE( "00 01FF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9604;
    cpu.reg.sp = 8615;
    cpu.reg.a = 11;
    cpu.reg.b = 81;
    cpu.reg.c = 131;
    cpu.reg.d = 147;
    cpu.reg.e = 132;
    cpu.reg.f = 224;
    cpu.reg.h = 160;
    cpu.reg.l = 244;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9604] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 11);
    CHECK(cpu.reg.b == 81);
    CHECK(cpu.reg.c == 131);
    CHECK(cpu.reg.d == 147);
    CHECK(cpu.reg.e == 132);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 244);
    CHECK(cpu.reg.pc == 9605);
    // CHECK(cpu.reg.sp == 8615);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9604] == 0);
}

TEST_CASE( "00 0200", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12383;
    cpu.reg.sp = 58486;
    cpu.reg.a = 194;
    cpu.reg.b = 128;
    cpu.reg.c = 241;
    cpu.reg.d = 243;
    cpu.reg.e = 160;
    cpu.reg.f = 176;
    cpu.reg.h = 245;
    cpu.reg.l = 211;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[12383] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 128);
    CHECK(cpu.reg.c == 241);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 211);
    CHECK(cpu.reg.pc == 12384);
    // CHECK(cpu.reg.sp == 58486);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12383] == 0);
}

TEST_CASE( "00 0201", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60552;
    cpu.reg.sp = 34353;
    cpu.reg.a = 117;
    cpu.reg.b = 224;
    cpu.reg.c = 247;
    cpu.reg.d = 171;
    cpu.reg.e = 101;
    cpu.reg.f = 224;
    cpu.reg.h = 212;
    cpu.reg.l = 201;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60552] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 247);
    CHECK(cpu.reg.d == 171);
    CHECK(cpu.reg.e == 101);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 212);
    CHECK(cpu.reg.l == 201);
    CHECK(cpu.reg.pc == 60553);
    // CHECK(cpu.reg.sp == 34353);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60552] == 0);
}

TEST_CASE( "00 0202", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25738;
    cpu.reg.sp = 47590;
    cpu.reg.a = 222;
    cpu.reg.b = 184;
    cpu.reg.c = 149;
    cpu.reg.d = 8;
    cpu.reg.e = 41;
    cpu.reg.f = 240;
    cpu.reg.h = 12;
    cpu.reg.l = 101;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[25738] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 222);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 149);
    CHECK(cpu.reg.d == 8);
    CHECK(cpu.reg.e == 41);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 25739);
    // CHECK(cpu.reg.sp == 47590);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25738] == 0);
}

TEST_CASE( "00 0203", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21780;
    cpu.reg.sp = 22582;
    cpu.reg.a = 196;
    cpu.reg.b = 193;
    cpu.reg.c = 156;
    cpu.reg.d = 68;
    cpu.reg.e = 148;
    cpu.reg.f = 192;
    cpu.reg.h = 169;
    cpu.reg.l = 84;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21780] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 196);
    CHECK(cpu.reg.b == 193);
    CHECK(cpu.reg.c == 156);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 148);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 169);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 21781);
    // CHECK(cpu.reg.sp == 22582);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21780] == 0);
}

TEST_CASE( "00 0204", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10712;
    cpu.reg.sp = 23999;
    cpu.reg.a = 252;
    cpu.reg.b = 50;
    cpu.reg.c = 27;
    cpu.reg.d = 15;
    cpu.reg.e = 251;
    cpu.reg.f = 112;
    cpu.reg.h = 117;
    cpu.reg.l = 195;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10712] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 252);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 27);
    CHECK(cpu.reg.d == 15);
    CHECK(cpu.reg.e == 251);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 117);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 10713);
    // CHECK(cpu.reg.sp == 23999);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10712] == 0);
}

TEST_CASE( "00 0205", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45557;
    cpu.reg.sp = 41320;
    cpu.reg.a = 92;
    cpu.reg.b = 199;
    cpu.reg.c = 72;
    cpu.reg.d = 66;
    cpu.reg.e = 174;
    cpu.reg.f = 0;
    cpu.reg.h = 231;
    cpu.reg.l = 62;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[45557] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 92);
    CHECK(cpu.reg.b == 199);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 174);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 231);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 45558);
    // CHECK(cpu.reg.sp == 41320);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[45557] == 0);
}

TEST_CASE( "00 0206", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44303;
    cpu.reg.sp = 11946;
    cpu.reg.a = 141;
    cpu.reg.b = 244;
    cpu.reg.c = 151;
    cpu.reg.d = 145;
    cpu.reg.e = 213;
    cpu.reg.f = 240;
    cpu.reg.h = 131;
    cpu.reg.l = 11;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[44303] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 145);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 131);
    CHECK(cpu.reg.l == 11);
    CHECK(cpu.reg.pc == 44304);
    // CHECK(cpu.reg.sp == 11946);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44303] == 0);
}

TEST_CASE( "00 0207", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16828;
    cpu.reg.sp = 8883;
    cpu.reg.a = 157;
    cpu.reg.b = 3;
    cpu.reg.c = 215;
    cpu.reg.d = 40;
    cpu.reg.e = 46;
    cpu.reg.f = 240;
    cpu.reg.h = 188;
    cpu.reg.l = 140;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[16828] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 157);
    CHECK(cpu.reg.b == 3);
    CHECK(cpu.reg.c == 215);
    CHECK(cpu.reg.d == 40);
    CHECK(cpu.reg.e == 46);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 16829);
    // CHECK(cpu.reg.sp == 8883);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16828] == 0);
}

TEST_CASE( "00 0208", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39748;
    cpu.reg.sp = 53041;
    cpu.reg.a = 239;
    cpu.reg.b = 196;
    cpu.reg.c = 76;
    cpu.reg.d = 72;
    cpu.reg.e = 252;
    cpu.reg.f = 80;
    cpu.reg.h = 13;
    cpu.reg.l = 156;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[39748] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 239);
    CHECK(cpu.reg.b == 196);
    CHECK(cpu.reg.c == 76);
    CHECK(cpu.reg.d == 72);
    CHECK(cpu.reg.e == 252);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 13);
    CHECK(cpu.reg.l == 156);
    CHECK(cpu.reg.pc == 39749);
    // CHECK(cpu.reg.sp == 53041);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39748] == 0);
}

TEST_CASE( "00 0209", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20684;
    cpu.reg.sp = 33433;
    cpu.reg.a = 185;
    cpu.reg.b = 78;
    cpu.reg.c = 96;
    cpu.reg.d = 71;
    cpu.reg.e = 117;
    cpu.reg.f = 64;
    cpu.reg.h = 142;
    cpu.reg.l = 192;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[20684] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 185);
    CHECK(cpu.reg.b == 78);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 117);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 142);
    CHECK(cpu.reg.l == 192);
    CHECK(cpu.reg.pc == 20685);
    // CHECK(cpu.reg.sp == 33433);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20684] == 0);
}

TEST_CASE( "00 020A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46651;
    cpu.reg.sp = 12371;
    cpu.reg.a = 79;
    cpu.reg.b = 102;
    cpu.reg.c = 233;
    cpu.reg.d = 112;
    cpu.reg.e = 0;
    cpu.reg.f = 160;
    cpu.reg.h = 190;
    cpu.reg.l = 203;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[46651] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 79);
    CHECK(cpu.reg.b == 102);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 112);
    CHECK(cpu.reg.e == 0);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 190);
    CHECK(cpu.reg.l == 203);
    CHECK(cpu.reg.pc == 46652);
    // CHECK(cpu.reg.sp == 12371);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46651] == 0);
}

TEST_CASE( "00 020B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60733;
    cpu.reg.sp = 24328;
    cpu.reg.a = 74;
    cpu.reg.b = 134;
    cpu.reg.c = 233;
    cpu.reg.d = 16;
    cpu.reg.e = 112;
    cpu.reg.f = 192;
    cpu.reg.h = 95;
    cpu.reg.l = 72;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60733] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 74);
    CHECK(cpu.reg.b == 134);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 16);
    CHECK(cpu.reg.e == 112);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 95);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 60734);
    // CHECK(cpu.reg.sp == 24328);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60733] == 0);
}

TEST_CASE( "00 020C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53471;
    cpu.reg.sp = 11977;
    cpu.reg.a = 164;
    cpu.reg.b = 126;
    cpu.reg.c = 39;
    cpu.reg.d = 95;
    cpu.reg.e = 161;
    cpu.reg.f = 224;
    cpu.reg.h = 164;
    cpu.reg.l = 170;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[53471] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 126);
    CHECK(cpu.reg.c == 39);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 161);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 53472);
    // CHECK(cpu.reg.sp == 11977);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53471] == 0);
}

TEST_CASE( "00 020D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48081;
    cpu.reg.sp = 28653;
    cpu.reg.a = 204;
    cpu.reg.b = 172;
    cpu.reg.c = 134;
    cpu.reg.d = 34;
    cpu.reg.e = 68;
    cpu.reg.f = 16;
    cpu.reg.h = 4;
    cpu.reg.l = 201;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48081] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 204);
    CHECK(cpu.reg.b == 172);
    CHECK(cpu.reg.c == 134);
    CHECK(cpu.reg.d == 34);
    CHECK(cpu.reg.e == 68);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 4);
    CHECK(cpu.reg.l == 201);
    CHECK(cpu.reg.pc == 48082);
    // CHECK(cpu.reg.sp == 28653);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48081] == 0);
}

TEST_CASE( "00 020E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61625;
    cpu.reg.sp = 61237;
    cpu.reg.a = 96;
    cpu.reg.b = 143;
    cpu.reg.c = 13;
    cpu.reg.d = 32;
    cpu.reg.e = 52;
    cpu.reg.f = 128;
    cpu.reg.h = 97;
    cpu.reg.l = 245;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[61625] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 143);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 32);
    CHECK(cpu.reg.e == 52);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 97);
    CHECK(cpu.reg.l == 245);
    CHECK(cpu.reg.pc == 61626);
    // CHECK(cpu.reg.sp == 61237);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[61625] == 0);
}

TEST_CASE( "00 020F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20031;
    cpu.reg.sp = 2491;
    cpu.reg.a = 69;
    cpu.reg.b = 78;
    cpu.reg.c = 203;
    cpu.reg.d = 114;
    cpu.reg.e = 167;
    cpu.reg.f = 144;
    cpu.reg.h = 186;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[20031] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 78);
    CHECK(cpu.reg.c == 203);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 167);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 20032);
    // CHECK(cpu.reg.sp == 2491);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20031] == 0);
}

TEST_CASE( "00 0210", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37014;
    cpu.reg.sp = 46342;
    cpu.reg.a = 213;
    cpu.reg.b = 9;
    cpu.reg.c = 75;
    cpu.reg.d = 26;
    cpu.reg.e = 121;
    cpu.reg.f = 0;
    cpu.reg.h = 20;
    cpu.reg.l = 222;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37014] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 213);
    CHECK(cpu.reg.b == 9);
    CHECK(cpu.reg.c == 75);
    CHECK(cpu.reg.d == 26);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 20);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 37015);
    // CHECK(cpu.reg.sp == 46342);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37014] == 0);
}

TEST_CASE( "00 0211", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43743;
    cpu.reg.sp = 57910;
    cpu.reg.a = 160;
    cpu.reg.b = 175;
    cpu.reg.c = 253;
    cpu.reg.d = 130;
    cpu.reg.e = 154;
    cpu.reg.f = 16;
    cpu.reg.h = 15;
    cpu.reg.l = 12;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43743] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 160);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 253);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 154);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 15);
    CHECK(cpu.reg.l == 12);
    CHECK(cpu.reg.pc == 43744);
    // CHECK(cpu.reg.sp == 57910);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43743] == 0);
}

TEST_CASE( "00 0212", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30577;
    cpu.reg.sp = 15181;
    cpu.reg.a = 172;
    cpu.reg.b = 99;
    cpu.reg.c = 223;
    cpu.reg.d = 223;
    cpu.reg.e = 165;
    cpu.reg.f = 80;
    cpu.reg.h = 101;
    cpu.reg.l = 177;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30577] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 172);
    CHECK(cpu.reg.b == 99);
    CHECK(cpu.reg.c == 223);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 165);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 101);
    CHECK(cpu.reg.l == 177);
    CHECK(cpu.reg.pc == 30578);
    // CHECK(cpu.reg.sp == 15181);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30577] == 0);
}

TEST_CASE( "00 0213", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19399;
    cpu.reg.sp = 35076;
    cpu.reg.a = 190;
    cpu.reg.b = 173;
    cpu.reg.c = 33;
    cpu.reg.d = 223;
    cpu.reg.e = 88;
    cpu.reg.f = 48;
    cpu.reg.h = 219;
    cpu.reg.l = 102;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[19399] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 190);
    CHECK(cpu.reg.b == 173);
    CHECK(cpu.reg.c == 33);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 88);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 219);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 19400);
    // CHECK(cpu.reg.sp == 35076);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19399] == 0);
}

TEST_CASE( "00 0214", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 470;
    cpu.reg.sp = 23254;
    cpu.reg.a = 146;
    cpu.reg.b = 43;
    cpu.reg.c = 234;
    cpu.reg.d = 125;
    cpu.reg.e = 244;
    cpu.reg.f = 32;
    cpu.reg.h = 95;
    cpu.reg.l = 249;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[470] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 146);
    CHECK(cpu.reg.b == 43);
    CHECK(cpu.reg.c == 234);
    CHECK(cpu.reg.d == 125);
    CHECK(cpu.reg.e == 244);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 95);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 471);
    // CHECK(cpu.reg.sp == 23254);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[470] == 0);
}

TEST_CASE( "00 0215", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36778;
    cpu.reg.sp = 32931;
    cpu.reg.a = 2;
    cpu.reg.b = 29;
    cpu.reg.c = 40;
    cpu.reg.d = 89;
    cpu.reg.e = 2;
    cpu.reg.f = 176;
    cpu.reg.h = 63;
    cpu.reg.l = 104;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[36778] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 29);
    CHECK(cpu.reg.c == 40);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 2);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 63);
    CHECK(cpu.reg.l == 104);
    CHECK(cpu.reg.pc == 36779);
    // CHECK(cpu.reg.sp == 32931);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36778] == 0);
}

TEST_CASE( "00 0216", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46712;
    cpu.reg.sp = 36197;
    cpu.reg.a = 130;
    cpu.reg.b = 244;
    cpu.reg.c = 109;
    cpu.reg.d = 178;
    cpu.reg.e = 124;
    cpu.reg.f = 112;
    cpu.reg.h = 36;
    cpu.reg.l = 190;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46712] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 130);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 109);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 36);
    CHECK(cpu.reg.l == 190);
    CHECK(cpu.reg.pc == 46713);
    // CHECK(cpu.reg.sp == 36197);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46712] == 0);
}

TEST_CASE( "00 0217", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60328;
    cpu.reg.sp = 19787;
    cpu.reg.a = 106;
    cpu.reg.b = 234;
    cpu.reg.c = 15;
    cpu.reg.d = 128;
    cpu.reg.e = 17;
    cpu.reg.f = 0;
    cpu.reg.h = 203;
    cpu.reg.l = 160;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60328] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 106);
    CHECK(cpu.reg.b == 234);
    CHECK(cpu.reg.c == 15);
    CHECK(cpu.reg.d == 128);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 60329);
    // CHECK(cpu.reg.sp == 19787);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60328] == 0);
}

TEST_CASE( "00 0218", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37053;
    cpu.reg.sp = 12018;
    cpu.reg.a = 8;
    cpu.reg.b = 147;
    cpu.reg.c = 204;
    cpu.reg.d = 103;
    cpu.reg.e = 107;
    cpu.reg.f = 32;
    cpu.reg.h = 99;
    cpu.reg.l = 57;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[37053] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 147);
    CHECK(cpu.reg.c == 204);
    CHECK(cpu.reg.d == 103);
    CHECK(cpu.reg.e == 107);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 57);
    CHECK(cpu.reg.pc == 37054);
    // CHECK(cpu.reg.sp == 12018);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37053] == 0);
}

TEST_CASE( "00 0219", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30563;
    cpu.reg.sp = 30233;
    cpu.reg.a = 55;
    cpu.reg.b = 236;
    cpu.reg.c = 29;
    cpu.reg.d = 135;
    cpu.reg.e = 196;
    cpu.reg.f = 176;
    cpu.reg.h = 136;
    cpu.reg.l = 250;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30563] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 55);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 29);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 196);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 30564);
    // CHECK(cpu.reg.sp == 30233);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30563] == 0);
}

TEST_CASE( "00 021A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40411;
    cpu.reg.sp = 18744;
    cpu.reg.a = 174;
    cpu.reg.b = 183;
    cpu.reg.c = 12;
    cpu.reg.d = 67;
    cpu.reg.e = 87;
    cpu.reg.f = 96;
    cpu.reg.h = 107;
    cpu.reg.l = 95;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[40411] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 174);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 67);
    CHECK(cpu.reg.e == 87);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 107);
    CHECK(cpu.reg.l == 95);
    CHECK(cpu.reg.pc == 40412);
    // CHECK(cpu.reg.sp == 18744);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40411] == 0);
}

TEST_CASE( "00 021B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43283;
    cpu.reg.sp = 33178;
    cpu.reg.a = 148;
    cpu.reg.b = 75;
    cpu.reg.c = 140;
    cpu.reg.d = 248;
    cpu.reg.e = 124;
    cpu.reg.f = 96;
    cpu.reg.h = 232;
    cpu.reg.l = 201;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43283] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 140);
    CHECK(cpu.reg.d == 248);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 201);
    CHECK(cpu.reg.pc == 43284);
    // CHECK(cpu.reg.sp == 33178);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43283] == 0);
}

TEST_CASE( "00 021C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61232;
    cpu.reg.sp = 24129;
    cpu.reg.a = 36;
    cpu.reg.b = 183;
    cpu.reg.c = 178;
    cpu.reg.d = 119;
    cpu.reg.e = 141;
    cpu.reg.f = 64;
    cpu.reg.h = 50;
    cpu.reg.l = 146;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61232] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 36);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 178);
    CHECK(cpu.reg.d == 119);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 50);
    CHECK(cpu.reg.l == 146);
    CHECK(cpu.reg.pc == 61233);
    // CHECK(cpu.reg.sp == 24129);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61232] == 0);
}

TEST_CASE( "00 021D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5241;
    cpu.reg.sp = 25942;
    cpu.reg.a = 139;
    cpu.reg.b = 230;
    cpu.reg.c = 58;
    cpu.reg.d = 243;
    cpu.reg.e = 19;
    cpu.reg.f = 80;
    cpu.reg.h = 218;
    cpu.reg.l = 129;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[5241] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 230);
    CHECK(cpu.reg.c == 58);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 129);
    CHECK(cpu.reg.pc == 5242);
    // CHECK(cpu.reg.sp == 25942);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5241] == 0);
}

TEST_CASE( "00 021E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57811;
    cpu.reg.sp = 2317;
    cpu.reg.a = 148;
    cpu.reg.b = 244;
    cpu.reg.c = 93;
    cpu.reg.d = 75;
    cpu.reg.e = 219;
    cpu.reg.f = 176;
    cpu.reg.h = 249;
    cpu.reg.l = 62;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[57811] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 93);
    CHECK(cpu.reg.d == 75);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 249);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 57812);
    // CHECK(cpu.reg.sp == 2317);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57811] == 0);
}

TEST_CASE( "00 021F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3525;
    cpu.reg.sp = 30113;
    cpu.reg.a = 210;
    cpu.reg.b = 228;
    cpu.reg.c = 57;
    cpu.reg.d = 126;
    cpu.reg.e = 176;
    cpu.reg.f = 240;
    cpu.reg.h = 140;
    cpu.reg.l = 178;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[3525] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 57);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 178);
    CHECK(cpu.reg.pc == 3526);
    // CHECK(cpu.reg.sp == 30113);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3525] == 0);
}

TEST_CASE( "00 0220", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28672;
    cpu.reg.sp = 48917;
    cpu.reg.a = 10;
    cpu.reg.b = 165;
    cpu.reg.c = 42;
    cpu.reg.d = 66;
    cpu.reg.e = 153;
    cpu.reg.f = 96;
    cpu.reg.h = 196;
    cpu.reg.l = 167;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28672] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 165);
    CHECK(cpu.reg.c == 42);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 196);
    CHECK(cpu.reg.l == 167);
    CHECK(cpu.reg.pc == 28673);
    // CHECK(cpu.reg.sp == 48917);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28672] == 0);
}

TEST_CASE( "00 0221", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27904;
    cpu.reg.sp = 11596;
    cpu.reg.a = 171;
    cpu.reg.b = 44;
    cpu.reg.c = 22;
    cpu.reg.d = 180;
    cpu.reg.e = 39;
    cpu.reg.f = 16;
    cpu.reg.h = 151;
    cpu.reg.l = 153;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[27904] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 171);
    CHECK(cpu.reg.b == 44);
    CHECK(cpu.reg.c == 22);
    CHECK(cpu.reg.d == 180);
    CHECK(cpu.reg.e == 39);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 151);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 27905);
    // CHECK(cpu.reg.sp == 11596);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[27904] == 0);
}

TEST_CASE( "00 0222", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61711;
    cpu.reg.sp = 34233;
    cpu.reg.a = 242;
    cpu.reg.b = 84;
    cpu.reg.c = 9;
    cpu.reg.d = 104;
    cpu.reg.e = 191;
    cpu.reg.f = 192;
    cpu.reg.h = 149;
    cpu.reg.l = 81;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61711] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 242);
    CHECK(cpu.reg.b == 84);
    CHECK(cpu.reg.c == 9);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 61712);
    // CHECK(cpu.reg.sp == 34233);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61711] == 0);
}

TEST_CASE( "00 0223", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58595;
    cpu.reg.sp = 3163;
    cpu.reg.a = 2;
    cpu.reg.b = 66;
    cpu.reg.c = 222;
    cpu.reg.d = 0;
    cpu.reg.e = 91;
    cpu.reg.f = 192;
    cpu.reg.h = 227;
    cpu.reg.l = 162;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[58595] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 222);
    CHECK(cpu.reg.d == 0);
    CHECK(cpu.reg.e == 91);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 227);
    CHECK(cpu.reg.l == 162);
    CHECK(cpu.reg.pc == 58596);
    // CHECK(cpu.reg.sp == 3163);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58595] == 0);
}

TEST_CASE( "00 0224", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58519;
    cpu.reg.sp = 685;
    cpu.reg.a = 121;
    cpu.reg.b = 21;
    cpu.reg.c = 53;
    cpu.reg.d = 209;
    cpu.reg.e = 218;
    cpu.reg.f = 240;
    cpu.reg.h = 153;
    cpu.reg.l = 153;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[58519] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 121);
    CHECK(cpu.reg.b == 21);
    CHECK(cpu.reg.c == 53);
    CHECK(cpu.reg.d == 209);
    CHECK(cpu.reg.e == 218);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 153);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 58520);
    // CHECK(cpu.reg.sp == 685);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58519] == 0);
}

TEST_CASE( "00 0225", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19833;
    cpu.reg.sp = 14249;
    cpu.reg.a = 171;
    cpu.reg.b = 110;
    cpu.reg.c = 32;
    cpu.reg.d = 159;
    cpu.reg.e = 188;
    cpu.reg.f = 32;
    cpu.reg.h = 170;
    cpu.reg.l = 177;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19833] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 171);
    CHECK(cpu.reg.b == 110);
    CHECK(cpu.reg.c == 32);
    CHECK(cpu.reg.d == 159);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 177);
    CHECK(cpu.reg.pc == 19834);
    // CHECK(cpu.reg.sp == 14249);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19833] == 0);
}

TEST_CASE( "00 0226", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56560;
    cpu.reg.sp = 14408;
    cpu.reg.a = 7;
    cpu.reg.b = 46;
    cpu.reg.c = 139;
    cpu.reg.d = 179;
    cpu.reg.e = 7;
    cpu.reg.f = 240;
    cpu.reg.h = 100;
    cpu.reg.l = 125;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56560] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 7);
    CHECK(cpu.reg.b == 46);
    CHECK(cpu.reg.c == 139);
    CHECK(cpu.reg.d == 179);
    CHECK(cpu.reg.e == 7);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 100);
    CHECK(cpu.reg.l == 125);
    CHECK(cpu.reg.pc == 56561);
    // CHECK(cpu.reg.sp == 14408);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56560] == 0);
}

TEST_CASE( "00 0227", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2522;
    cpu.reg.sp = 6935;
    cpu.reg.a = 233;
    cpu.reg.b = 248;
    cpu.reg.c = 113;
    cpu.reg.d = 207;
    cpu.reg.e = 98;
    cpu.reg.f = 208;
    cpu.reg.h = 28;
    cpu.reg.l = 233;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[2522] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 233);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 113);
    CHECK(cpu.reg.d == 207);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 2523);
    // CHECK(cpu.reg.sp == 6935);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2522] == 0);
}

TEST_CASE( "00 0228", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56023;
    cpu.reg.sp = 49586;
    cpu.reg.a = 100;
    cpu.reg.b = 54;
    cpu.reg.c = 39;
    cpu.reg.d = 156;
    cpu.reg.e = 126;
    cpu.reg.f = 176;
    cpu.reg.h = 184;
    cpu.reg.l = 40;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[56023] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 100);
    CHECK(cpu.reg.b == 54);
    CHECK(cpu.reg.c == 39);
    CHECK(cpu.reg.d == 156);
    CHECK(cpu.reg.e == 126);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 56024);
    // CHECK(cpu.reg.sp == 49586);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[56023] == 0);
}

TEST_CASE( "00 0229", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11245;
    cpu.reg.sp = 4242;
    cpu.reg.a = 104;
    cpu.reg.b = 135;
    cpu.reg.c = 227;
    cpu.reg.d = 15;
    cpu.reg.e = 198;
    cpu.reg.f = 96;
    cpu.reg.h = 125;
    cpu.reg.l = 72;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[11245] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 104);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 15);
    CHECK(cpu.reg.e == 198);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 11246);
    // CHECK(cpu.reg.sp == 4242);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11245] == 0);
}

TEST_CASE( "00 022A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13951;
    cpu.reg.sp = 63801;
    cpu.reg.a = 47;
    cpu.reg.b = 177;
    cpu.reg.c = 165;
    cpu.reg.d = 211;
    cpu.reg.e = 212;
    cpu.reg.f = 144;
    cpu.reg.h = 55;
    cpu.reg.l = 200;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[13951] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 47);
    CHECK(cpu.reg.b == 177);
    CHECK(cpu.reg.c == 165);
    CHECK(cpu.reg.d == 211);
    CHECK(cpu.reg.e == 212);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 55);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 13952);
    // CHECK(cpu.reg.sp == 63801);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13951] == 0);
}

TEST_CASE( "00 022B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1668;
    cpu.reg.sp = 19047;
    cpu.reg.a = 11;
    cpu.reg.b = 96;
    cpu.reg.c = 122;
    cpu.reg.d = 64;
    cpu.reg.e = 100;
    cpu.reg.f = 208;
    cpu.reg.h = 72;
    cpu.reg.l = 183;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[1668] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 11);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 122);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 100);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 72);
    CHECK(cpu.reg.l == 183);
    CHECK(cpu.reg.pc == 1669);
    // CHECK(cpu.reg.sp == 19047);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1668] == 0);
}

TEST_CASE( "00 022C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53901;
    cpu.reg.sp = 1304;
    cpu.reg.a = 68;
    cpu.reg.b = 0;
    cpu.reg.c = 67;
    cpu.reg.d = 108;
    cpu.reg.e = 21;
    cpu.reg.f = 32;
    cpu.reg.h = 203;
    cpu.reg.l = 108;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53901] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 0);
    CHECK(cpu.reg.c == 67);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 108);
    CHECK(cpu.reg.pc == 53902);
    // CHECK(cpu.reg.sp == 1304);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53901] == 0);
}

TEST_CASE( "00 022D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8145;
    cpu.reg.sp = 62440;
    cpu.reg.a = 149;
    cpu.reg.b = 221;
    cpu.reg.c = 152;
    cpu.reg.d = 122;
    cpu.reg.e = 111;
    cpu.reg.f = 192;
    cpu.reg.h = 172;
    cpu.reg.l = 10;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[8145] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 149);
    CHECK(cpu.reg.b == 221);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 122);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 172);
    CHECK(cpu.reg.l == 10);
    CHECK(cpu.reg.pc == 8146);
    // CHECK(cpu.reg.sp == 62440);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8145] == 0);
}

TEST_CASE( "00 022E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56061;
    cpu.reg.sp = 47831;
    cpu.reg.a = 16;
    cpu.reg.b = 92;
    cpu.reg.c = 138;
    cpu.reg.d = 136;
    cpu.reg.e = 18;
    cpu.reg.f = 48;
    cpu.reg.h = 206;
    cpu.reg.l = 249;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[56061] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 16);
    CHECK(cpu.reg.b == 92);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 18);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 56062);
    // CHECK(cpu.reg.sp == 47831);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56061] == 0);
}

TEST_CASE( "00 022F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47033;
    cpu.reg.sp = 32403;
    cpu.reg.a = 150;
    cpu.reg.b = 252;
    cpu.reg.c = 226;
    cpu.reg.d = 229;
    cpu.reg.e = 170;
    cpu.reg.f = 176;
    cpu.reg.h = 219;
    cpu.reg.l = 127;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47033] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 150);
    CHECK(cpu.reg.b == 252);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 170);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 219);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 47034);
    // CHECK(cpu.reg.sp == 32403);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47033] == 0);
}

TEST_CASE( "00 0230", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11622;
    cpu.reg.sp = 21290;
    cpu.reg.a = 18;
    cpu.reg.b = 49;
    cpu.reg.c = 232;
    cpu.reg.d = 18;
    cpu.reg.e = 199;
    cpu.reg.f = 160;
    cpu.reg.h = 243;
    cpu.reg.l = 187;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[11622] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 18);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 11623);
    // CHECK(cpu.reg.sp == 21290);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11622] == 0);
}

TEST_CASE( "00 0231", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24778;
    cpu.reg.sp = 4283;
    cpu.reg.a = 194;
    cpu.reg.b = 207;
    cpu.reg.c = 163;
    cpu.reg.d = 23;
    cpu.reg.e = 167;
    cpu.reg.f = 176;
    cpu.reg.h = 151;
    cpu.reg.l = 47;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[24778] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 207);
    CHECK(cpu.reg.c == 163);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 167);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 151);
    CHECK(cpu.reg.l == 47);
    CHECK(cpu.reg.pc == 24779);
    // CHECK(cpu.reg.sp == 4283);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[24778] == 0);
}

TEST_CASE( "00 0232", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58823;
    cpu.reg.sp = 30318;
    cpu.reg.a = 57;
    cpu.reg.b = 30;
    cpu.reg.c = 186;
    cpu.reg.d = 41;
    cpu.reg.e = 32;
    cpu.reg.f = 144;
    cpu.reg.h = 203;
    cpu.reg.l = 180;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[58823] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 57);
    CHECK(cpu.reg.b == 30);
    CHECK(cpu.reg.c == 186);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 180);
    CHECK(cpu.reg.pc == 58824);
    // CHECK(cpu.reg.sp == 30318);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58823] == 0);
}

TEST_CASE( "00 0233", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18203;
    cpu.reg.sp = 47102;
    cpu.reg.a = 42;
    cpu.reg.b = 47;
    cpu.reg.c = 1;
    cpu.reg.d = 154;
    cpu.reg.e = 180;
    cpu.reg.f = 112;
    cpu.reg.h = 87;
    cpu.reg.l = 187;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[18203] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 1);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 180);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 87);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 18204);
    // CHECK(cpu.reg.sp == 47102);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18203] == 0);
}

TEST_CASE( "00 0234", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35512;
    cpu.reg.sp = 44536;
    cpu.reg.a = 3;
    cpu.reg.b = 77;
    cpu.reg.c = 143;
    cpu.reg.d = 80;
    cpu.reg.e = 121;
    cpu.reg.f = 64;
    cpu.reg.h = 159;
    cpu.reg.l = 166;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35512] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 77);
    CHECK(cpu.reg.c == 143);
    CHECK(cpu.reg.d == 80);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 159);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 35513);
    // CHECK(cpu.reg.sp == 44536);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35512] == 0);
}

TEST_CASE( "00 0235", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59871;
    cpu.reg.sp = 29441;
    cpu.reg.a = 187;
    cpu.reg.b = 90;
    cpu.reg.c = 211;
    cpu.reg.d = 173;
    cpu.reg.e = 195;
    cpu.reg.f = 144;
    cpu.reg.h = 106;
    cpu.reg.l = 112;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[59871] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 187);
    CHECK(cpu.reg.b == 90);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 173);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 106);
    CHECK(cpu.reg.l == 112);
    CHECK(cpu.reg.pc == 59872);
    // CHECK(cpu.reg.sp == 29441);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59871] == 0);
}

TEST_CASE( "00 0236", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7189;
    cpu.reg.sp = 18302;
    cpu.reg.a = 117;
    cpu.reg.b = 42;
    cpu.reg.c = 41;
    cpu.reg.d = 187;
    cpu.reg.e = 85;
    cpu.reg.f = 240;
    cpu.reg.h = 203;
    cpu.reg.l = 182;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[7189] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 41);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 7190);
    // CHECK(cpu.reg.sp == 18302);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7189] == 0);
}

TEST_CASE( "00 0237", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32447;
    cpu.reg.sp = 41464;
    cpu.reg.a = 234;
    cpu.reg.b = 236;
    cpu.reg.c = 163;
    cpu.reg.d = 64;
    cpu.reg.e = 127;
    cpu.reg.f = 192;
    cpu.reg.h = 123;
    cpu.reg.l = 66;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32447] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 234);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 163);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 127);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 123);
    CHECK(cpu.reg.l == 66);
    CHECK(cpu.reg.pc == 32448);
    // CHECK(cpu.reg.sp == 41464);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32447] == 0);
}

TEST_CASE( "00 0238", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20498;
    cpu.reg.sp = 63017;
    cpu.reg.a = 15;
    cpu.reg.b = 153;
    cpu.reg.c = 187;
    cpu.reg.d = 70;
    cpu.reg.e = 148;
    cpu.reg.f = 224;
    cpu.reg.h = 193;
    cpu.reg.l = 59;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[20498] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 153);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 70);
    CHECK(cpu.reg.e == 148);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 193);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 20499);
    // CHECK(cpu.reg.sp == 63017);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20498] == 0);
}

TEST_CASE( "00 0239", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35963;
    cpu.reg.sp = 23057;
    cpu.reg.a = 237;
    cpu.reg.b = 230;
    cpu.reg.c = 117;
    cpu.reg.d = 230;
    cpu.reg.e = 242;
    cpu.reg.f = 48;
    cpu.reg.h = 19;
    cpu.reg.l = 170;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[35963] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 237);
    CHECK(cpu.reg.b == 230);
    CHECK(cpu.reg.c == 117);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 242);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 19);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 35964);
    // CHECK(cpu.reg.sp == 23057);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[35963] == 0);
}

TEST_CASE( "00 023A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38517;
    cpu.reg.sp = 44314;
    cpu.reg.a = 75;
    cpu.reg.b = 135;
    cpu.reg.c = 230;
    cpu.reg.d = 254;
    cpu.reg.e = 158;
    cpu.reg.f = 208;
    cpu.reg.h = 62;
    cpu.reg.l = 243;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[38517] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 75);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 230);
    CHECK(cpu.reg.d == 254);
    CHECK(cpu.reg.e == 158);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 62);
    CHECK(cpu.reg.l == 243);
    CHECK(cpu.reg.pc == 38518);
    // CHECK(cpu.reg.sp == 44314);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[38517] == 0);
}

TEST_CASE( "00 023B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 119;
    cpu.reg.sp = 2407;
    cpu.reg.a = 246;
    cpu.reg.b = 200;
    cpu.reg.c = 226;
    cpu.reg.d = 198;
    cpu.reg.e = 237;
    cpu.reg.f = 192;
    cpu.reg.h = 240;
    cpu.reg.l = 63;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[119] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 246);
    CHECK(cpu.reg.b == 200);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 198);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 240);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 120);
    // CHECK(cpu.reg.sp == 2407);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[119] == 0);
}

TEST_CASE( "00 023C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17891;
    cpu.reg.sp = 64147;
    cpu.reg.a = 196;
    cpu.reg.b = 236;
    cpu.reg.c = 150;
    cpu.reg.d = 66;
    cpu.reg.e = 35;
    cpu.reg.f = 16;
    cpu.reg.h = 208;
    cpu.reg.l = 108;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17891] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 196);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 35);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 208);
    CHECK(cpu.reg.l == 108);
    CHECK(cpu.reg.pc == 17892);
    // CHECK(cpu.reg.sp == 64147);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17891] == 0);
}

TEST_CASE( "00 023D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44148;
    cpu.reg.sp = 20716;
    cpu.reg.a = 141;
    cpu.reg.b = 135;
    cpu.reg.c = 96;
    cpu.reg.d = 152;
    cpu.reg.e = 54;
    cpu.reg.f = 208;
    cpu.reg.h = 109;
    cpu.reg.l = 26;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44148] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 96);
    CHECK(cpu.reg.d == 152);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 109);
    CHECK(cpu.reg.l == 26);
    CHECK(cpu.reg.pc == 44149);
    // CHECK(cpu.reg.sp == 20716);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44148] == 0);
}

TEST_CASE( "00 023E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30381;
    cpu.reg.sp = 59924;
    cpu.reg.a = 96;
    cpu.reg.b = 169;
    cpu.reg.c = 252;
    cpu.reg.d = 216;
    cpu.reg.e = 54;
    cpu.reg.f = 176;
    cpu.reg.h = 46;
    cpu.reg.l = 127;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[30381] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 169);
    CHECK(cpu.reg.c == 252);
    CHECK(cpu.reg.d == 216);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 46);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 30382);
    // CHECK(cpu.reg.sp == 59924);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30381] == 0);
}

TEST_CASE( "00 023F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50815;
    cpu.reg.sp = 43711;
    cpu.reg.a = 253;
    cpu.reg.b = 59;
    cpu.reg.c = 77;
    cpu.reg.d = 102;
    cpu.reg.e = 3;
    cpu.reg.f = 96;
    cpu.reg.h = 198;
    cpu.reg.l = 170;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[50815] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 253);
    CHECK(cpu.reg.b == 59);
    CHECK(cpu.reg.c == 77);
    CHECK(cpu.reg.d == 102);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 198);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 50816);
    // CHECK(cpu.reg.sp == 43711);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50815] == 0);
}

TEST_CASE( "00 0240", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1484;
    cpu.reg.sp = 26150;
    cpu.reg.a = 72;
    cpu.reg.b = 181;
    cpu.reg.c = 182;
    cpu.reg.d = 55;
    cpu.reg.e = 203;
    cpu.reg.f = 112;
    cpu.reg.h = 48;
    cpu.reg.l = 234;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[1484] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 72);
    CHECK(cpu.reg.b == 181);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 55);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 48);
    CHECK(cpu.reg.l == 234);
    CHECK(cpu.reg.pc == 1485);
    // CHECK(cpu.reg.sp == 26150);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1484] == 0);
}

TEST_CASE( "00 0241", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48479;
    cpu.reg.sp = 54144;
    cpu.reg.a = 109;
    cpu.reg.b = 84;
    cpu.reg.c = 157;
    cpu.reg.d = 141;
    cpu.reg.e = 164;
    cpu.reg.f = 112;
    cpu.reg.h = 40;
    cpu.reg.l = 2;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48479] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 109);
    CHECK(cpu.reg.b == 84);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 141);
    CHECK(cpu.reg.e == 164);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 40);
    CHECK(cpu.reg.l == 2);
    CHECK(cpu.reg.pc == 48480);
    // CHECK(cpu.reg.sp == 54144);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48479] == 0);
}

TEST_CASE( "00 0242", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34680;
    cpu.reg.sp = 24154;
    cpu.reg.a = 83;
    cpu.reg.b = 34;
    cpu.reg.c = 205;
    cpu.reg.d = 31;
    cpu.reg.e = 200;
    cpu.reg.f = 176;
    cpu.reg.h = 124;
    cpu.reg.l = 12;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[34680] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 83);
    CHECK(cpu.reg.b == 34);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 124);
    CHECK(cpu.reg.l == 12);
    CHECK(cpu.reg.pc == 34681);
    // CHECK(cpu.reg.sp == 24154);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34680] == 0);
}

TEST_CASE( "00 0243", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23770;
    cpu.reg.sp = 36131;
    cpu.reg.a = 113;
    cpu.reg.b = 168;
    cpu.reg.c = 197;
    cpu.reg.d = 106;
    cpu.reg.e = 61;
    cpu.reg.f = 240;
    cpu.reg.h = 167;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[23770] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 113);
    CHECK(cpu.reg.b == 168);
    CHECK(cpu.reg.c == 197);
    CHECK(cpu.reg.d == 106);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 23771);
    // CHECK(cpu.reg.sp == 36131);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[23770] == 0);
}

TEST_CASE( "00 0244", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7162;
    cpu.reg.sp = 3422;
    cpu.reg.a = 85;
    cpu.reg.b = 200;
    cpu.reg.c = 119;
    cpu.reg.d = 194;
    cpu.reg.e = 57;
    cpu.reg.f = 112;
    cpu.reg.h = 223;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[7162] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 85);
    CHECK(cpu.reg.b == 200);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 57);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 223);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 7163);
    // CHECK(cpu.reg.sp == 3422);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7162] == 0);
}

TEST_CASE( "00 0245", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43533;
    cpu.reg.sp = 50321;
    cpu.reg.a = 131;
    cpu.reg.b = 21;
    cpu.reg.c = 113;
    cpu.reg.d = 146;
    cpu.reg.e = 177;
    cpu.reg.f = 160;
    cpu.reg.h = 134;
    cpu.reg.l = 212;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43533] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 131);
    CHECK(cpu.reg.b == 21);
    CHECK(cpu.reg.c == 113);
    CHECK(cpu.reg.d == 146);
    CHECK(cpu.reg.e == 177);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 134);
    CHECK(cpu.reg.l == 212);
    CHECK(cpu.reg.pc == 43534);
    // CHECK(cpu.reg.sp == 50321);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43533] == 0);
}

TEST_CASE( "00 0246", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22203;
    cpu.reg.sp = 31444;
    cpu.reg.a = 75;
    cpu.reg.b = 231;
    cpu.reg.c = 90;
    cpu.reg.d = 166;
    cpu.reg.e = 199;
    cpu.reg.f = 112;
    cpu.reg.h = 206;
    cpu.reg.l = 63;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[22203] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 75);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 166);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 22204);
    // CHECK(cpu.reg.sp == 31444);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22203] == 0);
}

TEST_CASE( "00 0247", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28628;
    cpu.reg.sp = 47444;
    cpu.reg.a = 18;
    cpu.reg.b = 232;
    cpu.reg.c = 77;
    cpu.reg.d = 159;
    cpu.reg.e = 114;
    cpu.reg.f = 240;
    cpu.reg.h = 11;
    cpu.reg.l = 140;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28628] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 232);
    CHECK(cpu.reg.c == 77);
    CHECK(cpu.reg.d == 159);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 11);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 28629);
    // CHECK(cpu.reg.sp == 47444);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28628] == 0);
}

TEST_CASE( "00 0248", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43469;
    cpu.reg.sp = 16867;
    cpu.reg.a = 223;
    cpu.reg.b = 23;
    cpu.reg.c = 173;
    cpu.reg.d = 149;
    cpu.reg.e = 168;
    cpu.reg.f = 112;
    cpu.reg.h = 51;
    cpu.reg.l = 17;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43469] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 223);
    CHECK(cpu.reg.b == 23);
    CHECK(cpu.reg.c == 173);
    CHECK(cpu.reg.d == 149);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 51);
    CHECK(cpu.reg.l == 17);
    CHECK(cpu.reg.pc == 43470);
    // CHECK(cpu.reg.sp == 16867);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43469] == 0);
}

TEST_CASE( "00 0249", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54993;
    cpu.reg.sp = 43314;
    cpu.reg.a = 181;
    cpu.reg.b = 167;
    cpu.reg.c = 205;
    cpu.reg.d = 46;
    cpu.reg.e = 63;
    cpu.reg.f = 80;
    cpu.reg.h = 218;
    cpu.reg.l = 61;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54993] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 181);
    CHECK(cpu.reg.b == 167);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 54994);
    // CHECK(cpu.reg.sp == 43314);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54993] == 0);
}

TEST_CASE( "00 024A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44986;
    cpu.reg.sp = 2271;
    cpu.reg.a = 27;
    cpu.reg.b = 80;
    cpu.reg.c = 69;
    cpu.reg.d = 110;
    cpu.reg.e = 207;
    cpu.reg.f = 0;
    cpu.reg.h = 216;
    cpu.reg.l = 161;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[44986] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 27);
    CHECK(cpu.reg.b == 80);
    CHECK(cpu.reg.c == 69);
    CHECK(cpu.reg.d == 110);
    CHECK(cpu.reg.e == 207);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 216);
    CHECK(cpu.reg.l == 161);
    CHECK(cpu.reg.pc == 44987);
    // CHECK(cpu.reg.sp == 2271);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44986] == 0);
}

TEST_CASE( "00 024B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11649;
    cpu.reg.sp = 13453;
    cpu.reg.a = 51;
    cpu.reg.b = 153;
    cpu.reg.c = 112;
    cpu.reg.d = 87;
    cpu.reg.e = 21;
    cpu.reg.f = 96;
    cpu.reg.h = 50;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[11649] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 51);
    CHECK(cpu.reg.b == 153);
    CHECK(cpu.reg.c == 112);
    CHECK(cpu.reg.d == 87);
    CHECK(cpu.reg.e == 21);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 50);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 11650);
    // CHECK(cpu.reg.sp == 13453);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[11649] == 0);
}

TEST_CASE( "00 024C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37604;
    cpu.reg.sp = 58635;
    cpu.reg.a = 244;
    cpu.reg.b = 248;
    cpu.reg.c = 244;
    cpu.reg.d = 86;
    cpu.reg.e = 172;
    cpu.reg.f = 112;
    cpu.reg.h = 20;
    cpu.reg.l = 96;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37604] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 244);
    CHECK(cpu.reg.d == 86);
    CHECK(cpu.reg.e == 172);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 20);
    CHECK(cpu.reg.l == 96);
    CHECK(cpu.reg.pc == 37605);
    // CHECK(cpu.reg.sp == 58635);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37604] == 0);
}

TEST_CASE( "00 024D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61119;
    cpu.reg.sp = 64290;
    cpu.reg.a = 81;
    cpu.reg.b = 114;
    cpu.reg.c = 170;
    cpu.reg.d = 107;
    cpu.reg.e = 200;
    cpu.reg.f = 192;
    cpu.reg.h = 84;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[61119] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 114);
    CHECK(cpu.reg.c == 170);
    CHECK(cpu.reg.d == 107);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 84);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 61120);
    // CHECK(cpu.reg.sp == 64290);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61119] == 0);
}

TEST_CASE( "00 024E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14110;
    cpu.reg.sp = 7606;
    cpu.reg.a = 78;
    cpu.reg.b = 77;
    cpu.reg.c = 25;
    cpu.reg.d = 113;
    cpu.reg.e = 89;
    cpu.reg.f = 192;
    cpu.reg.h = 124;
    cpu.reg.l = 10;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[14110] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 77);
    CHECK(cpu.reg.c == 25);
    CHECK(cpu.reg.d == 113);
    CHECK(cpu.reg.e == 89);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 124);
    CHECK(cpu.reg.l == 10);
    CHECK(cpu.reg.pc == 14111);
    // CHECK(cpu.reg.sp == 7606);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[14110] == 0);
}

TEST_CASE( "00 024F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34396;
    cpu.reg.sp = 37357;
    cpu.reg.a = 158;
    cpu.reg.b = 144;
    cpu.reg.c = 208;
    cpu.reg.d = 120;
    cpu.reg.e = 45;
    cpu.reg.f = 160;
    cpu.reg.h = 140;
    cpu.reg.l = 130;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[34396] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 158);
    CHECK(cpu.reg.b == 144);
    CHECK(cpu.reg.c == 208);
    CHECK(cpu.reg.d == 120);
    CHECK(cpu.reg.e == 45);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 130);
    CHECK(cpu.reg.pc == 34397);
    // CHECK(cpu.reg.sp == 37357);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34396] == 0);
}

TEST_CASE( "00 0250", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4680;
    cpu.reg.sp = 17679;
    cpu.reg.a = 180;
    cpu.reg.b = 232;
    cpu.reg.c = 207;
    cpu.reg.d = 249;
    cpu.reg.e = 188;
    cpu.reg.f = 160;
    cpu.reg.h = 171;
    cpu.reg.l = 254;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[4680] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 180);
    CHECK(cpu.reg.b == 232);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 249);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 171);
    CHECK(cpu.reg.l == 254);
    CHECK(cpu.reg.pc == 4681);
    // CHECK(cpu.reg.sp == 17679);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4680] == 0);
}

TEST_CASE( "00 0251", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3173;
    cpu.reg.sp = 52377;
    cpu.reg.a = 62;
    cpu.reg.b = 135;
    cpu.reg.c = 187;
    cpu.reg.d = 108;
    cpu.reg.e = 113;
    cpu.reg.f = 192;
    cpu.reg.h = 92;
    cpu.reg.l = 124;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[3173] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 113);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 92);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 3174);
    // CHECK(cpu.reg.sp == 52377);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3173] == 0);
}

TEST_CASE( "00 0252", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16923;
    cpu.reg.sp = 38595;
    cpu.reg.a = 69;
    cpu.reg.b = 8;
    cpu.reg.c = 165;
    cpu.reg.d = 243;
    cpu.reg.e = 230;
    cpu.reg.f = 176;
    cpu.reg.h = 73;
    cpu.reg.l = 124;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[16923] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 8);
    CHECK(cpu.reg.c == 165);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 73);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 16924);
    // CHECK(cpu.reg.sp == 38595);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16923] == 0);
}

TEST_CASE( "00 0253", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19575;
    cpu.reg.sp = 34796;
    cpu.reg.a = 9;
    cpu.reg.b = 150;
    cpu.reg.c = 184;
    cpu.reg.d = 52;
    cpu.reg.e = 204;
    cpu.reg.f = 32;
    cpu.reg.h = 149;
    cpu.reg.l = 18;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19575] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 9);
    CHECK(cpu.reg.b == 150);
    CHECK(cpu.reg.c == 184);
    CHECK(cpu.reg.d == 52);
    CHECK(cpu.reg.e == 204);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 18);
    CHECK(cpu.reg.pc == 19576);
    // CHECK(cpu.reg.sp == 34796);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19575] == 0);
}

TEST_CASE( "00 0254", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38254;
    cpu.reg.sp = 36454;
    cpu.reg.a = 163;
    cpu.reg.b = 95;
    cpu.reg.c = 116;
    cpu.reg.d = 156;
    cpu.reg.e = 253;
    cpu.reg.f = 176;
    cpu.reg.h = 176;
    cpu.reg.l = 186;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[38254] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 163);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 156);
    CHECK(cpu.reg.e == 253);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 176);
    CHECK(cpu.reg.l == 186);
    CHECK(cpu.reg.pc == 38255);
    // CHECK(cpu.reg.sp == 36454);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38254] == 0);
}

TEST_CASE( "00 0255", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32414;
    cpu.reg.sp = 33864;
    cpu.reg.a = 24;
    cpu.reg.b = 196;
    cpu.reg.c = 153;
    cpu.reg.d = 219;
    cpu.reg.e = 27;
    cpu.reg.f = 96;
    cpu.reg.h = 93;
    cpu.reg.l = 40;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32414] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 24);
    CHECK(cpu.reg.b == 196);
    CHECK(cpu.reg.c == 153);
    CHECK(cpu.reg.d == 219);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 93);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 32415);
    // CHECK(cpu.reg.sp == 33864);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32414] == 0);
}

TEST_CASE( "00 0256", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58534;
    cpu.reg.sp = 47214;
    cpu.reg.a = 77;
    cpu.reg.b = 159;
    cpu.reg.c = 205;
    cpu.reg.d = 194;
    cpu.reg.e = 2;
    cpu.reg.f = 112;
    cpu.reg.h = 167;
    cpu.reg.l = 179;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[58534] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 77);
    CHECK(cpu.reg.b == 159);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 2);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 58535);
    // CHECK(cpu.reg.sp == 47214);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58534] == 0);
}

TEST_CASE( "00 0257", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30816;
    cpu.reg.sp = 61050;
    cpu.reg.a = 24;
    cpu.reg.b = 250;
    cpu.reg.c = 39;
    cpu.reg.d = 79;
    cpu.reg.e = 176;
    cpu.reg.f = 208;
    cpu.reg.h = 89;
    cpu.reg.l = 122;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[30816] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 24);
    CHECK(cpu.reg.b == 250);
    CHECK(cpu.reg.c == 39);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 89);
    CHECK(cpu.reg.l == 122);
    CHECK(cpu.reg.pc == 30817);
    // CHECK(cpu.reg.sp == 61050);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30816] == 0);
}

TEST_CASE( "00 0258", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34480;
    cpu.reg.sp = 8251;
    cpu.reg.a = 128;
    cpu.reg.b = 105;
    cpu.reg.c = 251;
    cpu.reg.d = 6;
    cpu.reg.e = 112;
    cpu.reg.f = 48;
    cpu.reg.h = 14;
    cpu.reg.l = 102;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[34480] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 251);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 112);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 14);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 34481);
    // CHECK(cpu.reg.sp == 8251);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34480] == 0);
}

TEST_CASE( "00 0259", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26140;
    cpu.reg.sp = 49192;
    cpu.reg.a = 203;
    cpu.reg.b = 73;
    cpu.reg.c = 70;
    cpu.reg.d = 186;
    cpu.reg.e = 232;
    cpu.reg.f = 144;
    cpu.reg.h = 9;
    cpu.reg.l = 157;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26140] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 203);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 70);
    CHECK(cpu.reg.d == 186);
    CHECK(cpu.reg.e == 232);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 9);
    CHECK(cpu.reg.l == 157);
    CHECK(cpu.reg.pc == 26141);
    // CHECK(cpu.reg.sp == 49192);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26140] == 0);
}

TEST_CASE( "00 025A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56787;
    cpu.reg.sp = 62410;
    cpu.reg.a = 120;
    cpu.reg.b = 150;
    cpu.reg.c = 118;
    cpu.reg.d = 229;
    cpu.reg.e = 9;
    cpu.reg.f = 16;
    cpu.reg.h = 51;
    cpu.reg.l = 244;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56787] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 150);
    CHECK(cpu.reg.c == 118);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 9);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 51);
    CHECK(cpu.reg.l == 244);
    CHECK(cpu.reg.pc == 56788);
    // CHECK(cpu.reg.sp == 62410);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56787] == 0);
}

TEST_CASE( "00 025B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43806;
    cpu.reg.sp = 41064;
    cpu.reg.a = 56;
    cpu.reg.b = 8;
    cpu.reg.c = 113;
    cpu.reg.d = 58;
    cpu.reg.e = 76;
    cpu.reg.f = 96;
    cpu.reg.h = 126;
    cpu.reg.l = 219;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43806] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 8);
    CHECK(cpu.reg.c == 113);
    CHECK(cpu.reg.d == 58);
    CHECK(cpu.reg.e == 76);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 126);
    CHECK(cpu.reg.l == 219);
    CHECK(cpu.reg.pc == 43807);
    // CHECK(cpu.reg.sp == 41064);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43806] == 0);
}

TEST_CASE( "00 025C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4177;
    cpu.reg.sp = 11591;
    cpu.reg.a = 27;
    cpu.reg.b = 122;
    cpu.reg.c = 202;
    cpu.reg.d = 234;
    cpu.reg.e = 22;
    cpu.reg.f = 32;
    cpu.reg.h = 114;
    cpu.reg.l = 244;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4177] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 27);
    CHECK(cpu.reg.b == 122);
    CHECK(cpu.reg.c == 202);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 22);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 114);
    CHECK(cpu.reg.l == 244);
    CHECK(cpu.reg.pc == 4178);
    // CHECK(cpu.reg.sp == 11591);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4177] == 0);
}

TEST_CASE( "00 025D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10796;
    cpu.reg.sp = 33024;
    cpu.reg.a = 215;
    cpu.reg.b = 83;
    cpu.reg.c = 162;
    cpu.reg.d = 10;
    cpu.reg.e = 99;
    cpu.reg.f = 240;
    cpu.reg.h = 80;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10796] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 83);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 10797);
    // CHECK(cpu.reg.sp == 33024);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10796] == 0);
}

TEST_CASE( "00 025E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57258;
    cpu.reg.sp = 51161;
    cpu.reg.a = 92;
    cpu.reg.b = 109;
    cpu.reg.c = 205;
    cpu.reg.d = 61;
    cpu.reg.e = 183;
    cpu.reg.f = 128;
    cpu.reg.h = 104;
    cpu.reg.l = 202;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[57258] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 92);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 61);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 104);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 57259);
    // CHECK(cpu.reg.sp == 51161);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57258] == 0);
}

TEST_CASE( "00 025F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7069;
    cpu.reg.sp = 7616;
    cpu.reg.a = 233;
    cpu.reg.b = 216;
    cpu.reg.c = 243;
    cpu.reg.d = 47;
    cpu.reg.e = 243;
    cpu.reg.f = 16;
    cpu.reg.h = 180;
    cpu.reg.l = 240;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[7069] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 233);
    CHECK(cpu.reg.b == 216);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 47);
    CHECK(cpu.reg.e == 243);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 7070);
    // CHECK(cpu.reg.sp == 7616);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7069] == 0);
}

TEST_CASE( "00 0260", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62333;
    cpu.reg.sp = 46686;
    cpu.reg.a = 134;
    cpu.reg.b = 116;
    cpu.reg.c = 9;
    cpu.reg.d = 47;
    cpu.reg.e = 90;
    cpu.reg.f = 176;
    cpu.reg.h = 74;
    cpu.reg.l = 138;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[62333] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 134);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 9);
    CHECK(cpu.reg.d == 47);
    CHECK(cpu.reg.e == 90);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 74);
    CHECK(cpu.reg.l == 138);
    CHECK(cpu.reg.pc == 62334);
    // CHECK(cpu.reg.sp == 46686);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62333] == 0);
}

TEST_CASE( "00 0261", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8479;
    cpu.reg.sp = 15977;
    cpu.reg.a = 146;
    cpu.reg.b = 194;
    cpu.reg.c = 122;
    cpu.reg.d = 172;
    cpu.reg.e = 33;
    cpu.reg.f = 208;
    cpu.reg.h = 195;
    cpu.reg.l = 142;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[8479] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 146);
    CHECK(cpu.reg.b == 194);
    CHECK(cpu.reg.c == 122);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 33);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 195);
    CHECK(cpu.reg.l == 142);
    CHECK(cpu.reg.pc == 8480);
    // CHECK(cpu.reg.sp == 15977);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8479] == 0);
}

TEST_CASE( "00 0262", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3268;
    cpu.reg.sp = 13836;
    cpu.reg.a = 16;
    cpu.reg.b = 24;
    cpu.reg.c = 121;
    cpu.reg.d = 105;
    cpu.reg.e = 223;
    cpu.reg.f = 32;
    cpu.reg.h = 3;
    cpu.reg.l = 170;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[3268] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 16);
    CHECK(cpu.reg.b == 24);
    CHECK(cpu.reg.c == 121);
    CHECK(cpu.reg.d == 105);
    CHECK(cpu.reg.e == 223);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 3);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 3269);
    // CHECK(cpu.reg.sp == 13836);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3268] == 0);
}

TEST_CASE( "00 0263", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48571;
    cpu.reg.sp = 28278;
    cpu.reg.a = 147;
    cpu.reg.b = 127;
    cpu.reg.c = 16;
    cpu.reg.d = 52;
    cpu.reg.e = 71;
    cpu.reg.f = 80;
    cpu.reg.h = 187;
    cpu.reg.l = 34;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[48571] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 147);
    CHECK(cpu.reg.b == 127);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 52);
    CHECK(cpu.reg.e == 71);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 187);
    CHECK(cpu.reg.l == 34);
    CHECK(cpu.reg.pc == 48572);
    // CHECK(cpu.reg.sp == 28278);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48571] == 0);
}

TEST_CASE( "00 0264", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28611;
    cpu.reg.sp = 26072;
    cpu.reg.a = 106;
    cpu.reg.b = 111;
    cpu.reg.c = 123;
    cpu.reg.d = 23;
    cpu.reg.e = 181;
    cpu.reg.f = 48;
    cpu.reg.h = 114;
    cpu.reg.l = 216;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[28611] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 106);
    CHECK(cpu.reg.b == 111);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 181);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 114);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 28612);
    // CHECK(cpu.reg.sp == 26072);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28611] == 0);
}

TEST_CASE( "00 0265", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46606;
    cpu.reg.sp = 44709;
    cpu.reg.a = 216;
    cpu.reg.b = 248;
    cpu.reg.c = 6;
    cpu.reg.d = 236;
    cpu.reg.e = 115;
    cpu.reg.f = 32;
    cpu.reg.h = 209;
    cpu.reg.l = 47;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[46606] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 216);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 6);
    CHECK(cpu.reg.d == 236);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 47);
    CHECK(cpu.reg.pc == 46607);
    // CHECK(cpu.reg.sp == 44709);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46606] == 0);
}

TEST_CASE( "00 0266", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39071;
    cpu.reg.sp = 49241;
    cpu.reg.a = 137;
    cpu.reg.b = 185;
    cpu.reg.c = 202;
    cpu.reg.d = 135;
    cpu.reg.e = 43;
    cpu.reg.f = 112;
    cpu.reg.h = 241;
    cpu.reg.l = 166;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39071] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 137);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 202);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 241);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 39072);
    // CHECK(cpu.reg.sp == 49241);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39071] == 0);
}

TEST_CASE( "00 0267", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54951;
    cpu.reg.sp = 59180;
    cpu.reg.a = 183;
    cpu.reg.b = 184;
    cpu.reg.c = 233;
    cpu.reg.d = 178;
    cpu.reg.e = 248;
    cpu.reg.f = 16;
    cpu.reg.h = 100;
    cpu.reg.l = 127;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54951] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 248);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 100);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 54952);
    // CHECK(cpu.reg.sp == 59180);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54951] == 0);
}

TEST_CASE( "00 0268", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10816;
    cpu.reg.sp = 49665;
    cpu.reg.a = 35;
    cpu.reg.b = 2;
    cpu.reg.c = 120;
    cpu.reg.d = 68;
    cpu.reg.e = 35;
    cpu.reg.f = 208;
    cpu.reg.h = 176;
    cpu.reg.l = 121;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10816] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 35);
    CHECK(cpu.reg.b == 2);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 35);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 176);
    CHECK(cpu.reg.l == 121);
    CHECK(cpu.reg.pc == 10817);
    // CHECK(cpu.reg.sp == 49665);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10816] == 0);
}

TEST_CASE( "00 0269", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60841;
    cpu.reg.sp = 45527;
    cpu.reg.a = 201;
    cpu.reg.b = 50;
    cpu.reg.c = 183;
    cpu.reg.d = 250;
    cpu.reg.e = 176;
    cpu.reg.f = 176;
    cpu.reg.h = 70;
    cpu.reg.l = 233;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60841] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 201);
    CHECK(cpu.reg.b == 50);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 250);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 70);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 60842);
    // CHECK(cpu.reg.sp == 45527);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60841] == 0);
}

TEST_CASE( "00 026A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63575;
    cpu.reg.sp = 15826;
    cpu.reg.a = 18;
    cpu.reg.b = 201;
    cpu.reg.c = 10;
    cpu.reg.d = 93;
    cpu.reg.e = 215;
    cpu.reg.f = 80;
    cpu.reg.h = 194;
    cpu.reg.l = 69;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[63575] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 18);
    CHECK(cpu.reg.b == 201);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 215);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 194);
    CHECK(cpu.reg.l == 69);
    CHECK(cpu.reg.pc == 63576);
    // CHECK(cpu.reg.sp == 15826);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63575] == 0);
}

TEST_CASE( "00 026B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54257;
    cpu.reg.sp = 5312;
    cpu.reg.a = 84;
    cpu.reg.b = 168;
    cpu.reg.c = 243;
    cpu.reg.d = 224;
    cpu.reg.e = 124;
    cpu.reg.f = 240;
    cpu.reg.h = 116;
    cpu.reg.l = 235;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[54257] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 168);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 224);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 116);
    CHECK(cpu.reg.l == 235);
    CHECK(cpu.reg.pc == 54258);
    // CHECK(cpu.reg.sp == 5312);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54257] == 0);
}

TEST_CASE( "00 026C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54393;
    cpu.reg.sp = 58590;
    cpu.reg.a = 95;
    cpu.reg.b = 216;
    cpu.reg.c = 69;
    cpu.reg.d = 51;
    cpu.reg.e = 153;
    cpu.reg.f = 208;
    cpu.reg.h = 110;
    cpu.reg.l = 127;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[54393] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 95);
    CHECK(cpu.reg.b == 216);
    CHECK(cpu.reg.c == 69);
    CHECK(cpu.reg.d == 51);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 110);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 54394);
    // CHECK(cpu.reg.sp == 58590);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54393] == 0);
}

TEST_CASE( "00 026D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42316;
    cpu.reg.sp = 11707;
    cpu.reg.a = 116;
    cpu.reg.b = 163;
    cpu.reg.c = 226;
    cpu.reg.d = 99;
    cpu.reg.e = 194;
    cpu.reg.f = 176;
    cpu.reg.h = 145;
    cpu.reg.l = 227;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[42316] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 116);
    CHECK(cpu.reg.b == 163);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 99);
    CHECK(cpu.reg.e == 194);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 145);
    CHECK(cpu.reg.l == 227);
    CHECK(cpu.reg.pc == 42317);
    // CHECK(cpu.reg.sp == 11707);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42316] == 0);
}

TEST_CASE( "00 026E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64624;
    cpu.reg.sp = 36377;
    cpu.reg.a = 36;
    cpu.reg.b = 204;
    cpu.reg.c = 108;
    cpu.reg.d = 183;
    cpu.reg.e = 200;
    cpu.reg.f = 224;
    cpu.reg.h = 123;
    cpu.reg.l = 68;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64624] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 36);
    CHECK(cpu.reg.b == 204);
    CHECK(cpu.reg.c == 108);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 123);
    CHECK(cpu.reg.l == 68);
    CHECK(cpu.reg.pc == 64625);
    // CHECK(cpu.reg.sp == 36377);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64624] == 0);
}

TEST_CASE( "00 026F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17391;
    cpu.reg.sp = 40800;
    cpu.reg.a = 49;
    cpu.reg.b = 96;
    cpu.reg.c = 46;
    cpu.reg.d = 128;
    cpu.reg.e = 67;
    cpu.reg.f = 128;
    cpu.reg.h = 63;
    cpu.reg.l = 231;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17391] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 49);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 128);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 63);
    CHECK(cpu.reg.l == 231);
    CHECK(cpu.reg.pc == 17392);
    // CHECK(cpu.reg.sp == 40800);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17391] == 0);
}

TEST_CASE( "00 0270", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17971;
    cpu.reg.sp = 27110;
    cpu.reg.a = 210;
    cpu.reg.b = 171;
    cpu.reg.c = 182;
    cpu.reg.d = 71;
    cpu.reg.e = 130;
    cpu.reg.f = 112;
    cpu.reg.h = 249;
    cpu.reg.l = 70;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[17971] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 130);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 249);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 17972);
    // CHECK(cpu.reg.sp == 27110);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17971] == 0);
}

TEST_CASE( "00 0271", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52619;
    cpu.reg.sp = 3297;
    cpu.reg.a = 90;
    cpu.reg.b = 26;
    cpu.reg.c = 229;
    cpu.reg.d = 177;
    cpu.reg.e = 219;
    cpu.reg.f = 112;
    cpu.reg.h = 59;
    cpu.reg.l = 205;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[52619] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 90);
    CHECK(cpu.reg.b == 26);
    CHECK(cpu.reg.c == 229);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 59);
    CHECK(cpu.reg.l == 205);
    CHECK(cpu.reg.pc == 52620);
    // CHECK(cpu.reg.sp == 3297);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52619] == 0);
}

TEST_CASE( "00 0272", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26527;
    cpu.reg.sp = 37554;
    cpu.reg.a = 113;
    cpu.reg.b = 164;
    cpu.reg.c = 42;
    cpu.reg.d = 220;
    cpu.reg.e = 213;
    cpu.reg.f = 0;
    cpu.reg.h = 152;
    cpu.reg.l = 106;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26527] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 113);
    CHECK(cpu.reg.b == 164);
    CHECK(cpu.reg.c == 42);
    CHECK(cpu.reg.d == 220);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 152);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 26528);
    // CHECK(cpu.reg.sp == 37554);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26527] == 0);
}

TEST_CASE( "00 0273", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40646;
    cpu.reg.sp = 34715;
    cpu.reg.a = 60;
    cpu.reg.b = 139;
    cpu.reg.c = 119;
    cpu.reg.d = 217;
    cpu.reg.e = 102;
    cpu.reg.f = 0;
    cpu.reg.h = 185;
    cpu.reg.l = 97;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40646] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 60);
    CHECK(cpu.reg.b == 139);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 217);
    CHECK(cpu.reg.e == 102);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 185);
    CHECK(cpu.reg.l == 97);
    CHECK(cpu.reg.pc == 40647);
    // CHECK(cpu.reg.sp == 34715);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40646] == 0);
}

TEST_CASE( "00 0274", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62141;
    cpu.reg.sp = 12820;
    cpu.reg.a = 162;
    cpu.reg.b = 56;
    cpu.reg.c = 233;
    cpu.reg.d = 36;
    cpu.reg.e = 59;
    cpu.reg.f = 128;
    cpu.reg.h = 186;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[62141] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 162);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 36);
    CHECK(cpu.reg.e == 59);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 62142);
    // CHECK(cpu.reg.sp == 12820);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62141] == 0);
}

TEST_CASE( "00 0275", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25613;
    cpu.reg.sp = 1053;
    cpu.reg.a = 214;
    cpu.reg.b = 6;
    cpu.reg.c = 162;
    cpu.reg.d = 66;
    cpu.reg.e = 241;
    cpu.reg.f = 80;
    cpu.reg.h = 155;
    cpu.reg.l = 84;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[25613] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 214);
    CHECK(cpu.reg.b == 6);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 66);
    CHECK(cpu.reg.e == 241);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 155);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 25614);
    // CHECK(cpu.reg.sp == 1053);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25613] == 0);
}

TEST_CASE( "00 0276", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14714;
    cpu.reg.sp = 15361;
    cpu.reg.a = 211;
    cpu.reg.b = 151;
    cpu.reg.c = 94;
    cpu.reg.d = 12;
    cpu.reg.e = 212;
    cpu.reg.f = 240;
    cpu.reg.h = 206;
    cpu.reg.l = 93;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[14714] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 211);
    CHECK(cpu.reg.b == 151);
    CHECK(cpu.reg.c == 94);
    CHECK(cpu.reg.d == 12);
    CHECK(cpu.reg.e == 212);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 93);
    CHECK(cpu.reg.pc == 14715);
    // CHECK(cpu.reg.sp == 15361);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14714] == 0);
}

TEST_CASE( "00 0277", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32613;
    cpu.reg.sp = 23224;
    cpu.reg.a = 155;
    cpu.reg.b = 156;
    cpu.reg.c = 141;
    cpu.reg.d = 30;
    cpu.reg.e = 152;
    cpu.reg.f = 96;
    cpu.reg.h = 238;
    cpu.reg.l = 86;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32613] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 155);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 30);
    CHECK(cpu.reg.e == 152);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 238);
    CHECK(cpu.reg.l == 86);
    CHECK(cpu.reg.pc == 32614);
    // CHECK(cpu.reg.sp == 23224);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32613] == 0);
}

TEST_CASE( "00 0278", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63329;
    cpu.reg.sp = 49082;
    cpu.reg.a = 198;
    cpu.reg.b = 139;
    cpu.reg.c = 60;
    cpu.reg.d = 184;
    cpu.reg.e = 14;
    cpu.reg.f = 192;
    cpu.reg.h = 135;
    cpu.reg.l = 165;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63329] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 139);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 14);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 135);
    CHECK(cpu.reg.l == 165);
    CHECK(cpu.reg.pc == 63330);
    // CHECK(cpu.reg.sp == 49082);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63329] == 0);
}

TEST_CASE( "00 0279", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41665;
    cpu.reg.sp = 15368;
    cpu.reg.a = 154;
    cpu.reg.b = 176;
    cpu.reg.c = 202;
    cpu.reg.d = 127;
    cpu.reg.e = 99;
    cpu.reg.f = 64;
    cpu.reg.h = 196;
    cpu.reg.l = 128;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[41665] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 154);
    CHECK(cpu.reg.b == 176);
    CHECK(cpu.reg.c == 202);
    CHECK(cpu.reg.d == 127);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 196);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 41666);
    // CHECK(cpu.reg.sp == 15368);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[41665] == 0);
}

TEST_CASE( "00 027A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48353;
    cpu.reg.sp = 10517;
    cpu.reg.a = 222;
    cpu.reg.b = 147;
    cpu.reg.c = 90;
    cpu.reg.d = 20;
    cpu.reg.e = 19;
    cpu.reg.f = 16;
    cpu.reg.h = 40;
    cpu.reg.l = 100;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48353] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 222);
    CHECK(cpu.reg.b == 147);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 40);
    CHECK(cpu.reg.l == 100);
    CHECK(cpu.reg.pc == 48354);
    // CHECK(cpu.reg.sp == 10517);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48353] == 0);
}

TEST_CASE( "00 027B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49792;
    cpu.reg.sp = 5499;
    cpu.reg.a = 56;
    cpu.reg.b = 34;
    cpu.reg.c = 51;
    cpu.reg.d = 8;
    cpu.reg.e = 144;
    cpu.reg.f = 80;
    cpu.reg.h = 193;
    cpu.reg.l = 251;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[49792] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 34);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 8);
    CHECK(cpu.reg.e == 144);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 193);
    CHECK(cpu.reg.l == 251);
    CHECK(cpu.reg.pc == 49793);
    // CHECK(cpu.reg.sp == 5499);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[49792] == 0);
}

TEST_CASE( "00 027C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30306;
    cpu.reg.sp = 58274;
    cpu.reg.a = 13;
    cpu.reg.b = 141;
    cpu.reg.c = 208;
    cpu.reg.d = 70;
    cpu.reg.e = 202;
    cpu.reg.f = 144;
    cpu.reg.h = 180;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[30306] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 13);
    CHECK(cpu.reg.b == 141);
    CHECK(cpu.reg.c == 208);
    CHECK(cpu.reg.d == 70);
    CHECK(cpu.reg.e == 202);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 30307);
    // CHECK(cpu.reg.sp == 58274);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30306] == 0);
}

TEST_CASE( "00 027D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49244;
    cpu.reg.sp = 8290;
    cpu.reg.a = 39;
    cpu.reg.b = 90;
    cpu.reg.c = 81;
    cpu.reg.d = 10;
    cpu.reg.e = 238;
    cpu.reg.f = 64;
    cpu.reg.h = 168;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49244] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 39);
    CHECK(cpu.reg.b == 90);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 238);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 168);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 49245);
    // CHECK(cpu.reg.sp == 8290);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49244] == 0);
}

TEST_CASE( "00 027E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50842;
    cpu.reg.sp = 36229;
    cpu.reg.a = 69;
    cpu.reg.b = 105;
    cpu.reg.c = 83;
    cpu.reg.d = 108;
    cpu.reg.e = 243;
    cpu.reg.f = 192;
    cpu.reg.h = 184;
    cpu.reg.l = 113;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[50842] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 243);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 184);
    CHECK(cpu.reg.l == 113);
    CHECK(cpu.reg.pc == 50843);
    // CHECK(cpu.reg.sp == 36229);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50842] == 0);
}

TEST_CASE( "00 027F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35214;
    cpu.reg.sp = 11866;
    cpu.reg.a = 221;
    cpu.reg.b = 38;
    cpu.reg.c = 46;
    cpu.reg.d = 104;
    cpu.reg.e = 10;
    cpu.reg.f = 144;
    cpu.reg.h = 10;
    cpu.reg.l = 48;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35214] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 38);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 10);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 10);
    CHECK(cpu.reg.l == 48);
    CHECK(cpu.reg.pc == 35215);
    // CHECK(cpu.reg.sp == 11866);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35214] == 0);
}

TEST_CASE( "00 0280", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46967;
    cpu.reg.sp = 35325;
    cpu.reg.a = 141;
    cpu.reg.b = 55;
    cpu.reg.c = 89;
    cpu.reg.d = 242;
    cpu.reg.e = 203;
    cpu.reg.f = 96;
    cpu.reg.h = 148;
    cpu.reg.l = 188;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[46967] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 55);
    CHECK(cpu.reg.c == 89);
    CHECK(cpu.reg.d == 242);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 148);
    CHECK(cpu.reg.l == 188);
    CHECK(cpu.reg.pc == 46968);
    // CHECK(cpu.reg.sp == 35325);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[46967] == 0);
}

TEST_CASE( "00 0281", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55138;
    cpu.reg.sp = 34965;
    cpu.reg.a = 132;
    cpu.reg.b = 75;
    cpu.reg.c = 139;
    cpu.reg.d = 117;
    cpu.reg.e = 17;
    cpu.reg.f = 224;
    cpu.reg.h = 237;
    cpu.reg.l = 24;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[55138] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 132);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 139);
    CHECK(cpu.reg.d == 117);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 237);
    CHECK(cpu.reg.l == 24);
    CHECK(cpu.reg.pc == 55139);
    // CHECK(cpu.reg.sp == 34965);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[55138] == 0);
}

TEST_CASE( "00 0282", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43376;
    cpu.reg.sp = 8971;
    cpu.reg.a = 96;
    cpu.reg.b = 120;
    cpu.reg.c = 109;
    cpu.reg.d = 81;
    cpu.reg.e = 32;
    cpu.reg.f = 0;
    cpu.reg.h = 141;
    cpu.reg.l = 134;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[43376] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 120);
    CHECK(cpu.reg.c == 109);
    CHECK(cpu.reg.d == 81);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 134);
    CHECK(cpu.reg.pc == 43377);
    // CHECK(cpu.reg.sp == 8971);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43376] == 0);
}

TEST_CASE( "00 0283", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14187;
    cpu.reg.sp = 38680;
    cpu.reg.a = 47;
    cpu.reg.b = 83;
    cpu.reg.c = 68;
    cpu.reg.d = 216;
    cpu.reg.e = 222;
    cpu.reg.f = 192;
    cpu.reg.h = 210;
    cpu.reg.l = 219;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[14187] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 47);
    CHECK(cpu.reg.b == 83);
    CHECK(cpu.reg.c == 68);
    CHECK(cpu.reg.d == 216);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 210);
    CHECK(cpu.reg.l == 219);
    CHECK(cpu.reg.pc == 14188);
    // CHECK(cpu.reg.sp == 38680);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[14187] == 0);
}

TEST_CASE( "00 0284", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 748;
    cpu.reg.sp = 5461;
    cpu.reg.a = 149;
    cpu.reg.b = 186;
    cpu.reg.c = 19;
    cpu.reg.d = 167;
    cpu.reg.e = 154;
    cpu.reg.f = 128;
    cpu.reg.h = 9;
    cpu.reg.l = 194;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[748] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 149);
    CHECK(cpu.reg.b == 186);
    CHECK(cpu.reg.c == 19);
    CHECK(cpu.reg.d == 167);
    CHECK(cpu.reg.e == 154);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 9);
    CHECK(cpu.reg.l == 194);
    CHECK(cpu.reg.pc == 749);
    // CHECK(cpu.reg.sp == 5461);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[748] == 0);
}

TEST_CASE( "00 0285", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30659;
    cpu.reg.sp = 5464;
    cpu.reg.a = 208;
    cpu.reg.b = 198;
    cpu.reg.c = 138;
    cpu.reg.d = 191;
    cpu.reg.e = 192;
    cpu.reg.f = 112;
    cpu.reg.h = 111;
    cpu.reg.l = 196;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30659] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 198);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 191);
    CHECK(cpu.reg.e == 192);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 111);
    CHECK(cpu.reg.l == 196);
    CHECK(cpu.reg.pc == 30660);
    // CHECK(cpu.reg.sp == 5464);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30659] == 0);
}

TEST_CASE( "00 0286", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30388;
    cpu.reg.sp = 7836;
    cpu.reg.a = 184;
    cpu.reg.b = 79;
    cpu.reg.c = 171;
    cpu.reg.d = 225;
    cpu.reg.e = 168;
    cpu.reg.f = 80;
    cpu.reg.h = 10;
    cpu.reg.l = 131;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[30388] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 79);
    CHECK(cpu.reg.c == 171);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 10);
    CHECK(cpu.reg.l == 131);
    CHECK(cpu.reg.pc == 30389);
    // CHECK(cpu.reg.sp == 7836);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30388] == 0);
}

TEST_CASE( "00 0287", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24322;
    cpu.reg.sp = 36422;
    cpu.reg.a = 38;
    cpu.reg.b = 110;
    cpu.reg.c = 28;
    cpu.reg.d = 79;
    cpu.reg.e = 230;
    cpu.reg.f = 160;
    cpu.reg.h = 244;
    cpu.reg.l = 216;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[24322] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 38);
    CHECK(cpu.reg.b == 110);
    CHECK(cpu.reg.c == 28);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 244);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 24323);
    // CHECK(cpu.reg.sp == 36422);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[24322] == 0);
}

TEST_CASE( "00 0288", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40401;
    cpu.reg.sp = 17973;
    cpu.reg.a = 46;
    cpu.reg.b = 190;
    cpu.reg.c = 71;
    cpu.reg.d = 38;
    cpu.reg.e = 237;
    cpu.reg.f = 32;
    cpu.reg.h = 139;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[40401] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 46);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 38);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 40402);
    // CHECK(cpu.reg.sp == 17973);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40401] == 0);
}

TEST_CASE( "00 0289", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33187;
    cpu.reg.sp = 19318;
    cpu.reg.a = 167;
    cpu.reg.b = 85;
    cpu.reg.c = 42;
    cpu.reg.d = 208;
    cpu.reg.e = 83;
    cpu.reg.f = 224;
    cpu.reg.h = 245;
    cpu.reg.l = 83;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[33187] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 167);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 42);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 83);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 83);
    CHECK(cpu.reg.pc == 33188);
    // CHECK(cpu.reg.sp == 19318);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33187] == 0);
}

TEST_CASE( "00 028A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44730;
    cpu.reg.sp = 23722;
    cpu.reg.a = 94;
    cpu.reg.b = 159;
    cpu.reg.c = 224;
    cpu.reg.d = 20;
    cpu.reg.e = 166;
    cpu.reg.f = 192;
    cpu.reg.h = 140;
    cpu.reg.l = 107;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44730] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 159);
    CHECK(cpu.reg.c == 224);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 166);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 44731);
    // CHECK(cpu.reg.sp == 23722);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44730] == 0);
}

TEST_CASE( "00 028B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29939;
    cpu.reg.sp = 22950;
    cpu.reg.a = 129;
    cpu.reg.b = 181;
    cpu.reg.c = 67;
    cpu.reg.d = 122;
    cpu.reg.e = 11;
    cpu.reg.f = 208;
    cpu.reg.h = 38;
    cpu.reg.l = 101;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[29939] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 129);
    CHECK(cpu.reg.b == 181);
    CHECK(cpu.reg.c == 67);
    CHECK(cpu.reg.d == 122);
    CHECK(cpu.reg.e == 11);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 29940);
    // CHECK(cpu.reg.sp == 22950);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29939] == 0);
}

TEST_CASE( "00 028C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34653;
    cpu.reg.sp = 51151;
    cpu.reg.a = 148;
    cpu.reg.b = 75;
    cpu.reg.c = 129;
    cpu.reg.d = 29;
    cpu.reg.e = 171;
    cpu.reg.f = 96;
    cpu.reg.h = 65;
    cpu.reg.l = 148;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34653] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 129);
    CHECK(cpu.reg.d == 29);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 65);
    CHECK(cpu.reg.l == 148);
    CHECK(cpu.reg.pc == 34654);
    // CHECK(cpu.reg.sp == 51151);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34653] == 0);
}

TEST_CASE( "00 028D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16818;
    cpu.reg.sp = 40317;
    cpu.reg.a = 30;
    cpu.reg.b = 185;
    cpu.reg.c = 113;
    cpu.reg.d = 240;
    cpu.reg.e = 85;
    cpu.reg.f = 208;
    cpu.reg.h = 25;
    cpu.reg.l = 179;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[16818] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 30);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 113);
    CHECK(cpu.reg.d == 240);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 25);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 16819);
    // CHECK(cpu.reg.sp == 40317);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16818] == 0);
}

TEST_CASE( "00 028E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37994;
    cpu.reg.sp = 61119;
    cpu.reg.a = 108;
    cpu.reg.b = 129;
    cpu.reg.c = 19;
    cpu.reg.d = 179;
    cpu.reg.e = 27;
    cpu.reg.f = 112;
    cpu.reg.h = 34;
    cpu.reg.l = 187;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[37994] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 108);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 19);
    CHECK(cpu.reg.d == 179);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 34);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 37995);
    // CHECK(cpu.reg.sp == 61119);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37994] == 0);
}

TEST_CASE( "00 028F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5805;
    cpu.reg.sp = 59516;
    cpu.reg.a = 58;
    cpu.reg.b = 35;
    cpu.reg.c = 3;
    cpu.reg.d = 46;
    cpu.reg.e = 211;
    cpu.reg.f = 16;
    cpu.reg.h = 192;
    cpu.reg.l = 133;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[5805] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 58);
    CHECK(cpu.reg.b == 35);
    CHECK(cpu.reg.c == 3);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 211);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 192);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 5806);
    // CHECK(cpu.reg.sp == 59516);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[5805] == 0);
}

TEST_CASE( "00 0290", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55273;
    cpu.reg.sp = 29225;
    cpu.reg.a = 213;
    cpu.reg.b = 221;
    cpu.reg.c = 236;
    cpu.reg.d = 11;
    cpu.reg.e = 129;
    cpu.reg.f = 16;
    cpu.reg.h = 239;
    cpu.reg.l = 116;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[55273] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 213);
    CHECK(cpu.reg.b == 221);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 11);
    CHECK(cpu.reg.e == 129);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 239);
    CHECK(cpu.reg.l == 116);
    CHECK(cpu.reg.pc == 55274);
    // CHECK(cpu.reg.sp == 29225);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[55273] == 0);
}

TEST_CASE( "00 0291", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 250;
    cpu.reg.sp = 28469;
    cpu.reg.a = 222;
    cpu.reg.b = 208;
    cpu.reg.c = 190;
    cpu.reg.d = 31;
    cpu.reg.e = 127;
    cpu.reg.f = 64;
    cpu.reg.h = 185;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[250] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 222);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 127);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 185);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 251);
    // CHECK(cpu.reg.sp == 28469);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[250] == 0);
}

TEST_CASE( "00 0292", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25035;
    cpu.reg.sp = 54491;
    cpu.reg.a = 50;
    cpu.reg.b = 85;
    cpu.reg.c = 226;
    cpu.reg.d = 3;
    cpu.reg.e = 170;
    cpu.reg.f = 144;
    cpu.reg.h = 203;
    cpu.reg.l = 135;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[25035] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 3);
    CHECK(cpu.reg.e == 170);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 203);
    CHECK(cpu.reg.l == 135);
    CHECK(cpu.reg.pc == 25036);
    // CHECK(cpu.reg.sp == 54491);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25035] == 0);
}

TEST_CASE( "00 0293", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62654;
    cpu.reg.sp = 37927;
    cpu.reg.a = 207;
    cpu.reg.b = 106;
    cpu.reg.c = 131;
    cpu.reg.d = 26;
    cpu.reg.e = 3;
    cpu.reg.f = 80;
    cpu.reg.h = 182;
    cpu.reg.l = 226;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[62654] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 207);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 131);
    CHECK(cpu.reg.d == 26);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 226);
    CHECK(cpu.reg.pc == 62655);
    // CHECK(cpu.reg.sp == 37927);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62654] == 0);
}

TEST_CASE( "00 0294", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31885;
    cpu.reg.sp = 23312;
    cpu.reg.a = 178;
    cpu.reg.b = 66;
    cpu.reg.c = 148;
    cpu.reg.d = 123;
    cpu.reg.e = 143;
    cpu.reg.f = 16;
    cpu.reg.h = 182;
    cpu.reg.l = 253;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[31885] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 178);
    CHECK(cpu.reg.b == 66);
    CHECK(cpu.reg.c == 148);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 143);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 31886);
    // CHECK(cpu.reg.sp == 23312);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31885] == 0);
}

TEST_CASE( "00 0295", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29762;
    cpu.reg.sp = 8964;
    cpu.reg.a = 151;
    cpu.reg.b = 109;
    cpu.reg.c = 232;
    cpu.reg.d = 144;
    cpu.reg.e = 114;
    cpu.reg.f = 0;
    cpu.reg.h = 24;
    cpu.reg.l = 78;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29762] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 151);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 232);
    CHECK(cpu.reg.d == 144);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 78);
    CHECK(cpu.reg.pc == 29763);
    // CHECK(cpu.reg.sp == 8964);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29762] == 0);
}

TEST_CASE( "00 0296", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64888;
    cpu.reg.sp = 23131;
    cpu.reg.a = 185;
    cpu.reg.b = 135;
    cpu.reg.c = 13;
    cpu.reg.d = 183;
    cpu.reg.e = 247;
    cpu.reg.f = 240;
    cpu.reg.h = 236;
    cpu.reg.l = 203;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64888] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 185);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 247);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 203);
    CHECK(cpu.reg.pc == 64889);
    // CHECK(cpu.reg.sp == 23131);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64888] == 0);
}

TEST_CASE( "00 0297", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38964;
    cpu.reg.sp = 60;
    cpu.reg.a = 191;
    cpu.reg.b = 248;
    cpu.reg.c = 248;
    cpu.reg.d = 197;
    cpu.reg.e = 228;
    cpu.reg.f = 0;
    cpu.reg.h = 254;
    cpu.reg.l = 179;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[38964] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 228);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 254);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 38965);
    // CHECK(cpu.reg.sp == 60);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38964] == 0);
}

TEST_CASE( "00 0298", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31306;
    cpu.reg.sp = 9661;
    cpu.reg.a = 176;
    cpu.reg.b = 7;
    cpu.reg.c = 51;
    cpu.reg.d = 117;
    cpu.reg.e = 139;
    cpu.reg.f = 128;
    cpu.reg.h = 123;
    cpu.reg.l = 106;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[31306] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 176);
    CHECK(cpu.reg.b == 7);
    CHECK(cpu.reg.c == 51);
    CHECK(cpu.reg.d == 117);
    CHECK(cpu.reg.e == 139);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 123);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 31307);
    // CHECK(cpu.reg.sp == 9661);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31306] == 0);
}

TEST_CASE( "00 0299", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41165;
    cpu.reg.sp = 64837;
    cpu.reg.a = 54;
    cpu.reg.b = 22;
    cpu.reg.c = 240;
    cpu.reg.d = 229;
    cpu.reg.e = 223;
    cpu.reg.f = 0;
    cpu.reg.h = 112;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[41165] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 54);
    CHECK(cpu.reg.b == 22);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 223);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 41166);
    // CHECK(cpu.reg.sp == 64837);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41165] == 0);
}

TEST_CASE( "00 029A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62209;
    cpu.reg.sp = 32715;
    cpu.reg.a = 208;
    cpu.reg.b = 92;
    cpu.reg.c = 131;
    cpu.reg.d = 223;
    cpu.reg.e = 48;
    cpu.reg.f = 128;
    cpu.reg.h = 146;
    cpu.reg.l = 163;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62209] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 92);
    CHECK(cpu.reg.c == 131);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 146);
    CHECK(cpu.reg.l == 163);
    CHECK(cpu.reg.pc == 62210);
    // CHECK(cpu.reg.sp == 32715);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62209] == 0);
}

TEST_CASE( "00 029B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60101;
    cpu.reg.sp = 38320;
    cpu.reg.a = 240;
    cpu.reg.b = 196;
    cpu.reg.c = 217;
    cpu.reg.d = 228;
    cpu.reg.e = 230;
    cpu.reg.f = 112;
    cpu.reg.h = 198;
    cpu.reg.l = 167;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[60101] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 240);
    CHECK(cpu.reg.b == 196);
    CHECK(cpu.reg.c == 217);
    CHECK(cpu.reg.d == 228);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 198);
    CHECK(cpu.reg.l == 167);
    CHECK(cpu.reg.pc == 60102);
    // CHECK(cpu.reg.sp == 38320);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60101] == 0);
}

TEST_CASE( "00 029C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12756;
    cpu.reg.sp = 46275;
    cpu.reg.a = 210;
    cpu.reg.b = 56;
    cpu.reg.c = 42;
    cpu.reg.d = 226;
    cpu.reg.e = 58;
    cpu.reg.f = 208;
    cpu.reg.h = 116;
    cpu.reg.l = 99;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[12756] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 42);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 58);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 116);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 12757);
    // CHECK(cpu.reg.sp == 46275);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12756] == 0);
}

TEST_CASE( "00 029D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28379;
    cpu.reg.sp = 61914;
    cpu.reg.a = 22;
    cpu.reg.b = 142;
    cpu.reg.c = 13;
    cpu.reg.d = 188;
    cpu.reg.e = 61;
    cpu.reg.f = 64;
    cpu.reg.h = 90;
    cpu.reg.l = 223;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[28379] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 22);
    CHECK(cpu.reg.b == 142);
    CHECK(cpu.reg.c == 13);
    CHECK(cpu.reg.d == 188);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 90);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 28380);
    // CHECK(cpu.reg.sp == 61914);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28379] == 0);
}

TEST_CASE( "00 029E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19909;
    cpu.reg.sp = 13740;
    cpu.reg.a = 31;
    cpu.reg.b = 181;
    cpu.reg.c = 99;
    cpu.reg.d = 190;
    cpu.reg.e = 63;
    cpu.reg.f = 16;
    cpu.reg.h = 2;
    cpu.reg.l = 132;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19909] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 31);
    CHECK(cpu.reg.b == 181);
    CHECK(cpu.reg.c == 99);
    CHECK(cpu.reg.d == 190);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 2);
    CHECK(cpu.reg.l == 132);
    CHECK(cpu.reg.pc == 19910);
    // CHECK(cpu.reg.sp == 13740);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19909] == 0);
}

TEST_CASE( "00 029F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64015;
    cpu.reg.sp = 373;
    cpu.reg.a = 198;
    cpu.reg.b = 175;
    cpu.reg.c = 72;
    cpu.reg.d = 24;
    cpu.reg.e = 190;
    cpu.reg.f = 128;
    cpu.reg.h = 214;
    cpu.reg.l = 188;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64015] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 24);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 214);
    CHECK(cpu.reg.l == 188);
    CHECK(cpu.reg.pc == 64016);
    // CHECK(cpu.reg.sp == 373);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64015] == 0);
}

TEST_CASE( "00 02A0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32696;
    cpu.reg.sp = 3226;
    cpu.reg.a = 49;
    cpu.reg.b = 102;
    cpu.reg.c = 14;
    cpu.reg.d = 221;
    cpu.reg.e = 66;
    cpu.reg.f = 64;
    cpu.reg.h = 232;
    cpu.reg.l = 63;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[32696] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 49);
    CHECK(cpu.reg.b == 102);
    CHECK(cpu.reg.c == 14);
    CHECK(cpu.reg.d == 221);
    CHECK(cpu.reg.e == 66);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 32697);
    // CHECK(cpu.reg.sp == 3226);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32696] == 0);
}

TEST_CASE( "00 02A1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40789;
    cpu.reg.sp = 21255;
    cpu.reg.a = 188;
    cpu.reg.b = 223;
    cpu.reg.c = 17;
    cpu.reg.d = 193;
    cpu.reg.e = 213;
    cpu.reg.f = 0;
    cpu.reg.h = 28;
    cpu.reg.l = 217;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[40789] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 188);
    CHECK(cpu.reg.b == 223);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 193);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 217);
    CHECK(cpu.reg.pc == 40790);
    // CHECK(cpu.reg.sp == 21255);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40789] == 0);
}

TEST_CASE( "00 02A2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48783;
    cpu.reg.sp = 6312;
    cpu.reg.a = 139;
    cpu.reg.b = 235;
    cpu.reg.c = 38;
    cpu.reg.d = 132;
    cpu.reg.e = 70;
    cpu.reg.f = 96;
    cpu.reg.h = 30;
    cpu.reg.l = 221;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48783] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 38);
    CHECK(cpu.reg.d == 132);
    CHECK(cpu.reg.e == 70);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 30);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 48784);
    // CHECK(cpu.reg.sp == 6312);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48783] == 0);
}

TEST_CASE( "00 02A3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53805;
    cpu.reg.sp = 10072;
    cpu.reg.a = 236;
    cpu.reg.b = 40;
    cpu.reg.c = 10;
    cpu.reg.d = 114;
    cpu.reg.e = 241;
    cpu.reg.f = 224;
    cpu.reg.h = 113;
    cpu.reg.l = 214;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53805] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 236);
    CHECK(cpu.reg.b == 40);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 241);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 113);
    CHECK(cpu.reg.l == 214);
    CHECK(cpu.reg.pc == 53806);
    // CHECK(cpu.reg.sp == 10072);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53805] == 0);
}

TEST_CASE( "00 02A4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57353;
    cpu.reg.sp = 40739;
    cpu.reg.a = 6;
    cpu.reg.b = 85;
    cpu.reg.c = 240;
    cpu.reg.d = 64;
    cpu.reg.e = 30;
    cpu.reg.f = 48;
    cpu.reg.h = 65;
    cpu.reg.l = 65;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[57353] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 6);
    CHECK(cpu.reg.b == 85);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 30);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 65);
    CHECK(cpu.reg.l == 65);
    CHECK(cpu.reg.pc == 57354);
    // CHECK(cpu.reg.sp == 40739);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57353] == 0);
}

TEST_CASE( "00 02A5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51324;
    cpu.reg.sp = 16983;
    cpu.reg.a = 31;
    cpu.reg.b = 70;
    cpu.reg.c = 53;
    cpu.reg.d = 112;
    cpu.reg.e = 222;
    cpu.reg.f = 128;
    cpu.reg.h = 252;
    cpu.reg.l = 238;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[51324] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 31);
    CHECK(cpu.reg.b == 70);
    CHECK(cpu.reg.c == 53);
    CHECK(cpu.reg.d == 112);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 252);
    CHECK(cpu.reg.l == 238);
    CHECK(cpu.reg.pc == 51325);
    // CHECK(cpu.reg.sp == 16983);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[51324] == 0);
}

TEST_CASE( "00 02A6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61359;
    cpu.reg.sp = 28843;
    cpu.reg.a = 141;
    cpu.reg.b = 112;
    cpu.reg.c = 154;
    cpu.reg.d = 35;
    cpu.reg.e = 118;
    cpu.reg.f = 32;
    cpu.reg.h = 183;
    cpu.reg.l = 31;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61359] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 112);
    CHECK(cpu.reg.c == 154);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 118);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 183);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 61360);
    // CHECK(cpu.reg.sp == 28843);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61359] == 0);
}

TEST_CASE( "00 02A7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40408;
    cpu.reg.sp = 22076;
    cpu.reg.a = 183;
    cpu.reg.b = 243;
    cpu.reg.c = 63;
    cpu.reg.d = 24;
    cpu.reg.e = 119;
    cpu.reg.f = 144;
    cpu.reg.h = 53;
    cpu.reg.l = 179;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[40408] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 243);
    CHECK(cpu.reg.c == 63);
    CHECK(cpu.reg.d == 24);
    CHECK(cpu.reg.e == 119);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 40409);
    // CHECK(cpu.reg.sp == 22076);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40408] == 0);
}

TEST_CASE( "00 02A8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7612;
    cpu.reg.sp = 40975;
    cpu.reg.a = 87;
    cpu.reg.b = 129;
    cpu.reg.c = 192;
    cpu.reg.d = 48;
    cpu.reg.e = 189;
    cpu.reg.f = 0;
    cpu.reg.h = 52;
    cpu.reg.l = 41;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[7612] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 87);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 192);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 189);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 52);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 7613);
    // CHECK(cpu.reg.sp == 40975);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7612] == 0);
}

TEST_CASE( "00 02A9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 50124;
    cpu.reg.sp = 59524;
    cpu.reg.a = 206;
    cpu.reg.b = 8;
    cpu.reg.c = 80;
    cpu.reg.d = 32;
    cpu.reg.e = 74;
    cpu.reg.f = 128;
    cpu.reg.h = 15;
    cpu.reg.l = 99;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[50124] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 8);
    CHECK(cpu.reg.c == 80);
    CHECK(cpu.reg.d == 32);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 15);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 50125);
    // CHECK(cpu.reg.sp == 59524);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[50124] == 0);
}

TEST_CASE( "00 02AA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49753;
    cpu.reg.sp = 30781;
    cpu.reg.a = 118;
    cpu.reg.b = 16;
    cpu.reg.c = 116;
    cpu.reg.d = 201;
    cpu.reg.e = 236;
    cpu.reg.f = 48;
    cpu.reg.h = 130;
    cpu.reg.l = 7;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49753] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 201);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 130);
    CHECK(cpu.reg.l == 7);
    CHECK(cpu.reg.pc == 49754);
    // CHECK(cpu.reg.sp == 30781);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49753] == 0);
}

TEST_CASE( "00 02AB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52609;
    cpu.reg.sp = 2432;
    cpu.reg.a = 72;
    cpu.reg.b = 191;
    cpu.reg.c = 25;
    cpu.reg.d = 154;
    cpu.reg.e = 223;
    cpu.reg.f = 16;
    cpu.reg.h = 67;
    cpu.reg.l = 10;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[52609] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 72);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 25);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 223);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 10);
    CHECK(cpu.reg.pc == 52610);
    // CHECK(cpu.reg.sp == 2432);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52609] == 0);
}

TEST_CASE( "00 02AC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30257;
    cpu.reg.sp = 32443;
    cpu.reg.a = 239;
    cpu.reg.b = 228;
    cpu.reg.c = 32;
    cpu.reg.d = 195;
    cpu.reg.e = 60;
    cpu.reg.f = 80;
    cpu.reg.h = 175;
    cpu.reg.l = 4;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30257] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 239);
    CHECK(cpu.reg.b == 228);
    CHECK(cpu.reg.c == 32);
    CHECK(cpu.reg.d == 195);
    CHECK(cpu.reg.e == 60);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 175);
    CHECK(cpu.reg.l == 4);
    CHECK(cpu.reg.pc == 30258);
    // CHECK(cpu.reg.sp == 32443);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30257] == 0);
}

TEST_CASE( "00 02AD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20822;
    cpu.reg.sp = 17989;
    cpu.reg.a = 152;
    cpu.reg.b = 98;
    cpu.reg.c = 237;
    cpu.reg.d = 56;
    cpu.reg.e = 75;
    cpu.reg.f = 240;
    cpu.reg.h = 174;
    cpu.reg.l = 55;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[20822] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 152);
    CHECK(cpu.reg.b == 98);
    CHECK(cpu.reg.c == 237);
    CHECK(cpu.reg.d == 56);
    CHECK(cpu.reg.e == 75);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 174);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 20823);
    // CHECK(cpu.reg.sp == 17989);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[20822] == 0);
}

TEST_CASE( "00 02AE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19482;
    cpu.reg.sp = 33200;
    cpu.reg.a = 30;
    cpu.reg.b = 40;
    cpu.reg.c = 240;
    cpu.reg.d = 107;
    cpu.reg.e = 4;
    cpu.reg.f = 144;
    cpu.reg.h = 0;
    cpu.reg.l = 188;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[19482] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 30);
    CHECK(cpu.reg.b == 40);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 107);
    CHECK(cpu.reg.e == 4);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 188);
    CHECK(cpu.reg.pc == 19483);
    // CHECK(cpu.reg.sp == 33200);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19482] == 0);
}

TEST_CASE( "00 02AF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63637;
    cpu.reg.sp = 15701;
    cpu.reg.a = 214;
    cpu.reg.b = 223;
    cpu.reg.c = 241;
    cpu.reg.d = 173;
    cpu.reg.e = 190;
    cpu.reg.f = 48;
    cpu.reg.h = 35;
    cpu.reg.l = 218;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63637] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 214);
    CHECK(cpu.reg.b == 223);
    CHECK(cpu.reg.c == 241);
    CHECK(cpu.reg.d == 173);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 35);
    CHECK(cpu.reg.l == 218);
    CHECK(cpu.reg.pc == 63638);
    // CHECK(cpu.reg.sp == 15701);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63637] == 0);
}

TEST_CASE( "00 02B0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12151;
    cpu.reg.sp = 36502;
    cpu.reg.a = 47;
    cpu.reg.b = 140;
    cpu.reg.c = 89;
    cpu.reg.d = 225;
    cpu.reg.e = 171;
    cpu.reg.f = 144;
    cpu.reg.h = 17;
    cpu.reg.l = 129;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[12151] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 47);
    CHECK(cpu.reg.b == 140);
    CHECK(cpu.reg.c == 89);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 171);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 17);
    CHECK(cpu.reg.l == 129);
    CHECK(cpu.reg.pc == 12152);
    // CHECK(cpu.reg.sp == 36502);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12151] == 0);
}

TEST_CASE( "00 02B1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42830;
    cpu.reg.sp = 22115;
    cpu.reg.a = 78;
    cpu.reg.b = 126;
    cpu.reg.c = 196;
    cpu.reg.d = 76;
    cpu.reg.e = 98;
    cpu.reg.f = 192;
    cpu.reg.h = 19;
    cpu.reg.l = 64;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[42830] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 126);
    CHECK(cpu.reg.c == 196);
    CHECK(cpu.reg.d == 76);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 19);
    CHECK(cpu.reg.l == 64);
    CHECK(cpu.reg.pc == 42831);
    // CHECK(cpu.reg.sp == 22115);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[42830] == 0);
}

TEST_CASE( "00 02B2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62479;
    cpu.reg.sp = 26243;
    cpu.reg.a = 36;
    cpu.reg.b = 184;
    cpu.reg.c = 138;
    cpu.reg.d = 110;
    cpu.reg.e = 170;
    cpu.reg.f = 96;
    cpu.reg.h = 0;
    cpu.reg.l = 42;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62479] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 36);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 110);
    CHECK(cpu.reg.e == 170);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 62480);
    // CHECK(cpu.reg.sp == 26243);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62479] == 0);
}

TEST_CASE( "00 02B3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44174;
    cpu.reg.sp = 41060;
    cpu.reg.a = 64;
    cpu.reg.b = 182;
    cpu.reg.c = 246;
    cpu.reg.d = 204;
    cpu.reg.e = 107;
    cpu.reg.f = 224;
    cpu.reg.h = 147;
    cpu.reg.l = 16;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44174] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 64);
    CHECK(cpu.reg.b == 182);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 204);
    CHECK(cpu.reg.e == 107);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 16);
    CHECK(cpu.reg.pc == 44175);
    // CHECK(cpu.reg.sp == 41060);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44174] == 0);
}

TEST_CASE( "00 02B4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36000;
    cpu.reg.sp = 24489;
    cpu.reg.a = 145;
    cpu.reg.b = 192;
    cpu.reg.c = 193;
    cpu.reg.d = 53;
    cpu.reg.e = 191;
    cpu.reg.f = 0;
    cpu.reg.h = 63;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[36000] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 145);
    CHECK(cpu.reg.b == 192);
    CHECK(cpu.reg.c == 193);
    CHECK(cpu.reg.d == 53);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 63);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 36001);
    // CHECK(cpu.reg.sp == 24489);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36000] == 0);
}

TEST_CASE( "00 02B5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56674;
    cpu.reg.sp = 31509;
    cpu.reg.a = 128;
    cpu.reg.b = 108;
    cpu.reg.c = 211;
    cpu.reg.d = 79;
    cpu.reg.e = 183;
    cpu.reg.f = 96;
    cpu.reg.h = 250;
    cpu.reg.l = 106;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56674] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 128);
    CHECK(cpu.reg.b == 108);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 250);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 56675);
    // CHECK(cpu.reg.sp == 31509);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56674] == 0);
}

TEST_CASE( "00 02B6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54159;
    cpu.reg.sp = 59050;
    cpu.reg.a = 214;
    cpu.reg.b = 14;
    cpu.reg.c = 158;
    cpu.reg.d = 183;
    cpu.reg.e = 180;
    cpu.reg.f = 16;
    cpu.reg.h = 161;
    cpu.reg.l = 240;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54159] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 214);
    CHECK(cpu.reg.b == 14);
    CHECK(cpu.reg.c == 158);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 180);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 54160);
    // CHECK(cpu.reg.sp == 59050);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54159] == 0);
}

TEST_CASE( "00 02B7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17302;
    cpu.reg.sp = 32025;
    cpu.reg.a = 214;
    cpu.reg.b = 88;
    cpu.reg.c = 53;
    cpu.reg.d = 6;
    cpu.reg.e = 227;
    cpu.reg.f = 160;
    cpu.reg.h = 63;
    cpu.reg.l = 222;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[17302] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 214);
    CHECK(cpu.reg.b == 88);
    CHECK(cpu.reg.c == 53);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 227);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 63);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 17303);
    // CHECK(cpu.reg.sp == 32025);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[17302] == 0);
}

TEST_CASE( "00 02B8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28555;
    cpu.reg.sp = 46283;
    cpu.reg.a = 234;
    cpu.reg.b = 116;
    cpu.reg.c = 211;
    cpu.reg.d = 200;
    cpu.reg.e = 45;
    cpu.reg.f = 224;
    cpu.reg.h = 105;
    cpu.reg.l = 192;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[28555] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 234);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 45);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 105);
    CHECK(cpu.reg.l == 192);
    CHECK(cpu.reg.pc == 28556);
    // CHECK(cpu.reg.sp == 46283);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[28555] == 0);
}

TEST_CASE( "00 02B9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2357;
    cpu.reg.sp = 48192;
    cpu.reg.a = 94;
    cpu.reg.b = 106;
    cpu.reg.c = 126;
    cpu.reg.d = 229;
    cpu.reg.e = 20;
    cpu.reg.f = 32;
    cpu.reg.h = 65;
    cpu.reg.l = 120;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[2357] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 126);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 20);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 65);
    CHECK(cpu.reg.l == 120);
    CHECK(cpu.reg.pc == 2358);
    // CHECK(cpu.reg.sp == 48192);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[2357] == 0);
}

TEST_CASE( "00 02BA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52187;
    cpu.reg.sp = 944;
    cpu.reg.a = 179;
    cpu.reg.b = 16;
    cpu.reg.c = 243;
    cpu.reg.d = 151;
    cpu.reg.e = 97;
    cpu.reg.f = 80;
    cpu.reg.h = 119;
    cpu.reg.l = 132;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[52187] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 179);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 151);
    CHECK(cpu.reg.e == 97);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 119);
    CHECK(cpu.reg.l == 132);
    CHECK(cpu.reg.pc == 52188);
    // CHECK(cpu.reg.sp == 944);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52187] == 0);
}

TEST_CASE( "00 02BB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48527;
    cpu.reg.sp = 16311;
    cpu.reg.a = 50;
    cpu.reg.b = 103;
    cpu.reg.c = 140;
    cpu.reg.d = 163;
    cpu.reg.e = 211;
    cpu.reg.f = 160;
    cpu.reg.h = 170;
    cpu.reg.l = 44;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[48527] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 50);
    CHECK(cpu.reg.b == 103);
    CHECK(cpu.reg.c == 140);
    CHECK(cpu.reg.d == 163);
    CHECK(cpu.reg.e == 211);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 44);
    CHECK(cpu.reg.pc == 48528);
    // CHECK(cpu.reg.sp == 16311);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48527] == 0);
}

TEST_CASE( "00 02BC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57846;
    cpu.reg.sp = 35050;
    cpu.reg.a = 83;
    cpu.reg.b = 18;
    cpu.reg.c = 185;
    cpu.reg.d = 134;
    cpu.reg.e = 60;
    cpu.reg.f = 0;
    cpu.reg.h = 91;
    cpu.reg.l = 199;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[57846] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 83);
    CHECK(cpu.reg.b == 18);
    CHECK(cpu.reg.c == 185);
    CHECK(cpu.reg.d == 134);
    CHECK(cpu.reg.e == 60);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 91);
    CHECK(cpu.reg.l == 199);
    CHECK(cpu.reg.pc == 57847);
    // CHECK(cpu.reg.sp == 35050);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57846] == 0);
}

TEST_CASE( "00 02BD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48385;
    cpu.reg.sp = 48219;
    cpu.reg.a = 224;
    cpu.reg.b = 133;
    cpu.reg.c = 54;
    cpu.reg.d = 185;
    cpu.reg.e = 199;
    cpu.reg.f = 176;
    cpu.reg.h = 183;
    cpu.reg.l = 123;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48385] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 224);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 54);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 183);
    CHECK(cpu.reg.l == 123);
    CHECK(cpu.reg.pc == 48386);
    // CHECK(cpu.reg.sp == 48219);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48385] == 0);
}

TEST_CASE( "00 02BE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7065;
    cpu.reg.sp = 25416;
    cpu.reg.a = 91;
    cpu.reg.b = 254;
    cpu.reg.c = 252;
    cpu.reg.d = 177;
    cpu.reg.e = 156;
    cpu.reg.f = 112;
    cpu.reg.h = 160;
    cpu.reg.l = 192;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[7065] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 91);
    CHECK(cpu.reg.b == 254);
    CHECK(cpu.reg.c == 252);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 156);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 192);
    CHECK(cpu.reg.pc == 7066);
    // CHECK(cpu.reg.sp == 25416);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7065] == 0);
}

TEST_CASE( "00 02BF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4434;
    cpu.reg.sp = 9957;
    cpu.reg.a = 52;
    cpu.reg.b = 55;
    cpu.reg.c = 157;
    cpu.reg.d = 176;
    cpu.reg.e = 145;
    cpu.reg.f = 32;
    cpu.reg.h = 178;
    cpu.reg.l = 191;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[4434] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 52);
    CHECK(cpu.reg.b == 55);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 176);
    CHECK(cpu.reg.e == 145);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 191);
    CHECK(cpu.reg.pc == 4435);
    // CHECK(cpu.reg.sp == 9957);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[4434] == 0);
}

TEST_CASE( "00 02C0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58555;
    cpu.reg.sp = 65392;
    cpu.reg.a = 94;
    cpu.reg.b = 68;
    cpu.reg.c = 179;
    cpu.reg.d = 248;
    cpu.reg.e = 26;
    cpu.reg.f = 32;
    cpu.reg.h = 142;
    cpu.reg.l = 9;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[58555] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 94);
    CHECK(cpu.reg.b == 68);
    CHECK(cpu.reg.c == 179);
    CHECK(cpu.reg.d == 248);
    CHECK(cpu.reg.e == 26);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 142);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 58556);
    // CHECK(cpu.reg.sp == 65392);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58555] == 0);
}

TEST_CASE( "00 02C1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28441;
    cpu.reg.sp = 34140;
    cpu.reg.a = 63;
    cpu.reg.b = 170;
    cpu.reg.c = 93;
    cpu.reg.d = 233;
    cpu.reg.e = 170;
    cpu.reg.f = 112;
    cpu.reg.h = 212;
    cpu.reg.l = 171;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28441] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 170);
    CHECK(cpu.reg.c == 93);
    CHECK(cpu.reg.d == 233);
    CHECK(cpu.reg.e == 170);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 212);
    CHECK(cpu.reg.l == 171);
    CHECK(cpu.reg.pc == 28442);
    // CHECK(cpu.reg.sp == 34140);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28441] == 0);
}

TEST_CASE( "00 02C2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16530;
    cpu.reg.sp = 41911;
    cpu.reg.a = 81;
    cpu.reg.b = 154;
    cpu.reg.c = 46;
    cpu.reg.d = 53;
    cpu.reg.e = 11;
    cpu.reg.f = 192;
    cpu.reg.h = 113;
    cpu.reg.l = 80;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[16530] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 154);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 53);
    CHECK(cpu.reg.e == 11);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 113);
    CHECK(cpu.reg.l == 80);
    CHECK(cpu.reg.pc == 16531);
    // CHECK(cpu.reg.sp == 41911);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16530] == 0);
}

TEST_CASE( "00 02C3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12364;
    cpu.reg.sp = 30083;
    cpu.reg.a = 183;
    cpu.reg.b = 145;
    cpu.reg.c = 223;
    cpu.reg.d = 203;
    cpu.reg.e = 50;
    cpu.reg.f = 224;
    cpu.reg.h = 207;
    cpu.reg.l = 24;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[12364] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 145);
    CHECK(cpu.reg.c == 223);
    CHECK(cpu.reg.d == 203);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 207);
    CHECK(cpu.reg.l == 24);
    CHECK(cpu.reg.pc == 12365);
    // CHECK(cpu.reg.sp == 30083);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12364] == 0);
}

TEST_CASE( "00 02C4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40878;
    cpu.reg.sp = 60390;
    cpu.reg.a = 73;
    cpu.reg.b = 194;
    cpu.reg.c = 154;
    cpu.reg.d = 60;
    cpu.reg.e = 216;
    cpu.reg.f = 144;
    cpu.reg.h = 30;
    cpu.reg.l = 250;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[40878] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 73);
    CHECK(cpu.reg.b == 194);
    CHECK(cpu.reg.c == 154);
    CHECK(cpu.reg.d == 60);
    CHECK(cpu.reg.e == 216);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 30);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 40879);
    // CHECK(cpu.reg.sp == 60390);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40878] == 0);
}

TEST_CASE( "00 02C5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30300;
    cpu.reg.sp = 51029;
    cpu.reg.a = 164;
    cpu.reg.b = 112;
    cpu.reg.c = 225;
    cpu.reg.d = 163;
    cpu.reg.e = 180;
    cpu.reg.f = 224;
    cpu.reg.h = 230;
    cpu.reg.l = 20;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[30300] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 112);
    CHECK(cpu.reg.c == 225);
    CHECK(cpu.reg.d == 163);
    CHECK(cpu.reg.e == 180);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 230);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 30301);
    // CHECK(cpu.reg.sp == 51029);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30300] == 0);
}

TEST_CASE( "00 02C6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27690;
    cpu.reg.sp = 22386;
    cpu.reg.a = 38;
    cpu.reg.b = 123;
    cpu.reg.c = 199;
    cpu.reg.d = 178;
    cpu.reg.e = 138;
    cpu.reg.f = 16;
    cpu.reg.h = 24;
    cpu.reg.l = 94;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[27690] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 38);
    CHECK(cpu.reg.b == 123);
    CHECK(cpu.reg.c == 199);
    CHECK(cpu.reg.d == 178);
    CHECK(cpu.reg.e == 138);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 94);
    CHECK(cpu.reg.pc == 27691);
    // CHECK(cpu.reg.sp == 22386);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[27690] == 0);
}

TEST_CASE( "00 02C7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32362;
    cpu.reg.sp = 3218;
    cpu.reg.a = 242;
    cpu.reg.b = 173;
    cpu.reg.c = 59;
    cpu.reg.d = 19;
    cpu.reg.e = 139;
    cpu.reg.f = 32;
    cpu.reg.h = 132;
    cpu.reg.l = 205;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32362] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 242);
    CHECK(cpu.reg.b == 173);
    CHECK(cpu.reg.c == 59);
    CHECK(cpu.reg.d == 19);
    CHECK(cpu.reg.e == 139);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 132);
    CHECK(cpu.reg.l == 205);
    CHECK(cpu.reg.pc == 32363);
    // CHECK(cpu.reg.sp == 3218);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32362] == 0);
}

TEST_CASE( "00 02C8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46433;
    cpu.reg.sp = 53803;
    cpu.reg.a = 210;
    cpu.reg.b = 119;
    cpu.reg.c = 183;
    cpu.reg.d = 69;
    cpu.reg.e = 187;
    cpu.reg.f = 224;
    cpu.reg.h = 4;
    cpu.reg.l = 24;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46433] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 69);
    CHECK(cpu.reg.e == 187);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 4);
    CHECK(cpu.reg.l == 24);
    CHECK(cpu.reg.pc == 46434);
    // CHECK(cpu.reg.sp == 53803);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46433] == 0);
}

TEST_CASE( "00 02C9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60829;
    cpu.reg.sp = 34833;
    cpu.reg.a = 230;
    cpu.reg.b = 239;
    cpu.reg.c = 157;
    cpu.reg.d = 132;
    cpu.reg.e = 140;
    cpu.reg.f = 176;
    cpu.reg.h = 140;
    cpu.reg.l = 92;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[60829] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 230);
    CHECK(cpu.reg.b == 239);
    CHECK(cpu.reg.c == 157);
    CHECK(cpu.reg.d == 132);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 92);
    CHECK(cpu.reg.pc == 60830);
    // CHECK(cpu.reg.sp == 34833);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[60829] == 0);
}

TEST_CASE( "00 02CA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29545;
    cpu.reg.sp = 18346;
    cpu.reg.a = 61;
    cpu.reg.b = 205;
    cpu.reg.c = 12;
    cpu.reg.d = 230;
    cpu.reg.e = 159;
    cpu.reg.f = 144;
    cpu.reg.h = 119;
    cpu.reg.l = 236;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29545] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 61);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 119);
    CHECK(cpu.reg.l == 236);
    CHECK(cpu.reg.pc == 29546);
    // CHECK(cpu.reg.sp == 18346);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29545] == 0);
}

TEST_CASE( "00 02CB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11925;
    cpu.reg.sp = 21266;
    cpu.reg.a = 135;
    cpu.reg.b = 27;
    cpu.reg.c = 240;
    cpu.reg.d = 133;
    cpu.reg.e = 223;
    cpu.reg.f = 144;
    cpu.reg.h = 170;
    cpu.reg.l = 89;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[11925] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 135);
    CHECK(cpu.reg.b == 27);
    CHECK(cpu.reg.c == 240);
    CHECK(cpu.reg.d == 133);
    CHECK(cpu.reg.e == 223);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 89);
    CHECK(cpu.reg.pc == 11926);
    // CHECK(cpu.reg.sp == 21266);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11925] == 0);
}

TEST_CASE( "00 02CC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54058;
    cpu.reg.sp = 51464;
    cpu.reg.a = 164;
    cpu.reg.b = 220;
    cpu.reg.c = 72;
    cpu.reg.d = 111;
    cpu.reg.e = 7;
    cpu.reg.f = 224;
    cpu.reg.h = 50;
    cpu.reg.l = 163;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54058] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 111);
    CHECK(cpu.reg.e == 7);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 50);
    CHECK(cpu.reg.l == 163);
    CHECK(cpu.reg.pc == 54059);
    // CHECK(cpu.reg.sp == 51464);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54058] == 0);
}

TEST_CASE( "00 02CD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10147;
    cpu.reg.sp = 38299;
    cpu.reg.a = 13;
    cpu.reg.b = 150;
    cpu.reg.c = 98;
    cpu.reg.d = 176;
    cpu.reg.e = 72;
    cpu.reg.f = 0;
    cpu.reg.h = 240;
    cpu.reg.l = 72;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[10147] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 13);
    CHECK(cpu.reg.b == 150);
    CHECK(cpu.reg.c == 98);
    CHECK(cpu.reg.d == 176);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 240);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 10148);
    // CHECK(cpu.reg.sp == 38299);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10147] == 0);
}

TEST_CASE( "00 02CE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47943;
    cpu.reg.sp = 721;
    cpu.reg.a = 242;
    cpu.reg.b = 100;
    cpu.reg.c = 91;
    cpu.reg.d = 67;
    cpu.reg.e = 26;
    cpu.reg.f = 240;
    cpu.reg.h = 88;
    cpu.reg.l = 106;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[47943] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 242);
    CHECK(cpu.reg.b == 100);
    CHECK(cpu.reg.c == 91);
    CHECK(cpu.reg.d == 67);
    CHECK(cpu.reg.e == 26);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 88);
    CHECK(cpu.reg.l == 106);
    CHECK(cpu.reg.pc == 47944);
    // CHECK(cpu.reg.sp == 721);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[47943] == 0);
}

TEST_CASE( "00 02CF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61857;
    cpu.reg.sp = 57991;
    cpu.reg.a = 210;
    cpu.reg.b = 95;
    cpu.reg.c = 195;
    cpu.reg.d = 98;
    cpu.reg.e = 205;
    cpu.reg.f = 192;
    cpu.reg.h = 83;
    cpu.reg.l = 105;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[61857] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 195);
    CHECK(cpu.reg.d == 98);
    CHECK(cpu.reg.e == 205);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 83);
    CHECK(cpu.reg.l == 105);
    CHECK(cpu.reg.pc == 61858);
    // CHECK(cpu.reg.sp == 57991);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[61857] == 0);
}

TEST_CASE( "00 02D0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14523;
    cpu.reg.sp = 65259;
    cpu.reg.a = 52;
    cpu.reg.b = 148;
    cpu.reg.c = 244;
    cpu.reg.d = 92;
    cpu.reg.e = 0;
    cpu.reg.f = 16;
    cpu.reg.h = 103;
    cpu.reg.l = 9;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[14523] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 52);
    CHECK(cpu.reg.b == 148);
    CHECK(cpu.reg.c == 244);
    CHECK(cpu.reg.d == 92);
    CHECK(cpu.reg.e == 0);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 103);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 14524);
    // CHECK(cpu.reg.sp == 65259);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[14523] == 0);
}

TEST_CASE( "00 02D1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6619;
    cpu.reg.sp = 55347;
    cpu.reg.a = 218;
    cpu.reg.b = 8;
    cpu.reg.c = 246;
    cpu.reg.d = 71;
    cpu.reg.e = 234;
    cpu.reg.f = 112;
    cpu.reg.h = 24;
    cpu.reg.l = 127;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[6619] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 8);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 71);
    CHECK(cpu.reg.e == 234);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 127);
    CHECK(cpu.reg.pc == 6620);
    // CHECK(cpu.reg.sp == 55347);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[6619] == 0);
}

TEST_CASE( "00 02D2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29479;
    cpu.reg.sp = 51625;
    cpu.reg.a = 71;
    cpu.reg.b = 162;
    cpu.reg.c = 243;
    cpu.reg.d = 229;
    cpu.reg.e = 6;
    cpu.reg.f = 16;
    cpu.reg.h = 120;
    cpu.reg.l = 56;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29479] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 71);
    CHECK(cpu.reg.b == 162);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 29480);
    // CHECK(cpu.reg.sp == 51625);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29479] == 0);
}

TEST_CASE( "00 02D3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19719;
    cpu.reg.sp = 31854;
    cpu.reg.a = 251;
    cpu.reg.b = 4;
    cpu.reg.c = 107;
    cpu.reg.d = 23;
    cpu.reg.e = 6;
    cpu.reg.f = 96;
    cpu.reg.h = 210;
    cpu.reg.l = 138;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19719] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 251);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 210);
    CHECK(cpu.reg.l == 138);
    CHECK(cpu.reg.pc == 19720);
    // CHECK(cpu.reg.sp == 31854);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19719] == 0);
}

TEST_CASE( "00 02D4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34594;
    cpu.reg.sp = 25855;
    cpu.reg.a = 2;
    cpu.reg.b = 41;
    cpu.reg.c = 8;
    cpu.reg.d = 153;
    cpu.reg.e = 181;
    cpu.reg.f = 240;
    cpu.reg.h = 227;
    cpu.reg.l = 139;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[34594] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 41);
    CHECK(cpu.reg.c == 8);
    CHECK(cpu.reg.d == 153);
    CHECK(cpu.reg.e == 181);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 227);
    CHECK(cpu.reg.l == 139);
    CHECK(cpu.reg.pc == 34595);
    // CHECK(cpu.reg.sp == 25855);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34594] == 0);
}

TEST_CASE( "00 02D5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51872;
    cpu.reg.sp = 47282;
    cpu.reg.a = 122;
    cpu.reg.b = 231;
    cpu.reg.c = 138;
    cpu.reg.d = 114;
    cpu.reg.e = 203;
    cpu.reg.f = 192;
    cpu.reg.h = 14;
    cpu.reg.l = 189;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[51872] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 122);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 114);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 14);
    CHECK(cpu.reg.l == 189);
    CHECK(cpu.reg.pc == 51873);
    // CHECK(cpu.reg.sp == 47282);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[51872] == 0);
}

TEST_CASE( "00 02D6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 14543;
    cpu.reg.sp = 18829;
    cpu.reg.a = 222;
    cpu.reg.b = 81;
    cpu.reg.c = 132;
    cpu.reg.d = 165;
    cpu.reg.e = 188;
    cpu.reg.f = 240;
    cpu.reg.h = 95;
    cpu.reg.l = 37;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[14543] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 222);
    CHECK(cpu.reg.b == 81);
    CHECK(cpu.reg.c == 132);
    CHECK(cpu.reg.d == 165);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 95);
    CHECK(cpu.reg.l == 37);
    CHECK(cpu.reg.pc == 14544);
    // CHECK(cpu.reg.sp == 18829);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[14543] == 0);
}

TEST_CASE( "00 02D7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36400;
    cpu.reg.sp = 22226;
    cpu.reg.a = 126;
    cpu.reg.b = 155;
    cpu.reg.c = 118;
    cpu.reg.d = 230;
    cpu.reg.e = 76;
    cpu.reg.f = 112;
    cpu.reg.h = 208;
    cpu.reg.l = 182;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[36400] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 126);
    CHECK(cpu.reg.b == 155);
    CHECK(cpu.reg.c == 118);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 76);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 208);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 36401);
    // CHECK(cpu.reg.sp == 22226);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36400] == 0);
}

TEST_CASE( "00 02D8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57007;
    cpu.reg.sp = 22165;
    cpu.reg.a = 95;
    cpu.reg.b = 81;
    cpu.reg.c = 112;
    cpu.reg.d = 199;
    cpu.reg.e = 123;
    cpu.reg.f = 48;
    cpu.reg.h = 108;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[57007] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 95);
    CHECK(cpu.reg.b == 81);
    CHECK(cpu.reg.c == 112);
    CHECK(cpu.reg.d == 199);
    CHECK(cpu.reg.e == 123);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 108);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 57008);
    // CHECK(cpu.reg.sp == 22165);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[57007] == 0);
}

TEST_CASE( "00 02D9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17418;
    cpu.reg.sp = 40392;
    cpu.reg.a = 187;
    cpu.reg.b = 7;
    cpu.reg.c = 85;
    cpu.reg.d = 68;
    cpu.reg.e = 43;
    cpu.reg.f = 64;
    cpu.reg.h = 31;
    cpu.reg.l = 204;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[17418] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 187);
    CHECK(cpu.reg.b == 7);
    CHECK(cpu.reg.c == 85);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 31);
    CHECK(cpu.reg.l == 204);
    CHECK(cpu.reg.pc == 17419);
    // CHECK(cpu.reg.sp == 40392);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[17418] == 0);
}

TEST_CASE( "00 02DA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26899;
    cpu.reg.sp = 57042;
    cpu.reg.a = 205;
    cpu.reg.b = 226;
    cpu.reg.c = 5;
    cpu.reg.d = 6;
    cpu.reg.e = 134;
    cpu.reg.f = 160;
    cpu.reg.h = 193;
    cpu.reg.l = 122;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[26899] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 205);
    CHECK(cpu.reg.b == 226);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 134);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 193);
    CHECK(cpu.reg.l == 122);
    CHECK(cpu.reg.pc == 26900);
    // CHECK(cpu.reg.sp == 57042);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26899] == 0);
}

TEST_CASE( "00 02DB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35656;
    cpu.reg.sp = 3586;
    cpu.reg.a = 111;
    cpu.reg.b = 97;
    cpu.reg.c = 178;
    cpu.reg.d = 65;
    cpu.reg.e = 67;
    cpu.reg.f = 112;
    cpu.reg.h = 209;
    cpu.reg.l = 187;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[35656] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 111);
    CHECK(cpu.reg.b == 97);
    CHECK(cpu.reg.c == 178);
    CHECK(cpu.reg.d == 65);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 209);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 35657);
    // CHECK(cpu.reg.sp == 3586);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35656] == 0);
}

TEST_CASE( "00 02DC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13967;
    cpu.reg.sp = 25528;
    cpu.reg.a = 12;
    cpu.reg.b = 122;
    cpu.reg.c = 83;
    cpu.reg.d = 27;
    cpu.reg.e = 189;
    cpu.reg.f = 48;
    cpu.reg.h = 186;
    cpu.reg.l = 54;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[13967] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 12);
    CHECK(cpu.reg.b == 122);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 27);
    CHECK(cpu.reg.e == 189);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 54);
    CHECK(cpu.reg.pc == 13968);
    // CHECK(cpu.reg.sp == 25528);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[13967] == 0);
}

TEST_CASE( "00 02DD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9723;
    cpu.reg.sp = 41032;
    cpu.reg.a = 179;
    cpu.reg.b = 121;
    cpu.reg.c = 64;
    cpu.reg.d = 98;
    cpu.reg.e = 244;
    cpu.reg.f = 64;
    cpu.reg.h = 131;
    cpu.reg.l = 187;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9723] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 179);
    CHECK(cpu.reg.b == 121);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 98);
    CHECK(cpu.reg.e == 244);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 131);
    CHECK(cpu.reg.l == 187);
    CHECK(cpu.reg.pc == 9724);
    // CHECK(cpu.reg.sp == 41032);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9723] == 0);
}

TEST_CASE( "00 02DE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42987;
    cpu.reg.sp = 2356;
    cpu.reg.a = 99;
    cpu.reg.b = 158;
    cpu.reg.c = 174;
    cpu.reg.d = 246;
    cpu.reg.e = 124;
    cpu.reg.f = 16;
    cpu.reg.h = 243;
    cpu.reg.l = 233;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[42987] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 158);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 42988);
    // CHECK(cpu.reg.sp == 2356);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42987] == 0);
}

TEST_CASE( "00 02DF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15268;
    cpu.reg.sp = 63073;
    cpu.reg.a = 147;
    cpu.reg.b = 182;
    cpu.reg.c = 211;
    cpu.reg.d = 43;
    cpu.reg.e = 5;
    cpu.reg.f = 192;
    cpu.reg.h = 55;
    cpu.reg.l = 142;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15268] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 147);
    CHECK(cpu.reg.b == 182);
    CHECK(cpu.reg.c == 211);
    CHECK(cpu.reg.d == 43);
    CHECK(cpu.reg.e == 5);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 55);
    CHECK(cpu.reg.l == 142);
    CHECK(cpu.reg.pc == 15269);
    // CHECK(cpu.reg.sp == 63073);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15268] == 0);
}

TEST_CASE( "00 02E0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45433;
    cpu.reg.sp = 30718;
    cpu.reg.a = 112;
    cpu.reg.b = 107;
    cpu.reg.c = 120;
    cpu.reg.d = 171;
    cpu.reg.e = 85;
    cpu.reg.f = 208;
    cpu.reg.h = 0;
    cpu.reg.l = 59;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[45433] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 112);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 171);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 45434);
    // CHECK(cpu.reg.sp == 30718);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[45433] == 0);
}

TEST_CASE( "00 02E1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48749;
    cpu.reg.sp = 43286;
    cpu.reg.a = 115;
    cpu.reg.b = 167;
    cpu.reg.c = 23;
    cpu.reg.d = 194;
    cpu.reg.e = 41;
    cpu.reg.f = 176;
    cpu.reg.h = 56;
    cpu.reg.l = 87;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48749] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 115);
    CHECK(cpu.reg.b == 167);
    CHECK(cpu.reg.c == 23);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 41);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 56);
    CHECK(cpu.reg.l == 87);
    CHECK(cpu.reg.pc == 48750);
    // CHECK(cpu.reg.sp == 43286);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48749] == 0);
}

TEST_CASE( "00 02E2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 42142;
    cpu.reg.sp = 62480;
    cpu.reg.a = 99;
    cpu.reg.b = 140;
    cpu.reg.c = 91;
    cpu.reg.d = 20;
    cpu.reg.e = 115;
    cpu.reg.f = 0;
    cpu.reg.h = 44;
    cpu.reg.l = 240;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[42142] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 140);
    CHECK(cpu.reg.c == 91);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 115);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 44);
    CHECK(cpu.reg.l == 240);
    CHECK(cpu.reg.pc == 42143);
    // CHECK(cpu.reg.sp == 62480);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[42142] == 0);
}

TEST_CASE( "00 02E3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3429;
    cpu.reg.sp = 24313;
    cpu.reg.a = 246;
    cpu.reg.b = 174;
    cpu.reg.c = 174;
    cpu.reg.d = 179;
    cpu.reg.e = 202;
    cpu.reg.f = 32;
    cpu.reg.h = 48;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[3429] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 246);
    CHECK(cpu.reg.b == 174);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 179);
    CHECK(cpu.reg.e == 202);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 48);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 3430);
    // CHECK(cpu.reg.sp == 24313);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3429] == 0);
}

TEST_CASE( "00 02E4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38805;
    cpu.reg.sp = 40016;
    cpu.reg.a = 160;
    cpu.reg.b = 112;
    cpu.reg.c = 2;
    cpu.reg.d = 23;
    cpu.reg.e = 51;
    cpu.reg.f = 32;
    cpu.reg.h = 101;
    cpu.reg.l = 200;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[38805] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 160);
    CHECK(cpu.reg.b == 112);
    CHECK(cpu.reg.c == 2);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 51);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 101);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 38806);
    // CHECK(cpu.reg.sp == 40016);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38805] == 0);
}

TEST_CASE( "00 02E5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18936;
    cpu.reg.sp = 27619;
    cpu.reg.a = 153;
    cpu.reg.b = 87;
    cpu.reg.c = 177;
    cpu.reg.d = 60;
    cpu.reg.e = 173;
    cpu.reg.f = 80;
    cpu.reg.h = 147;
    cpu.reg.l = 84;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[18936] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 177);
    CHECK(cpu.reg.d == 60);
    CHECK(cpu.reg.e == 173);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 18937);
    // CHECK(cpu.reg.sp == 27619);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[18936] == 0);
}

TEST_CASE( "00 02E6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54661;
    cpu.reg.sp = 10729;
    cpu.reg.a = 197;
    cpu.reg.b = 175;
    cpu.reg.c = 156;
    cpu.reg.d = 10;
    cpu.reg.e = 162;
    cpu.reg.f = 208;
    cpu.reg.h = 242;
    cpu.reg.l = 5;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54661] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 156);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 162);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 242);
    CHECK(cpu.reg.l == 5);
    CHECK(cpu.reg.pc == 54662);
    // CHECK(cpu.reg.sp == 10729);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54661] == 0);
}

TEST_CASE( "00 02E7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55977;
    cpu.reg.sp = 65135;
    cpu.reg.a = 164;
    cpu.reg.b = 90;
    cpu.reg.c = 57;
    cpu.reg.d = 226;
    cpu.reg.e = 203;
    cpu.reg.f = 16;
    cpu.reg.h = 223;
    cpu.reg.l = 197;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[55977] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 90);
    CHECK(cpu.reg.c == 57);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 223);
    CHECK(cpu.reg.l == 197);
    CHECK(cpu.reg.pc == 55978);
    // CHECK(cpu.reg.sp == 65135);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[55977] == 0);
}

TEST_CASE( "00 02E8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60911;
    cpu.reg.sp = 37764;
    cpu.reg.a = 48;
    cpu.reg.b = 231;
    cpu.reg.c = 58;
    cpu.reg.d = 3;
    cpu.reg.e = 146;
    cpu.reg.f = 128;
    cpu.reg.h = 76;
    cpu.reg.l = 26;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60911] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 58);
    CHECK(cpu.reg.d == 3);
    CHECK(cpu.reg.e == 146);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 76);
    CHECK(cpu.reg.l == 26);
    CHECK(cpu.reg.pc == 60912);
    // CHECK(cpu.reg.sp == 37764);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60911] == 0);
}

TEST_CASE( "00 02E9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49397;
    cpu.reg.sp = 23156;
    cpu.reg.a = 60;
    cpu.reg.b = 35;
    cpu.reg.c = 60;
    cpu.reg.d = 184;
    cpu.reg.e = 116;
    cpu.reg.f = 176;
    cpu.reg.h = 154;
    cpu.reg.l = 153;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49397] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 60);
    CHECK(cpu.reg.b == 35);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 116);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 49398);
    // CHECK(cpu.reg.sp == 23156);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49397] == 0);
}

TEST_CASE( "00 02EA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52585;
    cpu.reg.sp = 62646;
    cpu.reg.a = 63;
    cpu.reg.b = 74;
    cpu.reg.c = 83;
    cpu.reg.d = 217;
    cpu.reg.e = 200;
    cpu.reg.f = 112;
    cpu.reg.h = 164;
    cpu.reg.l = 12;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[52585] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 74);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 217);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 12);
    CHECK(cpu.reg.pc == 52586);
    // CHECK(cpu.reg.sp == 62646);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52585] == 0);
}

TEST_CASE( "00 02EB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34587;
    cpu.reg.sp = 23662;
    cpu.reg.a = 176;
    cpu.reg.b = 13;
    cpu.reg.c = 111;
    cpu.reg.d = 20;
    cpu.reg.e = 107;
    cpu.reg.f = 16;
    cpu.reg.h = 47;
    cpu.reg.l = 248;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34587] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 176);
    CHECK(cpu.reg.b == 13);
    CHECK(cpu.reg.c == 111);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 107);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 47);
    CHECK(cpu.reg.l == 248);
    CHECK(cpu.reg.pc == 34588);
    // CHECK(cpu.reg.sp == 23662);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34587] == 0);
}

TEST_CASE( "00 02EC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9668;
    cpu.reg.sp = 44052;
    cpu.reg.a = 208;
    cpu.reg.b = 205;
    cpu.reg.c = 91;
    cpu.reg.d = 116;
    cpu.reg.e = 82;
    cpu.reg.f = 240;
    cpu.reg.h = 93;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[9668] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 91);
    CHECK(cpu.reg.d == 116);
    CHECK(cpu.reg.e == 82);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 93);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 9669);
    // CHECK(cpu.reg.sp == 44052);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9668] == 0);
}

TEST_CASE( "00 02ED", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29301;
    cpu.reg.sp = 20932;
    cpu.reg.a = 48;
    cpu.reg.b = 52;
    cpu.reg.c = 235;
    cpu.reg.d = 144;
    cpu.reg.e = 240;
    cpu.reg.f = 80;
    cpu.reg.h = 75;
    cpu.reg.l = 68;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[29301] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 52);
    CHECK(cpu.reg.c == 235);
    CHECK(cpu.reg.d == 144);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 68);
    CHECK(cpu.reg.pc == 29302);
    // CHECK(cpu.reg.sp == 20932);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29301] == 0);
}

TEST_CASE( "00 02EE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10554;
    cpu.reg.sp = 12108;
    cpu.reg.a = 106;
    cpu.reg.b = 184;
    cpu.reg.c = 4;
    cpu.reg.d = 237;
    cpu.reg.e = 228;
    cpu.reg.f = 192;
    cpu.reg.h = 130;
    cpu.reg.l = 11;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10554] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 106);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 4);
    CHECK(cpu.reg.d == 237);
    CHECK(cpu.reg.e == 228);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 130);
    CHECK(cpu.reg.l == 11);
    CHECK(cpu.reg.pc == 10555);
    // CHECK(cpu.reg.sp == 12108);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10554] == 0);
}

TEST_CASE( "00 02EF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27648;
    cpu.reg.sp = 64391;
    cpu.reg.a = 212;
    cpu.reg.b = 68;
    cpu.reg.c = 188;
    cpu.reg.d = 126;
    cpu.reg.e = 98;
    cpu.reg.f = 144;
    cpu.reg.h = 66;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[27648] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 68);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 66);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 27649);
    // CHECK(cpu.reg.sp == 64391);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[27648] == 0);
}

TEST_CASE( "00 02F0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17494;
    cpu.reg.sp = 30266;
    cpu.reg.a = 246;
    cpu.reg.b = 130;
    cpu.reg.c = 133;
    cpu.reg.d = 75;
    cpu.reg.e = 245;
    cpu.reg.f = 16;
    cpu.reg.h = 132;
    cpu.reg.l = 112;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[17494] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 246);
    CHECK(cpu.reg.b == 130);
    CHECK(cpu.reg.c == 133);
    CHECK(cpu.reg.d == 75);
    CHECK(cpu.reg.e == 245);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 132);
    CHECK(cpu.reg.l == 112);
    CHECK(cpu.reg.pc == 17495);
    // CHECK(cpu.reg.sp == 30266);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[17494] == 0);
}

TEST_CASE( "00 02F1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32483;
    cpu.reg.sp = 19934;
    cpu.reg.a = 140;
    cpu.reg.b = 187;
    cpu.reg.c = 36;
    cpu.reg.d = 82;
    cpu.reg.e = 27;
    cpu.reg.f = 32;
    cpu.reg.h = 85;
    cpu.reg.l = 229;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32483] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 187);
    CHECK(cpu.reg.c == 36);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 85);
    CHECK(cpu.reg.l == 229);
    CHECK(cpu.reg.pc == 32484);
    // CHECK(cpu.reg.sp == 19934);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32483] == 0);
}

TEST_CASE( "00 02F2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 141;
    cpu.reg.sp = 29310;
    cpu.reg.a = 88;
    cpu.reg.b = 61;
    cpu.reg.c = 221;
    cpu.reg.d = 238;
    cpu.reg.e = 200;
    cpu.reg.f = 0;
    cpu.reg.h = 223;
    cpu.reg.l = 182;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[141] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 88);
    CHECK(cpu.reg.b == 61);
    CHECK(cpu.reg.c == 221);
    CHECK(cpu.reg.d == 238);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 223);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 142);
    // CHECK(cpu.reg.sp == 29310);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[141] == 0);
}

TEST_CASE( "00 02F3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26928;
    cpu.reg.sp = 24061;
    cpu.reg.a = 89;
    cpu.reg.b = 111;
    cpu.reg.c = 102;
    cpu.reg.d = 136;
    cpu.reg.e = 82;
    cpu.reg.f = 96;
    cpu.reg.h = 191;
    cpu.reg.l = 60;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26928] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 89);
    CHECK(cpu.reg.b == 111);
    CHECK(cpu.reg.c == 102);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 82);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 26929);
    // CHECK(cpu.reg.sp == 24061);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26928] == 0);
}

TEST_CASE( "00 02F4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40403;
    cpu.reg.sp = 61830;
    cpu.reg.a = 166;
    cpu.reg.b = 172;
    cpu.reg.c = 247;
    cpu.reg.d = 162;
    cpu.reg.e = 125;
    cpu.reg.f = 96;
    cpu.reg.h = 243;
    cpu.reg.l = 72;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[40403] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 166);
    CHECK(cpu.reg.b == 172);
    CHECK(cpu.reg.c == 247);
    CHECK(cpu.reg.d == 162);
    CHECK(cpu.reg.e == 125);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 72);
    CHECK(cpu.reg.pc == 40404);
    // CHECK(cpu.reg.sp == 61830);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40403] == 0);
}

TEST_CASE( "00 02F5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21492;
    cpu.reg.sp = 37872;
    cpu.reg.a = 46;
    cpu.reg.b = 124;
    cpu.reg.c = 98;
    cpu.reg.d = 187;
    cpu.reg.e = 3;
    cpu.reg.f = 192;
    cpu.reg.h = 136;
    cpu.reg.l = 77;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21492] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 46);
    CHECK(cpu.reg.b == 124);
    CHECK(cpu.reg.c == 98);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 77);
    CHECK(cpu.reg.pc == 21493);
    // CHECK(cpu.reg.sp == 37872);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21492] == 0);
}

TEST_CASE( "00 02F6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31610;
    cpu.reg.sp = 8533;
    cpu.reg.a = 84;
    cpu.reg.b = 105;
    cpu.reg.c = 238;
    cpu.reg.d = 191;
    cpu.reg.e = 134;
    cpu.reg.f = 128;
    cpu.reg.h = 48;
    cpu.reg.l = 197;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[31610] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 238);
    CHECK(cpu.reg.d == 191);
    CHECK(cpu.reg.e == 134);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 48);
    CHECK(cpu.reg.l == 197);
    CHECK(cpu.reg.pc == 31611);
    // CHECK(cpu.reg.sp == 8533);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31610] == 0);
}

TEST_CASE( "00 02F7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44335;
    cpu.reg.sp = 12227;
    cpu.reg.a = 22;
    cpu.reg.b = 222;
    cpu.reg.c = 75;
    cpu.reg.d = 187;
    cpu.reg.e = 94;
    cpu.reg.f = 80;
    cpu.reg.h = 28;
    cpu.reg.l = 84;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44335] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 22);
    CHECK(cpu.reg.b == 222);
    CHECK(cpu.reg.c == 75);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 94);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 28);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 44336);
    // CHECK(cpu.reg.sp == 12227);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44335] == 0);
}

TEST_CASE( "00 02F8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16415;
    cpu.reg.sp = 64682;
    cpu.reg.a = 6;
    cpu.reg.b = 44;
    cpu.reg.c = 95;
    cpu.reg.d = 104;
    cpu.reg.e = 210;
    cpu.reg.f = 224;
    cpu.reg.h = 149;
    cpu.reg.l = 202;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[16415] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 6);
    CHECK(cpu.reg.b == 44);
    CHECK(cpu.reg.c == 95);
    CHECK(cpu.reg.d == 104);
    CHECK(cpu.reg.e == 210);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 149);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 16416);
    // CHECK(cpu.reg.sp == 64682);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16415] == 0);
}

TEST_CASE( "00 02F9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 60146;
    cpu.reg.sp = 7880;
    cpu.reg.a = 244;
    cpu.reg.b = 119;
    cpu.reg.c = 83;
    cpu.reg.d = 197;
    cpu.reg.e = 118;
    cpu.reg.f = 80;
    cpu.reg.h = 156;
    cpu.reg.l = 128;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[60146] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 244);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 118);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 60147);
    // CHECK(cpu.reg.sp == 7880);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[60146] == 0);
}

TEST_CASE( "00 02FA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17361;
    cpu.reg.sp = 40768;
    cpu.reg.a = 61;
    cpu.reg.b = 83;
    cpu.reg.c = 114;
    cpu.reg.d = 27;
    cpu.reg.e = 99;
    cpu.reg.f = 208;
    cpu.reg.h = 17;
    cpu.reg.l = 253;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17361] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 61);
    CHECK(cpu.reg.b == 83);
    CHECK(cpu.reg.c == 114);
    CHECK(cpu.reg.d == 27);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 17);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 17362);
    // CHECK(cpu.reg.sp == 40768);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17361] == 0);
}

TEST_CASE( "00 02FB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 35024;
    cpu.reg.sp = 21166;
    cpu.reg.a = 27;
    cpu.reg.b = 105;
    cpu.reg.c = 5;
    cpu.reg.d = 98;
    cpu.reg.e = 190;
    cpu.reg.f = 64;
    cpu.reg.h = 82;
    cpu.reg.l = 200;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[35024] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 27);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 98);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 82);
    CHECK(cpu.reg.l == 200);
    CHECK(cpu.reg.pc == 35025);
    // CHECK(cpu.reg.sp == 21166);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[35024] == 0);
}

TEST_CASE( "00 02FC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1601;
    cpu.reg.sp = 1826;
    cpu.reg.a = 217;
    cpu.reg.b = 43;
    cpu.reg.c = 119;
    cpu.reg.d = 14;
    cpu.reg.e = 70;
    cpu.reg.f = 32;
    cpu.reg.h = 182;
    cpu.reg.l = 174;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[1601] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 217);
    CHECK(cpu.reg.b == 43);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 14);
    CHECK(cpu.reg.e == 70);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 174);
    CHECK(cpu.reg.pc == 1602);
    // CHECK(cpu.reg.sp == 1826);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1601] == 0);
}

TEST_CASE( "00 02FD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33790;
    cpu.reg.sp = 35272;
    cpu.reg.a = 206;
    cpu.reg.b = 15;
    cpu.reg.c = 64;
    cpu.reg.d = 117;
    cpu.reg.e = 199;
    cpu.reg.f = 240;
    cpu.reg.h = 39;
    cpu.reg.l = 90;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[33790] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 15);
    CHECK(cpu.reg.c == 64);
    CHECK(cpu.reg.d == 117);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 39);
    CHECK(cpu.reg.l == 90);
    CHECK(cpu.reg.pc == 33791);
    // CHECK(cpu.reg.sp == 35272);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[33790] == 0);
}

TEST_CASE( "00 02FE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47423;
    cpu.reg.sp = 55731;
    cpu.reg.a = 21;
    cpu.reg.b = 135;
    cpu.reg.c = 107;
    cpu.reg.d = 212;
    cpu.reg.e = 50;
    cpu.reg.f = 96;
    cpu.reg.h = 197;
    cpu.reg.l = 146;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[47423] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 135);
    CHECK(cpu.reg.c == 107);
    CHECK(cpu.reg.d == 212);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 197);
    CHECK(cpu.reg.l == 146);
    CHECK(cpu.reg.pc == 47424);
    // CHECK(cpu.reg.sp == 55731);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47423] == 0);
}

TEST_CASE( "00 02FF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40323;
    cpu.reg.sp = 45019;
    cpu.reg.a = 231;
    cpu.reg.b = 47;
    cpu.reg.c = 101;
    cpu.reg.d = 89;
    cpu.reg.e = 10;
    cpu.reg.f = 96;
    cpu.reg.h = 251;
    cpu.reg.l = 103;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[40323] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 231);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 101);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 10);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 251);
    CHECK(cpu.reg.l == 103);
    CHECK(cpu.reg.pc == 40324);
    // CHECK(cpu.reg.sp == 45019);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[40323] == 0);
}

TEST_CASE( "00 0300", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3437;
    cpu.reg.sp = 45325;
    cpu.reg.a = 227;
    cpu.reg.b = 48;
    cpu.reg.c = 192;
    cpu.reg.d = 237;
    cpu.reg.e = 122;
    cpu.reg.f = 240;
    cpu.reg.h = 225;
    cpu.reg.l = 8;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[3437] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 227);
    CHECK(cpu.reg.b == 48);
    CHECK(cpu.reg.c == 192);
    CHECK(cpu.reg.d == 237);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 225);
    CHECK(cpu.reg.l == 8);
    CHECK(cpu.reg.pc == 3438);
    // CHECK(cpu.reg.sp == 45325);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3437] == 0);
}

TEST_CASE( "00 0301", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32797;
    cpu.reg.sp = 32142;
    cpu.reg.a = 37;
    cpu.reg.b = 155;
    cpu.reg.c = 136;
    cpu.reg.d = 118;
    cpu.reg.e = 88;
    cpu.reg.f = 208;
    cpu.reg.h = 136;
    cpu.reg.l = 203;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[32797] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 37);
    CHECK(cpu.reg.b == 155);
    CHECK(cpu.reg.c == 136);
    CHECK(cpu.reg.d == 118);
    CHECK(cpu.reg.e == 88);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 203);
    CHECK(cpu.reg.pc == 32798);
    // CHECK(cpu.reg.sp == 32142);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32797] == 0);
}

TEST_CASE( "00 0302", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15328;
    cpu.reg.sp = 52398;
    cpu.reg.a = 163;
    cpu.reg.b = 197;
    cpu.reg.c = 233;
    cpu.reg.d = 196;
    cpu.reg.e = 203;
    cpu.reg.f = 32;
    cpu.reg.h = 91;
    cpu.reg.l = 116;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[15328] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 163);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 203);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 91);
    CHECK(cpu.reg.l == 116);
    CHECK(cpu.reg.pc == 15329);
    // CHECK(cpu.reg.sp == 52398);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15328] == 0);
}

TEST_CASE( "00 0303", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54111;
    cpu.reg.sp = 36396;
    cpu.reg.a = 140;
    cpu.reg.b = 236;
    cpu.reg.c = 97;
    cpu.reg.d = 94;
    cpu.reg.e = 98;
    cpu.reg.f = 112;
    cpu.reg.h = 206;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54111] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 97);
    CHECK(cpu.reg.d == 94);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 54112);
    // CHECK(cpu.reg.sp == 36396);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54111] == 0);
}

TEST_CASE( "00 0304", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39992;
    cpu.reg.sp = 6047;
    cpu.reg.a = 211;
    cpu.reg.b = 254;
    cpu.reg.c = 105;
    cpu.reg.d = 46;
    cpu.reg.e = 217;
    cpu.reg.f = 128;
    cpu.reg.h = 165;
    cpu.reg.l = 222;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[39992] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 211);
    CHECK(cpu.reg.b == 254);
    CHECK(cpu.reg.c == 105);
    CHECK(cpu.reg.d == 46);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 165);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 39993);
    // CHECK(cpu.reg.sp == 6047);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39992] == 0);
}

TEST_CASE( "00 0305", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26407;
    cpu.reg.sp = 16267;
    cpu.reg.a = 210;
    cpu.reg.b = 146;
    cpu.reg.c = 56;
    cpu.reg.d = 56;
    cpu.reg.e = 72;
    cpu.reg.f = 224;
    cpu.reg.h = 147;
    cpu.reg.l = 225;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[26407] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 146);
    CHECK(cpu.reg.c == 56);
    CHECK(cpu.reg.d == 56);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 147);
    CHECK(cpu.reg.l == 225);
    CHECK(cpu.reg.pc == 26408);
    // CHECK(cpu.reg.sp == 16267);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[26407] == 0);
}

TEST_CASE( "00 0306", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61725;
    cpu.reg.sp = 32723;
    cpu.reg.a = 56;
    cpu.reg.b = 6;
    cpu.reg.c = 102;
    cpu.reg.d = 108;
    cpu.reg.e = 111;
    cpu.reg.f = 144;
    cpu.reg.h = 36;
    cpu.reg.l = 13;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[61725] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 56);
    CHECK(cpu.reg.b == 6);
    CHECK(cpu.reg.c == 102);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 36);
    CHECK(cpu.reg.l == 13);
    CHECK(cpu.reg.pc == 61726);
    // CHECK(cpu.reg.sp == 32723);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61725] == 0);
}

TEST_CASE( "00 0307", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4604;
    cpu.reg.sp = 2337;
    cpu.reg.a = 129;
    cpu.reg.b = 171;
    cpu.reg.c = 246;
    cpu.reg.d = 254;
    cpu.reg.e = 52;
    cpu.reg.f = 192;
    cpu.reg.h = 213;
    cpu.reg.l = 241;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4604] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 129);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 246);
    CHECK(cpu.reg.d == 254);
    CHECK(cpu.reg.e == 52);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 213);
    CHECK(cpu.reg.l == 241);
    CHECK(cpu.reg.pc == 4605);
    // CHECK(cpu.reg.sp == 2337);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4604] == 0);
}

TEST_CASE( "00 0308", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49049;
    cpu.reg.sp = 46836;
    cpu.reg.a = 214;
    cpu.reg.b = 176;
    cpu.reg.c = 72;
    cpu.reg.d = 183;
    cpu.reg.e = 158;
    cpu.reg.f = 16;
    cpu.reg.h = 30;
    cpu.reg.l = 123;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49049] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 214);
    CHECK(cpu.reg.b == 176);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 183);
    CHECK(cpu.reg.e == 158);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 30);
    CHECK(cpu.reg.l == 123);
    CHECK(cpu.reg.pc == 49050);
    // CHECK(cpu.reg.sp == 46836);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49049] == 0);
}

TEST_CASE( "00 0309", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25865;
    cpu.reg.sp = 52225;
    cpu.reg.a = 198;
    cpu.reg.b = 9;
    cpu.reg.c = 26;
    cpu.reg.d = 22;
    cpu.reg.e = 195;
    cpu.reg.f = 160;
    cpu.reg.h = 49;
    cpu.reg.l = 229;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25865] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 9);
    CHECK(cpu.reg.c == 26);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 49);
    CHECK(cpu.reg.l == 229);
    CHECK(cpu.reg.pc == 25866);
    // CHECK(cpu.reg.sp == 52225);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25865] == 0);
}

TEST_CASE( "00 030A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58873;
    cpu.reg.sp = 65228;
    cpu.reg.a = 254;
    cpu.reg.b = 101;
    cpu.reg.c = 112;
    cpu.reg.d = 6;
    cpu.reg.e = 44;
    cpu.reg.f = 32;
    cpu.reg.h = 154;
    cpu.reg.l = 80;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[58873] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 254);
    CHECK(cpu.reg.b == 101);
    CHECK(cpu.reg.c == 112);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 44);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 154);
    CHECK(cpu.reg.l == 80);
    CHECK(cpu.reg.pc == 58874);
    // CHECK(cpu.reg.sp == 65228);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58873] == 0);
}

TEST_CASE( "00 030B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58903;
    cpu.reg.sp = 39321;
    cpu.reg.a = 218;
    cpu.reg.b = 83;
    cpu.reg.c = 182;
    cpu.reg.d = 39;
    cpu.reg.e = 124;
    cpu.reg.f = 64;
    cpu.reg.h = 67;
    cpu.reg.l = 59;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[58903] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 83);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 39);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 58904);
    // CHECK(cpu.reg.sp == 39321);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58903] == 0);
}

TEST_CASE( "00 030C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19785;
    cpu.reg.sp = 24904;
    cpu.reg.a = 185;
    cpu.reg.b = 246;
    cpu.reg.c = 72;
    cpu.reg.d = 229;
    cpu.reg.e = 72;
    cpu.reg.f = 192;
    cpu.reg.h = 205;
    cpu.reg.l = 202;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19785] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 185);
    CHECK(cpu.reg.b == 246);
    CHECK(cpu.reg.c == 72);
    CHECK(cpu.reg.d == 229);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 205);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 19786);
    // CHECK(cpu.reg.sp == 24904);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19785] == 0);
}

TEST_CASE( "00 030D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47483;
    cpu.reg.sp = 56427;
    cpu.reg.a = 123;
    cpu.reg.b = 164;
    cpu.reg.c = 80;
    cpu.reg.d = 232;
    cpu.reg.e = 136;
    cpu.reg.f = 240;
    cpu.reg.h = 67;
    cpu.reg.l = 55;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47483] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 123);
    CHECK(cpu.reg.b == 164);
    CHECK(cpu.reg.c == 80);
    CHECK(cpu.reg.d == 232);
    CHECK(cpu.reg.e == 136);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 67);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 47484);
    // CHECK(cpu.reg.sp == 56427);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47483] == 0);
}

TEST_CASE( "00 030E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4082;
    cpu.reg.sp = 62486;
    cpu.reg.a = 30;
    cpu.reg.b = 86;
    cpu.reg.c = 98;
    cpu.reg.d = 4;
    cpu.reg.e = 52;
    cpu.reg.f = 80;
    cpu.reg.h = 4;
    cpu.reg.l = 241;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4082] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 30);
    CHECK(cpu.reg.b == 86);
    CHECK(cpu.reg.c == 98);
    CHECK(cpu.reg.d == 4);
    CHECK(cpu.reg.e == 52);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 4);
    CHECK(cpu.reg.l == 241);
    CHECK(cpu.reg.pc == 4083);
    // CHECK(cpu.reg.sp == 62486);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4082] == 0);
}

TEST_CASE( "00 030F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62686;
    cpu.reg.sp = 37309;
    cpu.reg.a = 11;
    cpu.reg.b = 152;
    cpu.reg.c = 198;
    cpu.reg.d = 41;
    cpu.reg.e = 163;
    cpu.reg.f = 208;
    cpu.reg.h = 189;
    cpu.reg.l = 250;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[62686] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 11);
    CHECK(cpu.reg.b == 152);
    CHECK(cpu.reg.c == 198);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 163);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 189);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 62687);
    // CHECK(cpu.reg.sp == 37309);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62686] == 0);
}

TEST_CASE( "00 0310", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12426;
    cpu.reg.sp = 36702;
    cpu.reg.a = 68;
    cpu.reg.b = 109;
    cpu.reg.c = 205;
    cpu.reg.d = 2;
    cpu.reg.e = 152;
    cpu.reg.f = 96;
    cpu.reg.h = 232;
    cpu.reg.l = 63;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[12426] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 205);
    CHECK(cpu.reg.d == 2);
    CHECK(cpu.reg.e == 152);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 12427);
    // CHECK(cpu.reg.sp == 36702);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12426] == 0);
}

TEST_CASE( "00 0311", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8843;
    cpu.reg.sp = 8053;
    cpu.reg.a = 210;
    cpu.reg.b = 238;
    cpu.reg.c = 209;
    cpu.reg.d = 228;
    cpu.reg.e = 187;
    cpu.reg.f = 112;
    cpu.reg.h = 230;
    cpu.reg.l = 175;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[8843] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 238);
    CHECK(cpu.reg.c == 209);
    CHECK(cpu.reg.d == 228);
    CHECK(cpu.reg.e == 187);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 230);
    CHECK(cpu.reg.l == 175);
    CHECK(cpu.reg.pc == 8844);
    // CHECK(cpu.reg.sp == 8053);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[8843] == 0);
}

TEST_CASE( "00 0312", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2072;
    cpu.reg.sp = 25513;
    cpu.reg.a = 255;
    cpu.reg.b = 251;
    cpu.reg.c = 6;
    cpu.reg.d = 89;
    cpu.reg.e = 1;
    cpu.reg.f = 16;
    cpu.reg.h = 193;
    cpu.reg.l = 195;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[2072] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 255);
    CHECK(cpu.reg.b == 251);
    CHECK(cpu.reg.c == 6);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 193);
    CHECK(cpu.reg.l == 195);
    CHECK(cpu.reg.pc == 2073);
    // CHECK(cpu.reg.sp == 25513);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[2072] == 0);
}

TEST_CASE( "00 0313", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36104;
    cpu.reg.sp = 59258;
    cpu.reg.a = 218;
    cpu.reg.b = 56;
    cpu.reg.c = 60;
    cpu.reg.d = 226;
    cpu.reg.e = 217;
    cpu.reg.f = 192;
    cpu.reg.h = 144;
    cpu.reg.l = 194;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[36104] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 226);
    CHECK(cpu.reg.e == 217);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 144);
    CHECK(cpu.reg.l == 194);
    CHECK(cpu.reg.pc == 36105);
    // CHECK(cpu.reg.sp == 59258);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[36104] == 0);
}

TEST_CASE( "00 0314", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62181;
    cpu.reg.sp = 28095;
    cpu.reg.a = 212;
    cpu.reg.b = 156;
    cpu.reg.c = 52;
    cpu.reg.d = 246;
    cpu.reg.e = 183;
    cpu.reg.f = 208;
    cpu.reg.h = 152;
    cpu.reg.l = 104;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62181] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 156);
    CHECK(cpu.reg.c == 52);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 152);
    CHECK(cpu.reg.l == 104);
    CHECK(cpu.reg.pc == 62182);
    // CHECK(cpu.reg.sp == 28095);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62181] == 0);
}

TEST_CASE( "00 0315", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7250;
    cpu.reg.sp = 19004;
    cpu.reg.a = 107;
    cpu.reg.b = 3;
    cpu.reg.c = 84;
    cpu.reg.d = 119;
    cpu.reg.e = 6;
    cpu.reg.f = 240;
    cpu.reg.h = 0;
    cpu.reg.l = 223;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7250] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 107);
    CHECK(cpu.reg.b == 3);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 119);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 0);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 7251);
    // CHECK(cpu.reg.sp == 19004);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7250] == 0);
}

TEST_CASE( "00 0316", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51073;
    cpu.reg.sp = 6547;
    cpu.reg.a = 219;
    cpu.reg.b = 73;
    cpu.reg.c = 236;
    cpu.reg.d = 64;
    cpu.reg.e = 50;
    cpu.reg.f = 208;
    cpu.reg.h = 243;
    cpu.reg.l = 20;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[51073] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 219);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 64);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 20);
    CHECK(cpu.reg.pc == 51074);
    // CHECK(cpu.reg.sp == 6547);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[51073] == 0);
}

TEST_CASE( "00 0317", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44674;
    cpu.reg.sp = 30634;
    cpu.reg.a = 194;
    cpu.reg.b = 255;
    cpu.reg.c = 87;
    cpu.reg.d = 123;
    cpu.reg.e = 252;
    cpu.reg.f = 48;
    cpu.reg.h = 136;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[44674] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 255);
    CHECK(cpu.reg.c == 87);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 252);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 44675);
    // CHECK(cpu.reg.sp == 30634);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44674] == 0);
}

TEST_CASE( "00 0318", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12470;
    cpu.reg.sp = 13088;
    cpu.reg.a = 232;
    cpu.reg.b = 180;
    cpu.reg.c = 218;
    cpu.reg.d = 36;
    cpu.reg.e = 31;
    cpu.reg.f = 144;
    cpu.reg.h = 95;
    cpu.reg.l = 244;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[12470] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 232);
    CHECK(cpu.reg.b == 180);
    CHECK(cpu.reg.c == 218);
    CHECK(cpu.reg.d == 36);
    CHECK(cpu.reg.e == 31);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 95);
    CHECK(cpu.reg.l == 244);
    CHECK(cpu.reg.pc == 12471);
    // CHECK(cpu.reg.sp == 13088);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12470] == 0);
}

TEST_CASE( "00 0319", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5792;
    cpu.reg.sp = 11262;
    cpu.reg.a = 185;
    cpu.reg.b = 27;
    cpu.reg.c = 146;
    cpu.reg.d = 189;
    cpu.reg.e = 96;
    cpu.reg.f = 96;
    cpu.reg.h = 126;
    cpu.reg.l = 30;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[5792] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 185);
    CHECK(cpu.reg.b == 27);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 189);
    CHECK(cpu.reg.e == 96);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 126);
    CHECK(cpu.reg.l == 30);
    CHECK(cpu.reg.pc == 5793);
    // CHECK(cpu.reg.sp == 11262);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5792] == 0);
}

TEST_CASE( "00 031A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 27374;
    cpu.reg.sp = 5593;
    cpu.reg.a = 101;
    cpu.reg.b = 248;
    cpu.reg.c = 120;
    cpu.reg.d = 244;
    cpu.reg.e = 218;
    cpu.reg.f = 112;
    cpu.reg.h = 215;
    cpu.reg.l = 42;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[27374] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 101);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 218);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 215);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 27375);
    // CHECK(cpu.reg.sp == 5593);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[27374] == 0);
}

TEST_CASE( "00 031B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25453;
    cpu.reg.sp = 23158;
    cpu.reg.a = 0;
    cpu.reg.b = 225;
    cpu.reg.c = 141;
    cpu.reg.d = 172;
    cpu.reg.e = 225;
    cpu.reg.f = 32;
    cpu.reg.h = 161;
    cpu.reg.l = 235;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25453] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 0);
    CHECK(cpu.reg.b == 225);
    CHECK(cpu.reg.c == 141);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 225);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 161);
    CHECK(cpu.reg.l == 235);
    CHECK(cpu.reg.pc == 25454);
    // CHECK(cpu.reg.sp == 23158);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25453] == 0);
}

TEST_CASE( "00 031C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8684;
    cpu.reg.sp = 61860;
    cpu.reg.a = 197;
    cpu.reg.b = 178;
    cpu.reg.c = 24;
    cpu.reg.d = 163;
    cpu.reg.e = 176;
    cpu.reg.f = 32;
    cpu.reg.h = 229;
    cpu.reg.l = 184;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[8684] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 178);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 163);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 229);
    CHECK(cpu.reg.l == 184);
    CHECK(cpu.reg.pc == 8685);
    // CHECK(cpu.reg.sp == 61860);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8684] == 0);
}

TEST_CASE( "00 031D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63071;
    cpu.reg.sp = 51174;
    cpu.reg.a = 84;
    cpu.reg.b = 246;
    cpu.reg.c = 226;
    cpu.reg.d = 172;
    cpu.reg.e = 229;
    cpu.reg.f = 144;
    cpu.reg.h = 183;
    cpu.reg.l = 120;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63071] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 84);
    CHECK(cpu.reg.b == 246);
    CHECK(cpu.reg.c == 226);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 229);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 183);
    CHECK(cpu.reg.l == 120);
    CHECK(cpu.reg.pc == 63072);
    // CHECK(cpu.reg.sp == 51174);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63071] == 0);
}

TEST_CASE( "00 031E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4939;
    cpu.reg.sp = 32952;
    cpu.reg.a = 15;
    cpu.reg.b = 42;
    cpu.reg.c = 1;
    cpu.reg.d = 30;
    cpu.reg.e = 116;
    cpu.reg.f = 208;
    cpu.reg.h = 125;
    cpu.reg.l = 39;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[4939] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 1);
    CHECK(cpu.reg.d == 30);
    CHECK(cpu.reg.e == 116);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 39);
    CHECK(cpu.reg.pc == 4940);
    // CHECK(cpu.reg.sp == 32952);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[4939] == 0);
}

TEST_CASE( "00 031F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63235;
    cpu.reg.sp = 10284;
    cpu.reg.a = 63;
    cpu.reg.b = 248;
    cpu.reg.c = 209;
    cpu.reg.d = 247;
    cpu.reg.e = 122;
    cpu.reg.f = 192;
    cpu.reg.h = 94;
    cpu.reg.l = 192;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[63235] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 248);
    CHECK(cpu.reg.c == 209);
    CHECK(cpu.reg.d == 247);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 94);
    CHECK(cpu.reg.l == 192);
    CHECK(cpu.reg.pc == 63236);
    // CHECK(cpu.reg.sp == 10284);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63235] == 0);
}

TEST_CASE( "00 0320", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44704;
    cpu.reg.sp = 58607;
    cpu.reg.a = 115;
    cpu.reg.b = 72;
    cpu.reg.c = 183;
    cpu.reg.d = 184;
    cpu.reg.e = 235;
    cpu.reg.f = 192;
    cpu.reg.h = 69;
    cpu.reg.l = 27;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[44704] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 115);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 235);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 69);
    CHECK(cpu.reg.l == 27);
    CHECK(cpu.reg.pc == 44705);
    // CHECK(cpu.reg.sp == 58607);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44704] == 0);
}

TEST_CASE( "00 0321", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55675;
    cpu.reg.sp = 4445;
    cpu.reg.a = 29;
    cpu.reg.b = 116;
    cpu.reg.c = 156;
    cpu.reg.d = 93;
    cpu.reg.e = 31;
    cpu.reg.f = 224;
    cpu.reg.h = 18;
    cpu.reg.l = 204;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[55675] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 156);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 31);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 18);
    CHECK(cpu.reg.l == 204);
    CHECK(cpu.reg.pc == 55676);
    // CHECK(cpu.reg.sp == 4445);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[55675] == 0);
}

TEST_CASE( "00 0322", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10160;
    cpu.reg.sp = 27956;
    cpu.reg.a = 24;
    cpu.reg.b = 14;
    cpu.reg.c = 219;
    cpu.reg.d = 61;
    cpu.reg.e = 111;
    cpu.reg.f = 32;
    cpu.reg.h = 160;
    cpu.reg.l = 35;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[10160] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 24);
    CHECK(cpu.reg.b == 14);
    CHECK(cpu.reg.c == 219);
    CHECK(cpu.reg.d == 61);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 35);
    CHECK(cpu.reg.pc == 10161);
    // CHECK(cpu.reg.sp == 27956);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10160] == 0);
}

TEST_CASE( "00 0323", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58175;
    cpu.reg.sp = 60291;
    cpu.reg.a = 10;
    cpu.reg.b = 191;
    cpu.reg.c = 90;
    cpu.reg.d = 105;
    cpu.reg.e = 2;
    cpu.reg.f = 32;
    cpu.reg.h = 26;
    cpu.reg.l = 190;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[58175] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 10);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 105);
    CHECK(cpu.reg.e == 2);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 190);
    CHECK(cpu.reg.pc == 58176);
    // CHECK(cpu.reg.sp == 60291);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[58175] == 0);
}

TEST_CASE( "00 0324", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10644;
    cpu.reg.sp = 50874;
    cpu.reg.a = 82;
    cpu.reg.b = 129;
    cpu.reg.c = 152;
    cpu.reg.d = 234;
    cpu.reg.e = 54;
    cpu.reg.f = 112;
    cpu.reg.h = 91;
    cpu.reg.l = 81;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[10644] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 82);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 91);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 10645);
    // CHECK(cpu.reg.sp == 50874);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10644] == 0);
}

TEST_CASE( "00 0325", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44809;
    cpu.reg.sp = 14919;
    cpu.reg.a = 65;
    cpu.reg.b = 36;
    cpu.reg.c = 27;
    cpu.reg.d = 200;
    cpu.reg.e = 64;
    cpu.reg.f = 48;
    cpu.reg.h = 228;
    cpu.reg.l = 224;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[44809] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 65);
    CHECK(cpu.reg.b == 36);
    CHECK(cpu.reg.c == 27);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 64);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 228);
    CHECK(cpu.reg.l == 224);
    CHECK(cpu.reg.pc == 44810);
    // CHECK(cpu.reg.sp == 14919);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44809] == 0);
}

TEST_CASE( "00 0326", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47278;
    cpu.reg.sp = 13499;
    cpu.reg.a = 98;
    cpu.reg.b = 3;
    cpu.reg.c = 130;
    cpu.reg.d = 110;
    cpu.reg.e = 153;
    cpu.reg.f = 64;
    cpu.reg.h = 38;
    cpu.reg.l = 62;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47278] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 98);
    CHECK(cpu.reg.b == 3);
    CHECK(cpu.reg.c == 130);
    CHECK(cpu.reg.d == 110);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 47279);
    // CHECK(cpu.reg.sp == 13499);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47278] == 0);
}

TEST_CASE( "00 0327", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33496;
    cpu.reg.sp = 8425;
    cpu.reg.a = 118;
    cpu.reg.b = 17;
    cpu.reg.c = 123;
    cpu.reg.d = 136;
    cpu.reg.e = 44;
    cpu.reg.f = 208;
    cpu.reg.h = 53;
    cpu.reg.l = 250;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[33496] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 17);
    CHECK(cpu.reg.c == 123);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 44);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 250);
    CHECK(cpu.reg.pc == 33497);
    // CHECK(cpu.reg.sp == 8425);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33496] == 0);
}

TEST_CASE( "00 0328", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 708;
    cpu.reg.sp = 51378;
    cpu.reg.a = 21;
    cpu.reg.b = 162;
    cpu.reg.c = 179;
    cpu.reg.d = 237;
    cpu.reg.e = 35;
    cpu.reg.f = 128;
    cpu.reg.h = 112;
    cpu.reg.l = 255;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[708] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 162);
    CHECK(cpu.reg.c == 179);
    CHECK(cpu.reg.d == 237);
    CHECK(cpu.reg.e == 35);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 255);
    CHECK(cpu.reg.pc == 709);
    // CHECK(cpu.reg.sp == 51378);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[708] == 0);
}

TEST_CASE( "00 0329", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13751;
    cpu.reg.sp = 4710;
    cpu.reg.a = 161;
    cpu.reg.b = 133;
    cpu.reg.c = 142;
    cpu.reg.d = 126;
    cpu.reg.e = 82;
    cpu.reg.f = 48;
    cpu.reg.h = 247;
    cpu.reg.l = 43;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[13751] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 161);
    CHECK(cpu.reg.b == 133);
    CHECK(cpu.reg.c == 142);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 82);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 43);
    CHECK(cpu.reg.pc == 13752);
    // CHECK(cpu.reg.sp == 4710);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[13751] == 0);
}

TEST_CASE( "00 032A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62557;
    cpu.reg.sp = 21402;
    cpu.reg.a = 139;
    cpu.reg.b = 20;
    cpu.reg.c = 128;
    cpu.reg.d = 18;
    cpu.reg.e = 124;
    cpu.reg.f = 176;
    cpu.reg.h = 38;
    cpu.reg.l = 170;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[62557] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 20);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 18);
    CHECK(cpu.reg.e == 124);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 62558);
    // CHECK(cpu.reg.sp == 21402);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62557] == 0);
}

TEST_CASE( "00 032B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16209;
    cpu.reg.sp = 26140;
    cpu.reg.a = 120;
    cpu.reg.b = 111;
    cpu.reg.c = 215;
    cpu.reg.d = 191;
    cpu.reg.e = 19;
    cpu.reg.f = 16;
    cpu.reg.h = 212;
    cpu.reg.l = 157;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[16209] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 111);
    CHECK(cpu.reg.c == 215);
    CHECK(cpu.reg.d == 191);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 212);
    CHECK(cpu.reg.l == 157);
    CHECK(cpu.reg.pc == 16210);
    // CHECK(cpu.reg.sp == 26140);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16209] == 0);
}

TEST_CASE( "00 032C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13330;
    cpu.reg.sp = 12208;
    cpu.reg.a = 32;
    cpu.reg.b = 246;
    cpu.reg.c = 136;
    cpu.reg.d = 44;
    cpu.reg.e = 80;
    cpu.reg.f = 128;
    cpu.reg.h = 66;
    cpu.reg.l = 84;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[13330] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 32);
    CHECK(cpu.reg.b == 246);
    CHECK(cpu.reg.c == 136);
    CHECK(cpu.reg.d == 44);
    CHECK(cpu.reg.e == 80);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 66);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 13331);
    // CHECK(cpu.reg.sp == 12208);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13330] == 0);
}

TEST_CASE( "00 032D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17767;
    cpu.reg.sp = 63541;
    cpu.reg.a = 235;
    cpu.reg.b = 93;
    cpu.reg.c = 207;
    cpu.reg.d = 35;
    cpu.reg.e = 241;
    cpu.reg.f = 96;
    cpu.reg.h = 57;
    cpu.reg.l = 32;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17767] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 235);
    CHECK(cpu.reg.b == 93);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 241);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 57);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 17768);
    // CHECK(cpu.reg.sp == 63541);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17767] == 0);
}

TEST_CASE( "00 032E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 38604;
    cpu.reg.sp = 46466;
    cpu.reg.a = 12;
    cpu.reg.b = 124;
    cpu.reg.c = 5;
    cpu.reg.d = 106;
    cpu.reg.e = 194;
    cpu.reg.f = 64;
    cpu.reg.h = 146;
    cpu.reg.l = 163;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[38604] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 12);
    CHECK(cpu.reg.b == 124);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 106);
    CHECK(cpu.reg.e == 194);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 146);
    CHECK(cpu.reg.l == 163);
    CHECK(cpu.reg.pc == 38605);
    // CHECK(cpu.reg.sp == 46466);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[38604] == 0);
}

TEST_CASE( "00 032F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 58788;
    cpu.reg.sp = 53865;
    cpu.reg.a = 53;
    cpu.reg.b = 193;
    cpu.reg.c = 150;
    cpu.reg.d = 125;
    cpu.reg.e = 20;
    cpu.reg.f = 0;
    cpu.reg.h = 22;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[58788] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 53);
    CHECK(cpu.reg.b == 193);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 125);
    CHECK(cpu.reg.e == 20);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 22);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 58789);
    // CHECK(cpu.reg.sp == 53865);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[58788] == 0);
}

TEST_CASE( "00 0330", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9293;
    cpu.reg.sp = 32509;
    cpu.reg.a = 240;
    cpu.reg.b = 32;
    cpu.reg.c = 233;
    cpu.reg.d = 246;
    cpu.reg.e = 163;
    cpu.reg.f = 0;
    cpu.reg.h = 238;
    cpu.reg.l = 63;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[9293] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 240);
    CHECK(cpu.reg.b == 32);
    CHECK(cpu.reg.c == 233);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 163);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 238);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 9294);
    // CHECK(cpu.reg.sp == 32509);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9293] == 0);
}

TEST_CASE( "00 0331", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 46732;
    cpu.reg.sp = 32527;
    cpu.reg.a = 164;
    cpu.reg.b = 109;
    cpu.reg.c = 79;
    cpu.reg.d = 234;
    cpu.reg.e = 40;
    cpu.reg.f = 96;
    cpu.reg.h = 191;
    cpu.reg.l = 110;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[46732] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 164);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 79);
    CHECK(cpu.reg.d == 234);
    CHECK(cpu.reg.e == 40);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 191);
    CHECK(cpu.reg.l == 110);
    CHECK(cpu.reg.pc == 46733);
    // CHECK(cpu.reg.sp == 32527);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[46732] == 0);
}

TEST_CASE( "00 0332", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24899;
    cpu.reg.sp = 47688;
    cpu.reg.a = 77;
    cpu.reg.b = 125;
    cpu.reg.c = 152;
    cpu.reg.d = 77;
    cpu.reg.e = 17;
    cpu.reg.f = 144;
    cpu.reg.h = 170;
    cpu.reg.l = 232;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[24899] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 77);
    CHECK(cpu.reg.b == 125);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 77);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 232);
    CHECK(cpu.reg.pc == 24900);
    // CHECK(cpu.reg.sp == 47688);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[24899] == 0);
}

TEST_CASE( "00 0333", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48058;
    cpu.reg.sp = 13465;
    cpu.reg.a = 206;
    cpu.reg.b = 177;
    cpu.reg.c = 168;
    cpu.reg.d = 136;
    cpu.reg.e = 202;
    cpu.reg.f = 80;
    cpu.reg.h = 199;
    cpu.reg.l = 142;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[48058] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 206);
    CHECK(cpu.reg.b == 177);
    CHECK(cpu.reg.c == 168);
    CHECK(cpu.reg.d == 136);
    CHECK(cpu.reg.e == 202);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 199);
    CHECK(cpu.reg.l == 142);
    CHECK(cpu.reg.pc == 48059);
    // CHECK(cpu.reg.sp == 13465);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[48058] == 0);
}

TEST_CASE( "00 0334", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 36480;
    cpu.reg.sp = 59364;
    cpu.reg.a = 226;
    cpu.reg.b = 236;
    cpu.reg.c = 156;
    cpu.reg.d = 206;
    cpu.reg.e = 125;
    cpu.reg.f = 128;
    cpu.reg.h = 125;
    cpu.reg.l = 223;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[36480] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 226);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 156);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 125);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 223);
    CHECK(cpu.reg.pc == 36481);
    // CHECK(cpu.reg.sp == 59364);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[36480] == 0);
}

TEST_CASE( "00 0335", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61184;
    cpu.reg.sp = 14872;
    cpu.reg.a = 118;
    cpu.reg.b = 208;
    cpu.reg.c = 161;
    cpu.reg.d = 177;
    cpu.reg.e = 138;
    cpu.reg.f = 48;
    cpu.reg.h = 83;
    cpu.reg.l = 64;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[61184] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 208);
    CHECK(cpu.reg.c == 161);
    CHECK(cpu.reg.d == 177);
    CHECK(cpu.reg.e == 138);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 83);
    CHECK(cpu.reg.l == 64);
    CHECK(cpu.reg.pc == 61185);
    // CHECK(cpu.reg.sp == 14872);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[61184] == 0);
}

TEST_CASE( "00 0336", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2999;
    cpu.reg.sp = 21394;
    cpu.reg.a = 117;
    cpu.reg.b = 209;
    cpu.reg.c = 210;
    cpu.reg.d = 193;
    cpu.reg.e = 76;
    cpu.reg.f = 144;
    cpu.reg.h = 163;
    cpu.reg.l = 109;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[2999] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 209);
    CHECK(cpu.reg.c == 210);
    CHECK(cpu.reg.d == 193);
    CHECK(cpu.reg.e == 76);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 163);
    CHECK(cpu.reg.l == 109);
    CHECK(cpu.reg.pc == 3000);
    // CHECK(cpu.reg.sp == 21394);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2999] == 0);
}

TEST_CASE( "00 0337", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21909;
    cpu.reg.sp = 62891;
    cpu.reg.a = 22;
    cpu.reg.b = 119;
    cpu.reg.c = 178;
    cpu.reg.d = 198;
    cpu.reg.e = 140;
    cpu.reg.f = 0;
    cpu.reg.h = 71;
    cpu.reg.l = 133;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[21909] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 22);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 178);
    CHECK(cpu.reg.d == 198);
    CHECK(cpu.reg.e == 140);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 21910);
    // CHECK(cpu.reg.sp == 62891);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21909] == 0);
}

TEST_CASE( "00 0338", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63494;
    cpu.reg.sp = 43856;
    cpu.reg.a = 248;
    cpu.reg.b = 116;
    cpu.reg.c = 85;
    cpu.reg.d = 26;
    cpu.reg.e = 77;
    cpu.reg.f = 224;
    cpu.reg.h = 214;
    cpu.reg.l = 251;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[63494] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 248);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 85);
    CHECK(cpu.reg.d == 26);
    CHECK(cpu.reg.e == 77);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 214);
    CHECK(cpu.reg.l == 251);
    CHECK(cpu.reg.pc == 63495);
    // CHECK(cpu.reg.sp == 43856);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63494] == 0);
}

TEST_CASE( "00 0339", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57208;
    cpu.reg.sp = 51907;
    cpu.reg.a = 66;
    cpu.reg.b = 189;
    cpu.reg.c = 227;
    cpu.reg.d = 147;
    cpu.reg.e = 47;
    cpu.reg.f = 176;
    cpu.reg.h = 55;
    cpu.reg.l = 102;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[57208] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 189);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 147);
    CHECK(cpu.reg.e == 47);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 55);
    CHECK(cpu.reg.l == 102);
    CHECK(cpu.reg.pc == 57209);
    // CHECK(cpu.reg.sp == 51907);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57208] == 0);
}

TEST_CASE( "00 033A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44592;
    cpu.reg.sp = 44870;
    cpu.reg.a = 221;
    cpu.reg.b = 102;
    cpu.reg.c = 217;
    cpu.reg.d = 103;
    cpu.reg.e = 168;
    cpu.reg.f = 160;
    cpu.reg.h = 245;
    cpu.reg.l = 55;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[44592] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 221);
    CHECK(cpu.reg.b == 102);
    CHECK(cpu.reg.c == 217);
    CHECK(cpu.reg.d == 103);
    CHECK(cpu.reg.e == 168);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 44593);
    // CHECK(cpu.reg.sp == 44870);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44592] == 0);
}

TEST_CASE( "00 033B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10927;
    cpu.reg.sp = 61857;
    cpu.reg.a = 11;
    cpu.reg.b = 203;
    cpu.reg.c = 125;
    cpu.reg.d = 244;
    cpu.reg.e = 85;
    cpu.reg.f = 112;
    cpu.reg.h = 150;
    cpu.reg.l = 81;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[10927] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 11);
    CHECK(cpu.reg.b == 203);
    CHECK(cpu.reg.c == 125);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 150);
    CHECK(cpu.reg.l == 81);
    CHECK(cpu.reg.pc == 10928);
    // CHECK(cpu.reg.sp == 61857);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[10927] == 0);
}

TEST_CASE( "00 033C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54443;
    cpu.reg.sp = 51272;
    cpu.reg.a = 15;
    cpu.reg.b = 224;
    cpu.reg.c = 253;
    cpu.reg.d = 251;
    cpu.reg.e = 72;
    cpu.reg.f = 80;
    cpu.reg.h = 79;
    cpu.reg.l = 180;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54443] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 15);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 253);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 72);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 79);
    CHECK(cpu.reg.l == 180);
    CHECK(cpu.reg.pc == 54444);
    // CHECK(cpu.reg.sp == 51272);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54443] == 0);
}

TEST_CASE( "00 033D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30611;
    cpu.reg.sp = 636;
    cpu.reg.a = 161;
    cpu.reg.b = 4;
    cpu.reg.c = 20;
    cpu.reg.d = 52;
    cpu.reg.e = 197;
    cpu.reg.f = 64;
    cpu.reg.h = 140;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[30611] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 161);
    CHECK(cpu.reg.b == 4);
    CHECK(cpu.reg.c == 20);
    CHECK(cpu.reg.d == 52);
    CHECK(cpu.reg.e == 197);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 30612);
    // CHECK(cpu.reg.sp == 636);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30611] == 0);
}

TEST_CASE( "00 033E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37124;
    cpu.reg.sp = 1107;
    cpu.reg.a = 153;
    cpu.reg.b = 154;
    cpu.reg.c = 220;
    cpu.reg.d = 166;
    cpu.reg.e = 155;
    cpu.reg.f = 32;
    cpu.reg.h = 24;
    cpu.reg.l = 78;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37124] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 154);
    CHECK(cpu.reg.c == 220);
    CHECK(cpu.reg.d == 166);
    CHECK(cpu.reg.e == 155);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 24);
    CHECK(cpu.reg.l == 78);
    CHECK(cpu.reg.pc == 37125);
    // CHECK(cpu.reg.sp == 1107);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37124] == 0);
}

TEST_CASE( "00 033F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19179;
    cpu.reg.sp = 1539;
    cpu.reg.a = 211;
    cpu.reg.b = 45;
    cpu.reg.c = 83;
    cpu.reg.d = 23;
    cpu.reg.e = 208;
    cpu.reg.f = 16;
    cpu.reg.h = 127;
    cpu.reg.l = 44;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[19179] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 211);
    CHECK(cpu.reg.b == 45);
    CHECK(cpu.reg.c == 83);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 208);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 127);
    CHECK(cpu.reg.l == 44);
    CHECK(cpu.reg.pc == 19180);
    // CHECK(cpu.reg.sp == 1539);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[19179] == 0);
}

TEST_CASE( "00 0340", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7626;
    cpu.reg.sp = 48693;
    cpu.reg.a = 237;
    cpu.reg.b = 31;
    cpu.reg.c = 116;
    cpu.reg.d = 15;
    cpu.reg.e = 53;
    cpu.reg.f = 96;
    cpu.reg.h = 26;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[7626] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 237);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 116);
    CHECK(cpu.reg.d == 15);
    CHECK(cpu.reg.e == 53);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 7627);
    // CHECK(cpu.reg.sp == 48693);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7626] == 0);
}

TEST_CASE( "00 0341", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6862;
    cpu.reg.sp = 8943;
    cpu.reg.a = 20;
    cpu.reg.b = 51;
    cpu.reg.c = 193;
    cpu.reg.d = 0;
    cpu.reg.e = 188;
    cpu.reg.f = 176;
    cpu.reg.h = 102;
    cpu.reg.l = 157;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[6862] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 20);
    CHECK(cpu.reg.b == 51);
    CHECK(cpu.reg.c == 193);
    CHECK(cpu.reg.d == 0);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 102);
    CHECK(cpu.reg.l == 157);
    CHECK(cpu.reg.pc == 6863);
    // CHECK(cpu.reg.sp == 8943);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6862] == 0);
}

TEST_CASE( "00 0342", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47940;
    cpu.reg.sp = 48399;
    cpu.reg.a = 130;
    cpu.reg.b = 36;
    cpu.reg.c = 227;
    cpu.reg.d = 208;
    cpu.reg.e = 101;
    cpu.reg.f = 176;
    cpu.reg.h = 39;
    cpu.reg.l = 181;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[47940] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 130);
    CHECK(cpu.reg.b == 36);
    CHECK(cpu.reg.c == 227);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 101);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 39);
    CHECK(cpu.reg.l == 181);
    CHECK(cpu.reg.pc == 47941);
    // CHECK(cpu.reg.sp == 48399);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[47940] == 0);
}

TEST_CASE( "00 0343", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6797;
    cpu.reg.sp = 32848;
    cpu.reg.a = 240;
    cpu.reg.b = 116;
    cpu.reg.c = 126;
    cpu.reg.d = 169;
    cpu.reg.e = 111;
    cpu.reg.f = 0;
    cpu.reg.h = 163;
    cpu.reg.l = 179;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[6797] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 240);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 126);
    CHECK(cpu.reg.d == 169);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 163);
    CHECK(cpu.reg.l == 179);
    CHECK(cpu.reg.pc == 6798);
    // CHECK(cpu.reg.sp == 32848);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[6797] == 0);
}

TEST_CASE( "00 0344", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25419;
    cpu.reg.sp = 63113;
    cpu.reg.a = 3;
    cpu.reg.b = 158;
    cpu.reg.c = 5;
    cpu.reg.d = 206;
    cpu.reg.e = 219;
    cpu.reg.f = 96;
    cpu.reg.h = 136;
    cpu.reg.l = 216;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[25419] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 158);
    CHECK(cpu.reg.c == 5);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 25420);
    // CHECK(cpu.reg.sp == 63113);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25419] == 0);
}

TEST_CASE( "00 0345", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54239;
    cpu.reg.sp = 21950;
    cpu.reg.a = 121;
    cpu.reg.b = 230;
    cpu.reg.c = 122;
    cpu.reg.d = 219;
    cpu.reg.e = 178;
    cpu.reg.f = 64;
    cpu.reg.h = 100;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54239] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 121);
    CHECK(cpu.reg.b == 230);
    CHECK(cpu.reg.c == 122);
    CHECK(cpu.reg.d == 219);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 100);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 54240);
    // CHECK(cpu.reg.sp == 21950);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54239] == 0);
}

TEST_CASE( "00 0346", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 11335;
    cpu.reg.sp = 653;
    cpu.reg.a = 14;
    cpu.reg.b = 111;
    cpu.reg.c = 15;
    cpu.reg.d = 80;
    cpu.reg.e = 60;
    cpu.reg.f = 48;
    cpu.reg.h = 130;
    cpu.reg.l = 29;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[11335] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 111);
    CHECK(cpu.reg.c == 15);
    CHECK(cpu.reg.d == 80);
    CHECK(cpu.reg.e == 60);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 130);
    CHECK(cpu.reg.l == 29);
    CHECK(cpu.reg.pc == 11336);
    // CHECK(cpu.reg.sp == 653);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[11335] == 0);
}

TEST_CASE( "00 0347", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24825;
    cpu.reg.sp = 55929;
    cpu.reg.a = 81;
    cpu.reg.b = 49;
    cpu.reg.c = 170;
    cpu.reg.d = 79;
    cpu.reg.e = 190;
    cpu.reg.f = 48;
    cpu.reg.h = 111;
    cpu.reg.l = 172;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[24825] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 81);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 170);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 190);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 111);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 24826);
    // CHECK(cpu.reg.sp == 55929);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[24825] == 0);
}

TEST_CASE( "00 0348", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30744;
    cpu.reg.sp = 3121;
    cpu.reg.a = 212;
    cpu.reg.b = 60;
    cpu.reg.c = 22;
    cpu.reg.d = 146;
    cpu.reg.e = 122;
    cpu.reg.f = 128;
    cpu.reg.h = 27;
    cpu.reg.l = 202;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[30744] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 212);
    CHECK(cpu.reg.b == 60);
    CHECK(cpu.reg.c == 22);
    CHECK(cpu.reg.d == 146);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 27);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 30745);
    // CHECK(cpu.reg.sp == 3121);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30744] == 0);
}

TEST_CASE( "00 0349", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16289;
    cpu.reg.sp = 19815;
    cpu.reg.a = 58;
    cpu.reg.b = 158;
    cpu.reg.c = 177;
    cpu.reg.d = 200;
    cpu.reg.e = 221;
    cpu.reg.f = 224;
    cpu.reg.h = 37;
    cpu.reg.l = 122;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[16289] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 58);
    CHECK(cpu.reg.b == 158);
    CHECK(cpu.reg.c == 177);
    CHECK(cpu.reg.d == 200);
    CHECK(cpu.reg.e == 221);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 37);
    CHECK(cpu.reg.l == 122);
    CHECK(cpu.reg.pc == 16290);
    // CHECK(cpu.reg.sp == 19815);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16289] == 0);
}

TEST_CASE( "00 034A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 19707;
    cpu.reg.sp = 20289;
    cpu.reg.a = 195;
    cpu.reg.b = 119;
    cpu.reg.c = 120;
    cpu.reg.d = 91;
    cpu.reg.e = 189;
    cpu.reg.f = 192;
    cpu.reg.h = 199;
    cpu.reg.l = 84;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[19707] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 195);
    CHECK(cpu.reg.b == 119);
    CHECK(cpu.reg.c == 120);
    CHECK(cpu.reg.d == 91);
    CHECK(cpu.reg.e == 189);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 199);
    CHECK(cpu.reg.l == 84);
    CHECK(cpu.reg.pc == 19708);
    // CHECK(cpu.reg.sp == 20289);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[19707] == 0);
}

TEST_CASE( "00 034B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62008;
    cpu.reg.sp = 46122;
    cpu.reg.a = 11;
    cpu.reg.b = 169;
    cpu.reg.c = 209;
    cpu.reg.d = 152;
    cpu.reg.e = 61;
    cpu.reg.f = 144;
    cpu.reg.h = 86;
    cpu.reg.l = 69;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[62008] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 11);
    CHECK(cpu.reg.b == 169);
    CHECK(cpu.reg.c == 209);
    CHECK(cpu.reg.d == 152);
    CHECK(cpu.reg.e == 61);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 86);
    CHECK(cpu.reg.l == 69);
    CHECK(cpu.reg.pc == 62009);
    // CHECK(cpu.reg.sp == 46122);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[62008] == 0);
}

TEST_CASE( "00 034C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37638;
    cpu.reg.sp = 43724;
    cpu.reg.a = 104;
    cpu.reg.b = 91;
    cpu.reg.c = 100;
    cpu.reg.d = 139;
    cpu.reg.e = 50;
    cpu.reg.f = 48;
    cpu.reg.h = 250;
    cpu.reg.l = 167;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[37638] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 104);
    CHECK(cpu.reg.b == 91);
    CHECK(cpu.reg.c == 100);
    CHECK(cpu.reg.d == 139);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 250);
    CHECK(cpu.reg.l == 167);
    CHECK(cpu.reg.pc == 37639);
    // CHECK(cpu.reg.sp == 43724);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37638] == 0);
}

TEST_CASE( "00 034D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56493;
    cpu.reg.sp = 53100;
    cpu.reg.a = 223;
    cpu.reg.b = 68;
    cpu.reg.c = 103;
    cpu.reg.d = 35;
    cpu.reg.e = 137;
    cpu.reg.f = 96;
    cpu.reg.h = 157;
    cpu.reg.l = 211;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[56493] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 223);
    CHECK(cpu.reg.b == 68);
    CHECK(cpu.reg.c == 103);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 137);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 157);
    CHECK(cpu.reg.l == 211);
    CHECK(cpu.reg.pc == 56494);
    // CHECK(cpu.reg.sp == 53100);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[56493] == 0);
}

TEST_CASE( "00 034E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48653;
    cpu.reg.sp = 40139;
    cpu.reg.a = 218;
    cpu.reg.b = 87;
    cpu.reg.c = 67;
    cpu.reg.d = 180;
    cpu.reg.e = 50;
    cpu.reg.f = 64;
    cpu.reg.h = 206;
    cpu.reg.l = 40;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48653] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 67);
    CHECK(cpu.reg.d == 180);
    CHECK(cpu.reg.e == 50);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 40);
    CHECK(cpu.reg.pc == 48654);
    // CHECK(cpu.reg.sp == 40139);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48653] == 0);
}

TEST_CASE( "00 034F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52421;
    cpu.reg.sp = 10561;
    cpu.reg.a = 1;
    cpu.reg.b = 185;
    cpu.reg.c = 85;
    cpu.reg.d = 244;
    cpu.reg.e = 118;
    cpu.reg.f = 160;
    cpu.reg.h = 150;
    cpu.reg.l = 54;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[52421] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 1);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 85);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 118);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 150);
    CHECK(cpu.reg.l == 54);
    CHECK(cpu.reg.pc == 52422);
    // CHECK(cpu.reg.sp == 10561);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52421] == 0);
}

TEST_CASE( "00 0350", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48717;
    cpu.reg.sp = 40364;
    cpu.reg.a = 155;
    cpu.reg.b = 127;
    cpu.reg.c = 163;
    cpu.reg.d = 144;
    cpu.reg.e = 114;
    cpu.reg.f = 0;
    cpu.reg.h = 129;
    cpu.reg.l = 12;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48717] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 155);
    CHECK(cpu.reg.b == 127);
    CHECK(cpu.reg.c == 163);
    CHECK(cpu.reg.d == 144);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 129);
    CHECK(cpu.reg.l == 12);
    CHECK(cpu.reg.pc == 48718);
    // CHECK(cpu.reg.sp == 40364);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48717] == 0);
}

TEST_CASE( "00 0351", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32510;
    cpu.reg.sp = 42141;
    cpu.reg.a = 108;
    cpu.reg.b = 108;
    cpu.reg.c = 26;
    cpu.reg.d = 14;
    cpu.reg.e = 235;
    cpu.reg.f = 16;
    cpu.reg.h = 237;
    cpu.reg.l = 230;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[32510] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 108);
    CHECK(cpu.reg.b == 108);
    CHECK(cpu.reg.c == 26);
    CHECK(cpu.reg.d == 14);
    CHECK(cpu.reg.e == 235);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 237);
    CHECK(cpu.reg.l == 230);
    CHECK(cpu.reg.pc == 32511);
    // CHECK(cpu.reg.sp == 42141);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32510] == 0);
}

TEST_CASE( "00 0352", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30429;
    cpu.reg.sp = 47240;
    cpu.reg.a = 14;
    cpu.reg.b = 30;
    cpu.reg.c = 37;
    cpu.reg.d = 29;
    cpu.reg.e = 43;
    cpu.reg.f = 112;
    cpu.reg.h = 236;
    cpu.reg.l = 63;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[30429] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 30);
    CHECK(cpu.reg.c == 37);
    CHECK(cpu.reg.d == 29);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 236);
    CHECK(cpu.reg.l == 63);
    CHECK(cpu.reg.pc == 30430);
    // CHECK(cpu.reg.sp == 47240);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30429] == 0);
}

TEST_CASE( "00 0353", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40321;
    cpu.reg.sp = 53378;
    cpu.reg.a = 23;
    cpu.reg.b = 51;
    cpu.reg.c = 175;
    cpu.reg.d = 166;
    cpu.reg.e = 153;
    cpu.reg.f = 48;
    cpu.reg.h = 181;
    cpu.reg.l = 48;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40321] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 23);
    CHECK(cpu.reg.b == 51);
    CHECK(cpu.reg.c == 175);
    CHECK(cpu.reg.d == 166);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 181);
    CHECK(cpu.reg.l == 48);
    CHECK(cpu.reg.pc == 40322);
    // CHECK(cpu.reg.sp == 53378);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40321] == 0);
}

TEST_CASE( "00 0354", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18215;
    cpu.reg.sp = 29475;
    cpu.reg.a = 172;
    cpu.reg.b = 221;
    cpu.reg.c = 119;
    cpu.reg.d = 206;
    cpu.reg.e = 255;
    cpu.reg.f = 96;
    cpu.reg.h = 113;
    cpu.reg.l = 128;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[18215] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 172);
    CHECK(cpu.reg.b == 221);
    CHECK(cpu.reg.c == 119);
    CHECK(cpu.reg.d == 206);
    CHECK(cpu.reg.e == 255);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 113);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 18216);
    // CHECK(cpu.reg.sp == 29475);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18215] == 0);
}

TEST_CASE( "00 0355", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 176;
    cpu.reg.sp = 61791;
    cpu.reg.a = 78;
    cpu.reg.b = 14;
    cpu.reg.c = 106;
    cpu.reg.d = 37;
    cpu.reg.e = 98;
    cpu.reg.f = 208;
    cpu.reg.h = 221;
    cpu.reg.l = 116;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[176] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 14);
    CHECK(cpu.reg.c == 106);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 98);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 221);
    CHECK(cpu.reg.l == 116);
    CHECK(cpu.reg.pc == 177);
    // CHECK(cpu.reg.sp == 61791);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[176] == 0);
}

TEST_CASE( "00 0356", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41486;
    cpu.reg.sp = 10425;
    cpu.reg.a = 85;
    cpu.reg.b = 19;
    cpu.reg.c = 244;
    cpu.reg.d = 129;
    cpu.reg.e = 63;
    cpu.reg.f = 64;
    cpu.reg.h = 120;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[41486] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 85);
    CHECK(cpu.reg.b == 19);
    CHECK(cpu.reg.c == 244);
    CHECK(cpu.reg.d == 129);
    CHECK(cpu.reg.e == 63);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 41487);
    // CHECK(cpu.reg.sp == 10425);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41486] == 0);
}

TEST_CASE( "00 0357", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23229;
    cpu.reg.sp = 22390;
    cpu.reg.a = 118;
    cpu.reg.b = 64;
    cpu.reg.c = 146;
    cpu.reg.d = 31;
    cpu.reg.e = 96;
    cpu.reg.f = 160;
    cpu.reg.h = 188;
    cpu.reg.l = 219;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[23229] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 64);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 96);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 188);
    CHECK(cpu.reg.l == 219);
    CHECK(cpu.reg.pc == 23230);
    // CHECK(cpu.reg.sp == 22390);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[23229] == 0);
}

TEST_CASE( "00 0358", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44413;
    cpu.reg.sp = 59221;
    cpu.reg.a = 192;
    cpu.reg.b = 9;
    cpu.reg.c = 10;
    cpu.reg.d = 160;
    cpu.reg.e = 165;
    cpu.reg.f = 16;
    cpu.reg.h = 60;
    cpu.reg.l = 21;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44413] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 192);
    CHECK(cpu.reg.b == 9);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 160);
    CHECK(cpu.reg.e == 165);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 21);
    CHECK(cpu.reg.pc == 44414);
    // CHECK(cpu.reg.sp == 59221);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44413] == 0);
}

TEST_CASE( "00 0359", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29880;
    cpu.reg.sp = 51519;
    cpu.reg.a = 66;
    cpu.reg.b = 123;
    cpu.reg.c = 187;
    cpu.reg.d = 185;
    cpu.reg.e = 176;
    cpu.reg.f = 128;
    cpu.reg.h = 220;
    cpu.reg.l = 222;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[29880] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 123);
    CHECK(cpu.reg.c == 187);
    CHECK(cpu.reg.d == 185);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 220);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 29881);
    // CHECK(cpu.reg.sp == 51519);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29880] == 0);
}

TEST_CASE( "00 035A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12695;
    cpu.reg.sp = 14709;
    cpu.reg.a = 90;
    cpu.reg.b = 19;
    cpu.reg.c = 16;
    cpu.reg.d = 217;
    cpu.reg.e = 73;
    cpu.reg.f = 112;
    cpu.reg.h = 29;
    cpu.reg.l = 134;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[12695] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 90);
    CHECK(cpu.reg.b == 19);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 217);
    CHECK(cpu.reg.e == 73);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 29);
    CHECK(cpu.reg.l == 134);
    CHECK(cpu.reg.pc == 12696);
    // CHECK(cpu.reg.sp == 14709);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12695] == 0);
}

TEST_CASE( "00 035B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48824;
    cpu.reg.sp = 1883;
    cpu.reg.a = 194;
    cpu.reg.b = 202;
    cpu.reg.c = 190;
    cpu.reg.d = 28;
    cpu.reg.e = 179;
    cpu.reg.f = 192;
    cpu.reg.h = 232;
    cpu.reg.l = 73;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[48824] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 28);
    CHECK(cpu.reg.e == 179);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 73);
    CHECK(cpu.reg.pc == 48825);
    // CHECK(cpu.reg.sp == 1883);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48824] == 0);
}

TEST_CASE( "00 035C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 20493;
    cpu.reg.sp = 23168;
    cpu.reg.a = 21;
    cpu.reg.b = 73;
    cpu.reg.c = 128;
    cpu.reg.d = 17;
    cpu.reg.e = 166;
    cpu.reg.f = 32;
    cpu.reg.h = 36;
    cpu.reg.l = 26;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[20493] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 21);
    CHECK(cpu.reg.b == 73);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 17);
    CHECK(cpu.reg.e == 166);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 36);
    CHECK(cpu.reg.l == 26);
    CHECK(cpu.reg.pc == 20494);
    // CHECK(cpu.reg.sp == 23168);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[20493] == 0);
}

TEST_CASE( "00 035D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7526;
    cpu.reg.sp = 21896;
    cpu.reg.a = 137;
    cpu.reg.b = 149;
    cpu.reg.c = 78;
    cpu.reg.d = 127;
    cpu.reg.e = 192;
    cpu.reg.f = 176;
    cpu.reg.h = 132;
    cpu.reg.l = 140;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[7526] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 137);
    CHECK(cpu.reg.b == 149);
    CHECK(cpu.reg.c == 78);
    CHECK(cpu.reg.d == 127);
    CHECK(cpu.reg.e == 192);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 132);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 7527);
    // CHECK(cpu.reg.sp == 21896);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7526] == 0);
}

TEST_CASE( "00 035E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44223;
    cpu.reg.sp = 33877;
    cpu.reg.a = 9;
    cpu.reg.b = 114;
    cpu.reg.c = 71;
    cpu.reg.d = 196;
    cpu.reg.e = 112;
    cpu.reg.f = 176;
    cpu.reg.h = 129;
    cpu.reg.l = 140;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[44223] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 9);
    CHECK(cpu.reg.b == 114);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 112);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 129);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 44224);
    // CHECK(cpu.reg.sp == 33877);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[44223] == 0);
}

TEST_CASE( "00 035F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29336;
    cpu.reg.sp = 27350;
    cpu.reg.a = 146;
    cpu.reg.b = 49;
    cpu.reg.c = 10;
    cpu.reg.d = 174;
    cpu.reg.e = 16;
    cpu.reg.f = 144;
    cpu.reg.h = 79;
    cpu.reg.l = 253;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29336] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 146);
    CHECK(cpu.reg.b == 49);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 174);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 79);
    CHECK(cpu.reg.l == 253);
    CHECK(cpu.reg.pc == 29337);
    // CHECK(cpu.reg.sp == 27350);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29336] == 0);
}

TEST_CASE( "00 0360", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16212;
    cpu.reg.sp = 1331;
    cpu.reg.a = 198;
    cpu.reg.b = 215;
    cpu.reg.c = 243;
    cpu.reg.d = 14;
    cpu.reg.e = 165;
    cpu.reg.f = 144;
    cpu.reg.h = 53;
    cpu.reg.l = 97;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[16212] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 198);
    CHECK(cpu.reg.b == 215);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 14);
    CHECK(cpu.reg.e == 165);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 97);
    CHECK(cpu.reg.pc == 16213);
    // CHECK(cpu.reg.sp == 1331);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16212] == 0);
}

TEST_CASE( "00 0361", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22380;
    cpu.reg.sp = 11012;
    cpu.reg.a = 2;
    cpu.reg.b = 250;
    cpu.reg.c = 121;
    cpu.reg.d = 208;
    cpu.reg.e = 32;
    cpu.reg.f = 144;
    cpu.reg.h = 71;
    cpu.reg.l = 68;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22380] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 2);
    CHECK(cpu.reg.b == 250);
    CHECK(cpu.reg.c == 121);
    CHECK(cpu.reg.d == 208);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 68);
    CHECK(cpu.reg.pc == 22381);
    // CHECK(cpu.reg.sp == 11012);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22380] == 0);
}

TEST_CASE( "00 0362", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21897;
    cpu.reg.sp = 29960;
    cpu.reg.a = 255;
    cpu.reg.b = 96;
    cpu.reg.c = 12;
    cpu.reg.d = 99;
    cpu.reg.e = 141;
    cpu.reg.f = 64;
    cpu.reg.h = 186;
    cpu.reg.l = 124;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21897] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 255);
    CHECK(cpu.reg.b == 96);
    CHECK(cpu.reg.c == 12);
    CHECK(cpu.reg.d == 99);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 186);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 21898);
    // CHECK(cpu.reg.sp == 29960);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21897] == 0);
}

TEST_CASE( "00 0363", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26246;
    cpu.reg.sp = 48117;
    cpu.reg.a = 25;
    cpu.reg.b = 158;
    cpu.reg.c = 152;
    cpu.reg.d = 210;
    cpu.reg.e = 17;
    cpu.reg.f = 16;
    cpu.reg.h = 32;
    cpu.reg.l = 107;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26246] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 158);
    CHECK(cpu.reg.c == 152);
    CHECK(cpu.reg.d == 210);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 32);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 26247);
    // CHECK(cpu.reg.sp == 48117);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26246] == 0);
}

TEST_CASE( "00 0364", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53723;
    cpu.reg.sp = 10761;
    cpu.reg.a = 229;
    cpu.reg.b = 197;
    cpu.reg.c = 38;
    cpu.reg.d = 154;
    cpu.reg.e = 133;
    cpu.reg.f = 240;
    cpu.reg.h = 223;
    cpu.reg.l = 33;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53723] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 229);
    CHECK(cpu.reg.b == 197);
    CHECK(cpu.reg.c == 38);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 133);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 223);
    CHECK(cpu.reg.l == 33);
    CHECK(cpu.reg.pc == 53724);
    // CHECK(cpu.reg.sp == 10761);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53723] == 0);
}

TEST_CASE( "00 0365", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7266;
    cpu.reg.sp = 21643;
    cpu.reg.a = 253;
    cpu.reg.b = 249;
    cpu.reg.c = 222;
    cpu.reg.d = 207;
    cpu.reg.e = 250;
    cpu.reg.f = 176;
    cpu.reg.h = 71;
    cpu.reg.l = 220;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[7266] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 253);
    CHECK(cpu.reg.b == 249);
    CHECK(cpu.reg.c == 222);
    CHECK(cpu.reg.d == 207);
    CHECK(cpu.reg.e == 250);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 71);
    CHECK(cpu.reg.l == 220);
    CHECK(cpu.reg.pc == 7267);
    // CHECK(cpu.reg.sp == 21643);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[7266] == 0);
}

TEST_CASE( "00 0366", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18460;
    cpu.reg.sp = 50446;
    cpu.reg.a = 148;
    cpu.reg.b = 127;
    cpu.reg.c = 138;
    cpu.reg.d = 20;
    cpu.reg.e = 249;
    cpu.reg.f = 176;
    cpu.reg.h = 224;
    cpu.reg.l = 41;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[18460] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 127);
    CHECK(cpu.reg.c == 138);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 249);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 224);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 18461);
    // CHECK(cpu.reg.sp == 50446);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[18460] == 0);
}

TEST_CASE( "00 0367", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59711;
    cpu.reg.sp = 58934;
    cpu.reg.a = 75;
    cpu.reg.b = 94;
    cpu.reg.c = 201;
    cpu.reg.d = 203;
    cpu.reg.e = 234;
    cpu.reg.f = 224;
    cpu.reg.h = 102;
    cpu.reg.l = 77;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[59711] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 75);
    CHECK(cpu.reg.b == 94);
    CHECK(cpu.reg.c == 201);
    CHECK(cpu.reg.d == 203);
    CHECK(cpu.reg.e == 234);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 102);
    CHECK(cpu.reg.l == 77);
    CHECK(cpu.reg.pc == 59712);
    // CHECK(cpu.reg.sp == 58934);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[59711] == 0);
}

TEST_CASE( "00 0368", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25076;
    cpu.reg.sp = 56821;
    cpu.reg.a = 184;
    cpu.reg.b = 138;
    cpu.reg.c = 250;
    cpu.reg.d = 223;
    cpu.reg.e = 16;
    cpu.reg.f = 16;
    cpu.reg.h = 156;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25076] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 138);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 16);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 156);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 25077);
    // CHECK(cpu.reg.sp == 56821);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25076] == 0);
}

TEST_CASE( "00 0369", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1367;
    cpu.reg.sp = 58774;
    cpu.reg.a = 184;
    cpu.reg.b = 76;
    cpu.reg.c = 16;
    cpu.reg.d = 20;
    cpu.reg.e = 209;
    cpu.reg.f = 80;
    cpu.reg.h = 167;
    cpu.reg.l = 110;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[1367] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 184);
    CHECK(cpu.reg.b == 76);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 209);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 167);
    CHECK(cpu.reg.l == 110);
    CHECK(cpu.reg.pc == 1368);
    // CHECK(cpu.reg.sp == 58774);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1367] == 0);
}

TEST_CASE( "00 036A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18733;
    cpu.reg.sp = 18031;
    cpu.reg.a = 7;
    cpu.reg.b = 19;
    cpu.reg.c = 158;
    cpu.reg.d = 193;
    cpu.reg.e = 219;
    cpu.reg.f = 128;
    cpu.reg.h = 157;
    cpu.reg.l = 160;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[18733] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 7);
    CHECK(cpu.reg.b == 19);
    CHECK(cpu.reg.c == 158);
    CHECK(cpu.reg.d == 193);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 157);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 18734);
    // CHECK(cpu.reg.sp == 18031);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18733] == 0);
}

TEST_CASE( "00 036B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26792;
    cpu.reg.sp = 15155;
    cpu.reg.a = 90;
    cpu.reg.b = 37;
    cpu.reg.c = 144;
    cpu.reg.d = 192;
    cpu.reg.e = 88;
    cpu.reg.f = 112;
    cpu.reg.h = 66;
    cpu.reg.l = 8;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26792] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 90);
    CHECK(cpu.reg.b == 37);
    CHECK(cpu.reg.c == 144);
    CHECK(cpu.reg.d == 192);
    CHECK(cpu.reg.e == 88);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 66);
    CHECK(cpu.reg.l == 8);
    CHECK(cpu.reg.pc == 26793);
    // CHECK(cpu.reg.sp == 15155);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26792] == 0);
}

TEST_CASE( "00 036C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 23328;
    cpu.reg.sp = 15751;
    cpu.reg.a = 192;
    cpu.reg.b = 101;
    cpu.reg.c = 27;
    cpu.reg.d = 139;
    cpu.reg.e = 84;
    cpu.reg.f = 208;
    cpu.reg.h = 83;
    cpu.reg.l = 150;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[23328] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 192);
    CHECK(cpu.reg.b == 101);
    CHECK(cpu.reg.c == 27);
    CHECK(cpu.reg.d == 139);
    CHECK(cpu.reg.e == 84);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 83);
    CHECK(cpu.reg.l == 150);
    CHECK(cpu.reg.pc == 23329);
    // CHECK(cpu.reg.sp == 15751);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[23328] == 0);
}

TEST_CASE( "00 036D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39732;
    cpu.reg.sp = 10850;
    cpu.reg.a = 217;
    cpu.reg.b = 166;
    cpu.reg.c = 60;
    cpu.reg.d = 41;
    cpu.reg.e = 75;
    cpu.reg.f = 176;
    cpu.reg.h = 194;
    cpu.reg.l = 247;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[39732] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 217);
    CHECK(cpu.reg.b == 166);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 75);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 194);
    CHECK(cpu.reg.l == 247);
    CHECK(cpu.reg.pc == 39733);
    // CHECK(cpu.reg.sp == 10850);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39732] == 0);
}

TEST_CASE( "00 036E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55761;
    cpu.reg.sp = 28697;
    cpu.reg.a = 253;
    cpu.reg.b = 10;
    cpu.reg.c = 150;
    cpu.reg.d = 223;
    cpu.reg.e = 246;
    cpu.reg.f = 96;
    cpu.reg.h = 39;
    cpu.reg.l = 67;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[55761] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 253);
    CHECK(cpu.reg.b == 10);
    CHECK(cpu.reg.c == 150);
    CHECK(cpu.reg.d == 223);
    CHECK(cpu.reg.e == 246);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 39);
    CHECK(cpu.reg.l == 67);
    CHECK(cpu.reg.pc == 55762);
    // CHECK(cpu.reg.sp == 28697);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[55761] == 0);
}

TEST_CASE( "00 036F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57375;
    cpu.reg.sp = 48031;
    cpu.reg.a = 32;
    cpu.reg.b = 57;
    cpu.reg.c = 88;
    cpu.reg.d = 115;
    cpu.reg.e = 20;
    cpu.reg.f = 48;
    cpu.reg.h = 175;
    cpu.reg.l = 23;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[57375] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 32);
    CHECK(cpu.reg.b == 57);
    CHECK(cpu.reg.c == 88);
    CHECK(cpu.reg.d == 115);
    CHECK(cpu.reg.e == 20);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 175);
    CHECK(cpu.reg.l == 23);
    CHECK(cpu.reg.pc == 57376);
    // CHECK(cpu.reg.sp == 48031);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57375] == 0);
}

TEST_CASE( "00 0370", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9106;
    cpu.reg.sp = 23594;
    cpu.reg.a = 3;
    cpu.reg.b = 94;
    cpu.reg.c = 213;
    cpu.reg.d = 33;
    cpu.reg.e = 179;
    cpu.reg.f = 64;
    cpu.reg.h = 168;
    cpu.reg.l = 32;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[9106] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 94);
    CHECK(cpu.reg.c == 213);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 179);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 168);
    CHECK(cpu.reg.l == 32);
    CHECK(cpu.reg.pc == 9107);
    // CHECK(cpu.reg.sp == 23594);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[9106] == 0);
}

TEST_CASE( "00 0371", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33473;
    cpu.reg.sp = 26621;
    cpu.reg.a = 17;
    cpu.reg.b = 56;
    cpu.reg.c = 74;
    cpu.reg.d = 48;
    cpu.reg.e = 255;
    cpu.reg.f = 96;
    cpu.reg.h = 34;
    cpu.reg.l = 124;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[33473] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 17);
    CHECK(cpu.reg.b == 56);
    CHECK(cpu.reg.c == 74);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 255);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 34);
    CHECK(cpu.reg.l == 124);
    CHECK(cpu.reg.pc == 33474);
    // CHECK(cpu.reg.sp == 26621);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[33473] == 0);
}

TEST_CASE( "00 0372", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37551;
    cpu.reg.sp = 54898;
    cpu.reg.a = 255;
    cpu.reg.b = 172;
    cpu.reg.c = 174;
    cpu.reg.d = 12;
    cpu.reg.e = 151;
    cpu.reg.f = 208;
    cpu.reg.h = 230;
    cpu.reg.l = 221;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[37551] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 255);
    CHECK(cpu.reg.b == 172);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 12);
    CHECK(cpu.reg.e == 151);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 230);
    CHECK(cpu.reg.l == 221);
    CHECK(cpu.reg.pc == 37552);
    // CHECK(cpu.reg.sp == 54898);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37551] == 0);
}

TEST_CASE( "00 0373", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18581;
    cpu.reg.sp = 16445;
    cpu.reg.a = 42;
    cpu.reg.b = 41;
    cpu.reg.c = 122;
    cpu.reg.d = 27;
    cpu.reg.e = 125;
    cpu.reg.f = 48;
    cpu.reg.h = 55;
    cpu.reg.l = 26;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[18581] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 42);
    CHECK(cpu.reg.b == 41);
    CHECK(cpu.reg.c == 122);
    CHECK(cpu.reg.d == 27);
    CHECK(cpu.reg.e == 125);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 55);
    CHECK(cpu.reg.l == 26);
    CHECK(cpu.reg.pc == 18582);
    // CHECK(cpu.reg.sp == 16445);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[18581] == 0);
}

TEST_CASE( "00 0374", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63785;
    cpu.reg.sp = 50667;
    cpu.reg.a = 161;
    cpu.reg.b = 72;
    cpu.reg.c = 61;
    cpu.reg.d = 128;
    cpu.reg.e = 67;
    cpu.reg.f = 16;
    cpu.reg.h = 68;
    cpu.reg.l = 216;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[63785] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 161);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 61);
    CHECK(cpu.reg.d == 128);
    CHECK(cpu.reg.e == 67);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 68);
    CHECK(cpu.reg.l == 216);
    CHECK(cpu.reg.pc == 63786);
    // CHECK(cpu.reg.sp == 50667);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[63785] == 0);
}

TEST_CASE( "00 0375", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29650;
    cpu.reg.sp = 55355;
    cpu.reg.a = 103;
    cpu.reg.b = 51;
    cpu.reg.c = 151;
    cpu.reg.d = 33;
    cpu.reg.e = 114;
    cpu.reg.f = 112;
    cpu.reg.h = 247;
    cpu.reg.l = 143;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29650] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 103);
    CHECK(cpu.reg.b == 51);
    CHECK(cpu.reg.c == 151);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 114);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 143);
    CHECK(cpu.reg.pc == 29651);
    // CHECK(cpu.reg.sp == 55355);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29650] == 0);
}

TEST_CASE( "00 0376", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29574;
    cpu.reg.sp = 53700;
    cpu.reg.a = 161;
    cpu.reg.b = 212;
    cpu.reg.c = 55;
    cpu.reg.d = 54;
    cpu.reg.e = 188;
    cpu.reg.f = 192;
    cpu.reg.h = 116;
    cpu.reg.l = 90;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29574] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 161);
    CHECK(cpu.reg.b == 212);
    CHECK(cpu.reg.c == 55);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 188);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 116);
    CHECK(cpu.reg.l == 90);
    CHECK(cpu.reg.pc == 29575);
    // CHECK(cpu.reg.sp == 53700);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29574] == 0);
}

TEST_CASE( "00 0377", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47519;
    cpu.reg.sp = 46596;
    cpu.reg.a = 220;
    cpu.reg.b = 72;
    cpu.reg.c = 9;
    cpu.reg.d = 153;
    cpu.reg.e = 74;
    cpu.reg.f = 224;
    cpu.reg.h = 145;
    cpu.reg.l = 70;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[47519] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 220);
    CHECK(cpu.reg.b == 72);
    CHECK(cpu.reg.c == 9);
    CHECK(cpu.reg.d == 153);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 145);
    CHECK(cpu.reg.l == 70);
    CHECK(cpu.reg.pc == 47520);
    // CHECK(cpu.reg.sp == 46596);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[47519] == 0);
}

TEST_CASE( "00 0378", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26321;
    cpu.reg.sp = 20513;
    cpu.reg.a = 67;
    cpu.reg.b = 243;
    cpu.reg.c = 210;
    cpu.reg.d = 213;
    cpu.reg.e = 169;
    cpu.reg.f = 32;
    cpu.reg.h = 145;
    cpu.reg.l = 166;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[26321] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 67);
    CHECK(cpu.reg.b == 243);
    CHECK(cpu.reg.c == 210);
    CHECK(cpu.reg.d == 213);
    CHECK(cpu.reg.e == 169);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 145);
    CHECK(cpu.reg.l == 166);
    CHECK(cpu.reg.pc == 26322);
    // CHECK(cpu.reg.sp == 20513);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26321] == 0);
}

TEST_CASE( "00 0379", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 56566;
    cpu.reg.sp = 16221;
    cpu.reg.a = 228;
    cpu.reg.b = 101;
    cpu.reg.c = 242;
    cpu.reg.d = 197;
    cpu.reg.e = 240;
    cpu.reg.f = 208;
    cpu.reg.h = 120;
    cpu.reg.l = 157;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[56566] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 228);
    CHECK(cpu.reg.b == 101);
    CHECK(cpu.reg.c == 242);
    CHECK(cpu.reg.d == 197);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 157);
    CHECK(cpu.reg.pc == 56567);
    // CHECK(cpu.reg.sp == 16221);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[56566] == 0);
}

TEST_CASE( "00 037A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8961;
    cpu.reg.sp = 32652;
    cpu.reg.a = 135;
    cpu.reg.b = 184;
    cpu.reg.c = 207;
    cpu.reg.d = 142;
    cpu.reg.e = 24;
    cpu.reg.f = 16;
    cpu.reg.h = 75;
    cpu.reg.l = 128;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[8961] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 135);
    CHECK(cpu.reg.b == 184);
    CHECK(cpu.reg.c == 207);
    CHECK(cpu.reg.d == 142);
    CHECK(cpu.reg.e == 24);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 75);
    CHECK(cpu.reg.l == 128);
    CHECK(cpu.reg.pc == 8962);
    // CHECK(cpu.reg.sp == 32652);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8961] == 0);
}

TEST_CASE( "00 037B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54491;
    cpu.reg.sp = 33400;
    cpu.reg.a = 148;
    cpu.reg.b = 198;
    cpu.reg.c = 136;
    cpu.reg.d = 94;
    cpu.reg.e = 226;
    cpu.reg.f = 192;
    cpu.reg.h = 132;
    cpu.reg.l = 130;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[54491] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 198);
    CHECK(cpu.reg.c == 136);
    CHECK(cpu.reg.d == 94);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 132);
    CHECK(cpu.reg.l == 130);
    CHECK(cpu.reg.pc == 54492);
    // CHECK(cpu.reg.sp == 33400);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54491] == 0);
}

TEST_CASE( "00 037C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53307;
    cpu.reg.sp = 28957;
    cpu.reg.a = 194;
    cpu.reg.b = 236;
    cpu.reg.c = 174;
    cpu.reg.d = 2;
    cpu.reg.e = 251;
    cpu.reg.f = 144;
    cpu.reg.h = 140;
    cpu.reg.l = 75;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[53307] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 194);
    CHECK(cpu.reg.b == 236);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 2);
    CHECK(cpu.reg.e == 251);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 140);
    CHECK(cpu.reg.l == 75);
    CHECK(cpu.reg.pc == 53308);
    // CHECK(cpu.reg.sp == 28957);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[53307] == 0);
}

TEST_CASE( "00 037D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40991;
    cpu.reg.sp = 34664;
    cpu.reg.a = 74;
    cpu.reg.b = 195;
    cpu.reg.c = 255;
    cpu.reg.d = 56;
    cpu.reg.e = 122;
    cpu.reg.f = 160;
    cpu.reg.h = 248;
    cpu.reg.l = 252;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40991] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 74);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 255);
    CHECK(cpu.reg.d == 56);
    CHECK(cpu.reg.e == 122);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 248);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 40992);
    // CHECK(cpu.reg.sp == 34664);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40991] == 0);
}

TEST_CASE( "00 037E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 61644;
    cpu.reg.sp = 39012;
    cpu.reg.a = 148;
    cpu.reg.b = 190;
    cpu.reg.c = 196;
    cpu.reg.d = 205;
    cpu.reg.e = 174;
    cpu.reg.f = 128;
    cpu.reg.h = 131;
    cpu.reg.l = 60;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[61644] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 196);
    CHECK(cpu.reg.d == 205);
    CHECK(cpu.reg.e == 174);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 131);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 61645);
    // CHECK(cpu.reg.sp == 39012);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[61644] == 0);
}

TEST_CASE( "00 037F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49011;
    cpu.reg.sp = 6438;
    cpu.reg.a = 220;
    cpu.reg.b = 55;
    cpu.reg.c = 84;
    cpu.reg.d = 89;
    cpu.reg.e = 199;
    cpu.reg.f = 240;
    cpu.reg.h = 17;
    cpu.reg.l = 115;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[49011] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 220);
    CHECK(cpu.reg.b == 55);
    CHECK(cpu.reg.c == 84);
    CHECK(cpu.reg.d == 89);
    CHECK(cpu.reg.e == 199);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 17);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 49012);
    // CHECK(cpu.reg.sp == 6438);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49011] == 0);
}

TEST_CASE( "00 0380", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43949;
    cpu.reg.sp = 58183;
    cpu.reg.a = 109;
    cpu.reg.b = 109;
    cpu.reg.c = 61;
    cpu.reg.d = 51;
    cpu.reg.e = 139;
    cpu.reg.f = 144;
    cpu.reg.h = 47;
    cpu.reg.l = 50;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43949] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 109);
    CHECK(cpu.reg.b == 109);
    CHECK(cpu.reg.c == 61);
    CHECK(cpu.reg.d == 51);
    CHECK(cpu.reg.e == 139);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 47);
    CHECK(cpu.reg.l == 50);
    CHECK(cpu.reg.pc == 43950);
    // CHECK(cpu.reg.sp == 58183);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43949] == 0);
}

TEST_CASE( "00 0381", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29848;
    cpu.reg.sp = 44137;
    cpu.reg.a = 143;
    cpu.reg.b = 218;
    cpu.reg.c = 7;
    cpu.reg.d = 135;
    cpu.reg.e = 161;
    cpu.reg.f = 64;
    cpu.reg.h = 135;
    cpu.reg.l = 150;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29848] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 218);
    CHECK(cpu.reg.c == 7);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 161);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 135);
    CHECK(cpu.reg.l == 150);
    CHECK(cpu.reg.pc == 29849);
    // CHECK(cpu.reg.sp == 44137);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29848] == 0);
}

TEST_CASE( "00 0382", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 45099;
    cpu.reg.sp = 50322;
    cpu.reg.a = 139;
    cpu.reg.b = 231;
    cpu.reg.c = 162;
    cpu.reg.d = 187;
    cpu.reg.e = 121;
    cpu.reg.f = 16;
    cpu.reg.h = 42;
    cpu.reg.l = 1;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[45099] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 139);
    CHECK(cpu.reg.b == 231);
    CHECK(cpu.reg.c == 162);
    CHECK(cpu.reg.d == 187);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 42);
    CHECK(cpu.reg.l == 1);
    CHECK(cpu.reg.pc == 45100);
    // CHECK(cpu.reg.sp == 50322);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[45099] == 0);
}

TEST_CASE( "00 0383", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 2324;
    cpu.reg.sp = 12417;
    cpu.reg.a = 238;
    cpu.reg.b = 52;
    cpu.reg.c = 217;
    cpu.reg.d = 230;
    cpu.reg.e = 43;
    cpu.reg.f = 192;
    cpu.reg.h = 136;
    cpu.reg.l = 170;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[2324] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 238);
    CHECK(cpu.reg.b == 52);
    CHECK(cpu.reg.c == 217);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 136);
    CHECK(cpu.reg.l == 170);
    CHECK(cpu.reg.pc == 2325);
    // CHECK(cpu.reg.sp == 12417);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[2324] == 0);
}

TEST_CASE( "00 0384", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25639;
    cpu.reg.sp = 57973;
    cpu.reg.a = 189;
    cpu.reg.b = 255;
    cpu.reg.c = 195;
    cpu.reg.d = 23;
    cpu.reg.e = 81;
    cpu.reg.f = 144;
    cpu.reg.h = 153;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[25639] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 189);
    CHECK(cpu.reg.b == 255);
    CHECK(cpu.reg.c == 195);
    CHECK(cpu.reg.d == 23);
    CHECK(cpu.reg.e == 81);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 153);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 25640);
    // CHECK(cpu.reg.sp == 57973);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[25639] == 0);
}

TEST_CASE( "00 0385", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30821;
    cpu.reg.sp = 28820;
    cpu.reg.a = 192;
    cpu.reg.b = 187;
    cpu.reg.c = 105;
    cpu.reg.d = 175;
    cpu.reg.e = 250;
    cpu.reg.f = 208;
    cpu.reg.h = 144;
    cpu.reg.l = 198;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[30821] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 192);
    CHECK(cpu.reg.b == 187);
    CHECK(cpu.reg.c == 105);
    CHECK(cpu.reg.d == 175);
    CHECK(cpu.reg.e == 250);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 144);
    CHECK(cpu.reg.l == 198);
    CHECK(cpu.reg.pc == 30822);
    // CHECK(cpu.reg.sp == 28820);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30821] == 0);
}

TEST_CASE( "00 0386", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21726;
    cpu.reg.sp = 17450;
    cpu.reg.a = 169;
    cpu.reg.b = 205;
    cpu.reg.c = 139;
    cpu.reg.d = 21;
    cpu.reg.e = 53;
    cpu.reg.f = 0;
    cpu.reg.h = 20;
    cpu.reg.l = 219;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[21726] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 169);
    CHECK(cpu.reg.b == 205);
    CHECK(cpu.reg.c == 139);
    CHECK(cpu.reg.d == 21);
    CHECK(cpu.reg.e == 53);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 20);
    CHECK(cpu.reg.l == 219);
    CHECK(cpu.reg.pc == 21727);
    // CHECK(cpu.reg.sp == 17450);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21726] == 0);
}

TEST_CASE( "00 0387", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10678;
    cpu.reg.sp = 12032;
    cpu.reg.a = 78;
    cpu.reg.b = 235;
    cpu.reg.c = 17;
    cpu.reg.d = 10;
    cpu.reg.e = 47;
    cpu.reg.f = 192;
    cpu.reg.h = 227;
    cpu.reg.l = 92;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10678] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 78);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 17);
    CHECK(cpu.reg.d == 10);
    CHECK(cpu.reg.e == 47);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 227);
    CHECK(cpu.reg.l == 92);
    CHECK(cpu.reg.pc == 10679);
    // CHECK(cpu.reg.sp == 12032);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10678] == 0);
}

TEST_CASE( "00 0388", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4518;
    cpu.reg.sp = 12448;
    cpu.reg.a = 148;
    cpu.reg.b = 107;
    cpu.reg.c = 76;
    cpu.reg.d = 7;
    cpu.reg.e = 48;
    cpu.reg.f = 128;
    cpu.reg.h = 232;
    cpu.reg.l = 196;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[4518] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 76);
    CHECK(cpu.reg.d == 7);
    CHECK(cpu.reg.e == 48);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 232);
    CHECK(cpu.reg.l == 196);
    CHECK(cpu.reg.pc == 4519);
    // CHECK(cpu.reg.sp == 12448);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[4518] == 0);
}

TEST_CASE( "00 0389", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 18139;
    cpu.reg.sp = 35822;
    cpu.reg.a = 52;
    cpu.reg.b = 204;
    cpu.reg.c = 59;
    cpu.reg.d = 134;
    cpu.reg.e = 56;
    cpu.reg.f = 176;
    cpu.reg.h = 206;
    cpu.reg.l = 61;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[18139] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 52);
    CHECK(cpu.reg.b == 204);
    CHECK(cpu.reg.c == 59);
    CHECK(cpu.reg.d == 134);
    CHECK(cpu.reg.e == 56);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 61);
    CHECK(cpu.reg.pc == 18140);
    // CHECK(cpu.reg.sp == 35822);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[18139] == 0);
}

TEST_CASE( "00 038A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64284;
    cpu.reg.sp = 61675;
    cpu.reg.a = 218;
    cpu.reg.b = 63;
    cpu.reg.c = 248;
    cpu.reg.d = 244;
    cpu.reg.e = 110;
    cpu.reg.f = 176;
    cpu.reg.h = 141;
    cpu.reg.l = 236;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64284] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 218);
    CHECK(cpu.reg.b == 63);
    CHECK(cpu.reg.c == 248);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 110);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 236);
    CHECK(cpu.reg.pc == 64285);
    // CHECK(cpu.reg.sp == 61675);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64284] == 0);
}

TEST_CASE( "00 038B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12117;
    cpu.reg.sp = 39725;
    cpu.reg.a = 134;
    cpu.reg.b = 79;
    cpu.reg.c = 58;
    cpu.reg.d = 48;
    cpu.reg.e = 145;
    cpu.reg.f = 240;
    cpu.reg.h = 109;
    cpu.reg.l = 10;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[12117] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 134);
    CHECK(cpu.reg.b == 79);
    CHECK(cpu.reg.c == 58);
    CHECK(cpu.reg.d == 48);
    CHECK(cpu.reg.e == 145);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 109);
    CHECK(cpu.reg.l == 10);
    CHECK(cpu.reg.pc == 12118);
    // CHECK(cpu.reg.sp == 39725);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[12117] == 0);
}

TEST_CASE( "00 038C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52283;
    cpu.reg.sp = 53343;
    cpu.reg.a = 44;
    cpu.reg.b = 42;
    cpu.reg.c = 182;
    cpu.reg.d = 113;
    cpu.reg.e = 25;
    cpu.reg.f = 176;
    cpu.reg.h = 164;
    cpu.reg.l = 60;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[52283] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 44);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 113);
    CHECK(cpu.reg.e == 25);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 60);
    CHECK(cpu.reg.pc == 52284);
    // CHECK(cpu.reg.sp == 53343);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52283] == 0);
}

TEST_CASE( "00 038D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32673;
    cpu.reg.sp = 47110;
    cpu.reg.a = 28;
    cpu.reg.b = 129;
    cpu.reg.c = 45;
    cpu.reg.d = 130;
    cpu.reg.e = 75;
    cpu.reg.f = 224;
    cpu.reg.h = 59;
    cpu.reg.l = 139;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[32673] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 28);
    CHECK(cpu.reg.b == 129);
    CHECK(cpu.reg.c == 45);
    CHECK(cpu.reg.d == 130);
    CHECK(cpu.reg.e == 75);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 59);
    CHECK(cpu.reg.l == 139);
    CHECK(cpu.reg.pc == 32674);
    // CHECK(cpu.reg.sp == 47110);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[32673] == 0);
}

TEST_CASE( "00 038E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43569;
    cpu.reg.sp = 20722;
    cpu.reg.a = 14;
    cpu.reg.b = 65;
    cpu.reg.c = 60;
    cpu.reg.d = 96;
    cpu.reg.e = 252;
    cpu.reg.f = 96;
    cpu.reg.h = 227;
    cpu.reg.l = 51;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[43569] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 65);
    CHECK(cpu.reg.c == 60);
    CHECK(cpu.reg.d == 96);
    CHECK(cpu.reg.e == 252);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 227);
    CHECK(cpu.reg.l == 51);
    CHECK(cpu.reg.pc == 43570);
    // CHECK(cpu.reg.sp == 20722);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[43569] == 0);
}

TEST_CASE( "00 038F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13061;
    cpu.reg.sp = 27401;
    cpu.reg.a = 242;
    cpu.reg.b = 107;
    cpu.reg.c = 71;
    cpu.reg.d = 85;
    cpu.reg.e = 236;
    cpu.reg.f = 112;
    cpu.reg.h = 45;
    cpu.reg.l = 37;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[13061] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 242);
    CHECK(cpu.reg.b == 107);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 85);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 45);
    CHECK(cpu.reg.l == 37);
    CHECK(cpu.reg.pc == 13062);
    // CHECK(cpu.reg.sp == 27401);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13061] == 0);
}

TEST_CASE( "00 0390", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59656;
    cpu.reg.sp = 26212;
    cpu.reg.a = 148;
    cpu.reg.b = 89;
    cpu.reg.c = 216;
    cpu.reg.d = 73;
    cpu.reg.e = 231;
    cpu.reg.f = 0;
    cpu.reg.h = 204;
    cpu.reg.l = 42;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[59656] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 231);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 204);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 59657);
    // CHECK(cpu.reg.sp == 26212);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59656] == 0);
}

TEST_CASE( "00 0391", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21169;
    cpu.reg.sp = 58191;
    cpu.reg.a = 141;
    cpu.reg.b = 16;
    cpu.reg.c = 143;
    cpu.reg.d = 220;
    cpu.reg.e = 46;
    cpu.reg.f = 176;
    cpu.reg.h = 49;
    cpu.reg.l = 78;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21169] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 141);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 143);
    CHECK(cpu.reg.d == 220);
    CHECK(cpu.reg.e == 46);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 49);
    CHECK(cpu.reg.l == 78);
    CHECK(cpu.reg.pc == 21170);
    // CHECK(cpu.reg.sp == 58191);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21169] == 0);
}

TEST_CASE( "00 0392", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62565;
    cpu.reg.sp = 56052;
    cpu.reg.a = 193;
    cpu.reg.b = 175;
    cpu.reg.c = 250;
    cpu.reg.d = 93;
    cpu.reg.e = 226;
    cpu.reg.f = 144;
    cpu.reg.h = 139;
    cpu.reg.l = 193;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[62565] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 193);
    CHECK(cpu.reg.b == 175);
    CHECK(cpu.reg.c == 250);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 193);
    CHECK(cpu.reg.pc == 62566);
    // CHECK(cpu.reg.sp == 56052);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62565] == 0);
}

TEST_CASE( "00 0393", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41056;
    cpu.reg.sp = 6317;
    cpu.reg.a = 88;
    cpu.reg.b = 189;
    cpu.reg.c = 40;
    cpu.reg.d = 30;
    cpu.reg.e = 200;
    cpu.reg.f = 240;
    cpu.reg.h = 205;
    cpu.reg.l = 65;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[41056] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 88);
    CHECK(cpu.reg.b == 189);
    CHECK(cpu.reg.c == 40);
    CHECK(cpu.reg.d == 30);
    CHECK(cpu.reg.e == 200);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 205);
    CHECK(cpu.reg.l == 65);
    CHECK(cpu.reg.pc == 41057);
    // CHECK(cpu.reg.sp == 6317);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41056] == 0);
}

TEST_CASE( "00 0394", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3795;
    cpu.reg.sp = 4247;
    cpu.reg.a = 29;
    cpu.reg.b = 230;
    cpu.reg.c = 149;
    cpu.reg.d = 232;
    cpu.reg.e = 19;
    cpu.reg.f = 32;
    cpu.reg.h = 195;
    cpu.reg.l = 107;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[3795] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 29);
    CHECK(cpu.reg.b == 230);
    CHECK(cpu.reg.c == 149);
    CHECK(cpu.reg.d == 232);
    CHECK(cpu.reg.e == 19);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 195);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 3796);
    // CHECK(cpu.reg.sp == 4247);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[3795] == 0);
}

TEST_CASE( "00 0395", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 9436;
    cpu.reg.sp = 51328;
    cpu.reg.a = 8;
    cpu.reg.b = 202;
    cpu.reg.c = 67;
    cpu.reg.d = 193;
    cpu.reg.e = 191;
    cpu.reg.f = 160;
    cpu.reg.h = 39;
    cpu.reg.l = 182;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[9436] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 8);
    CHECK(cpu.reg.b == 202);
    CHECK(cpu.reg.c == 67);
    CHECK(cpu.reg.d == 193);
    CHECK(cpu.reg.e == 191);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 39);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 9437);
    // CHECK(cpu.reg.sp == 51328);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[9436] == 0);
}

TEST_CASE( "00 0396", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13019;
    cpu.reg.sp = 47975;
    cpu.reg.a = 109;
    cpu.reg.b = 220;
    cpu.reg.c = 0;
    cpu.reg.d = 68;
    cpu.reg.e = 58;
    cpu.reg.f = 96;
    cpu.reg.h = 205;
    cpu.reg.l = 133;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[13019] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 109);
    CHECK(cpu.reg.b == 220);
    CHECK(cpu.reg.c == 0);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 58);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 205);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 13020);
    // CHECK(cpu.reg.sp == 47975);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13019] == 0);
}

TEST_CASE( "00 0397", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43378;
    cpu.reg.sp = 11181;
    cpu.reg.a = 187;
    cpu.reg.b = 244;
    cpu.reg.c = 228;
    cpu.reg.d = 13;
    cpu.reg.e = 32;
    cpu.reg.f = 112;
    cpu.reg.h = 11;
    cpu.reg.l = 48;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[43378] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 187);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 228);
    CHECK(cpu.reg.d == 13);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 11);
    CHECK(cpu.reg.l == 48);
    CHECK(cpu.reg.pc == 43379);
    // CHECK(cpu.reg.sp == 11181);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43378] == 0);
}

TEST_CASE( "00 0398", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37722;
    cpu.reg.sp = 62203;
    cpu.reg.a = 154;
    cpu.reg.b = 89;
    cpu.reg.c = 121;
    cpu.reg.d = 167;
    cpu.reg.e = 165;
    cpu.reg.f = 16;
    cpu.reg.h = 198;
    cpu.reg.l = 34;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[37722] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 154);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 121);
    CHECK(cpu.reg.d == 167);
    CHECK(cpu.reg.e == 165);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 198);
    CHECK(cpu.reg.l == 34);
    CHECK(cpu.reg.pc == 37723);
    // CHECK(cpu.reg.sp == 62203);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37722] == 0);
}

TEST_CASE( "00 0399", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26139;
    cpu.reg.sp = 11873;
    cpu.reg.a = 75;
    cpu.reg.b = 158;
    cpu.reg.c = 203;
    cpu.reg.d = 253;
    cpu.reg.e = 185;
    cpu.reg.f = 160;
    cpu.reg.h = 179;
    cpu.reg.l = 237;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26139] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 75);
    CHECK(cpu.reg.b == 158);
    CHECK(cpu.reg.c == 203);
    CHECK(cpu.reg.d == 253);
    CHECK(cpu.reg.e == 185);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 179);
    CHECK(cpu.reg.l == 237);
    CHECK(cpu.reg.pc == 26140);
    // CHECK(cpu.reg.sp == 11873);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26139] == 0);
}

TEST_CASE( "00 039A", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25907;
    cpu.reg.sp = 6849;
    cpu.reg.a = 68;
    cpu.reg.b = 176;
    cpu.reg.c = 49;
    cpu.reg.d = 59;
    cpu.reg.e = 159;
    cpu.reg.f = 144;
    cpu.reg.h = 165;
    cpu.reg.l = 220;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[25907] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 68);
    CHECK(cpu.reg.b == 176);
    CHECK(cpu.reg.c == 49);
    CHECK(cpu.reg.d == 59);
    CHECK(cpu.reg.e == 159);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 165);
    CHECK(cpu.reg.l == 220);
    CHECK(cpu.reg.pc == 25908);
    // CHECK(cpu.reg.sp == 6849);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25907] == 0);
}

TEST_CASE( "00 039B", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 33093;
    cpu.reg.sp = 11015;
    cpu.reg.a = 31;
    cpu.reg.b = 141;
    cpu.reg.c = 108;
    cpu.reg.d = 88;
    cpu.reg.e = 161;
    cpu.reg.f = 176;
    cpu.reg.h = 206;
    cpu.reg.l = 100;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[33093] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 31);
    CHECK(cpu.reg.b == 141);
    CHECK(cpu.reg.c == 108);
    CHECK(cpu.reg.d == 88);
    CHECK(cpu.reg.e == 161);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 100);
    CHECK(cpu.reg.pc == 33094);
    // CHECK(cpu.reg.sp == 11015);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[33093] == 0);
}

TEST_CASE( "00 039C", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22412;
    cpu.reg.sp = 55989;
    cpu.reg.a = 25;
    cpu.reg.b = 23;
    cpu.reg.c = 117;
    cpu.reg.d = 172;
    cpu.reg.e = 11;
    cpu.reg.f = 64;
    cpu.reg.h = 231;
    cpu.reg.l = 9;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22412] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 25);
    CHECK(cpu.reg.b == 23);
    CHECK(cpu.reg.c == 117);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 11);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 231);
    CHECK(cpu.reg.l == 9);
    CHECK(cpu.reg.pc == 22413);
    // CHECK(cpu.reg.sp == 55989);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22412] == 0);
}

TEST_CASE( "00 039D", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49308;
    cpu.reg.sp = 29778;
    cpu.reg.a = 191;
    cpu.reg.b = 22;
    cpu.reg.c = 160;
    cpu.reg.d = 36;
    cpu.reg.e = 213;
    cpu.reg.f = 160;
    cpu.reg.h = 189;
    cpu.reg.l = 17;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49308] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 191);
    CHECK(cpu.reg.b == 22);
    CHECK(cpu.reg.c == 160);
    CHECK(cpu.reg.d == 36);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 189);
    CHECK(cpu.reg.l == 17);
    CHECK(cpu.reg.pc == 49309);
    // CHECK(cpu.reg.sp == 29778);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49308] == 0);
}

TEST_CASE( "00 039E", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 59332;
    cpu.reg.sp = 13765;
    cpu.reg.a = 48;
    cpu.reg.b = 201;
    cpu.reg.c = 155;
    cpu.reg.d = 73;
    cpu.reg.e = 33;
    cpu.reg.f = 0;
    cpu.reg.h = 170;
    cpu.reg.l = 247;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[59332] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 48);
    CHECK(cpu.reg.b == 201);
    CHECK(cpu.reg.c == 155);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 33);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 170);
    CHECK(cpu.reg.l == 247);
    CHECK(cpu.reg.pc == 59333);
    // CHECK(cpu.reg.sp == 13765);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[59332] == 0);
}

TEST_CASE( "00 039F", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 28217;
    cpu.reg.sp = 14757;
    cpu.reg.a = 243;
    cpu.reg.b = 6;
    cpu.reg.c = 183;
    cpu.reg.d = 141;
    cpu.reg.e = 54;
    cpu.reg.f = 16;
    cpu.reg.h = 107;
    cpu.reg.l = 129;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[28217] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 243);
    CHECK(cpu.reg.b == 6);
    CHECK(cpu.reg.c == 183);
    CHECK(cpu.reg.d == 141);
    CHECK(cpu.reg.e == 54);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 107);
    CHECK(cpu.reg.l == 129);
    CHECK(cpu.reg.pc == 28218);
    // CHECK(cpu.reg.sp == 14757);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[28217] == 0);
}

TEST_CASE( "00 03A0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47989;
    cpu.reg.sp = 21936;
    cpu.reg.a = 153;
    cpu.reg.b = 54;
    cpu.reg.c = 57;
    cpu.reg.d = 158;
    cpu.reg.e = 64;
    cpu.reg.f = 112;
    cpu.reg.h = 117;
    cpu.reg.l = 42;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[47989] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 153);
    CHECK(cpu.reg.b == 54);
    CHECK(cpu.reg.c == 57);
    CHECK(cpu.reg.d == 158);
    CHECK(cpu.reg.e == 64);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 117);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 47990);
    // CHECK(cpu.reg.sp == 21936);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47989] == 0);
}

TEST_CASE( "00 03A1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30400;
    cpu.reg.sp = 8816;
    cpu.reg.a = 89;
    cpu.reg.b = 127;
    cpu.reg.c = 242;
    cpu.reg.d = 189;
    cpu.reg.e = 230;
    cpu.reg.f = 112;
    cpu.reg.h = 14;
    cpu.reg.l = 42;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[30400] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 89);
    CHECK(cpu.reg.b == 127);
    CHECK(cpu.reg.c == 242);
    CHECK(cpu.reg.d == 189);
    CHECK(cpu.reg.e == 230);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 14);
    CHECK(cpu.reg.l == 42);
    CHECK(cpu.reg.pc == 30401);
    // CHECK(cpu.reg.sp == 8816);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[30400] == 0);
}

TEST_CASE( "00 03A2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 24346;
    cpu.reg.sp = 31828;
    cpu.reg.a = 118;
    cpu.reg.b = 179;
    cpu.reg.c = 29;
    cpu.reg.d = 172;
    cpu.reg.e = 89;
    cpu.reg.f = 32;
    cpu.reg.h = 44;
    cpu.reg.l = 224;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[24346] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 118);
    CHECK(cpu.reg.b == 179);
    CHECK(cpu.reg.c == 29);
    CHECK(cpu.reg.d == 172);
    CHECK(cpu.reg.e == 89);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 44);
    CHECK(cpu.reg.l == 224);
    CHECK(cpu.reg.pc == 24347);
    // CHECK(cpu.reg.sp == 31828);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[24346] == 0);
}

TEST_CASE( "00 03A3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41513;
    cpu.reg.sp = 55403;
    cpu.reg.a = 254;
    cpu.reg.b = 130;
    cpu.reg.c = 98;
    cpu.reg.d = 94;
    cpu.reg.e = 208;
    cpu.reg.f = 144;
    cpu.reg.h = 247;
    cpu.reg.l = 153;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[41513] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 254);
    CHECK(cpu.reg.b == 130);
    CHECK(cpu.reg.c == 98);
    CHECK(cpu.reg.d == 94);
    CHECK(cpu.reg.e == 208);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 153);
    CHECK(cpu.reg.pc == 41514);
    // CHECK(cpu.reg.sp == 55403);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[41513] == 0);
}

TEST_CASE( "00 03A4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 13516;
    cpu.reg.sp = 45980;
    cpu.reg.a = 180;
    cpu.reg.b = 75;
    cpu.reg.c = 93;
    cpu.reg.d = 82;
    cpu.reg.e = 215;
    cpu.reg.f = 112;
    cpu.reg.h = 245;
    cpu.reg.l = 88;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[13516] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 180);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 93);
    CHECK(cpu.reg.d == 82);
    CHECK(cpu.reg.e == 215);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 245);
    CHECK(cpu.reg.l == 88);
    CHECK(cpu.reg.pc == 13517);
    // CHECK(cpu.reg.sp == 45980);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[13516] == 0);
}

TEST_CASE( "00 03A5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22876;
    cpu.reg.sp = 62065;
    cpu.reg.a = 20;
    cpu.reg.b = 105;
    cpu.reg.c = 179;
    cpu.reg.d = 54;
    cpu.reg.e = 95;
    cpu.reg.f = 0;
    cpu.reg.h = 98;
    cpu.reg.l = 199;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22876] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 20);
    CHECK(cpu.reg.b == 105);
    CHECK(cpu.reg.c == 179);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 95);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 98);
    CHECK(cpu.reg.l == 199);
    CHECK(cpu.reg.pc == 22877);
    // CHECK(cpu.reg.sp == 62065);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22876] == 0);
}

TEST_CASE( "00 03A6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15204;
    cpu.reg.sp = 50487;
    cpu.reg.a = 181;
    cpu.reg.b = 17;
    cpu.reg.c = 48;
    cpu.reg.d = 58;
    cpu.reg.e = 228;
    cpu.reg.f = 96;
    cpu.reg.h = 17;
    cpu.reg.l = 58;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[15204] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 181);
    CHECK(cpu.reg.b == 17);
    CHECK(cpu.reg.c == 48);
    CHECK(cpu.reg.d == 58);
    CHECK(cpu.reg.e == 228);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 17);
    CHECK(cpu.reg.l == 58);
    CHECK(cpu.reg.pc == 15205);
    // CHECK(cpu.reg.sp == 50487);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[15204] == 0);
}

TEST_CASE( "00 03A7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 5981;
    cpu.reg.sp = 56992;
    cpu.reg.a = 240;
    cpu.reg.b = 75;
    cpu.reg.c = 188;
    cpu.reg.d = 76;
    cpu.reg.e = 121;
    cpu.reg.f = 64;
    cpu.reg.h = 33;
    cpu.reg.l = 218;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[5981] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 240);
    CHECK(cpu.reg.b == 75);
    CHECK(cpu.reg.c == 188);
    CHECK(cpu.reg.d == 76);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 33);
    CHECK(cpu.reg.l == 218);
    CHECK(cpu.reg.pc == 5982);
    // CHECK(cpu.reg.sp == 56992);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[5981] == 0);
}

TEST_CASE( "00 03A8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12694;
    cpu.reg.sp = 61938;
    cpu.reg.a = 110;
    cpu.reg.b = 171;
    cpu.reg.c = 11;
    cpu.reg.d = 244;
    cpu.reg.e = 40;
    cpu.reg.f = 144;
    cpu.reg.h = 26;
    cpu.reg.l = 56;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[12694] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 110);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 11);
    CHECK(cpu.reg.d == 244);
    CHECK(cpu.reg.e == 40);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 26);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 12695);
    // CHECK(cpu.reg.sp == 61938);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12694] == 0);
}

TEST_CASE( "00 03A9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 15009;
    cpu.reg.sp = 47691;
    cpu.reg.a = 1;
    cpu.reg.b = 179;
    cpu.reg.c = 220;
    cpu.reg.d = 54;
    cpu.reg.e = 183;
    cpu.reg.f = 48;
    cpu.reg.h = 228;
    cpu.reg.l = 245;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[15009] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 1);
    CHECK(cpu.reg.b == 179);
    CHECK(cpu.reg.c == 220);
    CHECK(cpu.reg.d == 54);
    CHECK(cpu.reg.e == 183);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 228);
    CHECK(cpu.reg.l == 245);
    CHECK(cpu.reg.pc == 15010);
    // CHECK(cpu.reg.sp == 47691);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[15009] == 0);
}

TEST_CASE( "00 03AA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 12190;
    cpu.reg.sp = 53779;
    cpu.reg.a = 119;
    cpu.reg.b = 223;
    cpu.reg.c = 62;
    cpu.reg.d = 79;
    cpu.reg.e = 226;
    cpu.reg.f = 48;
    cpu.reg.h = 182;
    cpu.reg.l = 47;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[12190] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 119);
    CHECK(cpu.reg.b == 223);
    CHECK(cpu.reg.c == 62);
    CHECK(cpu.reg.d == 79);
    CHECK(cpu.reg.e == 226);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 182);
    CHECK(cpu.reg.l == 47);
    CHECK(cpu.reg.pc == 12191);
    // CHECK(cpu.reg.sp == 53779);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[12190] == 0);
}

TEST_CASE( "00 03AB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29344;
    cpu.reg.sp = 44352;
    cpu.reg.a = 225;
    cpu.reg.b = 57;
    cpu.reg.c = 251;
    cpu.reg.d = 135;
    cpu.reg.e = 255;
    cpu.reg.f = 16;
    cpu.reg.h = 243;
    cpu.reg.l = 172;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[29344] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 225);
    CHECK(cpu.reg.b == 57);
    CHECK(cpu.reg.c == 251);
    CHECK(cpu.reg.d == 135);
    CHECK(cpu.reg.e == 255);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 243);
    CHECK(cpu.reg.l == 172);
    CHECK(cpu.reg.pc == 29345);
    // CHECK(cpu.reg.sp == 44352);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[29344] == 0);
}

TEST_CASE( "00 03AC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 25722;
    cpu.reg.sp = 26453;
    cpu.reg.a = 183;
    cpu.reg.b = 190;
    cpu.reg.c = 69;
    cpu.reg.d = 175;
    cpu.reg.e = 237;
    cpu.reg.f = 176;
    cpu.reg.h = 164;
    cpu.reg.l = 56;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[25722] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 183);
    CHECK(cpu.reg.b == 190);
    CHECK(cpu.reg.c == 69);
    CHECK(cpu.reg.d == 175);
    CHECK(cpu.reg.e == 237);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 164);
    CHECK(cpu.reg.l == 56);
    CHECK(cpu.reg.pc == 25723);
    // CHECK(cpu.reg.sp == 26453);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[25722] == 0);
}

TEST_CASE( "00 03AD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21164;
    cpu.reg.sp = 5684;
    cpu.reg.a = 143;
    cpu.reg.b = 224;
    cpu.reg.c = 106;
    cpu.reg.d = 243;
    cpu.reg.e = 240;
    cpu.reg.f = 48;
    cpu.reg.h = 13;
    cpu.reg.l = 114;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[21164] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 143);
    CHECK(cpu.reg.b == 224);
    CHECK(cpu.reg.c == 106);
    CHECK(cpu.reg.d == 243);
    CHECK(cpu.reg.e == 240);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 13);
    CHECK(cpu.reg.l == 114);
    CHECK(cpu.reg.pc == 21165);
    // CHECK(cpu.reg.sp == 5684);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21164] == 0);
}

TEST_CASE( "00 03AE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 29541;
    cpu.reg.sp = 59583;
    cpu.reg.a = 6;
    cpu.reg.b = 195;
    cpu.reg.c = 85;
    cpu.reg.d = 196;
    cpu.reg.e = 246;
    cpu.reg.f = 32;
    cpu.reg.h = 43;
    cpu.reg.l = 144;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[29541] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 6);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 85);
    CHECK(cpu.reg.d == 196);
    CHECK(cpu.reg.e == 246);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 43);
    CHECK(cpu.reg.l == 144);
    CHECK(cpu.reg.pc == 29542);
    // CHECK(cpu.reg.sp == 59583);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[29541] == 0);
}

TEST_CASE( "00 03AF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21469;
    cpu.reg.sp = 22308;
    cpu.reg.a = 3;
    cpu.reg.b = 196;
    cpu.reg.c = 24;
    cpu.reg.d = 201;
    cpu.reg.e = 158;
    cpu.reg.f = 80;
    cpu.reg.h = 89;
    cpu.reg.l = 229;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[21469] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 3);
    CHECK(cpu.reg.b == 196);
    CHECK(cpu.reg.c == 24);
    CHECK(cpu.reg.d == 201);
    CHECK(cpu.reg.e == 158);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 89);
    CHECK(cpu.reg.l == 229);
    CHECK(cpu.reg.pc == 21470);
    // CHECK(cpu.reg.sp == 22308);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[21469] == 0);
}

TEST_CASE( "00 03B0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4321;
    cpu.reg.sp = 60648;
    cpu.reg.a = 99;
    cpu.reg.b = 106;
    cpu.reg.c = 169;
    cpu.reg.d = 22;
    cpu.reg.e = 74;
    cpu.reg.f = 192;
    cpu.reg.h = 108;
    cpu.reg.l = 206;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4321] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 99);
    CHECK(cpu.reg.b == 106);
    CHECK(cpu.reg.c == 169);
    CHECK(cpu.reg.d == 22);
    CHECK(cpu.reg.e == 74);
    CHECK(cpu.reg.f == 192);
    CHECK(cpu.reg.h == 108);
    CHECK(cpu.reg.l == 206);
    CHECK(cpu.reg.pc == 4322);
    // CHECK(cpu.reg.sp == 60648);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4321] == 0);
}

TEST_CASE( "00 03B1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44635;
    cpu.reg.sp = 44501;
    cpu.reg.a = 208;
    cpu.reg.b = 95;
    cpu.reg.c = 91;
    cpu.reg.d = 225;
    cpu.reg.e = 238;
    cpu.reg.f = 176;
    cpu.reg.h = 100;
    cpu.reg.l = 14;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44635] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 208);
    CHECK(cpu.reg.b == 95);
    CHECK(cpu.reg.c == 91);
    CHECK(cpu.reg.d == 225);
    CHECK(cpu.reg.e == 238);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 100);
    CHECK(cpu.reg.l == 14);
    CHECK(cpu.reg.pc == 44636);
    // CHECK(cpu.reg.sp == 44501);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44635] == 0);
}

TEST_CASE( "00 03B2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 3833;
    cpu.reg.sp = 9696;
    cpu.reg.a = 96;
    cpu.reg.b = 23;
    cpu.reg.c = 52;
    cpu.reg.d = 184;
    cpu.reg.e = 17;
    cpu.reg.f = 16;
    cpu.reg.h = 162;
    cpu.reg.l = 50;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[3833] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 23);
    CHECK(cpu.reg.c == 52);
    CHECK(cpu.reg.d == 184);
    CHECK(cpu.reg.e == 17);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 162);
    CHECK(cpu.reg.l == 50);
    CHECK(cpu.reg.pc == 3834);
    // CHECK(cpu.reg.sp == 9696);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[3833] == 0);
}

TEST_CASE( "00 03B3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31821;
    cpu.reg.sp = 48930;
    cpu.reg.a = 86;
    cpu.reg.b = 170;
    cpu.reg.c = 145;
    cpu.reg.d = 31;
    cpu.reg.e = 37;
    cpu.reg.f = 224;
    cpu.reg.h = 62;
    cpu.reg.l = 157;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[31821] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 86);
    CHECK(cpu.reg.b == 170);
    CHECK(cpu.reg.c == 145);
    CHECK(cpu.reg.d == 31);
    CHECK(cpu.reg.e == 37);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 62);
    CHECK(cpu.reg.l == 157);
    CHECK(cpu.reg.pc == 31822);
    // CHECK(cpu.reg.sp == 48930);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[31821] == 0);
}

TEST_CASE( "00 03B4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 47619;
    cpu.reg.sp = 17570;
    cpu.reg.a = 140;
    cpu.reg.b = 185;
    cpu.reg.c = 249;
    cpu.reg.d = 57;
    cpu.reg.e = 213;
    cpu.reg.f = 112;
    cpu.reg.h = 144;
    cpu.reg.l = 140;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[47619] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 140);
    CHECK(cpu.reg.b == 185);
    CHECK(cpu.reg.c == 249);
    CHECK(cpu.reg.d == 57);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 144);
    CHECK(cpu.reg.l == 140);
    CHECK(cpu.reg.pc == 47620);
    // CHECK(cpu.reg.sp == 17570);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[47619] == 0);
}

TEST_CASE( "00 03B5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 43855;
    cpu.reg.sp = 19865;
    cpu.reg.a = 76;
    cpu.reg.b = 171;
    cpu.reg.c = 247;
    cpu.reg.d = 6;
    cpu.reg.e = 141;
    cpu.reg.f = 96;
    cpu.reg.h = 247;
    cpu.reg.l = 227;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[43855] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 76);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 247);
    CHECK(cpu.reg.d == 6);
    CHECK(cpu.reg.e == 141);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 227);
    CHECK(cpu.reg.pc == 43856);
    // CHECK(cpu.reg.sp == 19865);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[43855] == 0);
}

TEST_CASE( "00 03B6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49879;
    cpu.reg.sp = 18342;
    cpu.reg.a = 97;
    cpu.reg.b = 52;
    cpu.reg.c = 143;
    cpu.reg.d = 235;
    cpu.reg.e = 101;
    cpu.reg.f = 240;
    cpu.reg.h = 12;
    cpu.reg.l = 39;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49879] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 97);
    CHECK(cpu.reg.b == 52);
    CHECK(cpu.reg.c == 143);
    CHECK(cpu.reg.d == 235);
    CHECK(cpu.reg.e == 101);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 39);
    CHECK(cpu.reg.pc == 49880);
    // CHECK(cpu.reg.sp == 18342);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49879] == 0);
}

TEST_CASE( "00 03B7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37100;
    cpu.reg.sp = 10528;
    cpu.reg.a = 232;
    cpu.reg.b = 87;
    cpu.reg.c = 118;
    cpu.reg.d = 145;
    cpu.reg.e = 195;
    cpu.reg.f = 48;
    cpu.reg.h = 217;
    cpu.reg.l = 151;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[37100] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 232);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 118);
    CHECK(cpu.reg.d == 145);
    CHECK(cpu.reg.e == 195);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 217);
    CHECK(cpu.reg.l == 151);
    CHECK(cpu.reg.pc == 37101);
    // CHECK(cpu.reg.sp == 10528);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[37100] == 0);
}

TEST_CASE( "00 03B8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34054;
    cpu.reg.sp = 32249;
    cpu.reg.a = 53;
    cpu.reg.b = 70;
    cpu.reg.c = 90;
    cpu.reg.d = 78;
    cpu.reg.e = 3;
    cpu.reg.f = 176;
    cpu.reg.h = 163;
    cpu.reg.l = 227;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[34054] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 53);
    CHECK(cpu.reg.b == 70);
    CHECK(cpu.reg.c == 90);
    CHECK(cpu.reg.d == 78);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 163);
    CHECK(cpu.reg.l == 227);
    CHECK(cpu.reg.pc == 34055);
    // CHECK(cpu.reg.sp == 32249);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[34054] == 0);
}

TEST_CASE( "00 03B9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 48659;
    cpu.reg.sp = 64774;
    cpu.reg.a = 154;
    cpu.reg.b = 10;
    cpu.reg.c = 146;
    cpu.reg.d = 4;
    cpu.reg.e = 111;
    cpu.reg.f = 32;
    cpu.reg.h = 145;
    cpu.reg.l = 176;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[48659] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 154);
    CHECK(cpu.reg.b == 10);
    CHECK(cpu.reg.c == 146);
    CHECK(cpu.reg.d == 4);
    CHECK(cpu.reg.e == 111);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 145);
    CHECK(cpu.reg.l == 176);
    CHECK(cpu.reg.pc == 48660);
    // CHECK(cpu.reg.sp == 64774);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[48659] == 0);
}

TEST_CASE( "00 03BA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 57144;
    cpu.reg.sp = 31270;
    cpu.reg.a = 150;
    cpu.reg.b = 10;
    cpu.reg.c = 204;
    cpu.reg.d = 118;
    cpu.reg.e = 193;
    cpu.reg.f = 112;
    cpu.reg.h = 12;
    cpu.reg.l = 165;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[57144] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 150);
    CHECK(cpu.reg.b == 10);
    CHECK(cpu.reg.c == 204);
    CHECK(cpu.reg.d == 118);
    CHECK(cpu.reg.e == 193);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 12);
    CHECK(cpu.reg.l == 165);
    CHECK(cpu.reg.pc == 57145);
    // CHECK(cpu.reg.sp == 31270);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[57144] == 0);
}

TEST_CASE( "00 03BB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 22463;
    cpu.reg.sp = 2233;
    cpu.reg.a = 62;
    cpu.reg.b = 25;
    cpu.reg.c = 236;
    cpu.reg.d = 160;
    cpu.reg.e = 12;
    cpu.reg.f = 160;
    cpu.reg.h = 139;
    cpu.reg.l = 101;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[22463] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 62);
    CHECK(cpu.reg.b == 25);
    CHECK(cpu.reg.c == 236);
    CHECK(cpu.reg.d == 160);
    CHECK(cpu.reg.e == 12);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 139);
    CHECK(cpu.reg.l == 101);
    CHECK(cpu.reg.pc == 22464);
    // CHECK(cpu.reg.sp == 2233);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[22463] == 0);
}

TEST_CASE( "00 03BC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 55065;
    cpu.reg.sp = 25916;
    cpu.reg.a = 104;
    cpu.reg.b = 152;
    cpu.reg.c = 10;
    cpu.reg.d = 26;
    cpu.reg.e = 69;
    cpu.reg.f = 80;
    cpu.reg.h = 183;
    cpu.reg.l = 6;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[55065] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 104);
    CHECK(cpu.reg.b == 152);
    CHECK(cpu.reg.c == 10);
    CHECK(cpu.reg.d == 26);
    CHECK(cpu.reg.e == 69);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 183);
    CHECK(cpu.reg.l == 6);
    CHECK(cpu.reg.pc == 55066);
    // CHECK(cpu.reg.sp == 25916);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[55065] == 0);
}

TEST_CASE( "00 03BD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52831;
    cpu.reg.sp = 27483;
    cpu.reg.a = 14;
    cpu.reg.b = 244;
    cpu.reg.c = 3;
    cpu.reg.d = 108;
    cpu.reg.e = 149;
    cpu.reg.f = 144;
    cpu.reg.h = 25;
    cpu.reg.l = 249;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[52831] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 14);
    CHECK(cpu.reg.b == 244);
    CHECK(cpu.reg.c == 3);
    CHECK(cpu.reg.d == 108);
    CHECK(cpu.reg.e == 149);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 25);
    CHECK(cpu.reg.l == 249);
    CHECK(cpu.reg.pc == 52832);
    // CHECK(cpu.reg.sp == 27483);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[52831] == 0);
}

TEST_CASE( "00 03BE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4629;
    cpu.reg.sp = 14844;
    cpu.reg.a = 26;
    cpu.reg.b = 146;
    cpu.reg.c = 2;
    cpu.reg.d = 68;
    cpu.reg.e = 12;
    cpu.reg.f = 128;
    cpu.reg.h = 251;
    cpu.reg.l = 19;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[4629] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 26);
    CHECK(cpu.reg.b == 146);
    CHECK(cpu.reg.c == 2);
    CHECK(cpu.reg.d == 68);
    CHECK(cpu.reg.e == 12);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 251);
    CHECK(cpu.reg.l == 19);
    CHECK(cpu.reg.pc == 4630);
    // CHECK(cpu.reg.sp == 14844);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4629] == 0);
}

TEST_CASE( "00 03BF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 21679;
    cpu.reg.sp = 20937;
    cpu.reg.a = 96;
    cpu.reg.b = 219;
    cpu.reg.c = 104;
    cpu.reg.d = 20;
    cpu.reg.e = 25;
    cpu.reg.f = 32;
    cpu.reg.h = 202;
    cpu.reg.l = 160;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[21679] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 96);
    CHECK(cpu.reg.b == 219);
    CHECK(cpu.reg.c == 104);
    CHECK(cpu.reg.d == 20);
    CHECK(cpu.reg.e == 25);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 202);
    CHECK(cpu.reg.l == 160);
    CHECK(cpu.reg.pc == 21680);
    // CHECK(cpu.reg.sp == 20937);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[21679] == 0);
}

TEST_CASE( "00 03C0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 898;
    cpu.reg.sp = 62782;
    cpu.reg.a = 90;
    cpu.reg.b = 31;
    cpu.reg.c = 121;
    cpu.reg.d = 97;
    cpu.reg.e = 222;
    cpu.reg.f = 128;
    cpu.reg.h = 80;
    cpu.reg.l = 202;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[898] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 90);
    CHECK(cpu.reg.b == 31);
    CHECK(cpu.reg.c == 121);
    CHECK(cpu.reg.d == 97);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 202);
    CHECK(cpu.reg.pc == 899);
    // CHECK(cpu.reg.sp == 62782);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[898] == 0);
}

TEST_CASE( "00 03C1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1305;
    cpu.reg.sp = 16716;
    cpu.reg.a = 41;
    cpu.reg.b = 148;
    cpu.reg.c = 145;
    cpu.reg.d = 143;
    cpu.reg.e = 236;
    cpu.reg.f = 144;
    cpu.reg.h = 206;
    cpu.reg.l = 186;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[1305] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 41);
    CHECK(cpu.reg.b == 148);
    CHECK(cpu.reg.c == 145);
    CHECK(cpu.reg.d == 143);
    CHECK(cpu.reg.e == 236);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 206);
    CHECK(cpu.reg.l == 186);
    CHECK(cpu.reg.pc == 1306);
    // CHECK(cpu.reg.sp == 16716);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[1305] == 0);
}

TEST_CASE( "00 03C2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 49528;
    cpu.reg.sp = 36848;
    cpu.reg.a = 66;
    cpu.reg.b = 87;
    cpu.reg.c = 156;
    cpu.reg.d = 189;
    cpu.reg.e = 32;
    cpu.reg.f = 16;
    cpu.reg.h = 53;
    cpu.reg.l = 55;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[49528] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 66);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 156);
    CHECK(cpu.reg.d == 189);
    CHECK(cpu.reg.e == 32);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 53);
    CHECK(cpu.reg.l == 55);
    CHECK(cpu.reg.pc == 49529);
    // CHECK(cpu.reg.sp == 36848);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[49528] == 0);
}

TEST_CASE( "00 03C3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39870;
    cpu.reg.sp = 1685;
    cpu.reg.a = 220;
    cpu.reg.b = 131;
    cpu.reg.c = 111;
    cpu.reg.d = 45;
    cpu.reg.e = 121;
    cpu.reg.f = 0;
    cpu.reg.h = 125;
    cpu.reg.l = 136;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[39870] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 220);
    CHECK(cpu.reg.b == 131);
    CHECK(cpu.reg.c == 111);
    CHECK(cpu.reg.d == 45);
    CHECK(cpu.reg.e == 121);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 125);
    CHECK(cpu.reg.l == 136);
    CHECK(cpu.reg.pc == 39871);
    // CHECK(cpu.reg.sp == 1685);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[39870] == 0);
}

TEST_CASE( "00 03C4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 4215;
    cpu.reg.sp = 43417;
    cpu.reg.a = 12;
    cpu.reg.b = 180;
    cpu.reg.c = 52;
    cpu.reg.d = 97;
    cpu.reg.e = 103;
    cpu.reg.f = 80;
    cpu.reg.h = 160;
    cpu.reg.l = 228;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[4215] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 12);
    CHECK(cpu.reg.b == 180);
    CHECK(cpu.reg.c == 52);
    CHECK(cpu.reg.d == 97);
    CHECK(cpu.reg.e == 103);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 160);
    CHECK(cpu.reg.l == 228);
    CHECK(cpu.reg.pc == 4216);
    // CHECK(cpu.reg.sp == 43417);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[4215] == 0);
}

TEST_CASE( "00 03C5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54999;
    cpu.reg.sp = 862;
    cpu.reg.a = 22;
    cpu.reg.b = 223;
    cpu.reg.c = 126;
    cpu.reg.d = 37;
    cpu.reg.e = 178;
    cpu.reg.f = 32;
    cpu.reg.h = 134;
    cpu.reg.l = 41;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[54999] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 22);
    CHECK(cpu.reg.b == 223);
    CHECK(cpu.reg.c == 126);
    CHECK(cpu.reg.d == 37);
    CHECK(cpu.reg.e == 178);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 134);
    CHECK(cpu.reg.l == 41);
    CHECK(cpu.reg.pc == 55000);
    // CHECK(cpu.reg.sp == 862);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[54999] == 0);
}

TEST_CASE( "00 03C6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 37074;
    cpu.reg.sp = 50876;
    cpu.reg.a = 252;
    cpu.reg.b = 195;
    cpu.reg.c = 71;
    cpu.reg.d = 144;
    cpu.reg.e = 56;
    cpu.reg.f = 160;
    cpu.reg.h = 222;
    cpu.reg.l = 71;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[37074] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 252);
    CHECK(cpu.reg.b == 195);
    CHECK(cpu.reg.c == 71);
    CHECK(cpu.reg.d == 144);
    CHECK(cpu.reg.e == 56);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 222);
    CHECK(cpu.reg.l == 71);
    CHECK(cpu.reg.pc == 37075);
    // CHECK(cpu.reg.sp == 50876);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[37074] == 0);
}

TEST_CASE( "00 03C7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34274;
    cpu.reg.sp = 32429;
    cpu.reg.a = 230;
    cpu.reg.b = 86;
    cpu.reg.c = 6;
    cpu.reg.d = 213;
    cpu.reg.e = 6;
    cpu.reg.f = 96;
    cpu.reg.h = 226;
    cpu.reg.l = 247;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[34274] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 230);
    CHECK(cpu.reg.b == 86);
    CHECK(cpu.reg.c == 6);
    CHECK(cpu.reg.d == 213);
    CHECK(cpu.reg.e == 6);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 226);
    CHECK(cpu.reg.l == 247);
    CHECK(cpu.reg.pc == 34275);
    // CHECK(cpu.reg.sp == 32429);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34274] == 0);
}

TEST_CASE( "00 03C8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 54060;
    cpu.reg.sp = 20643;
    cpu.reg.a = 243;
    cpu.reg.b = 86;
    cpu.reg.c = 115;
    cpu.reg.d = 88;
    cpu.reg.e = 213;
    cpu.reg.f = 240;
    cpu.reg.h = 255;
    cpu.reg.l = 149;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[54060] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 243);
    CHECK(cpu.reg.b == 86);
    CHECK(cpu.reg.c == 115);
    CHECK(cpu.reg.d == 88);
    CHECK(cpu.reg.e == 213);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 255);
    CHECK(cpu.reg.l == 149);
    CHECK(cpu.reg.pc == 54061);
    // CHECK(cpu.reg.sp == 20643);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[54060] == 0);
}

TEST_CASE( "00 03C9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41481;
    cpu.reg.sp = 7281;
    cpu.reg.a = 157;
    cpu.reg.b = 170;
    cpu.reg.c = 3;
    cpu.reg.d = 73;
    cpu.reg.e = 176;
    cpu.reg.f = 32;
    cpu.reg.h = 8;
    cpu.reg.l = 118;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[41481] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 157);
    CHECK(cpu.reg.b == 170);
    CHECK(cpu.reg.c == 3);
    CHECK(cpu.reg.d == 73);
    CHECK(cpu.reg.e == 176);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 8);
    CHECK(cpu.reg.l == 118);
    CHECK(cpu.reg.pc == 41482);
    // CHECK(cpu.reg.sp == 7281);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[41481] == 0);
}

TEST_CASE( "00 03CA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17316;
    cpu.reg.sp = 63042;
    cpu.reg.a = 160;
    cpu.reg.b = 188;
    cpu.reg.c = 179;
    cpu.reg.d = 230;
    cpu.reg.e = 207;
    cpu.reg.f = 160;
    cpu.reg.h = 247;
    cpu.reg.l = 169;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17316] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 160);
    CHECK(cpu.reg.b == 188);
    CHECK(cpu.reg.c == 179);
    CHECK(cpu.reg.d == 230);
    CHECK(cpu.reg.e == 207);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 247);
    CHECK(cpu.reg.l == 169);
    CHECK(cpu.reg.pc == 17317);
    // CHECK(cpu.reg.sp == 63042);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17316] == 0);
}

TEST_CASE( "00 03CB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64319;
    cpu.reg.sp = 50007;
    cpu.reg.a = 159;
    cpu.reg.b = 87;
    cpu.reg.c = 209;
    cpu.reg.d = 110;
    cpu.reg.e = 18;
    cpu.reg.f = 224;
    cpu.reg.h = 134;
    cpu.reg.l = 59;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[64319] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 159);
    CHECK(cpu.reg.b == 87);
    CHECK(cpu.reg.c == 209);
    CHECK(cpu.reg.d == 110);
    CHECK(cpu.reg.e == 18);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 134);
    CHECK(cpu.reg.l == 59);
    CHECK(cpu.reg.pc == 64320);
    // CHECK(cpu.reg.sp == 50007);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[64319] == 0);
}

TEST_CASE( "00 03CC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16594;
    cpu.reg.sp = 22943;
    cpu.reg.a = 166;
    cpu.reg.b = 89;
    cpu.reg.c = 7;
    cpu.reg.d = 52;
    cpu.reg.e = 43;
    cpu.reg.f = 144;
    cpu.reg.h = 180;
    cpu.reg.l = 4;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[16594] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 166);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 7);
    CHECK(cpu.reg.d == 52);
    CHECK(cpu.reg.e == 43);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 180);
    CHECK(cpu.reg.l == 4);
    CHECK(cpu.reg.pc == 16595);
    // CHECK(cpu.reg.sp == 22943);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[16594] == 0);
}

TEST_CASE( "00 03CD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 17622;
    cpu.reg.sp = 36212;
    cpu.reg.a = 108;
    cpu.reg.b = 116;
    cpu.reg.c = 176;
    cpu.reg.d = 76;
    cpu.reg.e = 80;
    cpu.reg.f = 144;
    cpu.reg.h = 60;
    cpu.reg.l = 182;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[17622] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 108);
    CHECK(cpu.reg.b == 116);
    CHECK(cpu.reg.c == 176);
    CHECK(cpu.reg.d == 76);
    CHECK(cpu.reg.e == 80);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 60);
    CHECK(cpu.reg.l == 182);
    CHECK(cpu.reg.pc == 17623);
    // CHECK(cpu.reg.sp == 36212);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[17622] == 0);
}

TEST_CASE( "00 03CE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31679;
    cpu.reg.sp = 25551;
    cpu.reg.a = 93;
    cpu.reg.b = 234;
    cpu.reg.c = 220;
    cpu.reg.d = 194;
    cpu.reg.e = 160;
    cpu.reg.f = 144;
    cpu.reg.h = 23;
    cpu.reg.l = 208;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[31679] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 93);
    CHECK(cpu.reg.b == 234);
    CHECK(cpu.reg.c == 220);
    CHECK(cpu.reg.d == 194);
    CHECK(cpu.reg.e == 160);
    CHECK(cpu.reg.f == 144);
    CHECK(cpu.reg.h == 23);
    CHECK(cpu.reg.l == 208);
    CHECK(cpu.reg.pc == 31680);
    // CHECK(cpu.reg.sp == 25551);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[31679] == 0);
}

TEST_CASE( "00 03CF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 30582;
    cpu.reg.sp = 3274;
    cpu.reg.a = 239;
    cpu.reg.b = 3;
    cpu.reg.c = 81;
    cpu.reg.d = 199;
    cpu.reg.e = 238;
    cpu.reg.f = 208;
    cpu.reg.h = 189;
    cpu.reg.l = 19;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[30582] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 239);
    CHECK(cpu.reg.b == 3);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 199);
    CHECK(cpu.reg.e == 238);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 189);
    CHECK(cpu.reg.l == 19);
    CHECK(cpu.reg.pc == 30583);
    // CHECK(cpu.reg.sp == 3274);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[30582] == 0);
}

TEST_CASE( "00 03D0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 62085;
    cpu.reg.sp = 46500;
    cpu.reg.a = 117;
    cpu.reg.b = 187;
    cpu.reg.c = 182;
    cpu.reg.d = 33;
    cpu.reg.e = 211;
    cpu.reg.f = 0;
    cpu.reg.h = 127;
    cpu.reg.l = 10;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[62085] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 117);
    CHECK(cpu.reg.b == 187);
    CHECK(cpu.reg.c == 182);
    CHECK(cpu.reg.d == 33);
    CHECK(cpu.reg.e == 211);
    CHECK(cpu.reg.f == 0);
    CHECK(cpu.reg.h == 127);
    CHECK(cpu.reg.l == 10);
    CHECK(cpu.reg.pc == 62086);
    // CHECK(cpu.reg.sp == 46500);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[62085] == 0);
}

TEST_CASE( "00 03D1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32228;
    cpu.reg.sp = 24818;
    cpu.reg.a = 251;
    cpu.reg.b = 11;
    cpu.reg.c = 28;
    cpu.reg.d = 168;
    cpu.reg.e = 125;
    cpu.reg.f = 96;
    cpu.reg.h = 48;
    cpu.reg.l = 197;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32228] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 251);
    CHECK(cpu.reg.b == 11);
    CHECK(cpu.reg.c == 28);
    CHECK(cpu.reg.d == 168);
    CHECK(cpu.reg.e == 125);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 48);
    CHECK(cpu.reg.l == 197);
    CHECK(cpu.reg.pc == 32229);
    // CHECK(cpu.reg.sp == 24818);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32228] == 0);
}

TEST_CASE( "00 03D2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16125;
    cpu.reg.sp = 48476;
    cpu.reg.a = 69;
    cpu.reg.b = 217;
    cpu.reg.c = 122;
    cpu.reg.d = 35;
    cpu.reg.e = 85;
    cpu.reg.f = 208;
    cpu.reg.h = 218;
    cpu.reg.l = 75;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[16125] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 69);
    CHECK(cpu.reg.b == 217);
    CHECK(cpu.reg.c == 122);
    CHECK(cpu.reg.d == 35);
    CHECK(cpu.reg.e == 85);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 218);
    CHECK(cpu.reg.l == 75);
    CHECK(cpu.reg.pc == 16126);
    // CHECK(cpu.reg.sp == 48476);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16125] == 0);
}

TEST_CASE( "00 03D3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 41871;
    cpu.reg.sp = 34984;
    cpu.reg.a = 246;
    cpu.reg.b = 16;
    cpu.reg.c = 16;
    cpu.reg.d = 41;
    cpu.reg.e = 177;
    cpu.reg.f = 208;
    cpu.reg.h = 222;
    cpu.reg.l = 168;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[41871] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 246);
    CHECK(cpu.reg.b == 16);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 41);
    CHECK(cpu.reg.e == 177);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 222);
    CHECK(cpu.reg.l == 168);
    CHECK(cpu.reg.pc == 41872);
    // CHECK(cpu.reg.sp == 34984);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[41871] == 0);
}

TEST_CASE( "00 03D4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26675;
    cpu.reg.sp = 59610;
    cpu.reg.a = 192;
    cpu.reg.b = 82;
    cpu.reg.c = 63;
    cpu.reg.d = 214;
    cpu.reg.e = 53;
    cpu.reg.f = 128;
    cpu.reg.h = 5;
    cpu.reg.l = 30;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26675] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 192);
    CHECK(cpu.reg.b == 82);
    CHECK(cpu.reg.c == 63);
    CHECK(cpu.reg.d == 214);
    CHECK(cpu.reg.e == 53);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 5);
    CHECK(cpu.reg.l == 30);
    CHECK(cpu.reg.pc == 26676);
    // CHECK(cpu.reg.sp == 59610);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26675] == 0);
}

TEST_CASE( "00 03D5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 34097;
    cpu.reg.sp = 63650;
    cpu.reg.a = 210;
    cpu.reg.b = 191;
    cpu.reg.c = 45;
    cpu.reg.d = 245;
    cpu.reg.e = 146;
    cpu.reg.f = 64;
    cpu.reg.h = 101;
    cpu.reg.l = 68;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[34097] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 210);
    CHECK(cpu.reg.b == 191);
    CHECK(cpu.reg.c == 45);
    CHECK(cpu.reg.d == 245);
    CHECK(cpu.reg.e == 146);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 101);
    CHECK(cpu.reg.l == 68);
    CHECK(cpu.reg.pc == 34098);
    // CHECK(cpu.reg.sp == 63650);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[34097] == 0);
}

TEST_CASE( "00 03D6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 64611;
    cpu.reg.sp = 29941;
    cpu.reg.a = 219;
    cpu.reg.b = 171;
    cpu.reg.c = 53;
    cpu.reg.d = 75;
    cpu.reg.e = 27;
    cpu.reg.f = 112;
    cpu.reg.h = 158;
    cpu.reg.l = 112;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[64611] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 219);
    CHECK(cpu.reg.b == 171);
    CHECK(cpu.reg.c == 53);
    CHECK(cpu.reg.d == 75);
    CHECK(cpu.reg.e == 27);
    CHECK(cpu.reg.f == 112);
    CHECK(cpu.reg.h == 158);
    CHECK(cpu.reg.l == 112);
    CHECK(cpu.reg.pc == 64612);
    // CHECK(cpu.reg.sp == 29941);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[64611] == 0);
}

TEST_CASE( "00 03D7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 52709;
    cpu.reg.sp = 6839;
    cpu.reg.a = 53;
    cpu.reg.b = 147;
    cpu.reg.c = 203;
    cpu.reg.d = 123;
    cpu.reg.e = 117;
    cpu.reg.f = 208;
    cpu.reg.h = 219;
    cpu.reg.l = 133;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[52709] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 53);
    CHECK(cpu.reg.b == 147);
    CHECK(cpu.reg.c == 203);
    CHECK(cpu.reg.d == 123);
    CHECK(cpu.reg.e == 117);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 219);
    CHECK(cpu.reg.l == 133);
    CHECK(cpu.reg.pc == 52710);
    // CHECK(cpu.reg.sp == 6839);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[52709] == 0);
}

TEST_CASE( "00 03D8", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 31840;
    cpu.reg.sp = 44689;
    cpu.reg.a = 63;
    cpu.reg.b = 254;
    cpu.reg.c = 16;
    cpu.reg.d = 182;
    cpu.reg.e = 219;
    cpu.reg.f = 80;
    cpu.reg.h = 16;
    cpu.reg.l = 107;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[31840] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 63);
    CHECK(cpu.reg.b == 254);
    CHECK(cpu.reg.c == 16);
    CHECK(cpu.reg.d == 182);
    CHECK(cpu.reg.e == 219);
    CHECK(cpu.reg.f == 80);
    CHECK(cpu.reg.h == 16);
    CHECK(cpu.reg.l == 107);
    CHECK(cpu.reg.pc == 31841);
    // CHECK(cpu.reg.sp == 44689);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[31840] == 0);
}

TEST_CASE( "00 03D9", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 32789;
    cpu.reg.sp = 6240;
    cpu.reg.a = 197;
    cpu.reg.b = 89;
    cpu.reg.c = 174;
    cpu.reg.d = 240;
    cpu.reg.e = 99;
    cpu.reg.f = 128;
    cpu.reg.h = 38;
    cpu.reg.l = 11;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[32789] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 89);
    CHECK(cpu.reg.c == 174);
    CHECK(cpu.reg.d == 240);
    CHECK(cpu.reg.e == 99);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 38);
    CHECK(cpu.reg.l == 11);
    CHECK(cpu.reg.pc == 32790);
    // CHECK(cpu.reg.sp == 6240);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[32789] == 0);
}

TEST_CASE( "00 03DA", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 39467;
    cpu.reg.sp = 48175;
    cpu.reg.a = 197;
    cpu.reg.b = 67;
    cpu.reg.c = 222;
    cpu.reg.d = 254;
    cpu.reg.e = 125;
    cpu.reg.f = 160;
    cpu.reg.h = 178;
    cpu.reg.l = 196;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 0;
    cpu.ram[39467] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 197);
    CHECK(cpu.reg.b == 67);
    CHECK(cpu.reg.c == 222);
    CHECK(cpu.reg.d == 254);
    CHECK(cpu.reg.e == 125);
    CHECK(cpu.reg.f == 160);
    CHECK(cpu.reg.h == 178);
    CHECK(cpu.reg.l == 196);
    CHECK(cpu.reg.pc == 39468);
    // CHECK(cpu.reg.sp == 48175);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[39467] == 0);
}

TEST_CASE( "00 03DB", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 44319;
    cpu.reg.sp = 60934;
    cpu.reg.a = 215;
    cpu.reg.b = 240;
    cpu.reg.c = 32;
    cpu.reg.d = 214;
    cpu.reg.e = 184;
    cpu.reg.f = 208;
    cpu.reg.h = 25;
    cpu.reg.l = 115;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[44319] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 215);
    CHECK(cpu.reg.b == 240);
    CHECK(cpu.reg.c == 32);
    CHECK(cpu.reg.d == 214);
    CHECK(cpu.reg.e == 184);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 25);
    CHECK(cpu.reg.l == 115);
    CHECK(cpu.reg.pc == 44320);
    // CHECK(cpu.reg.sp == 60934);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[44319] == 0);
}

TEST_CASE( "00 03DC", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40128;
    cpu.reg.sp = 14980;
    cpu.reg.a = 251;
    cpu.reg.b = 61;
    cpu.reg.c = 46;
    cpu.reg.d = 237;
    cpu.reg.e = 228;
    cpu.reg.f = 224;
    cpu.reg.h = 42;
    cpu.reg.l = 98;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40128] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 251);
    CHECK(cpu.reg.b == 61);
    CHECK(cpu.reg.c == 46);
    CHECK(cpu.reg.d == 237);
    CHECK(cpu.reg.e == 228);
    CHECK(cpu.reg.f == 224);
    CHECK(cpu.reg.h == 42);
    CHECK(cpu.reg.l == 98);
    CHECK(cpu.reg.pc == 40129);
    // CHECK(cpu.reg.sp == 14980);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40128] == 0);
}

TEST_CASE( "00 03DD", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 6874;
    cpu.reg.sp = 39991;
    cpu.reg.a = 187;
    cpu.reg.b = 210;
    cpu.reg.c = 132;
    cpu.reg.d = 124;
    cpu.reg.e = 28;
    cpu.reg.f = 128;
    cpu.reg.h = 163;
    cpu.reg.l = 214;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[6874] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 187);
    CHECK(cpu.reg.b == 210);
    CHECK(cpu.reg.c == 132);
    CHECK(cpu.reg.d == 124);
    CHECK(cpu.reg.e == 28);
    CHECK(cpu.reg.f == 128);
    CHECK(cpu.reg.h == 163);
    CHECK(cpu.reg.l == 214);
    CHECK(cpu.reg.pc == 6875);
    // CHECK(cpu.reg.sp == 39991);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[6874] == 0);
}

TEST_CASE( "00 03DE", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 40523;
    cpu.reg.sp = 18300;
    cpu.reg.a = 225;
    cpu.reg.b = 131;
    cpu.reg.c = 216;
    cpu.reg.d = 218;
    cpu.reg.e = 3;
    cpu.reg.f = 16;
    cpu.reg.h = 112;
    cpu.reg.l = 150;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[40523] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 225);
    CHECK(cpu.reg.b == 131);
    CHECK(cpu.reg.c == 216);
    CHECK(cpu.reg.d == 218);
    CHECK(cpu.reg.e == 3);
    CHECK(cpu.reg.f == 16);
    CHECK(cpu.reg.h == 112);
    CHECK(cpu.reg.l == 150);
    CHECK(cpu.reg.pc == 40524);
    // CHECK(cpu.reg.sp == 18300);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[40523] == 0);
}

TEST_CASE( "00 03DF", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 1071;
    cpu.reg.sp = 5264;
    cpu.reg.a = 119;
    cpu.reg.b = 235;
    cpu.reg.c = 58;
    cpu.reg.d = 186;
    cpu.reg.e = 39;
    cpu.reg.f = 64;
    cpu.reg.h = 238;
    cpu.reg.l = 137;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[1071] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 119);
    CHECK(cpu.reg.b == 235);
    CHECK(cpu.reg.c == 58);
    CHECK(cpu.reg.d == 186);
    CHECK(cpu.reg.e == 39);
    CHECK(cpu.reg.f == 64);
    CHECK(cpu.reg.h == 238);
    CHECK(cpu.reg.l == 137);
    CHECK(cpu.reg.pc == 1072);
    // CHECK(cpu.reg.sp == 5264);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[1071] == 0);
}

TEST_CASE( "00 03E0", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 16162;
    cpu.reg.sp = 19063;
    cpu.reg.a = 178;
    cpu.reg.b = 183;
    cpu.reg.c = 161;
    cpu.reg.d = 251;
    cpu.reg.e = 153;
    cpu.reg.f = 96;
    cpu.reg.h = 120;
    cpu.reg.l = 99;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[16162] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 178);
    CHECK(cpu.reg.b == 183);
    CHECK(cpu.reg.c == 161);
    CHECK(cpu.reg.d == 251);
    CHECK(cpu.reg.e == 153);
    CHECK(cpu.reg.f == 96);
    CHECK(cpu.reg.h == 120);
    CHECK(cpu.reg.l == 99);
    CHECK(cpu.reg.pc == 16163);
    // CHECK(cpu.reg.sp == 19063);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[16162] == 0);
}

TEST_CASE( "00 03E1", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 51992;
    cpu.reg.sp = 17775;
    cpu.reg.a = 157;
    cpu.reg.b = 42;
    cpu.reg.c = 128;
    cpu.reg.d = 95;
    cpu.reg.e = 148;
    cpu.reg.f = 240;
    cpu.reg.h = 119;
    cpu.reg.l = 31;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[51992] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 157);
    CHECK(cpu.reg.b == 42);
    CHECK(cpu.reg.c == 128);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 148);
    CHECK(cpu.reg.f == 240);
    CHECK(cpu.reg.h == 119);
    CHECK(cpu.reg.l == 31);
    CHECK(cpu.reg.pc == 51993);
    // CHECK(cpu.reg.sp == 17775);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[51992] == 0);
}

TEST_CASE( "00 03E2", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 53415;
    cpu.reg.sp = 17905;
    cpu.reg.a = 144;
    cpu.reg.b = 69;
    cpu.reg.c = 190;
    cpu.reg.d = 246;
    cpu.reg.e = 222;
    cpu.reg.f = 208;
    cpu.reg.h = 235;
    cpu.reg.l = 233;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[53415] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 144);
    CHECK(cpu.reg.b == 69);
    CHECK(cpu.reg.c == 190);
    CHECK(cpu.reg.d == 246);
    CHECK(cpu.reg.e == 222);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 235);
    CHECK(cpu.reg.l == 233);
    CHECK(cpu.reg.pc == 53416);
    // CHECK(cpu.reg.sp == 17905);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[53415] == 0);
}

TEST_CASE( "00 03E3", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 10135;
    cpu.reg.sp = 50039;
    cpu.reg.a = 148;
    cpu.reg.b = 27;
    cpu.reg.c = 252;
    cpu.reg.d = 95;
    cpu.reg.e = 1;
    cpu.reg.f = 48;
    cpu.reg.h = 99;
    cpu.reg.l = 252;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[10135] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 148);
    CHECK(cpu.reg.b == 27);
    CHECK(cpu.reg.c == 252);
    CHECK(cpu.reg.d == 95);
    CHECK(cpu.reg.e == 1);
    CHECK(cpu.reg.f == 48);
    CHECK(cpu.reg.h == 99);
    CHECK(cpu.reg.l == 252);
    CHECK(cpu.reg.pc == 10136);
    // CHECK(cpu.reg.sp == 50039);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[10135] == 0);
}

TEST_CASE( "00 03E4", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 26978;
    cpu.reg.sp = 3410;
    cpu.reg.a = 186;
    cpu.reg.b = 151;
    cpu.reg.c = 73;
    cpu.reg.d = 154;
    cpu.reg.e = 117;
    cpu.reg.f = 32;
    cpu.reg.h = 80;
    cpu.reg.l = 7;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[26978] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 186);
    CHECK(cpu.reg.b == 151);
    CHECK(cpu.reg.c == 73);
    CHECK(cpu.reg.d == 154);
    CHECK(cpu.reg.e == 117);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 80);
    CHECK(cpu.reg.l == 7);
    CHECK(cpu.reg.pc == 26979);
    // CHECK(cpu.reg.sp == 3410);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[26978] == 0);
}

TEST_CASE( "00 03E5", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 8999;
    cpu.reg.sp = 30066;
    cpu.reg.a = 60;
    cpu.reg.b = 47;
    cpu.reg.c = 81;
    cpu.reg.d = 126;
    cpu.reg.e = 211;
    cpu.reg.f = 176;
    cpu.reg.h = 141;
    cpu.reg.l = 62;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 1;
    cpu.ram[8999] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 60);
    CHECK(cpu.reg.b == 47);
    CHECK(cpu.reg.c == 81);
    CHECK(cpu.reg.d == 126);
    CHECK(cpu.reg.e == 211);
    CHECK(cpu.reg.f == 176);
    CHECK(cpu.reg.h == 141);
    CHECK(cpu.reg.l == 62);
    CHECK(cpu.reg.pc == 9000);
    // CHECK(cpu.reg.sp == 30066);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[8999] == 0);
}

TEST_CASE( "00 03E6", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 63500;
    cpu.reg.sp = 35382;
    cpu.reg.a = 120;
    cpu.reg.b = 200;
    cpu.reg.c = 243;
    cpu.reg.d = 3;
    cpu.reg.e = 133;
    cpu.reg.f = 208;
    cpu.reg.h = 5;
    cpu.reg.l = 16;
    // cpu.reg.ime = 1;
    // cpu.reg.ie = 0;
    cpu.ram[63500] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 120);
    CHECK(cpu.reg.b == 200);
    CHECK(cpu.reg.c == 243);
    CHECK(cpu.reg.d == 3);
    CHECK(cpu.reg.e == 133);
    CHECK(cpu.reg.f == 208);
    CHECK(cpu.reg.h == 5);
    CHECK(cpu.reg.l == 16);
    CHECK(cpu.reg.pc == 63501);
    // CHECK(cpu.reg.sp == 35382);
    // CHECK(cpu.reg.ime == 1);
    REQUIRE(cpu.ram[63500] == 0);
}

TEST_CASE( "00 03E7", "00" ) {
    // Setup
    Cpu cpu;
    cpu.reg.pc = 7103;
    cpu.reg.sp = 25468;
    cpu.reg.a = 216;
    cpu.reg.b = 182;
    cpu.reg.c = 160;
    cpu.reg.d = 93;
    cpu.reg.e = 127;
    cpu.reg.f = 32;
    cpu.reg.h = 134;
    cpu.reg.l = 222;
    // cpu.reg.ime = 0;
    // cpu.reg.ie = 1;
    cpu.ram[7103] = 0;

    // Act
    cpu.Step();

    // Assert
    CHECK(cpu.reg.a == 216);
    CHECK(cpu.reg.b == 182);
    CHECK(cpu.reg.c == 160);
    CHECK(cpu.reg.d == 93);
    CHECK(cpu.reg.e == 127);
    CHECK(cpu.reg.f == 32);
    CHECK(cpu.reg.h == 134);
    CHECK(cpu.reg.l == 222);
    CHECK(cpu.reg.pc == 7104);
    // CHECK(cpu.reg.sp == 25468);
    // CHECK(cpu.reg.ime == 0);
    REQUIRE(cpu.ram[7103] == 0);
}
