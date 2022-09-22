/*
 * servo_motor.h
 *
 * Created: 9/19/2022 12:43:40 PM
 *  Author: user
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "../../Utilities/types.h"

/*
	enum represents servo motor errors
*/
typedef enum EN_servoMotorError_t
{
	SERVO_MOTOR_OK, SERVO_MOTOR_INITIALIZATION_FAILED, WRONG_ANGLE
}EN_servoMotorError_t;



EN_servoMotorError_t SERVO_MOTOR_init(uint8_t servoMotorPin , uint8_t servoMotorPort);
EN_servoMotorError_t SERVO_MOTOR_rotate(uint8_t servoMotorPin , uint8_t servoMotorPort, signed char angle);


#endif /* SERVO_MOTOR_H_ */