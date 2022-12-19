#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"

/* PORT ID MACRO ----------------------------------------------------------------*/
#define GPIO_PORTA  ((uint8_t)0)
#define GPIO_PORTB  ((uint8_t)1)
#define GPIO_PORTC  ((uint8_t)2)
#define GPIO_PORTD  ((uint8_t)3)
#define GPIO_PORTE  ((uint8_t)4)
#define GPIO_PORTF  ((uint8_t)5)

/* PIN NUMBER MACRO ----------------------------------------------------------------*/
#define GPIO_PIN0   ((uint8_t)0)
#define GPIO_PIN1   ((uint8_t)1)
#define GPIO_PIN2   ((uint8_t)2)
#define GPIO_PIN3   ((uint8_t)3)
#define GPIO_PIN4   ((uint8_t)4)
#define GPIO_PIN5   ((uint8_t)5)
#define GPIO_PIN6   ((uint8_t)6)
#define GPIO_PIN7   ((uint8_t)7)

/* PIN DIRECTION MACRO ----------------------------------------------------------------*/
#define GPIO_INPUT  ((uint8_t)0)
#define GPIO_OUTPUT ((uint8_t)1)

/* PIN OUT STATE MACRO ----------------------------------------------------------------*/
#define GPIO_PIN_RESET ((uint8_t)0)
#define GPIO_PIN_SET   ((uint8_t)1)

/* PIN DIGITAL ENABLE MACRO ----------------------------------------------------------------*/
#define GPIO_DIG_DISABLE ((uint8_t)0)
#define GPIO_DIG_ENABLE  ((uint8_t)1)


/* GPIO APIs ----------------------------------------------------------------*/
void GPIOF_CLK_EN (void) ;
void GPIO_SetPinDigitalEnable(uint8_t Copy_PortID, uint8_t Copy_PinNum, uint8_t Copy_ENorDIS);
void GPIO_SetPinDirection(uint8_t Copy_PortID, uint8_t Copy_PinNum,uint8_t Copy_Direction);
void GPIO_SetPinValue(uint8_t Copy_PortID,uint8_t Copy_PinNum, uint8_t Copy_Value);
uint8_t GPIO_GetPinValue(uint8_t Copy_PortID,uint8_t Copy_PinNum);


#endif
