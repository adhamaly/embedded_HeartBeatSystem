/*
 * Timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include "utils.h"
#include "memmap.h"
#include "DIO.h"
#include "Timer.h"

 void delay_us(uint16 uSec){

	if(uSec <= MAX_USEC){
		// value calculation..
			uint8 counts = (uSec) / 128;
			uint8 tcnt0V = 256-counts;
				// load value into TCNT0
			TCNT0 = tcnt0V;
	// configure timer0 mode , prescalar 1024 ..
			TCCR0 = (1<<_CS00) | (1<<_CS02);

			// wait until TOV flag bit set [1]
			while(GET_BIT(TIFR,_TOV0) == 0);
			// Stop timer
			TCCR0 = 0;
			// Clear bit ..
			SET_BIT(TIFR,_TOV0);
	}

}
/* detail:- must enable global interrupt and make while(1); after call fucntion ...*/
 void Timer0_NmInit(uint8 tcntV,uint16 n){
	/* load value into TCNT0 */
			TCNT0 = tcntV;
			switch (n) {
			case 0:
				TCCR0 = (1<<_CS00);
				break;
			case 8:
				TCCR0 = (1<<_CS01);
				break;
			case 64:
				TCCR0 = (1<<_CS00) | (1<<_CS01);
				break;
			case 256:
				TCCR0 = (1<<_CS02);
				break;
			case 1024:
				TCCR0 = (1<<_CS00) | (1<<_CS02);
		     	break;
				}



		// enable interrupt for timer0
	SET_BIT(TIMSK,_TOIE0);
}

 void Timer0_CtcInit(uint8 tcnt0V,uint8 ocr0V,uint16 n){

	// load value into TCNT0
		TCNT0 = tcnt0V;
		// configure timer0 CTC mode
		SET_BIT(TCCR0,_WGM01);
		switch (n) {
					case 0:
						TCCR0 = (1<<_CS00);
						break;
					case 8:
						TCCR0 = (1<<_CS01);
						break;
					case 64:
						TCCR0 = (1<<_CS00) | (1<<_CS01);
						break;
					case 256:
						TCCR0 = (1<<_CS02);
						break;
					case 1024:
						TCCR0 = (1<<_CS00) | (1<<_CS02);
				     	break;
						}

	// load value to be compared with TCNT0 ..
	OCR0 = ocr0V;
	// enable interrupt for timer0
		SET_BIT(TIMSK,_OCIE0);

}
 void EN_G(void){
	SET_BIT(SREG,7);

}
 void Timer0_FastPwm_NonInverted(uint8 ocr0V,uint16 n){
	OCR0  = ocr0V;
	switch (n) {
				case 0:
					TCCR0 = (1<<_CS00);
					break;
				case 8:
					TCCR0 = (1<<_CS01);
					break;
				case 64:
					TCCR0 = (1<<_CS00) | (1<<_CS01);
					break;
				case 256:
					TCCR0 = (1<<_CS02);
					break;
				case 1024:
					TCCR0 = (1<<_CS00) | (1<<_CS02);
			     	break;
					}
	SET_BIT(TCCR0,_WGM00); // enable FAST
	SET_BIT(TCCR0,_WGM01);
	SET_BIT(TCCR0,_COM01); // enable non-inverted
	// enable interrupt for timer0
	SET_BIT(TIMSK,_TOIE0);
}
 void Timer0_FastPwm_Inverted(uint8 ocr0V,uint16 n){
	OCR0  = ocr0V;
	switch (n) {
				case 0:
					TCCR0 = (1<<_CS00);
					break;
				case 8:
					TCCR0 = (1<<_CS01);
					break;
				case 64:
					TCCR0 = (1<<_CS00) | (1<<_CS01);
					break;
				case 256:
					TCCR0 = (1<<_CS02);
					break;
				case 1024:
					TCCR0 = (1<<_CS00) | (1<<_CS02);
			     	break;
					}
	SET_BIT(TCCR0,_WGM00); // enable FAST
	SET_BIT(TCCR0,_WGM01);
	// enable inverted
	SET_BIT(TCCR0,_COM01);
	SET_BIT(TCCR0,_COM01);
	// enable interrupt for timer0
	SET_BIT(TIMSK,_TOIE0);
}
// TIMER 1 implementation ...

 void Timer1_NmInit(uint16 n){

	// WRITE TCNT1H ,then TCNT1L  (TCNT1)
	TCNT1H = 0;
	TCNT1L  = 0;
	// Choose prescalar division factor.
	switch (n) {
				case 0:
					TCCR1B = (1<<_CS10);
					break;
				case 8:
					TCCR1B = (1<<_CS11);
					break;
				case 64:
					TCCR1B = (1<<_CS10) | (1<<_CS11);
					break;
				case 256:
					TCCR1B = (1<<_CS12);
					break;
				case 1024:
					TCCR1B = (1<<_CS10) | (1<<_CS12);
			     	break;
					}


	// enable interrupt for timer0
		SET_BIT(TIMSK,_TOIE1);

}


 uint16 readICR1(){
	return (ICR1L | (ICR1H <<7 ));
}

 uint16 readTCNT1(){
	return (TCNT1L | (TCNT1H <<7 ));
}
