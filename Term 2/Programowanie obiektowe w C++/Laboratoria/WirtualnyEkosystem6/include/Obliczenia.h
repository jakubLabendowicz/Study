#ifndef OBLICZENIA_H
#define OBLICZENIA_H


class Obliczenia
{
    protected:
        const double pi = 3.14;

    public:

        virtual double promienKolaWgPola() = 0;
        virtual double promenOkreguWgObwodu() = 0;
        virtual ~Obliczenia();

};

#endif // OBLICZENIA_H
