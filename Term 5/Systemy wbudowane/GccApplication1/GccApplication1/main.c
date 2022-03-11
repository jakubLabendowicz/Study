#include <avr/io.h>
#include <util/delay.h>

#define PORTK 	PORTD
#define PINK 	PIND
#define DDRK	DDRD

#define PORTLED PORTA
#define DDRLED  DDRA

int main(void)
{
	DDRLED =0xff;
	DDRK   =0xf0;
	
	LCD_Initalize();
	
	
	while (1)
	{
		int clicked = keyboard();
		if (clicked != -1)
		{
			showLED(clicked);
			showLCD(clicked);
		}
	}
}


