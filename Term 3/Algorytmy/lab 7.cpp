#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>


using namespace std;


void przyklad1(double y[], int m, double& h);
void przyklad2(double y[], int m, double& h);
void trapezy(double y[], int m, double h);
void simpson(double y[], int m, double h);
void meth( int m,  int method, int przyklad);

void simpson(int m, int przyklad);
void trapezy( int m, int opt);

int main(){


    int option,method,m;
    double h=1;
    while(1){
        cout<<"Wybierz : \n 1=sin^2x+2 \n 2=e^x*2x^3 \n 3=wyjscie \n ";
        cin>>option;
        if(option==3)break;
        cout<<"Wybierz metode 1-Trapezy, 2-Simson \n";
        cin>>method;
        cout<<"Podaj liczbe przedzialow,  \n";
        cin>>m;
        if(m<1) continue;


        double *y = new double[m+1];
        if(option==1){
          //  przyklad1(y,m,h);
             meth(m,method,option);
        }else if(option==2){
            //przyklad2(y,m,h);
           meth(m,method,option);
        }

        delete [] y;
    }

    return 0;
}

void meth( int m, int method,int przyklad){
    if(method==1)trapezy(m,przyklad);
    else if(method==2){
        if (m % 2 == 0) simpson(m,przyklad);
        else cout<<"Nie moge policzyc metoda Simpsona - liczba przedzialow nie jest parzysta"<<endl;
    }else{
        cout<<"Zla opcja \n";
    }



}
/*
void przyklad1(double y[], int m,double& h){
     h = 2*3.14 / m*1.0;

    double x = 0;
    for (int i=0; i<=m; i++){
        y[i] =  (2.0+ pow(sin(x),2));
        x +=h;
    }
}

void przyklad2(double y[], int m, double& h){
     h = 2.0 / (m*1.0);

    double x = 0;
    for (int i=0; i<=m; i++){
        y[i] =  exp(x)*2*pow(x,3);
        x += h;

    }


}
*/



/*
void trapezy(double y[], int m,double h){

    double wynik=0;

    for (int i=1; i<m; i++){
        wynik += y[i];
    }
    wynik = wynik + y[0]/2 + y[m]/2;
    wynik *=h;

    cout<<endl<<"Wg  metody trapezow wynik = "<<wynik<<endl;

}

void simpson(double y[], int m, double h){
    double p=0,np=0,wynik=0;

    for (int i=1; i<m; i+=2){
        np += y[i];
    }
    np *= 4;

    for (int i=2; i<m-1; i+=2){
        p += y[i];
    }
    p *= 2;

    wynik = np + p;

    wynik = wynik + y[0] + y[m];
    wynik *= h/3;

    cout<<"Wg  metody Simpsona wynik = "<<wynik<<endl;

}
*/

double getY(double x ){
    return (2.0+ pow(sin(x),2));
}

double getY2(double x ){
    return (exp(x)*2*x*x*x);
}

void trapezy( int m, int opt){

    double wynik=0,h,y;
    if(opt==1){
        h = 2*3.14 / m*1.0;

        double x = 0+h;
        for (int i=1; i<m; i++){
            y=getY(x);
             x +=h;
            wynik += y;

        }
        wynik+=getY(0)/2;
        wynik+=getY(2*3.14)/2;
        wynik *=h;
    }
    else if(opt==2){

         h = 2.0/(m*1.0);

        double x = 0;
        for (int i=1; i<m; i++){
             x +=h;
            wynik += getY2(x);

        }
        wynik= wynik +(getY2(0)/2)+(getY2(2)/2);
        wynik *=h;

    }
    cout<<endl<<"Wg  metody trapezow wynik = "<<wynik<<endl;

}


void simpson(int m, int przyklad){



    double p=0,np=0,wynik=0,h,y;
        if(przyklad==1){

        h = 2*3.14 / m*1.0;

        double x = 0+h;

            for (int i=1; i<m; i+=2){
            np += getY(x);
             x +=2*h;

        }
        np *= 4;

        x=0+2*h;
        for (int i=2; i<m-1; i+=2){
             p +=getY(x);
             x +=2*h;

        }
        p *= 2;

        wynik = np + p;

        wynik = wynik +getY(0)+ getY(2*3.14);
        wynik *= h/3;

    }else if(przyklad==2){
        h = 2.0 / m*1.0;

        double x = 0+h;

        for (int i=1; i<m; i+=2){
            y= getY2(x);
             x +=2*h;
            np += y;
        }
        np *= 4;

        x=0+2*h;
        for (int i=2; i<m-1; i+=2){
            y= getY2(x);
             x +=2*h;
            p += y;
        }
        p *= 2;

        wynik = np + p;

        wynik = wynik +getY2(0) + getY2(2);
        wynik *= h/3;


    }


    cout<<"Wg  metody Simpsona wynik = "<<wynik<<endl;

}


