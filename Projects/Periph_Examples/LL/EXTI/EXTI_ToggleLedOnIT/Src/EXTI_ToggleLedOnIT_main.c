
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : EXTI_ToggleLedOnIT_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the EXTI functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  EXTI_ToggleLedOnIT/EXTI_ToggleLedOnIT_main.c
 * @brief How to configure the EXTI and use GPIOs to toggle the user LEDs 
 * available on the board when a user button is pressed. It is based on the
 * BLUENRG_LP LL API. The peripheral initialization uses LL unitary service
 * functions for optimization purposes (performance and size).
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\EXTI\\EXTI_ToggleLedOnIT\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\EXTI_ToggleLedOnIT.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\EXTI\\EXTI_ToggleLedOnIT\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\EXTI_ToggleLedOnIT.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\EXTI\\EXTI_ToggleLedOnIT\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
  -# Select desired configuration to build
  -# Select Project->Build Project. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Run->Run/Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \subsection Project_configurations Project configurations
- \c Release - Release configuration


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
|     A1     |       Not Used      |      Not Used      |
|     A11    |       Not Used      |      Not Used      |
|     A12    |       Not Used      |        N.A.        |
|     A13    |       Not Used      |        N.A.        |
|     A14    |       Not Used      |        N.A.        |
|     A15    |       Not Used      |        N.A.        |
|     A4     |       Not Used      |        N.A.        |
|     A5     |       Not Used      |        N.A.        |
|     A6     |       Not Used      |        N.A.        |
|     A7     |       Not Used      |        N.A.        |
|     A8     |       Not Used      |      Not Used      |
|     A9     |       Not Used      |      Not Used      |
|     B0     |       Not Used      |      Not Used      |
|     B14    |       Not Used      |      Not Used      |
|     B2     |       Not Used      |      Not Used      |
|     B3     |       Not Used      |      Not Used      |
|     B4     |       Not Used      |        DL2         |
|     B5     |       Not Used      |      Not Used      |
|     B7     |       Not Used      |      Not Used      |
|     B8     |         DL2         |        N.A.        |
|     B9     |       Not Used      |        N.A.        |
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
{SERIAL_IO_TABLE}
@endtable

* \section LEDs_description LEDs description
@table
|  LED name  |            STEVAL-IDB010V1           |            STEVAL-IDB011V1           |            STEVAL-IDB011V2           |            STEVAL-IDB012V1           |            STEVAL-IDB013V1           |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |               Not Used               |               Not Used               |               Not Used               |               Not Used               |               Not Used               |
|     DL2    |   ON: PUSH1 rising edge is detected  |   ON: PUSH1 rising edge is detected  |   ON: PUSH1 rising edge is detected  |   ON: PUSH1 rising edge is detected  |   ON: PUSH1 rising edge is detected  |
|     DL3    |               Not Used               |               Not Used               |               Not Used               |               Not Used               |               Not Used               |
|     DL4    |               Not Used               |               Not Used               |               Not Used               |               Not Used               |               Not Used               |
|     U5     |               Not Used               |               Not Used               |               Not Used               |               Not Used               |               Not Used               |

@endtable

* \section Buttons_description Buttons description
@table
|   BUTTON name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |
------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |   LED2 is toggled  |   LED2 is toggled  |   LED2 is toggled  |    LED2 is toggled   |    LED2 is toggled   |
|      PUSH2     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      RESET     |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |

@endtable

* \section Usage Usage

How to configure the EXTI and use GPIOs to toggle the user LEDs available on the board when a user button is pressed. 
It is based on the BLUENRG_LP LL API. 
The peripheral initialization uses LL unitary service functions for optimization purposes (performance and size).
Peripheral initialization can be also done using LL initialization function to demonstrate LL init usage defining the preprocessor define USE_LL_INIT.

In this example, one EXTI line is configured to generate an interrupt on each rising edge.

In the interrupt routine a led connected to a specific GPIO pin is toggled.

In this example:
    - External line 10 is connected to PA.10 pin
    - when falling edge is detected on External line 10 by pressing User push-button (PUSH1), LED2 toggles

On BlueNRG_LP-EVB:
    - External line 10 is connected to User push-button (PUSH1)

**/
   

/* Includes ------------------------------------------------------------------*/
#include "EXTI_ToggleLedOnIT_main.h"

/** @addtogroup RF_DRIVER_LL_Examples
  * @{
  */

