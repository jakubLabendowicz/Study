#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

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

void zad1()
{
    kolejka* duza = new kolejka;
    kolejka* mala = new kolejka;
    element* duzy = nullptr;
    element* maly = nullptr;
    ifstream source("zestaw11.txt");
    if (!source.is_open()) {
        cerr << "Blad otwarcia pliku" << endl;
        return;
    }
    char znak;
    while (!source.eof())
    {
        source.get(znak);
        if(znak>=65 && znak<=90) //du�a litera
        {
            push(*duza, znak);
        }
        else if(znak>=97 && znak<=122) //ma�a litera
        {
            push(*mala, znak);
        }

    }

    duzy = duza->head;
    maly = mala->head;

    int ilosc = 0;

    while(duzy != nullptr && maly != nullptr)
    {
        if(duzy->data+32 == maly->data){
            ilosc++;
        }
        duzy = duzy->next;
        maly= maly->next;
    }

    cout << "ODP: " << ilosc << endl;
    while(!isEmpty(*duza))
        pop(*duza);
    while(!isEmpty(*mala))
        pop(*mala);

    delete duza;
    delete mala;

    source.close();
    cout << endl;
}

struct element2
{
	int data;
	element2* next;
	element2* prev;
	element2(element2* prev, element2* next, int data): data(data), next(next), prev(prev){};
};

struct lista
{
    element2* head = nullptr;
	element2* tail = nullptr;
	int counter = 0;
	element2* goTo(int pos)
	{
		element2* temp = nullptr;
		if (pos < counter / 2)
		{
			temp = head;
			for (int i = 0; i < pos; i++)
			{
				if (temp->next) temp = temp->next;
				else break;
			}
		}
		else
		{
			temp = tail;
			for (int i = counter - 1; i > pos; i--)
			{
				if (temp->prev) temp = temp->prev;
				else break;
			}
		}
		return temp;
	}
};

void addTo(lista &l, int arg, int pos)
	{
		if (pos == 0)
		{
			if (l.counter == 0)
			{
				l.head = new element2(nullptr, nullptr, arg);
				l.tail = l.head;
				l.counter++;
			}
			else
			{
				element2* temp_h = new element2(nullptr, l.head, arg);
				l.head->prev = temp_h;
				l.head = temp_h;
				l.counter++;
			}
		}
		else if (pos > 0 && pos < l.counter)
		{
			if (l.counter != 0)
			{
				element2* temp = l.goTo(pos - 1);
				element2* temp_e = new element2(temp, temp->next, arg);
				temp_e->next->prev = temp_e;
				temp->next = temp_e;
				l.counter++;
			}
		}
		else if (pos == l.counter)
		{
				element2* new_tail = new element2(l.tail, nullptr, arg);
				l.tail->next = new_tail;
				l.tail = new_tail;
				l.counter++;
		}
	}

void show(lista &l)
{
    element2* temp = l.head;
    for(int i = 1; i<l.counter; i++)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void deleteFrom(lista &l, int pos)
{
    if (l.counter != 0)
    {
        if (pos == 0)
        {
            element2* temp_d = l.head;
            l.head = l.head->next;
            if (l.head) l.head->prev = nullptr;
            delete temp_d;
            l.counter--;
        }
        else if (pos > 0 && pos < l.counter - 1)
        {
            element2* temp = l.goTo(pos - 1);
            element2* temp_d = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete temp_d;
            l.counter--;
        }
        else if (pos == l.counter - 1)
        {
            element2* temp_d = l.tail;
            l.tail = l.tail->prev;
            l.tail->next = nullptr;
            delete temp_d;
            l.counter--;
        }
    }
}

void deleteEvery(lista &l)
{
    if (l.counter > 1)
    {
        element2* temp_l = l.head;
        element2* temp_r = l.head->next;
        while (temp_r)
        {
            while (temp_r->data > temp_l->data)
            {
                temp_l->next = temp_r->next;
                if (temp_r->next) temp_r->next->prev = temp_l;
                if (temp_r == l.tail) l.tail = temp_l;
                delete temp_r;
                l.counter--;
                temp_r = temp_l->next;
                if (!temp_r) break;
            }
            temp_l = temp_l->next;
            if (temp_l) temp_r = temp_l->next;
        }
    }
}

void zad2()
{
    lista l;
    int rozmiar = (rand() % 10) + 6;
    int liczba;
    int pos = 0;
    for (int i = 0; i<rozmiar; i++)
    {
        liczba = (rand() % 41) - 20;
        addTo(l, liczba, pos);
        pos++;
    }
    cout << "Przed" << endl;
    show(l);
    cout << endl;
    cout << "Po" << endl;

    element2* elem = l.head;

    int pierwszy, drugi;
    for(int i = 0; i+1<rozmiar; i++)
    {
        pierwszy = elem->data;
        elem = elem->next;
        drugi = elem->data;
        elem = elem->next;

        if(pierwszy>drugi)
        {
            deleteFrom(l, i+1);
        }
        else
        {
            deleteFrom(l, i);
        }
        rozmiar--;
    }

    show(l);
    cout << endl;
    deleteEvery(l);
}

void zad3()
{

}

int main()
{
    int loop = 1;
    while(loop == 1)
    {
        cout << "Menu:" << endl;
        cout << "1. Zadanie 1" << endl;
        cout << "2. Zadanie 2" << endl;
        cout << "3. Zadanie 3" << endl;
        cout << "4. Wyjscie" << endl;
        cout << endl;

        int wybor;
        cout << "Wybor: ";
        cin >> wybor;
        cout << endl;

        switch(wybor)
        {
            case 1:
                zad1();
            break;
            case 2:
                zad2();
            break;
            case 3:
                zad3();
            break;
            case 4:
                loop = 0;
            break;
        }
    }
}
