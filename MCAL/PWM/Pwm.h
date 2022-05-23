/*
 * Pwm.h
 *
 *  Created on: Apr 28, 2022
 *      Author: WINDOWS
 */

#ifndef PWM_H_
#define PWM_H_


typedef enum{
	PwmOk,
	PwmNok
}Pwm_tenuErrorStatus;

typedef enum{
	Channel0,
	Channel1,
	Channel2
}Pwm_tenuChannel;

typedef struct{
	Pwm_tenuChannel Channel;
	u16 WGM;
	u16 COM;
	u16 CS;
}Pwm_tstrCfg;

#define PWM_u16T0WGM_MASK                        (u16)40
#define PWM_u16T0CLK_MASK                        (u16)7
#define PWM_u16T0COM_MASK                        (u16)48


#define PWM_u16T0PHASE_CORRECT_MODE              (u16)64
#define PWM_u16T0FAST_PWM_MODE                   (u16)72

#define PWM_u16T0NORMAL_PORT_OPERATION           (u16)0
#define PWM_u16T0CLR_OC0_ON_CM                   (u16)32 //Set on top (fast PWM) ,set on CM downcounting (phase correct)
#define PWM_u16T0SET_OC0_ON_CM                   (u16)48 //Clear on top (fast PWM) ,Clear on CM downcounting (phase correct)

#define PWM_u16T0NO_CLK_SRC                      (u16)0
#define PWM_u16T0CLK_PRE_1                       (u16)1
#define PWM_u16T0CLK_PRE_8                       (u16)2
#define PWM_u16T0CLK_PRE_64                      (u16)3
#define PWM_u16T0CLK_PRE_256                     (u16)4
#define PWM_u16T0CLK_PRE_1024                    (u16)5
#define PWM_u16T0CLK_EXT_FE                      (u16)6
#define PWM_u16T0CLK_EXT_RE                      (u16)7


Pwm_tenuErrorStatus Pwm_enuInit(Pwm_tstrCfg * Add_pstrPwmCfg);
Pwm_tenuErrorStatus Pwm_enuSetOCR(Pwm_tenuChannel Copy_enuChannel , u16 Copy_u16Value );
void Pwm_enuSetICR(u16 Copy_u16Value);
Pwm_tenuErrorStatus Pwm_enuStart(Pwm_tenuChannel Copy_enuChannel );

#endif /* PWM_H_ */
