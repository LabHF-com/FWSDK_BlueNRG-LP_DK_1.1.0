
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : IWDG_Refresh_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the IWDG functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file IWDG_Refresh/IWDG_Refresh_main.c
 * @brief How to configure the IWDG peripheral to ensure periodical counter update and 
 * generate an MCU IWDG reset when a User push-button (PUSH1) is pressed. The peripheral 
 * is initialized with LL unitary service functions to optimize for performance and size.
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\IWDG\\IWDG_Refresh\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\IWDG_Refresh.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\IWDG\\IWDG_Refresh\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\IWDG_Refresh.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\LL\\IWDG\\IWDG_Refresh\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
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
|  LED name  |                       STEVAL-IDB010V1                      |                       STEVAL-IDB011V1                      |                       STEVAL-IDB011V2                      |                       STEVAL-IDB012V1                      |                       STEVAL-IDB013V1                      |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |
|     DL2    |   Blinking: application is running - Slow blinking: error  |   Blinking: application is running - Slow blinking: error  |   Blinking: application is running - Slow blinking: error  |   Blinking: application is running - Slow blinking: error  |   Blinking: application is running - Slow blinking: error  |
|     DL3    |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |
|     DL4    |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |
|     U5     |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |                          Not Used                          |

@endtable


* \section Buttons_description Buttons description
@table
|   BUTTON name  |              STEVAL-IDB010V1             |              STEVAL-IDB011V1             |              STEVAL-IDB011V2             |              STEVAL-IDB012V1             |              STEVAL-IDB013V1             |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |   Activate the IWDG if LED2 is blinking  |   Activate the IWDG if LED2 is blinking  |   Activate the IWDG if LED2 is blinking  |   Activate the IWDG if LED2 is blinking  |   Activate the IWDG if LED2 is blinking  |
|      PUSH2     |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |
|      RESET     |             Reset BlueNRG-LP             |             Reset BlueNRG-LP             |             Reset BlueNRG-LP             |             Reset BlueNRG-LPS            |             Reset BlueNRG-LPS            |

@endtable

* \section Usage Usage

How to configure the IWDG peripheral to ensure periodical counter update and generate an MCU IWDG reset when a User push-button (PUSH1) is pressed. 
The peripheral is initialized with LL unitary service functions to optimize for performance and size.

Example Configuration:
Configure the IWDG (prescaler, counter) and enable it.
Infinite refresh of the IWDG down-counter done in the main loop.
LED2 is blinking fast and continuously.

Example Execution:
When User push-button (PUSH1) is pressed, the down-counter automatic refresh mechanism is disable and thus, reset will occur. After a reset, when re-entering in the main, RCC IWDG Reset Flag will be checked and if we are back from a IWDG reset will be showed an information over the UART.


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
#include "IWDG_Refresh_main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

static __IO uint8_t ubKeyPressed = 0;

/* Private function prototypes -----------------------------------------------*/
void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes);
static void MX_GPIO_Init(void);
static void MX_IWDG_Init(void);
void Check_IWDG_Reset(void);
void LED2_On(void);
void LED2_Off(void);
void LED2_Toggle(void);
void LED3_On(void);
void LED3_Off(void);
void LED3_Toggle(void);

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
  
  /* Set systick to 1ms using system clock frequency */
  LL_Init1msTick(SystemCoreClock); 
   
  /* IO pull configuration with minimum power consumption */
  BSP_IO_Init();
  
  /* Initialization of COM port */
  BSP_COM_Init(Process_InputData);
  
  printf("** Application started **\n\r");
  
  printf("Application started\n\r");  
  	
  /* Check if the system has resumed from IWDG reset */
  Check_IWDG_Reset();
  
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  
  MX_IWDG_Init(); 
  
  printf("Wait for User push-button (PUSH1) press or enter 'c'/'C' character.\n\r");
  printf("Also the reset button can be used for this test.\n\r");
  
  /* Infinite loop */
  while (1)
  {
    if (1 != ubKeyPressed)
    {
      /* Refresh IWDG down-counter to default value */
      LL_IWDG_ReloadCounter(IWDG);
      
      /* Toggle LED2 */
      LED2_Toggle();
      
      /* Note that period used for Counter Reload MUST be higher than blinking timing value*/
      /* This Counter reload timeout period is a function of this value and the 
      clock prescaler. Refer to the datasheet for the timeout information  */
      LL_mDelay(LED_BLINK_FAST);
    }
  }
}


