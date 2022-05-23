/*
 * Uart.h
 *
 *  Created on: Apr 29, 2022
 *      Author: WINDOWS
 */

#ifndef UART_H_
#define UART_H_

typedef enum{
	UartOk,
	UartNok
}Uart_tenuErrorStatus;

typedef struct{
	u8 Mode;
	u8 CharacterSize;
	u8 Parity;
	u8 StopBit;
	u8 ClkPolarity;
	u16 BaudRate;
	u8 DoubleSpeed;
	u8 Tx_Interrupt;
	u8 Rx_Interrupt;
	u8 DataRegEmpty_Interrupt;
}Uart_tstrCfg;


#define     UART_u8INT_EN                                (u8)0x1
#define     UART_u8INT_DIS                               (u8)0x0

#define     UART_u8UBRR_SHIFT                            (u8)0x8

#define     UART_u8MODE_SYNC                             (u8)0x20
#define     UART_u8MODE_ASYNC                            (u8)0x0

#define     UART_u8CHAR_SIZE_5                           (u8)5
#define     UART_u8CHAR_SIZE_6                           (u8)6
#define     UART_u8CHAR_SIZE_7                           (u8)7
#define     UART_u8CHAR_SIZE_8                           (u8)8
#define     UART_u8CHAR_SIZE_9                           (u8)9

#define     UART_u8PARITY_DISABLED                       (u8)0x0
#define     UART_u8PARITY_EVEN                           (u8)0x10
#define     UART_u8PARITY_ODD                            (u8)0x30
#define     UART_u8PARITY_MASK                           (u8)0x30

#define     UART_u8STOPBIT_1                             (u8)0x0
#define     UART_u8STOPBIT_2                             (u8)0x8

#define     UART_u8CLK_POLARITY_RISING_TX                (u8)0x0
#define     UART_u8CLK_POLARITY_FALLING_TX               (u8)0x1

#define     UART_u8DOUBLE_SPEED                          (u8)0x2
#define     UART_u8NORMAL_SPEED                          (u8)0x0

Uart_tenuErrorStatus Uart_enuInit(Uart_tstrCfg * Add_pstrUartCfg);
void Uart_enuSendByte(u16 Copy_u16Data);
Uart_tenuErrorStatus Uart_enuRecieveByte(pu16 Add_pu16Data);

#endif /* UART_H_ */
