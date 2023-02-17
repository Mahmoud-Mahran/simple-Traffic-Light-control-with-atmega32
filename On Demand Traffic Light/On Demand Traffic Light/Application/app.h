


#ifndef APP_H_
#define APP_H_
//drivers include
#include "../EUCAL/LED Driver/led.h"	
#include "../EUCAL/Button Driver/button.h"
//helper macros definitions
#define CAR_GREEN			 0
#define CAR_YELLOW			 1
#define CAR_RED				 2
#define PED_GREEN			 3
#define PED_YELLOW			 4
#define PED_RED				 5
#define N_MODE				'n'
#define PEDESTRIAN_MODE		'p'

//function that takes void and returns void and initializes all required app components 
void app_init(void);
//function that takes void and returns void and contains main program logic
void app_start(void);	
//function that takes void and returns void and contains the actions performed when the push button is pressed
void my_isr(void);


#endif /* APP_H_ */