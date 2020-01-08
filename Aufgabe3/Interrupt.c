#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

int led_red = 0; 
int led_yellow = 0;


void init() 
{
	DDRD |= (0 << PD2) | (0 << PD3); // PD2 und PD3 sind die ports mit den interrupts; wenn bit 0 = eingang, bit = 1 ausgang
	PORTD |= (1 << PD2) | (1 << PD3);
	DDRB |= (1 << PB0) | (1 << PB1);
}



int main(void)
{
	init();
	
	GICR = 0xc0; // enable external interrupts
	MCUCR = 0x0A; // set on falling edge
	
	sei(); // interrupts einschalten
	
	
	
	    
    while (1) 
    {
		if(led_red == 1)
		{
			PORTB = (1<<PB0);
			_delay_ms(100);
			PORTB = (0<<PB0);
			_delay_ms(100);
		}
		if(led_yellow == 1)
		{
			PORTB = (1<<PB1);
			_delay_ms(100);
			PORTB = (0<<PB1);
			_delay_ms(100);
		}
    }
}


ISR(INT0_vect)
{
	if(led_red == 1)
	{
		led_red = 0;	
	}
	else
	{
		led_red = 1;	
	}
	
	led_yellow = 0;
}

ISR(INT1_vect)
{
	if(led_yellow == 1)
	{
		led_yellow = 0;
	}
	else 
	{
		led_yellow = 1;	
	}
	led_red = 0;
}

