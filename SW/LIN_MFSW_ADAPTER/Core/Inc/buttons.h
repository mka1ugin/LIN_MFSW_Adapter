#include "main.h"

enum Buttons {
		NONE,
		PQ_VOICE_CONTROL,
		PQ_PREV_TRACK,
		PQ_NEXT_TRACK,
		PQ_VOLUME_UP,
		PQ_VOLUME_DOWN,
		PQ_PHONE,
		PQ_PREV_WINDOW,
		PQ_NEXT_WINDOW,
		PQ_MENU_UP,
		PQ_MENU_DOWN,
		PQ_OK,
		PQ_BACK,
		MQB_VOICE_CONTROL,
		MQB_STEERING_HEAT,
		MQB_PREV_TRACK,
		MQB_NEXT_TRACK,
		MQB_VOLUME_UP,
		MQB_VOLUME_DOWN,
		MQB_LEFT_WHEEL,
		MQB_ASSIST_BUTTON,
		MQB_CRUISE_SET,
		MQB_PREV_WINDOW,
		MQB_NEXT_WINDOW,
		MQB_MENU_UP,
		MQB_MENU_DOWN,
		MQB_RIGHT_WHEEL
};

enum Buttons linkButton(enum Buttons);
enum Buttons decodePQButton(uint8_t);
enum Buttons decodeMQBButton(uint8_t, uint8_t);
uint8_t getPQButtonCode(enum Buttons);
void mqbToPq(uint8_t* input, uint8_t* output);