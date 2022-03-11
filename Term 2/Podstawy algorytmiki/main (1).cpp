#include <iostream>
#include <fstream>

struct Stack
{
	char ch;
	Stack* next;
};

bool empty(Stack* top)
{
	if (top == nullptr)
		return true;
	else
		return false;
}

void push(Stack*& top, char c)
{
	Stack* n = new Stack;
	n->ch = c;
	n->next = top;
	top = n;
}

void pop(Stack*& top)
{
	if (!empty(top))
	{
		Stack* temp = top;
		top = top->next;
		delete temp;
	}
}

char top(Stack* top)
{
	if (top != nullptr)
		return top->ch;
	else
		return 0;
}

void showAll(Stack*& top)
{
	while (!empty(top))
	{
		std::cout << top->ch;
		pop(top);
	}
}



int main()
{
	Stack* stk = nullptr;
	std::fstream file;

	file.open("task.txt");
	char loaded;
	while (!file.eof())
	{
		file.get(loaded);
		if (loaded == '<')
		{
			if (!file.eof())
				push(stk, file.get());
		}
		else if (loaded == '>')
			pop(stk);
		else if (loaded == '|')
			showAll(stk);
	}
}