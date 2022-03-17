/*
 * Port.h
 *
 *  Created on: Mar 10, 2022
 *      Author: WINDOWS
 */
#ifndef __PORT_H__
#define __PORT_H__


typedef enum{
	Port_enuPinError,
	Port_enuDirectionError,
	Port_enuOk,
	Port_enuModeError

}Port_tenuErrorStatus;



#define PORT_u8NUMBER_OF_PINS     32

#define PORT_u8PIN_INPUT          0
#define PORT_u8PIN_OUTPUT         1

#define PORT_u8PORT_A             0
#define PORT_u8PORT_B             1
#define PORT_u8PORT_C             2
#define PORT_u8PORT_D             3


#define PORT_u8INPUT_HIGHIMPEDANCE     0
#define PORT_u8INPUT_PULLUP            1
#define PORT_u8OUTPUT_HIGH			   2
#define PORT_u8OUTPUT_LOW		       3

#define PORT_u8PIN_0        0
#define PORT_u8PIN_1        1
#define PORT_u8PIN_2        2
#define PORT_u8PIN_3        3
#define PORT_u8PIN_4        4
#define PORT_u8PIN_5        5
#define PORT_u8PIN_6        6
#define PORT_u8PIN_7        7
#define PORT_u8PIN_8        8
#define PORT_u8PIN_9        9
#define PORT_u8PIN_10       10
#define PORT_u8PIN_11       11
#define PORT_u8PIN_12       12
#define PORT_u8PIN_13       13
#define PORT_u8PIN_14       14
#define PORT_u8PIN_15       15
#define PORT_u8PIN_16       16
#define PORT_u8PIN_17       17
#define PORT_u8PIN_18       18
#define PORT_u8PIN_19       19
#define PORT_u8PIN_20       20
#define PORT_u8PIN_21       21
#define PORT_u8PIN_22       22
#define PORT_u8PIN_23       23
#define PORT_u8PIN_24       24
#define PORT_u8PIN_25       25
#define PORT_u8PIN_26       26
#define PORT_u8PIN_27       27
#define PORT_u8PIN_28       28
#define PORT_u8PIN_29       29
#define PORT_u8PIN_30       30
#define PORT_u8PIN_31       31


Port_tenuErrorStatus Port_enuSetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDirection);
Port_tenuErrorStatus Port_enuSetPinMode(u8 Copy_u8PinNum, u8 Copy_u8PinMode);

#endif

