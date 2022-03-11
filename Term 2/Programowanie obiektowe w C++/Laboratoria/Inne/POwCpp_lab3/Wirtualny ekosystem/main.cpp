#include <iostream>
#include "organizm.h"
using namespace std;
void drukujOrganizm(const Organizm & o);
int main()
{



        //Test kreacji obiektow
        Organizm organizm1(10,3,2);
        Organizm organizm2=organizm1;
        Organizm organizm3(organizm1);


        cout<<" Wynik testu :"
           <<endl<<endl;
        cout<<" Organizm1 "<<endl;
            drukujOrganizm(organizm1);
            cout<<" Organizm2 "<<endl;
                drukujOrganizm(organizm2);
                cout<<" Organizm3 "<<endl;
                    drukujOrganizm(organizm3);



           //Test niezaleznosci obiektow
                    organizm1.posilek();
                    organizm2.posilek();
                    organizm3.posilek();
                    organizm3.krokSymulacji();


                    cout<<"Wynik testu :"
                    <<endl<<endl;
                    cout<<" Organizm1 :"<<endl;
                    drukujOrganizm(organizm1);
                    cout<<" Organizm2 :"<<endl;
                    drukujOrganizm(organizm2);
                    cout<<" Organizm3 :"<<endl;
                    drukujOrganizm(organizm3);

                    //Test symulcaji
                    Organizm organizm4(8,3,2);
                    cout<<"Wynik testu :"
                    <<endl<<endl;
                    cout<<"Stan poczatkowy : "
                       <<endl;
                    drukujOrganizm(organizm4);

                    for(int i=1;i<11;i++)
                    {
                        organizm4.krokSymulacji();
                        if(organizm4.paczkujacy())
                        {
                            organizm4.potomek();
                            cout<<" -->Potomek";

                        }else organizm4.posilek();
                        cout<<"Po wykonaniu kroku symulacji : "<<i<<endl;
                        drukujOrganizm(organizm4);
                    }






}

void drukujOrganizm(const Organizm & o)
{
 cout<<" Licznik zycia : "
    <<o.stanLicznikaZycia()
   << " licznikPosilkow:"
   <<o.stanLicznikaPosilkow()<<endl
  <<" limitPosilkow : "
 <<o.limitPosilkow
 <<" koszt potomka : "
 <<o.kosztPotomka<<endl
 <<"glodny : "<<o.glodny()
 <<" paczkujacy: "<<o.paczkujacy()<<endl<<endl;

}
