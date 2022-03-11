#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


ISR(INT0_vect){ //przycisk 0
    PORTA|=0b01010101; //co drugi led
    PORTC = PORTC+1;
    _delay_ms(100);
}

ISR(INT1_vect){ //przycisk 1
    PORTA= PORTA<<1; //przesuniêcie w lewo
    PORTC = PORTC+1;
    _delay_ms(100);
}

ISR(INT2_vect){ //przycisk 2
    PORTA = 0x00; //zerowanie
    PORTC = PORTC+1;
    _delay_ms(100);
}

int main (void) {
    DDRA = 255;
	PORTA =0x0F; //wyœwietlenie 4 pierwszych ledów

	DDRB = 0b11111011;
	PORTB =0b00000000;

    DDRC = 255;
	PORTC =0x00;

    DDRD = 0b11110011;
    PORTD =0b00000000;
    

    GICR = 0b11100000;
    sei();
    while(1);
}
