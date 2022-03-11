#ifndef KWADRAT_H
#define KWADRAT_H

#include "iostream"
#include "Prostokat.h"

class Obliczenia
{
    protected:
        const double pi = 3.14;

    public:

        virtual double promienKolaWgPola() = 0;
        virtual double promienOkreguWgObwodu() = 0;
        virtual ~Obliczenia();

};

class Kwadrat : public Prostokat, public Obliczenia
{

    public:
        Kwadrat(string nazwa = "?", double bok = 0)
            :Prostokat(nazwa, bok, bok) {}
        ~Kwadrat() { cout << "Kwadrat " << nazwa << " znika" << endl; }

        double promienKolaWgPola();
        double promienOkreguWgObwodu();

        string doTekstu();

};

#endif // KWADRAT_H
