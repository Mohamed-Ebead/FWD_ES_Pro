/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : GPIO_prog.c
  * @brief          : Main program body
  * @Author         : Mohamed Obaid 
  ******************************************************************************
  */
/* END Header */

/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "LED_interface.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"


/* Private macro -------------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/




int main(void) {


	uint8_t flag = 0;
	
	LED_Init();
	SYSTICK_Init();

	
	while(1) {	
		
		
		if(SYSTICK_GetCurrentValue() == 1) 
		{
			if (flag == 1) 
			{
				LED_TurnON();
				flag = 0;
			}
			else 
			{
				LED_TurnOFF();
				flag = 1;
			}
		}
	}
}
