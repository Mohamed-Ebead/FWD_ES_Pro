/* BEGIN Header */
/**
  ******************************************************************************
  * @file           : SysTick_program.c
  * @brief          : SysTick Driver
  * @Author         : Mohamed Obaid 
  ******************************************************************************
  */
/* END Header */

/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "BIT_calc.h"
#include "SysTick_private.h"
#include "SysTick_interface.h"


/* ptr to callback fn */
static void (*CallBack) (void);


/**
  * @fn     SYSTICK_CLK_EN
  * @brief  SYSTICK clock Enable Function
  * @retval none
  */
static void SYSTICK_CLK_EN (void)
{
	SET_BIT(SYSTICK->CTRL,SYSTICK_SYSTEM_CLOCK);
}

/**
  * @fn     SYSTICK_INT_EN
  * @brief  SYSTICK Interrupt Enable Function
  * @retval none
  */
void SYSTICK_INT_EN (void)
{
	SET_BIT(SYSTICK->CTRL,SYSTICK_INTERRUPT_ENABLED);
}

/**
  * @fn     SYSTICK_INT_DIS
  * @brief  SYSTICK Interrupt Disable Function
  * @retval none
  */
void SYSTICK_INT_DIS (void)
{
	CLR_BIT(SYSTICK->CTRL,SYSTICK_INTERRUPT_ENABLED);
}

/**
  * @fn     SYSTICK_Init
  * @brief  SYSTICK Initialization Function
  * @retval none
  */
void SYSTICK_Init(void)
{
	SYSTICK_CLK_EN();
	SYSTICK_INT_DIS();
	SYSTICK_Reload(1600000);
	//	SYSTICK_SETCallBack();
	SYSTICK_Start();

}

/**
  * @fn     SYSTICK_DeInit
  * @brief  SYSTICK DeInitialization Function
  * @retval none
  */
void SYSTICK_DeInit(void)
{
	CLR_BIT(SYSTICK->CTRL,SYSTICK_SYSTEM_CLOCK);
}

/**
  * @fn     SYSTICK_Start
  * @brief  SYSTICK Start Trigger Function
  * @retval none
  */
void SYSTICK_Start(void) 
{
	SET_BIT(SYSTICK->CTRL,SYSTICK_EN);
}

/**
  * @fn     SYSTICK_Stop
  * @brief  SYSTICK Stop Function
  * @retval none
  */
void SYSTICK_Stop(void) 
{
	CLR_BIT(SYSTICK->CTRL,SYSTICK_EN);
}


/**
  * @fn     SYSTICK_Reload
  * @brief  SYSTICK Reload Function
  * @retval none
  */
void SYSTICK_Reload(uint32_t Copy_Value) 
	{
	SYSTICK->RELOAD = Copy_Value;
}

/**
  * @fn     SYSTICK_Reload
  * @brief  SYSTICK Reload Function
  * @retval uint32_t Current value
  */
uint32_t SYSTICK_GetCurrentValue(void) 
{
	return SYSTICK->CURRENT;
}


void SYSTICK_SETCallBack(void (*pfn) (void))
{
	CallBack = pfn;
}


void SysTick_Handler(void)
{
	CallBack();
}
