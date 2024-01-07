/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 08/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void TIMER2_voidInit(void);

u8 TIMER2_u8SetCallBack(void (*Copy_ptrtofunc) (void));

void TIMER2_voidSetOCRValue(u8 Copy_u8Value);

void TIMER2_voidSetPWMMode(void);












#endif
