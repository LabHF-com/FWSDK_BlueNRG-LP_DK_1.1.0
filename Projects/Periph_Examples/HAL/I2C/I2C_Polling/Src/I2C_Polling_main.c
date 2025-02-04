
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : I2C_Polling_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the I2C functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  I2C_Polling/I2C_Polling_main.c
 * @brief How to handle I2C data buffer transmission/reception between two boards, in polling mode.
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\I2C\\I2C_Polling\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\I2C_Polling.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\I2C\\I2C_Polling\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\I2C_Polling.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\I2C\\I2C_Polling\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
  -# Select desired configuration to build
  -# Select Project->Build Project. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Run->Run/Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \subsection Project_configurations Project configurations
- \c Master_board - Master configuration
- \c Slave_board - Slave configuration


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
|     A13    |       I2C2 SCL      |        N.A.        |
|     A14    |       I2C2 SDA      |        N.A.        |
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
|     B7     |       Not Used      |      I2C2 SDA      |
|     B8     |         DL2         |        N.A.        |
|     B9     |         DL3         |        N.A.        |
|     A0     |         N.A.        |      Not Used      |
|     A10    |         N.A.        |      Not Used      |
|     B1     |         N.A.        |      Not Used      |
|     B6     |         N.A.        |      I2C2 SCL      |
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
|            |                                                                                                                                                                                                    Master_board                                                                                                                                                                                                     |||||                                                                                                      Slave_board                                                                                                      |||||
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|  LED name  |                                 STEVAL-IDB010V1                                |                                 STEVAL-IDB011V1                                |                                 STEVAL-IDB011V2                                |                                 STEVAL-IDB012V1                                |                                 STEVAL-IDB013V1                                |              STEVAL-IDB010V1             |              STEVAL-IDB011V1             |              STEVAL-IDB011V2             |              STEVAL-IDB012V1             |              STEVAL-IDB013V1             |
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |
|     DL2    |   ON:the transmission process is complete - Blinking: waiting for User action  |   ON:the transmission process is complete - Blinking: waiting for User action  |   ON:the transmission process is complete - Blinking: waiting for User action  |   ON:the transmission process is complete - Blinking: waiting for User action  |   ON:the transmission process is complete - Blinking: waiting for User action  |   ON: the reception process is complete  |   ON: the reception process is complete  |   ON: the reception process is complete  |   ON: the reception process is complete  |   ON: the reception process is complete  |
|     DL3    |                                    ON: error                                   |                                    ON: error                                   |                                    ON: error                                   |                                    ON: error                                   |                                    ON: error                                   |                 ON: error                |                 ON: error                |                 ON: error                |                 ON: error                |                 ON: error                |
|     DL4    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |
|     U5     |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                                    Not Used                                    |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |                 Not Used                 |

@endtable


* \section Buttons_description Buttons description
@table
|                |                                                                                                                                                                                                                                                 Master_board                                                                                                                                                                                                                                                  |||||                                                 Slave_board                                                 |||||
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|   BUTTON name  |                                          STEVAL-IDB010V1                                         |                                          STEVAL-IDB011V1                                         |                                          STEVAL-IDB011V2                                         |                                          STEVAL-IDB012V1                                         |                                          STEVAL-IDB013V1                                         |   STEVAL-IDB010V1  |   STEVAL-IDB011V1  |   STEVAL-IDB011V2  |    STEVAL-IDB012V1   |    STEVAL-IDB013V1   |
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |   1stPush:Master starts the transmission process - 2ndPush: Master starts the reception process  |   1stPush:Master starts the transmission process - 2ndPush: Master starts the reception process  |   1stPush:Master starts the transmission process - 2ndPush: Master starts the reception process  |   1stPush:Master starts the transmission process - 2ndPush: Master starts the reception process  |   1stPush:Master starts the transmission process - 2ndPush: Master starts the reception process  |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      PUSH2     |                                             Not Used                                             |                                             Not Used                                             |                                             Not Used                                             |                                             Not Used                                             |                                             Not Used                                             |      Not Used      |      Not Used      |      Not Used      |       Not Used       |       Not Used       |
|      RESET     |                                         Reset BlueNRG-LP                                         |                                         Reset BlueNRG-LP                                         |                                         Reset BlueNRG-LP                                         |                                         Reset BlueNRG-LPS                                        |                                         Reset BlueNRG-LPS                                        |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |  Reset BlueNRG-LP  |   Reset BlueNRG-LPS  |   Reset BlueNRG-LPS  |

@endtable

* \section Usage Usage

How to handle I2C data buffer transmission/reception between two boards, in polling mode.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals, initialize the Flash interface and the systick.

