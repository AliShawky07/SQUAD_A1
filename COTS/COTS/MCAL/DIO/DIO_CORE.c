/*
 * DIO_CORE.c
 *
 * Created: 8/19/2023 5:44:36 PM
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
#include "DIO_CORE.h"

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
* \Syntax          : void DIO_WRITE_CHANNEL (uint8 PIN_NUM , PIN_VALUE_T PIN_VALUE)      
* \Description     : DIO_WRITE_CHANNEL                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_WRITE_CHANNEL (uint8 PIN_NUM , uint8 PIN_VALUE)
{
	uint8 PORT = 0 , PIN = 0;
	PORT = PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
	PIN = PIN_NUM % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(PIN_VALUE)
	{
		case PIN_HIGH:
		
		switch(PORT)
		{
		case 0:
		SET_BIT (PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 1:
		SET_BIT (PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 2:
		SET_BIT (PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 3:
		SET_BIT (PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		default:
		break;
		}
		break;
	
		case PIN_LOW:
		
		switch(PORT)
		{
		case 0:
		CLR_BIT (PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 1:
		CLR_BIT (PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 2:
		CLR_BIT (PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 3:
		CLR_BIT (PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		default:
		break;
		}
		break;


	break;
	}
	
}
/******************************************************************************
* \Syntax          : void DIO_READ_CHANNEL (uint8 PIN_NUM , PIN_VALUE_T * PIN_VALUE)
* \Description     : DIO_READ_CHANNEL
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_READ_CHANNEL (uint8 PIN_NUM , uint8 * PIN_VALUE)
{
	uint8 PORT = 0 , PIN = 0;
	PORT = PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
	PIN = PIN_NUM % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(PORT)
	{
	case 0:
	*PIN_VALUE = GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) , PIN);
	break;
	
	case 1:
	*PIN_VALUE = GET_BIT (PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) , PIN);
	break;
	
	case 2:
	*PIN_VALUE = GET_BIT (PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) , PIN);
	break;
	
	case 3:
	*PIN_VALUE = GET_BIT (PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) , PIN);
	break;
	
	default:
	break;
	}	
}
/******************************************************************************
* \Syntax          : void DIO_TOGGLE_CHANNEL (uint8 PIN_NUM)
* \Description     : DIO_TOGGLE_CHANNEL
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_TOGGLE_CHANNEL (uint8 PIN_NUM)
{
	uint8 PORT = 0 , PIN = 0;
	PORT = PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
	PIN = PIN_NUM % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(PORT)
	{
		case 0:
		Toggle_BIT (PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 1:
		Toggle_BIT (PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 2:
		Toggle_BIT (PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		case 3:
		Toggle_BIT (PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) , PIN);
		break;
		
		default:
		break;
	}
}
/******************************************************************************
* \Syntax          : void DIO_WRITE_PORT (uint8 PIN_NUM , PORT_VALUE_T PORT_VALUE)
* \Description     : DIO_WRITE_PORT
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_WRITE_PORT (uint8 PIN_NUM , uint8 PORT_VALUE)
{
	uint8 PORT = 0 , PIN = 0;
	PORT = PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
	PIN = PIN_NUM % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(PORT)
	{
		case 0:
		PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = PORT_VALUE;
		break;
		
		case 1:
		PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = PORT_VALUE;
		break;
		
		case 2:
		PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = PORT_VALUE;
		break;
		
		case 3:
		PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = PORT_VALUE;
		break;
		
		default:
		break;
	}
}
/******************************************************************************
* \Syntax          : void DIO_READ_PORT (uint8 PIN_NUM , PORT_VALUE_T * PORT_VALUE)
* \Description     : DIO_READ_PORT
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_READ_PORT (uint8 PIN_NUM , uint8 * PORT_VALUE)
{
	uint8 PORT = 0 ;
	PORT = PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
	
	switch(PORT)
	{
		case 0:
		*PORT_VALUE = PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 1:
		*PORT_VALUE = PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 2:
		*PORT_VALUE = PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 3:
		*PORT_VALUE = PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		default:
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
