/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef UART_H_
#define UART_H_

typedef enum{
	MPCM = 0,
	U2X,
	PE,
	DOR,
	FE,
	UDRE,
	TXC,
	RXC
}UCSRA_R;

typedef enum{
		TXB8 = 0,
		RXB8,
		UCSZ2,
		TXEN,
		RXEN,
		UDRIE,
		TXCIE,
		RXCIE

}UCSRB_R;

typedef enum{
	UCPOL  = 0,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL

}UCSRA_C;



void USART_Init(unsigned long);				/* USART initialize function */
char USART_RxChar();						/* Data receiving function */
void USART_TxChar(char);					/* Data transmitting function */
void USART_SendString(char*);				/* Send string of USART data function */
void USART_INT_STRING(uint8 data);



#endif /* UART_H_ */
