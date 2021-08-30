#include	"STD_TYPES.h"
#include	"ADC_interface.h"
#include	"LCD_interface.h"

u8 Temperature_Read(void)
{
	u16 ADC_Val = 0 ;
	u8 Temp;
	ADC_Val = ADC_Read();
	Temp=ADC_Val/2.05;								//Equation for Measuring Temperature
	LCD_ReadSensor(Temp);						
	return Temp;
}