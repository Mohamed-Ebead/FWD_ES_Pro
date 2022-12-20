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
		if (Copy_ENorDIS == GPIO_DIG_ENABLE) {
				SET_BIT(GPIOA_DEN,Copy_PinNum);	
			}
			else {
				CLR_BIT(GPIOA_DEN,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (Copy_ENorDIS == GPIO_DIG_ENABLE) {
				SET_BIT(GPIOB_DEN,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOB_DEN,Copy_PinNum);	
			}
			break;
		case GPIO_PORTC:
			if (Copy_ENorDIS == GPIO_DIG_ENABLE) {
				SET_BIT(GPIOC_DEN,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOC_DEN,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (Copy_ENorDIS == GPIO_DIG_ENABLE) {
				SET_BIT(GPIOD_DEN,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOD_DEN,Copy_PinNum);
			}
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
			if (Copy_Direction == GPIO_OUTPUT) {
				SET_BIT(GPIOA_DIR,Copy_PinNum);	
			}
			else {
				CLR_BIT(GPIOA_DIR,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (Copy_Direction == GPIO_OUTPUT) {
				SET_BIT(GPIOB_DIR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOB_DIR,Copy_PinNum);	
			}
			break;
		case GPIO_PORTC:
			if (Copy_Direction == GPIO_OUTPUT) {
				SET_BIT(GPIOC_DIR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOC_DIR,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (Copy_Direction == GPIO_OUTPUT) {
				SET_BIT(GPIOD_DIR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOD_DIR,Copy_PinNum);
			}
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
			if (Copy_Value == GPIO_PIN_SET) {
				SET_BIT(GPIOA_DATA,Copy_PinNum);	
			}
			else {
				CLR_BIT(GPIOA_DATA,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (Copy_Value == GPIO_PIN_SET) {
				SET_BIT(GPIOB_DATA,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOB_DATA,Copy_PinNum);	
			}
			break;
		case GPIO_PORTC:
			if (Copy_Value == GPIO_PIN_SET) {
				SET_BIT(GPIOC_DATA,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOC_DATA,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (Copy_Value == GPIO_PIN_SET) {
				SET_BIT(GPIOD_DATA,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOD_DATA,Copy_PinNum);
			}
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
			Pin_State =  GET_BIT(GPIOA_DATA,Copy_PinNum);

			break; 
		case GPIO_PORTB:
				Pin_State =  GET_BIT(GPIOB_DATA,Copy_PinNum);

				break; 
		case GPIO_PORTC:
			Pin_State =  GET_BIT(GPIOC_DATA,Copy_PinNum);

			break;
		case GPIO_PORTD:
			Pin_State =  GET_BIT(GPIOD_DATA,Copy_PinNum);

			break;
		case GPIO_PORTE:
			Pin_State =  GET_BIT(GPIOE_DATA,Copy_PinNum);

			break;
		case GPIO_PORTF:
			Pin_State =  GET_BIT(GPIOF_DATA,Copy_PinNum);
			break;
	}
	
	return Pin_State ;
}







void GPIO_Config_PUR(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t PURConfig)
{
switch (Copy_PortID) {
		case GPIO_PORTA:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOA_PUR,Copy_PinNum);	
			}
			else {
				CLR_BIT(GPIOA_PUR,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOB_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOB_PUR,Copy_PinNum);	
			}
			break;
		case GPIO_PORTC:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOC_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOC_PUR,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOD_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOD_PUR,Copy_PinNum);
			}
			break;
			case GPIO_PORTE:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOE_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOE_PUR,Copy_PinNum);
			}
			break;
		case GPIO_PORTF:
			if (PURConfig == GPIO_PUR_EN) {
				SET_BIT(GPIOF_PUR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOF_PUR,Copy_PinNum);
			}
			break;
	}
}


void GPIO_ConfigurePullDown(uint8_t uint8_tPort, uint8_t Copy_PinNum, uint8_t PURConfig)
{
switch (uint8_tPort) {
		case GPIO_PORTA:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOA_PDR,Copy_PinNum);	
			}
			else {
				CLR_BIT(GPIOA_PDR,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOB_PDR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOB_PDR,Copy_PinNum);	
			}
			break;
		case GPIO_PORTC:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOC_PDR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOC_PDR,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOD_PDR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOD_PDR,Copy_PinNum);
			}
			break;
			case GPIO_PORTE:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOE_PDR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOE_PDR,Copy_PinNum);
			}
			break;
		case GPIO_PORTF:
			if (PURConfig == GPIO_PDR_EN) {
				SET_BIT(GPIOF_PDR,Copy_PinNum);
			}
			else {
				CLR_BIT(GPIOF_PDR,Copy_PinNum);
			}
			break;
	}
}

