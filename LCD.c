/*
 * LCD.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include<util/delay.h>
#include"STD.h"
#include"LCD_CFG.h"
#include"DIO.h"


LCD_STATUS LCD_Init(){

	LCD_STATUS status = _NOK;
// set direction output for [ CONTROL PINS & DATA PINS ]
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RS,OUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RW,OUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_E,OUT);
	// Set Direction for Data port
	DIO_SetPortDirection(LCD_DATA_PORT,0xff);
	_delay_ms(40);
	LCD_SendCmd(CMD_FUNCTION_SET_CMD);
	_delay_us(40);
	LCD_SendCmd(CMD_DISPLAY_ON_CURSOR_OFF);
	_delay_us(40);
	LCD_SendCmd(CMD_DISPLAY_CLEAR);
	_delay_ms(2);
	LCD_SendCmd(CMD_ENTRY_MODE_SET);

// end of initialization.....


	return status;


}
LCD_STATUS LCD_SendCmd(uint8 Cmd){
	LCD_STATUS status = 0;
	//RS = 0 (register command)
	//RW = 0 (Write on LCD)
	//send argument into LCD_DATA_PORT
	// Latching + delay....
	// E = HIGH
	//delay
	//E  = LOW
	// status  = _OK
	if(sizeof(Cmd) == sizeof(uint8)){
		DIO_WritePin(LCD_CONTROL_PORT,LCD_RS,LOW);
		DIO_WritePin(LCD_CONTROL_PORT,LCD_RW,LOW);
		DIO_WritePort(LCD_DATA_PORT,Cmd);
		DIO_WritePin(LCD_CONTROL_PORT,LCD_E,HIGH);
		_delay_ms(1);
		DIO_WritePin(LCD_CONTROL_PORT,LCD_E,LOW);

status = _OK;
	}else {
		status = _NOK;
	}
		return status;
}
LCD_STATUS LCD_SendChar(uint8 character){
	LCD_STATUS status = 0;
		//RS = 1 (register data)
			//RW = 0 (Write on LCD)
			//send argument into LCD_DATA_PORT
			// Latching + delay....
			// E = HIGH
			//delay
			//E  = LOW
	// status  = _OK
	if(sizeof(character) == sizeof(uint8)){
			DIO_WritePin(LCD_CONTROL_PORT,LCD_RS,HIGH);
			DIO_WritePin(LCD_CONTROL_PORT,LCD_RW,LOW);
			DIO_WritePort(LCD_DATA_PORT,character);
			DIO_WritePin(LCD_CONTROL_PORT,LCD_E,HIGH);
			_delay_ms(1);
			DIO_WritePin(LCD_CONTROL_PORT,LCD_E,LOW);

	status = _OK;
		}else {
			status = _NOK;
		}
			return status;


}
void LCD_IntegerToString(uint16 data)
{
	char SHOWA [3];
	itoa(data,SHOWA,10);
	LCD_send_a_string(SHOWA);
}
void LCD_send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {
        LCD_SendChar(*string_of_characters++);
    }
}
LCD_STATUS LCD_PutChar_XY(uint8 Line,uint8 index){
	LCD_STATUS status = _OK;
	switch(Line){
	case 1:
		LCD_SendCmd(FIRST_LINE_ADDRES+(index-1));
		break;
	case 2:

		LCD_SendCmd(SECOND_LINE_ADDRES+(index-1));
		break;
	default:
		status = _OK;
		break;
	}
	return status;
}
void LCD_ShiftLeft(){
	LCD_SendCmd(SHIFT_LEFT_MASK);
}
void LCD_RightRight(){
	LCD_SendCmd(SHIFT_RIGHT_MASK);
}

void LCD_DrawPattern(uint8 *p){
	LCD_SendCmd(FIRST_ADDRESS_CGRAM);
for(int i =0;i<64;i++){
		LCD_SendChar(p[i]);
	}

	/*
	LCD_SendChar(0b00011110);
	LCD_SendChar(0b00011110);
	LCD_SendChar(0b00010100);
	LCD_SendChar(0b00011100);
	LCD_SendChar(0b00000100);
	LCD_SendChar(0b00000100);
	LCD_SendChar(0b00001010);
	*/
	LCD_SendCmd(FIRST_ADDRESS_DDRAM);
	for(int i =0;i<8;i++){
		LCD_SendChar(FIRST_READ_ADDRESS_DDRAM+i);
	}


}
