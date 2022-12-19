/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : LED_program.c
  * @brief          : LED driver
  * @Author         : Mohamed Obaid 
  ******************************************************************************
  */
/* END Header */

/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "LED_interface.h"



void LED_Init(void)
{
	GPIOF_CLK_EN ();
	GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN2,GPIO_OUTPUT);
	GPIO_SetPinDigitalEnable(GPIO_PORTF,GPIO_PIN2,GPIO_DIG_ENABLE);
}


void LED_TurnON(void)
{
	GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_SET);
}



void LED_TurnOFF(void)
{
	GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_RESET);
}



