/*
 * main.c
 *
 *  Created on: Apr 7, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Port.h"
#include "Adc.h"
#include "Dio.h"
#include "Lcd.h"
#include "Lcd_cfg.h"
#include <util/delay.h>

#define MAX     8

int power(int base, int exponent)
{
	int result=1;
	for (exponent; exponent>0; exponent--)
	{
		result = result * base;
	}
	return result;
}

void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * power(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}




int main(void)
{
	u16 Loc_u16Reading = 0 ;
	u16 temp;
	f128 fReading;
	u8 buf[MAX];
	u8 flag=0;
	u8 lastFlag=1;
	u8 readSwitch = 1 ;

	Port_enuSetPinDirection( LCD_u8DATA_PIN_0 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_1 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_2 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_3 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_4 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_5 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_6 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8DATA_PIN_7 , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8RW , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8RS , PORT_u8PIN_OUTPUT );
	Port_enuSetPinDirection( LCD_u8ENABLE , PORT_u8PIN_OUTPUT );

	Port_enuSetPinDirection(PORT_u8PIN_0,PORT_u8PIN_INPUT);

	Port_enuSetPinMode( PORT_u8PIN_1 , PORT_u8INPUT_PULLUP );

	Adc_vidInit();
	Lcd_vidInit();


	Lcd_vidSendCommand(LCD_u8CLEAR_DISPLAY);
	Lcd_vidDisplayString("Voltage=");

	while(1)
	{

		DIO_enuReadChannel( DIO_u8PIN_1 , &readSwitch );
		_delay_ms(10);

		if(readSwitch == 0)
		{
			if(flag == 1)
				flag=0;
			else
				flag=1;
		}

		Adc_enuGetReading( &Loc_u16Reading );
		Loc_u16Reading *= (5000 / 1024);
		fReading = ( f128 )  Loc_u16Reading / 1000.0 ;
		ftoa(fReading, buf, 4);

		if(flag == 0 && lastFlag == 1)
		{
			Lcd_vidGoTo(LCD_u8ROW_2 , LCD_u8COL_13 );
			Lcd_vidDisplayString("          ");

			Lcd_vidGoTo(LCD_u8ROW_2 , LCD_u8COL_13 );
			Lcd_vidDisplayString("Volt");
		}
		else if(flag == 1 && lastFlag == 0)
		{
			Lcd_vidGoTo(LCD_u8ROW_2 , LCD_u8COL_13 );
			Lcd_vidDisplayString("          ");

			Lcd_vidGoTo(LCD_u8ROW_2 , LCD_u8COL_13 );
			Lcd_vidDisplayString("mV");
		}

		if(Loc_u16Reading != temp || flag != lastFlag )
		{
			Lcd_vidGoTo(LCD_u8ROW_1 , LCD_u8COL_9 );
			Lcd_vidDisplayString("          ");

			Lcd_vidGoTo(LCD_u8ROW_1 , LCD_u8COL_9 );

			if(flag == 0)
				Lcd_vidDisplayNumber(Loc_u16Reading);
			else
				Lcd_vidDisplayString(buf);
		}

		temp = Loc_u16Reading;
		lastFlag = flag ;
		_delay_ms(10);


	}

	return 0;
}
