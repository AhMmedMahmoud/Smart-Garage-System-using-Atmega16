/*
 * interrupts.h
 *
 * Created: 9/22/2022 12:43:30 PM
 *  Author: user
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


#define ISR(INT_VECT) void INT_VECT() __attribute__ ((signal,used));    \
void INT_VECT()

#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_18

#define TIMER0_INT __vector_9
#define TIMER2_INT __vector_4

void enable_Global_Interrupts();


#endif /* INTERRUPTS_H_ */