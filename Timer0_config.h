/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 06/9/2023
//                              *Component Timer0*
/*******************************************************************************/

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*
 * Options
 * 1- OVF_MODE
 * 2- CTC_MODE
 * 3- FAST_PWM
 */


#define TIMER0_MODE  CTC_MODE

/*
 * Options
 * 1- DIV_BY_1
 * 2- DIV_BY_8
 * 3- DIV_BY_64
 * 4- DIV_BY_256
 * 5- DIV_BY_1024
 *
 */
#define PRE_SCALER   DIV_BY_64

/* Options Fast PWM
 * 1-S_TOP_C_CMP
 * 2-C_TOP_S_CMP
 */

#define FAST_PWM_MODE   S_TOP_C_CMP


#endif
