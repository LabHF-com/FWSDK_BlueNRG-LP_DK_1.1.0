
/******************** (C) COPYRIGHT 2022 STMicroelectronics ********************
* File Name          : SPI_Polling_Master_main.c
* Author             : RF Application Team
* Version            : 1.0.0
* Date               : 04-March-2019
* Description        : Code demonstrating the SPI functionality
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/**
 * @file  SPI_Polling_Master/SPI_Polling_Master_main.c
 * @brief Data buffer transmission/reception between two boards via SPI using Polling mode.
 *

* \section KEIL_project KEIL project
  To use the project with KEIL uVision 5 for ARM, please follow the instructions below:
  -# Open the KEIL uVision 5 for ARM and select Project->Open Project menu. 
  -# Open the KEIL project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\SPI\\SPI_Polling_Master\\MDK-ARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\SPI_Polling_Master.uvprojx</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild all target files. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download to download the related binary image.
  -# Alternatively, open the BlueNRG-LP Flasher utility and download the built binary image.

* \section IAR_project IAR project
  To use the project with IAR Embedded Workbench for ARM, please follow the instructions below:
  -# Open the Embedded Workbench for ARM and select File->Open->Workspace menu. 
  -# Open the IAR project
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\SPI\\SPI_Polling_Master\\EWARM\\{STEVAL-IDB011V1|STEVAL-IDB012V1}\\SPI_Polling_Master.eww</tt>
  -# Select desired configuration to build
  -# Select Project->Rebuild All. This will recompile and link the entire application
  -# To download the binary image, please connect an USB cable in your board (CMSIS-DAP upgrade).
  -# Select Project->Download and Debug to download the related binary image.
  -# Alternatively, open the Flasher utility and download the built binary image.

* \section WISE_project WiSE-Studio project
  To use the project with WiSE-Studio IDE (GCC toolchain), please follow the instructions below:
  -# Open the WiSE-Studio IDE
  -# Select File, Import, Existing Projects into Workspace
     <tt>C:\\Users\\{username}\\ST\\BlueNRG-LP_LPS DK x.x.x\\Projects\\Periph_Examples\\HAL\\SPI\\SPI_Polling_Master\\WiSE-Studio\\{STEVAL-IDB011V1|STEVAL-IDB012V1}</tt> 
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
|     A11    |       Not Used      |      SPI3 MOSI     |
|     A12    |       SPI2 MOSI     |        N.A.        |
|     A13    |       Not Used      |        N.A.        |
|     A14    |       Not Used      |        N.A.        |
|     A15    |       Not Used      |        N.A.        |
|     A4     |       Not Used      |        N.A.        |
|     A5     |       SPI2 SCK      |        N.A.        |
|     A6     |        U5/DL1       |        N.A.        |
|     A7     |       SPI2 MISO     |        N.A.        |
|     A8     |       USART TX      |      SPI3 MISO     |
|     A9     |       USART RX      |      Not Used      |
|     B0     |       Not Used      |      USART RX      |
|     B14    |       Not Used      |      Not Used      |
|     B2     |       Not Used      |      Not Used      |
|     B3     |       Not Used      |      SPI3 SCK      |
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
|  LED name  |                                           STEVAL-IDB010V1                                          |                                           STEVAL-IDB011V1                                          |                                           STEVAL-IDB011V2                                          |                                           STEVAL-IDB012V1                                          |                                           STEVAL-IDB013V1                                          |
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|     DL1    |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |
|     DL2    |  Fast blinking: waiting User push-button (PUSH1) - ON: transmission/reception process is complete  |  Fast blinking: waiting User push-button (PUSH1) - ON: transmission/reception process is complete  |  Fast blinking: waiting User push-button (PUSH1) - ON: transmission/reception process is complete  |  Fast blinking: waiting User push-button (PUSH1) - ON: transmission/reception process is complete  |  Fast blinking: waiting User push-button (PUSH1) - ON: transmission/reception process is complete  |
|     DL3    |                                 ON: error - Blinking: timeout error                                |                                 ON: error - Blinking: timeout error                                |                                 ON: error - Blinking: timeout error                                |                                 ON: error - Blinking: timeout error                                |                                 ON: error - Blinking: timeout error                                |
|     DL4    |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |
|     U5     |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |                                              Not Used                                              |

@endtable


* \section Buttons_description Buttons description
@table
|   BUTTON name  |                    STEVAL-IDB010V1                   |                    STEVAL-IDB011V1                   |                    STEVAL-IDB011V2                   |                    STEVAL-IDB012V1                   |                    STEVAL-IDB013V1                   |
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|      PUSH1     |  Start the communication through IT on master board  |  Start the communication through IT on master board  |  Start the communication through IT on master board  |  Start the communication through IT on master board  |  Start the communication through IT on master board  |
|      PUSH2     |                       Not Used                       |                       Not Used                       |                       Not Used                       |                       Not Used                       |                       Not Used                       |
|      RESET     |                   Reset BlueNRG-LP                   |                   Reset BlueNRG-LP                   |                   Reset BlueNRG-LP                   |                   Reset BlueNRG-LPS                  |                   Reset BlueNRG-LPS                  |

@endtable

* \section Usage Usage

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals, initialize the Flash interface and the systick.

The SPI peripheral configuration is ensured by the HAL_SPI_Init() function.
This later is calling the HAL_SPI_MspInit()function which core is implementing the configuration of the needed SPI resources according to the used hardware (CLOCK, GPIO). 
You may update this function to change SPI configuration.

The SPI communication is then initiated.
The HAL_SPI_TransmitReceive() function allows the reception and the transmission of a predefined data buffer at the same time (Full Duplex Mode).
If the Master board is used, the project SPI_Polling_Master must be used.
If the Slave board is used, the project SPI_Polling_Slave must be used.

For this example the aTxBuffer is predefined and the aRxBuffer size is same as aTxBuffer.

In a first step after the user press the User push-button (PUSH1), SPI Master starts the communication by sending aTxBuffer and receiving aRxBuffer through  HAL_SPI_TransmitReceive(), at the same time SPI Slave transmits aTxBuffer and receives aRxBuffer through HAL_SPI_TransmitReceive(). 
The end of this step is monitored through the HAL_SPI_GetState() function result.
Finally, aRxBuffer and aTxBuffer are compared through Buffercmp() in order to check buffers correctness.  

Timeout is set to 10 seconds which means that if no communication occurs during 10 seconds, a timeout error is generated.

BlueNRG_LP board's LEDs can be used to monitor the transfer status:
 - LED1 toggles quickly on master board waiting User push-button (PUSH1) to be pressed.
 - LED1 turns ON when the transmission process is complete.
 - LED2 turns ON when the reception process is complete.
 - LED3 turns ON when there is an error in transmission/reception process. 
 - LED3 toggles when there is a timeout error in transmission/reception process. 

You need to perform a reset on Slave board, then perform it on Master board to have the correct behavior of this example.

In order to make the program work, you must do the following:
 - Launch serial communication SW on PC
 - Flash the project in the Board
 - Press the RESET button

BlueNRG_LP-EVB Set-up
- Connect Master board SPI CLK pin to Slave Board SPI CLK pin
- Connect Master board SPI MISO pin to Slave Board SPI MISO pin
- Connect Master board SPI MOSI pin to Slave Board SPI MOSI pin
- Connect Master board GND  to Slave Board GND
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
#include "SPI_Polling_Master_main.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint32_t pressCToContinue = 0;
SPI_HandleTypeDef hspiMaster;

#if defined( CONFIG_DATASIZE_16BIT )
/* Buffer used for transmission */
uint16_t aTxBuffer[] = {0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF,0xAAAA,0xFFFF};
uint8_t ubNbDataToTransmit = sizeof(aTxBuffer)/2;
/* Buffer used for reception */
uint16_t aRxBuffer[sizeof(aTxBuffer)/2];

