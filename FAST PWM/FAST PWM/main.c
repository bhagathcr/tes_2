/*
 * FAST PWM.c
 *
 * Created: 09-06-2026 14:07:55
 * Author : Bhgath cr
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "PWM.h"

int main(void)
{
	pwm0a_config();
	pwm_duty(20);
    /* Replace with your application code */
    while (1) 
{}
	
}

