#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <locale.h>

using namespace std;

int main()
{
    ifstream task("task.txt");
    char znak;
    while(!task.eof())
    {
        task.get(znak);
        cout << znak;
    }
    return 0;
}
