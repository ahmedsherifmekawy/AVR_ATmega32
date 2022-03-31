/*
 * Dio.c
 *
 *  Created on: Mar 10, 2022
 *      Author: WINDOWS
 */

#include <avr/io.h>
#include "Dio.h"
#include "Bit_utils.h"

Dio_tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8ChannelLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOK;
	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	if( Copy_u8ChannelId >= DIO_u8NUMBER_OF_PINS )
	{
		Loc_enuReturnStatus = DioChannelIdError;
	}
	else if( ( Copy_u8ChannelLevel != DIO_u8LEVEL_ZERO ) && ( Copy_u8ChannelLevel != DIO_u8LEVEL_ONE ) )
	{
		Loc_enuReturnStatus = DioLevelError;
	}
	else
	{
		Loc_u8Port = Copy_u8ChannelId / 8 ;
		Loc_u8Pin = Copy_u8ChannelId % 8 ;

		switch(Loc_u8Port)
		{
			case DIO_u8PORT_A:
			{
				if(Copy_u8ChannelLevel == DIO_u8LEVEL_ONE)
				{
					SET_BIT(PORTA,Loc_u8Pin);
				}

				else
				{
					CLR_BIT(PORTA,Loc_u8Pin);
				}
				break;
			}

			case DIO_u8PORT_B:
			{
				if(Copy_u8ChannelLevel == DIO_u8LEVEL_ONE)
				{
					SET_BIT(PORTB,Loc_u8Pin);
				}

				else
				{
					CLR_BIT(PORTB,Loc_u8Pin);
				}
				break;
			}

			case DIO_u8PORT_C:
			{
				if(Copy_u8ChannelLevel == DIO_u8LEVEL_ONE)
				{
					SET_BIT(PORTC,Loc_u8Pin);
				}

				else
				{
					CLR_BIT(PORTC,Loc_u8Pin);
				}
				break;
			}

			case DIO_u8PORT_D:
			{
				if(Copy_u8ChannelLevel == DIO_u8LEVEL_ONE)
				{
					SET_BIT(PORTD,Loc_u8Pin);
				}

				else
				{
					CLR_BIT(PORTD,Loc_u8Pin);
				}
				break;
			}
		}
	}
	return Loc_enuReturnStatus;
}
Dio_tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId, pu8 Copy_pu8ChannelLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOK;

	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	if(  Copy_u8ChannelId >= DIO_u8NUMBER_OF_PINS )
	{
		Loc_enuReturnStatus = DioChannelIdError;
	}

	else
	{
		Loc_u8Port = Copy_u8ChannelId / 8 ;
		Loc_u8Pin = Copy_u8ChannelId % 8 ;

		switch(Loc_u8Port)
		{
			case DIO_u8PORT_A:
			{
				*Copy_pu8ChannelLevel = GET_BIT(PINA,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_B:
			{
				*Copy_pu8ChannelLevel = GET_BIT(PINB,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_C:
			{
				*Copy_pu8ChannelLevel = GET_BIT(PINC,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_D:
			{
				*Copy_pu8ChannelLevel = GET_BIT(PIND,Loc_u8Pin);
				break;
			}
		}
	}
	return Loc_enuReturnStatus;
}
Dio_tenuErrorStatus DIO_enuWritePort(u8 Copy_u8PortId, u8 Copy_uPortLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOK;


	if( Copy_u8PortId >= DIO_u8PORT_NUMBER )
	{
		Loc_enuReturnStatus = DioChannelIdError;
	}

	else
	{

		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A:
			{
				PORTA = Copy_uPortLevel ;
				break;
			}

			case DIO_u8PORT_B:
			{
				PORTB = Copy_uPortLevel ;
				break;
			}

			case DIO_u8PORT_C:
			{
				PORTC = Copy_uPortLevel ;
				break;
			}

			case DIO_u8PORT_D:
			{
				PORTD = Copy_uPortLevel ;
				break;
			}
		}
	}
	return Loc_enuReturnStatus;
}


Dio_tenuErrorStatus DIO_enuReadPort(u8 Copy_u8PortId, pu8 Copy_pu8PortLevel)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOK;


	if(  Copy_u8PortId >= DIO_u8PORT_NUMBER )
	{
		Loc_enuReturnStatus = DioChannelIdError;
	}

	else
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8PORT_A:
			{
				*Copy_pu8PortLevel = PINA;
				break;
			}

			case DIO_u8PORT_B:
			{
				*Copy_pu8PortLevel = PINB;
				break;
			}

			case DIO_u8PORT_C:
			{
				*Copy_pu8PortLevel = PINC;
				break;
			}

			case DIO_u8PORT_D:
			{
				*Copy_pu8PortLevel = PIND;
				break;
			}
		}
	}
	return Loc_enuReturnStatus;
}

Dio_tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId)
{
	Dio_tenuErrorStatus Loc_enuReturnStatus = Dio_enuOK;

	u8 Loc_u8Port;
	u8 Loc_u8Pin;

	if(  Copy_u8ChannelId >= DIO_u8NUMBER_OF_PINS  )
	{
		Loc_enuReturnStatus = DioChannelIdError;
	}

	else
	{
		Loc_u8Port = Copy_u8ChannelId / 8 ;
		Loc_u8Pin = Copy_u8ChannelId % 8 ;

		switch(Loc_u8Port)
		{
			case DIO_u8PORT_A:
			{
				TGL_BIT(PINA,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_B:
			{
				TGL_BIT(PINB,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_C:
			{
				TGL_BIT(PINC,Loc_u8Pin);
				break;
			}

			case DIO_u8PORT_D:
			{
				TGL_BIT(PIND,Loc_u8Pin);
				break;
			}
		}
	}

	return Loc_enuReturnStatus;
}
