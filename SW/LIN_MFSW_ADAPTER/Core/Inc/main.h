/* USER CODE BEGIN Header */

/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef enum
{
  LIN_RECEIVING_BREAK 									    = 0x01,
  LIN_RECEIVING_SYNC    									  = 0x02,
  LIN_RECEIVING_ID      									  = 0x03,
  LIN_RECEIVING_DATA_FROM_MASTER_UART2      = 0x04,
  LIN_SENDING_DATA_TO_MASTER_UART2  	      = 0x05,
	LIN_RECEIVING_DATA_FROM_SLAVE_UART1				= 0x06,
	LIN_SENDING_DATA_TO_SLAVE_UART1						= 0x07,
	LIN_SENDING_REQUEST_TO_SLAVE_UART1				= 0x08
} LIN_State;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

#define BUTTONS_ID	0x8E
#define STATUS_ID		0x0D
#define DIAG_ID			0x3C
#define DIAG_RS_ID	0x7D
#define TEMP_ID			0xBA

#define BUTTONS_LEN	9
#define STATUS_LEN	5
#define TEMP_LEN		3
#define DIAG_RQ_LEN	9
#define LIN_SYNC_BYTE	0x55

#define TIMEOUT 5
#define HEADER_LEN 3

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern uint8_t LIN_CalcCheckSum(uint8_t *id, uint8_t *data, uint8_t len);
extern uint8_t buttonData[BUTTONS_LEN];
extern uint8_t buttonBuf[BUTTONS_LEN];
extern uint8_t statusData[STATUS_LEN];
extern uint8_t statusBuf[STATUS_LEN];
extern uint8_t tempData[TEMP_LEN];
extern uint8_t tempBuf[TEMP_LEN];
extern uint8_t diagRqBuf[DIAG_RQ_LEN];
extern HAL_StatusTypeDef linSend(UART_HandleTypeDef *huart, uint8_t id, uint8_t data[], uint8_t len);
extern HAL_StatusTypeDef linRead(UART_HandleTypeDef *huart, uint8_t id, uint8_t data[], uint8_t len);
extern HAL_StatusTypeDef linRequest(UART_HandleTypeDef *huart, uint8_t id);
extern void blink(void);

extern IWDG_HandleTypeDef hiwdg;

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Led_Pin GPIO_PIN_13
#define Led_GPIO_Port GPIOC
#define SLP2_Pin GPIO_PIN_4
#define SLP2_GPIO_Port GPIOA
#define SLP1_Pin GPIO_PIN_11
#define SLP1_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
