#include <avr/io.h>
#include <avr/delay.h>

int main (void) { //p�tla g��wna 
	while(1) {
	PORTC = 0xff;
		for(int i = 1; i<=9; i++) {
			PORTC = PORTC << 1;
			_delay_ms(250);
		}
	}
	PORTC = 0xff;
		for(int i = 1; i<=9; i++) {
			PORTC = PORTC >> 1;
			_delay_ms(250);
		}
	}
}
