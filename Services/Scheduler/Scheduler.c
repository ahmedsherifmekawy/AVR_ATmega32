/*
 * Scheduler.c
 *
 *  Created on: Apr 26, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Gpt.h"
#include "Scheduler.h"
#include "Scheduler_cfg.h"
#include <math.h>

extern Task_t * TaskList[SCHED_NUM_OF_TASKS];

u16 Sched_u16OverflowNum;
u16 Sched_u16Preload;

void Sched(void)
{
	u8 Loc_u8Idx;
	static u16 Counter;

	Counter++;
	if( Counter == Sched_u16OverflowNum + 1 )
	{
		for( Loc_u8Idx = 0 ; Loc_u8Idx < SCHED_NUM_OF_TASKS ; Loc_u8Idx ++ )
		{
			if( TaskList [ Loc_u8Idx ] != NULL )
			{
				if( TaskList [ Loc_u8Idx ] -> State == 1 )
				{
					if( TaskList [ Loc_u8Idx ] -> FirstDelay  == 0 )
					{
						TaskList [ Loc_u8Idx ] -> Pcode();
						TaskList [ Loc_u8Idx ] -> FirstDelay = TaskList [ Loc_u8Idx ] -> Peridicity;
					}
					TaskList[ Loc_u8Idx ] -> FirstDelay --;
				}
			}
		}
		Counter = 0;
	}
}
void Sched_vidInit(void)
{
	Gpt_ConfigType Loc_strTimerCfg;
	f32 OverflowTime;
	f32 OverFlow_Number;
	f32 OverFlow_Number_fraction;

	Loc_strTimerCfg.Channel = Timer0;
	Loc_strTimerCfg.T0 -> CS = GPT_u8_CS_T01CLK_PRE_64;
	Loc_strTimerCfg.T0 -> COM = GPT_u8_COM_NORMAL_PORT_OPERATION;
	Loc_strTimerCfg.T0 -> WGM = GPT_u8_WGM_T02NORMAL_MODE;
	Loc_strTimerCfg.T0 -> ModeOfOPeration = GPT_u8T0INTERRUPT_NORMAL;


	OverflowTime = ( (u32)256 * 64 * 1000 ) / (f32) 16000000 ;//MS
	OverFlow_Number = 1000 / OverflowTime ;
	Sched_u16OverflowNum = (u16) OverFlow_Number;
	OverFlow_Number_fraction = round(OverFlow_Number*100000)/100000 - Sched_u16OverflowNum;
	Sched_u16Preload = 256 *(1 - OverFlow_Number_fraction );
	if( Sched_u16Preload != 0 )
		Sched_u16OverflowNum ++;

	Gpt_enuInit( &Loc_strTimerCfg );
	Gpt_enuT0OverflowRegiserCbf(Sched);
}
void Sched_vidStart(void)
{
	Gpt_ChannelType Loc_enuChannel = Timer0;
	Gpt_enuStartTimer( Loc_enuChannel , Sched_u16Preload );
	while(1);
}
