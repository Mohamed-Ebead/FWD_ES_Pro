#ifndef _BUTTON_INTERFACE_H
#define _BUTTON_INTERFACE_H

#include "STD_TYPES.h"

typedef struct
{
	uint8_t Copy_PortID;
	uint8_t Copy_PinNum;
}ButtonConfig_t;

typedef enum {
BUTTON_UP, BUTTON_DOWN, BUTTON_PRESSED, BUTTON_RELEASED
}ButtonState_t;
void delay_ms(int milli);
ButtonState_t Button_u8GetButtonDebounced(ButtonConfig_t * buttonConfig,
	ButtonState_t buttonState);


void SW1_Init(void) ; 
void SW2_Init(void) ; 


#endif