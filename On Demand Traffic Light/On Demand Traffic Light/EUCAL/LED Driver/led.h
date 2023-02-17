


#ifndef LED_H_
#define LED_H_
//used driver includes
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer0 Driver/timer0.h"
//helper macros for error handling
#define LED_OK					222
#define LED_OPERATION_FAILED	220
//struct to store led attributes
typedef struct LEDS{
	uint8_t port;
	uint8_t pin;
	uint8_t state;
}LEDS;
/*function that takes a "LEDS" struct and returns an int for error handling 
initializes led according to given arguments */
int LED_init(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns on led */
int LED_on(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns off led */
int LED_off(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
toggles led */
int LED_toggle(LEDS *led);
/*function that takes 2 "LEDS" structs, a blink delay and total blinking duration and returns an int for error handling
blinks two leds according to given arguments */
int LED_blink(double delay, double duration, LEDS *led1, LEDS *led2);





#endif /* LED_H_ */