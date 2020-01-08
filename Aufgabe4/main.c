#include <avr/io.h>
#include <avr/interrupt.h>


// default system clock is 1MHz

// need 8 bit Timer and 1024 prescaler = ~1ms; than need preload (TCNT0) of 255;


volatile int32_t millisec = 0;
// volatile int32_t sec = 0; // not needed here

void waitFor (int32_t ms) 
{
	int32_t sth = ms + millisec;
	while(sth >= millisec)
	{
		/*
		doing it with if statement has the possibility of missing the target time,
		so doing it in the statement of the loop gets around this.
		
		if(sth >= millisec)
		{
		}
		else break;
		*/
	}
}

void waitUntil(int32_t ms)
{
	while (millisec <= ms)
	{
		/*
		doing it with if statement has the possibility of missing the target time,
		so doing it in the statement of the loop gets around this.
		
		if(millisec <= ms)
		{
		}
		else break;*/
	}
}

int main(void)
{
   DDRD |= (1<<PD3); // PD3 as output
   
   
   TCCR0 |= (1<<CS02) | (1<<CS00); // prescaler 1024
   TCNT0 = 255; // preload
   
   TIMSK |= (1 << TOIE0); // enable timer overflow interrupt 
   
   sei(); // enable interrupts
   
   waitUntil(1000);
   
   while(1)
   {
	   // blink in one second intervals
	   PORTD = (1 << PD3); 
	   waitFor(1000);
	   PORTD = (0 << PD3);
	   waitFor(1000);
	   
   }  
}


ISR(TIMER0_OVF_vect)
{
	millisec++; // count up milliseconds
	TCNT0 = 255; // set preload again
	
}
