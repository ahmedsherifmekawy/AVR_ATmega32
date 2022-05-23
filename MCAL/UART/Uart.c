/*
 * Uart.c
 *
 *  Created on: Apr 29, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "avr/io.h"
#include "Uart.h"
#include "Uart_prv.h"


u8 CharSize;
Uart_tenuErrorStatus Uart_enuInit(Uart_tstrCfg * Add_pstrUartCfg)
{
	Uart_tenuErrorStatus Loc_enuError = UartOk;
	u8 Loc_u8Reg;
	u16 Loc_u16Baudrate;
	if( Add_pstrUartCfg == NULL )
	{
		Loc_enuError = UartNok;
	}
	else
	{
		Loc_u16Baudrate = ( 16000000 / ( 16*Add_pstrUartCfg -> BaudRate ) ) - 1 ;
		UBRRH = ( ( Loc_u16Baudrate ) >> UART_u8UBRR_SHIFT );
		UBRRL = Loc_u16Baudrate;

		Loc_u8Reg = UCSRC;
		Loc_u8Reg &= ~UART_u8MODE_SYNC_MSK;
		Loc_u8Reg |=( Add_pstrUartCfg -> Mode & UART_u8MODE_SYNC_MSK );

		Loc_u8Reg &= ~UART_u8PARITY_MSK;
		Loc_u8Reg |=(Add_pstrUartCfg -> Parity & UART_u8PARITY_MSK );

		Loc_u8Reg &= ~UART_u8STOPBIT_MSK;
		Loc_u8Reg |=( Add_pstrUartCfg -> StopBit & UART_u8STOPBIT_MSK );

		Loc_u8Reg &= ~UART_u8CLK_POLARITY_MSK;
		Loc_u8Reg |=( Add_pstrUartCfg -> ClkPolarity & UART_u8CLK_POLARITY_MSK );

		SET_BIT(Loc_u8Reg,URSEL);
		UCSRC = Loc_u8Reg;
		CharSize = Add_pstrUartCfg -> CharacterSize;
		switch(Add_pstrUartCfg -> CharacterSize)
		{
			case UART_u8CHAR_SIZE_5:
			{
				CLR_BIT( UCSRC , UCSZ0 );
				CLR_BIT( UCSRC , UCSZ1 );
				CLR_BIT( UCSRB , UCSZ2) ;
				break;
			}
			case UART_u8CHAR_SIZE_6:
			{
				SET_BIT( UCSRC , UCSZ0 );
				CLR_BIT( UCSRC , UCSZ1 );
				CLR_BIT( UCSRB , UCSZ2) ;
				break;
			}
			case UART_u8CHAR_SIZE_7:
			{
				CLR_BIT( UCSRC , UCSZ0 );
				SET_BIT( UCSRC , UCSZ1 );
				CLR_BIT( UCSRB , UCSZ2) ;
				break;
			}
			case UART_u8CHAR_SIZE_8:
			{
				SET_BIT( UCSRC , UCSZ0 );
				SET_BIT( UCSRC , UCSZ1 );
				CLR_BIT( UCSRB , UCSZ2) ;
				break;
			}
			case UART_u8CHAR_SIZE_9:
			{
				SET_BIT( UCSRC , UCSZ0 );
				SET_BIT( UCSRC , UCSZ1 );
				SET_BIT( UCSRB , UCSZ2) ;
				break;
			}
		}
		Loc_u8Reg = UCSRA;
		Loc_u8Reg &= ~UART_u8DOUBLE_SPEED_MSK;
		Loc_u8Reg |=( Add_pstrUartCfg -> DoubleSpeed & UART_u8DOUBLE_SPEED_MSK );
		UCSRA = Loc_u8Reg;

		if( Add_pstrUartCfg -> Tx_Interrupt == UART_u8INT_EN )
		{
			SET_BIT( UCSRB , TXCIE );
		}
		else
		{
			CLR_BIT( UCSRB , TXCIE );
		}
		if( Add_pstrUartCfg -> Rx_Interrupt == UART_u8INT_EN )
		{
			SET_BIT( UCSRB , RXCIE );
		}
		else
		{
			CLR_BIT( UCSRB , RXCIE );
		}
		if( Add_pstrUartCfg -> DataRegEmpty_Interrupt == UART_u8INT_EN )
		{
			SET_BIT( UCSRB , UDRIE );
		}
		else
		{
			CLR_BIT( UCSRB , UDRIE );
		}
	}
	return Loc_enuError;
}
void Uart_enuSendByte(u16 Copy_u16Data)
{
	SET_BIT( UCSRB , TXEN );
	while( GET_BIT( UCSRA , UDRE ) == 0 );
	SET_BIT( UCSRA , TXC );
	if( CharSize == UART_u8CHAR_SIZE_9 )
	{
		if( GET_BIT( Copy_u16Data , 8) == 0 )
		{
			CLR_BIT(UCSRB , TXB8);
		}
		else
		{
			SET_BIT(UCSRB , TXB8);
		}
	}
	UDR = Copy_u16Data;
}
Uart_tenuErrorStatus Uart_enuRecieveByte(pu16 Add_pu16Data)
{
	Uart_tenuErrorStatus Loc_enuError = UartOk;

	if(Add_pu16Data == NULL)
	{
		Loc_enuError = UartNok;
	}
	else
	{
		SET_BIT( UCSRB , RXEN );
		while( GET_BIT( UCSRA , RXC ) == 0 );
		SET_BIT( UCSRA , RXC );
		*Add_pu16Data = UDR;
		if( CharSize == UART_u8CHAR_SIZE_9 )
		{
			if( GET_BIT( UCSRB , RXB8 ) == 0 )
			{
				CLR_BIT( (*Add_pu16Data) , 8 );
			}
			else
			{
				SET_BIT( (*Add_pu16Data) , 8 );
			}
		}
	}
	return Loc_enuError;
}
