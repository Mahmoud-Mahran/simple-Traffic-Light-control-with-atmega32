
#include "button.h"
int button_init(uint8_t port_number, uint8_t pin_number, uint8_t mode, uint8_t value)
{
	if (DIO_init(port_number, pin_number, mode) == DIO_OK && DIO_write(port_number, pin_number, value) == DIO_OK)
	{
		return BUTTON_OK;
	}
	return BUTTON_INIT_FAILED;
}
void button_interrupt_EN(void (*func) (void))
{
	int0_init();	//enable external interrupt0
	my_CB = func;	//get the function called on button press
}

// interrupt service routine
ISR(INT0_vect)
{
	my_CB();
}