#ifndef _SYSTICK_INTERFACE_H
#define _SYSTICK_INTERFACE_H

/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"


#define SYSTICK_EN                  ((uint8_t)0)
#define SYSTICK_NO_INTERRUPT        ((uint8_t)0)
#define SYSTICK_INTERRUPT_ENABLED   ((uint8_t)1)
#define SYSTICK_SYSTEM_CLOCK        ((uint8_t)2)



void SYSTICK_Init(void) ; 
void SYSTICK_DeInit(void) ;

void SYSTICK_INT_EN (void);
void SYSTICK_INT_DIS (void);

void SYSTICK_Reload(uint32_t Copy_Value);
uint32_t SYSTICK_GetCurrentValue(void);
void SYSTICK_Start(void);
void SYSTICK_Stop(void) ;
void SYSTICK_SETCallBack(void (*pfn) (void));




#endif