void GPIO_SelectInterruptSense(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t uint8_tSense)
{
	switch (Copy_PortID)
	{
case GPIO_PORTA:
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOA_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOA_IS,Copy_PinNum);
			}
			break;
			case GPIO_PORTB:
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOB_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOB_IS,Copy_PinNum);
			}
			break;
		case GPIO_PORTC:
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOC_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOC_IS,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOD_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOD_IS,Copy_PinNum);
			}
			break;
		case GPIO_PORTE:
			if (uint8_tSense == GPIO_SENSE_EDGE)
			{
				CLR_BIT(GPIOE_IS,Copy_PinNum);
			}
			else
			{
				SET_BIT(GPIOE_IS,Copy_PinNum);
			}
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
			SET_BIT(GPIOA_IM,Copy_PinNum);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_IM,Copy_PinNum);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_IM,Copy_PinNum);
			break;
		case GPIO_PORTD:
			SET_BIT(GPIOD_IM,Copy_PinNum);
			break;
		case GPIO_PORTE:
			SET_BIT(GPIOE_IM,Copy_PinNum);
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
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOA_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOA_IEV,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOB_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOB_IEV,Copy_PinNum);
			}
			break;
		case GPIO_PORTC:
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOC_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOC_IEV,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOD_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOD_IEV,Copy_PinNum);
			}
			break;
		case GPIO_PORTE:
			if (uint8_tEvent == GPIO_HL_RE)
			{
				SET_BIT(GPIOE_IEV,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOE_IEV,Copy_PinNum);
			}
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
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOA_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOA_IBE,Copy_PinNum);
			}
			break;
		case GPIO_PORTB:
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOB_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOB_IBE,Copy_PinNum);
			}
			break;
		case GPIO_PORTC:
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOC_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOC_IBE,Copy_PinNum);
			}
			break;
		case GPIO_PORTD:
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOD_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOD_IBE,Copy_PinNum);
			}
			break;
		case GPIO_PORTE:
			if (uint8_tBothEdges == GPIO_INTERRUPT_BOTHEDGES)
			{
				SET_BIT(GPIOE_IBE,Copy_PinNum);
			}
			else
			{
				CLR_BIT(GPIOE_IBE,Copy_PinNum);
			}
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
			SET_BIT(GPIOA_ICR,Copy_PinNum);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_ICR,Copy_PinNum);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_ICR,Copy_PinNum);
			break;
		case GPIO_PORTD:
			SET_BIT(GPIOD_ICR,Copy_PinNum);
			break;
		case GPIO_PORTE:
			SET_BIT(GPIOE_ICR,Copy_PinNum);
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
			result = GET_BIT(GPIOA_MIS,Copy_PinNum);

			break;
		case GPIO_PORTB:
			result = GET_BIT(GPIOB_MIS,Copy_PinNum);

		break;
		case GPIO_PORTC:
			result = GET_BIT(GPIOC_MIS,Copy_PinNum);

			break;
		case GPIO_PORTD:
			result = GET_BIT(GPIOD_MIS,Copy_PinNum);

			break;
		case GPIO_PORTE:
			result = GET_BIT(GPIOE_MIS,Copy_PinNum);

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
				GPIOA_LOCK = 0x4C4F434B;
			break;
		case GPIO_PORTB:
				GPIOB_LOCK = 0x4C4F434B;
			break;
		case GPIO_PORTC:
				GPIOC_LOCK = 0x4C4F434B;
			break;
		case GPIO_PORTD:
				GPIOD_LOCK = 0x4C4F434B;
			break;
		case GPIO_PORTE:
				GPIOE_LOCK = 0x4C4F434B;
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
			GPIOA_LOCK = 0;
			break;
		case GPIO_PORTB:
			GPIOB_LOCK = 0;
			break;
		case GPIO_PORTC:
			GPIOC_LOCK = 0;
			break;
		case GPIO_PORTD:
			GPIOD_LOCK = 0;
			break;
		case GPIO_PORTE:
			GPIOE_LOCK = 0;
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
			SET_BIT(GPIOA_CR,Copy_PinNum);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_CR,Copy_PinNum);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_CR,Copy_PinNum);
			break;
		case GPIO_PORTD:
			SET_BIT(GPIOD_CR,Copy_PinNum);
			break;
		case GPIO_PORTE:
			SET_BIT(GPIOE_CR,Copy_PinNum);
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

