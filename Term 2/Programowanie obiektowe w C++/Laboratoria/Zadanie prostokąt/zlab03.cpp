#include "zlab03.h"
#include<iostream>
using namespace  std;


bool Prostokat::czyPoprawny(double bok1, double bok2)

{
    return bok1>0 && bok2>0;
}

void Prostokat::ObliczObwod()
{
    obwod=2*(bok1+bok2);
}

void Prostokat::obliczPole()
{
    pole=bok1*bok2;
}

Prostokat::Prostokat(string n,double a,double b)
    :nazwa(n)
{
    poprawny=czyPoprawny(a,b);

    if(poprawny)
    {
        bok1=a;
        bok2=b;
        obliczPole();
        ObliczObwod();

    }else{
        bok1=bok2=pole=obwod=0;
    }


}
Prostokat::~Prostokat()
{
    cout<<" Prostokat: "<<nazwa
       <<" znika. "<<endl;

}
bool Prostokat::czyPoprawny()
{
    return  poprawny;
}
const::string &Prostokat::jakaNazwa()
{
    return  nazwa;
}
double Prostokat::podajPole()
{
    return pole;
}
double Prostokat::podajObwod()
{
    return obwod;
}
bool Prostokat::zmienBoki(double a, double b)
{
    if(czyPoprawny(a,b))
    {
        poprawny=true;
        bok1=a;
        bok2=b;
        obliczPole();
        ObliczObwod();
        return  true;
    }return false;
}
string Prostokat::doTekstu()
{
    string napis ="";
    napis = "Prostokat o nazwie: "+ nazwa
            + " bok1=" + to_string(bok1)
            + " bok2=" + to_string(bok2);
    if(poprawny) napis+=" obwod="+ to_string(obwod)
            +" pole=" + to_string(pole);
    else napis +=" !Figura niepoprawna.";
    return napis;





}
