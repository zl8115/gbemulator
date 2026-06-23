#pragma once

#include <cstdint>

// I/O Register Names
constexpr uint16_t REG_P1_JOYPAD                      = 0xFF00;
constexpr uint16_t REG_SERIAL_TRANSFER_DATA           = 0xFF01;
constexpr uint16_t REG_SERIAL_TRANSFER_CONTROL        = 0xFF02;
constexpr uint16_t REG_DIVIDER_REGISTER               = 0xFF04;
constexpr uint16_t REG_TIMER_COUNTER                  = 0xFF05;
constexpr uint16_t REG_TIMER_MODULO                   = 0xFF06;
constexpr uint16_t REG_TIMER_CONTROL                  = 0xFF07;
constexpr uint16_t REG_INTERRUPT_FLAG                 = 0xFF0F;
constexpr uint16_t REG_SOUND_CHANNEL1_SWEEP           = 0xFF10;
constexpr uint16_t REG_SOUND_CHANNEL1_LENGTH_AND_DUTY = 0xFF11;
constexpr uint16_t REG_SOUND_CHANNEL1_VOL_AND_ENVLP   = 0xFF12;
constexpr uint16_t REG_SOUND_CHANNEL1_PERIOD_LOW      = 0xFF13;
constexpr uint16_t REG_SOUND_CHANNEL1_PERIOD_HIGH     = 0xFF14;
constexpr uint16_t REG_SOUND_CHANNEL2_LENGTH_AND_DUTY = 0xFF16;
constexpr uint16_t REG_SOUND_CHANNEL2_VOL_AND_ENVLP   = 0xFF17;
constexpr uint16_t REG_SOUND_CHANNEL2_PERIOD_LOW      = 0xFF18;
constexpr uint16_t REG_SOUND_CHANNEL2_PERIOD_HIGH     = 0xFF19;
constexpr uint16_t REG_SOUND_CHANNEL3_DAC             = 0xFF1A;
constexpr uint16_t REG_SOUND_CHANNEL3_LENGTH_TIMER    = 0xFF1B;
constexpr uint16_t REG_SOUND_CHANNEL3_OUTPUT_LEVEL    = 0xFF1C;
constexpr uint16_t REG_SOUND_CHANNEL3_PERIOD_LOW      = 0xFF1D;
constexpr uint16_t REG_SOUND_CHANNEL3_PERIOD_HIGH     = 0xFF1E;
constexpr uint16_t REG_SOUND_CHANNEL4_TIMER           = 0xFF20;
constexpr uint16_t REG_SOUND_CHANNEL4_VOL_AND_ENVLP   = 0xFF21;
constexpr uint16_t REG_SOUND_CHANNEL4_FREQ_AND_RAND   = 0xFF22;
constexpr uint16_t REG_SOUND_CHANNEL4_CONTROL         = 0xFF23;
constexpr uint16_t REG_SOUND_VOLUME_AND_VIN_PANNING   = 0xFF24;
constexpr uint16_t REG_SOUND_PANNING                  = 0xFF25;
constexpr uint16_t REG_SOUND_ENABLE                   = 0xFF26;
constexpr uint16_t REG_LCD_CONTROL                    = 0xFF40;
constexpr uint16_t REG_LCD_STATUS                     = 0xFF41;
constexpr uint16_t REG_LCD_VIEW_SCROLL_Y              = 0xFF42;
constexpr uint16_t REG_LCD_VIEW_SCROLL_X              = 0xFF43;
constexpr uint16_t REG_LCD_Y_COORDINATE               = 0xFF44;
constexpr uint16_t REG_LCD_LY_COMPARE                 = 0xFF45;
constexpr uint16_t REG_DMA_TRANSFER_ADDRESS           = 0xFF46;
constexpr uint16_t REG_BG_PALETTE                     = 0xFF47;
constexpr uint16_t REG_SPRITE_PALETTE_0               = 0xFF48;
constexpr uint16_t REG_SPRITE_PALETTE_1               = 0xFF49;
constexpr uint16_t REG_WINDOW_POS_Y                   = 0xFF4A;
constexpr uint16_t REG_WINDOW_POS_X                   = 0xFF4B;
constexpr uint16_t REG_BOOT_ROM_MAPPING_CONTROL       = 0xFF50;
constexpr uint16_t REG_INTERRUPT_ENABLE                = 0xFFFF;

// I/O Register Region
constexpr uint16_t REGION_SOUND_WAVE_RAM_START        = 0xFF30;
constexpr uint16_t REGION_SOUND_WAVE_RAM_END          = 0xFF3F;

// Memory Bus Register Regions
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
