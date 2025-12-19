#pragma once

#include "detail/memory/mapped_memory_block.h"
#include "detail/memory/mapped_register.h"

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

    const WeakMappedMemoryBlock<0x4000>& GetRomBankA() const              { return m_romBankA; }
    const WeakMappedMemoryBlock<0x4000>& GetRomBankB() const              { return m_romBankB; }
    const WeakMappedMemoryBlock<0x2000>& GetVideoRam() const              { return m_videoRam; }
    const WeakMappedMemoryBlock<0x2000>& GetExternalRam() const           { return m_externalRam; }
    const MemoryBlock          <0x2000>& GetWorkingRam() const            { return m_workingRam; }
    const MappedMemoryBlock    <0x1E00>& GetEchoRam() const               { return m_echoRam; }
    const WeakMappedMemoryBlock  <0xA0>& GetObjectAttributeMemory() const { return m_objectAttributeMemory; }
    const MemoryBlock            <0x60>& GetNotUsable() const             { return m_notUsable; }
    const MemoryBlock            <0x80>& GetInput() const                 { return m_input; }
    const MemoryBlock            <0x80>& GetHighRam() const               { return m_highRam; }

private:
    void DmaTransfer(uint16_t address);

    bool m_testMode;

    WeakMappedMemoryBlock<0x4000> m_romBankA;
    WeakMappedMemoryBlock<0x4000> m_romBankB;
    WeakMappedMemoryBlock<0x2000> m_videoRam;
    WeakMappedMemoryBlock<0x2000> m_externalRam;
    MemoryBlock          <0x2000> m_workingRam;
    MappedMemoryBlock    <0x1E00> m_echoRam;
    WeakMappedMemoryBlock  <0xA0> m_objectAttributeMemory;
    MemoryBlock            <0x60> m_notUsable;
    MemoryBlock            <0x80> m_input;
    MemoryBlock            <0x80> m_highRam;

    std::weak_ptr<MappedRegister> m_bootRomReg;
    std::optional<MemoryBlock<0x2000>> m_fakeEchoRam;
};

} // namespace detail
