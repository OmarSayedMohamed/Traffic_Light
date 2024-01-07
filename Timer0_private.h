/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 06/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0       *((volatile u8*)0x53)  // Timer-Counter-Control-Register
#define TCCR0_CS00     0
#define TCCR0_CS01     1
#define TCCR0_CS02     2

#define TCCR0_WGM00    6
#define TCCR0_WGM01    3

#define TCCR0_COM00    4
#define TCCR0_COM01    5

#define OCR0        *((volatile u8*)0x5C)  // Compare Value

#define TIMSK       *((volatile u8*)0x59)  // Interrupt Enable
#define TIMSK_TOIE0     0  // Interrupt Enable OVF Mode
#define TIMSK_OCIE0     1  // Interrupt Enable CMP Mode

#define TIFR        *((volatile u8*)0x58)  // Flag Register
#define TIFR_TOV0       0  // Interrupt Flag OVF Mode
#define TIFR_OCF0       1  // Interrupt Flag CMP Mode

#define TCNT0       *((volatile u8*)0x52)  // Ticks Number


#define OVF_MODE   1
#define CTC_MODE   2
#define FAST_PWM   3


#define  DIV_BY_1         1
#define  DIV_BY_8         2
#define  DIV_BY_64        3
#define  DIV_BY_256       4
#define  DIV_BY_1024      5

#define S_TOP_C_CMP       1
#define C_TOP_S_CMP       2



#endif
