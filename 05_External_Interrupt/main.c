#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT0_vect)
{
	if(PIND & 0x04)
	{
		PORTB &= ~(0x01 << PORTB5);
	}
	else
	{
		PORTB |= 0x01 << PORTB5;
	}
}

int main(void)
{
	DDRB |= 0x01 << DDB5;
	PORTD |= 0x01 << PORTD2;
	
	EIMSK |= 0x01 << INT0;
	EICRA |= 0x01 << ISC00;
	sei();
	/* Replace with your application code */
	while (1)
	{
		
	}
}

