#pragma once

#include <cstdint>

#include <array>
#include <memory>
#include <span>
#include <stdexcept>
#include <vector>

namespace detail {

template<std::size_t N>
using MemoryBlock = std::array<uint8_t, N>;

template<std::size_t N>
class MappedMemoryBlock
{
public:

    MappedMemoryBlock(MemoryBlock<N>& memoryBlock, std::size_t offset):
        m_region(memoryBlock.begin() + offset, memoryBlock.begin() + offset + N)
    {}

    template <std::size_t O> requires (O > N)
    MappedMemoryBlock(MemoryBlock<O>& memoryBlock, std::size_t offset):
        m_region(memoryBlock.begin() + offset, memoryBlock.begin() + offset + N)
    {}

    MappedMemoryBlock(std::vector<uint8_t>& memoryBlock, std::size_t offset):
        m_region(memoryBlock.begin() + offset, memoryBlock.begin() + offset + N)
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

    const std::span<uint8_t, N>& GetSpan() const
    {
        return m_region;
    }

protected:
    std::span<uint8_t, N> m_region;
};

template<std::size_t N>
class WeakMappedMemoryBlock
{
public:
    WeakMappedMemoryBlock()
    {}

    WeakMappedMemoryBlock(std::shared_ptr<MappedMemoryBlock<N>> pMemoryBlock):
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

    const std::shared_ptr<MappedMemoryBlock<N>> get() const
    {
        return m_pMemoryBlock.lock();
    }

private:
    std::weak_ptr<MappedMemoryBlock<N>> m_pMemoryBlock;
};

} // namespace detail
