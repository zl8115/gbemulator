#pragma once

#include "mmu_mapped_memory.h"

#include <functional>

namespace detail {

class CatridgeMemoryBlockController:
    public MappedMemoryBlock
{
public:
    template<std::size_t N>
    CatridgeMemoryBlockController(
        MemoryBlock<N>& memoryBlock,
        uint16_t offset,
        uint16_t count,
        std::function<bool(uint16_t, uint8_t)> notifyFunc)
    :
        MappedMemoryBlock(memoryBlock, offset, count),
        m_handleFunc(notifyFunc)
    {}

    CatridgeMemoryBlockController(
        std::vector<uint8_t>& memoryBlock,
        uint16_t offset,
        uint16_t count,
        std::function<bool(uint16_t address, uint8_t value)> notifyFunc)
    :
        MappedMemoryBlock(memoryBlock, offset, count),
        m_handleFunc(notifyFunc)
    {}

    void Write(uint16_t relativeAddress, uint8_t byte) override
    {
        if (m_handleFunc(relativeAddress, byte))
        {
            MappedMemoryBlock::Write(relativeAddress, byte);
        }
    };

private:
    std::function<bool(uint16_t, uint8_t)> m_handleFunc;
};

class CatridgeBootRomRegister:
    public MappedRegister
{
public:
    CatridgeBootRomRegister(MappedRegister&& mappedReg, std::function<bool(uint8_t)> handleFunc):
        MappedRegister(std::forward<MappedRegister&&>(mappedReg)),
        m_handleFunc(handleFunc)
    {}

    void Write(uint8_t byte) override
    {
        if (m_handleFunc(byte))
        {
            MappedRegister::Write(byte);
        }
    }

private:
    std::function<bool(uint8_t)> m_handleFunc;
};

} // namespace detail
