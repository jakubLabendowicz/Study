#ifndef ZLAB03_H
#define ZLAB03_H
#include <string>
using namespace  std;


class Prostokat
{

private:
    string nazwa;
    double bok1,bok2;
    bool poprawny;
    double pole,obwod;
    bool czyPoprawny(double bok1,double bok2);
    void ObliczObwod();
    void obliczPole();


public:
    Prostokat(string n="?",double a=1, double b=2);
    ~Prostokat();
    bool czyPoprawny();
    const string& jakaNazwa();
    double podajPole();
    double podajObwod();
    bool zmienBoki(double a,double b);

    std::string doTekstu();

};

#endif // ZLAB03_H
