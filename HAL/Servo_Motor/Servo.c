/*
 * Servo.c
 *
 *  Created on: Apr 29, 2022
 *      Author: WINDOWS
 */



#include "Std_types.h"
#include "Bit_utils.h"
#include "Pwm.h"
#include "Servo.h"

void Servo_vidInit( void )
{
	Pwm_tstrCfg Loc_strServo = {
			.CS = PWM_u16T0CLK_PRE_256 ,
			.Channel = Channel1,
			.WGM = PWM_u16T0FAST_PWM_MODE,
			.COM = PWM_u16T0CLR_OC0_ON_CM
	};
	Pwm_enuInit( &Loc_strServo );
	Pwm_enuSetICR( SERVO_u16TIMER_TOP );
	Pwm_enuStart( Channel1 );

}
void Servo_vidSetAngle( u8 Copy_u8Angle)
{
	f32 Loc_f32Temp = 0.34444444;
	u16 Loc_u16Res;
	Loc_u16Res = (f32) ( Loc_f32Temp * (f32)Copy_u8Angle ) + 63;
	Pwm_enuSetOCR( Channel1 , Loc_u16Res );
}
