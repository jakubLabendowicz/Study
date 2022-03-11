#include "Prostokat.h"
#include <iostream>
#include <string>
using namespace std;

Prostokat::Prostokat(string n, double a, double b)
    :nazwa(n)
{
    poprawny = czyPoprawny(a, b);

    if (poprawny){
        bok1 = a;
        bok2 = b;
        obliczObwod();
        obliczPole();
    }
    else
        bok1 = bok2 = pole = obwod = 0;

}

Prostokat::~Prostokat(){
    cout << "Prostokat: " << nazwa << " znika." << endl;
}

bool Prostokat::czyPoprawny(double bok1, double bok2){
    return bok1 >0 && bok2 > 0;
}

void Prostokat::obliczObwod(){
   obwod = 2* (bok1 + bok2);
}

void Prostokat::obliczPole(){
    pole = bok1 * bok2;
}

bool Prostokat::czyPoprawny(){
    return czyPoprawny();
}

const std::string &Prostokat::jakaNazwa(){
    return nazwa;
}

double Prostokat::podajPole(){
    return pole;
}

double Prostokat::podajObwod(){
    return obwod;
}

bool Prostokat::zmienBoki(double a, double b){
    if (czyPoprawny(a, b)){
        poprawny = true;
        bok1 = a;
        bok2 = a;
        obliczObwod();
        obliczPole();
        return true;
    }
    return false;
}

string Prostokat::doTekstu() {
    string napis = "";
    napis = "Prostokat o nazwie " + nazwa
            + " bok1 = " + to_string(bok1)
            + " bok2 = " + to_string(bok2);
    if (poprawny) napis += " obwod = " + to_string(obwod)
            + " pole = " + to_string(pole);
    else napis += " !Figura niepoprawna.";

    return napis;
}
