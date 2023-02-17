 
#include "app.h"
LEDS Traffic_Lights[6];			//struct to hold led data
uint8_t mode = N_MODE;			//variable to store current mode
uint8_t pressed = 0;			//variable to store current pressed state
uint8_t const del_period = 5;	// const used to make a delay period of 5 seconds

void app_init()
{
	//setting ports and pins of all leds and the push button and initializing the external interrupt and timer0
	Traffic_Lights[CAR_GREEN].port = Traffic_Lights[CAR_YELLOW].port = Traffic_Lights[CAR_RED].port = PORT_A;
	Traffic_Lights[CAR_GREEN].pin = 0;
	Traffic_Lights[CAR_YELLOW].pin = 1;
	Traffic_Lights[CAR_RED].pin = 2;
	Traffic_Lights[PED_GREEN].port = Traffic_Lights[PED_YELLOW].port = Traffic_Lights[PED_RED].port = PORT_B;
	Traffic_Lights[PED_GREEN].pin = 0;
	Traffic_Lights[PED_YELLOW].pin = 1;
	Traffic_Lights[PED_RED].pin = 2;
	button_init(PORT_D, 2, INPUT, HIGH);
	button_interrupt_EN(my_isr);
	Timer0_init();
	for (int i = 0; i < 6; i++)
	{
		LED_init(&Traffic_Lights[i]);
	}

}


void app_start(void)
{
	while (1)
	{
		if (mode == N_MODE)
		{
			// making sure all leds are off
			for (int i = 0; i < 6; i++)
			{
				LED_off(&Traffic_Lights[i]);
			}
			//turn on car green and pedestrian red leds
			LED_on(&Traffic_Lights[CAR_GREEN]);
			LED_on(&Traffic_Lights[PED_RED]);
			//5 second delay
			Timer0_delay(del_period);
			//check if the button was pressed (interrupt triggered) and the current mode was changed
			if(mode == PEDESTRIAN_MODE) continue;
			//turn off car green and pedestrian red leds
			LED_off(&Traffic_Lights[CAR_GREEN]);
			LED_off(&Traffic_Lights[PED_RED]);
			//blink both yellow leds every 0.5 second for 5 seconds
			LED_blink(0.5, del_period, &Traffic_Lights[CAR_YELLOW], &Traffic_Lights[PED_YELLOW]);
			//check if the button was pressed (interrupt triggered) and the current mode was changed
			if(mode == PEDESTRIAN_MODE) continue;
			//turn off both yellow leds
			LED_off(&Traffic_Lights[CAR_YELLOW]);
			LED_off(&Traffic_Lights[PED_YELLOW]);
			//turn on car red and pedestrian green leds
			LED_on(&Traffic_Lights[CAR_RED]);
			LED_on(&Traffic_Lights[PED_GREEN]);
			//5 second delay
			Timer0_delay(del_period);
			//check if the button was pressed (interrupt triggered) and the current mode was changed
			if(mode == PEDESTRIAN_MODE) continue;
			//turn off car red led
			LED_off(&Traffic_Lights[CAR_RED]);
			//blink both yellow leds every 0.5 second for 5 seconds
			LED_blink(0.5, del_period, &Traffic_Lights[CAR_YELLOW], &Traffic_Lights[PED_YELLOW]);
			//check if the button was pressed (interrupt triggered) and the current mode was changed
			if(mode == PEDESTRIAN_MODE) continue;
		}
		if (mode == PEDESTRIAN_MODE)
		{
			//if the red light is on
			if(Traffic_Lights[CAR_RED].state == 2)
			{
				//5 second delay
				Timer0_delay(del_period);
			}
			//if the green light is on or the yellow leds are blinking
			if (Traffic_Lights[CAR_GREEN].state == 2 || Traffic_Lights[CAR_YELLOW].state == 3)
			{
				// making sure all leds are off
				for (int i = 0; i < 6; i++)
				{
					LED_off(&Traffic_Lights[i]);
				}
				//turn on pedestrian red led
				LED_on(&Traffic_Lights[PED_RED]);
				//blink both yellow leds every 0.5 second for 5 seconds
				LED_blink(0.5, del_period, &Traffic_Lights[CAR_YELLOW], &Traffic_Lights[PED_YELLOW]);
				//turn off pedestrian red led and both yellow leds
				LED_off(&Traffic_Lights[PED_RED]);
				LED_off(&Traffic_Lights[CAR_YELLOW]);
				LED_off(&Traffic_Lights[PED_YELLOW]);
				//turn on car red and pedestrian green leds
				LED_on(&Traffic_Lights[CAR_RED]);
				LED_on(&Traffic_Lights[PED_GREEN]);
				//5 second delay
				Timer0_delay(del_period);
			}
			//turn off car red led
			LED_off(&Traffic_Lights[CAR_RED]);
			//blink both yellow leds every 0.5 second for 5 seconds
			LED_blink(0.5, del_period, &Traffic_Lights[CAR_YELLOW], &Traffic_Lights[PED_YELLOW]);
			//switch to normal mode
			mode = N_MODE;
			//write zero to the button pressed state
			pressed = 0;
		}
	}
}
void my_isr(void)
{
	// if the button isn't already pressed
	if (pressed == 0)
		{
			//switch to pedestrian mode
			mode = PEDESTRIAN_MODE;
			//set the button pressed state to 1
			pressed = 1;
			//stop the timer to stop any on going delay
			Timer0_stop();
		}
}

