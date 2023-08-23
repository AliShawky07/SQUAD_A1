/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author: Telbany
 */ 


#include "LED.h"
//#include "BUZZ.h"
#include "BUTTON.h"
#include "RELAY.h"
#include "Seven_Seg.h"
#include "PORT_CORE.h"
#define F_CPU 16000000U
#include <util\delay.h>

int main(void)
{
	
uint8 VALUE = 0;
PORT_Init();

   while (1)
   {
	   
	   VALUE = BUTTON_GETVALUE(BTN_1);
	   if(VALUE == 1)
	   {
		   LED_Toggle(LED_GREEN);
	   }
	   
	   VALUE = BUTTON_GETVALUE(BTN_2);
	   if(VALUE == 1)
	   {
		   LED_Toggle(LED_BLUE);
	   }
	    VALUE = BUTTON_GETVALUE(BTN_3);
	    if(VALUE == 1)
	    {
		    LED_Toggle(LED_RED);
	    }
	 
   }
   
}

