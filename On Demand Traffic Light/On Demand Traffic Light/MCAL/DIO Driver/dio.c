
#include "dio.h"

int DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if (direction == OUTPUT)
			{
				DDRA |= (1<<pinNumber);   //output
				return DIO_OK;
			}
			else if (direction == INPUT)  //input
			{
				DDRA &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_INIT_FAILED;
			}
		break;
		case PORT_B:
			if (direction == OUTPUT)
			{
				DDRB |= (1<<pinNumber);   //output
				return DIO_OK;
			}
			else if (direction == INPUT)  //input
			{
				DDRB &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_INIT_FAILED;
			}
		break;
		case PORT_C:
			if (direction == OUTPUT)
			{
				DDRC |= (1<<pinNumber);   //output
				return DIO_OK;
			}
			else if (direction == INPUT)  //input
			{
				DDRC &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_INIT_FAILED;
			}
		break;
		case PORT_D:
			if (direction == OUTPUT)
			{
				DDRD |= (1<<pinNumber);   //output
				return DIO_OK;
			}
			else if (direction == INPUT)  //input
			{
				DDRD &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_INIT_FAILED;
			}
		break;
		default:
			return DIO_INIT_FAILED;
		break;
	}
}

int DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
			if (value == HIGH)
			{
				PORTA |= (1<<pinNumber);   //write 1
				return DIO_OK;
			}
			else if (value == LOW)  //write 0
			{
				PORTA &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_WRITE_FAILED;
			}
		break;
		case PORT_B:
			if (value == HIGH)
			{
				PORTB |= (1<<pinNumber);		//write 1
				return DIO_OK;
			}
			else if (value == LOW)				//write 0
			{
				PORTB &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_WRITE_FAILED;
			}
		break;
			case PORT_C:
			if (value == HIGH)
			{
				PORTC |= (1<<pinNumber);	//write 1
				return DIO_OK;
			}
			else if (value == LOW)			//write 0
			{
				PORTC &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_WRITE_FAILED;
			}
		break;
		case PORT_D:
			if (value == HIGH)
			{
				PORTD |= (1<<pinNumber);	//write 1
				return DIO_OK;
			}
			else if (value == LOW)			//write 0
			{
				PORTD &= ~(1<<pinNumber);
				return DIO_OK;
			}
			else
			{
				return DIO_WRITE_FAILED;
			}
		break;
	}
	return DIO_WRITE_FAILED;
}

int DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
			PORTA ^= (1<<pinNumber);   //toggle bit
			return DIO_OK;
		break;
		case PORT_B:
			PORTB ^= (1<<pinNumber);   //toggle bit
			return DIO_OK;
		break;
		case PORT_C:
			PORTC ^= (1<<pinNumber);   //toggle bit
			return DIO_OK;
		break;
		case PORT_D:
			PORTD ^= (1<<pinNumber);   //toggle bit
			return DIO_OK;
		break;
		default:
			return DIO_TOGGLE_FAILED;
		break;
	}
}

int DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value)
{
		switch(portNumber)
		{
			case PORT_A:
				*value = PINA & (1<<pinNumber);   //read bit
				return DIO_OK;
			break; //redundant
			case PORT_B:
				*value = PINB & (1<<pinNumber);   //read bit
				return DIO_OK;
			break;
			case PORT_C:
				*value = PINC & (1<<pinNumber);   //read bit
				return DIO_OK;
			break;
			case PORT_D:
				*value = PIND & (1<<pinNumber);   //read bit
				return DIO_OK;
			break;
		default:
			return DIO_READ_FAILED;
		break;
			
		}
}
