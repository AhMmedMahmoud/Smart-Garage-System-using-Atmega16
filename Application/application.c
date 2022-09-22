/*
 * application.c
 *
 * Created: 9/21/2022 2:11:37 PM
 *  Author: user
 */ 

#include "../Utilities/registers.h"
#include "../Utilities/config.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/Timer2/timer2.h"
#include "../MCAL/Interrupts/interrupts.h"
#include "../ECUAL/Servo Motor/servo_motor.h"
#include "../ECUAL/Led/led.h"
#include "../ECUAL/LCD/lcd.h"
#include "../ECUAL/PIR Sensor/pir_sensorh.h"
#include "application.h"
#include <stdio.h>

ST_lcd_t lcd;

uint8_t entryGateSensorRead = 0;
uint8_t exitGateSensorRead = 0;
uint8_t buttonRead = 0;

long long overFlows_timer0 = 0;
long long overFlows_timer2 = 0;

uint8_t state1 = ENTRY_GATE_NOT_RAISED;
uint8_t state2 = EXIT_GATE_NOT_RAISED;

uint8_t carsNumber = 0;
char textToDisplay[17];

ISR(TIMER0_INT)
{
	if(overFlows_timer0 == overFlows_entryGate_openTime-1)
	{	
		Timer0_stop();				 
		Timer0_disableOverflow_Interrupt();
		
		SERVO_MOTOR_rotate(servoMotor1Pin, servoMotor1Port, 0);		// close gate
		LED_off(led1Pin,led1Port);
		overFlows_timer0 = 0;
		state1 = ENTRY_GATE_NOT_RAISED;
		
		LCD_pass(&lcd,CLEAR_DISPLAY,COMMAND);
		sprintf(textToDisplay, "Cars number: %d", ++carsNumber);
		LCD_writeString(&lcd,(uint8_t*)textToDisplay);
		
		if(carsNumber < 3)
		{
		LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
		LCD_writeString(&lcd,(uint8_t*)"Enter is allowed");
		}
	}
	else
	{
		Timer0_setCurrentValue(initialValue_entryGate_openTime);
		overFlows_timer0++;
	}
}

ISR(TIMER2_INT)
{
	if(overFlows_timer2 == overFlows_exitGate_openTime-1)
	{
		Timer2_stop();				
		Timer2_disableOverflow_Interrupt();
		
		SERVO_MOTOR_rotate(servoMotor2Pin, servoMotor2Port, 0);		// close gate
		LED_off(led2Pin,led2Port);
		overFlows_timer2 = 0;
		state2 = EXIT_GATE_NOT_RAISED;
		
		LCD_pass(&lcd,CLEAR_DISPLAY,COMMAND);
		sprintf(textToDisplay, "Cars number: %d", --carsNumber);
		LCD_writeString(&lcd,(uint8_t*)textToDisplay);
		
		LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
		LCD_writeString(&lcd,(uint8_t*)"Enter is allowed");
	}
	else
	{
		Timer2_setCurrentValue(initialValue_exitGate_openTime);
		overFlows_timer2++;
	}
}


void setup()
{
	Timer0_init(TIMER0_NORMAL_MODE, prescaler, DISABLE_OCO_PIN);
	Timer2_init(TIMER0_NORMAL_MODE,prescaler,DISABLE_OCO_PIN);
	
	SERVO_MOTOR_init(servoMotor1Pin, servoMotor1Port);
	SERVO_MOTOR_init(servoMotor2Pin, servoMotor2Port);
	
	SERVO_MOTOR_rotate(servoMotor1Pin, servoMotor1Port, 0);
	SERVO_MOTOR_rotate(servoMotor2Pin, servoMotor2Port, 0);
	
	PIR_SENSOR_init(pirSensor1Pin,pirSensor1Port);
	PIR_SENSOR_init(pirSensor2Pin,pirSensor2Port);
	
	
	LED_init(led1Pin,led1Port);	
	LED_init(led2Pin,led2Port);	
	LCD_init(&lcd,PIN0,Port_D,PIN1,Port_D,PIN0,Port_C,PIN1,Port_C,PIN2,Port_C,PIN3,Port_C,PIN4,Port_C,PIN5,Port_C,PIN6,Port_C,PIN7,Port_C);
	
	enable_Global_Interrupts();
	Timer0_setCurrentValue(initialValue_entryGate_openTime);
	Timer2_setCurrentValue(initialValue_exitGate_openTime);
	
	
	sprintf(textToDisplay, "Cars number: %d", carsNumber);
	LCD_writeString(&lcd,(uint8_t*)textToDisplay);
	LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
	LCD_writeString(&lcd,(uint8_t*)"Enter is allowed");
}


void appStart()
{
	PIR_SENSOR_read(pirSensor1Pin,pirSensor1Port, &entryGateSensorRead);
	PIR_SENSOR_read(pirSensor2Pin,pirSensor2Port, &exitGateSensorRead);
	if(exitGateSensorRead == 1 && state2 == EXIT_GATE_NOT_RAISED)
	{
		SERVO_MOTOR_rotate(servoMotor2Pin, servoMotor2Port, -90);		// open gate
		LED_on(led2Pin,led2Port);										// light led gate1
		
		Timer2_enableOverflow_Interrupt();
		Timer2_start();
		state2 = EXIT_GATE_RAISED;
	}
	else if(carsNumber == 3)
	{
		LCD_pass(&lcd,JUMP_TO_SECOND_LINE_POSITION_0,COMMAND);
		LCD_writeString(&lcd,(uint8_t*)"Garge is Full");
	}
	else if(entryGateSensorRead == 1 && state1 == ENTRY_GATE_NOT_RAISED)
	{	
		SERVO_MOTOR_rotate(servoMotor1Pin, servoMotor1Port, -90);		// open gate1
		LED_on(led1Pin,led1Port);										// light led gate1
				
		Timer0_enableOverflow_Interrupt();
		Timer0_start();		
		state1 = ENTRY_GATE_RAISED;
	}
	
	
}