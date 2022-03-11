#include <iostream>

using namespace std;

double interpolacjaNevilla(double x[],double y[],int n, double p){

    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
          y[j]= y[j + 1] + (y[j + 1] - y[j]) * (p - x[i]) / (x[i] - x[j]);
        }

    }
    return y[0];

/*
     double Q[n][n];
    int i,j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Q[i][j] = 0.0;

   for (i = 0; i < n; i++)
        Q[i][0] = y[i];


    for (i = 1; i < n; i++) {
        for (j = 1; j <= i; j++) {
            Q[i][j] = ((p - x[i - j])*(Q[i][j - 1])
                        - (p - x[i])*(Q[i - 1][j - 1]))/(x[i] - x[i - j]);
        }
    }

    /*
    cout<<"Macierz \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2f ", Q[i][j]);
        }
        cout<<endl;
    }



    return Q[n-1][n-1];
*/

}


int main(){
    int n;
    double p;
    while(1){
        cout<<"Podaj ilosc wezlow: "; cin>>n;
        double *x = new double[n];
        double *y = new double[n];

        for (int i=0; i<n; i++){
            cout<<" x["<<i<<"] = "; cin>>x[i];
            cout<<" f["<<x[i]<<"] = "; cin>>y[i];
            if(x[i]<=x[i-1] && i!=0){
                cout<<"Numery wiezlow musza byc miedzy soba rozne i ulozone w porzadku rosnacym \n";
                i--;
            }

        }
        cout<<endl<<endl;


        bool punktDoPodania=true;
        while(punktDoPodania){
            cout<<"Podaj punkt p "; cin>>p;

            if(p>=x[0] && p<=x[n-1]) punktDoPodania=false;
            else cout<<"Punkt "<<p<<"nie nalezy do <"<<x[0]<<","<<x[n-1]<<"> \n";
       }
        cout<<"Wartosc funkcji w x = "<<p<<" to y ~~ "<<interpolacjaNevilla(x,y,n,p)<<endl;


        delete [] x;
        delete [] y;

    cout<<endl<<endl<<endl;

    }
    return 0;
}
