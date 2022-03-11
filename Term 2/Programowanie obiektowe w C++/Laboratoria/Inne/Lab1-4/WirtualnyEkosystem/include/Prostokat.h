#ifndef PROSTOKAT_H
#define PROSTOKAT_H

#include <string>
using namespace std;

class Prostokat
{

private:
    string nazwa;
    double bok1, bok2;
    bool poprawny;
    double obwod, pole;

    bool czyPoprawny(double bok1, double bok2);
    void obliczObwod();
    void obliczPole();

public:

    Prostokat(string n = "?", double a = 1, double b = 2);
    ~Prostokat();

    bool czyPoprawny();
    const string& jakaNazwa();
    double podajPole();
    double podajObwod();
    bool zmienBoki(double a, double b);

    string doTekstu();

};

#endif // PROSTOKAT_H
