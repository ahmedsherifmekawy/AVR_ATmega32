/*
 * main.c
 *
 *  Created on: Apr 26, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Bit_utils.h"
#include "Gpt.h"
#include "avr/io.h"
#include <math.h>
#include "avr/interrupt.h"

#define TICK_TIME_MS            1000
#define FREQ                    16000000


u16 x;

void task()
{
	static u16 counter = 0;
	counter ++;
	if(counter == x+1)
	{
		TGL_BIT(PORTA,0);
		SET_BIT(PORTA,1);
		counter = 0;
	}
}

int main(void)
{

	u16 Sched_u16OverflowNum;
	u16 Sched_u16Preload;
	f32 OverflowTime;
	f32 OverFlow_Number;
	f32 OverFlow_Number_fraction;

	sei();
	DDRA = 0xFF;

	Gpt_ConfigType Loc_strTimerCfg;
	Loc_strTimerCfg.Channel = Timer0;
	Loc_strTimerCfg.T0 -> CS = GPT_u8_CS_T01CLK_PRE_64;
	Loc_strTimerCfg.T0 -> COM = GPT_u8_COM_NORMAL_PORT_OPERATION;
	Loc_strTimerCfg.T0 -> WGM = GPT_u8_WGM_T02NORMAL_MODE;
	Loc_strTimerCfg.T0 -> ModeOfOPeration = GPT_u8T0INTERRUPT_NORMAL;


	OverflowTime = ( (u32)256 * 64 * 1000 ) / (f32) 16000000 ;//MS
	OverFlow_Number = TICK_TIME_MS / OverflowTime ;
	Sched_u16OverflowNum = (u16) OverFlow_Number;
	OverFlow_Number_fraction = round(OverFlow_Number*100000)/100000 - Sched_u16OverflowNum;
	Sched_u16Preload = 256 *(1 - OverFlow_Number_fraction );
	if( Sched_u16Preload != 0 )
		Sched_u16OverflowNum ++;

	x=Sched_u16OverflowNum;

	Gpt_enuInit( &Loc_strTimerCfg );
	Gpt_enuT0OverflowRegiserCbf(task);
	Gpt_enuStartTimer( Loc_strTimerCfg.Channel , Sched_u16Preload );

	while(1);
	return 0;
}
