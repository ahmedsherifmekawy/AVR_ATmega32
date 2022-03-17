/*
 * main.c
 *
 *  Created on: Mar 17, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Lcd.h"
#include "Scenes.h"
#include <util/delay.h>

int main(void)
{
	Lcd_vidInit();

	char a[8][8]={

	  {
	    0b00100  ,
		0b01110  ,
		0b00101  ,
		0b11111  ,             // on ground
		0b10100  ,
		0b01010  ,
		0b11111  ,
		0b00000
	  } ,

	  {
	    0b00100  ,
	    0b01110  ,
	    0b00101  ,           // on air
	    0b11111  ,
	    0b10100  ,
	    0b01010  ,
	    0b00000  ,
	    0b00000
	  } ,

	  {
	    0b11111  ,
	    0b10100  ,
	    0b01010  ,              // down half
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000
	  } ,

	  {
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,                // up half
	    0b00000  ,
	    0b00100  ,
	    0b01110  ,
	    0b00101  ,
	    0b00000
	  } ,

	  {
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000
	  } ,

	  {
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000
	  } ,

	  {
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000
	  } ,
	  {
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000  ,
	    0b00000
	  }



	};

	Lcd_vidInit();

	Lcd_vidCreateCustomCharacter(a[0],LCD_u8CGRAM_ADDRESS_1);
	Lcd_vidCreateCustomCharacter(a[1],LCD_u8CGRAM_ADDRESS_2);
	Lcd_vidCreateCustomCharacter(a[2],LCD_u8CGRAM_ADDRESS_3);
	Lcd_vidCreateCustomCharacter(a[3],LCD_u8CGRAM_ADDRESS_4);
	Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

	Scene_one();
	Scene_two();
	Scene_three();
	Scene_four();

	while(1)
	{

	}
	return 0;
}
