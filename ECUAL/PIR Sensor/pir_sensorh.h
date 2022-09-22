/*
 * pir_sensorh.h
 *
 * Created: 9/21/2022 2:35:32 PM
 *  Author: user
 */ 


#ifndef PIR_SENSORH_H_
#define PIR_SENSORH_H_

#include "../../Utilities/types.h"


/*
	enum represents pir sensor errors
*/
typedef enum EN_pirSensorError_t
{
	PIR_SENSOR_OK, PIR_SENSOR_INITIALIZATION_FAILED, PIR_SENSOR_READING_FAILED
}EN_pirSensorError_t;


EN_pirSensorError_t PIR_SENSOR_init( uint8_t sensorPin, uint8_t sensorPort);
EN_pirSensorError_t PIR_SENSOR_read( uint8_t sensorPin, uint8_t sensorPort, uint8_t *value);

#endif /* PIR_SENSORH_H_ */