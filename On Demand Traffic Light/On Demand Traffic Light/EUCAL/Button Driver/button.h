


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Int0 Driver/int0.h"
#define BUTTON_OK			88
#define BUTTON_INIT_FAILED	99
void (*my_CB) (void);
/*function that takes the port number, pin, output or input mode and a value to set and returns an int for error handling
initializes button  */
int button_init(uint8_t port_number, uint8_t pin_number, uint8_t mode, uint8_t value);
/*function that takes the a pointer to the call back function that will be executed 
when the button is pressed and returns void
initializes external interrupt0 and gets a function to execute when the ISR is triggered  */
void button_interrupt_EN(void (*func) (void));




#endif /* BUTTON_H_ */