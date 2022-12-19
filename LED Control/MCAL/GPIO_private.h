#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

//GPIOF Registers (GPIOF is chosen for simulation btn and LEDs)

//TODO Add the remaining GPIOs

/* GPIOF port Registers */
#define GPIOF_DATA (*((volatile uint32_t*)0x400253FC))
#define GPIOF_DIR (*((volatile uint32_t*)0x40025400))
#define GPIOF_IS (*((volatile uint32_t*)0x40025404))
#define GPIOF_IBE (*((volatile uint32_t*)0x40025408))
#define GPIOF_IEV (*((volatile uint32_t*)0x4002540C))
#define GPIOF_IM (*((volatile uint32_t*)0x40025410))
#define GPIOF_RIS (*((volatile uint32_t*)0x40025414))
#define GPIOF_MIS (*((volatile uint32_t*)0x40025418))
#define GPIOF_ICR (*((volatile uint32_t*)0x4002541C))
#define GPIOF_AFSEL (*((volatile uint32_t*)0x40025420))
#define GPIOF_DR2R (*((volatile uint32_t*)0x40025500))
#define GPIOF_DR4R (*((volatile uint32_t*)0x40025504))
#define GPIOF_DR8R (*((volatile uint32_t*)0x40025508))
#define GPIOF_ODR (*((volatile uint32_t*)0x4002550C))
#define GPIOF_PUR (*((volatile uint32_t*)0x40025510))
#define GPIOF_PDR (*((volatile uint32_t*)0x40025514))
#define GPIOF_SLR (*((volatile uint32_t*)0x40025518))
#define GPIOF_DEN (*((volatile uint32_t*)0x4002551C))
#define GPIOF_LOCK (*((volatile uint32_t*)0x40025420))
#define GPIOF_CR (*((volatile uint32_t*)0x40025524))
#define GPIOF_AMSEL (*((volatile uint32_t*)0x40025528))
#define GPIOF_PCTL (*((volatile uint32_t*)0x4002552C))
#define GPIOF_ADCCTL (*((volatile uint32_t*)0x4002530))
#define GPIOF_DMACTL (*((volatile uint32_t*)0x40025534))
#define GPIOF_PeriphID4 (*((volatile uint32_t*)0x40025FD0))
#define GPIOF_PeriphID5 (*((volatile uint32_t*)0x40025FD4))
#define GPIOF_PeriphID6 (*((volatile uint32_t*)0x40025FD8))
#define GPIOF_PeriphID7 (*((volatile uint32_t*)0x40025FDC))
#define GPIOF_PeriphID0 (*((volatile uint32_t*)0x40025FE0))
#define GPIOF_PeriphID1 (*((volatile uint32_t*)0x40025FE4))
#define GPIOF_PeriphID2 (*((volatile uint32_t*)0x40025FE8))
#define GPIOF_PeriphID3 (*((volatile uint32_t*)0x40025FEC))
#define GPIOF_CellID0 (*((volatile uint32_t*)0x40025FF0))
#define GPIOF_CellID1 (*((volatile uint32_t*)0x40025FF4))
#define GPIOF_CellID2 (*((volatile uint32_t*)0x40025FF8))
#define GPIOF_CellID3 (*((volatile uint32_t*)0x40025FFC))


/* RCGCGPIO Clock Enable Register */
#define RCGCGPIO  (*((uint32_t *) 0x400FE608))
	

#endif