/**
* @brief IWDG Initialization Function
* @param None
* @retval None
*/
static void MX_IWDG_Init(void)
{  
  /* Enable APB0 indipendent Watchdog peripherals clock */
  LL_APB0_EnableClock(LL_APB0_PERIPH_WDG);
  
  /* Force WDG peripheral reset */
  LL_APB0_ForceReset(LL_APB0_PERIPH_WDG);
  LL_APB0_ReleaseReset(LL_APB0_PERIPH_WDG);
  
  /* Check if WDG Reset Release flag interrupt occurred or not */
  while(LL_RCC_IsActiveFlag_WDGRSTREL() == 0)
  {
  }
    
  LL_IWDG_Enable(IWDG);
  LL_IWDG_EnableWriteAccess(IWDG);
  LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_4);
  LL_IWDG_SetWindow(IWDG, 0xFFF);
  LL_IWDG_SetReloadCounter(IWDG, 0xFFE);
  while (LL_IWDG_IsReady(IWDG) != 1)
  {
  }
  
  LL_IWDG_ReloadCounter(IWDG);
}
/**
* @brief GPIO Initialization Function
* @param None
* @retval None
*/
static void MX_GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};
  
  /* GPIO Ports Clock Enable */
  LED2_GPIO_CLK_ENABLE();
  USER_BUTTON_GPIO_CLK_ENABLE();
  USER_BUTTON_SYSCFG_CLK_ENABLE();
  
  /* Configure GPIO for LED */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
  GPIO_InitStruct.Pin = LED2_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);
  
  /* Turn Off Led2 */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
  
  LL_GPIO_SetOutputPin(LED3_GPIO_PORT, LED3_PIN);
  GPIO_InitStruct.Pin = LED3_PIN;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);
   
  /* Configure GPIO for BUTTON */
  LL_GPIO_SetPinPull(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_PULL_NO);
  LL_GPIO_SetPinMode(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN, LL_GPIO_MODE_INPUT);
 
  /* Enable a rising trigger External line 10 Interrupt */
  EXTI_InitStruct.Line = LL_EXTI_LINE_PA10;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Type = LL_EXTI_TYPE_EDGE;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_EDGE;
  LL_EXTI_Init(&EXTI_InitStruct);

  /* Configure NVIC for USER_BUTTON_EXTI_IRQn */
  NVIC_SetPriority(USER_BUTTON_EXTI_IRQn, IRQ_LOW_PRIORITY );
  NVIC_EnableIRQ(USER_BUTTON_EXTI_IRQn);
}

/**
* @brief  This function check if the system has resumed from IWDG reset
* @param  None
* @retval None
*/
void Check_IWDG_Reset(void)
{  
  volatile uint32_t wdg_flag = RAM_VR.ResetReason & RCC_CSR_WDGRSTF;
  /* check IWDG reset flag */
  if(wdg_flag == RCC_CSR_WDGRSTF)
  {
    printf("The system has resumed from IWDG reset\n\r");
    printf("** Test successfully. ** \n\r\n\r");
    //wdg_flag = 0;
  }
}

/**
* @brief  Turn-on LED2.
* @param  None
* @retval None
*/
void LED2_On(void)
{
  /* Turn LED2 on */
  LL_GPIO_ResetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/**
* @brief  Turn-off LED2.
* @param  None
* @retval None
*/
void LED2_Off(void)
{
  /* Turn LED2 off */
  LL_GPIO_SetOutputPin(LED2_GPIO_PORT, LED2_PIN);
}

/**
* @brief  Toggle LED2.
* @param  None
* @retval None
*/
void LED2_Toggle(void)
{
  /* Toggle LED2 */
  LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
}


/**
* @brief  Turn-on LED3.
* @param  None
* @retval None
*/
void LED3_On(void)
{
  /* Turn LED3 on */
  LL_GPIO_ResetOutputPin(LED3_GPIO_PORT, LED3_PIN);
}

/**
* @brief  Turn-off LED3.
* @param  None
* @retval None
*/
void LED3_Off(void)
{
  /* Turn LED3 off */
  LL_GPIO_SetOutputPin(LED3_GPIO_PORT, LED3_PIN);
}

/**
* @brief  Toggle LED3.
* @param  None
* @retval None
*/
void LED3_Toggle(void)
{
  /* Toggle LED3 */
  LL_GPIO_TogglePin(LED3_GPIO_PORT, LED3_PIN);
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
  ubKeyPressed = 1;
}

void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes)
{
  if(Nb_bytes>0)
  {
    if(data_buffer[0] == 'c' || data_buffer[0] == 'C' )
    {
      UserButton_Callback();
    }
  }
}

/**
* @brief  This function is executed in case of error occurrence.
* @retval None
*/
void Error_Handler(void)
{
  /* User can add his own implementation to report the HAL error return state */
  /* Toggle IO in an infinite loop */
  while (1)
  {
    LL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
    LL_mDelay(1000);
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
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
  tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


