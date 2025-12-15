#pragma once

#include <array>
#include <string>

static const std::array<std::string, 0x100> OpCodeNames = {
    "NOP",             // 0x00
    "LD BC,nn",        // 0x01
    "LD (BC),A",       // 0x02
    "INC BC",          // 0x03
    "INC B",           // 0x04
    "DEC B",           // 0x05
    "LD B,n",          // 0x06
    "RLCA",            // 0x07
    "LD (nn),SP",      // 0x08
    "ADD HL,BC",       // 0x09
    "LD A,(BC)",       // 0x0A
    "DEC BC",          // 0x0B
    "INC C",           // 0x0C
    "DEC C",           // 0x0D
    "LD C,n",          // 0x0E
    "RRCA",            // 0x0F

    "STOP",            // 0x10
    "LD DE,nn",        // 0x11
    "LD (DE),A",       // 0x12
    "INC DE",          // 0x13
    "INC D",           // 0x14
    "DEC D",           // 0x15
    "LD D,n",          // 0x16
    "RLA",             // 0x17
    "JR n",            // 0x18
    "ADD HL,DE",       // 0x19
    "LD A,(DE)",       // 0x1A
    "DEC DE",          // 0x1B
    "INC E",           // 0x1C
    "DEC E",           // 0x1D
    "LD E,n",          // 0x1E
    "RRA",             // 0x1F

    "JR NZ,n",         // 0x20
    "LD HL,nn",        // 0x21
    "LD (HL+),A",      // 0x22
    "INC HL",          // 0x23
    "INC H",           // 0x24
    "DEC H",           // 0x25
    "LD H,n",          // 0x26
    "DAA",             // 0x27
    "JR Z,n",          // 0x28
    "ADD HL,HL",       // 0x29
    "LD A,(HLI)",      // 0x2A
    "DEC HL",          // 0x2B
    "INC L",           // 0x2C
    "DEC L",           // 0x2D
    "LD L,n",          // 0x2E
    "CPL",             // 0x2F

    "JR NC,n",         // 0x30
    "LD SP,nn",        // 0x31
    "LD (HL-),A",      // 0x32
    "INC SP",          // 0x33
    "INC (HL)",        // 0x34
    "DEC (HL)",        // 0x35
    "LD (HL),n",       // 0x36
    "SCF",             // 0x37
    "JR C,n",          // 0x38
    "ADD HL,SP",       // 0x39
    "LD A,(HLD)",      // 0x3A
    "DEC SP",          // 0x3B
    "INC A",           // 0x3C
    "DEC A",           // 0x3D
    "LDA,n",           // 0x3E
    "CCF",             // 0x3F

    "LD B,B",          // 0x40
    "LD B,C",          // 0x41
    "LD B,D",          // 0x42
    "LD B,E",          // 0x43
    "LD B,H",          // 0x44
    "LD B,L",          // 0x45
    "LD B,(HL)",       // 0x46
    "LD B,A",          // 0x47
    "LD C,B",          // 0x48
    "LD C,C",          // 0x49
    "LD C,D",          // 0x4A
    "LD C,E",          // 0x4B
    "LD C,H",          // 0x4C
    "LD C,L",          // 0x4D
    "LD C,(HL)",       // 0x4E
    "LD C,A",          // 0x4F

    "LD D,B",          // 0x50
    "LD D,C",          // 0x51
    "LD D,D",          // 0x52
    "LD D,E",          // 0x53
    "LD D,H",          // 0x54
    "LD D,L",          // 0x55
    "LD D,(HL)",       // 0x56
    "LD D,A",          // 0x57
    "LD E,B",          // 0x58
    "LD E,C",          // 0x59
    "LD E,D",          // 0x5A
    "LD E,E",          // 0x5B
    "LD E,H",          // 0x5C
    "LD E,L",          // 0x5D
    "LD E,(HL)",       // 0x5E
    "LD E,A",          // 0x5F

    "LD H,B",          // 0x60
    "LD H,C",          // 0x61
    "LD H,D",          // 0x62
    "LD H,E",          // 0x63
    "LD H,H",          // 0x64
    "LD H,L",          // 0x65
    "LD H,(HL)",       // 0x66
    "LD H,A",          // 0x67
    "LD L,B",          // 0x68
    "LD L,C",          // 0x69
    "LD L,D",          // 0x6A
    "LD L,E",          // 0x6B
    "LD L,H",          // 0x6C
    "LD L,L",          // 0x6D
    "LD L,(HL)",       // 0x6E
    "LD L,A",          // 0x6F

    "LD (HL),B",       // 0x70
    "LD (HL),C",       // 0x71
    "LD (HL),D",       // 0x72
    "LD (HL),E",       // 0x73
    "LD (HL),H",       // 0x74
    "LD (HL),L",       // 0x75
    "HALT",            // 0x76
    "LD (HL),A",       // 0x77
    "LD A,B",          // 0x78
    "LD A,C",          // 0x79
    "LD A,D",          // 0x7A
    "LD A,E",          // 0x7B
    "LD A,H",          // 0x7C
    "LD A,L",          // 0x7D
    "LD A,(HL)",       // 0x7E
    "LD A,A",          // 0x7F

    "ADD A,B",         // 0x80
    "ADD A,C",         // 0x81
    "ADD A,D",         // 0x82
    "ADD A,E",         // 0x83
    "ADD A,H",         // 0x84
    "ADD A,L",         // 0x85
    "ADD A,(HL)",      // 0x86
    "ADD A,A",         // 0x87
    "ADC A,B",         // 0x88
    "ADC A,C",         // 0x89
    "ADC A,D",         // 0x8A
    "ADC A,E",         // 0x8B
    "ADC A,H",         // 0x8C
    "ADC A,L",         // 0x8D
    "ADC A,(HL)",      // 0x8E
    "ADC A,A",         // 0x8F

    "SUB B",           // 0x90
    "SUB C",           // 0x91
    "SUB D",           // 0x92
    "SUB E",           // 0x93
    "SUB H",           // 0x94
    "SUB L",           // 0x95
    "SUB (HL)",        // 0x96
    "SUB A",           // 0x97
    "SBC A,B",         // 0x98
    "SBC A,C",         // 0x99
    "SBC A,D",         // 0x9A
    "SBC A,E",         // 0x9B
    "SBC A,H",         // 0x9C
    "SBC A,L",         // 0x9D
    "SBC A,(HL)",      // 0x9E
    "SBC A,A",         // 0x9F

    "AND B",           // 0xA0
    "AND C",           // 0xA1
    "AND D",           // 0xA2
    "AND E",           // 0xA3
    "AND H",           // 0xA4
    "AND L",           // 0xA5
    "AND (HL)",        // 0xA6
    "AND A",           // 0xA7
    "XOR B",           // 0xA8
    "XOR C",           // 0xA9
    "XOR D",           // 0xAA
    "XOR E",           // 0xAB
    "XOR H",           // 0xAC
    "XOR L",           // 0xAD
    "XOR (HL)",        // 0xAE
    "XOR A",           // 0xAF

    "OR B",            // 0xB0
    "OR C",            // 0xB1
    "OR D",            // 0xB2
    "OR E",            // 0xB3
    "OR H",            // 0xB4
    "OR L",            // 0xB5
    "OR (HL)",         // 0xB6
    "OR A",            // 0xB7
    "CP B",            // 0xB8
    "CP C",            // 0xB9
    "CP D",            // 0xBA
    "CP E",            // 0xBB
    "CP H",            // 0xBC
    "CP L",            // 0xBD
    "CP (HL)",         // 0xBE
    "CP A",            // 0xBF

    "RET NZ",          // 0xC0
    "POP BC",          // 0xC1
    "JP NZ,nn",        // 0xC2
    "JP nn",           // 0xC3
    "CALL NZ,nn",      // 0xC4
    "PUSH BC",         // 0xC5
    "ADD A,n",         // 0xC6
    "RST ",            // 0xC7
    "RET Z",           // 0xC8
    "RET",             // 0xC9
    "JP Z,nn",         // 0xCA
    "cb opcode",       // 0xCB
    "CALL Z,nn",       // 0xCC
    "CALL nn",         // 0xCD
    "ADC A,n",         // 0xCE
    "RST 0x08",        // 0xCF

    "RET NC",          // 0xD0
    "POP DE",          // 0xD1
    "JP NC,nn",        // 0xD2
    "unused opcode",   // 0xD3
    "CALL NC,nn",      // 0xD4
    "PUSH DE",         // 0xD5
    "SUB n",           // 0xD6
    "RST 0x10",        // 0xD7
    "RET C",           // 0xD8
    "RETI",            // 0xD9
    "JP C,nn",         // 0xDA
    "unused opcode",   // 0xDB
    "CALL C,nn",       // 0xDC
    "unused opcode",   // 0xDD
    "SBC A,n",         // 0xDE
    "RST 0x18",        // 0xDF

    "LD (0xFF00+n),A", // 0xE0
    "POP HL",          // 0xE1
    "LD (0xFF00+C),A", // 0xE2
    "unused opcode",   // 0xE3
    "unused opcode",   // 0xE4
    "PUSH HL",         // 0xE5
    "AND n",           // 0xE6
    "RST 0x20",        // 0xE7
    "ADD SP,n",        // 0xE8
    "JP (HL)",         // 0xE9
    "LD (nn),A",       // 0xEA
    "unused opcode",   // 0xEB
    "unused opcode",   // 0xEC
    "unused opcode",   // 0xED
    "XOR n",           // 0xEE
    "RST 0x28",        // 0xEF

    "LD A,(0xFF00+n)", // 0xF0
    "POP AF",          // 0xF1
    "LD A,(0xFF00+C)", // 0xF2
    "DI",              // 0xF3
    "unused opcode",   // 0xF4
    "PUSH AF",         // 0xF5
    "OR n",            // 0xF6
    "RST 0x30",        // 0xF7
    "LD HL,SP",        // 0xF8
    "LD SP,HL",        // 0xF9
    "LD A,(nn)",       // 0xFA
    "EI",              // 0xFB
    "unused opcode",   // 0xFC
    "unused opcode",   // 0xFD
    "CP n",            // 0xFE
    "RST"              // 0xFF
};

