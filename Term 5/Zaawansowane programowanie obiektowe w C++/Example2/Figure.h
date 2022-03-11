#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
class Figure  //w klasie znajduja sie pola klasy oraz naglowki metod
{
private:
    float area;
public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area1);
    virtual void calculateArea()=0;
    void show();
};
#endif // FIGURE_H_INCLUDED
