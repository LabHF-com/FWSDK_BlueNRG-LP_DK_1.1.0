
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : BLE_Sync_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 29-March-2021
* Description        : Code demonstrating a simple clock synchronization
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file BLE_Sync_main.c
 * @brief  This example shows a simple clock synchronization example
 * 

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Project\\BLE_Examples\\BLE_Sync\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\BLE_Sync.uvprojx</tt> 
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Debug->Start/Stop Debug Session to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Project\\BLE_Examples\\BLE_Sync\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\BLE_Sync.eww</tt> 
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Project\\BLE_Examples\\BLE_Sync\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
  -# Select desired configuration to build
  -# Select Project->Build Project. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Run->Run/Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \subsection Project_configurations Project configurations
- \c Master - Master configuration
- \c Slave - Slave configuration


* \section Board_supported Boards supported
- \c STEVAL-IDB010V1
- \c STEVAL-IDB011V1
- \c STEVAL-IDB011V2
- \c STEVAL-IDB012V1
- \c STEVAL-IDB013V1


* \section Power_settings Power configuration settings
@table

==========================================================================================================
|                                         STEVAL-IDB01xV1                                                |
----------------------------------------------------------------------------------------------------------
| Jumper name | Description                                                                |
| JP2         |                                                                            |
----------------------------------------------------------------------------------------------------------
| USB         | USB supply power                                                            |
| BAT         | The supply voltage must be provided through battery pins.                   |


@endtable 

* \section Jumper_settings Jumper settings
@table

========================================================================================================================================================================================
|                                                                             STEVAL-IDB01xV1                                                                                          |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Jumper name |                                                                Description                                                                                             |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------          
| JP1         | It provides the voltage to the BlueNRG-LP circuit. It must be fitted. It can be used for current measurements of the BlueNRG-LP device.                                |          
| JP2         | It is a switch between two power domains. BAT position: to provide power from battery holder; USB position: to provide power from USB connector.                       |
| JP3         | It connects the BLE_SWCLK pin of the BlueNRG-LP with the SWCLK pin of the USB_CMSISDAP. It must be fitted.                                                             |          
| JP4         | It connects the BLE_SWDIO pin of the BlueNRG-LP with the SWDIO pin of the USB_CMSISDAP. It must be fitted.                                                             |
| JP5         | It connects the BLE_RSTN pin of the BlueNRG-LP with the rest of the board (the USB_CMSISDAP and RESET push button). It must be fitted.                                 |


@endtable 
                        
* \section Pin_settings Pin settings
@table
|            |                                                 Master                                                  |||||                                                  Slave                                                  |||||
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  PIN name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |   STEVAL-IDB012V1  |   STEVAL-IDB013V1  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |   STEVAL-IDB012V1  |   STEVAL-IDB013V1  |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     A0     |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     A1     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     A10    |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     A11    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |        N.A.        |      Not Used      |      Not Used      |      Not Used      |      Not Used      |        N.A.        |
|     A12    |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A13    |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A14    |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A15    |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A3     |        N.A.        |        N.A.        |        N.A.        |      Not Used      |        N.A.        |        N.A.        |        N.A.        |        N.A.        |      Not Used      |        N.A.        |
|     A4     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A5     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A6     |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A7     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     A8     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |        N.A.        |      Not Used      |      Not Used      |      Not Used      |      Not Used      |        N.A.        |
|     A9     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |      Not Used      |      Not Used      |      Not Used      |      Not Used      |        N.A.        |      Not Used      |
|     B0     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B1     |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     B12    |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     B13    |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     B14    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B15    |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     B2     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B3     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B4     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B5     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B6     |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |        N.A.        |        N.A.        |        N.A.        |      Not Used      |      Not Used      |
|     B7     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     B8     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     B9     |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |      Not Used      |      Not Used      |      Not Used      |        N.A.        |        N.A.        |
|     GND    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     RST    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|    VBAT    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |

@endtable 

* \section Serial_IO Serial I/O
@table
| Parameter name  | Value            | Unit      |
----------------------------------------------------
| Baudrate        | 921600           | bit/sec   |
| Data bits       | 8                | bit       |
| Parity          | None             | bit       |
| Stop bits       | 1                | bit       |
@endtable

