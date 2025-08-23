#include <stdint.h>
#include <memory.h>

class MemoryBus
{
public:
    MemoryBus();

    uint8_t ReadByte(uint16_t address);

private:
    uint8_t m_memory[0xFFFF];
};
