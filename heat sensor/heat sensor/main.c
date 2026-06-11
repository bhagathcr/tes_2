/*
 * Heat Sensor with LM35 and L293D
 * PB5 -> L293D IN1
 * PB4 -> L293D IN2
 * PB3 -> LED
 * PC3 -> LM35 Output (ADC3)
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

int main(void)
{
    lcd_init();

    /* Outputs */
   /* Outputs */
   DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB3);

    /* ADC3 Input */
    DDRC &= ~(1 << PC3);

    /* ADC Setup */
    ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0);
    // AVCC reference, ADC3 selected

    ADCSRA = (1 << ADEN) |
             (1 << ADPS2) |
             (1 << ADPS1) |
             (1 << ADPS0);

    while (1)
    {
        /* Start ADC Conversion */
        ADCSRA |= (1 << ADSC);

        /* Wait until conversion complete */
        while (ADCSRA & (1 << ADSC));

        uint16_t adcRead = ADC;

        /* LM35 Temperature */
        float temperature = (adcRead * 500.0) / 1024.0;

        /* LCD Display */
        lcd_set_cursor(0, 0);
        lcd_print("Temperature:");

        lcd_set_cursor(1, 0);
        lcd_print_float(temperature);
        lcd_print(" C   ");

        if (temperature > 50.0)
        {
	        /* Motor ON */
	        PORTB |= (1 << PB7);     // IN1 = HIGH
	        PORTB &= ~(1 << PB6);    // IN2 = LOW

	        /* Blink LED */
	        PORTB ^= (1 << PB3);

	        _delay_ms(500);
        }
        else
        {
	        /* Motor OFF */
	        PORTB &= ~(1 << PB7);
	        PORTB &= ~(1 << PB6);

	        /* LED OFF */
	        PORTB &= ~(1 << PB3);

	        _delay_ms(500);
        }
    }

    return 0;
}