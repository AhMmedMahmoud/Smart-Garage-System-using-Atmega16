/*
 * pir_sensor.c
 *
 * Created: 9/21/2022 2:35:09 PM
 *  Author: user
 */ 

#include "pir_sensorh.h"
#include "../../MCAL/DIO/dio.h"

EN_pirSensorError_t PIR_SENSOR_init( uint8_t sensorPin, uint8_t sensorPort)
{
	switch ( DIO_init(sensorPin,sensorPort,IN) )
	{
		case OK:	return PIR_SENSOR_OK;
		default:	return PIR_SENSOR_INITIALIZATION_FAILED;
	}	
}

EN_pirSensorError_t PIR_SENSOR_read( uint8_t sensorPin, uint8_t sensorPort, uint8_t *value)
{
	switch( DIO_read(sensorPin,sensorPort,value) )
	{
		case OK: return PIR_SENSOR_OK;
		default: return PIR_SENSOR_READING_FAILED;
	}
	
}