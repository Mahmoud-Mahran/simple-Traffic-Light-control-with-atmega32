
#include "int0.h"

void int0_init(void)
{
	
	sei();
	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
		
}

