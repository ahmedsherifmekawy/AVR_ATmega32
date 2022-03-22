/*
 * main.c
 *
 *  Created on: Mar 22, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Keypad.h"
#include "Keypad_cfg.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "Port.h"
#include "Dio.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	u8 x;
	u16 op1 , op2;
	s16 res;
	u8 opFlag = 0;
	u8 counter = 0;
	u8 a[6];
	Keypad_tenuErrorStatus y = KeypadNok;
	Lcd_vidInit();

	Port_enuSetPinDirection( KEYPAD_u8PIN_1 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( KEYPAD_u8PIN_2 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( KEYPAD_u8PIN_3 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( KEYPAD_u8PIN_4 , PORT_u8PIN_OUTPUT );

	Port_enuSetPinMode( KEYPAD_u8PIN_5 , PORT_u8INPUT_PULLUP );
	Port_enuSetPinMode( KEYPAD_u8PIN_6 , PORT_u8INPUT_PULLUP );
	Port_enuSetPinMode( KEYPAD_u8PIN_7 , PORT_u8INPUT_PULLUP );
	Port_enuSetPinMode( KEYPAD_u8PIN_8 , PORT_u8INPUT_PULLUP );

	while(1)
	{
		y = Keypad_enuGetKey(&x);
		if( y == KeypadOk )
		{
			if(counter == 0)
			{
				while(!(x >='0' && x<='9') )
				{
					Keypad_enuGetKey(&x);
					_delay_ms(10);
				}

			}
			else if(counter == 1)
			{
				while(x=='=' || x==' ')
				{
					Keypad_enuGetKey(&x);
					_delay_ms(10);
				}
				if(!(x >='0' && x<='9'))
				{
					opFlag=1;
				}
			}
			else if(counter == 2)
			{
				if(opFlag == 0)
				{
					while((x >='0' && x<='9')||x==' ')
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}
				}
				else
				{
					while(!(x >='0' && x<='9'))
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}

				}

			}
			else if(counter == 3)
			{
				if(opFlag == 0)
				{
					while(!(x >='0' && x<='9') )
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}
				}
				else
				{
					while(!(x >='0' && x<='9') && x!='=' )
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}
				}

			}
			else if(counter == 4)
			{
				if(opFlag == 0)
				{
					while(!(x >='0' && x<='9') && x!='=' )
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}
				}
				else
				{
					while(x!='=')
					{
						Keypad_enuGetKey(&x);
						_delay_ms(10);
					}
				}


			}
			else if(counter == 5)
			{
				while(x!='=')
				{
					Keypad_enuGetKey(&x);
					_delay_ms(10);
				}
			}
			Lcd_vidDisplayCharacter(x);
			a[counter++] = x;
			if(x=='=')
				break;
		}
		_delay_ms(10);
	}
	a[counter] = x;
	counter = 0;

	if(opFlag == 1)
	{
		op1=a[0]-48;
		opFlag=a[1];
		if(a[3]=='=')
		{
			op2 = a[2]-48;
		}
		else
		{
			op2 = (a[2]-48)*10 + (a[3]-48);
		}
	}
	else
	{
		op1=(a[0]-48)*10 + (a[1]-48);
		opFlag=a[2];
		if(a[4]=='=')
		{
			op2 = a[3]-48;
		}
		else
		{
			op2 = (a[3]-48)*10 + (a[4]-48);
		}
	}

	switch(opFlag)
	{
		case '+':
		{
			res=op1+op2;
			break;
		}
		case '-':
		{
			res=op1-op2;
			break;
		}
		case '*':
		{
			res=op1*op2;
			break;
		}
		case '/':
		{
			if(op2 == 0)
				opFlag=1;
			else
				res=op1/op2;
			break;
		}
	}

	Lcd_vidGoTo(LCD_u8ROW_2,LCD_u8COL_8);

	if(opFlag != 1)
		Lcd_vidDisplayNumber(res);
	else
		Lcd_vidDisplayString("error");


	//Lcd_vidDisplayString(a);

	return 0;
}
