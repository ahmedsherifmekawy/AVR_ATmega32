/*
 * main.c
 *
 *  Created on: Mar 24, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "SevenSegment.h"
#include "SevenSegment_cfg.h"
#include "port.h"
#include <util/delay.h>

int main(void)
{
	u8 counter= 0;

	Port_enuSetPinDirection(PORT_u8PIN_0 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_1 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_2 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_3 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_4 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_5 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection(PORT_u8PIN_6 , PORT_u8PIN_OUTPUT );
	//Port_enuSetPinDirection(PORT_u8PIN_7 , PORT_u8PIN_OUTPUT );

	while(1)
	{
		SevenSegment_enuDisplayNumber(counter);
		counter++;
		if(counter>9)
			counter=0;
		_delay_ms(20);
	}
	return 0;
}
