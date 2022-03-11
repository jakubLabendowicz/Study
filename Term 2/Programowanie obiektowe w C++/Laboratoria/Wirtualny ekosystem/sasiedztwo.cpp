#include "sasiedztwo.h"
#include "ustawienia.h"
#include "generatorlosowy.h"

Polozenie Sasiedztwo::losujPolozenie()
{
unsigned short min = 0, max=8;
return static_cast<Polozenie>
(GeneratorLosowy::losujPomiedzy(min,max));
}

Sasiedztwo::Sasiedztwo(RodzajMieszkanca rodzaj)
{
for(auto i : {0,1,2})
for(auto j: {0,1,2})
sasiad[i][j] = rodzaj;

sasiad[1][1] = NIEZNANE;
}

void Sasiedztwo::okreslSasiada
(Polozenie polozenie, RodzajMieszkanca rodzaj)
{
if(polozenie != NIGDZIE)
*elementWewnetrzny(polozenie) = rodzaj;
}

RodzajMieszkanca Sasiedztwo::
ktoJestSasiadem(Polozenie polozenie)
{
if(polozenie != NIGDZIE)
return * elementWewnetrzny(polozenie);
else return NIEZNANE;
}

unsigned short Sasiedztwo::
ile(RodzajMieszkanca rodzaj) const
{
unsigned short licznik = 0;

for(int i : {0,1,2})
for(int j: {0,1,2}){
if(i==1 && j==1) continue;
if(sasiad[i][j]==rodzaj) licznik++;
}

return licznik;
}

Polozenie Sasiedztwo::
losujSasiada(RodzajMieszkanca rodzaj)
{
if(ile(rodzaj)==0) return NIGDZIE;
else{
Polozenie polozenie = Sasiedztwo::losujPolozenie();

while(ktoJestSasiadem(polozenie) != rodzaj)
polozenie = Sasiedztwo::losujPolozenie();

return polozenie;
}
}

void Sasiedztwo::
zmienIdeksyWgPolozenia(Polozenie polozenie,
long &wiersz, long &kolumna)
{
if(polozenie==PG || polozenie==P || polozenie==PD)
kolumna++;
else if(polozenie==LG || polozenie==L | polozenie==LD)
kolumna--;

if(polozenie==LG || polozenie==G || polozenie==PG)
wiersz--;
else if(polozenie==LD || polozenie==D ||polozenie==PD)
wiersz++;
}

void Sasiedztwo::
zmienIdeksyWgPolozenia(Polozenie polozenie,
unsigned int &wiersz, unsigned int &kolumna)
{
long w = static_cast<long>(wiersz);
long k = static_cast<long>(kolumna);

zmienIdeksyWgPolozenia(polozenie,w,k);

wiersz = static_cast<unsigned int>(w);
kolumna = static_cast<unsigned int>(k);
}
