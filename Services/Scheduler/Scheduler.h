/*
 * Scheduler.h
 *
 *  Created on: Apr 26, 2022
 *      Author: WINDOWS
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

typedef struct{
	u16 FirstDelay;
	u16 Peridicity;
	u8 State ;
	void (*Pcode)(void);
}Task_t;

void Sched_vidInit(void);
void Sched_vidStart(void);

#endif /* SCHEDULER_H_ */
