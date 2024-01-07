/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: hp
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"
#include "Timer0_interface.h"
#include "Timer2_interface.h"
#include "USART_interface.h"

void led (void);
void seg (void);

// Custom Character People
u8 people[8] = {
		0x00,
		0x00,
		0x15,
		0x0E,
		0x04,
		0x0A,
		0x11,
		0x00
};
// Custom Character Car
u8 car [8] = {
		0x00,
		0x00,
		0x0E,
		0x0E,
		0x0E,
		0x11,
		0x1F,
		0x1B
};
// Custom Character Stop
u8 stop [8] =
{
		0x00,
		0x00,
		0x0F,
		0x0F,
		0x0F,
		0x0F,
		0x1F,
		0x1F
};
// Initialize Seven Segment
u8 sev_seg[10] =
{
		0b11101111,    /* 9 */
		0b11111111,   /* 8 */
		0b10000111,   /* 7 */
		0b11111101,   /* 6 */
		0b11101101,   /* 5 */
		0b11100110,   /* 4 */
		0b11001111,   /* 3 */
		0b11011011,   /* 2 */
		0b10000110,   /* 1 */
		0b10111111   /* 0 */
};

void main (void)

{
	//DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT); // Make PORTA Output for Traffic Led

	// Timer0 Initialization
	TIMER0_voidSetOCRValue(125);
	TIMER0_voidInit();

	// Timer2 Initialization
	TIMER2_voidSetOCRValue(125);
	TIMER2_voidInit();

	// LCD Initialization
	DIO_voidSetPortDir(PORTB_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTC_REG,PORT_DIR_OUT);




	// Seven Segment Initialization
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);

	CLCD_voidInit();
	TIMER0_u8SetCallBack(led);
	TIMER2_u8SetCallBack(seg);
	GIE_voidEnable();


	DIO_voidSetPinDir(PORTD_REG,PIN0,PIN_DIR_OUT);
	DIO_voidSetPinDir(PORTD_REG,PIN1,PIN_DIR_IN);
	USART_voidInit();
	while (1)
	{

	}

}

void led (void)
{
	static u32 Local_u16counter = 0;
	Local_u16counter ++;


	if (Local_u16counter == 500)
	{
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" Car Can Go");
		CLCD_voidDrawSpecialChar(car,0,1,10);
		for (u8 i=0 ; i<8 ; i++)
		{
			CLCD_voidSendData(car[i]);
		}
		/*
		DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_HIGH);
		DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTA_REG,PIN2,PIN_VAL_LOW);
		 */
		USART_voidSend('1');

	}

	else if (Local_u16counter == 5500)
	{
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString("    ALL Stop");
		CLCD_voidDrawSpecialChar(stop,0,1,7);
		for (u8 j=0 ; j<8 ; j++)
		{
			CLCD_voidSendData(stop[j]);
		}
		/*
		DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(PORTA_REG,PIN2,PIN_VAL_LOW);
		 */
		USART_voidSend('2');
	}

	else if (Local_u16counter == 8000)
	{
		CLCD_voidSendCommand(Clear);
		CLCD_voidSendString(" People Can GO");
		CLCD_voidDrawSpecialChar(people,0,1,9);
		for (u8 k=0 ; k<8 ; k++)
		{
			CLCD_voidSendData(people[k]);
		}
		/*
		DIO_voidSetPinVal(PORTA_REG,PIN0,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTA_REG,PIN1,PIN_VAL_LOW);
		DIO_voidSetPinVal(PORTA_REG,PIN2,PIN_VAL_HIGH);
		 */
		USART_voidSend('3');

	}

	else if (Local_u16counter == 13000)
	{
		Local_u16counter = 0;
	}

}

void seg (void)
{
	static u16 Local_u16counter1 = 0;
	Local_u16counter1 ++;


	if (Local_u16counter1 == 1000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[0]);
	}

	else if (Local_u16counter1 == 2000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[1]);
	}
	else if (Local_u16counter1 == 3000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[2]);
	}

	else if (Local_u16counter1 == 4000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[3]);
	}
	else if (Local_u16counter1 == 5000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[4]);
	}
	else if (Local_u16counter1 == 6000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[5]);
	}
	else if (Local_u16counter1 == 7000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[6]);
	}
	else if (Local_u16counter1 == 8000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[7]);
	}
	else if (Local_u16counter1 == 9000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[8]);
	}
	else if (Local_u16counter1 == 10000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[9]);
	}
	else if (Local_u16counter1 == 12000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[6]);
	}
	else if (Local_u16counter1 == 13000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[7]);
	}
	else if (Local_u16counter1 == 14000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[8]);
	}
	else if (Local_u16counter1 == 15000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[9]);
	}
	if (Local_u16counter1 == 16000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[0]);
	}

	else if (Local_u16counter1 == 17000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[1]);
	}
	else if (Local_u16counter1 == 18000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[2]);
	}

	else if (Local_u16counter1 == 19000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[3]);
	}
	else if (Local_u16counter1 == 20000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[4]);
	}
	else if (Local_u16counter1 == 21000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[5]);
	}
	else if (Local_u16counter1 == 22000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[6]);
	}
	else if (Local_u16counter1 == 23000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[7]);
	}
	else if (Local_u16counter1 == 24000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[8]);
	}
	else if (Local_u16counter1 == 25000)
	{
		DIO_voidSetPortVal(PORTA_REG,sev_seg[9]);
	}
	else if (Local_u16counter1 == 26000)
	{
		Local_u16counter1 =0;
	}
}

