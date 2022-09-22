/*
 * registers.h
 *
 * Created: 9/13/2022 1:16:13 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"


// macros for ports
enum Ports {Port_A,Port_B,Port_C,Port_D};

// macros for pins
enum Pins  {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,};
	
// registers for DIO	
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

#define PORTB  *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

#define PORTC  *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

#define PORTD  *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

// registers for interrupt
#define SREG  *((volatile uint8_t*)0x5F)
#define MCUCR *((volatile uint8_t*)0x55)
#define GICR  *((volatile uint8_t*)0x5B)

// registers for timer0
#define TCNT0  *((volatile uint8_t*)0x52)
#define TCCR0  *((volatile uint8_t*)0x53)


// registers for timer1
#define TCNT2  *((volatile uint8_t*)0x44)
#define TCCR2  *((volatile uint8_t*)0x45)

// registers for timers
#define TIFR   *((volatile uint8_t*)0x58)
#define TIMSK  *((volatile uint8_t*)0x59)


// registers for ADC
#define ADMUX   *((volatile uint8_t*)0x27)
#define ADCSRA  *((volatile uint8_t*)0x26)
#define ADCH    *((volatile uint8_t*)0x25)
#define ADCL    *((volatile uint8_t*)0x24)
#define SFIOR   *((volatile uint8_t*)0x50)
 
 
#endif /* REGISTERS_H_ */