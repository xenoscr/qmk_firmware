/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include_next <mcuconf.h>

/*
 * HAL driver system settings
 */


#undef STM32_HSI_ENABLED
#undef STM32_HSI48_ENABLED
#undef STM32_SW
#undef STM32_CECSW
#undef STM32_I2C1SW

#define STM32_HSI_ENABLED   FALSE
#define STM32_HSI48_ENABLED TRUE
#define STM32_SW            STM32_SW_HSI48
#define STM32_CECSW         STM32_CECSW_OFF
#define STM32_I2C1SW        STM32_I2C1SW_SYSCLK

/*
 * I2C driver system settings
 */

#undef STM32_I2C_USE_I2C1
#undef STM32_I2C_USE_I2C2
#undef STM32_I2C_USE_DMA

#define STM32_I2C_USE_I2C1  TRUE
#define STM32_I2C_USE_I2C2  TRUE
#define STM32_I2C_USE_DMA   DMA

/*
 * SERIAL driver system settings
 */

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

/*
 * PWM driver system settings
 */

#undef STM32_PWM_USE_TIM1
#undef STM32_PWM_USE_TIM3

#define STM32_PWM_USE_TIM1 TRUE
#define STM32_PWM_USE_TIM3 TRUE

#undef STM32_SPI_USE_SPI2
#define STM32_SPI_USE_SPI2 TRUE
