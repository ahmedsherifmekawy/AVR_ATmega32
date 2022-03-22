/*
 * Keypad.h
 *
 *  Created on: Mar 20, 2022
 *      Author: WINDOWS
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

typedef enum{
	KeypadOk,
	KeypadNoKeyPressed,
	KeypadNok
}Keypad_tenuErrorStatus;

#define    KEYPAD_ZERO            0

#define    KEYPAD_u8COL_1         0
#define    KEYPAD_u8COL_2         1
#define    KEYPAD_u8COL_3         2
#define    KEYPAD_u8COL_4         3

#define    KEYPAD_u8KEYPRESSED    0xFF

Keypad_tenuErrorStatus Keypad_enuGetKey(pu8 Add_pu8PressedKey);


#endif /* KEYPAD_H_ */
