/*
 * main.c
 *
 *  Created on: Apr 26, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Scheduler.h"
#include "Scheduler_cfg.h"
#include "avr/interrupt.h"
#include "avr/io.h"

int main(void)
{
	DDRA = 0xFF;
	sei();
	Sched_vidInit();
	Sched_vidStart();
	return 0;
}
