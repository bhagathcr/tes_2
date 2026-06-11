/*
 * PWM.c
 *
 * Created: 09-06-2026 15:19:33
 *  Author: Bhgath cr
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void pwm0a_config()
{
	
	DDRD=(1<<DDD6);
	TCCR0A|=(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	TCCR0A|=(1<<COM0A1);
	TCCR0A|=(1<<COM0A0);
	TCCR0B&=~(1<<CS02);
	TCCR0B|=(1<<CS01);
	TCCR0B|=(1<<CS00);
}
void pwm_duty(int duty)
{
	int a=(duty*256)/100;
	OCR0A=a;
}