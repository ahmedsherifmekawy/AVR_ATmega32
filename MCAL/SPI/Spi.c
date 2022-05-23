/*
 * Spi.c
 *
 *  Created on: May 20, 2022
 *      Author: WINDOWS
 */


#include "Std_types.h"
#include "Bit_utils.h"
#include "Spi.h"
#include "Spi_prv.h"
#include "avr/io.h"

Spi_tenuErrorStatus Spi_enuInit(Spi_tstrCfg * Add_strSpiCfg)
{
	Spi_tenuErrorStatus Loc_enuError = SpiOk;
	u8 Loc_u8Reg;
	if( Add_strSpiCfg == NULL )
	{
		Loc_enuError = SpiNok;
	}
	else
	{
		SPCR |= SPI_u8CR_SPE_MSK;
		Loc_u8Reg = SPCR;
		Loc_u8Reg &= ~SPI_u8CR_SPIE_MSK;
		Loc_u8Reg |= ( SPI_u8CR_SPIE_MSK | Add_strSpiCfg ->Interrupt );

		Loc_u8Reg &= ~SPI_u8CR_DORD_MSK;
		Loc_u8Reg |= ( SPI_u8CR_DORD_MSK | Add_strSpiCfg ->DataOrder );

		Loc_u8Reg &= ~SPI_u8CR_MSTR_MSK;
		Loc_u8Reg |= ( SPI_u8CR_MSTR_MSK | Add_strSpiCfg ->MasterSlaveSelect );

		Loc_u8Reg &= ~SPI_u8CR_CPOL_MSK;
		Loc_u8Reg |= ( SPI_u8CR_CPOL_MSK | Add_strSpiCfg ->ClkPolarity );

		Loc_u8Reg &= ~SPI_u8CR_CPHA_MSK;
		Loc_u8Reg |= ( SPI_u8CR_CPHA_MSK | Add_strSpiCfg ->ClkPhase );

		SPCR = Loc_u8Reg;

		switch(Add_strSpiCfg ->ClkRate)
		{
			case SPI_u8CLK_RATE_DIV_4:
			{
				CLR_BIT( SPCR , SPR0 );
				CLR_BIT( SPCR , SPR1 );
				CLR_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_16:
			{
				SET_BIT( SPCR , SPR0 );
				CLR_BIT( SPCR , SPR1 );
				CLR_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_64:
			{
				CLR_BIT( SPCR , SPR0 );
				SET_BIT( SPCR , SPR1 );
				CLR_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_128:
			{
				SET_BIT( SPCR , SPR0 );
				SET_BIT( SPCR , SPR1 );
				CLR_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_2:
			{
				CLR_BIT( SPCR , SPR0 );
				CLR_BIT( SPCR , SPR1 );
				SET_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_8:
			{
				SET_BIT( SPCR , SPR0 );
				CLR_BIT( SPCR , SPR1 );
				SET_BIT( SPCR , SPI2X );
				break;
			}
			case SPI_u8CLK_RATE_DIV_32:
			{
				CLR_BIT( SPCR , SPR0 );
				SET_BIT( SPCR , SPR1 );
				SET_BIT( SPCR , SPI2X );
				break;
			}
		}
	}
	return Loc_enuError;
}
Spi_tenuErrorStatus Spi_enuTransferData( u8 Copy_u8SendData ,pu8 Add_pu8ReceiveData )
{
	Spi_tenuErrorStatus Loc_enuError = SpiOk;

	if( Add_pu8ReceiveData == NULL )
	{
		Loc_enuError = SpiNok;
	}
	else
	{
		SPDR = Copy_u8SendData;
		while( GET_BIT(SPSR,SPIF)==0 );
		*Add_pu8ReceiveData = SPDR;
	}
	return Loc_enuError;
}
