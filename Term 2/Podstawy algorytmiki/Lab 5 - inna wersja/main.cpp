#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string podajTekst();
int podajDlugosc(string t);
void naiwny(string tekst, string wzorzec, int dlugoscTekstu, int dlugoscWzorca);
void zbudujTabliceDopasowan(string wzorzec, int dlugoscWzorca, int* p);
void kmp(string wzorzec, string tekst, int dlugoscWzorca, int dlugoscTekstu, int* p);

int main()
{
    int* p = nullptr;

    string tekst;
    int dlugoscTekstu;
    string wzorzec;
    int dlugoscWzorca;

    int loop = 1;
    while(loop == 1)
    {
        cout << "Menu" << endl;
        cout << "1. Podaj tekst" << endl;
        cout << "2. Podaj wzorzec" << endl;
        cout << "3. Wyszukaj wzorzec w tekscie za pomoca algorytmu naiwnego" << endl;
        cout << "4. Wyszukaj wzorzec w tekscie za pomoca algorytmu KMP" << endl;
        cout << "0. Koniec" << endl;
        cout << endl;

        int wybor;
        cin >> wybor;
        cout << endl;

        switch(wybor)
        {
            case 1:
                cout << "Tekst: ";
                tekst = podajTekst();
                dlugoscTekstu = podajDlugosc(tekst);
                cout << endl;
            break;
            case 2:
                cout << "Wzorzec: ";
                wzorzec = podajTekst();
                dlugoscWzorca = podajDlugosc(wzorzec);
                cout << endl;
            break;
            case 3:
                cout << "Algorytm: " << endl;
                naiwny(tekst, wzorzec, dlugoscTekstu, dlugoscWzorca);
                cout << endl;
            break;
            case 4:
                cout << "Algorytm: " << endl;
                p = new int [wzorzec.size()];
                zbudujTabliceDopasowan(wzorzec, dlugoscWzorca, p);
                kmp(wzorzec, tekst, dlugoscWzorca, dlugoscTekstu, p);
                cout << endl;
            break;
            case 0:
                loop = 0;
                delete [] p;
            break;
        }
    }
    delete [] p;
    return 0;
}

string podajTekst()
{
    string t;
    cin.ignore();
    getline(cin,t);
    return t;
}

int podajDlugosc(string t)
{
    return t.size();
}

void naiwny(string tekst, string wzorzec, int dlugoscTekstu, int dlugoscWzorca)
{
    for(int i = 0; i <= dlugoscTekstu - dlugoscWzorca; i++)
    {
        int j = 0;
        while(j < dlugoscWzorca && wzorzec[j] == tekst[i + j])
        {
            j++;
        }
        if(j == dlugoscWzorca)
        {
            cout << "Pozycja wzorca w tekscie: " << i << endl;
        }
    }
}

void zbudujTabliceDopasowan(string wzorzec, int dlugoscWzorca, int* p)
{
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    int i = 1;
    while(i < dlugoscWzorca)
    {
        while(t > 0 && wzorzec[t] != wzorzec[i])
        {
            t = p[t];
        }

        if(wzorzec[t] == wzorzec[i])
        {
            t++;
        }
        p[i + 1] = t;
        i++;
    }
}

void kmp(string wzorzec, string tekst, int dlugoscWzorca, int dlugoscTekstu, int* p)
{
    int i = 0;
    int j = 0;
    while(i < dlugoscTekstu - dlugoscWzorca + 1)
    {
        while(wzorzec[j] == tekst[i + j] && j < dlugoscWzorca)
        {
            j++;
        }
        if(j == dlugoscWzorca)
        {
            cout << "Pozycja wzorca w tekscie: " << i << endl;
        }
        i = i + max(1, j - p[j]);
        j = p[j];
    }
}
