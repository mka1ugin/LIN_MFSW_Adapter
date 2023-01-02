/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "main.h"
#include "buttons.h"
#include "string.h"
#include "identification.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

uint8_t rxByte = 0;
uint8_t diagStr = 0;

uint8_t misc = 0;

uint32_t linSlaveRxCnt = 0;
uint32_t linSlaveTxCnt = 0;

uint32_t txBytes = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */

extern LIN_State slaveState;
HAL_StatusTypeDef slaveWrite = HAL_OK;
HAL_StatusTypeDef slaveRead = HAL_OK;

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
	uint32_t isrflags = huart1.Instance->SR;
    
    if ((isrflags & USART_SR_LBD) != RESET)
    {
      CLEAR_BIT(huart1.Instance->SR, USART_SR_LBD);
    }
		else if ((isrflags & USART_SR_RXNE) != RESET)
		{
			uint16_t temp = huart1.Instance->DR;
			CLEAR_BIT(huart1.Instance->SR, USART_SR_RXNE);
		}
  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
  if (slaveState == LIN_RECEIVING_BREAK)
  {
    uint32_t isrflags = huart2.Instance->SR;
    
    if ((isrflags & USART_SR_LBD) != RESET)
    {
      CLEAR_BIT(huart2.Instance->SR, USART_SR_LBD);
      uint16_t temp = huart2.Instance->DR;
      slaveState = LIN_RECEIVING_SYNC;
      HAL_UART_Receive_IT(&huart2, &rxByte, 1);
    }
  }
}
  /* USER CODE END USART2_IRQn 1 */

/* USER CODE BEGIN 1 */

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    blink();
		switch(slaveState)
    { 

			case LIN_SENDING_DATA_TO_MASTER_UART2:
					slaveState = LIN_RECEIVING_BREAK;
					HAL_IWDG_Refresh(&hiwdg);	
					break;
				
			case LIN_SENDING_DATA_TO_SLAVE_UART1:
				if (rxByte == STATUS_ID)
				{
					memcpy(statusData, statusBuf, STATUS_LEN);
				}
				slaveState = LIN_RECEIVING_BREAK;
				HAL_IWDG_Refresh(&hiwdg);	
        break;
				
			case LIN_SENDING_REQUEST_TO_SLAVE_UART1:
				if (rxByte == BUTTONS_ID)
				{
					slaveState = LIN_RECEIVING_DATA_FROM_SLAVE_UART1;
					HAL_UART_Receive_IT(&huart1, buttonBuf, BUTTONS_LEN);
					break;
				}
				
				if (rxByte == TEMP_ID)
				{
					slaveState = LIN_RECEIVING_DATA_FROM_SLAVE_UART1;
					HAL_UART_Receive_IT(&huart1, tempBuf, TEMP_LEN);
					break;
				}
				
				break;
        
      default:
        break;
    }
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		blink();
		uint8_t linSync = LIN_SYNC_BYTE;

    switch(slaveState)
    {
      case LIN_RECEIVING_SYNC:
        if (rxByte == LIN_SYNC_BYTE)
        {
          slaveState = LIN_RECEIVING_ID;
          HAL_UART_Receive_IT(&huart2, &rxByte, 1);
        }
        else
        {
          slaveState = LIN_RECEIVING_BREAK;
					HAL_IWDG_Refresh(&hiwdg);
        }
        break;
          
      case LIN_RECEIVING_ID:
				if (rxByte == STATUS_ID)
				{
					slaveState = LIN_RECEIVING_DATA_FROM_MASTER_UART2;
					HAL_UART_Receive_IT(&huart2, statusBuf, STATUS_LEN);
					slaveState = LIN_SENDING_DATA_TO_SLAVE_UART1;
					linSend(&huart1, STATUS_ID, statusData, STATUS_LEN);
				}
				else if (rxByte == BUTTONS_ID)
				{
					slaveState = LIN_SENDING_DATA_TO_MASTER_UART2;
					HAL_UART_Transmit_IT(&huart2, buttonData, BUTTONS_LEN);
					slaveState = LIN_SENDING_REQUEST_TO_SLAVE_UART1;
					linRequest(&huart1, BUTTONS_ID);
				}
				else if (rxByte == DIAG_RS_ID)
				{
					if (diagString == 0xFF)
					{
						slaveState = LIN_SENDING_DATA_TO_SLAVE_UART1;
						linRequest(&huart1, DIAG_RS_ID);
					}
					else
					{
						slaveState = LIN_SENDING_DATA_TO_MASTER_UART2;
						getDiagResponce();
						HAL_UART_Transmit_IT(&huart2, responce, DIAG_RQ_LEN);
					}					
				}
				else if (rxByte == DIAG_ID)
				{
					slaveState = LIN_RECEIVING_DATA_FROM_MASTER_UART2;
					HAL_UART_Receive_IT(&huart2, diagRqBuf, DIAG_RQ_LEN);					
				}
				else if (rxByte == TEMP_ID)
				{
					slaveState = LIN_SENDING_DATA_TO_MASTER_UART2;
					HAL_UART_Transmit_IT(&huart2, tempData, TEMP_LEN + 1);
					slaveState = LIN_SENDING_REQUEST_TO_SLAVE_UART1;
					linRequest(&huart1, TEMP_ID);
				}
				else
				{
					slaveState = LIN_RECEIVING_BREAK;
					HAL_IWDG_Refresh(&hiwdg);
				}
				break;
								
      case LIN_RECEIVING_DATA_FROM_MASTER_UART2:
        if (rxByte == STATUS_ID)
				{
          slaveState = LIN_SENDING_DATA_TO_SLAVE_UART1;
					linSend(&huart1, STATUS_ID, statusData, STATUS_LEN);
				}
				if (rxByte == DIAG_ID)
				{
					loadDiagRequest(diagRqBuf);
					slaveState = LIN_RECEIVING_BREAK;
					HAL_IWDG_Refresh(&hiwdg);
				}
				break;
				
			case LIN_RECEIVING_DATA_FROM_SLAVE_UART1:
				if (rxByte == BUTTONS_ID)
				{
					memcpy(buttonData, buttonBuf, BUTTONS_LEN);
					mqbToPq(buttonBuf, buttonData);
				}
				if (rxByte == BUTTONS_ID)
				{
					memcpy(tempData, tempBuf, 3);
				}
				slaveState = LIN_RECEIVING_BREAK;
				HAL_IWDG_Refresh(&hiwdg);				
				break;
      
			default:
        break;
    }
 }

/* USER CODE END 1 */