static const std::array<std::string, 0x100> CbOpcodeNames = {
    "RLC B",           // cb 0x00
    "RLC C",           // cb 0x01
    "RLC D",           // cb 0x02
    "RLC E",           // cb 0x03
    "RLC H",           // cb 0x04
    "RLC L",           // cb 0x05
    "RLC (HL)",        // cb 0x06
    "RLC A",           // cb 0x07
    "RRC B",           // cb 0x08
    "RRC C",           // cb 0x09
    "RRC D",           // cb 0x0A
    "RRC E",           // cb 0x0B
    "RRC H",           // cb 0x0C
    "RRC L",           // cb 0x0D
    "RRC (HL)",        // cb 0x0E
    "RRC A",           // cb 0x0F

    "RL B",            // cb 0x10
    "RL C",            // cb 0x11
    "RL D",            // cb 0x12
    "RL E",            // cb 0x13
    "RL H",            // cb 0x14
    "RL L ",           // cb 0x15
    "RL (HL)",         // cb 0x16
    "RL A",            // cb 0x17
    "RR B",            // cb 0x18
    "RR C",            // cb 0x19
    "RR D",            // cb 0x1A
    "RR E",            // cb 0x1B
    "RR H",            // cb 0x1C
    "RR L",            // cb 0x1D
    "RR (HL)",         // cb 0x1E
    "RR A",            // cb 0x1F

    "SLA B",           // cb 0x20
    "SLA C",           // cb 0x21
    "SLA D",           // cb 0x22
    "SLA E",           // cb 0x23
    "SLA H",           // cb 0x24
    "SLA L",           // cb 0x25
    "SLA (HL)",        // cb 0x26
    "SLA A",           // cb 0x27
    "SRA B",           // cb 0x28
    "SRA C",           // cb 0x29
    "SRA D",           // cb 0x2A
    "SRA E",           // cb 0x2B
    "SRA H",           // cb 0x2C
    "SRA L",           // cb 0x2D
    "SRA (HL)",        // cb 0x2E
    "SRA A",           // cb 0x2F

    "SWAP B",          // cb 0x30
    "SWAP C",          // cb 0x31
    "SWAP D",          // cb 0x32
    "SWAP E",          // cb 0x33
    "SWAP H",          // cb 0x34
    "SWAP L",          // cb 0x35
    "SWAP (HL)",       // cb 0x36
    "SWAP A",          // cb 0x37
    "SRL B",           // cb 0x38
    "SRL C",           // cb 0x39
    "SRL D",           // cb 0x3A
    "SRL E",           // cb 0x3B
    "SRL H",           // cb 0x3C
    "SRL L",           // cb 0x3D
    "SRL (HL)",        // cb 0x3E
    "SRL A",           // cb 0x3F

    "BIT 0 B",         // cb 0x40
    "BIT 0 C",         // cb 0x41
    "BIT 0 D",         // cb 0x42
    "BIT 0 E",         // cb 0x43
    "BIT 0 H",         // cb 0x44
    "BIT 0 L",         // cb 0x45
    "BIT 0 (HL)",      // cb 0x46
    "BIT 0 A",         // cb 0x47
    "BIT 1 B",         // cb 0x48
    "BIT 1 C",         // cb 0x49
    "BIT 1 D",         // cb 0x4A
    "BIT 1 E",         // cb 0x4B
    "BIT 1 H",         // cb 0x4C
    "BIT 1 L",         // cb 0x4D
    "BIT 1 (HL)",      // cb 0x4E
    "BIT 1 A",         // cb 0x4F

    "BIT 2 B",         // cb 0x50
    "BIT 2 C",         // cb 0x51
    "BIT 2 D",         // cb 0x52
    "BIT 2 E",         // cb 0x53
    "BIT 2 H",         // cb 0x54
    "BIT 2 L",         // cb 0x55
    "BIT 2 (HL)",      // cb 0x56
    "BIT 2 A",         // cb 0x57
    "BIT 3 B",         // cb 0x58
    "BIT 3 C",         // cb 0x59
    "BIT 3 D",         // cb 0x5A
    "BIT 3 E",         // cb 0x5B
    "BIT 3 H",         // cb 0x5C
    "BIT 3 L",         // cb 0x5D
    "BIT 3 (HL)",      // cb 0x5E
    "BIT 3 A",         // cb 0x5F

    "BIT 4 B",         // cb 0x60
    "BIT 4 C",         // cb 0x61
    "BIT 4 D",         // cb 0x62
    "BIT 4 E",         // cb 0x63
    "BIT 4 H",         // cb 0x64
    "BIT 4 L",         // cb 0x65
    "BIT 4 (HL)",      // cb 0x66
    "BIT 4 A",         // cb 0x67
    "BIT 5 B",         // cb 0x68
    "BIT 5 C",         // cb 0x69
    "BIT 5 D",         // cb 0x6A
    "BIT 5 E",         // cb 0x6B
    "BIT 5 H",         // cb 0x6C
    "BIT 5 L",         // cb 0x6D
    "BIT 5 (HL)",      // cb 0x6E
    "BIT 5 A",         // cb 0x6F

    "BIT 6 B",         // cb 0x70
    "BIT 6 C",         // cb 0x71
    "BIT 6 D",         // cb 0x72
    "BIT 6 E",         // cb 0x73
    "BIT 6 H",         // cb 0x74
    "BIT 6 L",         // cb 0x75
    "BIT 6 (HL)",      // cb 0x76
    "BIT 6 A",         // cb 0x77
    "BIT 7 B",         // cb 0x78
    "BIT 7 C",         // cb 0x79
    "BIT 7 D",         // cb 0x7A
    "BIT 7 E",         // cb 0x7B
    "BIT 7 H",         // cb 0x7C
    "BIT 7 L",         // cb 0x7D
    "BIT 7 (HL)",      // cb 0x7E
    "BIT 7 A",         // cb 0x7F

    "RES 0 B",         // cb 0x80
    "RES 0 C",         // cb 0x81
    "RES 0 D",         // cb 0x82
    "RES 0 E",         // cb 0x83
    "RES 0 H",         // cb 0x84
    "RES 0 L",         // cb 0x85
    "RES 0 (HL)",      // cb 0x86
    "RES 0 A",         // cb 0x87
    "RES 1 B",         // cb 0x88
    "RES 1 C",         // cb 0x89
    "RES 1 D",         // cb 0x8A
    "RES 1 E",         // cb 0x8B
    "RES 1 H",         // cb 0x8C
    "RES 1 L",         // cb 0x8D
    "RES 1 (HL)",      // cb 0x8E
    "RES 1 A",         // cb 0x8F

    "RES 2 B",         // cb 0x90
    "RES 2 C",         // cb 0x91
    "RES 2 D",         // cb 0x92
    "RES 2 E",         // cb 0x93
    "RES 2 H",         // cb 0x94
    "RES 2 L",         // cb 0x95
    "RES 2 (HL)",      // cb 0x96
    "RES 2 A",         // cb 0x97
    "RES 3 B",         // cb 0x98
    "RES 3 C",         // cb 0x99
    "RES 3 D",         // cb 0x9A
    "RES 3 E",         // cb 0x9B
    "RES 3 H",         // cb 0x9C
    "RES 3 L",         // cb 0x9D
    "RES 3 (HL)",      // cb 0x9E
    "RES 3 A",         // cb 0x9F

    "RES 4 B",         // cb 0xA0
    "RES 4 C",         // cb 0xA1
    "RES 4 D",         // cb 0xA2
    "RES 4 E",         // cb 0xA3
    "RES 4 H",         // cb 0xA4
    "RES 4 L",         // cb 0xA5
    "RES 4 (HL)",      // cb 0xA6
    "RES 4 A",         // cb 0xA7
    "RES 5 B",         // cb 0xA8
    "RES 5 C",         // cb 0xA9
    "RES 5 D",         // cb 0xAA
    "RES 5 E",         // cb 0xAB
    "RES 5 H",         // cb 0xAC
    "RES 5 L",         // cb 0xAD
    "RES 5 (HL)",      // cb 0xAE
    "RES 5 A",         // cb 0xAF

    "RES 6 B",         // cb 0xB0
    "RES 6 C",         // cb 0xB1
    "RES 6 D",         // cb 0xB2
    "RES 6 E",         // cb 0xB3
    "RES 6 H",         // cb 0xB4
    "RES 6 L",         // cb 0xB5
    "RES 6 (HL)",      // cb 0xB6
    "RES 6 A",         // cb 0xB7
    "RES 7 B",         // cb 0xB8
    "RES 7 C",         // cb 0xB9
    "RES 7 D",         // cb 0xBA
    "RES 7 E",         // cb 0xBB
    "RES 7 H",         // cb 0xBC
    "RES 7 L",         // cb 0xBD
    "RES 7 (HL)",      // cb 0xBE
    "RES 7 A",         // cb 0xBF

    "SET 0 B",         // cb 0xC0
    "SET 0 C",         // cb 0xC1
    "SET 0 D",         // cb 0xC2
    "SET 0 E",         // cb 0xC3
    "SET 0 H",         // cb 0xC4
    "SET 0 L",         // cb 0xC5
    "SET 0 (HL)",      // cb 0xC6
    "SET 0 A",         // cb 0xC7
    "SET 1 B",         // cb 0xC8
    "SET 1 C",         // cb 0xC9
    "SET 1 D",         // cb 0xCA
    "SET 1 E",         // cb 0xCB
    "SET 1 H",         // cb 0xCC
    "SET 1 L",         // cb 0xCD
    "SET 1 (HL)",      // cb 0xCE
    "SET 1 A",         // cb 0xCF

    "SET 2 B",         // cb 0xD0
    "SET 2 C",         // cb 0xD1
    "SET 2 D",         // cb 0xD2
    "SET 2 E",         // cb 0xD3
    "SET 2 H",         // cb 0xD4
    "SET 2 L",         // cb 0xD5
    "SET 2 (HL)",      // cb 0xD6
    "SET 2 A",         // cb 0xD7
    "SET 3 B",         // cb 0xD8
    "SET 3 C",         // cb 0xD9
    "SET 3 D",         // cb 0xDA
    "SET 3 E",         // cb 0xDB
    "SET 3 H",         // cb 0xDC
    "SET 3 L",         // cb 0xDD
    "SET 3 (HL)",      // cb 0xDE
    "SET 3 A",         // cb 0xDF

    "SET 4 B",         // cb 0xE0
    "SET 4 C",         // cb 0xE1
    "SET 4 D",         // cb 0xE2
    "SET 4 E",         // cb 0xE3
    "SET 4 H",         // cb 0xE4
    "SET 4 L",         // cb 0xE5
    "SET 4 (HL)",      // cb 0xE6
    "SET 4 A",         // cb 0xE7
    "SET 5 B",         // cb 0xE8
    "SET 5 C",         // cb 0xE9
    "SET 5 D",         // cb 0xEA
    "SET 5 E",         // cb 0xEB
    "SET 5 H",         // cb 0xEC
    "SET 5 L",         // cb 0xED
    "SET 5 (HL)",      // cb 0xEE
    "SET 5 A",         // cb 0xEF

    "SET 6 B",         // cb 0xF0
    "SET 6 C",         // cb 0xF1
    "SET 6 D",         // cb 0xF2
    "SET 6 E",         // cb 0xF3
    "SET 6 H",         // cb 0xF4
    "SET 6 L",         // cb 0xF5
    "SET 6 (HL)",      // cb 0xF6
    "SET 6 A",         // cb 0xF7
    "SET 7 B",         // cb 0xF8
    "SET 7 C",         // cb 0xF9
    "SET 7 D",         // cb 0xFA
    "SET 7 E",         // cb 0xFB
    "SET 7 H",         // cb 0xFC
    "SET 7 L",         // cb 0xFD
    "SET 7 (HL)",      // cb 0xFE
    "SET 7 A",         // cb 0xFF
};
