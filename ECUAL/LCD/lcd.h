/*
 * lcd.h
 *
 * Created: 9/13/2022 1:34:44 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"


typedef struct ST_lcd_t
{
	uint8_t RS_pin,	 RS_port;
	uint8_t E_pin,	 E_port;
	uint8_t D0_pin,  D0_port;
	uint8_t D1_pin,  D1_port;
	uint8_t D2_pin,  D2_port;
	uint8_t D3_pin,  D3_port;
	uint8_t D4_pin,  D4_port;
	uint8_t D5_pin,  D5_port;
	uint8_t D6_pin,  D6_port;
	uint8_t D7_pin,  D7_port;
} ST_lcd_t;

typedef enum EN_type_t
{
	COMMAND, DATA
} EN_type_t;

typedef enum EN_instructions_t
{
	CLEAR_DISPLAY = 0X01,					 // clear screen , jump to first line position 0 
	RETURN_HOME = 0X02,						 // jump to first line position 0 
	ENTRY_MODE_SET = 0x06,					 // increment cursor position, no display shift
	DISPLAY_ON_OFF = 0X0C,					 // display on, cursor oFF, cursor blink OFF
	FUNCTION_SET = 0x38,					 // 8 bits data, 2 lines, 5x8 dots
	JUMP_TO_SECOND_LINE_POSITION_0 = 0XC0	 // jump to second line position 0 
} EN_instructions_t;


void LCD_init
(
ST_lcd_t *lcd,uint8_t RS, uint8_t RS_port, uint8_t E,  uint8_t E_port, uint8_t D0, uint8_t D0_port, uint8_t D1, uint8_t D1_port, uint8_t D2, uint8_t D2_port,
uint8_t D3, uint8_t D3_port, uint8_t D4, uint8_t D4_port, uint8_t D5, uint8_t D5_port, uint8_t D6, uint8_t D6_port, uint8_t D7, uint8_t D7_port
);

void LCD_pass(ST_lcd_t *lcd, uint8_t value, uint8_t type);

void LCD_writeString(ST_lcd_t *lcd, uint8_t str[]);

#endif /* LCD_H_ */