/*
 * servo_motor.c
 *
 * Created: 9/19/2022 12:43:23 PM
 *  Author: user
 */ 

#include "servo_motor.h"
#include "../../MCAL/DIO/dio.h"
#include "../../Utilities/config.h"
#include <util/delay.h>


EN_servoMotorError_t SERVO_MOTOR_init(uint8_t servoMotorPin , uint8_t servoMotorPort)
{
	switch ( DIO_init(servoMotorPin,servoMotorPort,OUT) )
	{
		case OK:	return SERVO_MOTOR_OK;
		default:	return SERVO_MOTOR_INITIALIZATION_FAILED;
	}
}

EN_servoMotorError_t SERVO_MOTOR_rotate(uint8_t servoMotorPin , uint8_t servoMotorPort, signed char angle)
{
	switch( angle )
	{
		
		case -90:
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(955);
				_delay_us(915.8);
				DIO_write(servoMotorPin, servoMotorPort, LOW);
				_delay_ms(20-0.9);
				return SERVO_MOTOR_OK;
		
		case -45:
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(1205);
				_delay_us(1244.2);
				DIO_write(servoMotorPin, servoMotorPort, LOW);
				_delay_ms(20-1.205);
				return SERVO_MOTOR_OK;
						
		case 0:
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(1455);
				_delay_us(1494.3);
				DIO_write(servoMotorPin, servoMotorPort, LOW);
				_delay_ms(20-1.455);
				return SERVO_MOTOR_OK;
		
		case 45:
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(1705);
				_delay_us(1744.3);
				DIO_write(servoMotorPin, servoMotorPort, LOW);				
				_delay_ms(20-1.705);
				return SERVO_MOTOR_OK;
						
		case 90:		
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(1955);
				_delay_us(1994.3);
				DIO_write(servoMotorPin, servoMotorPort, LOW);
				_delay_ms(20-1.955);
				return SERVO_MOTOR_OK;		
				
		case 10:
				DIO_write(servoMotorPin, servoMotorPort, HIGH);
				//_delay_us(1455 + 5.55*angle);
				DIO_write(servoMotorPin, servoMotorPort, LOW);
				_delay_ms(20-1.455);
				return SERVO_MOTOR_OK;					
	}
	return WRONG_ANGLE;
}