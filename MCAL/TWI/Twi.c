/*
 * Twi.c
 *
 *  Created on: May 21, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "avr/io.h"
#include "Twi.h"
#include "Twi_prv.h"


Twi_tenuErrorStatus Twi_enuInit( Twi_tstrCfg * Add_pstrCfg)
{
	Twi_tenuErrorStatus Loc_enuError = TwiOk;

	u8 Loc_u8Reg;
	if(Add_pstrCfg == NULL)
	{
		Loc_enuError = TwiNok;
	}
	else
	{
		Loc_u8Reg = TWSR;
		Loc_u8Reg &= ~TWI_u8PRESCALER_MSK;
		Loc_u8Reg |= ( Add_pstrCfg->Prescaler | TWI_u8PRESCALER_MSK );
		TWBR = Add_pstrCfg->BitRate;
		TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) );
		while( GET_BIT(TWCR, TWINT) == 0 );
		TWAR |= ( Add_pstrCfg->Address << 1 );
		TWAR |= Add_pstrCfg->GeneralCall;
		TWSR = Loc_u8Reg;
	}
	return Loc_enuError;
}
void Twi_vidMasterSendStart()
{
	TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) | (1<<TWSTA) | (1<<TWINT) );
	while( GET_BIT(TWCR, TWINT) == 0 );
	TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) );
}
void Twi_vidMasterSendStop()
{
	TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) | (1<<TWSTO) );
	TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) | (1<<TWSTO) | (1<<TWINT) );
}
Twi_tenuErrorStatus Twi_enuMasterSendAddress( u8 Copy_u8SlaveAddress, u8 Copy_u8RW )
{
	Twi_tenuErrorStatus Loc_enuError = TwiOk;
	u8 Loc_u8Reg;
	if(Copy_u8SlaveAddress > 128)
	{
		Loc_enuError = TwiNok;
	}
	else
	{
		Loc_u8Reg = ( Copy_u8SlaveAddress << 1 );
		Loc_u8Reg |= Copy_u8RW;
		while( GET_BIT(TWCR, TWINT) == 0 );
		TWDR = Loc_u8Reg;
	}
	return Loc_enuError;
}

void Twi_vidSendData(u8 Copy_u8Data)
{
	while( GET_BIT(TWCR, TWINT) == 0 );
	TWDR = Copy_u8Data;
}
Twi_tenuErrorStatus Twi_enuReceiveData(pu8 Add_pu8Data)
{
	Twi_tenuErrorStatus Loc_enuError = TwiOk;

	if(Add_pu8Data == NULL)
	{
		Loc_enuError = TwiNok;
	}
	else
	{
		TWCR = ( (1<<TWEN) | (1<<TWIE) | (1<<TWEA) | (1<<TWINT) );
		while( GET_BIT(TWCR, TWINT) == 0 );

		// Check status if data is received by ack ( or let it for the user to check )
		*Add_pu8Data = TWDR;
	}

	return Loc_enuError;
}
Twi_tenuErrorStatus Twi_vidGetStatus(pu8 Add_pu8Status)
{
	Twi_tenuErrorStatus Loc_enuError = TwiOk;

	if(Add_pu8Status == NULL)
	{
		Loc_enuError = TwiNok;
	}
	else
	{
		while( GET_BIT(TWCR, TWINT) == 0 );
		*Add_pu8Status = ( TWSR & 0b11111000 );
	}
	return Loc_enuError;
}
