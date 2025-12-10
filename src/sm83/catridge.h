#pragma once

#include <cstdint>
#include <vector>
#include <memory>

class Mmu;

namespace detail {
class CatridgeImpl;
} // namespace detail

class Catridge
{
public:
    Catridge(Mmu& mmu);
    ~Catridge();

    Catridge(Catridge&&) noexcept;
    Catridge& operator=(Catridge&&) noexcept;

    Catridge(const Catridge&) = delete;
    Catridge& operator=(const Catridge&) = delete;

    void LoadRom(std::vector<uint8_t>&& romData);
    uint8_t Read(uint8_t address) const;
    void Write(uint8_t address, uint8_t value);

    void EnableBootRom(bool enable);
    bool IsLoaded() const;

private:
    std::unique_ptr<detail::CatridgeImpl> m_pImpl;
};
