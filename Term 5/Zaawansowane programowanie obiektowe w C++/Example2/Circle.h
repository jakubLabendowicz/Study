#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

class Circle: public Figure
{
private:
    float r;
public:
    Circle(float r1);
    ~Circle();
    virtual void calculateArea() override;//implementacja metody ktora byla w klasie bazowej czysto wirtualna
};
#endif // CIRCLE_H_INCLUDED
