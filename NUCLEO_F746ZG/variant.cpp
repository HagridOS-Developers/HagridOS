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

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
// This array allows to wrap Arduino pin number(Dx or x)
// to STM32 PinName (PX_n)
const PinName digitalPin[] = {
//PX_n, //Dx
PG_9,  //D0
PG_14, //D1
PF_15, //D2
PE_13, //D3
PF_14, //D4
PE_11, //D5
PE_9,  //D6
PF_13, //D7
PF_12, //D8
PD_15, //D9
PD_14, //D10
PA_7,  //D11
PA_6,  //D12
PA_5,  //D13
PB_9,  //D14
PB_8,  //D15
PC_6,  //D16
PB_15, //D17
PB_13, //D18
PB_12, //D19
PA_15, //D20
PC_7,  //D21
PB_5,  //D22
PB_3,  //D23
PA_4,  //D24
PB_4,  //D25
PB_6,  //D26
PB_2,  //D27
PD_13, //D28
PD_12, //D29
PD_11, //D30
PE_2,  //D31
PA_0,  //D32
PB_0,  //D33 - LED_GREEN
PE_0,  //D34
PB_11, //D35
PB_10, //D36
PE_15, //D37
PE_14, //D38
PE_12, //D39
PE_10, //D40
PE_7,  //D41
PE_8,  //D42
PC_8,  //D43
PC_9,  //D44
PC_10, //D45
PC_11, //D46
PC_12, //D47
PD_2,  //D48
PG_2,  //D49
PG_3,  //D50
PD_7,  //D51
PD_6,  //D52
PD_5,  //D53
PD_4,  //D54
PD_3,  //D55
PE_2,  //D56
PE_4,  //D57
PE_5,  //D58
PE_6,  //D59
PE_3,  //D60
PF_8,  //D61
PF_7,  //D62
PF_9,  //D63
PG_1,  //D64
PG_0,  //D65
PD_1,  //D66
PD_0,  //D67
PF_0,  //D68
PF_1,  //D69
PF_2,  //D70
PA_7,  //D71
NC,    //D72
PB_7,  //D73 - LED_BLUE
PB_14, //D74 - LED_RED
PC_13, //D75 - USER_BTN
PD_9,  //D76 - Serial Rx
PD_8,  //D77 - Serial Tx
PA_3,  //D78/A0
PC_0,  //D79/A1
PC_3,  //D80/A2
PF_3,  //D81/A3
PF_5,  //D82/A4
PF_10, //D83/A5
PB_1,  //D84/A6
PC_2,  //D85/A7
PF_4,  //D86/A8
PF_6,  //D87/A9
// Duplicated pins in order to be aligned with PinMap_ADC
PA_7,  //D88/A10 = D11
PA_6,  //D89/A11 = D12
PA_5,  //D90/A12 = D13
PA_4,  //D91/A13 = D24
PA_0,  //D92/A14 = D32
PF_8,  //D93/A15 = D61
PF_7,  //D94/A16 = D62
PF_9 //D95/A17 = D63
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */

WEAK void SystemClock_Config(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 432;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;
    if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      while(1) {};
    }

    /* Activate the OverDrive to reach the 216 Mhz Frequency */
    if(HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
      while(1) {};
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
       clocks dividers */
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
      while(1) {};
    }
}

#ifdef __cplusplus
}
#endif