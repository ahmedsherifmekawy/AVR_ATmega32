/*
 * Twi.h
 *
 *  Created on: May 21, 2022
 *      Author: WINDOWS
 */

#ifndef TWI_H_
#define TWI_H_


typedef enum{
	TwiNok,
	TwiOk
}Twi_tenuErrorStatus;

typedef struct{
	u8 BitRate;
	u8 Prescaler;
	u8 Address;
	u8 GeneralCall;
}Twi_tstrCfg;

Twi_tenuErrorStatus Twi_enuInit( Twi_tstrCfg * Add_pstrCfg);
void Twi_vidMasterSendStart();
void Twi_vidMasterSendStop();
Twi_tenuErrorStatus Twi_enuMasterSendAddress( u8 Copy_u8SlaveAddress, u8 Copy_u8RW );
void Twi_vidMasterSendData(u8 Copy_u8Data);
Twi_tenuErrorStatus Twi_enuMasterReceiveData(pu8 Add_pu8Data);
void Twi_vidSlaveSendData(u8 Copy_u8Data);
Twi_tenuErrorStatus Twi_enuSlaveReceiveData(pu8 Add_pu8Data);
Twi_tenuErrorStatus Twi_vidGetStatus(pu8 Add_pu8Status);

#endif /* TWI_H_ */
