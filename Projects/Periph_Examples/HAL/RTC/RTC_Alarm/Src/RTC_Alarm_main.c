
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : RTC_Alarm_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 19-April-2019
* Description        : Code demonstrating the basic RTC functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  RTC_Alarm/RTC_Alarm_main.c
 * @brief Configuration and generation of an RTC alarm .
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\RTC\\RTC_Alarm\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\RTC_Alarm.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\RTC\\RTC_Alarm\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\RTC_Alarm.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\RTC\\RTC_Alarm\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
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
|  LED name  |        STEVAL-IDB010V1       |        STEVAL-IDB011V1       |        STEVAL-IDB011V2       |        STEVAL-IDB012V1       |        STEVAL-IDB013V1       |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |           Not Used           |           Not Used           |           Not Used           |           Not Used           |           Not Used           |
|     DL2    |  On: RTC Alarm is generated  |  On: RTC Alarm is generated  |  On: RTC Alarm is generated  |  On: RTC Alarm is generated  |  On: RTC Alarm is generated  |
|     DL3    |     Slow blinking: error     |     Slow blinking: error     |     Slow blinking: error     |     Slow blinking: error     |     Slow blinking: error     |
|     DL4    |           Not Used           |           Not Used           |           Not Used           |           Not Used           |           Not Used           |
|     U5     |           Not Used           |           Not Used           |           Not Used           |           Not Used           |           Not Used           |

@endtable

* \section Buttons_description Buttons description
@table
|   BUTTON name  |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |
------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      PUSH2     |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      RESET     |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |

@endtable

* \section Usage Usage

Configuration and generation of an RTC alarm using the RTC HAL API.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals, initialize the Flash interface and the systick.

The RTC peripheral configuration is ensured by the HAL_RTC_Init() function.
This later is calling the HAL_RTC_MspInit() function which core is implementing the configuration of the needed RTC resources according to the used hardware (CLOCK, PWR, RTC clock source and BackUp). 
You may update this function to change RTC configuration.

HAL_RTC_SetDate() and HAL_RTC_SetTime() functions are called to initialize the time and the date.
HAL_RTC_SetAlarm_IT() function is then called to initialize the Alarm feature with interrupt mode.

In this example, the Time is set to 23:59:50 and the Alarm must be generated on 00:00:00.

LED2 is turned ON when the RTC Alarm is generated correctly.

The current time is updated and displayed on the USART.

In case of error, LED3 is toggled with a period of one second.

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
#include "RTC_Alarm_main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint32_t pressCToContinue = 0;
RTC_HandleTypeDef hrtc;

/* Buffer used for displaying Time */
uint8_t aShowTime[16] = "hh:ms:ss";
__IO uint32_t RTCStatus = 0;

/* Private function prototypes -----------------------------------------------*/
void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes);
static void MX_RTC_Init(void);
void RTC_TimeShow(uint8_t *showtime);

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
  HAL_Init();
  
  /* IO pull configuration with minimum power consumption */
  BSP_IO_Init();
  
  /* Initialization of COM port */
  BSP_COM_Init(Process_InputData);
  
  printf("** Application started **\n\r");
  
  /* Configure LED2 and LED3 */
  BSP_LED_Init(BSP_LED2);
  BSP_LED_Init(BSP_LED3);
  
  /* Initialize all configured peripherals */
  MX_RTC_Init();
  
  /* Infinite loop */
  RTCStatus = 1;
  while (1)
  {
    HAL_Delay(1000);
    /* Display the updated Time */
    RTC_TimeShow(aShowTime);
    
  }
}

/**
* @brief RTC Initialization Function
* @param None
* @retval None
*/
static void MX_RTC_Init(void)
{
  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};
  RTC_AlarmTypeDef sAlarm = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};

  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) == HAL_OK)
  { 
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
    
    /* Initialize RTC Only */
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
    hrtc.Init.SynchPrediv = RTC_SYNCH_PREDIV;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
      Error_Handler();
    }
    /* Initialize RTC and set the Time and Date */
    sTime.Hours = 0x23;
    sTime.Minutes = 0x59;
    sTime.Seconds = 0x50;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
    {
      Error_Handler();
    }
    sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
    sDate.Month = RTC_MONTH_DECEMBER;
    sDate.Date = 0x31;
    sDate.Year = 0x19;
    if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
    {
      Error_Handler();
    }
    /* Enable the Alarm A */
    sAlarm.AlarmTime.Hours = 0x0;
    sAlarm.AlarmTime.Minutes = 0x00;
    sAlarm.AlarmTime.Seconds = 0x00;
    sAlarm.AlarmTime.SubSeconds = 0x00;
    sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
    sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
    sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
    sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
    sAlarm.AlarmDateWeekDay = RTC_WEEKDAY_WEDNESDAY;
    sAlarm.Alarm = RTC_ALARM_A;
    if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BCD) != HAL_OK)
    {
      Error_Handler();
    }
    /* Configure the NVIC for RTC Alarm */
    NVIC_SetPriority(RTC_IRQn, IRQ_LOW_PRIORITY );
    NVIC_EnableIRQ(RTC_IRQn);
  }
}

/**
* @brief  Alarm callback
* @param  hrtc : RTC handle
* @retval None
*/
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  /* Turn LED2 on: Alarm generation */
  BSP_LED_On(BSP_LED2);
  printf("\tLED2 On: Alarm generated");
}

/**
* @brief  Display the current time.
* @param  showtime : pointer to buffer
* @retval None
*/
void RTC_TimeShow(uint8_t *showtime)
{
  RTC_DateTypeDef sdatestructureget;
  RTC_TimeTypeDef stimestructureget;
  
  /* Get the RTC current Time */
  HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
  /* Get the RTC current Date */
  HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);
  /* Display time Format : hh:mm:ss */
  sprintf((char *)showtime, "%02d:%02d:%02d", stimestructureget.Hours, stimestructureget.Minutes, stimestructureget.Seconds);
 
  // print on the UART the time and date
  BSP_COM_Write("\n\r", 2);
  BSP_COM_Write("\n\r", 2);
  BSP_COM_Write((uint8_t *)aShowTime, sizeof(aShowTime)+1);
}


void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes)
{
  if(Nb_bytes>0)
  {
    if(data_buffer[0] == 'c' || data_buffer[0] == 'C' )
    {
      pressCToContinue = 1;
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
  RTCStatus = 0xE;
  while (1)
  {
    /* Toggle LED3 with a period of one second */
    BSP_LED_Toggle(BSP_LED3);
    HAL_Delay(1000);
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
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


