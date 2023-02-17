


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"
/************************************************************************/
/* Port A                                                                     */
/************************************************************************/
#define PORTA *((volatile uint8_t*) (0x3B))
#define DDRA *((volatile uint8_t*) (0x3A))
#define PINA *((volatile uint8_t*) (0x39))

/************************************************************************/
/* Port B                                                                    */
/************************************************************************/
#define PORTB *((volatile uint8_t*) (0x38))
#define DDRB *((volatile uint8_t*) (0x37))
#define PINB *((volatile uint8_t*) (0x36))
/************************************************************************/
/* Port C                                                                    */
/************************************************************************/
#define PORTC *((volatile uint8_t*) (0x35))
#define DDRC *((volatile uint8_t*) (0x34))
#define PINC *((volatile uint8_t*) (0x33))
/************************************************************************/
/* Port D                                                                   */
/************************************************************************/
#define PORTD *((volatile uint8_t*) (0x32))
#define DDRD *((volatile uint8_t*) (0x31))
#define PIND *((volatile uint8_t*) (0x30))

/************************************************************************/
/* Timer0 registers                                                                     */
/************************************************************************/
#define TCCR0 *((volatile uint8_t*) (0x53))
#define TCNT0 *((volatile uint8_t*) (0x52))
#define TIFR *((volatile uint8_t*) (0x58))
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define WGM00 6
#define COM00 4
#define COM01 5
/************************************************************************/
/* int0 registers                                                       */
/************************************************************************/
#define SREG *((volatile uint8_t*) (0x5F))
#define MCUCR *((volatile uint8_t*) (0x55))
#define GICR  *((volatile uint8_t*) (0x5A))
#define GIFR  *((volatile uint8_t*) (0x5B))
#define ISC00  0
#define ISC01  1
#define INT0   6
#define INTF0  6
#endif /* REGISTERS_H_ */