#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int pow2(int a,int b);

int make_hash(char s, int off, int p, int exp);

int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp);

void naiwny(string tekst, string wzorzec, int spr, int dlugoscWzorca);

void kr(string pattern, string text, int lenP, int lenT, int p, int off);

int main()
{
    ifstream plik("tekst.txt");
    string wzorzec;
    getline(plik, wzorzec);

    string analizowana_linijka;
    int i = 0;
    while(getline(plik, analizowana_linijka))
    {
        cout << "Linijka numer " << i + 1 << ": " << analizowana_linijka << endl;
        kr(wzorzec, analizowana_linijka, wzorzec.size(), analizowana_linijka.size(), 3, 97);
        i++;
    }

    plik.close();
    return 0;
}

int pow2(int a,int b)
{
    int w=1;
    for (int i=0;i<b;i++)
    {
        w=w*a;
    }
    return w;
}

int make_hash(char s, int off, int p, int exp)
{
    int hash = 0;
    hash = hash +((int)s-off)*pow2(p, exp);
    return hash;
}

int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp)
{
    int u_hash = hash-((int)s_prev-off)*pow2(p, exp);
    u_hash = u_hash*p;
    u_hash = u_hash+((int)s_next-off);
    return u_hash;
}

void naiwny(string tekst, string wzorzec, int spr, int dlugoscWzorca)
{
    int odp = 1;
    int i = 0;
    for(int k = spr; k < dlugoscWzorca; k++)
    {
        if(wzorzec[i] != tekst[k])
        {
            odp = 0;
            i++;
        }
    }

    if(odp == 1)
    {
        cout << "Pozycja wzorca w tekscie: " << spr <<endl;
    }
}

void kr(string pattern, string text, int lenP, int lenT, int p, int off)
{
    int hashP = 0;
    int hashT = 0;
    int i = 0;
    while(i<lenP)
    {
        hashP = hashP + make_hash(pattern[i], off, p, lenP - i - 1);
        hashT = hashT + make_hash(text[i], off, p, lenP - i - 1);
        i = i + 1;
    }

    i = lenP;
    int j = 0;
    while(i<=lenT)
    {
        if(hashP == hashT)
        {
            naiwny(text, pattern, j, pattern.size());
        }
        if(i<lenT)
        {
            hashT = update_hash(hashT, text[j], text[i], off, p, lenP-1);
        }
        i = i + 1;
        j = j + 1;
    }
    cout << endl;
}
