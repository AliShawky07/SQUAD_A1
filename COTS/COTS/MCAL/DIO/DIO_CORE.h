/*
 * DIO_CORE.h
 *
 * Created: 8/19/2023 5:44:49 PM
 *  Author: Telbany
 */ 
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_CORE_H_
#define DIO_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_EACH_PORT_PINS 8

#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7

#define PORTB_PIN0  8
#define PORTB_PIN1  9
#define PORTB_PIN2  10
#define PORTB_PIN3  11
#define PORTB_PIN4  12
#define PORTB_PIN5  13
#define PORTB_PIN6  14
#define PORTB_PIN7  15

#define PORTC_PIN0  16
#define PORTC_PIN1  17
#define PORTC_PIN2  18
#define PORTC_PIN3  19
#define PORTC_PIN4  20
#define PORTC_PIN5  21
#define PORTC_PIN6  22
#define PORTC_PIN7  23

#define PORTD_PIN0  24
#define PORTD_PIN1  25
#define PORTD_PIN2  26
#define PORTD_PIN3  27
#define PORTD_PIN4  28
#define PORTD_PIN5  29
#define PORTD_PIN6  30
#define PORTD_PIN7  31

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH
}PIN_VALUE_T;

/*typedef enum
{
	PORT_LOW = 0X00,
	PORT_HIGH = 0XFF
}PORT_VALUE_T;*/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void DIO_WRITE_CHANNEL (uint8 PIN_NUM , PIN_VALUE_T PIN_VALUE);
void DIO_READ_CHANNEL (uint8 PIN_NUM , PIN_VALUE_T * PIN_VALUE);
void DIO_TOGGLE_CHANNEL (uint8 PIN_NUM);
void DIO_WRITE_PORT (uint8 PIN_NUM , uint8 PORT_VALUE);
void DIO_READ_PORT (uint8 PIN_NUM , uint8 * PORT_VALUE);
 
#endif /* DIO_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/








