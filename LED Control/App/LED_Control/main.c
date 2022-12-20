/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
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
#include "BUTTON_interface.h"
#include "NVIC_interface.h""
/* Private macro -------------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/
LED_STATE_t LED_State = LED_OFF ;



int main(void) {


	GPIOF_CLK_EN();

	LED_Init();
	SYSTICK_Init();

	SW1_Init();
	SW2_Init();
	
		/*NVIC configuration*/
	NVIC_SetInterrupt(NVIC_GPIOF);
	
	/*Enable global interrupt*/
	__enable_irq();
	
	while(1) {	
		
	
		if (SYSTICK_TimeElapsedFlag == 1)   // check every second
		{
			SYSTICK_TimeElapsedFlag = 0 ;     // clear flag 
			
			switch (LED_State)
			{
				case LED_ON :
				if ( Seconds_counter % T_ON_Seconds == 0  )  // T ON elapsed 
				{
					Seconds_counter = 0 ; 
					LED_TurnOFF();
					LED_State = LED_OFF ;
				}
				
				break;
				
				case LED_OFF :
					if ( Seconds_counter %  T_OFF_Seconds == 0 ) // T OFF Elapsed 
					{
						Seconds_counter = 0 ;
						LED_TurnON();
						LED_State = LED_ON ;
					}
				break;
			}
		
		}
	
	}
}
