/*
 *  memmap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

// PORTS interface
#define PORTA (*((volatile uint8*)0x3B ))
#define DDRA (*((volatile uint8*)0x3A ))
#define PINA (*((volatile uint8*)0x39))
#define PORTB (*((volatile uint8*)0x38 ))
#define DDRB (*((volatile uint8*)0x37 ))
#define PINB (*((volatile uint8*)0x36))
#define PORTC (*((volatile uint8*)0x35 ))
#define DDRC (*((volatile uint8*)0x34 ))
#define PINC (*((volatile uint8*)0x33))
#define PORTD (*((volatile uint8*)0x32 ))
#define DDRD (*((volatile uint8*)0x31 ))
#define PIND (*((volatile uint8*)0x30))

// ADC registers..
#define ADCMUX (*((volatile uint8*)0x27))
#define ADCSRA (*((volatile uint8*)0x26))
#define ADCH (*((volatile uint8*)0x25))
#define ADCL (*((volatile uint8*)0x24))
#define SFIOR (*((volatile uint8*)0x50))

// External Interrupt Register..
#define MCUCR (*((volatile uint8*)0x55))
#define MCUCSR (*((volatile uint8*)0x54))
#define SREG (*((volatile uint8*)0x5F))
#define GICR (*((volatile uint8*)0x5B))
#define GIFR (*((volatile uint8*)0x5A))

// Timer0 Registers....
#define TCNT0 (*((volatile uint8*)0x52))
#define TCCR0 (*((volatile uint8*)0x53))
#define TIFR (*((volatile uint8*)0x58))
#define TIMSK (*((volatile uint8*)0x59))
#define OCR0 (*((volatile uint8*)0x5C))

// Timer1 Registers....
#define TCCR1A (*((volatile uint8*)0x4F))
#define TCCR1B (*((volatile uint8*)0x4E))
#define TCNT1H (*((volatile uint8*)0x4D))
#define TCNT1L (*((volatile uint8*)0x4C))
#define OCR1AH (*((volatile uint8*)0x4B))
#define OCR1AL (*((volatile uint8*)0x4A))
#define OCR1BH (*((volatile uint8*)0x49))
#define OCR1BL (*((volatile uint8*)0x48))
#define ICR1H (*((volatile uint8*)0x47))
#define ICR1L (*((volatile uint8*)0x46))

//watch dog timer register .
#define WDTCR (*((volatile uint8*)0x41))

// USART REGSITERs...
#define UBRRH (*((volatile uint8*)0x40))
#define UCSRC (*((volatile uint8*)0x40))
#define UDR (*((volatile uint8*)0x2C))
#define UCSRA (*((volatile uint8*)0x2B))
#define UCSRB (*((volatile uint8*)0x2A))
#define UBRRL (*((volatile uint8*)0x29))







#endif /* MEMMAP_H_ */
