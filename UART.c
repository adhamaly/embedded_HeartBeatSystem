/*
 * UART.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include "memmap.h"
#include "utils.h"
#include "DIO.h"
#include "UART.h"



void USART_Init(unsigned long baud){
	/* Set baud rate */
		UBRRH = (uint8)(baud>>8);
		UBRRL = (uint8)baud;
		/* Enable receiver and transmitter */
		UCSRB = (1<<RXEN)|(1<<TXEN);
		/* Set frame format: set select register  , 2stop bit,8data */
		UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

char USART_RxChar()
{
	while ( !(UCSRA & (1<<RXC)) );
		/* Get and return received data from buffer */
		return UDR;
}

void USART_TxChar(char data)
{
	/* Wait for empty transmit buffer */
		while ( !( UCSRA & (1<<UDRE)) );
		/* Put data into buffer, sends the data */
		UDR = data;
}

void USART_SendString(char *str)
{
	int i=0;
	/* Send each char of string till the NULL */
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);
		i++;
	}
}
void USART_INT_STRING(uint8 data){
		char SHOWA [3];
		itoa(data,SHOWA,10);
		USART_SendString(SHOWA);

}
