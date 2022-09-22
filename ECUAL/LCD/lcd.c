/*
 * lcd.c
 *
 * Created: 9/13/2022 1:34:44 PM
 *  Author: Ahmed Mahmoud Mohamed Ibrahim
 */  

#include "lcd.h"
#include "../../MCAL/Dio/dio.h"
//#include "../../MCAL/Timer0/timer0.h"
#include "../../Utilities/config.h"
#include <util/delay.h>

void LCD_init(ST_lcd_t *lcd, uint8_t RS, uint8_t RS_port, uint8_t E,  uint8_t E_port, uint8_t D0, uint8_t D0_port,
							 uint8_t D1, uint8_t D1_port, uint8_t D2, uint8_t D2_port, uint8_t D3, uint8_t D3_port,
							 uint8_t D4, uint8_t D4_port, uint8_t D5, uint8_t D5_port, uint8_t D6, uint8_t D6_port, uint8_t D7, uint8_t D7_port)
{
	lcd->D0_pin = D0;
	lcd->D1_pin = D1;
	lcd->D2_pin = D2;
	lcd->D3_pin = D3;
	lcd->D4_pin = D4;
	lcd->D5_pin = D5;
	lcd->D6_pin = D6;
	lcd->D7_pin = D7;
	lcd->RS_pin = RS;
	lcd->E_pin = E;
	
	lcd->D0_port = D0_port;
	lcd->D1_port = D1_port;
	lcd->D2_port = D2_port;
	lcd->D3_port = D3_port;
	lcd->D4_port = D4_port;
	lcd->D5_port = D5_port;
	lcd->D6_port = D6_port;
	lcd->D7_port = D7_port;
	lcd->RS_port = RS_port;
	lcd->E_port = E_port;
	
	DIO_init(lcd->D0_pin,lcd->D0_port,OUT);
	DIO_init(lcd->D1_pin,lcd->D1_port,OUT);
	DIO_init(lcd->D2_pin,lcd->D2_port,OUT);
	DIO_init(lcd->D3_pin,lcd->D3_port,OUT);
	DIO_init(lcd->D4_pin,lcd->D4_port,OUT);
	DIO_init(lcd->D5_pin,lcd->D5_port,OUT);
	DIO_init(lcd->D6_pin,lcd->D6_port,OUT);
	DIO_init(lcd->D7_pin,lcd->D7_port,OUT);
	DIO_init(lcd->RS_pin,lcd->RS_port,OUT);
	DIO_init(lcd->E_pin,lcd->E_port,OUT);
	
	
	LCD_pass(lcd, ENTRY_MODE_SET, COMMAND);
	LCD_pass(lcd, DISPLAY_ON_OFF,COMMAND);
	LCD_pass(lcd, FUNCTION_SET,COMMAND);
	LCD_pass(lcd, CLEAR_DISPLAY,COMMAND);
}	



void LCD_pass(ST_lcd_t *lcd, uint8_t value, uint8_t type)
{
	DIO_write(lcd->E_pin,lcd->E_port,LOW);
	
	if(type == COMMAND)
		DIO_write(lcd->RS_pin,lcd->RS_port,LOW);
	else if(type == DATA)
		DIO_write(lcd->RS_pin,lcd->RS_port,HIGH);
	
	
	DIO_write(lcd->D0_pin,lcd->D0_port,(value & (1<<PIN0)) >> PIN0 );
	DIO_write(lcd->D1_pin,lcd->D1_port,(value & (1<<PIN1)) >> PIN1 );
	DIO_write(lcd->D2_pin,lcd->D2_port,(value & (1<<PIN2)) >> PIN2 );
	DIO_write(lcd->D3_pin,lcd->D3_port,(value & (1<<PIN3)) >> PIN3 );
	DIO_write(lcd->D4_pin,lcd->D4_port,(value & (1<<PIN4)) >> PIN4 );
	DIO_write(lcd->D5_pin,lcd->D5_port,(value & (1<<PIN5)) >> PIN5 );
	DIO_write(lcd->D6_pin,lcd->D6_port,(value & (1<<PIN6)) >> PIN6 );
	DIO_write(lcd->D7_pin,lcd->D7_port,(value & (1<<PIN7)) >> PIN7 );
	
	
	
	DIO_write(lcd->E_pin, lcd->E_port,HIGH);
	//timer0_delay_uS(1);
	_delay_us(1);
	DIO_write(lcd->E_pin, lcd->E_port,LOW);
	//timer0_delay_uS(1);
	_delay_ms(2);
}

void LCD_writeString(ST_lcd_t *lcd, uint8_t str[])
{
	//int i = 0;
	while(*str != '\0')
	{
		LCD_pass(lcd, *(str++) ,DATA);
	}
}

