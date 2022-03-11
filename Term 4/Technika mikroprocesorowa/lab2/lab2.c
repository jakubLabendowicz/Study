#include <avr/io.h>
#include <avr/delay.h>

int main (void) { //pêtla g³ówna 
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
