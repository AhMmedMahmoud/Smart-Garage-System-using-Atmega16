/*
 * timer2.c
 *
 * Created: 8/23/2022 8:42:00 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#include "timer2.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/config.h"
#include <math.h>

uint8_t Timer2_clock;
uint16_t Timer2_prescaler;

double T_tick;
double T_max_Delay;

uint8_t Timer2_initialValue;
long long Timer2_overFlows;


void Timer2_init(uint8_t mode, uint16_t prescaler, uint8_t oc_state)
{	
	switch(prescaler)
	{
		case 1:		Timer2_prescaler = 1;		Timer2_clock = TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1;		break;
		case 8:		Timer2_prescaler = 8;		Timer2_clock = TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_8;		break;
		case 64:	Timer2_prescaler = 64;		Timer2_clock = TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_64;		break;
		case 256:	Timer2_prescaler = 256;		Timer2_clock = TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_256;	break;
		case 1024:	Timer2_prescaler = 1024;	Timer2_clock = TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1024;	break;
	}
	
	T_tick = (double)Timer2_prescaler / F_CPU;
	T_max_Delay = T_tick * 256;
	
	
	TCCR2 = ( TCCR2 & ~( (1<<WGM20) | (1<<WGM21) ) ) | mode;
	TCCR2 = ( TCCR2 & ~( (1<<COM20) | (1<<COM21) ) ) | oc_state;	
}



void Timer2_start()
{
	TCCR2 = (   TCCR2 & ~( (1<<CS20) | (1<<CS21) | (1<<CS22) )   ) | Timer2_clock; 
}






/*
	 clock source to be used by Timer2  is  No clock source
*/
void Timer2_stop()
{
	TCCR2 &= ~((1<<CS20) | (1<<CS21) | (1<<CS22));             // timer clock is disconnected --> disable timer
}



/*
	this functions clear overflow flag
*/
void Timer2_clearOverFlowFlag()
{
	TIFR |= (1<<TOV2);            // clear overflow flag by writting 1   (commom bug)
}



/*
	set timer2 curernt value
*/
void Timer2_setCurrentValue(uint8_t value)
{
	TCNT2 = value;
}


/*
	check if there is overflow or no overflow
	if there , return OVERFLOW
	else retunr NOTOVERFLOW
*/
EN_timer2_OverFlowState_t Timer2_checkOverFlow()
{
	return ((((TIFR & (1<<TOV2) )>>TOV2) == 1) ? TIMER2_OVERFLOW : TIMER2_NOTOVERFLOW);
}


void Timer2_enableOverflow_Interrupt()
{
	TIMSK |= (1<<PIN6);			// enable timer2 overflow interrupt
}


void Timer2_disableOverflow_Interrupt()
{
	TIMSK &= ~(1<<PIN6);		 // disable timer2 overflow interrupt
}
