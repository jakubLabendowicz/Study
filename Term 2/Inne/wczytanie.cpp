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

int main()
{
    student* st = nullptr;
    int liczba_studentow;
    wczytaj_dane_studentow("studenci.csv", st, liczba_studentow);


    cout <<endl<<endl;
    for (int i = 0; i< liczba_studentow; i++)
        cout << st[i].imie<<" "<<st[i].nazwisko<<" "<<st[i].ocena<<endl;
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

