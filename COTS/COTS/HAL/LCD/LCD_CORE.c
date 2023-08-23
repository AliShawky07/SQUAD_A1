/*
 * LCD_CORE.c
 *
 * Created: 8/23/2023 9:28:53 PM
 *  Author: Telbany
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void LCD_Init(void)       
* \Description     : LCD_Init                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LCD_Init(void)
{
	//#if (LCD_MODE == LCD_4BIT_MODE)

	LCD_WRITE_COMMAND(0X33);
	LCD_WRITE_COMMAND(0X32);
	LCD_WRITE_COMMAND(0X28);
	
	LCD_WRITE_COMMAND(0X0E);
	//LCD_WRITE_COMMAND(0X0C);
	
	LCD_WRITE_COMMAND(0X01);
	LCD_WRITE_COMMAND(0X06);
	LCD_WRITE_COMMAND(0X02);
	

//#endif
}

/******************************************************************************
* \Syntax          : void LCD_WRITE_COMMAND(uint8 cmd)
* \Description     : LCD_WRITE_COMMAND
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WRITE_COMMAND(uint8 cmd)
{
	uint8 OLD_VALUE = 0 , NEW_VALUE = 0;
	DIO_WRITE_CHANNEL(LCD_RS_PIN , PIN_LOW);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	#if (LCD_MODE == LCD_4BIT_MODE)
	//highest
	/*DIO_READ_OUTPUT_PORT (LCD_D4_PIN , &OLD_VALUE);
	NEW_VALUE = ((cmd >> 1) & DATA_MASK) | (OLD_VALUE & DATA_PORT_MASK);
	DIO_WRITE_PORT(LCD_D4_PIN , NEW_VALUE);
	*/
	DIO_WRITE_CHANNEL(LCD_D4_PIN , GET_BIT(cmd , 4));
	DIO_WRITE_CHANNEL(LCD_D5_PIN , GET_BIT(cmd , 5));
	DIO_WRITE_CHANNEL(LCD_D6_PIN , GET_BIT(cmd , 6));
	DIO_WRITE_CHANNEL(LCD_D7_PIN , GET_BIT(cmd , 7));
	
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	//lowest
	/*DIO_READ_OUTPUT_PORT (LCD_D4_PIN , &OLD_VALUE);
	NEW_VALUE = ((cmd << 3) & DATA_MASK) | (OLD_VALUE & DATA_PORT_MASK);
	DIO_WRITE_PORT(LCD_D4_PIN , NEW_VALUE);
	*/
	DIO_WRITE_CHANNEL(LCD_D4_PIN , GET_BIT(cmd , 0));
	DIO_WRITE_CHANNEL(LCD_D5_PIN , GET_BIT(cmd , 1));
	DIO_WRITE_CHANNEL(LCD_D6_PIN , GET_BIT(cmd , 2));
	DIO_WRITE_CHANNEL(LCD_D7_PIN , GET_BIT(cmd , 3));
	
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);
	
#endif
}

/******************************************************************************
* \Syntax          : void LCD_WRITE_CHAR(uint8 chr)
* \Description     : LCD_WRITE_CHAR
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WRITE_CHAR(uint8 cmd)
{
	uint8 OLD_VALUE = 0 , NEW_VALUE = 0;
	DIO_WRITE_CHANNEL(LCD_RS_PIN , PIN_HIGH);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	#if (LCD_MODE == LCD_4BIT_MODE)
	//highest
	/*DIO_READ_OUTPUT_PORT (LCD_D4_PIN , &OLD_VALUE);
	NEW_VALUE = ((chr >> 1) & DATA_MASK) | (OLD_VALUE & DATA_PORT_MASK);
	DIO_WRITE_PORT(LCD_D4_PIN , NEW_VALUE);
	*/
	DIO_WRITE_CHANNEL(LCD_D4_PIN , GET_BIT(cmd , 4));
	DIO_WRITE_CHANNEL(LCD_D5_PIN , GET_BIT(cmd , 5));
	DIO_WRITE_CHANNEL(LCD_D6_PIN , GET_BIT(cmd , 6));
	DIO_WRITE_CHANNEL(LCD_D7_PIN , GET_BIT(cmd , 7));
	
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	//lowest
	/*
	DIO_READ_OUTPUT_PORT (LCD_D4_PIN , &OLD_VALUE);
	NEW_VALUE = ((chr << 3) & DATA_MASK) | (OLD_VALUE & DATA_PORT_MASK);
	DIO_WRITE_PORT(LCD_D4_PIN , NEW_VALUE);
	*/
	DIO_WRITE_CHANNEL(LCD_D4_PIN , GET_BIT(cmd , 0));
	DIO_WRITE_CHANNEL(LCD_D5_PIN , GET_BIT(cmd , 1));
	DIO_WRITE_CHANNEL(LCD_D6_PIN , GET_BIT(cmd , 2));
	DIO_WRITE_CHANNEL(LCD_D7_PIN , GET_BIT(cmd , 3));
	
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WRITE_CHANNEL(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);
	
#endif
}

/******************************************************************************
* \Syntax          : void LCD_WRITE_STRING(uint8* chr)
* \Description     : LCD_WRITE_STRING
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WRITE_STRING(uint8* chr)
{
	uint8 cnt = -1;
	
	while(chr[cnt] != '\0')
	{
		LCD_WRITE_CHAR(chr[cnt]);
		cnt++;
	}
}

/******************************************************************************
* \Syntax          : void LCD_CLEAR(void)
* \Description     : LCD_CLEAR
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_CLEAR(void)
{
	LCD_WRITE_COMMAND(0X01);
}
/******************************************************************************
* \Syntax          : void LCD_CLEAR(void)
* \Description     : LCD_CLEAR
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_GOTO(uint8 ROW , uint8 COL)
{
	uint8 arr[2] = {0X00 , 0XC0};
		
		LCD_WRITE_COMMAND(arr[ROW]+COL);
}

//void LCD_WRITE_INTEGER(uint32 num)


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
