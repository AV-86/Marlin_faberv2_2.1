/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * STM32F407VET6 with RAMPS-like shield
 * 'Black' STM32F407VET6 board - https://www.stm32duino.com/viewtopic.php?t=485
 * Shield - https://github.com/jmz52/Hardware
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Black STM32F4VET6 supports up to 2 hotends / E steppers."
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "Black STM32F4VET6"
#endif

#define DEFAULT_MACHINE_NAME "Faber_V2"

//#define I2C_EEPROM
//#define SRAM_EEPROM_EMULATION
#define FLASH_EEPROM_EMULATION
#define MARLIN_EEPROM_SIZE                0x2000  // 8K

//
// Servos
//
#define SERVO0_PIN                          PE13
#define SERVO1_PIN                          PE14

//
// Limit Switches
//
#define X_MIN_PIN          PD14
#define X_MAX_PIN          PD15
#define Y_MIN_PIN          PC7
#define Y_MAX_PIN          PC8
#define Z_MIN_PIN          PD11
#define Z_MAX_PIN          PD12

//
// Steppers
//
//Axis X connector
#define X_STEP_PIN         PD3
#define X_DIR_PIN          PD2
#define X_ENABLE_PIN       PD0

//Axis Y connector
#define Y_STEP_PIN         PE5
#define Y_DIR_PIN          PE6
#define Y_ENABLE_PIN       PC13

//Axis Z connector
#define Z_STEP_PIN         PD1
#define Z_DIR_PIN          PD7
#define Z_ENABLE_PIN       PD4

//E0 connector
//Используется для второго мотора оси Z, чтобы не выравнивать для каждой печати
#define Z2_STEP_PIN        PB5
#define Z2_DIR_PIN         PB4
#define Z2_ENABLE_PIN      PB3

//E1 connector
#define E0_STEP_PIN        PE1
#define E0_DIR_PIN         PE0
#define E0_ENABLE_PIN      PB8

//Это для dondolo дублирование тех же пинов что и E0
#define E1_STEP_PIN        PE1
#define E1_DIR_PIN         PE0
#define E1_ENABLE_PIN      PB8

//
// Temperature Sensors
//
#define TEMP_0_PIN         PC2  // T0 (Thrm0 connector)
#define TEMP_1_PIN         PC3  // T1 (Thrm1 connector)
#define TEMP_BED_PIN       PC4  // TB (Thrm2 connector)

#ifndef TEMP_CHAMBER_PIN
  #define TEMP_CHAMBER_PIN                  PC3   // TC
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN       PA0     // (Heater0 connector)
#define HEATER_1_PIN       PA1     // (Heater1 connector)
//#define HEATER_2_PIN       PA10  // (Heater2 connector)
//#define HEATER_3_PIN       PA3   // (AC_Bed connector)
//#define HEATER_BED_PIN     PA2   // (DC_Bed connector)
#define HEATER_BED_PIN       PA3   // (AC_Bed connector)

#define FAN0_PIN            PA9  // (Fan0 connector)
#define FAN1_PIN           PD10 // (Fan1 connector)
#define FAN2_PIN           PA10 // (Heater2 connector)

//
// Misc. Functions
//
//#define LED_PIN                           PA7
#define PWR_LOSS            PA4         //Power loss / nAC_FAULT
#define KILL_PIN            PA8

#define EnableHiPWR_PIN     PC15
#define EnableServoPWR_PIN  PC14

//
// LCD / Controller
//
#define SD_DETECT_PIN      PA15
#define SDSS               PE7
#define SS_PIN             PE7
#define SCK_PIN            PA5
#define MISO_PIN           PA6
#define MOSI_PIN           PA7

#define SD_SCK_PIN         PA5
#define SD_SS_PIN          PE7
#define SD_MISO_PIN        PA6
#define SD_MOSI_PIN        PA7


#define BEEPER_PIN         PC9
#define LCD_PINS_RS        PE9
#define LCD_PINS_EN        PE8
#define LCD_PINS_D4        PB12
#define LCD_PINS_D5        PB13
#define LCD_PINS_D6        PD8
#define LCD_PINS_D7        PD9
#define BTN_ENC            PB1
#define BTN_EN1            PB0
#define BTN_EN2            PC5

#define DOGLCD_CS          LCD_PINS_D5
#define DOGLCD_A0          LCD_PINS_D6

#define SERVO0_TIMER_NUM 2
#define SERVO1_TIMER_NUM 2


#define BOARD_INIT() do{}while(0)

#if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
  #define BTN_ENC_EN                 LCD_PINS_D7  // Detect the presence of the encoder
#endif
