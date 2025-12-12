#pragma once

#include <cstdint>

#include <stdexcept>
#include <span>
#include <array>
#include <memory>
#include <vector>

namespace detail {

template<std::size_t N>
using MemoryBlock = std::array<uint8_t, N>;

class MappedRegister
{
public:
    MappedRegister(uint8_t& reg):
        m_reg(reg)
    {}

    uint8_t Read() const { return m_reg; }
    virtual void Write(uint8_t byte) { m_reg = byte; };

private:
    uint8_t& m_reg;
};

class MappedMemoryBlock
{
public:
    template<std::size_t N>
    MappedMemoryBlock(MemoryBlock<N>& memoryBlock, uint16_t offset, uint16_t count):
        m_region(memoryBlock.begin() + offset, memoryBlock.begin() + offset + count)
    {}

    MappedMemoryBlock(std::vector<uint8_t>& memoryBlock, uint16_t offset, uint16_t count):
        m_region(memoryBlock.begin() + offset, memoryBlock.begin() + offset + count)
    {}

    uint8_t Read(uint16_t relativeAddress) const
    {
        if (relativeAddress > m_region.size())
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_region[relativeAddress];
    }

    // Virtual to allow listeners to read what is written to address
    virtual void Write(uint16_t relativeAddress, uint8_t byte)
    {
        if (relativeAddress > m_region.size())
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        m_region[relativeAddress] = byte;
    };

    std::size_t size()
    {
        return m_region.size();
    }

protected:
    std::span<uint8_t> m_region;
};

class WeakMappedMemoryBlock
{
public:
    WeakMappedMemoryBlock()
    {}

    WeakMappedMemoryBlock(std::shared_ptr<MappedMemoryBlock> pMemoryBlock):
        m_pMemoryBlock(pMemoryBlock)
    {}

    uint8_t Read(uint16_t relativeAddress) const
    {
        if (auto pMemoryBlock = m_pMemoryBlock.lock())
        {
            return pMemoryBlock->Read(relativeAddress);
        }
        throw std::runtime_error("Memory block does not exist. Addr: " + std::to_string(relativeAddress));
    }

    void Write(uint16_t relativeAddress, uint8_t byte) const
    {
        if (auto pMemoryBlock = m_pMemoryBlock.lock())
        {
            pMemoryBlock->Write(relativeAddress, byte);
            return;
        }
        throw std::runtime_error("Memory block does not exist. Addr: " + std::to_string(relativeAddress));
    }

private:
    std::weak_ptr<MappedMemoryBlock> m_pMemoryBlock;
};

} // namespace detail
