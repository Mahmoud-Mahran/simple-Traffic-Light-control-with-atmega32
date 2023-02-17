
#include "timer0.h"
#include "../DIO Driver/dio.h"
#include <avr/interrupt.h>
double overflows_counter = 0;
int Timer0_init(void)
{
	sei();
	TCCR0 = 0x00;
	TCNT0 = 0x00;
	return INIT_OK;
}
int Timer0_start(void)
{
	TCNT0 = 0;
	TCCR0 |= (1<<CS00);
	return TIMER_STARTED;
}
int Timer0_stop(void)
{
	TCCR0 = 0x00;
	TCNT0 = 0;
	return TIMER_STOPPED;
}
int Timer0_delay(double delay)
{	
	
	double overflows = 0;
	overflows = ceil((delay*F_CPU)/(256*PRESCALER)); // calculate needed overflows
	TIMSK |= (1<<TOIE0); //enable timer0 overflow interrupt
	TIFR |= (1<<TOV0); //clear timer0 overflow interrupt
	Timer0_start(); // start timer
	while (overflows_counter <= overflows && TCCR0 != 0x00); // wait till needed overflow count (delay period) while checking that the timer wasn't interruped / stopped
	if(overflows_counter < overflows)
	{
		overflows_counter = 0; // reset counter
		 return TIMER_INTERRUPTED; //error handling
		 
	}
	Timer0_stop(); // stop timer
	overflows_counter = 0; // reset counter
	return DELAY_COMPLETE; //error handling
	
}

ISR(TIMER0_OVF_vect)
{
	overflows_counter++;
}