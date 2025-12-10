#pragma once

#include "detail/mmu_mapped_memory.h"

#include <cstdint>
#include <optional>

namespace detail {

class PpuImpl;
class InputImpl;
class CatridgeImpl;

class MmuImpl {
public:
    MmuImpl();

    uint8_t Read(const uint16_t address) const;
    void Write(const uint16_t address, uint8_t byte);
    MappedRegister GetMappedRegister(const uint16_t address);

    void MapMemory(const PpuImpl& ppu);
    void MapMemory(const CatridgeImpl& catridge);

    void EnableTestMode();
    void DisableTestMode();

private:
    void DmaTransfer(uint16_t address);

    bool m_testMode;

    WeakMappedMemoryBlock m_romBankA;
    WeakMappedMemoryBlock m_romBankB;
    WeakMappedMemoryBlock m_videoRam;
    WeakMappedMemoryBlock m_externalRam;
    MemoryBlock<0x2000> m_workingRam;
    // MappedMemoryBlock m_workingRam00;
    // MappedMemoryBlock m_workingRam01;
    MappedMemoryBlock m_echoRam;
    WeakMappedMemoryBlock m_objectAttributeMemory;
    MemoryBlock<0x80> m_notUsable;
    MemoryBlock<0x80> m_input; // 0x80
    MemoryBlock<0x80> m_highRam;
    uint8_t m_interruptEnable;

    std::optional<MemoryBlock<0x2000>> m_fakeEchoRam;
};

} // namespace detail
