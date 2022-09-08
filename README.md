# STM32-CMSIS_learning
В данном репозитории представлены мои учебные проекты для отладочной платы BluePill (STM32F103CBT6)

Статус: В разработке

Библиотека: CMSIS

# Список проектов
1. Blinking_LED
2. SPI_Loopback
3. SPI_TFTFillScreen
4. SPI_TFTFillScreenWithDMA

# Описание проектов
## Blinking_LED
Моргание бортовым светодиодом, заведенным на пин PC13, раз в 1000 мс.

## SPI_Loopback
Тестирование хардварного SPI, путём заворота Rx на Tx.

## SPI_TFTFillScreen
Заливка TFT экрана (контроллер ST7735) на 1 с поочередно красным, зеленым и синим цветами через SPI.

## SPI_TFTFillScreenWithDMA
Заливка TFT экрана (контроллер ST7735) на 1с с поочередно красным, зеленым и синим цветами через SPI
с использованием DMA.
