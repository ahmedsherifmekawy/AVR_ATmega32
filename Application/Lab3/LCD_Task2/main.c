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

	char  n1[] ="A M D"; char n2[] =" H E ";
	u8 r = LCD_u8ROW_1 , r2 = LCD_u8ROW_2 ;
	s8 c;

	Lcd_vidInit();

	while(1)
	{

		for( c= -4 ; c < 12 ;c++ )
		{
			if(c%2 == 0)
			{
				Lcd_vidGoTo( r , c);
				Lcd_vidDisplayString(n1);
				Lcd_vidGoTo( r2 , c);
				Lcd_vidDisplayString(n2);
			}
			else
			{
				Lcd_vidGoTo( r2 , c);
				Lcd_vidDisplayString(n1);
				Lcd_vidGoTo( r , c);
				Lcd_vidDisplayString(n2);
			}

			_delay_ms(10);
			Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);
		}

		for( c= 11 ; c >= 0 ;c-- )
		{
			if(c%2 == 0)
			{
				Lcd_vidGoTo( r , c);
				Lcd_vidDisplayString(n1);
				Lcd_vidGoTo( r2 , c);
				Lcd_vidDisplayString(n2);
			}
			else
			{
				Lcd_vidGoTo( r2 , c);
				Lcd_vidDisplayString(n1);
				Lcd_vidGoTo( r , c);
				Lcd_vidDisplayString(n2);
			}

			_delay_ms(10);
			Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);
		}

	}
	return 0;
}
