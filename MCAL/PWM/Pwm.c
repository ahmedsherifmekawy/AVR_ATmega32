/*
 * Pwm.c
 *
 *  Created on: Apr 28, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "avr/io.h"
#include "Pwm.h"

u8 ClockPrescaller;

Pwm_tenuErrorStatus Pwm_enuInit(Pwm_tstrCfg * Add_pstrPwmCfg)
{
	Pwm_tenuErrorStatus Loc_enuError = PwmOk;
	u16 Loc_u16Reg;
	if(Add_pstrPwmCfg == NULL)
	{
		Loc_enuError = PwmNok;
	}
	else
	{
		ClockPrescaller = Add_pstrPwmCfg -> CS;
		switch( Add_pstrPwmCfg ->Channel )
		{
			case Channel0:
			{
				Loc_u16Reg = TCCR0 | PWM_u16T0WGM_MASK ;
				Loc_u16Reg &= ( Add_pstrPwmCfg -> WGM | ~PWM_u16T0WGM_MASK );
				TCCR0 = Loc_u16Reg;

				Loc_u16Reg = TCCR0 | PWM_u16T0COM_MASK ;
				Loc_u16Reg &= ( Add_pstrPwmCfg -> COM | ~PWM_u16T0COM_MASK );
				TCCR0 = Loc_u16Reg;

				break;
			}
		}

	}
	return Loc_enuError;
}
Pwm_tenuErrorStatus Pwm_enuSetOCR(Pwm_tenuChannel Copy_enuChannel , u16 Copy_u16Value )
{
	Pwm_tenuErrorStatus Loc_enuError = PwmOk;
	if(Copy_enuChannel > Channel2)
	{
		Loc_enuError = PwmNok;
	}
	else
	{
		switch( Copy_enuChannel )
		{
			case Channel0:
			{
				OCR0 = Copy_u16Value;
				break;
			}
			case Channel1:
			{
				OCR1A = Copy_u16Value;
				break;
			}
			case Channel2:
			{
				OCR2 = Copy_u16Value;
				break;
			}
		}
	}
	return Loc_enuError;
}
void Pwm_enuSetICR(u16 Copy_u16Value)
{
	ICR1 = Copy_u16Value;
}
Pwm_tenuErrorStatus Pwm_enuStart(Pwm_tenuChannel Copy_enuChannel )
{
	Pwm_tenuErrorStatus Loc_enuError = PwmOk;
	u16 Loc_u16Reg;
	if(Copy_enuChannel > Channel2)
	{
		Loc_enuError = PwmNok;
	}
	else
	{
		switch(Copy_enuChannel)
		{
			case Channel0:
			{
				Loc_u16Reg = TCCR0 | PWM_u16T0CLK_MASK ;
				Loc_u16Reg &= ( ClockPrescaller | ~PWM_u16T0CLK_MASK );
				TCCR0 = Loc_u16Reg;
				break;
			}
			case Channel2:
			{
				Loc_u16Reg = TCCR2 | PWM_u16T0CLK_MASK ;
				Loc_u16Reg &= ( ClockPrescaller | ~PWM_u16T0CLK_MASK );
				TCCR2 = Loc_u16Reg;
				break;
			}
		}
	}
	return Loc_enuError;
}
