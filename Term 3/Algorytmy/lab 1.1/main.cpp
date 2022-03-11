#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int liczba,system;

    cout<<"podaj liczbe: ";
    cin>>liczba;
    cout<<"podaj system liczbowy: ";
    cin>>system;

    stack <int> stos;

    while(liczba!=0)
    {
        stos.push(liczba%system);
        liczba/=system;
    }

    while(!stos.empty())
    {
        switch (stos.top())
        {
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        default:
            cout<<stos.top();
            break;
        }
        cout<<" ";
        stos.pop();
    }
    return 0;
}
