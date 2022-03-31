/*
 * SevenSegment.c
 *
 *  Created on: Mar 21, 2022
 *      Author: WINDOWS
 */


#include "Bit_utils.h"
#include "Std_types.h"
#include "Dio.h"
#include "SevenSegment.h"
#include "SevenSegment_cfg.h"

SevenSegment_tenuErrorStatus SevenSegment_enuDisplayNumber( u8 Copy_u8number )
{
	SevenSegment_tenuErrorStatus Loc_enuErrorStatus = SevenSegmentOk;

	if(Copy_u8number > 9)
	{
		Loc_enuErrorStatus = SevenSegmentNok;
	}
	#if SEVEN_SEGMENT_MODE == COMMON_CATHODE
	u8 Loc_u8SevenSegmentNumbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
    #else
	u8 Loc_u8SevenSegmentNumbers[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
    #endif

	DIO_enuWritePort( SEVEN_SEGMENT_u8PORT , Loc_u8SevenSegmentNumbers[Copy_u8number] );

	return Loc_enuErrorStatus;
}
