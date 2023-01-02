#include "main.h"

#define LIN_REQUEST_ID	0x3C
#define LIN_RESPONCE_ID	0x3D

extern uint8_t diagString;

extern uint8_t responce[9];

extern uint8_t diagStrings[131];

extern uint8_t requestStrings[56];

extern void loadDiagRequest(uint8_t request[]);
extern void getDiagResponce(void);