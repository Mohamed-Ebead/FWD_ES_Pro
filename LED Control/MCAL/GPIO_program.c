/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : GPIO_program.c
  * @brief          : General Purpose Input Output driver
  * @Author         : Mohamed Obaid 
  ******************************************************************************
  */
/* END Header */

#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"


/**
  * @fn     GPIOF_CLK_EN
  * @brief  GPIOF Clock Enable Function
  * @retval none
  */
void GPIOF_CLK_EN (void) 
{
	/* the clock to the appropriate GPIO module must be enabled via the RCGCGPIO register */
		RCGCGPIO |= (1U<<5);
}


/**
  * @fn     GPIOF_CLK_EN
  * @brief  GPIO Digital Enable Function
  * @param  Copy_PortID @ PORT ID MACRO
  * @param  Copy_PinNum @ PIN NUMBER MACRO
  * @param  Copy_ENorDIS @ PIN DIGITAL ENABLE MACRO
  * @retval none
  */
void GPIO_SetPinDigitalEnable(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t Copy_ENorDIS)
{
	switch (Copy_PortID) 
	{
		case GPIO_PORTA:
			break; 
		case GPIO_PORTB:
				break; 
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			if (Copy_ENorDIS == GPIO_DIG_ENABLE) {
				SET_BIT(GPIOF_DEN,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOF_DEN,Copy_PinNum);
			}
	}
}

/**
  * @fn     GPIO_SetPinDirection
  * @brief  Set GPIO Pin Direction Function
  * @param  Copy_PortID @ PORT ID MACRO
  * @param  Copy_PinNum @ PIN NUMBER MACRO
  * @param  Copy_Direction @ PIN DIRECTION MACRO
  * @retval none
  */
void GPIO_SetPinDirection(uint8_t Copy_PortID, uint8_t Copy_PinNum,uint8_t Copy_Direction)
{
	switch (Copy_PortID) 
	{
		case GPIO_PORTA:
			break; 
		case GPIO_PORTB:
				break; 
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			if (Copy_Direction == GPIO_OUTPUT) 
			{
				SET_BIT(GPIOF_DIR,Copy_PinNum);
			}
			else 
			{
				CLR_BIT(GPIOF_DIR,Copy_PinNum);
			}
			break;
	}

}

/**
  * @fn     GPIO_SetPinValue
  * @brief  GPIO Set Pin value Function
  * @param  Copy_PortID @ PORT ID MACRO
  * @param  Copy_PinNum @ PIN NUMBER MACRO
  * @param  Copy_Value @ PIN OUT STATE MACRO
  * @retval none
  */
void GPIO_SetPinValue(uint8_t Copy_PortID,uint8_t Copy_PinNum, uint8_t Copy_Value)
{
	switch (Copy_PortID) 
	{
		case GPIO_PORTA:
			break; 
		case GPIO_PORTB:
				break; 
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			if (Copy_Value == GPIO_PIN_SET) 
			{
				SET_BIT(GPIOF_DATA,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOF_DATA,Copy_PinNum);
			}
	}
}


/**
  * @fn     GPIO_GetPinValue
  * @brief  GPIO Get Pin value Function
  * @param  Copy_PortID @ PORT ID MACRO
  * @param  Copy_PinNum @ PIN NUMBER MACRO
  * @retval uint8_t 0 or 1 
  */
uint8_t GPIO_GetPinValue(uint8_t Copy_PortID,uint8_t Copy_PinNum)
{
	uint8_t Pin_State  = GPIO_PIN_RESET ; 
	switch(Copy_PortID)
	{
		case GPIO_PORTA:
			break; 
		case GPIO_PORTB:
				break; 
		case GPIO_PORTC:
			break;
		case GPIO_PORTD:
			break;
		case GPIO_PORTE:
			break;
		case GPIO_PORTF:
			Pin_State =  GET_BIT(GPIOF_DATA,Copy_PinNum);
			break;
	}
	
	return Pin_State ;
}



