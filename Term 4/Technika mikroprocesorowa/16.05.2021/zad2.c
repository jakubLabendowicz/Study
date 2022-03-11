#define F_CPU 100000UL
#include <avr/io.h>
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_Init() {
    UCSRB |= (1 << RXEN) | (1 << TXEN);
    UBRRH = (uint8_t)(BAUD_PRESCALLER >> 8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
}

void USART_putchar(char data) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

unsigned char USART_getchar() {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

void USART_text(char *str) {
    unsigned char n = 0;
    while (str[n])
        USART_putchar(str[n++]);
}

int main() {
    USART_Init();
    USART_text("Wpisz: 'x'\n");
    char a = USART_getchar();
    if (a == 'x')
        USART_text("Potwierdzenie: ");
    else
        USART_text("Brak potwierdzenia: ");
    USART_putchar(a);
}
