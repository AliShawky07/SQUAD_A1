/*
 * Seven_Seg.c
 *
 * Created: 8/18/2023 4:09:34 PM
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
#include "Seven_Seg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 uint8 SEVEN_SEG[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XDE};
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
* \Syntax          : void SEVEN_SEG_Init(void)
* \Description     : SEVEN SEG INIT
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void SEVEN_SEG_Init(void)
{
 SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR )  , 6);
 SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR )  , 7);
 PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR )  = 0XFF;
}
/******************************************************************************
* \Syntax          : void SEVEN_SEG_Display(void)
* \Description     : SEVEN SEG DISPLAY
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void SEVEN_SEG_Display(void)
{	
 SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 6);
 CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 7);//NEW
 PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT ) = SEVEN_SEG[93%10];//NEW
 _delay_ms (1);

 CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 6);//NEW
 SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT )  , 7);
 PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT ) = SEVEN_SEG[93/10];//NEW
 _delay_ms (1);
}

/***********************************************************************************************************************  
END OF FILE: Seven_Seg.c
 *********************************************************************************************************************/
