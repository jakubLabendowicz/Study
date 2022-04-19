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
void run(stos* & top);
void pop(stos* & top);


int main()
{
    ifstream task("task.txt");
    char znak;
    stos *top = nullptr;
    while(!task.eof())
    {
        task.get(znak);
        switch(znak)
        {
            case '>': pop(top); break;
            case '<': task.get(znak); push(top,znak); break;
            case '|': run(top); break;
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

void run(stos* & top)
{
    while(!isEmpty(top))
    {
        cout << (char)get_top(top);
        pop(top);
    }
}

void pop(stos* & top)
{
    stos* temp = top;
    top = top->next;
    delete temp;
}


