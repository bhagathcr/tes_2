/*
 * LCD DISPLAY2.c
 *
 * Created: 10-06-2026 12:18:54
 * Author : Bhgath cr
 */ 
#define F_CPU 160000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
int main(void)
{
   lcd_init();
     
    while (1) 
    {
		lcd_set_cursor(0,0);
		lcd_print("hello");
		lcd_set_cursor(1,0);
		float a=22.22;
		lcd_print_float(a);
		_delay_ms(5000);
		lcd_clear();
		_delay_ms(1000);
    }
}

