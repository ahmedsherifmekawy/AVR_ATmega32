/*
 * Dio.h
 *
 *  Created on: Mar 10, 2022
 *      Author: WINDOWS
 */

#ifndef __DIO_H___
#define __DIO_H___

#include "Std_types.h"

typedef enum{
	DioChannelIdError,
	DioLevelError,
	Dio_enuOK

}Dio_tenuErrorStatus;


#define DIO_u8NUMBER_OF_PINS     32

#define DIO_u8LEVEL_ZERO         0
#define DIO_u8LEVEL_ONE          1

#define DIO_u8PORT_A             0
#define DIO_u8PORT_B             1
#define DIO_u8PORT_C             2
#define DIO_u8PORT_D             3

#define DIO_u8PORT_NUMBER 		 4


#define DIO_u8PIN_0              0
#define DIO_u8PIN_1              1
#define DIO_u8PIN_2              2
#define DIO_u8PIN_3              3
#define DIO_u8PIN_4              4
#define DIO_u8PIN_5              5
#define DIO_u8PIN_6              6
#define DIO_u8PIN_7              7
#define DIO_u8PIN_8              8
#define DIO_u8PIN_9              9
#define DIO_u8PIN_10             10
#define DIO_u8PIN_11             11
#define DIO_u8PIN_12             12
#define DIO_u8PIN_13             13
#define DIO_u8PIN_14             14
#define DIO_u8PIN_15             15
#define DIO_u8PIN_16             16
#define DIO_u8PIN_17             17
#define DIO_u8PIN_18             18
#define DIO_u8PIN_19             19
#define DIO_u8PIN_20             20
#define DIO_u8PIN_21             21
#define DIO_u8PIN_22             22
#define DIO_u8PIN_23             23
#define DIO_u8PIN_24             24
#define DIO_u8PIN_25             25
#define DIO_u8PIN_26             26
#define DIO_u8PIN_27             27
#define DIO_u8PIN_28             28
#define DIO_u8PIN_29             29
#define DIO_u8PIN_30             30
#define DIO_u8PIN_31             31


Dio_tenuErrorStatus DIO_enuWriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8ChannelLevel);
Dio_tenuErrorStatus DIO_enuReadChannel(u8 Copy_u8ChannelId, pu8 Copy_pu8ChannelLevel);
Dio_tenuErrorStatus DIO_enuWritePort(u8 Copy_u8PortId, u8 Copy_u8PortLevel);
Dio_tenuErrorStatus DIO_enuReadPort(u8 Copy_u8PortId, pu8 Copy_pu8PortLevel);
Dio_tenuErrorStatus DIO_enuFlipChannel(u8 Copy_u8ChannelId);


#endif
