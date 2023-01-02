#include "identification.h"

uint8_t diagString = 0xFF;
int8_t repeats = -1;

uint8_t responce[9];

uint8_t diagStrings[131] = {
														0x0A, 0x10, 0x0E, 0x62, 0x06, 0x5E, 0x62, 0x79, 0x35,
														0x0A, 0x21, 0x4D, 0x4B, 0x61, 0x6C, 0x75, 0x67, 0x91,
														0x0A, 0x22, 0x69, 0x6E, 0x20, 0xFF, 0xFF, 0xFF, 0xDB,
														0x0A, 0x06, 0x62, 0x06, 0xEE, 0x48, 0x30, 0x31, 0xEE,
														0x0A, 0x10, 0x07, 0x62, 0x06, 0x8E, 0x30, 0x30, 0x87,
														0x0A, 0x21, 0x30, 0x31, 0xFF, 0xFF, 0xFF, 0xFF, 0x73,
														0x0A, 0x06, 0x62, 0x06, 0x2E, 0x77, 0x77, 0x77, 0xF2,
														0x0A, 0x10, 0x10, 0x62, 0x07, 0x20, 0x4C, 0x49, 0xB6,
														0x0A, 0x21, 0x4E, 0x20, 0x41, 0x44, 0x41, 0x50, 0x4F,
														0x0A, 0x22, 0x50, 0x54, 0x45, 0x52, 0x20, 0xFF, 0x77,
														0x0A, 0x10, 0x17, 0x62, 0x07, 0x1E, 0x30, 0x30,	0xE6,
														0x0A, 0x21, 0x38, 0x37, 0x38, 0x32, 0x38, 0x20,	0xA2,
														0x0A, 0x22, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,	0x13,
														0x0A, 0x23, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x12
													};

uint8_t requestStrings[56] = {
														0x0A, 0x03, 0x22, 0x06, 0x5E, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x06, 0xBE, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x06, 0x8E, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x06, 0x2E, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x07, 0x4E, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x07, 0xBE, 0xFF, 0xFF, 0xFF,
														0x0A, 0x03, 0x22, 0x07, 0x1E, 0xFF, 0xFF, 0xFF,
														};				

void loadDiagRequest(uint8_t request[])
{
	switch (request[4]) {
		case 0x5E: diagString = 0; repeats = 2; break;
		case 0xBE: diagString = 0; repeats = 2; break;
		case 0xEE: diagString = 3; repeats = 1; break;
		case 0x8E: diagString = 4; repeats = 0; break;
		case 0x2E: diagString = 6; repeats = 0; break;
		case 0x4E: diagString = 7; repeats = 2; break;
		case 0x1E: diagString = 10; repeats = 3; break;
		
		default:	 diagString = 0xFF; repeats = -1;
	}
}

extern void getDiagResponce(void)
{
	for(int i = 0; i < 9; i++)
	{
		responce[i] = diagStrings[i + diagString * 9];
	}
	if (repeats >= 0)
	{
		diagString++;
		repeats--;
	} 
	else
	{
		diagString = 0xFF;
		repeats = -1;
	}
}