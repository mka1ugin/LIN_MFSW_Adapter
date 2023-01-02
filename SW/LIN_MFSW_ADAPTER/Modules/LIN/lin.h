/**
  ******************************************************************************
  * @file           : lin.h
  * @brief          : LIN driver interface
  * @author         : MicroTechnics (microtechnics.ru)
  ******************************************************************************
  */

#ifndef LIN_H
#define LIN_H



/* Includes ------------------------------------------------------------------*/

#include "stm32f1xx_hal.h"



/* Declarations and definitions ----------------------------------------------*/

#define LIN_TIMER_PERIOD_US                                             25

#define LIN_BREAK_SIZE_BITS                                             13
#define LIN_BREAK_DEVIATION_PERCENT                                     10

#define LIN_SYNC_BYTE                                                   0x55

#define LIN_RX_TIMEOUT_US                                               100000

typedef enum
{
  LIN_IDLE,
  LIN_RECEIVING_BREAK,
  LIN_RECEIVING_SYNC,
  LIN_RECEIVING_ID,
  LIN_RECEIVING_DATA,
  LIN_RECEIVING_CHECKSUM,
  LIN_SENDING_BREAK,
  LIN_SENDING_SYNC,
  LIN_SENDING_ID,
  LIN_SENDING_DATA,
  LIN_SENDING_CHECKSUM,
} LIN_State;

typedef enum
{
  LIN_MASTER,
  LIN_SLAVE,
} LIN_Mode;

typedef enum {
    LIN_OK,
    LIN_BUSY,
    LIN_NOT_INIT,
} LIN_Error;



/* Functions -----------------------------------------------------------------*/

extern void LIN_Init(UART_HandleTypeDef *uHandle, TIM_HandleTypeDef *tHandle, LIN_Mode mode,
                     GPIO_TypeDef *rPort, uint32_t rPin, GPIO_TypeDef *tPort, uint32_t tPin);
extern LIN_Error LIN_Transmit(uint32_t id, uint8_t *ptr, uint8_t len);
extern LIN_Error LIN_Receive(uint32_t id, uint8_t *ptr, uint8_t len);
extern uint8_t LIN_GetDataLength(uint8_t id);
extern uint8_t LIN_CalcCheckSum(uint8_t *data, uint8_t len);
extern void LIN_Reset();
extern LIN_State LIN_GetState();



#endif // #ifndef LIN_H
