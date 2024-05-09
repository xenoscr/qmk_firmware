// Copyright 2024 Conor Richard (@xenoscr)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define MASTER_RIGHT
#define SPLIT_HAND_PIN_LOW_IS_LEFT
#define SPLIT_USB_DETECT
#define STM32_ONBOARD_EEPROM_SIZE 1024

#define WS2812_DI_PIN A10
//#define WS2812_EXTERNAL_PULLUP

#define SPLIT_LED_STATE_ENABLED
#define SPLIT_LAYER_STATE_ENABLED

#define LED_PIN_1 B12
#define LED_PIN_2 B13
#define LED_PIN_3 B14

#define SERIAL_USE_MULTI_TRANSACTION
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 0

#define I2C_DRIVER I2CD2
#define I2C1_SCL_BANK GPIOB
#define I2C1_SDA_BANK GPIOB
#define I2C1_SCL 10
#define I2C1_SDA 11
//#define I2C1_SCL_PIN B10
//#define I2C1_SDA_PIN B11
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

// SPI RGB Driver
#define WS2812_SPI_DRIVER SPID2
#define WS2812_SPI_MOSI_PAL_MODE 0
#define WS2812_SPI_SCK_PAL_MODE 0
#define WS2812_SPI_SCK_PIN A10
