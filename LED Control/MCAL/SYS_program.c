
#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "SYS_private.h"
#include "SYS_interface.h"





void SYSCTRL_GPIO_CLK_EN (uint8_t GPIO_ID)
{
	switch(GPIO_ID)
	{
		case SYSCNTRL_GPIO_PORTA:
			SET_BIT(RCGCGPIO,0);
		break;
		case SYSCNTRL_GPIO_PORTB:
			SET_BIT(RCGCGPIO,1);
		break;
		case SYSCNTRL_GPIO_PORTC:
			SET_BIT(RCGCGPIO,2);
		break;
		case SYSCNTRL_GPIO_PORTD:
			SET_BIT(RCGCGPIO,3);
		break;
		case SYSCNTRL_GPIO_PORTE:
			SET_BIT(RCGCGPIO,4);
		break;
		case SYSCNTRL_GPIO_PORTF:
			SET_BIT(RCGCGPIO,5);
		break;
	}
}



