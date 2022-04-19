#include <iostream>
#include <string>

using namespace std;

void naiwny(string tekst, string wzorzec, int dlt, int dlw);
void kmp(string wzorzec, string tekst, int dlw, int dlt, int *p);
void zbudujTabliceDopasowana(string wzorzec, int dlw, int *p);

int main()
{
    string a, w;
    int dlugosc_tekstu, dlugosc_wzorca, *tab;

    tab = nullptr;
    int odp = 1;
    while(odp > 0)
    {
        cout << "1. Pobierz tekst" << endl;
        cout << "2. Wczytaj wzorzec" << endl;
        cout << "3. Wyszukaj wzorzec w tekscie za pomoc� algorytmu naiwnego" << endl;
        cout << "4. Wyszukaj wzorzec za pomoc� algorytmu  Knutha-Morrisa-Pratta" << endl;
        cout << "0. Koniec" << endl;
        cin >> odp;



    switch(odp)
    {
        case 1:
            cout << "Podaj tekst: \n";
            cin >> a;
            dlugosc_tekstu = a.length();
            tab = new int[dlugosc_tekstu];
            break;
        case 2:
            cout << "Podaj wzorzec: \n";
            cin >> w;
            dlugosc_wzorca = w.length();
            break;
        case 3:
            naiwny(a, w, dlugosc_tekstu, dlugosc_wzorca);
            break;
        case 4:
            zbudujTabliceDopasowana(w, dlugosc_wzorca, tab);
            kmp(w, a, dlugosc_wzorca, dlugosc_tekstu, tab);
            break;
        case 0:
            delete [] tab;
            return 0;
            break;
}
    }
    delete [] tab;
    return 0;
}

void naiwny(string tekst, string wzorzec, int dlt, int dlw)
{
    int i = 0;
    while(i <= dlt - dlw)
    {
        int j = 0;
        while(j < dlw && wzorzec[j] == tekst[i+j])
        {
            j++;
        }
        if(j == dlw)
        {
            cout << i << " ";
        }

        i++;
    }
    cout << "\n";

}

void zbudujTabliceDopasowana(string wzorzec, int dlw, int *p)
{
    p[0] = 0;
    p[1] = 0;
    int t = 0;
    int i = 1;

    while(i < dlw)
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

void kmp(string wzorzec, string tekst, int dlw, int dlt, int *p)
{
    int i = 0;
    int j = 0;

    while(i < dlt - dlw + 1)
    {
        while(wzorzec[j] == tekst[i + j] && j < dlw)
        {
            j++;
        }

        if(j == dlw)
        {
            cout << i << " ";
        }

        i = i + max(1, j - p[j]);
        j = p[j];
    }
    cout << "\n";
}
