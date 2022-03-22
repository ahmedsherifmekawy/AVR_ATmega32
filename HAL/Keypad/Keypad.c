/*
 * Keypad.c
 *
 *  Created on: Mar 20, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Dio.h"
#include "Keypad.h"
#include "Keypad_cfg.h"

Keypad_tenuErrorStatus Keypad_enuGetKey(pu8 Add_pu8PressedKey)
{
	u8 Loc_u8KeypadCharacters [4][4] = {
			{'+','-','*','/'},
			{'3','6','9','='},
			{'2','5','8','0'},
			{'1','4','7',' '}
	};
	u8 Loc_u8iterator;
	Keypad_tenuErrorStatus Loc_enuErrorStatus = KeypadOk ;
	u8 Loc_u8temp;
	u8 Loc_u8checkCharacter = KEYPAD_ZERO ;
	u8 Loc_u8notPressedFlag = 1;

	if(Add_pu8PressedKey == NULL)
	{
		Loc_enuErrorStatus = KeypadNok ;
	}
	else
	{
		for( Loc_u8iterator = KEYPAD_ZERO ; Loc_u8iterator < KEYPAD_u8SIZE ; Loc_u8iterator ++ )
		{

			Loc_u8checkCharacter = KEYPAD_ZERO ;

			DIO_enuWriteChannel( KEYPAD_u8PIN_1 , DIO_u8LEVEL_ONE );
			DIO_enuWriteChannel( KEYPAD_u8PIN_2 , DIO_u8LEVEL_ONE );
			DIO_enuWriteChannel( KEYPAD_u8PIN_3 , DIO_u8LEVEL_ONE );
			DIO_enuWriteChannel( KEYPAD_u8PIN_4 , DIO_u8LEVEL_ONE );

		    DIO_enuWriteChannel( Loc_u8iterator + KEYPAD_u8PIN_1 , DIO_u8LEVEL_ZERO );


			DIO_enuReadChannel( KEYPAD_u8PIN_5 ,&Loc_u8temp);
			Loc_u8checkCharacter |= Loc_u8temp << 0;

			DIO_enuReadChannel( KEYPAD_u8PIN_6 ,&Loc_u8temp);
			Loc_u8checkCharacter |= Loc_u8temp << 1;

			DIO_enuReadChannel( KEYPAD_u8PIN_7 ,&Loc_u8temp);
			Loc_u8checkCharacter |= Loc_u8temp << 2;

			DIO_enuReadChannel( KEYPAD_u8PIN_8 ,&Loc_u8temp);
			Loc_u8checkCharacter |= Loc_u8temp << 3;


			switch( Loc_u8checkCharacter )
			{
				case 0x7:
				{
					*Add_pu8PressedKey = Loc_u8KeypadCharacters[Loc_u8iterator][KEYPAD_u8COL_1];
					Loc_u8notPressedFlag = KEYPAD_u8KEYPRESSED;
					break;
				}
				case 0xB:
				{
					*Add_pu8PressedKey = Loc_u8KeypadCharacters[Loc_u8iterator][KEYPAD_u8COL_2];
					Loc_u8notPressedFlag = KEYPAD_u8KEYPRESSED;
					break;
				}
				case 0xD:
				{
					*Add_pu8PressedKey = Loc_u8KeypadCharacters[Loc_u8iterator][KEYPAD_u8COL_3];
					Loc_u8notPressedFlag = KEYPAD_u8KEYPRESSED;
					break;
				}
				case 0xE:
				{
					*Add_pu8PressedKey = Loc_u8KeypadCharacters[Loc_u8iterator][KEYPAD_u8COL_4];
					Loc_u8notPressedFlag = KEYPAD_u8KEYPRESSED;
					break;
				}

			}

			if( Loc_u8notPressedFlag == KEYPAD_u8KEYPRESSED )
			{
				break;
			}
		}
	}

	if( Loc_u8notPressedFlag != KEYPAD_u8KEYPRESSED )
	{
		Loc_enuErrorStatus = KeypadNoKeyPressed;
	}

	return Loc_enuErrorStatus;
}
