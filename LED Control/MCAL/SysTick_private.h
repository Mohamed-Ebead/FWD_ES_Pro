#ifndef _SYSTICK_PRIVATE_H
#define _SYSTICK_PRIVATE_H

#include "STD_TYPES.h"



typedef struct {
	uint32_t CTRL;
	uint32_t RELOAD;
	uint32_t CURRENT;
} SysTick_t;



#define SYSTICK  ((SysTick_t*) 0xE000E010)


#endif
