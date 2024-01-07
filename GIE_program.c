/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 30/8/2023
//                              *Component GIE*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);

}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);

}
