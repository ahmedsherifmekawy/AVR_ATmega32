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
	Lcd_vidInit();

	char a[4][8]={

	  {
	    0b00000 ,
		0b00000 ,
		0b10000 ,
		0b01000 ,
		0b00100 ,                                    // right up
		0b00010 ,
		0b11111 ,
		0b00000
	  } ,

	  {
	    0b00000 ,
	    0b00000 ,
	    0b00001 ,
	    0b00010 ,                                 //  left up
	    0b00100 ,
	    0b01000 ,
	    0b11111 ,
	    0b00000
	  } ,

	  {
	    0b10000 ,
	    0b01000 ,
	    0b00100 ,                                   // right down
	    0b00010 ,
	    0b00000 ,
	    0b00000 ,
	    0b00000 ,
	    0b00000
	  } ,

	  {
	    0b00001 ,
	    0b00010 ,                                  // left down
	    0b00100 ,
	    0b01000 ,
	    0b00000 ,
	    0b00000 ,
	    0b00000 ,
	    0b00000
	  } ,



	};


	char A [8][8] =
	{

			 {
			   0b10000 ,
			   0b01000 ,
			   0b00100 ,               // right 1 up
			   0b00010 ,
			   0b00001 ,
			   0b00000 ,
			   0b11111 ,
			   0b00000
			 } ,

			 {
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,              // right 2 up
			   0b00000 ,
			   0b10000 ,
			   0b11000 ,
			   0b00000
			 } ,

			 {
			   0b00001 ,
			   0b00010 ,
			   0b00100 ,                  // left 1 up
			   0b01000 ,
			   0b10000 ,
			   0b00000 ,
			   0b11111 ,
			   0b00000
			 } ,

			 {
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,                   // left 2 up
			   0b00000 ,
			   0b00001 ,
			   0b00011 ,
			   0b00000
			 } ,


			 {
			   0b10000 ,
			   0b01000 ,
			   0b00100 ,
			   0b00010 ,                 // right down
			   0b00001 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000
			 } ,


			 {
			   0b00001 ,
			   0b00010 ,
			   0b00100 ,
			   0b01000 ,              // left down
			   0b10000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000
			 } ,

			 {
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000
			 } ,

			 {
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000 ,
			   0b00000
			 }

	};

	u8 i , k;


	while(1)
	{
		Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

		Lcd_vidCreateCustomCharacter(a[0],LCD_u8CGRAM_ADDRESS_1);
		Lcd_vidCreateCustomCharacter(a[1],LCD_u8CGRAM_ADDRESS_2);
		Lcd_vidCreateCustomCharacter(a[2],LCD_u8CGRAM_ADDRESS_3);
		Lcd_vidCreateCustomCharacter(a[3],LCD_u8CGRAM_ADDRESS_4);

		Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

		Lcd_vidGoTo( LCD_u8ROW_1 , 8);
		Lcd_vidDisplayCharacter(0);
		Lcd_vidGoTo( LCD_u8ROW_1 , 7);
		Lcd_vidDisplayCharacter(1);

		Lcd_vidGoTo( LCD_u8ROW_2 , 9);
		Lcd_vidDisplayCharacter(2);
		Lcd_vidGoTo( LCD_u8ROW_2 , 6);
		Lcd_vidDisplayCharacter(3);


		_delay_ms(20);

		Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

		Lcd_vidCreateCustomCharacter(A[0],LCD_u8CGRAM_ADDRESS_1);
		Lcd_vidCreateCustomCharacter(A[1],LCD_u8CGRAM_ADDRESS_2);
		Lcd_vidCreateCustomCharacter(A[2],LCD_u8CGRAM_ADDRESS_3);
		Lcd_vidCreateCustomCharacter(A[3],LCD_u8CGRAM_ADDRESS_4);
		Lcd_vidCreateCustomCharacter(A[4],LCD_u8CGRAM_ADDRESS_5);
		Lcd_vidCreateCustomCharacter(A[5],LCD_u8CGRAM_ADDRESS_6);

		Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);

		Lcd_vidGoTo( LCD_u8ROW_1 , 8);
		Lcd_vidDisplayCharacter(0);
		Lcd_vidGoTo( LCD_u8ROW_1 , 9);
		Lcd_vidDisplayCharacter(1);

		Lcd_vidGoTo( LCD_u8ROW_1 , 7);
		Lcd_vidDisplayCharacter(2);
		Lcd_vidGoTo( LCD_u8ROW_1 , 6);
		Lcd_vidDisplayCharacter(3);

		Lcd_vidGoTo( LCD_u8ROW_2 , 10);
		Lcd_vidDisplayCharacter(4);
		Lcd_vidGoTo( LCD_u8ROW_2 , 5);
		Lcd_vidDisplayCharacter(5);


		_delay_ms(10);
	}
	return 0;
}
