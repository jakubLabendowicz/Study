/*
 * CFile1.c
 *
 * Created: 28.10.2021 14:48:08
 *  Author: Student_PL
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define PORTK 	PORTD
#define PINK 	PIND
#define DDRK	DDRD

#define PORTLED PORTA
#define DDRLED  DDRA

void showLED(int clicked){
	PORTLED = clicked;
}

void showLCD(int clicked){
	LCD_Clear();
	
	char a[2];
	
	if (clicked <= 9 && clicked >= 0)
	{
		itoa(clicked, a, 10);
	} else if (clicked == 10)
	{
		a[0] = '*';
		a[1] = ' ';
	} else if (clicked == 11)
	{
		a[0] = '#';
		a[1] = ' ';
	} else if (clicked == 12)
	{
		a[0] = 'A';
		a[1] = ' ';
	} else if (clicked == 13)
	{
		a[0] = 'B';
		a[1] = ' ';
	} else if (clicked == 14)
	{
		a[0] = 'C';
		a[1] = ' ';
	} else if (clicked == 15)
	{
		a[0] = 'D';
		a[1] = ' ';
	}
	
	LCD_WriteText("Przycisk:");
	LCD_WriteText(a);
}

int keyboard() {
	DDRLED =0xff;
	DDRK   =0xf0;
	
	PORTK  =0b11101111; //akytwacja kolumny K1 (1 z 4)
	_delay_ms(1);		//czas na ustalenie siê stanu na linii K1
	
	if((PINK & (1<<0))==0){
		return 1;
		_delay_ms(20);
	}
	if((PINK & (1<<1))==0){
		return 4;
		_delay_ms(20);
	}
	if((PINK & (1<<2))==0){
		return 7;
		_delay_ms(20);
	}
	if((PINK & (1<<3))==0){
		return 10;
		_delay_ms(20);
	}
	
	PORTK  =0b11011111; //akytwacja kolumny K2
	_delay_ms(1);		//czas na ustalenie siê stanu na linii K2
	
	if((PINK & (1<<0))==0){
		return 2;
		_delay_ms(20);
	}
	if((PINK & (1<<1))==0){
		return 5;
		_delay_ms(20);
	}
	if((PINK & (1<<2))==0){
		return 8;
		_delay_ms(20);
	}
	if((PINK & (1<<3))==0){
		return 0;
		_delay_ms(20);
	}
	
	PORTK  =0b10111111; //akytwacja kolumny K3
	_delay_ms(1);		//czas na ustalenie siê stanu na linii K3
	
	if((PINK & (1<<0))==0){
		return 3;
		_delay_ms(20);
	}
	if((PINK & (1<<1))==0){
		return 6;
		_delay_ms(20);
	}
	if((PINK & (1<<2))==0){
		return 9;
		_delay_ms(20);
	}
	if((PINK & (1<<3))==0){
		return 11;
		_delay_ms(20);
	}
	
	PORTK  =0b01111111; //akytwacja kolumny K4
	_delay_ms(1);		//czas na ustalenie siê stanu na linii K4
	
	if((PINK & (1<<0))==0){
		return 12;
		_delay_ms(20);
	}
	if((PINK & (1<<1))==0){
		return 13;
		_delay_ms(20);
	}
	if((PINK & (1<<2))==0){
		return 14;
		_delay_ms(20);
	}
	if((PINK & (1<<3))==0){
		return 15;
		_delay_ms(20);
	}
	return -1;
}