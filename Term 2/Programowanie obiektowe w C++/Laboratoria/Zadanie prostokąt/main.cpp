#include <iostream>
#include "zlab03.h"
using namespace std;

int main()
{
    cout<<"Labolatorium 03"<<endl;
    Prostokat p1;
    Prostokat p2("koc",1.4,2.2);
    Prostokat p3("pulapka",-2,-3);


    cout.precision(2);
    cout<<p1.doTekstu()<<endl;
    cout<<p2.doTekstu()<<endl;
    cout<<p3.doTekstu()<<endl;

    p3.zmienBoki(2,3);
    cout<<endl<<p3.doTekstu()<<endl;
    cout<<endl<<" Uzycie metody obiektu:"<<endl;
    cout<<" Nazwa: "<<p2.jakaNazwa()<<endl
       <<"Poprawny: "<<p2.czyPoprawny()<<endl
        <<"Obwod= :"<<p2.podajObwod()<<endl
       <<" Pole=:"<<p2.podajPole()<<endl;


    return 0;
}
