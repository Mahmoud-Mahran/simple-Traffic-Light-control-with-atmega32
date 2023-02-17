


#ifndef TIMER0_H_
#define TIMER0_H_
// include required headers
#include "../../registers.h"
#include <math.h>
//helper macros for error handling
#define INIT_OK					10
#define TIMER_STARTED			16
#define TIMER_STOPPED			32
#define DELAY_COMPLETE			64
#define TIMER_INTERRUPTED		128
//macros for dealy calculations
#define F_CPU					1000000.0
#define PRESCALER				1.0


/*function that takes no arguments and returns an int for error handling.
 initializes timer0 in normal mode */
int Timer0_init(void);
/*function that takes no arguments and returns an int for error handling.
 starts timer0 in normal mode with no prescaler */
int Timer0_start(void);
/*function that takes no arguments and returns an int for error handling.
 stops/ resets timer0 */
int Timer0_stop(void);
/*function that takes a delay period and returns an int for error handling.
 makes the necessary calculations to how how many overflows are required to get the needed delay and uses interrupts and timer overflow interrupt for timing*/
int Timer0_delay(double delay);



#endif /* TIMER0_H_ */