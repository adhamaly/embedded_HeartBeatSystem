/*
 * Timer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef TIMER_H_
#define TIMER_H_
typedef enum {
	_CS00 = 0,
	_CS01,
	_CS02,
	_WGM01,
	_COM00,
	_COM01,
	_WGM00,
	_FOC0
}TCCR0_R;
typedef enum {
	_WGM10 = 0,
	_WGM11,
	_FOC1B,
	_FOC1A,
	_COM1B0,
	_COM1B1,
	_COM1A0,
	_COM1A1
}TCCR1A_R;
typedef enum {
	_CS10 = 0,
	_CS11,
	_CS12,
	_WGM12,
	_WGM13,
	_X,
	_ICES1,
	_ICNC1
}TCCR1B_R;

typedef enum{
	_TOIE0 =0,
	_OCIE0,
	_TOIE1,
	_OCIE1B,
	_OCIE1A,
	_TICIE1,
	_TOIE2,
	_OCIE2
}TIMSK_R;
typedef enum{
	_TOV0 = 0,
	_OCF0,
	_TOV1,
	_OCF1B,
	_OCF1A,
	_ICF1,
	_TOV2,
	_OCF2
}TIFR_R;

#define PRESCALAR 1024
#define FCPU 8000000
#define MAX_USEC 32768

//TIMER0 PROTOTYPES..
 void delay_us(uint16);
 void Timer0_NmInit(uint8,uint16);
 void Timer0_CtcInit(uint8,uint8,uint16);
 void EN_G(void);
 void Timer0_FastPwm_NonInverted(uint8,uint16);
 void Timer0_FastPwm_Inverted(uint8,uint16);

// timer1 prototypes..

//prescalar N
 void Timer1_NmInit(uint16);
//  tcnt1h,tcnt1l,ocr1ah,ocr1al,n-prescalar
 void Timer1_CtcAInit(uint8,uint8,uint8,uint8,uint16);
//  tcnt1h,tcnt1l,ocr1bh,ocr1bl,n-prescalar
 void Timer1_CtcBInit(uint8,uint8,uint8,uint8,uint16);
// edge detectio 0-> failing 1->raising  , prescalar -n
 void Timer1_InPutCapInit(uint8,uint16);
 uint16 readICR1(void);
 uint16 readTCNT1(void);
// remain pwm of timer1....





#endif /* TIMER_H_ */
