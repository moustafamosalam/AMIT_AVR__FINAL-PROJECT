#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_interface.h"
#include "SPI_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "Temperature_Sensor.h"
#define F_CPU	16000000UL
#include <util/delay.h>


int main(void)
{
	u8 data;														//Variable for storing the data received from MCU1
	u8 Temp;														//Variable for storing the data received from ADC 
    ADC_Init();														//ADC initialization
	SPI_Init();														//SPI initialization	
							
	DIO_voidSetPinDirection(PORTB,PIN5,INPUT);						//MOSI Pin Input
	DIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);						//MISO Pin Output
	DIO_voidSetPinDirection(PORTB,PIN7,INPUT);						//Clock Pin Input	
	DIO_voidSetPinDirection(PORTB,PIN4,INPUT);						//Chip Selection Pin Input
	
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);						//Pin for Reading Temperature Sensor "ADC"

	DIO_voidSetPinDirection(PORTA,PIN2,OUTPUT);						//LED Simulating Door1
	DIO_voidSetPinDirection(PORTA,PIN3,OUTPUT);						//LED Simulating Door2	
	DIO_voidSetPinDirection(PORTA,PIN4,OUTPUT);						//LED Simulating Door3
	
	/*		LCD Pins Configuration									*/	
	DIO_voidSetPinDirection(PORTC,	PIN4,	OUTPUT);
	DIO_voidSetPinDirection(PORTC,	PIN5,	OUTPUT);
	DIO_voidSetPinDirection(PORTC,	PIN6,	OUTPUT);
	DIO_voidSetPortDirection(PORTD,	0xFF);

	LCD_init();														//LCD Initialization
	LCD_WriteSTring("Temp =");										
	
	while (1)
	{		
			LCD_GOTOXY(0,7);										//Go to line number 1 position number 7 
			Temp=Temperature_Read();								//Storing the value of the Temperature in Temp variable	
			
/*			Checking the value of the temperature						*/
			if(Temp<20)	
			{
				LCD_GOTOXY(1,10);									//Go to line number 2 position number 10 to write the temperature status
				LCD_WriteSTring("COLD");
			}
			else if((Temp>=20)&&(Temp<=30))
			{
				LCD_GOTOXY(1,10);									//Go to line number 2 position number 10 to write the temperature status
				LCD_WriteSTring("WARM");
			}
			else
			{
				LCD_GOTOXY(1,10);									//Go to line number 2 position number 10 to write the temperature status
				LCD_WriteSTring("HOT ");
			}
			
		data=SPI_Receive();											//Storing the data received from the MCU1 in data Variable
		
		/*		Checking the data received to do a specific action			*/
		switch(data){
			case('1') :
			DIO_voidSetPinValue(PORTA,PIN2,HIGH);					//LED Simulating Door1 ON
			DIO_voidSetPinValue(PORTA,PIN3,LOW);
			DIO_voidSetPinValue(PORTA,PIN4,LOW);
			break;
			case('2') :
			DIO_voidSetPinValue(PORTA,PIN2,LOW);
			DIO_voidSetPinValue(PORTA,PIN3,HIGH);					//LED Simulating Door2 ON
			DIO_voidSetPinValue(PORTA,PIN4,LOW);
			break;
			case('3') :
			DIO_voidSetPinValue(PORTA,PIN2,LOW);
			DIO_voidSetPinValue(PORTA,PIN3,LOW);
			DIO_voidSetPinValue(PORTA,PIN4,HIGH);					//LED Simulating Door3 ON
			break;
			case('4') :
			DIO_voidSetPinValue(PORTA,PIN2,HIGH);					//LED Simulating Door1 ON
			DIO_voidSetPinValue(PORTA,PIN3,HIGH);					//LED Simulating Door2 ON
			DIO_voidSetPinValue(PORTA,PIN4,HIGH);					//LED Simulating Door3 ON
			break;
		}
	}
}

