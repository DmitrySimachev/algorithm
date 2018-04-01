#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

using namespace std;

#define N 20

typedef struct elem 
{
	float value;
	struct elem *next; 
}	elem;

typedef struct list 
{ // дескриптор
	elem *first;
	int cnt; // кол-во элементов
}	list;

void create(list *);
void clear(list *);
void output(list);
void find(list);
void add(list *, int);
void remove(list *, int);

int main(void)
{
	setlocale(LC_ALL, "RUS");
	list l; //дескриптор списка
	int option; //выбранная опция
	int pos;

	//loop
	l.first = NULL;
	while (1)
	{
		if (l.first)
		{
			cout << "Доступные опции:\n";
			cout << "1) добавление элемента;\n";
			cout << "2) удаление элемента;\n";
			cout << "3) поиск максимального элемента;\n";
			cout << "4) вывод списка на экран;\n";
			cout << "5) очистка списка;\n";
			cout << "6) выход.\n";

			cin >> option;

			switch (option)
			{
			case 1:
				cout << "Введите индекс:\n";
				cin >> pos;
				add(&l, pos);
				break;
			case 2:
				cout << "Введите индекс:\n";
				cin >> pos;
				remove(&l, pos);
				break;
			case 3:
				find(l);
				break;
			case 4:
				output(l);
				break;
			case 5:
				clear(&l);
				break;
			case 6:
				clear(&l);
				return 0;
			default:
				cout << "Пожалуйста, введите номер доступной опции!";
			}
		}
		else
		{
			cout << "Доступные опции:\n";
			cout << "1) создание списка;\n";
			cout << "2) выход.\n";

			cin >> option;

			switch (option)
			{
			case 1:
				create(&l);
				break;
			case 2:
				return 0;
			default:
				cout << "Пожалуйста, введите номер доступной опции!";
			}
		}
	}
}

void create(list *ptr) //инициализацмя списка из 20 переменных
{
	ptr->first = (elem *)malloc(sizeof(elem));
	ptr->cnt = 1;
	cout << "Введите элемент\n";
	cin >> ptr->first->value;
	ptr->first->next = NULL;
	while (ptr->cnt < N)
	{
		add(ptr, ptr->cnt+1);
	}
}

void clear(list *ptr) //очищение списка
{
	while (ptr->first->next)
	{
		remove(ptr, 2);
	}
	free(ptr->first);
	ptr->first = NULL;
	ptr->cnt = 0;
}

void output(list l) //вывод списка
{
	float i = 1;
	elem *temp = l.first;
	while (temp)
	{
		cout << i++ << ") " << temp->value << ";\n";
		temp = temp->next;
	}
}

void find(list l) //поиск max элемента 
{
	float a = 0;
	int max = 0; 
	float i = l.first->value;
	elem * temp;
	
	temp = l.first;

	while (temp) 
	{
		if (temp->value >= a)
		{
			a = temp->value;
			max = i;
		}
		i++;
		temp = temp->next;
	}
	cout << "Найден максимальный элемент в позиции: " << max << " число: " << a << '\n';
}

void add(list *ptr, int p) //добавение элемента 
{
	float a;

	cout << "Введите элемент:\n";
	cin >> a;

	elem * tmp1, * tmp2;
	tmp1 = ptr->first;

	for (int i = 1; i < (p - 1); i++)
	{
		tmp1 = tmp1->next;
	}
	tmp2 = (elem *)malloc(sizeof(elem));
	tmp2->next = tmp1->next;
	tmp1->next = tmp2;
	tmp2->value = a;
	ptr->cnt++;
}

void remove(list *ptr, int p) //удаление элемента 
{
	elem * tmp1, * tmp2;

	tmp1 = ptr->first;
	for (int i = 1; i < (p - 1); i++)
	{
		tmp1 = tmp1->next;
	}
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	free(tmp2);
	tmp2 = NULL;
	ptr->cnt--;
}
