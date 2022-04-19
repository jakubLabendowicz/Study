#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student
    {
        string imie;
        string nazwisko;
        int punkty;
    };

int wczytajLiczbeStudentow()
{
    return n;
}

void sortowanieQuickSort(student* tab, int n, int tryb);

void wczytajStudentow(student*&tab, int n)
{
    student * tab = new student [n];

    string sciezka, linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    student* tab;
    sciezka = "studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;

    for(int i = 0; i < 2; i++)
    {
        plik >> sredniki;
    }

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik >> linia;
        istringstream ss(linia);
        getline (ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, tab[i].punkty);
    }

    plik.close();
}

void usunTabliceStudentow(student *&tab)
{
    delete [] tab;
}

void wyswietlStudentow(student* tab, int n)
{
    while(int i = 0; i<n; n++)
    {
        cout << tab[i].imie << "   " << tab[i].nazwisko << "   " << tab[i].punkty << endl;
    }
}

int main()
{
    int n, tryb;
    student * tab;

    cout << "Podaj tryb sortowania: ";
    cin >> tryb >> endl;

    n = wczytajLiczbeStudentow();

    wczytajStudentow(tab, n);
    sortowanieQuickSort(tab, n, tryb);
    wyswietlStudentow(tab, n);
    usunTabliceStudentow(tab);

    return 0;
}