The I2C peripheral configuration is ensured by the HAL_I2C_Init() function.
This later is calling the HAL_I2C_MspInit()function which core is implementing the configuration of the needed I2C resources according to the used hardware (CLOCK, GPIO). 
You may update this function to change I2C configuration.

The I2C communication is then initiated.
The project is split in two parts: the Master Board and the Slave Board
- Master Board
  The HAL_I2C_Master_Receive() and the HAL_I2C_Master_Transmit() functions 
  allow respectively the reception and the transmission of a predefined data buffer
  in Master mode using polling.
- Slave Board
  The HAL_I2C_Slave_Receive() and the HAL_I2C_Slave_Transmit() functions 
  allow respectively the reception and the transmission of a predefined data buffer
  in Slave mode using polling.
The user can choose between Master and Slave through "#define MASTER_BOARD" in the "I2C_Polling_main.c" file:
If the Master board is used, the "#define MASTER_BOARD" must be uncommented.
If the Slave board is used the "#define MASTER_BOARD" must be commented.

For this example the aTxBuffer is predefined and the aRxBuffer size is same as aTxBuffer.

In a first step after the user press the User push-button (PUSH1) on the Master Board,
I2C Master starts the communication by sending aTxBuffer through HAL_I2C_Master_Transmit()
to I2C Slave which receives aRxBuffer through HAL_I2C_Slave_Receive(). 
The second step starts when the user press the User push-button (PUSH1) on the Master Board,
the I2C Slave sends aTxBuffer through HAL_I2C_Slave_Transmit()
to the I2C Master which receives aRxBuffer through HAL_I2C_Master_Receive().
The end of this two steps are monitored through the HAL_I2C_GetState() function
result.
Finally, aTxBuffer and aRxBuffer are compared through Buffercmp() in order to 
check buffers correctness.  

BlueNRG_LP-EVB's LEDs can be used to monitor the transfer status:
 - LED2 is ON when the transmission process is complete.
 - LED2 is OFF when the reception process is complete.
 - LED3 is ON when there is an error in transmission/reception process.  

Timeout is set to 10 Seconds which means that if no communication occurs during 10 Seconds, a Timeout Error will be generated.

In order to make the program work, you must do the following : 
 -Rebuild all files and load your image into target memory.
    Uncomment "#define MASTER_BOARD" and load the project in Master Board
    Comment   "#define MASTER_BOARD" and load the project in Slave Board
 - Launch serial communication SW on PC
 - Flash the project in the Board
 - Press the RESET button

BlueNRG_LP-EVB Set-up
- Connect I2C_SCL line of Master board to I2C_SCL line of Slave Board.
- Connect I2C_SDA line of Master board to I2C_SDA line of Slave Board.
- Connect GND of Master board to GND of Slave Board.
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
#include "I2C_Polling_main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint32_t pressCToContinue = 0;
I2C_HandleTypeDef hi2cx;
/* Buffer used for transmission */
uint8_t aTxBuffer[] = " ****I2C_TwoBoards communication based on Polling****  ****I2C_TwoBoards communication based on Polling****  ****I2C_TwoBoards communication based on Polling**** ";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];

/* Private function prototypes -----------------------------------------------*/
void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes);

static void MX_GPIO_Init(void);
static void MX_I2Cx_Init(void);
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

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

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2Cx_Init();
  
  /* Configure LED2 and LED3 */
  BSP_LED_Init(BSP_LED2);
  BSP_LED_Init(BSP_LED3);
  
