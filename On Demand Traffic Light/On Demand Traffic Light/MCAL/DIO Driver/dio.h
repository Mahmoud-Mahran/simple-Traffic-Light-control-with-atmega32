


#ifndef DIO_H_
#define DIO_H_
// include registers
#include "../../registers.h"

//helper macros for ports
#define PORT_A   'A'
#define PORT_B   'B'
#define PORT_C   'C'
#define PORT_D   'D'

//helper macros for direction
#define OUTPUT   'o'
#define INPUT    'i'

#define HIGH	 1
#define LOW		 0
//helper macros for error handling
#define DIO_OK				111
#define DIO_INIT_FAILED		22
#define DIO_WRITE_FAILED	33
#define DIO_TOGGLE_FAILED	44
#define DIO_READ_FAILED		55
/*function that takes the port number, pin, output or input mode and returns an int for error handling 
 initializes the pin based on input arguments */
int DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);
/*function that takes the port number, pin and a value to set and returns an int for error handling 
 sets the pin value based on input arguments */
int DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);
/*function that takes the port number and pin and returns an int for error handling 
 toggles the pin value */
int DIO_toggle(uint8_t portNumber, uint8_t pinNumber);
/*function that takes the port number, pin and a  pointer to store value and returns an int for error handling.
 reads the pin value and stores it in the address given by the pointer */
int DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);



#endif /* DIO_H_ */