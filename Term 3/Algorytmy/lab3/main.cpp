#include <iostream>

using namespace std;

bool czyunikat(int n, int x[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (x[i]==x[j]) return false;
        }
    }
    return true;
}

bool czyp(int n, int p, int x[])
{
    int minn,maxx;
    minn=maxx=x[0];
    for (int i=1;i<n;i++)
    {
        if (x[i]>maxx) maxx=x[i];
        if (x[i]<minn) minn=x[i];
    }
    if (p>maxx || p<minn) return false;
    else return true;
}

void lagrange(int n, int p, int x[], int y[])
{
    float wynik=0;
    float wielomian;
    for (int i=0;i<n;i++)
    {
        wielomian=1;
        for (int j=0;j<n;j++)
        {
            if (j!=i) wielomian*=(p-x[j])/(x[i]-x[j]);
        }
        wynik+=y[i]*wielomian;
    }
    cout<<"przyblizona wartosc funkcji w punkcie "<<p<<" wynosi: "<<wynik;
}

int main()
{
    int n,p;
    cout << "Podaj ilosc wezlow: ";
    cin>>n;
    int x[n];
    int y[n];

    for(int i=0;i<n;i++)
    {
        cout<<"podaj wartosc "<<i<<" wezla: ";
        cin>>x[i];
        cout<<"podaj wartosc funkcji w punkcie "<<i<<" : ";
        cin>>y[i];
    }
    cout << "Podaj p: ";
    cin>>p;

    if (czyp(n,p,x)==true && czyunikat(n,x)==true)
    {
        cout<<"jd"<<endl;
        lagrange(n,p,x,y);
    }

    else cout<<"njd";
    return 0;
}
