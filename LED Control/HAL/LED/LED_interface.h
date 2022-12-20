#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

typedef enum {

	LED_IDLE = 0 ,
	LED_ON,
	LED_OFF
	
}LED_STATE_t ;



void LED_Init(void);
void LED_TurnON(void);
void LED_TurnOFF(void);

#endif 

