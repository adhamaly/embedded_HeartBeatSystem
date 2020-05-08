/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

// macros for control port and pins used for this port..
#define LCD_CONTROL_PORT PC
#define LCD_RS  Pin0
#define LCD_RW  Pin1
#define LCD_E   Pin2

#define LCD_DATA_PORT PB
// COMANDS for initialization..
#define CMD_FUNCTION_SET_CMD 0x38
#define CMD_DISPLAY_ON_CURSOR_OFF 0x0c
#define CMD_DISPLAY_CLEAR 0x01
#define CMD_ENTRY_MODE_SET 0x06

#define FIRST_LINE_ADDRES 0x80
#define SECOND_LINE_ADDRES 0xc0

#define SHIFT_LEFT_MASK 0b00011000
#define SHIFT_RIGHT_MASK 0b00011100

// Addresses ...
#define FIRST_ADDRESS_CGRAM 0x40
#define FIRST_ADDRESS_DDRAM 0x80
#define FIRST_READ_ADDRESS_DDRAM 0x00


typedef enum {
	_OK = 0,
	_NOK
}LCD_STATUS;

void LCD_IntegerToString(uint16 data);
LCD_STATUS LCD_Init();
LCD_STATUS LCD_SendCmd(uint8 Cmd);
LCD_STATUS LCD_SendChar(uint8 character);
void LCD_send_a_string(char *p);
LCD_STATUS LCD_PutChar_XY(uint8 Line,uint8 index);
void LCD_ShiftLeft();
void LCD_ShiftRight();
void LCD_DrawPattern(uint8 Patter[8]);





#endif /* LCD_CFG_H_ */