/** @addtogroup EXTI_ToggleLedOnIT
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void Configure_EXTI(void);
void MX_GPIO_Init(void);
void LED_Init(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* System initialization function */
  if (SystemInit(SYSCLK_32M, RADIO_SYSCLK_NONE) != SUCCESS)
  {
    /* Error during system clock configuration take appropriate action */
    while(1);
  }
  
  /* Set systick to 1ms using system clock frequency */
  LL_Init1msTick(SystemCoreClock); 

  /* Initialization of COM port */
  BSP_COM_Init(NULL);
  
  printf("** Application started **\n\r");
  
  /* Initialize LED2 */
  LED_Init();
 
  /* Initialize configured peripherals */
#if defined(USE_LL_UNITARY)
  /* LL unitary functions calls */
  /* Configure the EXTI Line on User Button */
  Configure_EXTI();  
#elif defined(USE_LL_INIT)
  /* LL Init function call */
  /* Initialize peripheral */
  MX_GPIO_Init();
#endif 
  
  printf("Wait for User push-button (PUSH1) press.\n\r");
  
  /* Infinite loop */
  while (1)
  {
  }
}


/**
  * @brief  This function configures EXTI Line as Push-Button
  * @note   Peripheral configuration is minimal configuration from reset values.  
  * @param  None
  * @retval None
  */
void Configure_EXTI()
{
  /* Enable the BUTTON Clock */
  USER_BUTTON_GPIO_CLK_ENABLE();
  USER_BUTTON_SYSCFG_CLK_ENABLE();
  
  /* Configure GPIO for BUTTON */
  LL_GPIO_SetPinMode(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_PULL_NO);

  /* Enable a rising trigger External line 10 Interrupt */
  USER_BUTTON_EXTI_LINE_ENABLE();
  USER_BUTTON_EXTI_RISING_TRIG_ENABLE();
  
  /* Clear the event occurred on the interrupt line 10 port A. */
  if (LL_EXTI_IsInterruptPending(USER_BUTTON_EXTI_LINE) != RESET)
  {
    LL_EXTI_ClearInterrupt(USER_BUTTON_EXTI_LINE);
  }

  /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, IRQ_LOW_PRIORITY );
  NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn);

  /* Configure NVIC for SysTick_IRQn */
  NVIC_SetPriority(SysTick_IRQn, IRQ_LOW_PRIORITY);
}

/**
* @brief GPIO Initialization Function
* @param None
* @retval None
*/
void MX_GPIO_Init(void)
{
  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
  
  /* GPIO Ports Clock Enable */
  USER_BUTTON_GPIO_CLK_ENABLE();
  USER_BUTTON_SYSCFG_CLK_ENABLE();
  
  /* Configure GPIO for BUTTON */
  LL_GPIO_SetPinMode(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_MODE_INPUT);
  LL_GPIO_SetPinPull(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_PULL_NO);
  
  /* Enable a rising trigger External line 10 Interrupt */
  EXTI_InitStruct.Line = LL_EXTI_LINE_PA10;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Type = LL_EXTI_TYPE_EDGE;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_EDGE;
  LL_EXTI_Init(&EXTI_InitStruct);
  
  /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, IRQ_LOW_PRIORITY );
  NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn);
  
  /* Configure NVIC for SysTick_IRQn */
  NVIC_SetPriority(SysTick_IRQn, IRQ_LOW_PRIORITY);
}

/**
  * @brief  Initialize LED2.
  * @param  None
  * @retval None
  */
void LED_Init(void)
{
  /* Enable the LED2 Clock */
  LED2_GPIO_CLK_ENABLE();

  /* Configure IO in output push-pull mode to drive external LED2 */
  LL_GPIO_SetPinMode(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_MODE_OUTPUT);
  /* Reset value is LL_GPIO_OUTPUT_PUSHPULL */
  LL_GPIO_SetPinOutputType(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_OUTPUT_PUSHPULL);
  /* Reset value is LL_GPIO_SPEED_FREQ_LOW */
  LL_GPIO_SetPinSpeed(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_SPEED_FREQ_HIGH);
  /* Reset value is LL_GPIO_PULL_NO */
  LL_GPIO_SetPinPull(LED2_GPIO_PORT, LED2_PIN, LL_GPIO_PULL_NO);

  /* Turn LED2 off */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/******************************************************************************/
/*   USER IRQ HANDLER TREATMENT                                               */
/******************************************************************************/
/**
  * @brief  Function to manage IRQ Handler
  * @param  None
  * @retval None
  */
void UserButton_Callback(void)
{
  LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
  printf("** Test successfully. ** \n\r\n\r");  
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



