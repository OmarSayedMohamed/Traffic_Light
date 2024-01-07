/*******************************************************************************/
// Layer : MCAL

// Author : OMAR Sayed
// Version : 01
// Date : 13/9/2023
//                              *Component USART*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit(void)
{

	UBRRL = 51; // BAUDE Rate 9600
	UCSRC = 0b10000110; // low parity check , char size 8 , one stop data
	UCSRB = 0b00011000; // REC and TRANS
}

void USART_voidSend(u8 Copy_u8data)
{
	while((GET_BIT(UCSRA,UCSRA_UDRE)) == 0);
	UDR = Copy_u8data;
}

u8 USART_u8Recieve(void)
{
	while((GET_BIT(UCSRA,UCSRA_RXC)) == 0);
	return UDR;

}
