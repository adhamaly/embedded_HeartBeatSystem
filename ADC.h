/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef ADC_H_
#define ADC_H_

typedef enum{

	ADC0  = 0X00,
	ADC1  = 0X01,
	ADC2  = 0X02,
	ADC3  = 0X03,
	ADC4  = 0X04,
	ADC5  = 0X05,
	ADC6  = 0X06,
	ADC7  = 0X07

}ADC_CHANNEL_T;

typedef enum{
	MUX0 = 0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1
}ADCMUX_R;
typedef enum{
	ADPS0 = 0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN
}ADCSRA_R;
typedef enum{
	ADTS0 = 5,
	ADTS1,
	ADTS2
}SFIOR_R;


 void ADC_Int(void);
 void ADC_StartSingleConversion(ADC_CHANNEL_T pin);
 void ADC_AutoTriggerConversion(ADC_CHANNEL_T pin);
 uint16 ADC_GETVALUE(void);
 uint16 Read_Analog(ADC_CHANNEL_T pin);


#endif /* ADC_H_ */
