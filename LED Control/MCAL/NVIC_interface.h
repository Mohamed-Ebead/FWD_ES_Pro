#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H


#include "STD_Types.h"

#define NVIC_GPIOF 30

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
#define SCS_BASE     (0xE000E000UL)                            /*!< System Control Space Base Address */
#define NVIC_BASE    (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */

#define NVIC          ((NVIC_Type*) NVIC_BASE)   /*!< NVIC configuration struct */




/*Function declarations*/
void NVIC_SetInterrupt(uint8_t u8InterruptID);
void NVIC_ClearInterrupt(uint8_t u8InterruptID);
void NVIC_SetPending(uint8_t u8InterruptID);
void NVIC_ClearPending(uint8_t u8InterruptID);
void NVIC_SetPriority(uint8_t u8InterruptID, uint8_t u8InterruptPriority);


#endif