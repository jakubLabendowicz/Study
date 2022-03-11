#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a,b,c,d,x1,x2;
    char metoda;
    cout<<"podaj a: ";
    cin>>a;
    cout<<"podaj b: ";
    cin>>b;
    cout<<"podaj c: ";
    cin>>c;
    cout<<"wybierz metode A lub B:";
    cin>>metoda;
    switch (metoda)
    {
        case 'A':
            cout<<endl<<"metoda A"<<endl;
            d=(b*b)-(4*a*c);
            cout<<"delta: "<<d<<endl;
            if (d==0)
            {
                x1=(-b)/(2*a);
                cout<<"x0: "<<x1<<endl;
            }
            else if (d>0)
            {
                x1=(-b-sqrt(d))/(2*a);
                x2=(-b+sqrt(d))/(2*a);
                cout<<"x1: "<<x1<<endl;
                cout<<"x2: "<<x2<<endl;
            }
            else cout<<"brak miejsc zerowych";
        case 'B':
            cout<<endl<<"metoda B"<<endl;
            double signt,t;
            t=(-b)*(2*a);
            if (t>0) signt=1;
            else if (t==0) signt=0;
            else signt=-1;
            x1=t+(signt*(sqrt(pow(t,2)-(c/a))));
            x2=c/(a*x1);
            cout<<"x1: "<<x1<<endl;
            cout<<"x2: "<<x2<<endl;
    }
    return 0;
}
