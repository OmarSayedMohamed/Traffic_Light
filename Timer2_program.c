/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 08/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer2_interface.h"
#include "Timer2_config.h"
#include "Timer2_private.h"


static void (*Global_ptrtofunc) (void) = NULL;

void TIMER2_voidInit(void)
{

#if TIMER2_MODE == CTC_MODE
	SET_BIT(TCCR2,TCCR2_WGM21);
	CLR_BIT(TCCR2,TCCR2_WGM20);

#elif  TIMER2_MODE == OVF_MODE
	CLR_BIT(TCCR2,TCCR2_WGM21);
	CLR_BIT(TCCR2,TCCR2_WGM20);

#elif  TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TCCR2,TCCR2_WGM20);


#else
#error ("WRONG_CHOICE_OF_MODE");

#endif

#if PRE_SCALER  == DIV_BY_1
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif PRE_SCALER == DIV_BY_8
	CLR_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif PRE_SCALER == DIV_BY_64
	SET_BIT(TCCR2,TCCR2_CS20);
	SET_BIT(TCCR2,TCCR2_CS21);
	CLR_BIT(TCCR2,TCCR2_CS22);

#elif PRE_SCALER == DIV_BY_256
	CLR_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);

#elif PRE_SCALER == DIV_BY_1024
	SET_BIT(TCCR2,TCCR2_CS20);
	CLR_BIT(TCCR2,TCCR2_CS21);
	SET_BIT(TCCR2,TCCR2_CS22);
#else
#error ("WRONG_PRESCALER");

#endif




	// Compare Match Event Interrupt Enable
	SET_BIT(TIMSK,TIMSK_OCIE2);


}

u8 TIMER2_u8SetCallBack(void (*Copy_ptrtofunc) (void))
{
	u8 Local_u8Errorstate= OK;

	if (Copy_ptrtofunc !=NULL)
	{
		Global_ptrtofunc=Copy_ptrtofunc;
	}

	else
	{
		Local_u8Errorstate = NOK;
	}

	return Local_u8Errorstate;
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if (Global_ptrtofunc !=NULL)
	{
		Global_ptrtofunc ();

	}
	/*
	static u16 Local_u16Counter=0;
	Local_u16Counter ++;
	if (4000 == Local_u16Counter)
	{
		if (Global_ptrtofunc !=NULL)
		{
			Global_ptrtofunc ();
			Local_u16Counter =0;
		}
	}
	 */
}

// Set OCR Value
void TIMER2_voidSetOCRValue(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

// Set Fast PWM Mode
void TIMER2_voidSetPWMMode(void)
{
#if FAST_PWM_MODE ==  S_TOP_C_CMP
	SET_BIT(TCCR2,TCCR2_COM21);
	CLR_BIT(TCCR2,TCCR2_COM20);

#elif  FAST_PWM_MODE ==  C_TOP_S_CMP
	SET_BIT(TCCR2,TCCR2_COM21);
	SET_BIT(TCCR2,TCCR2_COM20);

#else
#error ("WRONG_CHOICE_OF_MODE");

#endif
}
