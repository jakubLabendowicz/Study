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
void push(stos* & top, char newData);
void pop(stos* & top);
void zad5(stos* & stosik);

int main()
{
    ifstream task("task.txt");
    char znak;
    bool dodaj = false;
    stos *top = nullptr;
    while(!task.eof())
    {
        task.get(znak);
        if(znak=='<')
        {
            task.get(znak);
            push(top,znak);
        }
        if(znak=='>')
        {
            pop(top);
        }
        if(znak=='|')
        {
            zad5(top);
        }
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

void pop(stos* & top)
{
    stos* temp = top;
    top = top->next;
    delete temp;
}

void zad5(stos* & stosik)
{
    while(!isEmpty(stosik))
    {
        cout<< (char)get_top(stosik);
        pop(stosik);
    }
}
