/*
 * IncFile1.h
 *
 * Created: 28.10.2021 14:49:33
 *  Author: Student_PL
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define PORTK 	PORTD
#define PINK 	PIND
#define DDRK	DDRD

#define PORTLED PORTA
#define DDRLED  DDRA

#ifndef INCFILE1_H_
#define INCFILE1_H_

void showLED(int clicked);

void showLCD(int clicked);


#endif /* INCFILE1_H_ */