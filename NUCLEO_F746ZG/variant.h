/*
 *******************************************************************************
 * Copyright (c) 2017, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "PeripheralPins.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
extern const PinName digitalPin[];

// Enum defining pin names to match digital pin number --> Dx
// !!!
// !!! Copy the digitalPin[] array in variant.cpp
// !!! and remove all '_': PX_n --> PXn
// !!! For NC, suffix by _x where x is the number of NC:
// !!!   NC_1, NC_2,...
// !!! For duplicated pin name, suffix by _x where x is the number of pin:
// !!! PA7, PA7_2, PA7_3,...
enum {
  PG9,  //D0
  PG14, //D1
  PF15, //D2
  PE13, //D3
  PF14, //D4
  PE11, //D5
  PE9,  //D6
  PF13, //D7
  PF12, //D8
  PD15, //D9
  PD14, //D10
  PA7,  //D11
  PA6,  //D12
  PA5,  //D13
  PB9,  //D14
  PB8,  //D15
  PC6,  //D16
  PB15, //D17
  PB13, //D18
  PB12, //D19
  PA15, //D20
  PC7,  //D21
  PB5,  //D22
  PB3,  //D23
  PA4,  //D24
  PB4,  //D25
  PB6,  //D26
  PB2,  //D27
  PD13, //D28
  PD12, //D29
  PD11, //D30
  PE2,  //D31
  PA0,  //D32
  PB0,  //D33 - LEDGREEN
  PE0,  //D34
  PB11, //D35
  PB10, //D36
  PE15, //D37
  PE14, //D38
  PE12, //D39
  PE10, //D40
  PE7,  //D41
  PE8,  //D42
  PC8,  //D43
  PC9,  //D44
  PC10, //D45
  PC11, //D46
  PC12, //D47
  PD2,  //D48
  PG2,  //D49
  PG3,  //D50
  PD7,  //D51
  PD6,  //D52
  PD5,  //D53
  PD4,  //D54
  PD3,  //D55
  PE2_2,//D56
  PE4,  //D57
  PE5,  //D58
  PE6,  //D59
  PE3,  //D60
  PF8,  //D61
  PF7,  //D62
  PF9,  //D63
  PG1,  //D64
  PG0,  //D65
  PD1,  //D66
  PD0,  //D67
  PF0,  //D68
  PF1,  //D69
  PF2,  //D70
  PA7_2,//D71
  NC_1, //D72
  PB7,  //D73 - LEDBLUE
  PB14, //D74 - LEDRED
  PC13, //D75 - USERBTN
  PD9,  //D76 - Serial Rx
  PD8,  //D77 - Serial Tx
  PA3,  //D78/A0
  PC0,  //D79/A1
  PC3,  //D80/A2
  PF3,  //D81/A3
  PF5,  //D82/A4
  PF10, //D83/A5
  PB1,  //D84/A6
  PC2,  //D85/A7
  PF4,  //D86/A8
  PF6,  //D87/A9
  // Duplicated pins in order to be aligned with PinMapADC
  PA7_3,  //D88/A10 = D11
  PA6_2,  //D89/A11 = D12
  PA5_2,  //D90/A12 = D13
  PA4_2,  //D91/A13 = D24
  PA0_2,  //D92/A14 = D32
  PF8_2,  //D93/A15 = D61
  PF7_2,  //D94/A16 = D62
  PF9_2, //D95/A17 = D63
  PEND
};

// This must be a literal with the same value as PEND
// It is used with preprocessor tests (e.g. #if NUM_DIGITAL_PINS > 3)
// so an enum will not work.
#define NUM_DIGITAL_PINS        96

// Allow to define Arduino style alias for analog input pin number --> Ax
// All pins are digital, analog inputs are a subset of digital pins
// and must be contiguous to be able to loop on each value
// This must be a literal with a value less than or equal to MAX_ANALOG_INPUTS
// defined in pin_arduino.h
// It is used with preprocessor tests (e.g. #if NUM_ANALOG_INPUTS > 3)
// so an enum will not work.
// !!!
// !!! It must be aligned with the number of analog PinName
// !!! defined in digitalPin[] array in variant.cpp
// !!!
#define NUM_ANALOG_INPUTS       18
// Define digital pin number of the first analog input  (i.e. which digital pin is A0)
// First analog pin value (A0) must be greater than or equal to NUM_ANALOG_INPUTS
#define NUM_ANALOG_FIRST        78

// Below ADC, DAC and PWM definitions already done in the core
// Could be redefined here if needed
// ADC resolution is 12bits
#define ADC_RESOLUTION          12
#define DACC_RESOLUTION         12

// PWM resolution
#define PWM_RESOLUTION          8
#define PWM_FREQUENCY           1000
#define PWM_MAX_DUTY_CYCLE      255

#define LED_BUILTIN             PB0
#define LED_GREEN               LED_BUILTIN
#define LED_BLUE                PB7
#define LED_RED                 PB14

// On-board user button
#define USER_BTN                PC13

// Below SPI and I2C definitions already done in the core
// Could be redefined here if differs from the default one
// SPI Definitions
//#define PIN_SPI_SS              10 // Default for Arduino connector compatibility
//#define PIN_SPI_MOSI            11 // Default for Arduino connector compatibility
//#define PIN_SPI_MISO            12 // Default for Arduino connector compatibility
//#define PIN_SPI_SCK             13 // Default for Arduino connector compatibility

// I2C Definitions
//#define PIN_WIRE_SDA            14 // Default for Arduino connector compatibility
//#define PIN_WIRE_SCL            15 // Default for Arduino connector compatibility

// Timer Definitions
//Do not use timer used by PWM pins when possible. See PinMap_PWM in PeripheralPins.c
#define TIMER_TONE              TIM6
//#define TIMER_UART_EMULATED     TIMx

// Do not use basic timer: OC is required
#define TIMER_SERVO             TIM2  //TODO: advanced-control timers don't work

// UART Definitions
// Define here Serial instance number to map on Serial generic name
#define SERIAL_UART_INSTANCE    3 //ex: 2 for Serial2 (USART2)
// DEBUG_UART could be redefined to print on another instance than 'Serial'
//#define DEBUG_UART              ((USART_TypeDef *) U(S)ARTX) // ex: USART3
// DEBUG_UART baudrate, default: 9600 if not defined
//#define DEBUG_UART_BAUDRATE     x
// DEBUG_UART Tx pin name, default: the first one found in PinMap_UART_TX for DEBUG_UART
//#define DEBUG_PINNAME_TX        PX_n // PinName used for TX

// UART Emulation (uncomment if needed, required TIM1)
//#define UART_EMUL_RX            PX_n // PinName used for RX
//#define UART_EMUL_TX            PX_n // PinName used for TX

// Default pin used for 'Serial' instance (ex: ST-Link)
// Mandatory for Firmata
#define PIN_SERIAL_RX           PD9
#define PIN_SERIAL_TX           PD8

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR     Serial
#define SERIAL_PORT_HARDWARE    Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