#ifdef MASTER_BOARD
  printf("Master board\n\r");
  
  /* Configure User push-button (PUSH1) */
  BSP_PB_Init(BSP_PUSH1,BUTTON_MODE_GPIO);
  
  /* Infinite loop */
  /* Wait for User push-button (PUSH1) press before starting the Communication */
  printf("Wait for User push-button (PUSH1) press or enter 'c'/'C' character.\n\r");
  while((BSP_PB_GetState(BSP_PUSH1) == GPIO_PIN_RESET) && (pressCToContinue == 0))
  {
    BSP_LED_Toggle(BSP_LED2);
    HAL_Delay(100);
  }
  BSP_LED_Off(BSP_LED2);
  
  /* Delay to avoid that possible signal rebound is taken as button release */
  HAL_Delay(1000);
  
  /* The board sends the message and expects to receive it back */
  
  /* - Start the transmission process */  
  /* While the I2C in reception process, user can transmit data through 
  "aTxBuffer" buffer */
  printf("Start the transmission process.\n\r");
  printf("Timeout is set to 10S.\n\r");
  /* Timeout is set to 10S */
  while(HAL_I2C_Master_Transmit(&hi2cx, (uint16_t)I2C_ADDRESS, (uint8_t*)aTxBuffer, TXBUFFERSIZE, 10000)!= HAL_OK)
  {
    /* Error_Handler() function is called when Timeout error occurs.
    When Acknowledge failure occurs (Slave don't acknowledge its address)
    Master restarts communication */
    if (HAL_I2C_GetError(&hi2cx) != HAL_I2C_ERROR_AF)
    {
      printf("Timeout error occurs.\n\r");
      Error_Handler();
    }
  }
  
  /* Wait for User push-button (PUSH1) press before starting the Communication */
  printf("Wait for User push-button (PUSH1) press or enter 'c'/'C' character.\n\r");
  while((BSP_PB_GetState(BSP_PUSH1) == GPIO_PIN_RESET) && (pressCToContinue == 0))
  {
    BSP_LED_Toggle(BSP_LED2);
    HAL_Delay(100);
  }
  BSP_LED_Off(BSP_LED2);
  
  /* Delay to avoid that possible signal rebound is taken as button release */
  HAL_Delay(1000);
  
  /* - Put I2C peripheral in reception process */ 
  printf("Put I2C peripheral in reception process.\n\r");
  printf("Timeout is set to 10S.\n\r");
  /* Timeout is set to 10S */ 
  while(HAL_I2C_Master_Receive(&hi2cx, (uint16_t)I2C_ADDRESS, (uint8_t *)aRxBuffer, RXBUFFERSIZE, 10000) != HAL_OK)
  {
    /* Error_Handler() function is called when Timeout error occurs.
    When Acknowledge failure occurs (Slave don't acknowledge it's address)
    Master restarts communication */
    if (HAL_I2C_GetError(&hi2cx) != HAL_I2C_ERROR_AF)
    {
      printf("Timeout error occurs.\n\r");
      Error_Handler();
    }
  }
  
#else
  printf("Slave board\n\r");
  
  /* The board receives the message and sends it back */
  printf("The board receives the message and sends it back.\n\r");
  /* - Put I2C peripheral in reception process */ 
  printf("Put I2C peripheral in reception process.\n\r");
  /* Timeout is set to 10s  */
  printf("Timeout is set to 10s.\n\r");
  if(HAL_I2C_Slave_Receive(&hi2cx, (uint8_t *)aRxBuffer, RXBUFFERSIZE, 10000) != HAL_OK)
  {
    printf("Timeout error occurs.\n\r");
    /* Transfer error in reception process */
    Error_Handler();
  }
  
  /* - Start the transmission process */  
  printf("Start the transmission process.\n\r");
  /* While the I2C in reception process, user can transmit data through 
  "aTxBuffer" buffer */
  /* Timeout is set to 10s */
  printf("Timeout is set to 10s.\n\r");
  if(HAL_I2C_Slave_Transmit(&hi2cx, (uint8_t*)aTxBuffer, TXBUFFERSIZE, 10000)!= HAL_OK)
  {
    printf("Timeout error occurs.\n\r");
    /* Transfer error in transmission process */
    Error_Handler();
  }
  
#endif /* MASTER_BOARD */
  
  /* - Compare the sent and received buffers */
  printf("Compare the sent and received buffers:\n\r");
  if(Buffercmp((uint8_t*)aTxBuffer,(uint8_t*)aRxBuffer,RXBUFFERSIZE))
  {
    /* Processing Error */
    printf("Error\n\r");
    Error_Handler();
  }
  else
  {
    /* Turn LED2 on */
    printf("Ok\n\r");
    BSP_LED_On(BSP_LED2);
  }
  
  /* Infinite loop */
  while (1)
  {
  }
}

/**
* @brief I2Cx Initialization Function
* @param None
* @retval None
*/
static void MX_I2Cx_Init(void)
{
  hi2cx.Instance = I2Cx;
  hi2cx.Init.Timing = 0x10320309;
  hi2cx.Init.OwnAddress1 = 783;
  hi2cx.Init.AddressingMode = I2C_ADDRESSINGMODE_10BIT;
  hi2cx.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2cx.Init.OwnAddress2 = 0;
  hi2cx.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2cx.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2cx.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2cx) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2cx, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2cx, 0) != HAL_OK)
  {
    Error_Handler();
  }
}   

/**
* @brief GPIO Initialization Function
* @param None
* @retval None
*/
static void MX_GPIO_Init(void)
{
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
}

/**
* @brief  Compares two buffers.
* @param  pBuffer1, pBuffer2: buffers to be compared.
* @param  BufferLength: buffer's length
* @retval 0  : pBuffer1 identical to pBuffer2
*         >0 : pBuffer1 differs from pBuffer2
*/
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if ((*pBuffer1) != *pBuffer2)
    {
      return BufferLength;
    }
    pBuffer1++;
    pBuffer2++;
  }
  return 0;
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
  /* Turn LED3 on */
  BSP_LED_On(BSP_LED3);
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
  Error_Handler();
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


