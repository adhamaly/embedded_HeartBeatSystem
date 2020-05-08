/*
 * ADC.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */
#include "STD.h"
#include"ADC.h"
#include "utils.h"
#include "DIO.h"
#include "memmap.h"

 void ADC_Int(void){
	 SET_BIT(ADCSRA,ADEN); // enable ADC
	 SET_BIT(ADCSRA,ADPS2); // determine the prescalar divide factor...
	 SET_BIT(ADCSRA,ADPS1);
	 SET_BIT(ADCSRA,ADPS0);
	 // after the prescalar determine the Reference selection..
	 SET_BIT(ADCMUX,REFS0);
	 SET_BIT(ADCMUX,REFS1);
 }

 void ADC_StartSingleConversion(ADC_CHANNEL_T pin ){
	// MOD_REG(ADCMUX,pin); //
	  ADCMUX |= pin;  // determine the channel
	 SET_BIT(ADCSRA,ADSC); // start conversion

	/*  while the conversion is not processed halt the processor
	 (read the flag bit if = 0  conversion not finished)
       if = 1  conversion finished */
 	 while(GET_BIT(ADCSRA,ADIF) == 0);
	 /* if conversion is processed set the flag to be cleared by AND gate.. cleared mean that there is no conversion
	  * in this function the ADC will make one conversion and flag bit will cleared ..
	  * (put function in while(1) to make ADC convert more than one time) */
	 SET_BIT(ADCSRA,ADIF);

 }
  void ADC_AutoTriggerConversion(ADC_CHANNEL_T pin){
	  ADCMUX |= pin;
	  	 SET_BIT(ADCSRA,ADSC);
	  	 SET_BIT(ADCSRA,ADATE);
	  	 CLR_BIT(SFIOR,ADTS2);
	  	 CLR_BIT(SFIOR,ADTS1);
	  	 CLR_BIT(SFIOR,ADTS0);

	  	/*  while the conversion is not processed halt the processor
	  	 (read the flag bit if = 0  conversion not finished)
	         if = 1  conversion finished */
	   	 while(GET_BIT(ADCSRA,ADIF) == 0);
	  	 /* if conversion is processed set the flag to be cleared by AND gate.. cleared mean that there is no conversion
	  	  *  to allow ADC to make a new conversion.. in this function ADC make new conversion auto if flag bit is cleared ..
	  	  *  */
	  	 SET_BIT(ADCSRA,ADIF);

 }

  uint16 ADC_GETVALUE(void){

	  uint16 value = ADCL | (ADCH <<8);
	  return value;

  }


  uint16 Read_Analog(ADC_CHANNEL_T pin){

    	  ADCMUX |= pin;  // determine the channel
    		 SET_BIT(ADCSRA,ADSC); // start conversion

    		/*  while the conversion is not processed halt the processor
    		 (read the flag bit if = 0  conversion not finished)
    	       if = 1  conversion finished */
    	 	 while(GET_BIT(ADCSRA,ADIF) == 0);
    		 /* if conversion is processed set the flag to be cleared by AND gate.. cleared mean that there is no conversion
    		  * in this function the ADC will make one conversion and flag bit will cleared ..
    		  * (put function in while(1) to make ADC convert more than one time) */
    		 SET_BIT(ADCSRA,ADIF);

    	  uint16 value = ADCL | (ADCH <<8);
    	  return value;

      }
