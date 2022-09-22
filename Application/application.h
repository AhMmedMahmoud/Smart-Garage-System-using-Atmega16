/*
 * application.h
 *
 * Created: 9/21/2022 2:11:51 PM
 *  Author: user
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_



#define servoMotor1Pin	PIN0
#define servoMotor1Port	Port_A

#define servoMotor2Pin	PIN1
#define servoMotor2Port	Port_A

#define pirSensor1Pin	PIN2
#define pirSensor1Port	Port_D

#define pirSensor2Pin	PIN3
#define pirSensor2Port	Port_D

#define led1Pin  PIN0
#define led1Port Port_B

#define led2Pin  PIN1
#define led2Port Port_B


#define prescaler					1024

#define entryGate_openTime			2
#define exitGate_openTime			2

#define overFlows_entryGate_openTime	(long long)(entryGate_openTime / (prescaler*256.0 /F_CPU))
#define overFlows_exitGate_openTime		(long long)(exitGate_openTime / (prescaler*256.0 /F_CPU))

#define initialValue_entryGate_openTime		(uint8_t)( 256 - (entryGate_openTime / (((double)prescaler/F_CPU)*overFlows_entryGate_openTime)) )
#define initialValue_exitGate_openTime		(uint8_t)( 256 - (exitGate_openTime / (((double)prescaler/F_CPU)*overFlows_exitGate_openTime)) )


typedef enum EN_entryGateState_t
{
	ENTRY_GATE_NOT_RAISED, ENTRY_GATE_RAISED, ENTRY_GATE_DISABLE
} EN_entryGateState_t;

typedef enum EN_exitGateState_t
{
	EXIT_GATE_NOT_RAISED, EXIT_GATE_RAISED, EXIT_GATE_DISABLE
} EN_exitGateState_t;

void setup();
void appStart();


#endif /* APPLICATION_H_ */