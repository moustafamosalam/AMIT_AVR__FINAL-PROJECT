#ifndef 			USART_CONFIG_H
#define 			USART_CONFIG_H
	
/*			System Oscillator clock frequency							*/
#define 		F_CPU					16000000UL

/*				    Mode Of Operation
		    It Could Be Asynchronous or Synchronous 						*/
#define 		MODE_OF_OPERATION 		ASYNCHRONOUS

/*					Transmission Speed
			It Could Be Normal or Double 			 					*/
#define 		TRANSMISSION_SPEED		NORMAL_SPEED

/*					Character Size "Bits"
			It Could Be 5 or 6 or 7 or 8 or 9 Bits	 					*/
#define 		CHARACTER_BITS			8

/*					Number of Stop Bits	
			It Could Be One or TWO									*/
#define 		STOP_BITS				TWO_BIT

/*					Parity Mode
			It Could Be Disabled or even Parity or Odd Parity			*/
#define		PARITY_MODE 				DISABLED

/*					Baud Rate 
			Please Enter The Baud Rate									*/
#define		BAUD_RATE 				9600

/*					Clock Polarity
			It Could Be Rising Edge or Falling Edge 					*/
#define 		CLOCK_POLARITY			RISING_EDGE

#endif