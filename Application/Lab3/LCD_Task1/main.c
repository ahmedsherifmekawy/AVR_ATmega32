/*
 * main.c
 *
 *  Created on: Mar 17, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Lcd.h"

#include <util/delay.h>

int main(void)
{
	u8 r = LCD_u8ROW_1 , c ;
	Lcd_vidInit();
	while(1)
	{

		for( c = LCD_u8COL_1 ; c <= LCD_u8COL_16 ; c++ )
		{
			Lcd_vidGoTo( r , c );

			Lcd_vidDisplayCharacter('X');
			_delay_ms(10);
			Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

		}

		if( r == LCD_u8ROW_1 )
			r = LCD_u8ROW_2;
		else
			r = LCD_u8ROW_1;


	}
	return 0;
}
