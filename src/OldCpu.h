#include <stdint.h>
#include <ostream>
#include <utility>

#include "Registers.h"
#include "MemoryBus.h"

class OldCPU
{
public:
    enum class Instruction
    {
        INVALID = 0,
        ADD = 1,
        INC,
        LD,
        RLC
    };

    enum JumpTest: uint8_t
    {
        NotZero,
        Zero,
        NotCarry,
        Carry,
        Always
    };

    uint8_t Execute(Instruction instruction, uint8_t target);
    uint8_t Execute(uint8_t opcode);

    void Step();

    // std::function<uint8_t(void)> InstructionFromByte(uint8_t byte);
    std::pair<Instruction, Registers::Target> InstructionFromByte(uint8_t byte);

    friend std::ostream& operator<<(std::ostream&, OldCPU const& cpu);

    // static constexpr char ArithmeticTarget[] = {'A', 'B', 'C', 'D', 'E', 'G', 'H'};

private:
    // std::function<uint8_t(void)> PrefixedInstructionFromByte(uint8_t byte);
    // std::function<uint8_t(void)> UnprefixedInstructionFromByte(uint8_t byte);

    uint8_t Add(Registers::Target target, uint8_t value);
    uint8_t Load(Registers::Target source, Registers::Target target);

    // uint8_t Add(uint8_t value);
    uint8_t Jump(JumpTest jumpTest);

    uint8_t ReadFromReg(Registers::Target target);

    uint8_t m_pc; // Program Counter
    Registers m_reg;
    MemoryBus m_bus;
};
