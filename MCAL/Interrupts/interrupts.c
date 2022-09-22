/*
 * interrupts.c
 *
 * Created: 9/22/2022 1:02:05 PM
 *  Author: user
 */ 

#include "../../Utilities/registers.h"
#include "interrupts.h"

void enable_Global_Interrupts()
{
	SREG |= (1<<PIN7);      // enable global interrupts
}