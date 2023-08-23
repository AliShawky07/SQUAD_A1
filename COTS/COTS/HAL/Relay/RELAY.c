/*
 * RELAY.c
 *
 * Created: 8/16/2023 8:02:41 PM
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
#include "RELAY.h"

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void RELAY_Init(void)
{

	 SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR )  , 3);
	 SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR )  , 4);
}
/******************************************************************************
* \Syntax          : void BUZZ_On(void)
* \Description     : BUZZER ON
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RELAY_On(void)
{
	SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 3);
	SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 4);
}
/******************************************************************************
* \Syntax          : void BUZZ_Off(void)
* \Description     : BUZZER OFF
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RELAY_Off(void)
{
	CLR_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 3);
	CLR_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 4);
}
/******************************************************************************
* \Syntax          : void BUZZ_Toggle(void)
* \Description     : BUZZER TOGGLE
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RELAY_Toggle(void)
{
	Toggle_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 3);
	Toggle_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 4);
}

/**********************************************************************************************************************
 *  END OF FILE: RELAY.c
 *********************************************************************************************************************/
