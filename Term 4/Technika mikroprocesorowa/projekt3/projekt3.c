#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

int main(void)
{
    USART_Init();

    while(1)
    {
        USART_putchar('H');
        USART_putchar('e');
        USART_putchar('l');
        USART_putchar('l');
        USART_putchar('o');
        USART_putchar(' ');
        _delay_ms(250);
    }
}

void USART_putchar(unsigned char data)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR = data;

}

void USART_Init(void)
{
    UBRRH = (uint8_t)(BAUD_PRESCALLER >> 0);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
    /* (BAUD_RATE = 9600, ramka:8 bitów danych, brak kontroli parzystoœci, 1 bit stopu */
}