#elif defined( CONFIG_DATASIZE_8BIT ) 

/* Buffer used for transmission */
__attribute((aligned(4))) uint8_t aTxBuffer[] = {0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF};
uint8_t ubNbDataToTransmit = sizeof(aTxBuffer);
/* Buffer used for reception */
__attribute((aligned(4))) uint8_t aRxBuffer[sizeof(aTxBuffer)];

#endif

/* Private function prototypes -----------------------------------------------*/
void Process_InputData(uint8_t* data_buffer, uint16_t Nb_bytes);
static void MX_GPIO_Init(void);
static void MX_SPI_MASTER_Init(void);

static void Timeout_Error_Handler(void);
static uint16_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength);

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
  MX_SPI_MASTER_Init();
  
  /* Configure LEDs */
  BSP_LED_Init(BSP_LED2);
  BSP_LED_Init(BSP_LED3);
 
  printf("Master board\n\r");
  
#if defined( CONFIG_DATASIZE_16BIT ) 
  printf("SPI data width 16 bit\n\r");
#elif defined( CONFIG_DATASIZE_8BIT )
  printf("SPI data width 8 bit\n\r");
#endif 
   
  /* Configure User push-button (PUSH1) button */
  BSP_PB_Init(BSP_PUSH1,BUTTON_MODE_GPIO);

  /* Wait for User push-button (PUSH1) press before starting the Communication */
  printf("Wait for User push-button (PUSH1) press or enter 'c'/'C' character.\n\r");

  while((BSP_PB_GetState(BSP_PUSH1) == GPIO_PIN_RESET) && (pressCToContinue == 0))
  {
    BSP_LED_Toggle(BSP_LED2);
    HAL_Delay(200);
  }
  BSP_LED_Off(BSP_LED2);
  
  /*-1- Start the Full Duplex Communication process */  
  /* While the SPI in TransmitReceive process, user can transmit data through 
  "aTxBuffer" buffer & receive data through "aRxBuffer" */
  /* Timeout is set to 10S */
  
  switch(HAL_SPI_TransmitReceive(&hspiMaster, (uint8_t*)aTxBuffer, (uint8_t *)aRxBuffer, ubNbDataToTransmit, 10000))
  {
  case HAL_OK:
    /* Communication is completed ___________________________________________ */
    /* Compare the sent and received buffers */
    printf("Compare the sent and received buffers:\n\r");
    if (Buffercmp((uint8_t *)aTxBuffer, (uint8_t *)aRxBuffer, sizeof(aTxBuffer)))
    {
      /* Transfer error in transmission process */
      printf("Error\n\r");
      Error_Handler();
    }
    /* Transfer in transmission process is correct */
    printf("Transfer in transmission process is correct.\n\r");
    BSP_LED_On(BSP_LED2);
    /* Transfer in reception process is correct */
    printf("Transfer in reception process is correct.\n\r");
    BSP_LED_On(BSP_LED2);
    printf("** Test successfully. ** \n\r\n\r");
    break;
    
  case HAL_TIMEOUT:
    /* A Timeout Occur ______________________________________________________*/
    /* Call Timeout Handler */
    Timeout_Error_Handler();
    break;
    /* An Error Occur ______________________________________________________ */
  case HAL_ERROR:
    /* Call Timeout Handler */
    Error_Handler();
    break;
    default:
    break;
  }
  
  /* Infinite loop */
  while (1)
  {
  }
}

