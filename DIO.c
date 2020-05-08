/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include"STD.h"
#include"utils.h"
#include"memmap.h"
#include"DIO.h"

// Function set pin.
DIOStatus_t DIO_SetPinDirection(DIOPortID_t port,DIOPinID_t pin,DIODIRECTION_t dir){
if (pin <= Pin7 && port <=PD ){

	switch(port){
	case PA:
		switch(dir){
		case OUT:
			SET_BIT(DDRA,pin);
			break;
		case INPULLUP:
			CLR_BIT(DDRA,pin);
			SET_BIT(PORTA,pin);
			break;
		case INFREE:
			// code here .....
			CLR_BIT(DDRA,pin);

			break;

		}
       break;
	case PB:
		switch(dir){
				case OUT:
					SET_BIT(DDRB,pin);
					break;
				case INPULLUP:
					CLR_BIT(DDRB,pin);
					SET_BIT(PORTB,pin);
					break;
				case INFREE:
					// code here .....
					CLR_BIT(DDRB,pin);

					break;

				}
		break;

	case PC:
		switch(dir){
				case OUT:
					SET_BIT(DDRC,pin);
					break;
				case INPULLUP:
					CLR_BIT(DDRC,pin);
					SET_BIT(PORTC,pin);
					break;
				case INFREE:
					// code here .....
					CLR_BIT(DDRC,pin);

					break;

				}
		break;
	case PD:
		switch(dir){
				case OUT:
					SET_BIT(DDRD,pin);
					break;
				case INPULLUP:
					CLR_BIT(DDRD,pin);
					SET_BIT(PORTD,pin);
					break;
				case INFREE:
					// code here .....
					CLR_BIT(DDRD,pin);
					break;

				}
		break;
		}
	return OK;

}	else {
	return NOK;
}

}
// function set whole port.
DIOStatus_t DIO_SetPortDirection(DIOPortID_t port,uint8 mask){
if(port <= PD){
	switch(port){
	case PA:
		DDRA = mask;
		break;
	case PB:
		DDRB = mask;
		break;
	case PC:
		DDRC = mask;
		break;
	case PD:
		DDRD = mask;
		break;
	}
	return OK;
}
else {
	return NOK;
 }

}
void DIO_WritePin(DIOPortID_t port,DIOPinID_t pin,uint8 value ){
	if(port <= PD  && pin <= Pin7){
		switch(port){
		case PA:
			if(HIGH == value){
				SET_BIT(PORTA,pin);
			}else {
				CLR_BIT(PORTA,pin);
			}
			break;
		case PB:
			if(HIGH == value){
							SET_BIT(PORTB,pin);
						}else {
							CLR_BIT(PORTB,pin);
						}
			break;

		case PC:
			if(HIGH == value){
							SET_BIT(PORTC,pin);
						}else {
							CLR_BIT(PORTC,pin);
						}
			break;

		case PD:
			if(HIGH == value){
							SET_BIT(PORTD,pin);
						}else {
							CLR_BIT(PORTD,pin);
						}
			break;

		}
	}
}
void DIO_WritePort(DIOPortID_t port,uint8 mask){
	if(port <=PD){
		switch(port){
		case PA:
			PORTA = mask;
			break;
		case PB:
					PORTB = mask;
					break;
		case PC:
					PORTC = mask;
					break;
		case PD:
					PORTD = mask;
					break;

		}
	}
}
uint8 DIO_ReadPin(DIOPortID_t port , DIOPinID_t pin){
	uint8 v = 0;
	if(port<= PD && pin <= Pin7){
		switch(port){
		case PA:
			v =  GET_BIT(PINA,pin);
			break;
		case PB:
		v =  GET_BIT(PINB,pin);
		break;
		case PC:
			v =  GET_BIT(PINC,pin);
					break;
		case PD:
			v = GET_BIT(PIND,pin);
			break;

		}
		return v;

	}
	else {
		return 0;
	}

}
uint8 DIO_ReadPort(DIOPortID_t port){
	if(port<= PD){
		uint8 mask=0;
		switch(port){
		case PA:
			mask = PINA;
			break;
		case PB:
					mask = PINB;
					break;
		case PC:
					mask = PINC;
					break;
		case PD:
					mask = PIND;
					break;
		}
		return mask;

	}else {
		return 0;
	}
}








