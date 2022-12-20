/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : NVIC_program.c
  * @brief          : General Purpose Input Output driver
  * @Author         : Mohamed Obaid 
  ******************************************************************************
  */
/* END Header */
#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "NVIC_interface.h"

void NVIC_SetInterrupt(uint8_t uint8_tInterruptID)
{
	if (uint8_tInterruptID < 32)
	{
		NVIC->ISER[0] |= (1<<uint8_tInterruptID);
	}
	else if ((uint8_tInterruptID >= 32) & (uint8_tInterruptID < 63))
	{
		NVIC->ISER[1] |= (1<<(uint8_tInterruptID-32));
	}
}

void NVIC_ClearInterrupt(uint8_t uint8_tInterruptID)
{
	if (uint8_tInterruptID < 32)
	{
		NVIC->ICER[0] |= (1<<uint8_tInterruptID);
	}
	else if ((uint8_tInterruptID >= 32) & (uint8_tInterruptID < 63))
	{
		NVIC->ICER[1] |= (1<<(uint8_tInterruptID-32));
	}
}


void NVIC_SetPending(uint8_t uint8_tInterruptID)
{
if (uint8_tInterruptID < 32)
	{
		NVIC->ISPR[0] |= (1<<uint8_tInterruptID);
	}
	else if ((uint8_tInterruptID >= 32) & (uint8_tInterruptID < 63))
	{
		NVIC->ISPR[1] |= (1<<(uint8_tInterruptID-32));
	}
}

void NVIC_ClearPending(uint8_t uint8_tInterruptID)
{
if (uint8_tInterruptID < 32)
	{
		NVIC->ICPR[0] |= (1<<uint8_tInterruptID);
	}
	else if ((uint8_tInterruptID >= 32) & (uint8_tInterruptID < 63))
	{
		NVIC->ICPR[1] |= (1<<(uint8_tInterruptID-32));
	}
}

void NVIC_SetPriority(uint8_t uint8_tInterruptID, uint8_t uint8_tInterruptPriority)
{
	NVIC->IP[uint8_tInterruptID] = (uint8_tInterruptPriority<<5);
}