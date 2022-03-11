#include <avr/io.h>
#include <avr/delay.h>

int main (void) { //pêtla g³ówna
	DDRA = 255;
	DDRD = 0xf0;
	PORTA = 0b10101010;
	PORTD = 0b00001111;

	while(1) {
		if(bit_is_clear(PIND, 0)) {
			PORTA = ~PORTA;
		}
		if(bit_is_clear(PIND, 1)) {
			PORTA = ~PORTA;
		}
		if(bit_is_clear(PIND, 2)) {
			PORTA = ~PORTA;
		}
		if(bit_is_clear(PIND, 3)) {
			PORTA = ~PORTA;
		}
	}
}
