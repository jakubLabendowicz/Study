#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <locale.h>

using namespace std;

struct stos
{
    char data;
    stos* next;
};

int get_top(stos* top);
bool isEmpty(stos* top);
void push(stos* $top, char newData);

int main()
{
    ifstream task("task.txt");
    char znak;
    stos *top = nullptr;
    while(!task.eof())
    {
        task.get(znak);
        push(top, znak);
    }
    return 0;
}
int get_top(stos* top)
{
    return top->data;
}

bool isEmpty(stos* top)
{
    return top == nullptr;
}

void push(stos* & top, char newData)
{
    stos* nowy = new stos;
    nowy->data = newData;
    nowy->next = top;
    top = nowy;
}