* \section LEDs_description LEDs description
@table
|            |                                                 Master                                                  |||||                                                  Slave                                                  |||||
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  LED name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |   STEVAL-IDB012V1  |   STEVAL-IDB013V1  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |   STEVAL-IDB012V1  |   STEVAL-IDB013V1  |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     DL2    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     DL3    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     DL4    |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |
|     U5     |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |      Not Used      |

@endtable


* \section Buttons_description Buttons description
@table
|                |                                                   Master                                                    |||||                                                    Slave                                                    |||||
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|   BUTTON name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      PUSH2     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      RESET     |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |

@endtable

* \section Usage Usage

This demo shows a simple clock synchronization example.

The demo requires 2 BlueNRG-LP STEVAL boards configured, respectively, with the Master and Slave project configurations.

Boards can be powered from USB cable or from batteries (insert AAA batteries on the boards and move jumper JP2 to "BAT" position on BlueNRG-LP kit, no action is required on BlueNRG-LPS kits).

Once connected, the master shares its clock information, the network clock, with the slave. The slave is able to keep this network clock always
synchronized with the master while connected, without the need to exchange any other info.
The NETCLOCK library is used to keep the synchronization of this network clock and it also implements a function to start a timer that uses the
network clock.
This example shows the synchronization of the network clock by emitting pulses on PB4 at almost the same time (accuracy of +- 30 us).
The network time is also periodically printed at the same time on master and slave, so that it can be read on a serial terminal.
To give more accuracy, the HAL_VTIMER_Tick() is called inside an interrupt context (i.e. CPU_WKUP_IRQHandler()).

**/
   
/** @addtogroup BlueNRGLP_demonstrations_applications
 * BlueNRG-LP Clock Sync demo \see BLE_Sync_main.c for documentation.
 *
 *@{
 */

/** @} */
/** \cond DOXYGEN_SHOULD_SKIP_THIS
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include "rf_device_it.h"
#include "ble_const.h" 
#include "bluenrg_lp_stack.h"
#include "app_state.h"
#include "profile.h"
#include "Sync_config.h"
#include "bluenrg_lp_evb_config.h"
#include "rf_driver_hal_vtimer.h"
#include "bleplat.h"
#include "nvm_db.h"
#include "pka_manager.h"
#include "rng_manager.h"
#include "aes_manager.h"
#include "ble_controller.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

extern uint8_t call_stack_tick;
   
/* Private macro -------------------------------------------------------------*/
NO_INIT(uint32_t dyn_alloc_a[DYNAMIC_MEMORY_SIZE>>2]);

#define DEBUG 1

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void ModulesInit(void)
{
  uint8_t ret;
  BLE_STACK_InitTypeDef BLE_STACK_InitParams = BLE_STACK_INIT_PARAMETERS;
  
  
  LL_AHB_EnableClock(LL_AHB_PERIPH_PKA|LL_AHB_PERIPH_RNG);

  BLECNTR_InitGlobal();
  
  HAL_VTIMER_InitType VTIMER_InitStruct = {HS_STARTUP_TIME, INITIAL_CALIBRATION, CALIBRATION_INTERVAL};
  HAL_VTIMER_Init(&VTIMER_InitStruct);
  
  BLEPLAT_Init();  
  if (PKAMGR_Init() == PKAMGR_ERROR)
  {
      while(1);
  }
  if (RNGMGR_Init() != RNGMGR_SUCCESS)
  {
      while(1);
  }
  
  /* Init the AES block */
  AESMGR_Init();
  
  /* BlueNRG-LP stack init */
  ret = BLE_STACK_Init(&BLE_STACK_InitParams);
  if (ret != BLE_STATUS_SUCCESS) {
    printf("Error in BLE_STACK_Init() 0x%02x\r\n", ret);
    while(1);
  }
}

