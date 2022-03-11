#include <iostream>
#include <cmath>
using namespace std;



void lin(double x[],double y[], int n, double& a, double& b ){
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    for (int i=0;i<n;i++){
        xsum=xsum+x[i];                        // sigma(xi)
        ysum=ysum+y[i];                        // sigma(yi)
        x2sum=x2sum+pow(x[i],2);               // sigma(x^2)
        xysum=xysum+x[i]*y[i];                 // sigma(xi*yi)
    }
    a=(n*xysum-xsum*ysum)/(n*x2sum-xsum*xsum);
    b=(x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum);




}

void nonLin1(double x[], double y[], int n, double& a , double& b){
    for(int i=0;i<n;i++){
        x[i]=1/x[i];
    }
    lin(x,y,n,a,b);

}

void nonLin2(double x[], double y[] , int n,double& a, double& b){

    for(int i=0;i<n;i++){
        y[i]=log(y[i]);

    }
    lin(x,y,n,a,b);

    a=exp(a);
    b=exp(b);

}


int main(){
    int n;
    bool loop=true;
    while(loop){
        cout<<"Podaj ilosc wezlow: "; cin>>n;
        double *x = new double[n];
        double *y = new double[n];

        for (int i=0; i<n; i++){
            cout<<" x["<<i<<"] = "; cin>>x[i];
            cout<<" f["<<x[i]<<"] = "; cin>>y[i];

        }

        int opcja;
        cout<<"wybierz : \n  1=ax+b \n 2=b+a/x \n 3=b*a^x \n 4=wyjscie \n";
        cin>>opcja;
        double a=0;
        double b=0;
        switch(opcja){
            case 1: lin(x,y,n,a,b);
                cout<<"\n  aproksymacja : \n"<<a<<"x + "<<b<<endl;
                break;
            case 2: nonLin1(x,y,n,a,b);
                cout<<"\n  aproksymacja : \n"<<a<<"/x + "<<b<<endl;
                break;
            case 3:{
                    double xx[] = {1,2,3,5,7};
                    double yy[] ={1,exp(3),exp(6),exp(12),exp(18)};
                nonLin2(xx,yy,5,a,b);
                 cout<<"\n  aproksymacja : \n"<<a<<"^x * "<<b<<endl;
                 break;
            }
            case 4: loop=false;
                break;
        }

        delete [] x;
        delete [] y;

    cout<<endl<<endl<<endl;

    }
    return 0;
}
