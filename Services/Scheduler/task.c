/*
 * task.c
 *
 *  Created on: Apr 27, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "task.h"
#include "avr/io.h"

void task(void)
{
	TGL_BIT(PORTA,0);
}
