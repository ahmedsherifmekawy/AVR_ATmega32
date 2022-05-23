/*
 * Gpt.c
 *
 *  Created on: Apr 18, 2022
 *      Author: WINDOWS
 */


#include "std_types.h"
#include "Bit_utils.h"
#include "avr/io.h"
#include "Gpt.h"
#include "Gpt_prv.h"

u16 PreloadValue;
u16 Clock_Prescaler;
cbf_t T0_OverflowCbf;

Gpt_tenuErrorStatus Gpt_enuInit( const Gpt_ConfigType * Add_pstrConfig )
{
	Gpt_tenuErrorStatus Loc_enuErrorStatus = GptOk;
	u16 Loc_u16Reg;
	if(Add_pstrConfig == NULL)
	{
		Loc_enuErrorStatus = GptNok;
	}
	else if( Add_pstrConfig ->Channel > Timer2)
	{
		Loc_enuErrorStatus = GptNok;
	}

	else
	{
		switch( Add_pstrConfig ->Channel )
		{
			case Timer0:
			{
				Clock_Prescaler = Add_pstrConfig -> T0 -> CS;

				Loc_u16Reg = TCCR0 | GPT_u16T02WGM_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T0 -> WGM | ~GPT_u16T02WGM_MASK );
				TCCR0 = Loc_u16Reg;

				Loc_u16Reg = TCCR0 | GPT_u16T02COM_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T0 -> COM | ~GPT_u16T02COM_MASK );
				TCCR0 = Loc_u16Reg;

				Loc_u16Reg = TIMSK;
				Loc_u16Reg |= Add_pstrConfig -> T0 -> ModeOfOPeration;
				TIMSK = Loc_u16Reg;

				OCR0 = Add_pstrConfig -> T0 -> OCR;
				break;
			}
			case Timer1:
			{
				Clock_Prescaler = Add_pstrConfig -> T1 -> CS;

				Loc_u16Reg = TCCR1A | GPT_u16T1COMA_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T1 -> COMA | ~GPT_u16T1COMA_MASK );
				TCCR1A = Loc_u16Reg;

				Loc_u16Reg = TCCR1A | GPT_u16T1COMB_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T1 -> COMB | ~GPT_u16T1COMB_MASK );
				TCCR1A = Loc_u16Reg;

				Loc_u16Reg = TIMSK;
				Loc_u16Reg |= Add_pstrConfig -> T1 -> ModeOfOPeration;
				TIMSK = Loc_u16Reg;

				OCR1A = Add_pstrConfig -> T1 -> OCRA;
				OCR1B = Add_pstrConfig -> T1 -> OCRB;

				ICR1 = Add_pstrConfig -> T1 -> ICR;

				switch( Add_pstrConfig -> T1 -> WGM )
				{
					case GPT_u8T1WGM_NORMAL:
					{
						CLR_BIT( TCCR1A , WGM10 );
						CLR_BIT( TCCR1A , WGM11 );
						CLR_BIT( TCCR1A , WGM12 );
						CLR_BIT( TCCR1A , WGM13 );
						break;
					}
					case GPT_u8T1WGM_CTC_OCRA:
					{
						CLR_BIT( TCCR1A , WGM10 );
						CLR_BIT( TCCR1A , WGM11 );
						SET_BIT( TCCR1A , WGM12 );
						CLR_BIT( TCCR1A , WGM13 );
						break;
					}
					case GPT_u8T1WGM_CTC_ICR:
					{
						CLR_BIT( TCCR1A , WGM10 );
						CLR_BIT( TCCR1A , WGM11 );
						SET_BIT( TCCR1A , WGM12 );
						SET_BIT( TCCR1A , WGM13 );
						break;
					}
				}
				break;
			}
			case Timer2:
			{
				Clock_Prescaler = Add_pstrConfig -> T2 -> CS;

				Loc_u16Reg = TCCR0 | GPT_u16T02WGM_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T2 -> WGM | ~GPT_u16T02WGM_MASK );
				TCCR2 = Loc_u16Reg;

				Loc_u16Reg = TCCR0 | GPT_u16T02COM_MASK ;
				Loc_u16Reg &= ( Add_pstrConfig -> T2 -> COM | ~GPT_u16T02COM_MASK );
				TCCR2 = Loc_u16Reg;

				Loc_u16Reg = TIMSK;
				Loc_u16Reg |= Add_pstrConfig -> T2 -> ModeOfOPeration;
				TIMSK = Loc_u16Reg;

				OCR2 = Add_pstrConfig -> T2 -> OCR;
				break;
			}


		}
	}
	return Loc_enuErrorStatus;
}
Gpt_tenuErrorStatus Gpt_enuGetTimeElapsed( Gpt_ChannelType Copy_enuChannel , pu16 Add_pu16Time )
{
	Gpt_tenuErrorStatus Loc_enuErrorStatus = GptOk;
	if( Copy_enuChannel > Timer2)
	{
		Loc_enuErrorStatus = GptNok;
	}
	else if (Add_pu16Time == NULL)
	{
		Loc_enuErrorStatus = GptNok;
	}
	else
	{
		switch(Copy_enuChannel)
		{
			case Timer0:
			{
				*Add_pu16Time = TCNT0 - PreloadValue;
				break;
			}
			case Timer1:
			{
				*Add_pu16Time = TCNT1 - PreloadValue;
				break;
			}
			case Timer2:
			{
				*Add_pu16Time = TCNT2 - PreloadValue;
				break;
			}
		}
	}
	return Loc_enuErrorStatus;
}
Gpt_tenuErrorStatus Gpt_enuStartTimer( Gpt_ChannelType Copy_enuChannel , u16 Copy_u16Preload )
{
	Gpt_tenuErrorStatus Loc_enuErrorStatus = GptOk;
	u16 Loc_u16Reg;
	if(Copy_enuChannel>Timer2)
	{
		Loc_enuErrorStatus = GptNok;
	}
	else
	{
		PreloadValue = Copy_u16Preload;
		switch(Copy_enuChannel)
		{
			case Timer0:
			{
				TCNT0 = Copy_u16Preload;

				Loc_u16Reg = TCCR0 | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( Clock_Prescaler | ~GPT_u16CLK_MASK );
				TCCR0 = Loc_u16Reg;
				break;
			}
			case Timer1:
			{
				TCNT1 = Copy_u16Preload;

				Loc_u16Reg = TCCR1B | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( Clock_Prescaler | ~GPT_u16CLK_MASK );
				TCCR1B = Loc_u16Reg;
				break;
			}
			case Timer2:
			{
				TCNT2 = Copy_u16Preload;

				Loc_u16Reg = TCCR2 | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( Clock_Prescaler | ~GPT_u16CLK_MASK );
				TCCR2 = Loc_u16Reg;
				break;
			}
		}
	}
	return Loc_enuErrorStatus;
}
Gpt_tenuErrorStatus Gpt_enuStopTimer( Gpt_ChannelType Copy_enuChannel )
{
	Gpt_tenuErrorStatus Loc_enuErrorStatus = GptOk;
	u16 Loc_u16Reg;
	if(Copy_enuChannel>Timer2)
	{
		Loc_enuErrorStatus = GptNok;
	}
	else
	{
		switch(Copy_enuChannel)
		{
			case Timer0:
			{
				Loc_u16Reg = TCCR0 | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( GPT_u8_CS_T01NO_CLK_SRC | ~GPT_u16CLK_MASK );
				TCCR0 = Loc_u16Reg;
				break;
			}
			case Timer1:
			{
				Loc_u16Reg = TCCR1B | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( GPT_u8_CS_T01NO_CLK_SRC | ~GPT_u16CLK_MASK );
				TCCR1B = Loc_u16Reg;
				break;
			}
			case Timer2:
			{
				Loc_u16Reg = TCCR2 | GPT_u16CLK_MASK ;
				Loc_u16Reg &= ( GPT_u8_CS_T2NO_CLK_SRC | ~GPT_u16CLK_MASK );
				TCCR2 = Loc_u16Reg;
				break;
			}
		}
	}
	return Loc_enuErrorStatus;
}

Gpt_tenuErrorStatus Gpt_enuT0OverflowRegiserCbf(cbf_t Add_Cbf)
{
	Gpt_tenuErrorStatus Loc_enuError = GptOk;
	if(Add_Cbf)
	{
		T0_OverflowCbf = Add_Cbf;
	}
	else
	{
		Loc_enuError = GptNok;
	}
	return Loc_enuError;
}

void __vector_11 (void) __attribute__((signal,used));
void __vector_11 (void)
{
	if(T0_OverflowCbf)
		T0_OverflowCbf();

	TCNT0 = PreloadValue;
}

