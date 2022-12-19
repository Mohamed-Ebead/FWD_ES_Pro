#include "BIT_calc.h"
#include "STD_TYPES.h"
#include "NVIC_interface.h"
//#include "TM4C123.h"                    // Device header

void NVIC_vidSetInterrupt(uint8_t uint8_tInterruptID)
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

void NVIC_vidClearInterrupt(uint8_t uint8_tInterruptID)
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


void NVIC_vidSetPending(uint8_t uint8_tInterruptID)
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

void NVIC_vidClearPending(uint8_t uint8_tInterruptID)
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

void NVIC_vidSetPriority(uint8_t uint8_tInterruptID, uint8_t uint8_tInterruptPriority)
{
	NVIC->IP[uint8_tInterruptID] = (uint8_tInterruptPriority<<5);
}