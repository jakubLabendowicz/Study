#include <iostream>
#include <stack>

using namespace std;

int horner(int tab[], int n, int p)
{
    int wynik=tab[0];
    for(int i=1;i<=n;i++)
    {
        wynik=wynik*p + tab[i];
    }
    return wynik;
}
int silnia(int n)
{
    double sil=1;
    for(int i=n;i>1;i--) sil*=i;
    return sil;
}
int horner2(int tab[], int n, int p)
{
    double pochodna;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0+i;j--)
        {
            tab[j]=tab[j]+tab[j+1]*p;
        }
    }

    for(int i=0;i<=n;i++)
    {
        pochodna=tab[i]*silnia(i);
        cout<<"Pochodna "<<i<<" stopnia wynosi: "<<pochodna<<endl;
    }
}
int main()
{
    stack <int> stos;
    int n,x,punkt;
    cout<<"podaj stopien wielomianu:";
    cin>>n;
    int tab[n+1];
    for (int i=n;i>=0;i--)
    {
        cout<<"Wprowadz wspolczynnik x^"<<i<<": ";
        cin>>x;
        tab[i]=x;
    }

    cout<<"podaj szukany punkt: ";
    cin>>punkt;

    cout<<"wartosc wielomianu w punkcie "<<punkt<<" wynosi: "<<horner(tab,n,punkt)<<endl;
    horner2(tab,n,punkt);
    return 0;
}
