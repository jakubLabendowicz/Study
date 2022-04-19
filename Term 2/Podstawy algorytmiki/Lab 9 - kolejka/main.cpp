#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <locale.h>

using namespace std;

struct element
{
    char data;
    element* next = nullptr;
};

struct kolejka
{
    element* tail = nullptr;
    element* head = nullptr;
};

bool isEmpty(kolejka k)
{
    return k.head == nullptr;
}

void push(kolejka &k, char new_data)
{
    element* el = new element;
    el->data = new_data;
    if(isEmpty(k))
    {
        k.head = el;
    }
    else
    {
        k.tail->next = el;
    }
    k.tail = el;
}

void pop(kolejka &k)
{
    element* temp;
    temp = k.head;
    k.head = k.head->next;
    delete temp;
    if(isEmpty(k))
    {
        k.tail==nullptr;
    }
}

int main()
{
    kolejka k;
    ifstream source("task.tsk", std::ios::binary);
    ofstream target("myResult.jpg", std::ios::binary);
    char byte;
    source.get(byte);
    kolejka kolejki[byte];

    int numer_kolejki;
    char znak;
    int numer_kolejki_1;
    int numer_kolejki_2;

    while(!source.eof())
    {
        source.get(byte);
        switch (byte)
        {
        case '<':
            source.get(byte); numer_kolejki = byte; //Wczytanie numeru kolejki
            source.get(byte); znak = byte; //Wczytanie znaku
            push(kolejki[numer_kolejki], znak); //Dodanie do kolejki
            break;
        case '>':
            source.get(byte); numer_kolejki = byte; //Wczytanie numeru kolejki
            pop(kolejki[numer_kolejki]); //Usuniêcie z kolejki
            break;
        case '-':
            source.get(byte); numer_kolejki_1 = byte; //Wczytanie numeru kolejki 1
            source.get(byte); numer_kolejki_2 = byte; //Wczytanie numeru kolejki 2
            push(kolejki[numer_kolejki_2], kolejki[numer_kolejki_1].head -> data); //Dodanie do kolejki 2 wyjœcia z kolejki 1
            pop(kolejki[numer_kolejki_1]); //Usuniêcie z kolejki 1
            break;
        case '#':
            source.get(byte); numer_kolejki = byte; //Wczytanie numeru kolejki
            while(isEmpty(kolejki[numer_kolejki]) == false)
            {
                pop(kolejki[numer_kolejki]); //Usuniêcie z kolejki
            }
            break;
        case '|':
            source.get(byte); numer_kolejki = byte; //Wczytanie numeru kolejki
            target << kolejki[numer_kolejki].head -> data; //Zapisanie wyjœcia kolejki
            break;
        }
    }
    source.close();
    target.close();

    cout << "Done!" << endl;
    system("start myResult.jpg");

    return 0;
}
