/*
 * Lcd.c
 *
 *  Created on: Mar 16, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Dio.h"
#include "Lcd.h"
#include "Lcd_cfg.h"
#include "util/delay.h"
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
void Lcd_vidInit()
{
	_delay_ms(50);
	Lcd_vidSendCommand( LCD_u8EIGHT_BIT_MODE | LCD_u8TWO_LINE_DISPLAY );
	_delay_ms(1);
	Lcd_vidSendCommand( LCD_u8DISPLAY_ON | LCD_u8CURSOR_ON | LCD_u8CURSOR_BLINK_ON );
	_delay_ms(1);
	Lcd_vidSendCommand( LCD_u8CLEAR_DISPLAY );
	_delay_ms(2);
	Lcd_vidSendCommand( LCD_u8CURSOR_LEFT_TO_RIGHT );
}

void Lcd_vidSendCommand( u8 Copy_u8Command )
{
	DIO_enuWritePort( LCD_u8PORT_WRITE , Copy_u8Command );
	DIO_enuWriteChannel( LCD_u8RW , LCD_u8RW_WRITE );
	DIO_enuWriteChannel( LCD_u8RS , LCD_u8RS_COMMAND );
	DIO_enuWriteChannel( LCD_u8ENABLE , LCD_u8ENABLE_HIGH );
	_delay_ms(2);
	DIO_enuWriteChannel( LCD_u8ENABLE , LCD_u8ENABLE_LOW );
	_delay_ms(2);
}
void Lcd_vidDisplayCharacter( u8 Copy_u8Character )
{
	DIO_enuWritePort( LCD_u8PORT_WRITE , Copy_u8Character );
	DIO_enuWriteChannel( LCD_u8RW , LCD_u8RW_WRITE );
	DIO_enuWriteChannel( LCD_u8RS , LCD_u8RS_DATA );
	DIO_enuWriteChannel( LCD_u8ENABLE , LCD_u8ENABLE_HIGH );
	_delay_ms(2);
	DIO_enuWriteChannel( LCD_u8ENABLE , LCD_u8ENABLE_LOW );
	_delay_ms(2);
}

void Lcd_vidCreateCustomCharacter( pu8 Add_pu8CustomCharacter , u8 Copy_u8CgramAddress )
{
	u8 index;

	Lcd_vidSendCommand( Copy_u8CgramAddress );

	for(index = INDEX_ZERO ; index < INDEX_EIGHT; index ++)
	{
		Lcd_vidDisplayCharacter( *Add_pu8CustomCharacter );
		Add_pu8CustomCharacter++;
	}
}

void Lcd_vidDisplayNumber( s32 Copy_s32Number )
{
	u32 length = snprintf( LCD_u8ZERO , LCD_u8ZERO , "%ld", Copy_s32Number );
	pu8 str = malloc( length + LCD_u8ONE );
	snprintf( str , length + LCD_u8ONE, "%ld", Copy_s32Number );

	Lcd_vidDisplayString( str );
}

void Lcd_vidGoTo( u8 Copy_u8Row , u8 Copy_u8Col )
{
	Lcd_vidSendCommand( Copy_u8Row + Copy_u8Col - LCD_u8ONE );
	_delay_ms(1);
}


void Lcd_vidDisplayString( pu8 Add_pu8String )
{
	while( *Add_pu8String != ENDING_CHAR )
	{
		Lcd_vidDisplayCharacter( *Add_pu8String );
		Add_pu8String++;
	}
}
