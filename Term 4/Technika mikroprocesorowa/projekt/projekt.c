#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include "hd44780.h"

#define F_CPU 4000000L

volatile uint8_t i = 0;

char * nazwisko = "Labendowicz";

ISR(TIMER1_COMPA_vect){
    lcd_puts(nazwisko[i]);
	i++;
	if(i==11) {
		TCCR1B = TCCR1B & 0b11111000;
	}
    TCNT1 = 0;
}

int main(void){
	DDRA = 0xFF;
    lcd_init();
    LCD_DISPLAY(LCDDISPLAY);
	LCD_LOCATE(0,0);

    cli();

   	TIMSK |= (1<<OCIE1A);

    TCCR1B |= (1<<WGM12)|(1<<CS10) |(1<<CS12);

    //preskaler na: 1024
    OCR1A = 250;
   	sei();
   	while(1);
}
