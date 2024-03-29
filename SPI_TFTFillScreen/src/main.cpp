#include "main.hpp"

int main()
{
    mcu_init();

    static const uint8_t __attribute__((section(".rodata.ST7735S_InitCommandList"), used))
        commandList[] = {
            19,
            ST7735S_CMD_SWRESET,    ST7735S_CMD_DELAY,
                120,
            ST7735S_CMD_SLPOUT,     ST7735S_CMD_DELAY,
                255,
            ST7735S_CMD_FRMCTR1,    3,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_FRMCTR2,    3,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_FRMCTR3,    6,
                0x01, 0x2C, 0x2D,
                0x01, 0x2C, 0x2D,
            ST7735S_CMD_INVCTR,     1,
                0x07,
            ST7735S_CMD_PWRCTR1,    3,
                0xA2, 0x02, 0x84,
            ST7735S_CMD_PWRCTR2,    1,
                0xC5,
            ST7735S_CMD_PWRCTR3,    2,
                0x0A, 0x00,
            ST7735S_CMD_PWRCTR4,    2,
                0x8A, 0x2A,
            ST7735S_CMD_PWRCTR5,    2,
                0x8A, 0xEE,
            ST7735S_CMD_VMCTR1,     1,
                0x0E,
            ST7735S_CMD_INVOFF,     0,
            ST7735S_CMD_MADCTL,     1,
                0x00,
            ST7735S_CMD_COLMOD,     1,
                0x05,
            ST7735S_CMD_CASET,      4,
                0x00, 0x00,
                0x00, 0x7F,
            ST7735S_CMD_RASET,      4,
                0x00, 0x00,
                0x00, 0x9F,
            ST7735S_CMD_NORON,      ST7735S_CMD_DELAY,
                10,
            ST7735S_CMD_DISPON,     ST7735S_CMD_DELAY,
                255
        };

    JST7735S* display = new JST7735S(SPI2, commandList,
                                     #ifdef _8BIT_MODE
                                        new TFT8BitMode(SPI2),
                                     #elif defined(_16BIT_MODE)
                                        new TFT16BitMode(SPI2),
                                     #endif
                                     delay);

    while (1)
    {
        display->fillScreen(_RED);
        delay(1000);
        display->fillScreen(_GREEN);
        delay(1000);
        display->fillScreen(_BLUE);
        delay(1000);
    }
}

void SysTick_Handler()
{
    TICK++;
}

void delay(uint32_t delay_ms)
{
    uint32_t timeStamp = TICK;
    while (TICK - timeStamp < delay_ms);
}
