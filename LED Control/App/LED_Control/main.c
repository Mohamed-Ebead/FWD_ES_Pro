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
#include "SYS_interface.h"
#include "BUTTON_interface.h"
#include "NVIC_interface.h""
/* Private macro -------------------------------------------------------------*/



/* Private variables ---------------------------------------------------------*/




int main(void) {


	SYSCTRL_GPIO_CLK_EN(SYSCNTRL_GPIO_PORTF);
	
	uint8_t flag = 0;
	
	LED_Init();
	SYSTICK_Init();

	SW1_Init();
	SW2_Init();
	
		/*NVIC configuration*/
	NVIC_vidSetInterrupt(NVIC_GPIOF);
	
	/*Enable global interrupt*/
	__enable_irq();
	
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
