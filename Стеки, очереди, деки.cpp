#include <iostream> //console inp/outp
#include <stdlib.h> //random
#include <time.h> //random [2]
#include <conio.h> // getch
#define N 17
using namespace std;

typedef struct obj
{
	int value;
	struct obj* next;
	struct obj* prev;
};

struct queue
{
	obj* first;
	obj* last;
};


//functions prototypes
void Output(queue*);

void Menu(queue*);

void MenuChoice(queue*);

void Add(queue*);

void Delete(queue*);

void Clean(queue*);

void Create(queue*);



//main function

void main()
{
	//system setup
	srand(time(NULL));
	//stack descriptor
	queue list;
	list.first = list.last = NULL;
	queue* ptr = &list;
	//Menu launch
	Menu(ptr);
	//exit pause
	_getch();
	_getch();
}

//menu
void Menu(queue* ptr)
{
	if (ptr->first)
		cout << "Press\n 1) for stack output\n" << " 2) to Add an element\n" << " 3) to Delete an element\n" << " 4) to Clean the list" << endl;
	else //if there's no stack yet
		cout << "Press 1 to create New stack and fill it with random values" << endl;
	MenuChoice(ptr);
}

//menu choice (reads pressed keys)
void MenuChoice(queue* ptr)
{
	int i = _getch();
	if (ptr->first)
	{
		switch (i)
		{
		default: MenuChoice(ptr); break;
		case '1': Output(ptr);  Menu(ptr); break;
		case '2': Add(ptr); Output(ptr); Menu(ptr); break;
		case '3': Delete(ptr); Output(ptr); Menu(ptr); break;
		case '4': Clean(ptr); Menu(ptr); break;
		}
	}
	else
	{
		switch (i)
		{
		default: MenuChoice(ptr); break;
		case '1': Create(ptr); Output(ptr); Menu(ptr); break;
		}
	}
}


//stack creation
void Create(queue* ptr)
{

	ptr->first = ptr->last = new obj;
	ptr->first->value = rand() % 100;
	obj* prev;
	for (int i = 0; i < N - 1; i++)
	{
		prev = ptr->last;
		ptr->last = new obj;
		ptr->last->prev = prev;
		prev->next = ptr->last;
		ptr->last->value = rand() % 100;
		ptr->last->next = NULL;
	}
	cout << "Stack created successfully!\n";
	return;
}

void Output(queue* ptr)
{
	if (!ptr->first)
	{
		cout << "Stack is empty!\n";
		return;
	}
	obj* active = ptr->first;
	int i = 1;
	do
	{
		cout << i << ".\t" << active->value << endl;
		i++;
		active = active->next;
	} while (active);
	return;
}

void Add(queue* ptr)
{
	obj* prev;

	prev = ptr->last;
	ptr->last = new obj;
	ptr->last->prev = prev;
	prev->next = ptr->last;
	ptr->last->next = NULL;
	cout << "Enter the value:\t";
	cin >> ptr->last->value;
	cout << endl;
	return;
}

void Clean(queue* ptr)
{
	obj* temp = ptr->first;
	while (temp)
	{
		ptr->first = temp->next;
		delete temp;
		temp = ptr->first;
	}
	ptr->first = ptr->last = NULL;
	cout << "Stack's clear!\n";
	return;
}

void Delete(queue* ptr)
{
	//priority
	if (!ptr->first)
	{
		cout << "Stack is empty!\n";
		return;
	}
	obj* active = ptr->first;
	obj* max = ptr->first;

	do
	{
		if (active->value > max->value)
			max = active;
		active = active->next;
	} while (active);
	//
	obj* next = max->next;
	obj* prev = max->prev;
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	delete max;
	return;
}
