/*
  Plik hd44780.c

  Definicje kilku funkcji do obsługi alfanumerycznego
  wyświetlacza LCD HD44780
*/


#include<avr/io.h>
#include<util/delay.h>
#include "hd44780.h"

/*--------------------------------------------------------*/
/* Zapis danej lub instrukcji */

void WriteToLCD (unsigned char v,unsigned char  rs)
{

    SET_OUT_LCD_D4;
    SET_OUT_LCD_D5;
    SET_OUT_LCD_D6;
    SET_OUT_LCD_D7;

    if(v&0x10) SET_LCD_D4; else CLR_LCD_D4;
    if(v&0x20) SET_LCD_D5; else CLR_LCD_D5;
    if(v&0x40) SET_LCD_D6; else CLR_LCD_D6;
    if(v&0x80) SET_LCD_D7; else CLR_LCD_D7;
 
    CLR_LCD_E;
    if(rs) SET_LCD_RS;else CLR_LCD_RS;

    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;
 
    if(v&0x01) SET_LCD_D4; else CLR_LCD_D4;
    if(v&0x02) SET_LCD_D5; else CLR_LCD_D5;
    if(v&0x04) SET_LCD_D6; else CLR_LCD_D6;
    if(v&0x08) SET_LCD_D7; else CLR_LCD_D7;
 
    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;

    _delay_us(1600);
}



/*---------------------------------------------------------*/
/* Inicjalizacja wyswietlacza */

void lcd_init(void)
{
    _delay_ms(31);    
   
    SET_OUT_LCD_RS;
    SET_OUT_LCD_E;
    SET_OUT_LCD_D4;
    SET_OUT_LCD_D5;
    SET_OUT_LCD_D6;
    SET_OUT_LCD_D7;

    CLR_LCD_E;
    CLR_LCD_RS;
    SET_LCD_D4;
    SET_LCD_D5;
    CLR_LCD_D6;
    CLR_LCD_D7;        
  
    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;
    _delay_ms(160);

    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;
    _delay_ms(32);

    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;
    _delay_ms(32);

    CLR_LCD_D4;
    LCD_NOP;
    SET_LCD_E;
    LCD_NOP; 
    CLR_LCD_E;
    LCD_NOP;
    _delay_us(900);

    WriteToLCD (0x28 , LCDCOMMAND) ;
    _delay_us(900);

    LCD_DISPLAY(0) ;
    _delay_us(900);

    LCD_CLEAR ;
    _delay_ms(32);

    LCD_ENTRY_MODE(LCDINCREMENT) ;
    _delay_us(900);


}


/*--------------------------------------------------------*/
/* Wyswietla tekst na aktualnej pozycji kursora */

void lcd_puts(char *str)
{
    unsigned char i =0;

    while( str[i])
        LCD_WRITE_DATA(str[i++]) ;
}
