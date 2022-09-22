/*
 * timer0.c
 *
 * Created: 9/19/2022 3:54:14 PM
 *  Author: user
 */ 

#include "timer0.h"
#include "../../Utilities/registers.h" 
#include "../../Utilities/types.h" 
#include "../../Utilities/config.h"
#include <math.h>




uint8_t Timer0_clock;
uint16_t Timer0_prescaler;

double T_tick;
double T_max_Delay;

uint8_t Timer0_initialValue;
long long Timer0_overFlows;

/*

* for first argument (mode),   you can pass one of these macros (NORMAL_MODE, CTC_MODE, PWM_MODE, FAST_PWM_MODE)

* for second argument (clock), you can pass one of these macros (CPU_CLOCK_WITH_PRESCALER_1,
  CPU_CLOCK_WITH_PRESCALER_8, CPU_CLOCK_WITH_PRESCALER_64, CPU_CLOCK_WITH_PRESCALER_256,
  CPU_CLOCK_WITH_PRESCALER_1024, EXTERNAL_CLOCK_ON_FALLING_EDGE, EXTERNAL_CLOCK_ON_RISING_EDGE)
  
* for third argument (oc_state), you can pass one of these macros(DISABLE_OCO_PIN)

*/
void Timer0_init(uint8_t mode, uint16_t prescaler, uint8_t oc_state)
{
	switch(prescaler)
	{
		case 1:		Timer0_prescaler = 1;		Timer0_clock = TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1;		break;
		case 8:		Timer0_prescaler = 8;		Timer0_clock = TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_8;		break;
		case 64:	Timer0_prescaler = 64;		Timer0_clock = TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_64;		break;
		case 256:	Timer0_prescaler = 256;		Timer0_clock = TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_256;	break;
		case 1024:	Timer0_prescaler = 1024;	Timer0_clock = TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1024;	break;
	}
	
	T_tick = (double)Timer0_prescaler / F_CPU;
	T_max_Delay = T_tick * 256;
	
	// mode
	TCCR0 = (   TCCR0 & ~( (1<<WGM00) | (1<<WGM01) )   ) | mode;
	// oc pin
	TCCR0 = (   TCCR0 & ~( (1<<COM00) | (1<<COM01) )   ) | oc_state;
}


void Timer0_start()
{
	TCCR0 = (   TCCR0 & ~( (1<<CS02) | (1<<CS01) | (1<<CS00) )   ) | Timer0_clock; 
}
void Timer0_stop()
{
	TCCR0 = (   TCCR0 & ~( (1<<CS02) | (1<<CS01) | (1<<CS00) )   ) | TIMER0_CLOCK_IS_NO_CLOCK; 
}
uint8_t Timer0_checkOverFlow()
{
	if( ( TIFR & (1<<TOV0) ) == 0)
		return NO_OVERFLOW;
	else
		return OVERFLOW;
}
void Timer0_clearOverFlowFlag()
{
	TIFR |= (1<<TOV0);
}


/*
this function uses to test timer0 by running it at its longest time 
*/
void Timer0_test()
{
	Timer0_start();
	TCNT0 = 0;
	while(Timer0_checkOverFlow() == OVERFLOW);
	Timer0_clearOverFlowFlag();
	Timer0_stop();
}


/*
    error ~ 4200 micoSeconds  or  0.0042 seconds
*/
void Timer0_delay(long long amount, EN_timer0Units_t unit)
{	
	double T_delay = 0;
	
	if(unit == SECOND)
		T_delay = amount;
	if(unit == MILLISECOND)
		T_delay = amount/1000.0;
	else if(unit == MICROSECOND)
		T_delay = (double)amount/1000000;
	
				
	if(T_delay <= T_max_Delay)
	{
		Timer0_initialValue = (T_max_Delay - T_delay) / T_tick;
		Timer0_overFlows = 1;
	}
	else
	{
		Timer0_overFlows = (long long)(ceil(T_delay / T_max_Delay)); 
		Timer0_initialValue = (uint8_t)(256 - (T_delay / (T_tick*Timer0_overFlows)));
	}
	
	int i;
	Timer0_start();
	for(i = 0; i<Timer0_overFlows; i++)
	{		
		TCNT0 = Timer0_initialValue;
		while(Timer0_checkOverFlow() == NO_OVERFLOW);
		Timer0_clearOverFlowFlag();	
	}
	Timer0_stop();	
}


/*
	set timer0 curernt value
*/
void Timer0_setCurrentValue(uint8_t value)
{
	TCNT0 = value;
}



void Timer0_enableOverflow_Interrupt()
{
	TIMSK |= (1<<PIN0);		// enable timer0 overflow interrupt
}


void Timer0_disableOverflow_Interrupt()
{
	TIMSK &= ~(1<<PIN0);		 // disable timer0 overflow interrupt
}