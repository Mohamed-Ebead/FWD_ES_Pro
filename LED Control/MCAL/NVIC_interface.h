#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H


#include "STD_Types.h"

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  volatile uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;




/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */

#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */




/*Function declarations*/
void NVIC_vidSetInterrupt(uint8_t u8InterruptID);
void NVIC_vidClearInterrupt(uint8_t u8InterruptID);
void NVIC_vidSetPending(uint8_t u8InterruptID);
void NVIC_vidClearPending(uint8_t u8InterruptID);
void NVIC_vidSetPriority(uint8_t u8InterruptID, uint8_t u8InterruptPriority);

/*Interrupt IDs*/
#define NVIC_GPIOA 0
#define NVIC_GPIOB 1
#define NVIC_GPIOC 2
#define NVIC_GPIOD 3
#define NVIC_GPIOE 4
#define NVIC_UART0 5
#define NVIC_UART1 6
#define NVIC_GPIOF 30

#endif