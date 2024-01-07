/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 08/9/2023
//                              *Component Timer2*
/*******************************************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TCCR2       *((volatile u8*)0x45)  // Timer-Counter-Control-Register
#define TCCR2_CS20     0
#define TCCR2_CS21     1
#define TCCR2_CS22     2

#define TCCR2_WGM20    6
#define TCCR2_WGM21    3

#define TCCR2_COM20    4
#define TCCR2_COM21    5

#define OCR2        *((volatile u8*)0x43)  // Compare Value

#define TIMSK       *((volatile u8*)0x59)  // Interrupt Enable
#define TIMSK_TOIE2     6  // Interrupt Enable OVF Mode
#define TIMSK_OCIE2     7  // Interrupt Enable CMP Mode

#define TIFR        *((volatile u8*)0x58)  // Flag Register
#define TIFR_TOV2       6  // Interrupt Flag OVF Mode
#define TIFR_OCF2       7  // Interrupt Flag CMP Mode

#define TCNT2       *((volatile u8*)0x44)  // Ticks Number


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
