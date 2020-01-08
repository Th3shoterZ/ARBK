#include <avr/io.h>
#define F_CPU 1000000UL  
#include <util/delay.h>


int main(void)
{	
	DDRB = 0b00000111;
		
	while (1) 
    {
		
		
		PORTB = 1;
		_delay_ms(200);
		PORTB = 2;
		_delay_ms(200);
		PORTB = 4;
		_delay_ms(200);
		PORTB = 2;
		_delay_ms(200);
    }
	return 0;
}

