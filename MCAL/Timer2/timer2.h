/*
 * timer2.h
 *
 * Created: 8/23/2022 8:41:43 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include  "../../Utilities/types.h"


/* available clock signals for Timer2  */
#define TIMER2_CLOCK_IS_NO_CLOCK						0
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1      1
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_8      2
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_32     3
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_64     4
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_128    5
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_256    6
#define TIMER2_CLOCK_IS_CPU_CLOCK_WITH_PRESCALER_1024   7


typedef enum EN_timer2Units_t
{
	TIMER2_MICROSECOND, TIMER2_MILLISECOND, TIMER2_SECOND
}EN_timer2Units_t;


/*
	enum represents overflow state
*/
typedef enum EN_timer2_OverFlowState_t
{
	TIMER2_NOTOVERFLOW , TIMER2_OVERFLOW
}EN_timer2_OverFlowState_t;


// functions prototypes
void Timer2_init(uint8_t mode, uint16_t prescaler, uint8_t oc_state);
void Timer2_start();
void Timer2_stop();
void Timer2_clearOverFlowFlag();
void Timer2_setCurrentValue(uint8_t value);
EN_timer2_OverFlowState_t Timer2_checkOverFlow();
void Timer2_enableOverflow_Interrupt();
void Timer2_disableOverflow_Interrupt();



/* pins of register TCCR2 */
#define CS20  PIN0
#define CS21  PIN1
#define CS22  PIN2
#define WGM21 PIN3
#define COM20 PIN4
#define COM21 PIN5
#define WGM20 PIN6


/* some pins of register TIFR for Timer2 */
#define TOV2  PIN6
#define OCF2  PIN7


/* some pins of register TIMSK for Timer2 */
#define  TOIE2 PIN6
#define  OCIE2 PIN7


#endif /* TIMER2_H_ */