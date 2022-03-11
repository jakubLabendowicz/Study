#include<iostream>
#include "Figure.h"
#include "Circle.h"
using namespace std;

Circle::Circle(float r1)
{
    r=r1;
    cout<<"Konstruktor w klasie Circle"<<endl;
}

Circle::~Circle()
{
    cout<<"Destruktor w klasie Circle"<<endl;
}

void Circle:: calculateArea() //implementacja metody ktora byla w klasie bazowej czysto wirtualna
{
    float p=3.14*r*r;
    setArea(p);
}