/**
* @brief SPI_MASTER Initialization Function
* @param None
* @retval None
*/
static void MX_SPI_MASTER_Init(void)
{
  /* SPI_MASTER parameter configuration*/
  hspiMaster.Instance = SPI_MASTER;
  hspiMaster.Init.Mode = SPI_MODE_MASTER;
  hspiMaster.Init.Direction = SPI_DIRECTION_2LINES;
  hspiMaster.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspiMaster.Init.CLKPhase = SPI_PHASE_2EDGE;
#ifdef CONFIG_DATASIZE_16BIT 
  hspiMaster.Init.DataSize = SPI_DATASIZE_16BIT;
#else // CONFIG_DATASIZE_8BIT
  hspiMaster.Init.DataSize = SPI_DATASIZE_8BIT;
#endif 
  hspiMaster.Init.NSS = SPI_NSS_SOFT;
  hspiMaster.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspiMaster.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspiMaster.Init.TIMode = SPI_TIMODE_DISABLE;
  hspiMaster.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspiMaster.Init.CRCPolynomial = 7;
  hspiMaster.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspiMaster.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspiMaster) != HAL_OK)
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

/**
* @brief  This function is executed in case of error occurrence.
* @param  None
* @retval None
*/
static void Timeout_Error_Handler(void)
{
  /* Toggle LED3 on */
  while(1)
  {
    BSP_LED_On(BSP_LED3);
    HAL_Delay(500);
    BSP_LED_Off(BSP_LED3);
    HAL_Delay(500);
  }
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
    if((*pBuffer1) != *pBuffer2)
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
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



