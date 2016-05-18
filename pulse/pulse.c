#include <avr/io.h>
#include <util/delay.h>

/*
** Hello, World! for the AVR Tiny Programmer and ATtiny85 
**
** This USB programmer features an LED on PB0, which we 
** slowly pulse using PWM as an example here.
**
** Copyright (C) 2015, Majdi S. Abbas, <majdi@majdi.net>
**
*/

int main(void)
{
	int i = 0;

	DDRB |= (1 << PB0); /* Set PB0 for output. */

	TCCR0B |= (1 << CS01); /* Set timer0 prescaler to clock/8 */

	TCCR0A |= (1 << WGM01) | (1 << WGM00);  /* Enable Fast PWM */

	/*
	** This sets the output compare register on PB0, 
	** which is required for PWM output.
	*/
	TCCR0A |= (1 << COM0A1); 

	while (1)
  	{
		for(i=0;i<255;i++)
		{
			OCR0A = i;
			_delay_us(333);
		}

		_delay_ms(5); /* Hold at peak */

		for(i=255;i>0;i--)
		{
			OCR0A = i;
			_delay_us(333);
		}
		
		TCCR0A ^= (1 << COM0A1); /* Toggle OCR (PWM) off on PB0 */
		_delay_ms(250);
		TCCR0A ^= (1 << COM0A1); /* Toggle OCR (PWM) back on */
  	}

	return(0);
}
