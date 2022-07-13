#include "main.hpp"

uint8_t TxBuffer[4], RxBuffer[4];

int main()
{
    int i, j;

    mcu_init();

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 4; j++)
            {
                TxBuffer[j] = i * 4 + j;
            }
            SPI_SendData(SPI2, TxBuffer, 4);
            SPI_RecieveData(SPI2, RxBuffer, 4);
        }
    }
}
