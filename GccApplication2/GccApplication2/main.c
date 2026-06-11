/*
 * GccApplication2.c
 *
 * Created: 08-06-2026 14:26:09
 * Author : Bhgath cr
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB|=DDB5;
	DDRB|=DDB4;
    /* Replace with your application code */
    while (1) 
    {
		PORTB|=(1<<PB5);
		PORTB&=~(1<<PB4);
		_delay_ms(5000);
		PORTB&=~(1<<PB5);
		_delay_ms(5000);
		PORTB|=(1<<PB4);
		PORTB&=~(1<<PB5);
		_delay_ms(5000);
		PORTB&=~(1<<PB4);
		_delay_ms(5000);
		    }
}

