
#include "led.h"

int LED_init(LEDS *led)
{
	if (DIO_init(led->port, led->pin, OUTPUT) == DIO_OK)
	{
		return	LED_OK;
	}
	return LED_OPERATION_FAILED;
}
int LED_on(LEDS *led)
{
	if (DIO_write(led->port, led->pin, HIGH) == DIO_OK)
		{
			led->state = 2;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
}
int LED_off(LEDS *led)
{
	if (DIO_write(led->port, led->pin, LOW) == DIO_OK)
		{
			led->state = 1;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
}
int LED_toggle(LEDS *led)
{
	if (DIO_toggle(led->port, led->pin) == DIO_OK)
		{
			if(led->state == 1) led->state = 2;
			if(led->state == 2) led->state = 1;
			return	LED_OK;
		}
	return LED_OPERATION_FAILED;
	
}
int LED_blink(double delay, double duration, LEDS *led1, LEDS *led2)
{
	double temp = 0;
	while(temp <= duration)
	{
		if (LED_toggle(led1) == LED_OPERATION_FAILED) return LED_OPERATION_FAILED;
		if (LED_toggle(led2) == LED_OPERATION_FAILED) return LED_OPERATION_FAILED;
		if(Timer0_delay(delay) == TIMER_INTERRUPTED) 
		{ 
			return LED_OPERATION_FAILED;
			break; 
		}
		temp += delay;
		led1->state = 3;
		led2->state = 3;
	}
	return LED_OK;
}

/*int main(void)
{
	LEDS blue,green;
	blue.pin = 0;
	blue.port = PORT_A;
	green.pin = 1;
	green.port = PORT_A;
	//testing drivers
	LED_init(&blue);
	LED_init(&green);
	Timer0_init();
	LED_on(&blue);
	LED_on(&green);
	Timer0_delay(1.0);
	LED_off(&blue);
	LED_off(&green);
	Timer0_delay(1.0);
	LED_toggle(&green);
	LED_toggle(&blue);
	Timer0_delay(1.0);
	LED_blink(0.2, 10, &blue, &green);
	
}*/