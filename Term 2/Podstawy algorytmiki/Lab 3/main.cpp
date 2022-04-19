#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
struct student
{
    string imie;
    string nazwisko;
    int ocena;
};

void wczytaj_dane_studentow(string sciezka, student* &studenci, int &liczba_studentow);

void wyswietl_studentow(student* st, int n);

void usun_tablice_studentow(student *&st);

void podzialFlagaPolska(student* st, int liczba_studentow);

void podzialFlagaFrancuska(student* st, int liczba_studentow);

int main()
{
    student* st = nullptr;
    int liczba_studentow;


    int loop = 1;
    while(loop == 1)
    {
        cout << "Menu" << endl;
        cout << "1) Wczytaj dane z pliku" << endl;
        cout << "2) Zwolnij pamiec;" << endl;
        cout << "3) Podziel zbior studentow na dwa podzbiory za pomoca algorytmu Flaga Polska" << endl;
        cout << "4) Podziel zbior studentow na trzy podzbiory za pomoca algorytmu Flaga Francuzka" << endl;
        cout << "0) Koniec" << endl;
        cout << endl;

        int wybor;
        cin >> wybor;

        switch(wybor)
        {
            case 1:
                wczytaj_dane_studentow("studenci.csv", st, liczba_studentow);
            break;
            case 2:
                usun_tablice_studentow(st);
            break;
            case 3:
                podzialFlagaPolska(st, liczba_studentow);
            break;
            case 4:
                podzialFlagaFrancuska(st, liczba_studentow);
            break;
            case 0:
                loop = 0;
            break;
        }
    }
    return 0;
}

void wczytaj_dane_studentow(string sciezka, student* &studenci, int &liczba_studentow)
{
    if (studenci!=nullptr)
        return;

    ifstream plik;
    plik.open(sciezka);

    string linia;
    plik >> liczba_studentow;
    studenci = new student[liczba_studentow];
    plik >> linia;
    string temp_ocena,temp_imie,temp_nazwisko;


    for(int i=0; i<liczba_studentow; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, temp_imie, ';');
        getline(ss, temp_nazwisko, ';');
        getline(ss, temp_ocena);

        studenci[i].imie = temp_imie;
        studenci[i].nazwisko = temp_nazwisko;
        studenci[i].ocena = atoi(temp_ocena.c_str());
    }
    plik.close();
}

void wyswietl_studentow(student* st, int liczba_studentow)
{
    for (int i = 0; i< liczba_studentow; i++)
        cout << st[i].imie<<" "<<st[i].nazwisko<<" "<<st[i].ocena<<endl;
}

void usun_tablice_studentow(student *&st)
{
    delete [] st;
}

void podzialFlagaPolska(student* st, int liczba_studentow)
{
    int granica = 10;
    int i =0;
    int j = liczba_studentow-1;
    while(i<j)
    {
        while(st[i].ocena<=granica && i<j)
        {
            i=i+1;
        }
        while(st[j].ocena>granica && i<j)
        {
            j= j-1;
        }
        if(i<j)
        {
            swap(st[i], st[j]);
            i=i+1;
            j=j-1;
        }
    }

    int podzial;

    if(st[i].ocena<=granica)
    {
        podzial = i+1;
    }
    else{
        podzial = i;
    }

    cout << "Studenci, ktorzy otrzymali <=10 punktow: " << endl;
    for (int a = 0; a< podzial; a++)
        cout << st[a].imie<<" "<<st[a].nazwisko<<" "<<st[a].ocena<<endl;
    cout << endl;

    cout << "Studenci, ktorzy otrzymali >10 punktow: " << endl;
    for (int a = podzial; a< liczba_studentow; a++)
        cout << st[a].imie<<" "<<st[a].nazwisko<<" "<<st[a].ocena<<endl;
    cout << endl;
}

void podzialFlagaFrancuska(student* st, int liczba_studentow)
{
    int i =-1;
    int j=0;
    int k = liczba_studentow;
    while(j<k)
    {
        if(st[j].ocena%3==0)
        {
            i++;
            swap(st[i],st[j]);
            j++;
        }
        else
        {
            if(st[j].ocena%3==2)
            {
                k--;
                swap(st[k],st[j]);
            }
            else
            {
                j++;
            }
        }
    }

    cout<<"Pierwszy podzbior:"<<endl;
    for(int a=0;a<=i;a++)
    {
        cout<<st[a].imie<<" "<<st[a].nazwisko<<" "<<st[a].ocena<<endl;
    }
    cout<<" "<<endl;
    cout<<"Drugi:"<<endl;
    for(int a=i+1;a<j;a++)
    {
        cout<<st[a].imie<<" "<<st[a].nazwisko<<" "<<st[a].ocena<<endl;
    }
    cout<<" "<<endl;
    cout<<"Trzeci:"<<endl;

    for(int a=j;a<liczba_studentow;a++)
    {
        cout<<st[a].imie<<" "<<st[a].nazwisko<<" "<<st[a].ocena<<endl;
    }
}
