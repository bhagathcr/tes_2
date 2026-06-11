/*
 * Blink.c
 *
 * Created: 08-06-2026 11:27:59
 * Author : Bhgath cr
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0b00100000;
    /* Replace with your application code */
    while (1) 
    {
		PORTB=0b00100000;
		_delay_ms(1000);
		PORTB=0b00000000;
		_delay_ms(1000);
    }
}

