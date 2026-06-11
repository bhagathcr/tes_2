/*
 * ADC.c
 *
 * Created: 10-06-2026 15:00:50
 * Author : Bhgath cr
 */ 
#define F_CPU 160000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD|=(1<<PC3);
	ADMUX&=~(1<<REFS1);
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADPS2);
	ADCSRA|=(1<<ADPS1);
	ADCSRA|=(1<<ADPS0);
	ADCSRA|=(1<<ADEN);
	ADCSRA|=(1<<ADSC);
	ADCSRA|=(1<<ADIF);
	ADMUX|=(1<<MUX1);
	ADMUX|=(1<<MUX0);
	
	
    /* Replace with your application code */
    while (1) 
    { 
		
    }
}

