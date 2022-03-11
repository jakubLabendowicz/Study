#include <iostream>

using namespace std;

int horner(int tab[], int n, int p)
{   //pierwsza pochodna
    int k=1;
    for(int j=0;j<n;j++)
    {
        tab[j]=tab[j+1]*k;
    }
    //druga pochodna
    int g=1;
    for(int l=0;l<n-1;l++)
    {
        tab[l]=tab[l+1]*g;
    }
    //wartosc w niej
    int wynik=tab[0];
    for(int i=1;i<=n-2;i++)
    {
        wynik=wynik*p + tab[i];
    }
    return wynik;
}

int main()
{
    int n;
    int temp;
    int p;
    cout<<"podaj stopien wielomianu:";
    cin>>n;
    int tab[n+1];
    for (int i=n;i>=0;i--)
    {
        cout<<"Wprowadz wspolczynnik x^"<<i<<": ";
        cin>>temp;
        tab[i]=temp;
    }

    cout<<"podaj szukany punkt: ";
    cin>>p;

    cout<<"wartosc wielomianu w punkcie "<<p<<" wynosi: "<<horner(tab,n,p)<<endl;
    return 0;
}
