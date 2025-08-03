#pragma once

#include "u8g2.h"

#define USE_HW_IIC

// STM32F0 系列
#if defined(STM32F030x6) || defined(STM32F030x8) || \
    defined(STM32F070x6) || defined(STM32F070xB) || \
    defined(STM32F072xB) || defined(STM32F091xC)
#include "stm32f0xx_hal.h"

// STM32F1 系列
#elif defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F100xB)
#include "stm32f1xx_hal.h"

// STM32F4 系列（如 F401）
#elif defined(STM32F401xE) || defined(STM32F401xC)
#include "stm32f4xx_hal.h"

// STM32F7 系列
#elif defined(STM32F746xx) || defined(STM32F767xx) || defined(STM32F722xx)
  #include "stm32f7xx_hal.h"

// STM32H7 系列
#elif defined(STM32H743xx) || defined(STM32H750xx) || defined(STM32H7B3xx)
  #include "stm32h7xx_hal.h"

#else
  #error "Unsupported STM32 HAL series! Please define the correct chip macro."
#endif

void U8G2_Init(u8g2_t *u8g2);
