/*
Plik hd44780.h
*/

#ifndef LCD_HD44780
#define LCD_HD44780

#include<util/delay.h>

/* RS */
#define SET_OUT_LCD_RS  DDRA  |=  _BV(PA0)
#define SET_LCD_RS      PORTA |=  _BV(PA0)
#define CLR_LCD_RS      PORTA &= ~_BV(PA0)

/* E */
#define SET_OUT_LCD_E   DDRA  |=  _BV(PA1)
#define SET_LCD_E       PORTA |=  _BV(PA1)
#define CLR_LCD_E       PORTA &= ~_BV(PA1)

/* D4 */
#define SET_OUT_LCD_D4  DDRA  |=  _BV(PA4)
#define SET_LCD_D4      PORTA |=  _BV(PA4)
#define CLR_LCD_D4      PORTA &= ~_BV(PA4)

/* D5 */
#define SET_OUT_LCD_D5  DDRA  |=  _BV(PA5)
#define SET_LCD_D5      PORTA |=  _BV(PA5)
#define CLR_LCD_D5      PORTA &= ~_BV(PA5)

/* D6 */
#define SET_OUT_LCD_D6  DDRA  |=  _BV(PA6)
#define SET_LCD_D6      PORTA |=  _BV(PA6)
#define CLR_LCD_D6      PORTA &= ~_BV(PA6)

/* D7 */
#define SET_OUT_LCD_D7  DDRA  |=  _BV(PA7)
#define SET_LCD_D7      PORTA |=  _BV(PA7)
#define CLR_LCD_D7      PORTA &= ~_BV(PA7)

#define LCD_NOP asm volatile("nop\n\t""nop\n\t" "nop\n\t" "nop\n\t"::);


#define LCDCOMMAND 0
#define LCDDATA    1

#define LCD_LOCATE(x,y)  WriteToLCD(0x80|((x)+((y)*0x40)), LCDCOMMAND); _delay_us(900)

#define LCD_CLEAR              WriteToLCD(0x01, LCDCOMMAND); _delay_ms(32)
#define LCD_HOME               WriteToLCD(0x02, LCDCOMMAND); _delay_ms(32)

/* IDS */

#define LCDINCREMENT           0x02
#define LCDDECREMENT           0x00
#define LCDDISPLAYSHIFT        0x01

#define LCD_ENTRY_MODE(IDS)    WriteToLCD(0x04|(IDS), LCDCOMMAND); _delay_us(900)

/* BCD */
#define LCDDISPLAY             0x04
#define LCDCURSOR              0x02
#define LCDBLINK               0x01

#define LCD_DISPLAY(DCB)       WriteToLCD(0x08|(DCB), LCDCOMMAND); _delay_us(900)

/* RL */
#define LCDLEFT                0x00
#define LCDRIGHT               0x04

#define LCD_SHIFT_DISPLAY(RL)  WriteToLCD(0x18|(RL), LCDCOMMAND); _delay_us(900)
#define LCD_SHIFT_CURSOR(RL)   WriteToLCD(0x10|(RL), LCDCOMMAND); _delay_us(900)

#define LCD_CGRAM_ADDRESS(A)   WriteToLCD(0x40|((A)&0x3f), LCDCOMMAND); _delay_us(900)
#define LCD_DDRAM_ADDRESS(A)   WriteToLCD(0x80|((A)&0x7f), LCDCOMMAND); _delay_us(900)

#define LCD_WRITE_DATA(D)      WriteToLCD((D),LCDDATA)


void lcd_init(void);
void WriteToLCD(unsigned char v,unsigned char rs);
void lcd_puts(char *str);

#endif