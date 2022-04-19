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
int podzialFlagaPolska(student* st, int liczba_studentow, int pivot);
void sortowanieQuickSortHoar(student* st, int liczba_studentow);
void sortowanieQuickSortLomuto(student* st, int poczatek, int liczba_studentow);

int main()
{
    student* st = nullptr;
    int liczba_studentow;


    int loop = 1;
    while(loop == 1)
    {
        cout << "Menu" << endl;
        cout << "1) Wczytaj dane" << endl;
        cout << "2) Zwolnij pamiec" << endl;
        cout << "3) Posortuj Quicksort z zastosowaniem Flagi Polskiej (Wersja Tonyego Hoarea)" << endl;
        cout << "4) Posortuj Quicksort za pomoca metody Nicka Lomuto" << endl;
        cout << "0) Koniec" << endl;
        cout << endl;

        int wybor;
        cin >> wybor;
        cout << endl;

        switch(wybor)
        {
            case 1:
                wczytaj_dane_studentow("studenci.csv", st, liczba_studentow);
                wyswietl_studentow(st, liczba_studentow);
            break;
            case 2:
                usun_tablice_studentow(st);
            break;
            case 3:
                sortowanieQuickSortHoar(st, liczba_studentow);
                wyswietl_studentow(st, liczba_studentow);
            break;
            case 4:
                sortowanieQuickSortLomuto(st, 0, liczba_studentow-1);
                wyswietl_studentow(st, liczba_studentow);
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
    cout << "------ Tablica ------" << endl;
    for (int i = 0; i< liczba_studentow; i++)
        cout << st[i].imie<<" "<<st[i].nazwisko<<" "<<st[i].ocena<<endl;
    cout << endl;
}

void usun_tablice_studentow(student *&st)
{
    delete [] st;
}

int podzialFlagaPolska(student* st, int liczba_studentow, int pivot)
{
    int i = 0;
    int j = liczba_studentow-1;
    while(i<j)
    {
        while(st[i].ocena<=pivot && i<j)
        {
            i=i+1;
        }
        while(st[j].ocena>pivot && i<j)
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

    if(st[i].ocena<=pivot)
    {
        podzial = i+1;
    }
    else{
        podzial = i;
    }

    return podzial;
}

void sortowanieQuickSortHoar(student* st, int liczba_studentow)
{
    int srodek, pivot, granica;
    if(liczba_studentow<=1) return;

    srodek = liczba_studentow/2;
    pivot = st[srodek].ocena;
    student Pivot = st[srodek];

    st[srodek]=st[liczba_studentow-1];
    granica = podzialFlagaPolska(st, liczba_studentow-1, pivot);
    st[liczba_studentow-1]=st[granica];
    st[granica]=Pivot;
    sortowanieQuickSortHoar(st, granica);
    sortowanieQuickSortHoar(st+granica+1, liczba_studentow-granica-1);
}

void sortowanieQuickSortLomuto(student* st, int poczatek, int liczba_studentow)
{
    int srodek, granica;

    srodek = (poczatek+liczba_studentow)/2;
    student Pivot = st[srodek];
    st[srodek] = st[liczba_studentow];
    granica = poczatek;

    for(int i = poczatek; i < liczba_studentow; i++)
    {
        if(st[i].ocena<Pivot.ocena)
        {
            swap(st[granica], st[i]);
            granica = granica+1;
        }
    }

    st[liczba_studentow]=st[granica];
    st[granica]=Pivot;

    if(poczatek<granica-1)
    {
        sortowanieQuickSortLomuto(st, poczatek, granica-1);
    }

    if(granica+1<liczba_studentow)
    {
        sortowanieQuickSortLomuto(st, granica+1, liczba_studentow);
    }
}
