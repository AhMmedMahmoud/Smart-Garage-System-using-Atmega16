/*
 * timer0.h
 *
 * Created: 9/19/2022 3:54:33 PM
 *  Author: user
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/types.h"



/* pins of register TCCR0 */ 
#define CS00  PIN0
#define CS01  PIN1
#define CS02  PIN2
#define WGM01 PIN3
#define COM00 PIN4
#define COM01 PIN5
#define WGM00 PIN6
#define F0C0  PIN7

/* some pins of register TIFR for Timer0 */
#define TOV0	PIN0
#define OCF0	PIN1

/* available clock signals for Timer0  */
#define TIMER0_CLOCK_IS_NO_CLOCK						0
#define TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1      1
#define TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_8      2
#define TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_64     3
#define TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_256    4
#define TIMER0_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1024   5


/* available modes for Timer0 */
#define TIMER0_NORMAL_MODE		0
#define TIMER0_CTC_MODE			1
#define TIMER0_PWM_MODE			2
#define TIMER0_FAST_PWM_MODE	3

#define DISABLE_OCO_PIN		0

#define OVERFLOW     0
#define NO_OVERFLOW	 1



typedef enum EN_timer0Units_t
{
	MICROSECOND, MILLISECOND, SECOND
}EN_timer0Units_t;

void Timer0_init(uint8_t mode, uint16_t prescaler, uint8_t oc_state);
void Timer0_start();
void Timer0_stop();
uint8_t Timer0_checkOverFlow();
void Timer0_clearOverFlowFlag();
void Timer0_test();
void Timer0_delay(long long amount, EN_timer0Units_t unit);
void Timer0_setCurrentValue(uint8_t value);
void Timer0_enableOverflow_Interrupt();
void Timer0_disableOverflow_Interrupt();

#endif /* TIMER0_H_ */