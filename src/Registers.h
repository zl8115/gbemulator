#pragma once

#include <cstdint>
#include <limits>
#include <stdint.h>

class Registers
{
public:
    enum Flags: uint8_t
    {
        CARRY_FLAG      = 0x10,
        HALF_CARRY_FLAG = 0x20,
        NEGATE_FLAG     = 0x40,
        ZERO_FLAG       = 0x80,
        ALL             = 0xF0
    };

    enum Target: uint8_t
    {
        INVALID = std::numeric_limits<uint8_t>::max(),
        NONE = 0,

        // Single Registers
        A, B, C, D, E, H, L,

        // Large Registers
        BC, DE, HL,

        // Load Targets
        D8,

        // Extra
        N,
        BN,
        NN,
        SP,
        SPe,
        HLP,
        HLM,

        eJ,

        // END
        // TARGETS_END
    };
    
    // enum LoadTargets: uint8_t
    // {
    //     LOAD_TARGETS_START = TARGETS_END, // Dud Enum
    //     A_B, A_C, A_D, A_E, A_H, A_L,
    //     B_A, B_C, B_D, B_E, B_H, B_L,
    //     C_A, C_B, C_D, C_E, C_H, C_L,
    //     D_A, D_B, D_C, D_E, D_H, D_L,
    //     E_A, E_B, E_C, E_D, E_H, E_L,
    //     H_A, H_B, H_C, H_D, H_E, H_L,
    //     L_A, L_B, L_C, L_D, L_E, L_H,
    //     D8_A, D8_B, D8_C, D8_D, D8_E, D8_H, D8_L,
    //     HLI_A, HLI_B, HLI_C, HLI_D, HLI_E,
    // };

    Registers();

    uint8_t a;
    uint8_t f;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;

    bool HasFlag(Flags flag) const;

    const uint8_t Get(Target target) const;
    const uint16_t GetDouble(Target target) const;

    void Set(Target target, uint8_t value);
    void SetDouble(Target target, uint16_t value);
};

