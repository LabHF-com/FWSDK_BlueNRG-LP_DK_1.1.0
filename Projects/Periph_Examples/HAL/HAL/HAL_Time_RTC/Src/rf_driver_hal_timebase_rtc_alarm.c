/**
******************************************************************************
* @file    rf_driver_hal_timebase_rtc_alarm.c 
* @author  RF Application Team
* @brief   HAL time base based on the hardware RTC_ALARM.
*
*          This file override the native HAL time base functions (defined as weak)
*          to use the RTC ALARM for time base generation:
*           + Intializes the RTC peripheral to increment the seconds registers each 1ms
*           + The alarm is configured to assert an interrupt when the RTC reaches 1ms 
*           + HAL_IncTick is called at each Alarm event and the time is reset to 00:00:00
*           + HSE (default), LSE or LSI can be selected as RTC clock source  
@verbatim
==============================================================================
##### How to use this driver #####
==============================================================================
[..]
This file must be copied to the application folder and modified as follows:
(#) Rename it to 'rf_driver_hal_timebase_rtc_alarm.c'
(#) Add this file and the RTC HAL drivers to your project and uncomment
HAL_RTC_MODULE_ENABLED define in rf_device_hal_conf.h 

[..]
(@) HAL RTC alarm and HAL RTC wakeup drivers can�t be used with low power modes:
The wake up capability of the RTC may be intrusive in case of prior low power mode
configuration requiring different wake up sources.
Application/Example behavior is no more guaranteed 
(@) The rf_driver_hal_timebase_tim use is recommended for the Applications/Examples
requiring low power modes

@endverbatim
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT(c) 2020 STMicroelectronics. 
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under BSD 3-Clause license,
* the "License"; You may not use this file except in compliance with the 
* License. You may obtain a copy of the License at:
*                        opensource.org/licenses/BSD-3-Clause
*
******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "rf_driver_hal.h"
/** @addtogroup Peripherals_Drivers
* @{
*/

/** @defgroup HAL_TimeBase_RTC_Alarm  HAL TimeBase RTC Alarm
* @{
*/ 

