#ifndef USTAWIENIASYMULACJI_H
#define USTAWIENIASYMULACJI_H


class UstawieniaSymulacji
{
    public:
        const char
            znakGlon = '*',
            znakGrzyb = '#',
            znakBakteria = '@',
            znakTrup = '+',
            znakNieokreslony = '?',
            znakPustaNisza = '_',
            znakSeparator = ' ';

        unsigned short
            glonZycieMin = 5,
            glonZycieMax = 10,
            glonKosztPotomka = 2,
            glonLimitPosilkow = 6,

            grzybZycieMin = 40,
            grzybZycieMax = 60,
            grzybKosztPotomka = 3,
            grzybLimitPosilkow = 30,

            bakteriaZycieMin = 25,
            bakteriaZycieMax = 40,
            bakteriaKosztPotomka = 3,
            bakteriaLimitPosilkow = 10;

        bool poprawnyZnakNiszy(char znak) const {
            return znak == znakGlon ||
                znak == znakGrzyb ||
                znak == znakBakteria ||
                znak == znakTrup ||
                znak == znakPustaNisza;
        }

        bool poprawnySeparator(char znak) const {
            return znak == znakSeparator;
        }

    private:

        UstawieniaSymulacji(){}
        UstawieniaSymulacji(UstawieniaSymulacji&){}

    public:

        static UstawieniaSymulacji& pobierzUstawienia() {
            static UstawieniaSymulacji ustawienia;
            return ustawienia;
        }

};

#endif // USTAWIENIASYMULACJI_H
