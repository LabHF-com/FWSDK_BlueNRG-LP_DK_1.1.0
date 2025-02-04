/**
  ******************************************************************************
  * @file    Cortex/CORTEXM_MPU/Src/rf_device_mpu.c
  * @author  RF Application Team
  * @brief   Access rights configuration using Cortex-M3 MPU regions.
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
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rf_device_mpu.h"

/** @addtogroup RF_DRIVER_HAL_Examples
  * @{
  */

/** @addtogroup CORTEXM_MPU
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ARRAY_ADDRESS_START    (0x20002000UL)
#define ARRAY_SIZE             MPU_REGION_SIZE_256B
#define ARRAY_REGION_NUMBER    MPU_REGION_NUMBER3

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Only to demonstrate that the follow address is write protected, in this example is used the direct write of this location. */
#define PRIVILEGED_ADDRESS_READ_ONLY 0x20002000

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Configures the main MPU regions.
  * @param  None
  * @retval None
  */
void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable MPU */
  HAL_MPU_Disable();

  /* Configure RAM region as Region N°0, 256KB of size and R/W region */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = EXAMPLE_RAM_ADDRESS_START;
  MPU_InitStruct.Size = EXAMPLE_RAM_SIZE;
  MPU_InitStruct.AccessPermission = MPU_REGION_READ_WRITE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = EXAMPLE_RAM_REGION_NUMBER;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Configure FLASH region as REGION N°1, 1MB of size and R/W region */
  MPU_InitStruct.BaseAddress = EXAMPLE_FLASH_ADDRESS_START;
  MPU_InitStruct.Size = EXAMPLE_FLASH_SIZE;
  MPU_InitStruct.Number = EXAMPLE_FLASH_REGION_NUMBER;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Configure Peripheral region as REGION N°2, 512MB of size, R/W and Execute
  Never region */
  MPU_InitStruct.BaseAddress = EXAMPLE_PERIPH_ADDRESS_START;
  MPU_InitStruct.Size = EXAMPLE_PERIPH_SIZE;
  MPU_InitStruct.Number = EXAMPLE_PERIPH_REGION_NUMBER;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable MPU (any access not covered by any enabled region will cause a fault) */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  This function configures the access right using Cortex-M0 Plus MPU regions.
  * @param  None
  * @retval None
  */
void MPU_AccessPermConfig(void)
{
#ifdef ACCESS_PERMISSION
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable MPU */
  HAL_MPU_Disable();

  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = ARRAY_ADDRESS_START;
  MPU_InitStruct.Size = ARRAY_SIZE;
  MPU_InitStruct.AccessPermission = MPU_REGION_PRIVILEGED_READ_ONLY;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = ARRAY_REGION_NUMBER;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable MPU (any access not covered by any enabled region will cause a fault) */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
#endif
  
  char *x = (char*) PRIVILEGED_ADDRESS_READ_ONLY;
	
  /* Read from PrivilegedReadOnlyArray. This will not generate error */
  (void)x[0];

  /* write to privileged Read Only Area. This will generate an error */
   x[0] = 'e'; 
  
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



