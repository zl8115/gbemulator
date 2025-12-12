#pragma once

#include <cstdint>

// Single Register Names
constexpr uint16_t REG_P1_JOYPAD                      = 0xFF00;
constexpr uint16_t REG_LCD_CONTROL                    = 0xFF40;
constexpr uint16_t REG_BG_PALLETE                     = 0xFF47;
constexpr uint16_t REG_DMA_TRANSFER_ADDRESS           = 0xFF46;
constexpr uint16_t REG_BOOT_ROM_MAPPING_CONTROL       = 0xFF50;
constexpr uint16_t REG_INTERUPT_ENABLE                = 0xFFFF;

// Register Region Names
constexpr uint16_t REGION_CATRIDGE_FIXED_START        = 0x0000;
constexpr uint16_t REGION_CATRIDGE_FIXED_END          = 0x3FFF;
constexpr uint16_t REGION_CATRIDGE_SWITCHABLE_START   = 0x4000;
constexpr uint16_t REGION_CATRIDGE_SWITCHABLE_END     = 0x7FFF;
constexpr uint16_t REGION_VRAM_START                  = 0x8000;
constexpr uint16_t REGION_VRAM_END                    = 0x9FFF;
constexpr uint16_t REGION_CATRIDGE_EXTERNAL_RAM_START = 0xA000;
constexpr uint16_t REGION_CATRIDGE_EXTERNAL_RAM_END   = 0xBFFF;
constexpr uint16_t REGION_WORKING_RAM_START           = 0xC000;
constexpr uint16_t REGION_WORKING_RAM_END             = 0xDFFF;
constexpr uint16_t REGION_ECHO_RAM_START              = 0xE000;
constexpr uint16_t REGION_ECHO_RAM_END                = 0xFDFF;
constexpr uint16_t REGION_OAM_START                   = 0xFE00;
constexpr uint16_t REGION_OAM_END                     = 0xFE9F;
constexpr uint16_t REGION_UNUSABLE_START              = 0xFEA0;
constexpr uint16_t REGION_UNUSABLE_END                = 0xFEFF;
constexpr uint16_t REGION_IO_REGISTERS_START          = 0xFF00;
constexpr uint16_t REGION_IO_REGISTERS_END            = 0xFF7F;
constexpr uint16_t REGION_HIGH_RAM_START              = 0xFF80;
constexpr uint16_t REGION_HIGH_RAM_END                = 0xFFFE;
