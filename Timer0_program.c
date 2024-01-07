/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 06/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer0_interface.h"
#include "Timer0_config.h"
#include "Timer0_private.h"


static void (*Global_ptrtofunc) (void) = NULL;

void TIMER0_voidInit(void)
{

#if TIMER0_MODE == CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

#elif  TIMER0_MODE == OVF_MODE
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

#elif  TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);


#else
#error ("WRONG_CHOICE_OF_MODE");

#endif

#if PRE_SCALER  == DIV_BY_1
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif PRE_SCALER == DIV_BY_8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif PRE_SCALER == DIV_BY_64
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

#elif PRE_SCALER == DIV_BY_256
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);

#elif PRE_SCALER == DIV_BY_1024
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error ("WRONG_PRESCALER");

#endif




	// Compare Match Event Interrupt Enable
	SET_BIT(TIMSK,TIMSK_OCIE0);


}

u8 TIMER0_u8SetCallBack(void (*Copy_ptrtofunc) (void))
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

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
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
void TIMER0_voidSetOCRValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

// Set Fast PWM Mode
void TIMER0_voidSetPWMMode(void)
{
#if FAST_PWM_MODE ==  S_TOP_C_CMP
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);

#elif  FAST_PWM_MODE ==  C_TOP_S_CMP
	SET_BIT(TCCR0,TCCR0_COM01);
	SET_BIT(TCCR0,TCCR0_COM00);

#else
#error ("WRONG_CHOICE_OF_MODE");

#endif
}
