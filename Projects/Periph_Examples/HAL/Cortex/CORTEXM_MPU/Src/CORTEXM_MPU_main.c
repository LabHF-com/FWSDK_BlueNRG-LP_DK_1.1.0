
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : CORTEXM_MPU_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the CORTEX MPU functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  CORTEXM_MPU/CORTEXM_MPU_main.c
 * @brief  This example configures a memory area as 
 * privileged read-only, and attempts to perform read and write operations in
 * different modes.
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\Cortex\\CORTEXM_MPU\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\CORTEXM_MPU.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\Cortex\\CORTEXM_MPU\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\CORTEXM_MPU.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\Cortex\\CORTEXM_MPU\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
  -# Select desired configuration to build
  -# Select Project->Build Project. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Run->Run/Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \subsection Project_configurations Project configurations
- \c Test_Access_NOT_permitted - Access not permitted configuration
- \c Test_Access_permitted - Access permitted configuration


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
|  PIN name  | STEVAL-IDB011V{1-2} | STEVAL-IDB012V1|
--------------------------------------------------------
|     A1     |       Not Used      |      USART TX      |
|     A11    |       Not Used      |      Not Used      |
|     A12    |       Not Used      |        N.A.        |
|     A13    |       Not Used      |        N.A.        |
|     A14    |       Not Used      |        N.A.        |
|     A15    |       Not Used      |        N.A.        |
|     A4     |       Not Used      |        N.A.        |
|     A5     |       Not Used      |        N.A.        |
|     A6     |       Not Used      |        N.A.        |
|     A7     |       Not Used      |        N.A.        |
|     A8     |       USART TX      |      Not Used      |
|     A9     |       USART RX      |      Not Used      |
|     B0     |       Not Used      |      USART RX      |
|     B14    |       Not Used      |      Not Used      |
|     B2     |       Not Used      |      Not Used      |
|     B3     |       Not Used      |      Not Used      |
|     B4     |       Not Used      |        DL2         |
|     B5     |       Not Used      |      Not Used      |
|     B7     |       Not Used      |      Not Used      |
|     B8     |         DL2         |        N.A.        |
|     B9     |         DL3         |        N.A.        |
|     A0     |         N.A.        |      Not Used      |
|     A10    |         N.A.        |      Not Used      |
|     B1     |         N.A.        |      Not Used      |
|     B6     |         N.A.        |      Not Used      |
|     B15    |         N.A.        |      Not Used      |
|     GND    |       Not Used      |      Not Used      |
|     RST    |       Not Used      |      Not Used      |
|    VBAT    |       Not Used      |      Not Used      |
@endtable 

* \section Serial_IO Serial I/O
@table
| Parameter name  | Value            | Unit      |
----------------------------------------------------
| Baudrate        | 115200 [default] | bit/sec   |
| Data bits       | 8                | bit       |
| Parity          | None             | bit       |
| Stop bits       | 1                | bit       |
@endtable

* \section LEDs_description LEDs description
@table
|            |                                                                        Test_Access_permitted                                                                        |||||                                                                      Test_Access_NOT_permitted                                                                      |||||
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  LED name  |         STEVAL-IDB010V1        |         STEVAL-IDB011V1        |         STEVAL-IDB011V2        |         STEVAL-IDB012V1        |         STEVAL-IDB013V1        |         STEVAL-IDB010V1        |         STEVAL-IDB011V1        |         STEVAL-IDB011V2        |         STEVAL-IDB012V1        |         STEVAL-IDB013V1        |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |
|     DL2    |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |   ON: the access is permitted  |
|     DL3    |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |   ON: Hard fault is generated  |
|     DL4    |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |
|     U5     |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |            Not Used            |

@endtable


