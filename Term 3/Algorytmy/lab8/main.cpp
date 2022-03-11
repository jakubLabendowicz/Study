#include <iostream>
#include <math.h>

using namespace std;

void lagrange()
{
    double h[5]={0.236, 0.478, 0.568, 0.478, 0.236};
    double x[5]={-0.906, -0.538, 0, 0.538, 0.906};
    double wynik=0;
    for(int i=0;i<5;i++)
    {
        wynik+=h[i]*(1/sqrt(1+pow(x[i],2)));
    }
    cout<<"wynik lagrange: "<<wynik;
}

void hermit()
{
    double x[5]={-2.02, -0.958, 0, 0.958, 2.02};
    double h[5]={0.02, 0.393, 0.945, 0.393, 0.02};
    double wynik=0;
    for(int i=0;i<5;i++)
    {
        wynik+=h[i]*cos(x[i]);
    }
    cout<<"wynik hermit: "<<wynik;
}

void laguerre()
{
    double x[4]={0.322, 1.745, 4.536, 9.395};
    double h[4]={0.603154, 0.357419, 0.038888, 0.000539};
    double wynik=0;
    for(int i=0;i<4;i++)
    {
        wynik+=h[i]*exp(-x[i])*(sin(x[i])/x[i]);
    }
    cout<<"wynik laguerre: "<<wynik;
}

void czybyszew()
{
    double wynik=0;
    for(int i=0;i<4;i++)
    {
        wynik+=(3.14/4.0)*pow(cos(((2*i+1)*3.14)/8.0),2);
    }
    cout<<"wynik czybyszew: "<<wynik;
}
int main()
{
    int wybor=243;
    while(wybor>0)
    {
        cout<<endl<<"Dostepne metody"<<endl;
        cout<<"1. Lagrange"<<endl;
        cout<<"2. Hermit"<<endl;
        cout<<"3. Laguerre"<<endl;
        cout<<"4. Czybyszew"<<endl;
        cout<<"0. Koniec"<<endl;
        cout << "Wybierz metode: ";
        cin>>wybor;
        switch (wybor)
        {
            case 0:
                return 0;
            case 1:
                lagrange();
                break;
            case 2:
                hermit();
                break;
            case 3:
                laguerre();
                break;
            case 4:
                czybyszew();
                break;
        }
    }
}
