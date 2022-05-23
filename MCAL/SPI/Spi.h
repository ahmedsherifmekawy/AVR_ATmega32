/*
 * Spi.h
 *
 *  Created on: May 20, 2022
 *      Author: WINDOWS
 */

#ifndef SPI_H_
#define SPI_H_

typedef enum{
	SpiNok,
	SpiOk
}Spi_tenuErrorStatus;

typedef struct{
	u8 Interrupt;
	u8 DataOrder;
	u8 MasterSlaveSelect;
	u8 ClkPolarity;
	u8 ClkPhase;
	u8 ClkRate;
}Spi_tstrCfg;


#define              SPI_u8INT_EN                       (u8)0x80
#define              SPI_u8INT_DIS                      (u8)0x0

#define              SPI_u8DATA_ORDER_LSB               (u8)0x20
#define              SPI_u8DATA_ORDER_MSB               (u8)

#define              SPI_u8MASTER                       (u8)0x10
#define              SPI_u8SLAVE                        (u8)0x0

#define              SPI_u8CLK_POL_LE_RISING            (u8)0x0
#define              SPI_u8CLK_POL_LE_FALING            (u8)0x8

#define              SPI_u8CLK_PH_LE_SAMPLE             (u8)0x0
#define              SPI_u8CLK_PH_LE_SETUP              (u8)0x4

#define              SPI_u8CLK_RATE_DIV_4               (u8)1
#define              SPI_u8CLK_RATE_DIV_16              (u8)2
#define              SPI_u8CLK_RATE_DIV_64              (u8)3
#define              SPI_u8CLK_RATE_DIV_128             (u8)4
#define              SPI_u8CLK_RATE_DIV_2               (u8)5
#define              SPI_u8CLK_RATE_DIV_8               (u8)6
#define              SPI_u8CLK_RATE_DIV_32              (u8)7


Spi_tenuErrorStatus Spi_enuInit(Spi_tstrCfg * Add_strSpiCfg);
Spi_tenuErrorStatus Spi_enuTransferData( u8 Copy_u8SendData ,pu8 Add_pu8ReceiveData );

#endif /* SPI_H_ */
