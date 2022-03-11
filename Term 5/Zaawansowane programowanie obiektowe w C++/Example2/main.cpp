#include <iostream>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
using namespace std;

//void whoWorkMoreThan5Years(Employee** table, table_size)
//{

//}

//void howManyEarnLessThanMeanBonus(Employee** table, table_size)
//{

//}


int main()
{
   Figure* f1=new Square(4);
   Figure* f2=new Circle(2);

   f1->calculateArea();
   f1->show();

   f2->calculateArea();
   f2->show();

   delete f1;
   delete f2;

   Figure *f3;
   Square s1(4);
   f3=&s1;
   f3->calculateArea();
   f3->show();

   Figure* tab[3];
   tab[0]=new Square(4);
   tab[1]=new Square(2);
   tab[2]=new Circle(5);
   for(int i=0;i<3;i++){
    tab[i]->calculateArea();
    delete tab[i];
   }
   return 0;
}
