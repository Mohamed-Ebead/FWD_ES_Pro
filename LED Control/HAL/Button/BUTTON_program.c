/*
 Button Debouncing driver based on code from
 https://hackaday.com/2015/12/09/embed-with-elliot-debounce-your-noisy-buttons-part-i/
*/

#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "GPIO_interface.h"
#include "BUTTON_interface.h"
#include "NVIC_interface.h"

void vidProcessButtons(void) ;

typedef enum
{
	USER_IN_IDLE = 0 ,
	USER_IN_T_ON  ,
	USER_IN_T_OFF 
	
}Time_USER_IN_t ;

static Time_USER_IN_t Time_UserSet  = USER_IN_IDLE ;
static uint8_t USER_IN_Seconds = 0 ;

uint8_t T_ON_Seconds = 0 ;
uint8_t T_OFF_Seconds = 0 ;

void SW1_Init(void)
{
	/*Input pins configuration*/
	/*Button connected to F0 resets timer*/
	/*Button connected to F4 turns on count down timer*/
	GPIO_Unlock(GPIO_PORTF);
	GPIO_Commit(GPIO_PORTF,GPIO_PIN0);
	GPIO_Lock(GPIO_PORTF);
	
	
	GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN0,GPIO_INPUT);
	GPIO_SetPinDigitalEnable(GPIO_PORTF,GPIO_PIN2,GPIO_DIG_ENABLE);
	
	
	/*Pull resistance*/
	GPIO_Config_PUR(GPIO_PORTF,GPIO_PIN0,GPIO_PUR_ENABLED);

	/*Event Sense*/
	GPIO_SelectInterruptSense(GPIO_PORTF,GPIO_PIN0,GPIO_SENSE_EDGE);

	/*Both edges*/
	GPIO_InterruptEdges(GPIO_PORTF,GPIO_PIN0,GPIO_INTERRUPT_EVENTCONTROLLED);

	/*Interrupt event*/
	GPIO_SelectInterruptEvent(GPIO_PORTF,GPIO_PIN0,GPIO_EVENT_FALLINGEDGE);

	/*Clear interrupt*/
	GPIO_ClearInterrupt(GPIO_PORTF,GPIO_PIN0);

	/*Enable interrupt*/
	GPIO_EnableInterrupt(GPIO_PORTF,GPIO_PIN0);
	


	GPIO_SetCallBack(GPIO_PORTF,vidProcessButtons);
	

}

void SW2_Init (void)
{
	GPIO_Unlock(GPIO_PORTF);
	GPIO_Commit(GPIO_PORTF,GPIO_PIN4);
	GPIO_Lock(GPIO_PORTF);

	
	
	GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN4,GPIO_INPUT);
	GPIO_SetPinDigitalEnable(GPIO_PORTF,GPIO_PIN2,GPIO_DIG_ENABLE);
	
		/*Pull resistance*/
	GPIO_Config_PUR(GPIO_PORTF,GPIO_PIN4,GPIO_PUR_ENABLED);

	/*Event Sense*/
	GPIO_SelectInterruptSense(GPIO_PORTF,GPIO_PIN4,GPIO_SENSE_EDGE);

	/*Both edges*/
	GPIO_InterruptEdges(GPIO_PORTF,GPIO_PIN4,GPIO_INTERRUPT_EVENTCONTROLLED);

	/*Interrupt event*/
	GPIO_SelectInterruptEvent(GPIO_PORTF,GPIO_PIN4,GPIO_EVENT_FALLINGEDGE);

	/*Clear interrupt*/
	GPIO_ClearInterrupt(GPIO_PORTF,GPIO_PIN4);

	/*Enable interrupt*/
	GPIO_EnableInterrupt(GPIO_PORTF,GPIO_PIN4);
	
	
}


void vidProcessButtons(void)
{
	
	/*Checking the MIS register*/
	if (GPIO_u8GetInterruptStatus(GPIO_PORTF,GPIO_PIN0) == 1)
	{
		GPIO_ClearInterrupt(GPIO_PORTF,GPIO_PIN0);
		USER_IN_Seconds ++ ;
	}
	/*Checking the MIS register*/
	else if (GPIO_u8GetInterruptStatus(GPIO_PORTF,GPIO_PIN4) == 1)
	{
		GPIO_ClearInterrupt(GPIO_PORTF,GPIO_PIN4);
		switch (Time_UserSet)
		{
			case USER_IN_IDLE :
			case USER_IN_T_ON :
				T_ON_Seconds = USER_IN_Seconds ; 
				USER_IN_Seconds = 0 ; 
			  Time_UserSet = USER_IN_T_OFF ;
			break; 
			
			case USER_IN_T_OFF :
			  T_OFF_Seconds = USER_IN_Seconds ; 
		  	USER_IN_Seconds = 0 ; 
		  	Time_UserSet = USER_IN_T_ON ;
			break; 
			
		}
	}

}