void ModulesTick(void)
{
  /* HAL_VTIMER_Tick is done inside CPU_WKUP_IRQHandler() to reduce jitter of synchronized pulses */
  //HAL_VTIMER_Tick();
  
  /* Bluetooth stack tick */
  BLE_STACK_Tick();
  
  /* NVM manager tick */
  NVMDB_Tick();
}

void ConfigureGPIO(void)
{
  BSP_PB_Init(BSP_PUSH1, BUTTON_MODE_GPIO);
  BSP_PB_Init(BSP_PUSH2, BUTTON_MODE_GPIO);
  BSP_LED_Init(BSP_LED1);
  BSP_LED_Init(BSP_LED2);
  BSP_LED_Init(BSP_LED3);
  BSP_LED_On(BSP_LED1);
  
  LL_GPIO_SetPinMode(TEST_PULSE_GPIO_PORT, TEST_PULSE_GPIO_PIN, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinSpeed(TEST_PULSE_GPIO_PORT, TEST_PULSE_GPIO_PIN, LL_GPIO_SPEED_FREQ_HIGH);
  LL_GPIO_SetPinOutputType(TEST_PULSE_GPIO_PORT, TEST_PULSE_GPIO_PIN, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinPull(TEST_PULSE_GPIO_PORT, TEST_PULSE_GPIO_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_ResetOutputPin(TEST_PULSE_GPIO_PORT, TEST_PULSE_GPIO_PIN);
}

 int main(void) 
{
  uint8_t ret;
  WakeupSourceConfig_TypeDef wakeupIO = {0,0,0,0};
  PowerSaveLevels stopLevel;

  /* System initialization function */
  if (SystemInit(SYSCLK_64M, BLE_SYSCLK_32M) != SUCCESS) 
  {
    /* Error during system clock configuration take appropriate action */
    while(1);
  }
  /* Configure IOs for pwer save modes */
  BSP_IO_Init();

  /* Configure I/O communication channel */
  BSP_COM_Init(NULL);

  ModulesInit();
  
  ConfigureGPIO();
  
  PRINTF("\r\nBlueNRG-LP BLE Multiple Connection demo: ");
#if PROFILE_ROLE == ROLE_PERIPHERAL
  PRINTF("Sync Slave\r\n");
#elif PROFILE_ROLE == ROLE_CENTRAL
  PRINTF("Sync Master\r\n");
#else
#error define PROFILE_ROLE
#endif

  /* Init Device */
  ret = DeviceInit();
  if (ret != BLE_STATUS_SUCCESS) {
    PRINTF("CHAT_DeviceInit()--> Failed 0x%02x\r\n", ret);
    while(1);
  }
  
  PRINTF("BLE Stack Initialized \n");
  
  while(1) {
    
    ModulesTick();
    
    /* Application tick */
    APP_Tick();
    
    /* Request to go to sleep */
    HAL_PWR_MNGR_Request(POWER_SAVE_LEVEL_STOP_WITH_TIMER, wakeupIO, &stopLevel);
  }
  
} /* end main() */


/* Event used to notify the Host that a hardware failure has occurred in the Controller. 
   See bluenrg_lp_events.h. */
void hci_hardware_error_event(uint8_t Hardware_Code)
{
  if (Hardware_Code <= 0x03)
  {
    NVIC_SystemReset();
  }
}

/**
  * This event is generated to report firmware error informations.
  * FW_Error_Type possible values: 
  * Values:
  - 0x01: L2CAP recombination failure
  - 0x02: GATT unexpected response
  - 0x03: GATT unexpected request
    After this event with error type (0x01, 0x02, 0x3) it is recommended to disconnect. 
*/
void aci_hal_fw_error_event(uint8_t FW_Error_Type,
                            uint8_t Data_Length,
                            uint8_t Data[])
{
  if (FW_Error_Type <= 0x03)
  {
    uint16_t connHandle;
    
    /* Data field is the connection handle where error has occurred */
    connHandle = LE_TO_HOST_16(Data);
    
    aci_gap_terminate(connHandle, BLE_ERROR_TERMINATED_REMOTE_USER); 
  }
}

#ifdef  USE_FULL_ASSERT

/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
*/
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  
  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
/** \endcond
 */
