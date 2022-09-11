#pragma once

#include "stm32f103xb.h"

#include "config.hpp"
#include "init.hpp"
#include "utils/spi.hpp"
#include "tft/commands.hpp"
#include "tft/colors.hpp"

#if (_8BIT_MODE == 1)
    #include "tft/TFT8BitMode.hpp"
#elif (_16BIT_MODE == 1)
    #include "tft/TFT16BitMode.hpp"
#endif

#include <inc/ST7735S.hpp>

#define MADCTLGRAPHICS      0x6
#define MADCTLBMP           0x2

#define ST7735_WIDTH        128
#define ST7735_HEIGHT       160

volatile uint32_t TICK = 0;

void ST7735_init(SPI_TypeDef *SPIx, const uint8_t *commandList);
void sendCommand(SPI_TypeDef *SPIx, uint8_t command,
                 const uint8_t *address, uint8_t numArgs);
void ST7735_backlight(uint8_t on);
void fillScreen(SPI_TypeDef *SPIx, uint16_t color);
void ST7735_pushColor(SPI_TypeDef *SPIx, uint16_t color, int count);
void delay(uint32_t delay_ms);

#ifdef __cplusplus
extern "C"
{
    #endif // __cplusplus

    void SysTick_Handler();

    #ifdef __cplusplus
}
#endif // __cplusplus
