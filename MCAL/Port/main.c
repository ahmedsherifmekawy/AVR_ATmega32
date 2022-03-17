/*
 * main.c
 *
 *  Created on: Mar 13, 2022
 *      Author: WINDOWS

*/

#include "Std_types.h"
#include "Bit_utils.h"
#include "Port.h"


int main(void)
{
	Port_enuSetPinDirection(0,1);
	Port_enuSetPinMode(2,PORT_u8OUTPUT_HIGH);
	return 0;
}
