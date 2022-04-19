#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct element
{
	int data;
	element* next;
	element* prev;
	element(element* prev, element* next, int data): data(data), next(next), prev(prev){};
};

struct lista
{
    element* head = nullptr;
	element* tail = nullptr;
	int counter = 0;
	element* goTo(int pos)
	{
		element* temp = nullptr;
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
				l.head = new element(nullptr, nullptr, arg);
				l.tail = l.head;
				l.counter++;
			}
			else
			{
				element* temp_h = new element(nullptr, l.head, arg);
				l.head->prev = temp_h;
				l.head = temp_h;
				l.counter++;
			}
		}
		else if (pos > 0 && pos < l.counter)
		{
			if (l.counter != 0)
			{
				element* temp = l.goTo(pos - 1);
				element* temp_e = new element(temp, temp->next, arg);
				temp_e->next->prev = temp_e;
				temp->next = temp_e;
				l.counter++;
			}
		}
		else if (pos == l.counter)
		{
				element* new_tail = new element(l.tail, nullptr, arg);
				l.tail->next = new_tail;
				l.tail = new_tail;
				l.counter++;
		}
	}

void deleteFrom(lista &l, int pos)
{
    if (l.counter != 0)
    {
        if (pos == 0)
        {
            element* temp_d = l.head;
            l.head = l.head->next;
            if (l.head) l.head->prev = nullptr;
            delete temp_d;
            l.counter--;
        }
        else if (pos > 0 && pos < l.counter - 1)
        {
            element* temp = l.goTo(pos - 1);
            element* temp_d = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete temp_d;
            l.counter--;
        }
        else if (pos == l.counter - 1)
        {
            element* temp_d = l.tail;
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
        element* temp_l = l.head;
        element* temp_r = l.head->next;
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

void viewSum(lista &l)
{
    int sum = 0;
    element* temp_e = l.head;
    for (int i = 0; i < l.counter; i++)
    {
        int num = temp_e->data;
        if (num < 0) num = -num;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        temp_e = temp_e->next;
    }
    cout << sum << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		lista l;
		cout << "V3_" + to_string(i) << ": ";
		fstream source("V3_" + to_string(i) + ".tsk", ios::binary | ios::in);
		char znak = 0;
		char pos;
		char arg;
		while (!source.eof())
		{
			source.get(znak);
			switch (znak)
			{
				case '<':
				{
					pos = source.get();
					arg = source.get();
					addTo(l, arg, pos);
				}
				break;
				case '>':
				{
					pos = source.get();
					deleteFrom(l, pos);
				}
				break;
				case '!':
				{
					deleteEvery(l);
				}
				break;
			}
		}
		source.close();
		viewSum(l);
	}
	return 0;
}
