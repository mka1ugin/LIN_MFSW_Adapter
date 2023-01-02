#include "buttons.h"

enum Buttons linkButton(enum Buttons mqbButton)
{
	switch (mqbButton) {
		case MQB_NEXT_WINDOW: 	return PQ_NEXT_WINDOW;
		case MQB_PREV_WINDOW: 	return PQ_PREV_WINDOW;
		case MQB_MENU_UP: 			return PQ_MENU_UP;
		case MQB_MENU_DOWN: 		return PQ_MENU_DOWN;
		case MQB_RIGHT_WHEEL: 	return PQ_OK;
		case MQB_VOLUME_UP: 		return PQ_VOLUME_UP;
		case MQB_VOLUME_DOWN: 	return PQ_VOLUME_DOWN;
		case MQB_LEFT_WHEEL: 		return PQ_PHONE;
		case MQB_NEXT_TRACK: 		return PQ_NEXT_TRACK;
		case MQB_PREV_TRACK: 		return PQ_PREV_TRACK;
		case MQB_VOICE_CONTROL: return PQ_VOICE_CONTROL;
		
		case MQB_ASSIST_BUTTON: return MQB_ASSIST_BUTTON;
		case MQB_STEERING_HEAT: return MQB_STEERING_HEAT;
		case MQB_CRUISE_SET: 		return MQB_CRUISE_SET;
		
		default: return NONE;
	}
}

enum Buttons decodeMQBButton(uint8_t buttonId, uint8_t pressureType) {
	switch(buttonId) {
		case 0x02: return MQB_NEXT_WINDOW;
		case 0x03: return MQB_PREV_WINDOW;
		case 0x06: if (pressureType >= 0x01 && pressureType <= 0x03) { return MQB_MENU_UP; } else if (pressureType <= 0x0F && pressureType >= 0x0D) { return MQB_MENU_DOWN; }
		case 0x07: return MQB_RIGHT_WHEEL;
		case 0x0C: return MQB_ASSIST_BUTTON;
		case 0x12: if (pressureType >= 0x01 && pressureType <= 0x03) { return MQB_VOLUME_UP; } else if (pressureType <= 0x0F && pressureType >= 0x0D) { return MQB_VOLUME_DOWN; }
		case 0x13: return MQB_LEFT_WHEEL;
		case 0x15: return MQB_NEXT_TRACK;
		case 0x16: return MQB_PREV_TRACK;
		case 0x19: return MQB_VOICE_CONTROL;
		case 0x25: return MQB_STEERING_HEAT;
		case 0x74: return MQB_CRUISE_SET;
		default: return NONE;
	}
}

enum Buttons decodePQButton(uint8_t buttonId) {
	switch (buttonId) {
		case 0x02: return PQ_NEXT_TRACK;			//2
		case 0x03: return PQ_PREV_TRACK;			//3
		case 0x06: return PQ_VOLUME_UP;			//6
		case 0x07: return PQ_VOLUME_DOWN;		//7
		case 0x09: return PQ_PREV_WINDOW;		//9
		case 0x0A: return PQ_NEXT_WINDOW;		//10
		case 0x1A: return PQ_PHONE;					//26
		case 0x22: return PQ_MENU_UP;				//34
		case 0x23: return PQ_MENU_DOWN;			//35
		case 0x28: return PQ_OK;							//40
		case 0x29: return PQ_BACK;						//41
		case 0x2B: return PQ_VOICE_CONTROL;	//42
		default: return NONE;
	}
}

uint8_t getPQButtonCode(enum Buttons button)
{
	switch (button) {
		case PQ_NEXT_TRACK:			return 2;
		case PQ_PREV_TRACK: 		return 3;
		case PQ_VOLUME_UP: 			return 6;
		case PQ_VOLUME_DOWN: 		return 7;
		case PQ_PREV_WINDOW: 		return 9;
		case PQ_NEXT_WINDOW: 		return 10;
		case PQ_PHONE: 					return 26;
		case PQ_MENU_UP: 				return 34;
		case PQ_MENU_DOWN: 			return 35;
		case PQ_OK: 						return 40;
		case PQ_BACK: 					return 41;
		case PQ_VOICE_CONTROL: 	return 42;
		
		case MQB_ASSIST_BUTTON: return 0x0C;
		case MQB_STEERING_HEAT: return 0x25;
		case MQB_CRUISE_SET: 		return 0x74;
		
		default: 								return 0;
	}
}

void mqbToPq(uint8_t* input, uint8_t* output) {
	
	output[0] = input[0] & 0b00001111 + 0x80;	
	output[1] = getPQButtonCode(linkButton(decodeMQBButton(input[1], input[3])));	
	output[2] = 0x00;
	output[3] = 0x00;
	output[4] = 0x60;
	output[5] = 0x00;
	output[6] = 0x00;
	output[7] = 0x00;
	
	uint8_t id = 0x8E;
	output[8] = LIN_CalcCheckSum(&id, output, 8);
}
	