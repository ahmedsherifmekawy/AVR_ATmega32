/*
 * Scenes.c
 *
 *  Created on: Mar 17, 2022
 *      Author: WINDOWS
 */

#include "Std_types.h"
#include "Lcd.h"
#include "Lcd_cfg.h"

#include "Scenes.h"
#include <util/delay.h>

void Scene_one()
{
	u8 r = LCD_u8ROW_1 , c , i ;


	Lcd_vidGoTo( LCD_u8ROW_1 , 0);
	Lcd_vidDisplayString("______________________");

	Lcd_vidGoTo( LCD_u8ROW_2 , 0);
	Lcd_vidDisplayString("______________________");

	for (i=0;i<2;i++)
	{
		for( c = LCD_u8COL_1 ; c <= LCD_u8COL_16 ; c++ )
		{
			Lcd_vidGoTo( r , c );
			Lcd_vidDisplayCharacter(0);
			_delay_ms(10);

			Lcd_vidGoTo( r , c);
			Lcd_vidDisplayCharacter('_');
	    }
		r = LCD_u8ROW_2;
	}


}
void Scene_two()
{
	u8 r = LCD_u8ROW_1 , c , i ;


	Lcd_vidGoTo( LCD_u8ROW_1 , 0);
	Lcd_vidDisplayString("________ _____________");

	Lcd_vidGoTo( LCD_u8ROW_2 , 0);
	Lcd_vidDisplayString("______________________");


		for( c = LCD_u8COL_1 ; c < LCD_u8COL_9 ; c++ )
		{
			Lcd_vidGoTo( r , c );
			Lcd_vidDisplayCharacter(0);
			_delay_ms(10);

			Lcd_vidGoTo( r , c);
			Lcd_vidDisplayCharacter('_');
	    }
		r = LCD_u8ROW_2;

		for( c = LCD_u8COL_9 ; c <= LCD_u8COL_16 ; c++ )
		{
			Lcd_vidGoTo( r , c );
			Lcd_vidDisplayCharacter(0);
			_delay_ms(10);

			Lcd_vidGoTo( r , c);
			Lcd_vidDisplayCharacter('_');
		}

}

void Scene_three()
{
	u8 r = LCD_u8ROW_1 , c , i ;


	Lcd_vidGoTo( LCD_u8ROW_1 , 0);
	Lcd_vidDisplayString("______________________");

	Lcd_vidGoTo( LCD_u8ROW_2 , 0);
	Lcd_vidDisplayString("______________________");

	for( c = LCD_u8COL_1 ; c <= LCD_u8COL_16 ; c++ )
	{
		Lcd_vidGoTo( r , c );
		Lcd_vidDisplayCharacter(0);
		_delay_ms(10);

		Lcd_vidGoTo( r , c);
		Lcd_vidDisplayCharacter('_');
	}

	Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

	r = LCD_u8ROW_2;
	Lcd_vidGoTo( LCD_u8ROW_1 , 0);
	Lcd_vidDisplayString("________ ___|_________");

	Lcd_vidGoTo( LCD_u8ROW_2 , 0);
	Lcd_vidDisplayString("________/_____________");


	for( c = LCD_u8COL_1 ; c < LCD_u8COL_9 ; c++ )
	{
		Lcd_vidGoTo( r , c );
		Lcd_vidDisplayCharacter(0);
		_delay_ms(10);

		Lcd_vidGoTo( r , c);
		Lcd_vidDisplayCharacter('_');
	}

	r = LCD_u8ROW_1;

	Lcd_vidGoTo( LCD_u8ROW_2 , LCD_u8COL_9 );
	Lcd_vidDisplayCharacter(2);
	Lcd_vidGoTo( LCD_u8ROW_1 , LCD_u8COL_9 );
	Lcd_vidDisplayCharacter(3);

	_delay_ms(10);


	Lcd_vidGoTo( LCD_u8ROW_2 , LCD_u8COL_9 );
	Lcd_vidDisplayCharacter('/');
	Lcd_vidGoTo( LCD_u8ROW_1 , LCD_u8COL_9 );
	Lcd_vidDisplayCharacter(' ');


	for( c = LCD_u8COL_10 ; c < LCD_u8COL_13 ; c++ )
	{
		Lcd_vidGoTo( r , c );
		Lcd_vidDisplayCharacter(0);
		_delay_ms(10);

		Lcd_vidGoTo( r , c);
		Lcd_vidDisplayCharacter('_');
	}

}
void Scene_four()
{
	Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);
	Lcd_vidGoTo(LCD_u8ROW_2,4);
	Lcd_vidDisplayString("ops ;( ");
}

