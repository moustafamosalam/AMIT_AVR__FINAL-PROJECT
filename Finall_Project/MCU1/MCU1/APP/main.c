#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "SPI_interface.h"
#include "USART_interface.h"

#define F_CPU	16000000UL
#include <util/delay.h>

int main(void)
{
	u8 data;																	//Variable for storing the data received from Virtual Terminal
	
	SPI_Init();																	//SPI initialization
	USART_Init();																//USART initialization
												
	DIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);									//MOSI Pin Output			
	DIO_voidSetPinDirection(PORTB,PIN6,INPUT);									//MISO Pin Input
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);									//LED For Indicating that the data has been sent 
	DIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);									//Clock Pin Output
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);									//Chip Selection Pin Output
	 
															
    while (1) 
    {
		data=USART_ReceiveByte();												//Storing the data received from the Virtual Terminal in data Variable
		SPI_Transmit(data);														//Sending the data to MCU2 via SPI
		
/*		LED Blinking for Indicating that the data has been sent					*/		
		DIO_voidSetPinValue(PORTC,PIN0,HIGH);								
		_delay_ms(50);
		DIO_voidSetPinValue(PORTC,PIN0,LOW);
	
	}
}

