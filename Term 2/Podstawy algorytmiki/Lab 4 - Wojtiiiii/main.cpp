#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <conio.h>
using namespace std;
struct studenci
{
    string imie;
    string nazwisko;
    int punkty;
};



void ZWolnijPamiec(studenci *&tablica)
{
    delete[] tablica;
    tablica=0;
}



void wczytajDaneZPliku(studenci *&tablica,int &ilestudentow,string sciezka);

int flagaPolska(studenci *tablica,int ile_studentow,int pivot);
void quicksort_fp(studenci *tablica,int ile_studentow);
void quicksortLomuto(studenci* tablica,int lewy,int prawy);
int main()
{
    bool program=true;
 studenci* Tablica=nullptr;
    while (program ==true)
    {



    int liczba_studentow;
    int wybor;
    cout<<endl<<endl<<endl;
    cout<<"Witaj w programie co chesz zrobic?";
    cout<<endl<<"Wczytaj dane nacisnij 1";
    cout<<endl<<"Zwolnij pamiec nacisnij 2";
    cout<<endl<<"quicksort flaga polska 3";
    cout<<endl<<"Flaga francuzka 4";
    cout<<endl<<"Koniec nacisnij 0";
    cout<<endl<<"Wybieram : ";
    cin>>wybor;
    switch(wybor)
    {
    case 1:

        wczytajDaneZPliku(Tablica,liczba_studentow,"studenci.csv");

        break;
    case 2:

       ZWolnijPamiec(Tablica);
        break;
    case 3:
        quicksort_fp(Tablica,liczba_studentow);
        for(int i=0;i<liczba_studentow;i++)
        {
            cout<<Tablica[i].punkty<<" "<<Tablica[i].imie<<" "<<Tablica[i].nazwisko<<endl;

        }
        break;
    case 4:

        quicksortLomuto(Tablica,0,liczba_studentow-1);
        for(int i=0;i<liczba_studentow;i++)
        {
            cout<<Tablica[i].punkty<<" "<<Tablica[i].imie<<" "<<Tablica[i].nazwisko<<endl;

        }

        break;
    case 0:
        program=false;break;
    default: cout<<endl<<"!Niepoprawny klawisz !"<<endl;break;
    }
    }
    return 0;
}

int flagaPolska(studenci *tablica,int ile_studentow,int pivot)

{

    int pierwszy_indeks_drugiego;
    int i=0;
    int j=ile_studentow-1;
    while(i<j)
    {
        while(tablica[i].punkty<=pivot&&i<j)
        {
            i=i+1;
        }
        while(tablica[j].punkty>pivot&&i<j)
        {
            j=j-1;
        }
        if(i<j)
        {
            swap(tablica[i],tablica[j]);
            i=i+1;
            j=j-1;
        }
    }
    if (tablica[i].punkty<=pivot)
    {
        pierwszy_indeks_drugiego= i+1;

    }
    else
    {
        pierwszy_indeks_drugiego=i;
    }

return pierwszy_indeks_drugiego;

}



void wczytajDaneZPliku(studenci* &tablica,int &ilestudentow,string sciezka)
{
    if (tablica!=nullptr)
        return ;

    string linia;

    fstream plik;
    plik.open(sciezka);
    plik>>ilestudentow;
    tablica=new studenci [ilestudentow];
    plik>>linia;
    string temp_ocena,temp_imie,temp_nazwisko;


    for(int i=0;i<ilestudentow;i++)
    {
        plik>>linia;
        cout<<linia<<endl;
        istringstream ss(linia);

        getline(ss, temp_imie ,';');
        getline(ss, temp_nazwisko,';');
        getline(ss, temp_ocena);

        tablica[i].imie=temp_imie;
        tablica[i].nazwisko=temp_nazwisko;
        tablica[i].punkty=atoi(temp_ocena.c_str());

    }


    plik.close();




}
void quicksort_fp(studenci *tablica,int ile_studentow)
{
    if(ile_studentow<=1) return ;

    int srodek=ile_studentow/2;
    int Pivot=tablica[srodek].punkty;
    studenci piwot=tablica[srodek];

    tablica[srodek]=tablica[ile_studentow-1];
    int granica=flagaPolska(tablica,ile_studentow-1,Pivot);
    tablica[ile_studentow-1]=tablica[granica];
    tablica[granica]=piwot;
    quicksort_fp(tablica,granica);
    quicksort_fp(tablica+granica+1,ile_studentow-granica-1);

}








void quicksortLomuto(studenci* tablica,int lewy,int prawy)
{

    int srodek=(lewy+prawy)/2;

    studenci piwot=tablica[srodek];
    tablica[srodek]=tablica[prawy];
    int granica=lewy;
    for(int i=lewy;i<=prawy;i++)
    {
        if(tablica[i].punkty<piwot.punkty)
        {
            swap(tablica[granica],tablica[i]);
            granica=granica+1;

        }

    }

    tablica[prawy]=tablica[granica];
    tablica[granica]=piwot;

    if(lewy<granica-1)
    {
        quicksortLomuto(tablica,lewy,granica-1);
    }

    if(granica+1<prawy)
    {
        quicksortLomuto(tablica,granica+1,prawy);
    }





}
