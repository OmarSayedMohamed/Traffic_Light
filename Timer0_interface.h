/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 06/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack(void (*Copy_ptrtofunc) (void));

void TIMER0_voidSetOCRValue(u8 Copy_u8Value);

void TIMER0_voidSetPWMMode(void);











#endif
