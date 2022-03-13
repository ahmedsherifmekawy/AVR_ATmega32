/*
 * Port.c
 *
 *  Created on: Mar 10, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Bit_utils.h"
#include <avr/io.h>
#include "Port.h"

Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum,u8 Copy_u8PinDirection)
{
	Port_tenuErrorStatus Loc_enuReturnStatus=Port_enuOk;
	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	if( Copy_u8PinNum >= PORT_u8NUMBER_OF_PINS )
	{
		Loc_enuReturnStatus=Port_enuPinError;
	}
	else if( (Copy_u8PinDirection != PORT_u8PIN_INPUT) && (Copy_u8PinDirection != PORT_u8PIN_OUTPUT) )
	{
		Loc_enuReturnStatus=Port_enuDirectionError;
	}
	else
	{
		Loc_u8Port = Copy_u8PinNum / 8 ;
		Loc_u8Pin = Copy_u8PinNum % 8 ;

		switch(Loc_u8Port)
		{
			case PORT_u8PORT_A:
			{
				if(Copy_u8PinDirection == PORT_u8PIN_OUTPUT)
				{
					SET_BIT(DDRA,Loc_u8Pin);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8Pin);
				}
				break;
			}
			case PORT_u8PORT_B:
					{
						if(Copy_u8PinDirection == PORT_u8PIN_OUTPUT)
						{
							SET_BIT(DDRB,Loc_u8Pin);
						}
						else
						{
							CLR_BIT(DDRB,Loc_u8Pin);
						}
						break;
					}
			case PORT_u8PORT_C:
					{
						if(Copy_u8PinDirection == PORT_u8PIN_OUTPUT)
						{
							SET_BIT(DDRC,Loc_u8Pin);
						}
						else
						{
							CLR_BIT(DDRC,Loc_u8Pin);
						}
						break;
					}
			case PORT_u8PORT_D:
					{
						if(Copy_u8PinDirection == PORT_u8PIN_OUTPUT)
						{
							SET_BIT(DDRD,Loc_u8Pin);
						}
						else
						{
							CLR_BIT(DDRD,Loc_u8Pin);
						}
						break;
					}
		}
	}


	return Loc_enuReturnStatus;
}


Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode)
{
	Port_tenuErrorStatus Loc_enuReturnStatus=Port_enuOk;
		u8 Loc_u8Port;
		u8 Loc_u8Pin;
		if( Copy_u8PinNum >= PORT_u8NUMBER_OF_PINS )
		{
			Loc_enuReturnStatus=Port_enuPinError;
		}
		else if( ( Copy_u8PinMode!= PORT_u8INPUT_HIGHIMPEDANCE ) && ( Copy_u8PinMode!= PORT_u8INPUT_PULLUP ) && ( Copy_u8PinMode!= PORT_u8OUTPUT_HIGH ) )
		{
			Loc_enuReturnStatus=Port_enuModeError;
		}
		else
		{
			Loc_u8Port = Copy_u8PinNum / 8 ;
			Loc_u8Pin = Copy_u8PinNum % 8 ;

			switch(Loc_u8Port)
			{
				case PORT_u8PORT_A:
				{
					switch(Copy_u8PinMode)
					{
						case PORT_u8INPUT_HIGHIMPEDANCE:
						{
							CLR_BIT(DDRA,Loc_u8Pin);
							CLR_BIT(PORTA,Loc_u8Pin);
							break;
						}
						case PORT_u8INPUT_PULLUP:
						{
							CLR_BIT(DDRA,Loc_u8Pin);
							SET_BIT(PORTA,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_HIGH:
						{
							SET_BIT(DDRA,Loc_u8Pin);
							SET_BIT(PORTA,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_LOW:
						{
							CLR_BIT(DDRA,Loc_u8Pin);
							CLR_BIT(PORTA,Loc_u8Pin);
							break;
						}
					}
					break;
				}
				case PORT_u8PORT_B:
				{
					switch(Copy_u8PinMode)
					{
						case PORT_u8INPUT_HIGHIMPEDANCE:
						{
							CLR_BIT(DDRB,Loc_u8Pin);
							CLR_BIT(PORTB,Loc_u8Pin);
							break;
						}
						case PORT_u8INPUT_PULLUP:
						{
							CLR_BIT(DDRB,Loc_u8Pin);
							SET_BIT(PORTB,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_HIGH:
						{
							SET_BIT(DDRB,Loc_u8Pin);
							SET_BIT(PORTB,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_LOW:
						{
							CLR_BIT(DDRB,Loc_u8Pin);
							CLR_BIT(PORTB,Loc_u8Pin);
							break;
						}
					}
					break;
				}
				case PORT_u8PORT_C:
				{
					switch(Copy_u8PinMode)
					{
						case PORT_u8INPUT_HIGHIMPEDANCE:
						{
							CLR_BIT(DDRC,Loc_u8Pin);
							CLR_BIT(PORTC,Loc_u8Pin);
							break;
						}
						case PORT_u8INPUT_PULLUP:
						{
							CLR_BIT(DDRC,Loc_u8Pin);
							SET_BIT(PORTC,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_HIGH:
						{
							SET_BIT(DDRC,Loc_u8Pin);
							SET_BIT(PORTC,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_LOW:
						{
							CLR_BIT(DDRC,Loc_u8Pin);
							CLR_BIT(PORTC,Loc_u8Pin);
							break;
						}
					}
					break;
				}
				case PORT_u8PORT_D:
				{
					switch(Copy_u8PinMode)
					{
						case PORT_u8INPUT_HIGHIMPEDANCE:
						{
							CLR_BIT(DDRD,Loc_u8Pin);
							CLR_BIT(PORTD,Loc_u8Pin);
							break;
						}
						case PORT_u8INPUT_PULLUP:
						{
							CLR_BIT(DDRD,Loc_u8Pin);
							SET_BIT(PORTD,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_HIGH:
						{
							SET_BIT(DDRD,Loc_u8Pin);
							SET_BIT(PORTD,Loc_u8Pin);
							break;
						}
						case PORT_u8OUTPUT_LOW:
						{
							CLR_BIT(DDRD,Loc_u8Pin);
							CLR_BIT(PORTD,Loc_u8Pin);
							break;
						}
					}
					break;
				}
			}
		}
		return Loc_enuReturnStatus;
}
