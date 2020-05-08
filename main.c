/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#include "STD.h"
#include "ADC.h"
#include "UART.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD_CFG.h"
#include "DIO.h"
#include "Timer.h"
#include "memmap.h"
#include "UART.h"

int rate[10]; // array to hold last ten IBI values
unsigned long sampleCounter = 0; // used to determine pulse timing
unsigned long lastBeatTime = 0; // used to find IBI
int Peak =512; // used to find peak in pulse wave, seeded
int Trough = 512; // used to find trough in pulse wave, seeded
int thresh = 256; // used to find instant moment of heart beat, seeded
int amp = 100; // used to hold amplitude of pulse waveform, seeded
uint8 firstBeat; // used to seed rate array so we startup with reasonable BPM
uint8 secondBeat; // used to seed rate array so we startup with reasonable BPM
int pulsePin = 0; // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13; // pin to blink led at each beat

int runningTotal = 0; // clear the runningTotal variable
// these variables are volatile because they are used during the interrupt service routine!
unsigned int BPM; // used to hold the pulse rate
unsigned int Signal; // holds the incoming raw data
unsigned int IBI = 600; // holds the time between beats, must be seeded!
uint8 Pulse ; // true when pulse wave is high, false when it's low
uint8 QS;
int N_cnt, P_cnt;
int i = 0;
int main(void){

	Pulse = 0;
	QS = 0;
	firstBeat = 1;
	secondBeat = 0;
	DIO_SetPinDirection(PD,Pin0,INFREE);
	DIO_SetPinDirection(PD,Pin1,OUT);

	LCD_Init(); //initialize LCD
	ADC_Int();
	USART_Init(51);
	Timer0_CtcInit(0,124,256);
	EN_G();


	while(1){
	if (QS == 1){
		//LCD_PutChar_XY(1,1);
		//LCD_IntegerToString(BPM);
    	USART_TxChar(BPM);

	}


	}



	return 0;
}

ISR(TIMER0_COMP_vect){
	//READ HEART RATE FROM LCD

	Signal = Read_Analog(ADC0);
	sampleCounter += 2;
	N_cnt = sampleCounter - lastBeatTime;
	if(Signal < thresh && N_cnt > (IBI/5)*3){
	if (Signal < Trough){
	Trough = Signal;
	}
	}
	if(Signal > thresh && Signal > P_cnt){
	P_cnt = Signal;
	}

	// NOW IT'S TIME TO LOOK FOR THE HEART BEAT
	// signal surges up in value every time there is a pulse
	if (N_cnt > 250){ // avoid high frequency noise
	if ( (Signal > thresh) && (Pulse == 0) && (N_cnt > (IBI/5)*3) ){
	Pulse = 1; // set the Pulse flag when we think there is a pulse
	IBI = sampleCounter - lastBeatTime; // measure time between beats in mS
	lastBeatTime = sampleCounter; // keep track of time for next pulse

	if(secondBeat){ // if this is the second beat, if secondBeat == TRUE
	secondBeat = 0; // clear secondBeat flag
	for(i=0; i<=9; i++){ // seed the running total to get a realisitic BPM at startup
	rate[i] = IBI;
	}
	}

	if(firstBeat){ // if it's the first time we found a beat, if firstBeat == TRUE
	firstBeat = 0; // clear firstBeat flag
	secondBeat = 1; // set the second beat flag

	return; // IBI value is unreliable so discard it
	}


	// keep a running total of the last 10 IBI values
	runningTotal = 0; // clear the runningTotal variable

	for(i=0; i<=8; i++){ // shift data in the rate array
	rate[i] = rate[i+1]; // and drop the oldest IBI value
	runningTotal += rate[i]; // add up the 9 oldest IBI values
	}

	rate[9] = IBI; // add the latest IBI to the rate array
	runningTotal += rate[9]; // add the latest IBI to runningTotal
	runningTotal /= 10; // average the last 10 IBI values
	BPM = 60000/runningTotal; // how many beats can fit into a minute? that's BPM!
	QS = 1; // set Quantified Self flag
	// QS FLAG IS NOT CLEARED INSIDE THIS ISR
	}
	}

	if (Signal < thresh && Pulse == 1){ // when the values are going down, the beat is over

	Pulse = 0; // reset the Pulse flag so we can do it again
	amp = P_cnt - Trough; // get amplitude of the pulse wave
	thresh = amp/2 + Trough; // set thresh at 50% of the amplitude
	P_cnt = thresh; // reset these for next time
	Trough = thresh;
	}

	if (N_cnt > 2500){ // if 2.5 seconds go by without a beat
	thresh = 512; // set thresh default
	P_cnt = 512; // set P default
	Trough = 512; // set T default
	lastBeatTime = sampleCounter; // bring the lastBeatTime up to date
	firstBeat = 1; // set these to avoid noise
	secondBeat = 0; // when we get the heartbeat back
	}


}


