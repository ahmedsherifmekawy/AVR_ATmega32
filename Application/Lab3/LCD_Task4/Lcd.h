/*
 * Lcd.h
 *
 *  Created on: Mar 16, 2022
 *      Author: WINDOWS
 */

#define   LCD_u8ROW_1                 0b10000000
#define   LCD_u8ROW_2                 0b11000000

#define   LCD_u8COL_1                 0
#define   LCD_u8COL_2                 1
#define   LCD_u8COL_3                 2
#define   LCD_u8COL_4                 3
#define   LCD_u8COL_5                 4
#define   LCD_u8COL_6                 5
#define   LCD_u8COL_7                 6
#define   LCD_u8COL_8                 7
#define   LCD_u8COL_9                 8
#define   LCD_u8COL_10                9
#define   LCD_u8COL_11                10
#define   LCD_u8COL_12                11
#define   LCD_u8COL_13                12
#define   LCD_u8COL_14                13
#define   LCD_u8COL_15                14
#define   LCD_u8COL_16                15




#define   LCD_u8RW_READ               1
#define   LCD_u8RW_WRITE			  0

#define   LCD_u8RS_COMMAND            0
#define   LCD_u8RS_DATA	              1

#define   LCD_u8ENABLE_HIGH	          1
#define   LCD_u8ENABLE_LOW            0

#define   ENDING_CHAR                 '\0'
#define   INDEX_ZERO                  0
#define   INDEX_EIGHT                 8

#define   LCD_u8CLEAR_DISPLAY                             0b00000001
#define   LCD_u8CLEAR_RETURN_HOME                         0b00000010

#define   LCD_u8CURSOR_LEFT_TO_RIGHT                      0b00000110
#define   LCD_u8CURSOR_RIGHT_TO_LEFT                	  0b00000100

#define   LCD_u8DISPLAY_ON                                0b00001100
#define   LCD_u8DISPLAY_OFF                               0b00001100
#define   LCD_u8CURSOR_ON                                 0b00001010
#define   LCD_u8CURSOR_OFF                                0b00001000
#define   LCD_u8CURSOR_BLINK_ON                           0b00001001
#define   LCD_u8CURSOR_BLINK_OFF                          0b00001000

#define   LCD_u8SHIFT_CURSOR_LEFT                         0b00010000
#define   LCD_u8SHIFT_CURSOR_RIGHT                        0b00010100
#define   LCD_u8SHIFT_DISPLAY_LEFT                        0b00011000
#define   LCD_u8SHIFT_DISPLAY_RIGHT                       0b00011100

#define   LCD_u8EIGHT_BIT_MODE                            0b00110000
#define   LCD_u8FOUR_BIT_MODE                             0b00100000
#define   LCD_u8ONE_LINE_DISPLAY                          0b00100000
#define   LCD_u8TWO_LINE_DISPLAY                          0b00101000
#define   LCD_u8FIVE_TIMES_SEVEN_DOTS                     0b00100000
#define   LCD_u8FIVE_TIMES_TEN_DOTS                       0b00100100

#define   LCD_u8SET_CGRAM_ADDRESS                         0b01000000
#define   LCD_u8SET_DDRAM_ADDRESS                         0b10000000

#define   LCD_u8CGRAM_ADDRESS_1                           0b01000000
#define   LCD_u8CGRAM_ADDRESS_2                           0b01001000
#define   LCD_u8CGRAM_ADDRESS_3                           0b01010000
#define   LCD_u8CGRAM_ADDRESS_4                           0b01011000
#define   LCD_u8CGRAM_ADDRESS_5                           0b01100000
#define   LCD_u8CGRAM_ADDRESS_6                           0b01101000
#define   LCD_u8CGRAM_ADDRESS_7                           0b01110000
#define   LCD_u8CGRAM_ADDRESS_8                           0b01111000

#define   LCD_u8ADDRESS_MASK                              0b01111111
#define   LCD_u8BF_MASK                                   0b10000000


#define   LCD_u8ZERO                                      0
#define   LCD_u8ONE                                       0

///////////////////////////////////////////////////////////////////////////////////////////////////
void Lcd_vidInit();
void Lcd_vidSendCommand( u8 Copy_u8Command );
void Lcd_vidDisplayCharacter( u8 Copy_u8Character );
void Lcd_vidCreateCustomCharacter( pu8 Add_pu8CustomCharacter , u8 Copy_u8CgramAddress );

void Lcd_vidDisplayNumber( u32 Copy_u32Number );
void Lcd_vidGoTo( u8 Copy_u8Row , u8 Copy_u8Col );
void Lcd_vidDisplayString( pu8 Add_pu8String );
