#define F_CPU 1000000UL // ustawienie częstotliwości zegara
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUDRATE 9600 //określenie prędkości przesyłania
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) //wyznaczenie zawartości rejestru
int main(void)
{
    USART_Init(); //inicjalizacja
    while(1)
    {
        USART_putchar('j'); //wysyłanie znaku
        USART_putchar('a');
        USART_putchar('k');
        USART_putchar('u');
        USART_putchar('b');
        USART_putchar(' ');
        _delay_ms(250);
    }
}
void USART_putchar(unsigned char data) //wysyłanie znaku
{
    UDR = data;
}
void USART_Init(void) //inicjalizacja
{
   /* ustawienie baud */
    UBRRH = (uint8_t)(BAUD_PRESCALLER >> 8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
}
