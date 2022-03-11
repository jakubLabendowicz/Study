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

void newton(int n, int p, int x[],int y[])
{
    double iloczyn=1,wynik=0;
    for (int i=1;i<n;i++)
    {
        for (int j=n-1;j>=i;j--)
        {
            y[j]=(y[j]-y[j-1])/(x[j]-x[j-1]);
        }
    }
    for (int i=0;i<n;i++)
    {
        wynik+=y[i]*iloczyn;
        iloczyn=iloczyn*(p-x[i]);
    }

    cout<<"Wynik: "<<wynik;
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
        newton(n,p,x,y);
    }

    else cout<<"njd";
    return 0;
}
