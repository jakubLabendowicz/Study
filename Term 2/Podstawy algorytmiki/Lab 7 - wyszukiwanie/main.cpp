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

void wyszukiwanie_liniowe(student* &studenci, int liczba_studentow, int wartosc);

void wyszukiwanie_bisekcyjne(student* &studenci, int liczba_studentow, int wartosc);

int podzialFlagaPolska(student* st, int liczba_studentow, int pivot);
void sortowanieQuickSortHoar(student* st, int liczba_studentow);

int main()
{
    student* st = nullptr;
    int liczba_studentow;

    int loop = 1;
    while(loop == 1)
    {
        cout << "Menu" << endl;
        cout << "1) Wczytaj dane" << endl;
        cout << "2) Wyszukiwanie liniowe" << endl;
        cout << "3) Wyszukiwanie bisekcyjne" << endl;
        cout << "0) Koniec" << endl;
        cout << endl;

        int wybor;
        cout << "Wybor: ";
        cin >> wybor;
        cout << endl;

        switch(wybor)
        {
            case 1:
                wczytaj_dane_studentow("studenci.csv", st, liczba_studentow);

                for (int i = 0; i< liczba_studentow; i++)
                {
                    cout << st[i].imie<<" "<<st[i].nazwisko<<" "<<st[i].ocena<<endl;
                }
                cout << endl;
            break;
            case 2:
            {
                cout << "Podaj wartosc dla filtru: ";
                int wartosc;
                cin >> wartosc;
                cout << endl;
                wyszukiwanie_liniowe(st, liczba_studentow, wartosc);
                cout << endl;
            }
            break;
            case 3:
                cout << "Podaj wartosc dla filtru: ";
                int wartosc;
                cin >> wartosc;
                cout << endl;
                sortowanieQuickSortHoar(st, liczba_studentow);
                wyszukiwanie_bisekcyjne(st, liczba_studentow, wartosc);
                cout << endl;
            break;
            case 0:
                loop = 0;
            break;
        }
    }

    delete [] st;
    return 0;
}

void wczytaj_dane_studentow(string sciezka, student* &studenci, int &liczba_studentow)
{
    if (studenci!=nullptr)
        return;

    ifstream plik;
    plik.open(sciezka);

    string linia;
    plik >> liczba_studentow;   //wczytanie liczby studentow
    studenci = new student[liczba_studentow];   //
    plik >> linia; //dokonczenie wczytywania linijki z liczb¹ studentów
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

void wyszukiwanie_liniowe(student* &studenci, int liczba_studentow, int wartosc)
{
    ofstream plik_do_zapisu("liniowe.csv");
    int i = 0;
    int licz = 0;
    while(i<liczba_studentow)
    {
        if(studenci[i].ocena == wartosc)
        {
            plik_do_zapisu << studenci[i].imie << " " << studenci[i].nazwisko << " " << studenci[i].ocena << endl;
            licz = licz + 1;
        }
        i = i + 1;
    }
    if(licz == 0)
    {
        plik_do_zapisu << "Nie znaleziono" << endl;
        cout << "Nie znaleziono" << endl;
    }
    else
    {
        cout << "Filtrowanie zakoncone! " << "Znaleziono: " << licz << endl;
    }
    plik_do_zapisu.close();
}

void wyszukiwanie_bisekcyjne(student* &studenci, int liczba_studentow, int wartosc)
{
    ofstream plik_do_zapisu("bisekcyjne.csv");
    int lewy = 0;
    int prawy = liczba_studentow - 1;
    int srodek = 0;
    int licz = 0;
    int loop2 = 1;
    while(lewy<=prawy && loop2 == 1)
    {
        srodek = (lewy+prawy)/2;
        if(studenci[srodek].ocena == wartosc)
        {
            plik_do_zapisu << studenci[srodek].imie << " " << studenci[srodek].nazwisko << " " << studenci[srodek].ocena << endl;
            licz = licz + 1;

            int p = 1;
            while(studenci[srodek+p].ocena == wartosc && p<liczba_studentow-srodek)
            {
                plik_do_zapisu << studenci[srodek+p].imie << " " << studenci[srodek+p].nazwisko << " " << studenci[srodek+p].ocena << endl;
                licz = licz + 1;
                p++;
            }
            int l = 1;
            while(srodek-l>=0 && studenci[srodek-l].ocena == wartosc)
            {
                plik_do_zapisu << studenci[srodek-l].imie << " " << studenci[srodek-l].nazwisko << " " << studenci[srodek-l].ocena << endl;
                licz = licz + 1;
                l++;
            }
            loop2 = 0;
        }
        else if(wartosc<studenci[srodek].ocena)
        {
            prawy = srodek - 1;
        }
        else
        {
            lewy = srodek +1;
        }
    }

    if(licz == 0)
    {
        plik_do_zapisu << "Nie znaleziono" << endl;
        cout << "Nie znaleziono" << endl;
    }
    else
    {
        cout << "Filtrowanie zakoncone! " << "Znaleziono: " << licz << endl;
    }
    plik_do_zapisu.close();
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



