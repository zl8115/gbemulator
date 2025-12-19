#pragma once

#include "detail/memory/mapped_memory_block.h"
#include "detail/memory/mapped_register.h"

#include <functional>

namespace detail {

template<uint16_t N>
class CatridgeMemoryBlockController:
    public MappedMemoryBlock<N>
{
public:
    CatridgeMemoryBlockController(
        MemoryBlock<N>& memoryBlock,
        uint16_t offset,
        std::function<bool(uint16_t, uint8_t)> notifyFunc)
    :
        MappedMemoryBlock<N>(memoryBlock, offset),
        m_handleFunc(notifyFunc)
    {}

    CatridgeMemoryBlockController(
        std::vector<uint8_t>& memoryBlock,
        uint16_t offset,
        std::function<bool(uint16_t address, uint8_t value)> notifyFunc)
    :
        MappedMemoryBlock<N>(memoryBlock, offset),
        m_handleFunc(notifyFunc)
    {}

    void Write(uint16_t relativeAddress, uint8_t byte) override
    {
        if (m_handleFunc(relativeAddress, byte))
        {
            MappedMemoryBlock<N>::Write(relativeAddress, byte);
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