/* Private typedef -----------------------------------------------------------*/
#define RTC_ASYNCH_PREDIV       0U
#define RTC_SYNCH_PREDIV        31U

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef        hRTC_Handle;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
* @brief  This function configures the RTC_ALARMA as a time base source. 
*         The time source is configured  to have 1ms time base with a dedicated 
*         Tick interrupt priority. 
* @note   This function is called  automatically at the beginning of program after
*         reset by HAL_Init() or at any time when clock is configured, by HAL_RCC_ClockConfig().
* @param  TickPriority: Tick interrupt priority.
* @retval HAL status
*/
HAL_StatusTypeDef HAL_InitTick (uint32_t TickPriority)
{
  __IO uint32_t counter = 0U;
  
  /* RTC clock enable */
  __HAL_RCC_RTC_CLK_ENABLE();
  
  __HAL_RCC_CLEAR_IT(RCC_IT_RTCRSTRELRDY);
  /* Force RTC peripheral reset */
  __HAL_RCC_RTC_FORCE_RESET();
  __HAL_RCC_RTC_RELEASE_RESET();
  /* Check if RTC Reset Release flag interrupt occurred or not */
  while(__HAL_RCC_GET_IT(RCC_IT_RTCRSTRELRDY) == 0)
  {
  } 
  __HAL_RCC_CLEAR_IT(RCC_IT_RTCRSTRELRDY);
  
  /* The time base should be 1ms
  Time base = ((RTC_ASYNCH_PREDIV + 1) * (RTC_SYNCH_PREDIV + 1)) / RTC_CLOCK 
  LSE as RTC clock 
  Time base = ((31 + 1) * (0 + 1)) / 32.768KHz
  = ~1ms
  */
  hRTC_Handle.Instance = RTC;
  hRTC_Handle.Init.HourFormat = RTC_HOURFORMAT_24;
  hRTC_Handle.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
  hRTC_Handle.Init.SynchPrediv = RTC_SYNCH_PREDIV;
  hRTC_Handle.Init.OutPut = RTC_OUTPUT_DISABLE;
  hRTC_Handle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  if (HAL_RTC_Init(&hRTC_Handle) != HAL_OK)
  {
    return HAL_ERROR;
  }
  
  /* Disable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_DISABLE(&hRTC_Handle);
  
  /* Disable the Alarm A interrupt */
  __HAL_RTC_ALARMA_DISABLE(&hRTC_Handle);
  
  /* Clear flag alarm A */
  __HAL_RTC_ALARM_CLEAR_FLAG(&hRTC_Handle, RTC_FLAG_ALRAF);
  
  counter = 0U;
  /* Wait till RTC ALRAWF flag is set and if Time out is reached exit */
  while(__HAL_RTC_ALARM_GET_FLAG(&hRTC_Handle, RTC_FLAG_ALRAWF) == RESET)
  {
    if(counter++ == (SystemCoreClock /48U)) /* Timeout = ~ 1s */
    {
      return HAL_ERROR;
    }
  }
  
  hRTC_Handle.Instance->ALRMAR = (uint32_t)0x01U;
  
  /* Configure the Alarm state: Enable Alarm */
  __HAL_RTC_ALARMA_ENABLE(&hRTC_Handle);
  
  /* Configure the Alarm interrupt */
  __HAL_RTC_ALARM_ENABLE_IT(&hRTC_Handle, RTC_IT_ALRA);
  
  
  /* Check if the Initialization mode is set */
  if((hRTC_Handle.Instance->ISR & RTC_ISR_INITF) == (uint32_t)RESET)
  {
    /* Set the Initialization mode */
    hRTC_Handle.Instance->ISR = (uint32_t)RTC_INIT_MASK;
    counter = 0U;
    while((hRTC_Handle.Instance->ISR & RTC_ISR_INITF) == (uint32_t)RESET)
    {
      if(counter++ == (SystemCoreClock /48U)) /* Timeout = ~ 1s */
      {
        return HAL_ERROR;
      }
    }
  }
  hRTC_Handle.Instance->DR = 0U;
  hRTC_Handle.Instance->TR = 0U;
  
  hRTC_Handle.Instance->ISR &= (uint32_t)~RTC_ISR_INIT;
  
  /* Enable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_ENABLE(&hRTC_Handle);
  
  HAL_NVIC_SetPriority(RTC_IRQn, IRQ_LOW_PRIORITY );
  HAL_NVIC_EnableIRQ(RTC_IRQn);
  
  return HAL_OK;
}

/**
* @brief  Suspend Tick increment.
* @note   Disable the tick increment by disabling RTC ALARM interrupt.
* @retval None
*/
void HAL_SuspendTick(void)
{
  /* Disable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_DISABLE(&hRTC_Handle);
  /* Disable RTC ALARM update Interrupt */
  __HAL_RTC_ALARM_DISABLE_IT(&hRTC_Handle, RTC_IT_ALRA);
  /* Enable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_ENABLE(&hRTC_Handle);
}

/**
* @brief  Resume Tick increment.
* @note   Enable the tick increment by Enabling RTC ALARM interrupt.
* @retval None
*/
void HAL_ResumeTick(void)
{
  /* Disable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_DISABLE(&hRTC_Handle);
  /* Enable RTC ALARM Update interrupt */
  __HAL_RTC_ALARM_ENABLE_IT(&hRTC_Handle, RTC_IT_ALRA);
  /* Enable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_ENABLE(&hRTC_Handle);
}

/**
* @brief  ALARM A Event Callback in non blocking mode
* @note   This function is called  when RTC_ALARM interrupt took place, inside
* RTC_ALARM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
* a global variable "uwTick" used as application time base.
* @param  hrtc : RTC handle
* @retval None
*/
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  __IO uint32_t counter = 0U;
  
  HAL_IncTick();
  
  __HAL_RTC_WRITEPROTECTION_DISABLE(hrtc);
  
  /* Set the Initialization mode */
  hrtc->Instance->ISR = (uint32_t)RTC_INIT_MASK;
  
  while((hrtc->Instance->ISR & RTC_ISR_INITF) == (uint32_t)RESET)
  {
    if(counter++ == (SystemCoreClock /48U)) /* Timeout = ~ 1s */
    {
      break;
    }
  }
  
  /* Reset TR, DR and CR registers */
  hrtc->Instance->TR = (uint32_t)0x00000000U;
  hrtc->Instance->DR = (uint32_t)0x00000000U;
  
  hrtc->Instance->ISR &= (uint32_t)~RTC_ISR_INIT;
  
  /* Enable the write protection for RTC registers */
  __HAL_RTC_WRITEPROTECTION_ENABLE(hrtc);
}

/**
* @}
*/

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