* \section Buttons_description Buttons description
@table
|                |                                                         Test_Access_permitted                                                         |||||                                                                 Test_Access_NOT_permitted                                                                 |||||
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|   BUTTON name  |      STEVAL-IDB010V1     |      STEVAL-IDB011V1     |      STEVAL-IDB011V2     |      STEVAL-IDB012V1     |      STEVAL-IDB013V1     |        STEVAL-IDB010V1       |        STEVAL-IDB011V1       |        STEVAL-IDB011V2       |        STEVAL-IDB012V1       |        STEVAL-IDB013V1       |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |         Not Used         |         Not Used         |         Not Used         |         Not Used         |         Not Used         |           Not Used           |           Not Used           |           Not Used           |           Not Used           |           Not Used           |
|      PUSH2     |         Not Used         |         Not Used         |         Not Used         |         Not Used         |         Not Used         |           Not Used           |           Not Used           |           Not Used           |           Not Used           |           Not Used           |
|      RESET     |     Reset BlueNRG-LP     |     Reset BlueNRG-LP     |     Reset BlueNRG-LP     |     Reset BlueNRG-LPS    |     Reset BlueNRG-LPS    |       Reset BlueNRG-LP       |       Reset BlueNRG-LP       |       Reset BlueNRG-LP       |       Reset BlueNRG-LPS      |       Reset BlueNRG-LPS      |

@endtable

* \section Usage Usage

Presentation of the MPU feature. This example configures a memory area as privileged read-only, and attempts to perform read and write operations in different modes.

If the access is permitted LED2 is On. If the access is not permitted, a Hard fault is generated and LED3 is ON.


Rebuild all files and load your image into target memory to generate an MPU memory fault exception due to an access right error, uncomment the following line:
- Comment "#define ACCESS_PERMISSION" the access is permitted 
- Uncomment "#define ACCESS_PERMISSION" to generate an MPU memory fault


In order to make the program work, you must do the following:
 - Launch serial communication SW on PC
 - Flash the project in the Board
 - Press the RESET button

BlueNRG_LP-EVB Set-up
Connect USART1 TX/RX to respectively RX and TX pins of PC UART (could be done through a USB to UART adapter) :
- Connect BlueNRG_LP board USART1 TX pin to PC COM port RX signal
- Connect BlueNRG_LP board USART1 RX pin to PC COM port TX signal
- Connect BlueNRG_LP board GND to PC COM port GND signal

Launch serial communication SW on PC (as HyperTerminal or TeraTerm) with proper configuration :
- 115200 bauds
- 8 bits data
- 1 start bit
- 1 stop bit
- no parity
- no HW flow control 
**/
   

/* Includes ------------------------------------------------------------------*/
#include "CORTEXM_MPU_main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
__IO uint32_t AccessPermitted = 1;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
* @brief  The application entry point.
* @retval int
*/
int main(void)
{
  /* System initialization function */
  if (SystemInit(SYSCLK_32M, RADIO_SYSCLK_NONE) != SUCCESS)
  {
    /* Error during system clock configuration take appropriate action */
    while(1);
  }
  
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();
  
  /* IO pull configuration with minimum power consumption */
  BSP_IO_Init();
  
  /* Initialization of COM port */
  BSP_COM_Init(NULL);
  
  printf("** Application started **\n\r");
  
  /* Initialize all configured peripherals */
  /* Configure LED2 and LED3 */
  BSP_LED_Init(BSP_LED2);
  BSP_LED_Init(BSP_LED3);
  
  /* Set MPU regions */
  MPU_Config();
  
  MPU_AccessPermConfig();
    
  if( AccessPermitted == 1 )
  {
    /* Turn on LED2 */
    BSP_LED_On(BSP_LED2);
    printf("Write access is permitted.\n\r");
#ifndef ACCESS_PERMISSION
    printf("** Test successfully. ** \n\r\n\r");
#else
    printf("** Test fail. ** \n\r\n\r");
#endif
  }
  
  /* Infinite loop */
  while (1)
  {
  }
}

/**
* @brief  This function is executed in case of error occurrence.
* @retval None
*/
void Error_Handler(void)
{
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
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
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



