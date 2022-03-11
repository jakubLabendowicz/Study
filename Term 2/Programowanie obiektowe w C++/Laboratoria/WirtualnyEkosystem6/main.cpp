#include <iostream>
#include <string>
#include <locale>
#include "Prostokat.h"
#include "Kwadrat.h"
#include "Organizm.h"
#include "UstawieniaSymulacji.h"
#include "GeneratorLosowy.h"
#include "Sasiedztwo.h"
using namespace std;

typedef GeneratorLosowy GEN;

static char sep = UstawieniaSymulacji::pobierzUstawienia().znakSeparator;

void wyswietl(UstawieniaSymulacji&);
void drukujOrganizm(string nazwa, const Organizm& o);
string nazwaRodzaju(RodzajMieszkanca rodzaj);

int main()
{
    setlocale(LC_ALL, "");

    /*cout << "Laboratorium 03" << endl;

    Prostokat p1;
    Prostokat p2("koc", 1.4, 2.2);
    Prostokat p3("pu³apka", -2, -3);

    cout.precision(2);
    cout << p1.doTekstu() << endl;
    cout << p2.doTekstu() << endl;
    cout << p3.doTekstu() << endl;

    p3.zmienBoki(2, 3);
    cout << endl << p3.doTekstu() << endl;

    cout << endl << "U¿ycie metod obiektu:" << endl;
    cout << "Nazwa: " << p2.jakaNazwa() << endl
         << "Poprawny: " << p2.czyPoprawny() << endl
         << "Obwód = : " << p2.podajObwod() << endl
         << "Pole = : " << p2.podajPole() << endl;

    return 0;*/

    /*Organizm o1(8, 3, 2);
    Organizm o2 = o1;
    Organizm o3(o1);

    cout << "Wynik testu kreacji obiektów:"
         << endl << endl;
    drukujOrganizm("O1", o1);
    drukujOrganizm("O2", o2);
    drukujOrganizm("O3", o3);

    o1.posilek();
    o1.posilek();
    o2.posilek();
    o3.krokSymulacji();

    cout << "Wynik testu niezale¿noœci obiektów:"
         << endl << endl;
    drukujOrganizm("O1", o1);
    drukujOrganizm("O2", o2);
    drukujOrganizm("O3", o3);

    Organizm o4 (8, 3, 2);
    cout << "Wynik testu symulacji: " << endl << endl;
    drukujOrganizm("Stan pocz¹tkowy", o4);

    for (int i = 0 ; i < 10 ; i++){

        o4.krokSymulacji();

        if (o4.paczkujacy()){
            o4.potomek();
            cout << "---> Potomek" << endl;
        }
        else o4.posilek();

        cout << "Po wykonaniu kroku symulacji: " << i << endl;
        drukujOrganizm("", o4);

    }*/

    /*UstawieniaSymulacji& ust1 = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji& ust2 = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji& ust3 = UstawieniaSymulacji::pobierzUstawienia();

    cout << "Pobranie ustawien 3x" << endl;
    cout << "ust1: "; wyswietl(ust1);
    cout << "ust2: "; wyswietl(ust2);
    cout << "ust3: "; wyswietl(ust3);

    cout << endl << "Zmiana wartości tylko 1x" << endl;
    ust2.glonZycieMax = 100;

    cout << "ust1: "; wyswietl(ust1);
    cout << "ust2: "; wyswietl(ust2);
    cout << "ust3: "; wyswietl(ust3);*/

    /*cout << "Liczby losowe typu int:" << endl;
    cout << "od 0 do 5: ";
    for (int i = 0 ; i < 10 ; i++)
        cout << GEN::losujOdZeraDo(5) << " ";
    cout << "od 0 do 3: ";
    for (int i = 0 ; i < 10 ; i++)
        cout << GEN::losujOdZeraDo(3) << " ";
    cout << "od 0 do 20: ";
    for (int i = 0 ; i < 10 ; i++)
        cout << GEN::losujOdZeraDo(20) << " ";

    cout << endl << endl;

    cout << "Liczby losowe typu long: " << endl;
    cout << " od -2 do 2:";
    for (int i = 0 ; i<10 ; i++)
        cout << GEN::losujPomiedzy(-2L, 2L) << " ";

    cout << endl << endl;

    cout << "Liczby losowe typu unsigned short: " << endl;
    cout << " od 2 do 6: ";
    unsigned short min = 2, max = 6;

    for (int i = 0 ; i < 10 ; i++)
        cout << GEN::losujPomiedzy(min, max) << " ";

    cout << endl << endl;*/

    /*Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    cout << "Przeglad sasiedztwa:" << endl;
    for (int i = 0 ; i < 8 ; i++) {
        Polozenie p = static_cast<Polozenie>(i);
        RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);

        cout << "polozenie=" << p << " rodzaj=" << nazwaRodzaju(r) << endl;
    }

    cout << endl << "Policzenie sasiadow"
        << "okreslonego rodzaju:" << endl
        << " glony=" << sasiedztwo.ile(GLON) << endl
        << " grzyby=" << sasiedztwo.ile(GRZYB) << endl
        << " trupy=" << sasiedztwo.ile(TRUP) << endl;

    cout << endl << "Wylosowanie sasiada:" << endl
        <<" glon -> "
        << sasiedztwo.losujSasiada(GLON) << endl
        << " pustka -> "
        << sasiedztwo.losujSasiada(PUSTKA) << endl
        << " trup -> "
        << sasiedztwo.losujSasiada(TRUP) << endl;

    long wiersz, kolumna;
    cout << endl
        << "Zmiana indeksów [5][7] wg. polozenia: " << endl;

    for (int i = 0 ; i < 8 ; i++) {

        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 5, kolumna = 7;

        Sasiedztwo::zmienIndeksyWgPolozenia(p, wiersz, kolumna);

        cout << " położenie: " << p << " -> [" << wiersz << "][" << kolumna << "]" << endl;

    }

    cout << endl;*/

//    Kwadrat kwadrat("Kwadrek", 4);
//    Prostokat prostokat("Prostek", 2, 4);
//
//    Prostokat & referencjaDoProstokat1 = prostokat;
//    cout << referencjaDoProstokat1.doTekstu()
//               << endl << endl;
//
//    Prostokat & referencjaDoProstokat2 = kwadrat;
//    cout << referencjaDoProstokat2.doTekstu()
//               << endl << endl;

    Kwadrat kwadrat("Kwadrek", 4);
    Kwadrat & refDoKwadrat = kwadrat;

    double r0 = refDoKwadrat.promienKolaWgPola();
    double r1 = refDoKwadrat.promienOkreguWgObwodu();

    cout << "r0=" << r0 << endl << "r1=" << r1 << endl;

    return 0;
}


void wyswietl(UstawieniaSymulacji& ust) {
    cout << "Znak glon: " << ust.znakGlon
         << " zycieMin=" << ust.glonZycieMin
         << " zycieMax=" << ust.glonZycieMax
         << endl;
}

void drukujOrganizm(string nazwa, const Organizm& o) {
    cout << nazwa << endl;
    cout << "licznikZycie: " << o.stanLicznikaZycia()
         << " licznikPosilkow: " << o.stanLicznikaPosilkow() << endl
         << "limitPosilkow: " << o.limitPosilkow
         << " kosztPotomka: " << o.kosztPotomka << endl
         << "glodny: " << o.glodny()
         << " poczkujacy: " << o.paczkujacy() << endl << endl;
}

string nazwaRodzaju(RodzajMieszkanca rodzaj) {
    switch(rodzaj) {
        case GLON: return "GLON";
        case GRZYB: return "GRZYB";
        case BAKTERIA: return "BAKTERIA";
        case PUSTKA: return "PUSTKA";
        case SCIANA: return "ŚCIANA";
        case TRUP: return "TRUP";
        case NIEZNANE: return "NIEZNANE";
    }
}
