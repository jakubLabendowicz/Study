#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "Figure.h"
class Square: public Figure
{
private:
    float a;
public:
    Square(float a1);
    ~Square();
    virtual void calculateArea() override;
    void show();
};
#endif // SQUARE_H_INCLUDED
