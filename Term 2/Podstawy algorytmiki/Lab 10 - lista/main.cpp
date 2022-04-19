#include <iostream>
#include <fstream>

using namespace std;

struct element
{
    double data = 0;
    element* next = nullptr;
};

struct lista
{
    element *head = nullptr;
    element *tail = nullptr;
    int counter =0;
};

double get(lista &l,int pos){
    element *temp = l.head;
    for(int i=0;i<l.counter;i++){
        if(pos==i)
        {
            return temp->data;
        }
        temp=temp->next;
    }
    if (l.counter==pos)
    {
        return temp->data;
    }
}

double najw(lista &l){
    if(l.counter==0) return 0;
    if(l.counter==0) return l.head->data;
    element *e1 = l.head;
    element *e2=e1->next;
    double s=e1->data+e2->data;
    double pomo;
    double pomo2;
    e1=e2; e2=e2->next;
    for(int i=1;i<l.counter-1;i++)
    {
        pomo = get(l,i);
        pomo2 = get(l,i+1);
        if(pomo+pomo2>s )
        {
            s=pomo+pomo2;
        }
        e1=e1->next;


        e2=e2->next;
    }



    return s;
}

void deleteFrom(lista &l, int pos){
    if (l.counter<=0 || pos>l.counter) return;
	if (pos == 0)
    {
        if (l.head->next != nullptr)
        {
            element* temp = l.head;
            l.head = l.head->next;
            delete temp;
            l.counter--;
        }
        else
        {
            delete l.head;
            l.head = nullptr;
            l.counter=0;
        }
    }
    else
    {
		element* temp = l.head;
		for (int i = 0; i < pos - 1; i++){
			if (temp->next!=nullptr)
				temp = temp->next;
		}
		element* temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
		l.counter--;
	}

}

void addTo(lista &l, double arg, int pos){
        if (l.counter<0 || pos>l.counter) return;
        else if (pos == 0)
        {
            element* new_element = new element;
            new_element->data=arg;
            new_element->next=l.head;
            l.head = new_element;
            l.counter++;
        }
        else if(pos==0 && l.counter==0 )
        {
            element *temp = new element;
            temp->data=arg;
            temp->next=nullptr;
            l.head = temp;
            l.counter=1;
        }
        else
        {
            element *temp = new element;
			temp = l.head;
			for (int i = 0; i < pos - 1; i++)
			{
				if (temp->next!=nullptr)
					temp = temp->next;
			}
			element* new_element = new element;
			new_element->next=temp->next;
			new_element->data=arg;
			temp->next = new_element;
			l.counter++;
        }
}

int main()
{
    lista lista;
    ifstream source("V3_8.tsk", std::ios::binary);
    char arg;
    char arg2;

    while(!source.eof())
    {
        source.get(arg);
        switch(arg)
        {
            case '<':
            {
                source.get(arg2);
                source.get(arg);
                addTo(lista,arg,arg2);
            }
            break;
            case '!':
            {
                source.get(arg2);
                double war = get(lista,arg2);
                if(war<=0)
                {
                    deleteFrom(lista,arg2);
                    addTo(lista,war,lista.counter);
                }
                else
                {
                    deleteFrom(lista,arg2);
                    addTo(lista, war, 0);
                }
            }
            break;
            case '>':
            {
                source.get(arg2);
                deleteFrom(lista, arg2);
            }
            break;
        }
    }
    source.close();

    double solv = najw(lista); cout << solv;
}
