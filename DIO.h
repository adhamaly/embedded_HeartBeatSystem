/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef DIO_H_
#define DIO_H_

#define HIGH 1
#define LOW 0
typedef enum{
	PA = 0,
	PB,
	PC,
	PD
} DIOPortID_t;
typedef enum{
	Pin0 = 0,
	Pin1,
	Pin2,
	Pin3,
	Pin4,
	Pin5,
	Pin6,
	Pin7
} DIOPinID_t;
typedef enum{
	OUT = 0,
	INFREE,
	INPULLUP
} DIODIRECTION_t;
typedef enum{
	OK = 0,
	NOK
} DIOStatus_t;

DIOStatus_t DIO_SetPinDirection(DIOPortID_t port,DIOPinID_t pin,DIODIRECTION_t dir);
DIOStatus_t DIO_SetPortDirection(DIOPortID_t port,uint8 mask);// mask = 0b00010010
void DIO_WritePin(DIOPortID_t port,DIOPinID_t pin,uint8 value );
uint8 DIO_ReadPin(DIOPortID_t port , DIOPinID_t pin);
uint8 DIO_ReadPort(DIOPortID_t port);
void DIO_WritePort(DIOPortID_t port,uint8 mask);


#endif /* DIO_H_ */
