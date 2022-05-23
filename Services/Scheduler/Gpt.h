/*
 * Gpt.h
 *
 *  Created on: Apr 18, 2022
 *      Author: WINDOWS
 */

#ifndef GPT_H_
#define GPT_H_

typedef enum{
	Timer0,
	Timer1,
	Timer2
}Gpt_ChannelType;

typedef struct{
	u8 WGM;
	u8 COM;
	u8 CS;
	u8 OCR;
	u8 ModeOfOPeration;
}T02_Cfg;

typedef struct{
	u8 WGM;
	u8 COMA;
	u8 COMB;
	u8 CS;
	u16 OCRA;
	u16 OCRB;
	u16 ICR;
	u16 ModeOfOPeration;
}T1_Cfg;

typedef struct{
	Gpt_ChannelType Channel;
	T02_Cfg * T0;
	T1_Cfg * T1;
	T02_Cfg * T2;
}Gpt_ConfigType;


typedef enum{
	GptOk,
	GptNok
}Gpt_tenuErrorStatus;

typedef void (*cbf_t)(void);


#define GPT_u8_COM_NORMAL_PORT_OPERATION           (u8)0
#define GPT_u8_COM_TOGGLE_IN_COMPARE_MATCH         (u8)16
#define GPT_u8_COM_CLEAR_IN_COMPARE_MATCH          (u8)32
#define GPT_u8_COM_SET_IN_COMPARE_MATCH            (u8)48

#define GPT_u8_WGM_T02NORMAL_MODE                  (u8)0
#define GPT_u8_WGM_T02CTC_MODE                     (u8)8

#define GPT_u8T1WGM_NORMAL                         (u8)0
#define GPT_u8T1WGM_CTC_OCRA                       (u8)1
#define GPT_u8T1WGM_CTC_ICR                        (u8)2

#define GPT_u8_CS_T01NO_CLK_SRC                    (u8)0
#define GPT_u8_CS_T01CLK_PRE_1                     (u8)1
#define GPT_u8_CS_T01CLK_PRE_8                     (u8)2
#define GPT_u8_CS_T01CLK_PRE_64                    (u8)3
#define GPT_u8_CS_T01CLK_PRE_256                   (u8)4
#define GPT_u8_CS_T01CLK_PRE_1024                  (u8)5
#define GPT_u8_CS_T01CLK_EXT_FE                    (u8)6
#define GPT_u8_CS_T01CLK_EXT_RE                    (u8)7

#define GPT_u8_CS_T2NO_CLK_SRC                     (u8)0
#define GPT_u8_CS_T2CLK_PRE_1                      (u8)1
#define GPT_u8_CS_T2CLK_PRE_8                      (u8)2
#define GPT_u8_CS_T2CLK_PRE_32                     (u8)3
#define GPT_u8_CS_T2CLK_PRE_64                     (u8)4
#define GPT_u8_CS_T2CLK_PRE_128                    (u8)5
#define GPT_u8_CS_T2CLK_PRE_256                    (u8)6
#define GPT_u8_CS_T2CLK_PRE_1024                   (u8)7


#define GPT_u8T0POLLING                            (u8)0
#define GPT_u8T0INTERRUPT_NORMAL                   (u8)1
#define GPT_u8T0INTERRUPT_CTC                      (u8)2

Gpt_tenuErrorStatus Gpt_enuInit( const Gpt_ConfigType * Add_pstrConfig );
Gpt_tenuErrorStatus Gpt_enuGetTimeElapsed( Gpt_ChannelType Copy_enuChannel , pu16 Add_pu16Time );
Gpt_tenuErrorStatus Gpt_enuStartTimer( Gpt_ChannelType Copy_enuChannel , u16 Copy_u16Preload );
Gpt_tenuErrorStatus Gpt_enuStopTimer( Gpt_ChannelType Copy_enuChannel );
Gpt_tenuErrorStatus Gpt_enuT0OverflowRegiserCbf(cbf_t Add_Cbf);
#endif /* GPT_H_ */
