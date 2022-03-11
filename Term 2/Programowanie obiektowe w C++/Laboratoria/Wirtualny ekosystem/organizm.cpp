#include "organizm.h"
#include <iostream>




using namespace std;

void Organizm::krokSymulacji()
{
 if(zywy()) licznikZycia--;

}

Organizm::Organizm(unsigned short dlugoscZycia,unsigned short limitPosilkow,unsigned short kosztPotomka):

limitPosilkow(limitPosilkow),
  kosztPotomka(kosztPotomka),
  licznikZycia(dlugoscZycia),
  licznikPosilkow(0)
{

}
bool Organizm::posilek()

{
    if(glodny()){
        licznikPosilkow++;
        return true;

    }else return false;
}


bool Organizm::potomek()
{
    if(paczkujacy()){
        licznikPosilkow-=kosztPotomka;
        return true;

    }else return false;
}



