/*
 * Scheduler_cfg.c
 *
 *  Created on: Apr 26, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Scheduler.h"
#include "Scheduler_cfg.h"
#include "task.h"

Task_t x ={
		.State = 1,
		.Peridicity = 1,
		.FirstDelay = 0,
		.Pcode = task,
};

Task_t * TaskList[SCHED_NUM_OF_TASKS] = {

		[0] = &x
};


