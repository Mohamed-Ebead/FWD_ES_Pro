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

static void (*GPIOF_CallBack) (void);


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







void GPIO_Config_PUR(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t uint8_tPURConfig)
{
switch (Copy_PortID) {
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
			if (uint8_tPURConfig == GPIO_PUR_ENABLED) {
				SET_BIT(GPIOF_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOF_PUR,Copy_PinNum);
			}
			break;
	}
}


void GPIO_SelectInterruptSense(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t uint8_tSense)
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
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOF_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOF_IS,Copy_PinNum);
			}
			break;
	}

}

void GPIO_EnableInterrupt(uint8_t Copy_PortID, uint8_t Copy_PinNum)
{
switch(Copy_PortID) {
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
			SET_BIT(GPIOF_IM,Copy_PinNum);
			break;
	}
}


void GPIO_SelectInterruptEvent(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t uint8_tEvent)
{
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
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOF_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOF_IEV,Copy_PinNum);
			}
			break;
	}
}

void GPIO_InterruptEdges(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t uint8_tBothEdges)
{
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
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOF_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOF_IBE,Copy_PinNum);
			}
			break;
	}
}

void GPIO_ClearInterrupt(uint8_t Copy_PortID, uint8_t Copy_PinNum)
{
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
			SET_BIT(GPIOF_ICR,Copy_PinNum);
			break;
	}
}



uint8_t GPIO_u8GetInterruptStatus(uint8_t Copy_PortID, uint8_t Copy_PinNum)
{
	uint8_t result = 0;
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
			result = GET_BIT(GPIOF_MIS,Copy_PinNum);
			break;
	}
	return result;
}





void GPIO_Unlock(uint8_t Copy_PortID)
{
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
				GPIOF_LOCK = 0x4C4F434B; 
			break;
	}
}

void GPIO_Lock(uint8_t Copy_PortID)
{
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
			GPIOF_LOCK = 0;
			break;
	}
}

void GPIO_Commit(uint8_t Copy_PortID,uint8_t Copy_PinNum)
{
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
			SET_BIT(GPIOF_CR,Copy_PinNum);
			break;
	}
}




void GPIO_SetCallBack(uint8_t Copy_PortID, void (*pFn) (void))
{
	switch(Copy_PortID)
	{
		case GPIO_PORTF:
		GPIOF_CallBack	= pFn;
		break;
	}

}


void GPIOF_Handler()
{
	GPIOF_CallBack();
}

