#include "stdafx.h"
#include <iostream>
#include <locale.h> 

#define N 20
using namespace std;

int increment(long *inc, long size) // заполняем массив элементов по формуле Роберта Седжвика
{
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do 
	{
		if (++s % 2) 
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} 
	
	while (3 * inc[s] < size);

	return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}

void shellSort(int *a, long size) 
{
	int s = 0;
	long inc, i, j, seq[40];

	cout << "Метод Шелла: " << endl;

	s = increment(seq, size);
	while (s >= 0) 
	{
		inc = seq[s--];

		for (i = inc; i < size; i++)
		{
			int temp = a[i];

			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
			{
				a[j + inc] = a[j];
			}

			a[j + inc] = temp;

			for (int i = 0; i < N; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}

void shakerSort(int *mas, int size) 
{
	int temp = 0, count = 0;
	int right = size - 1, left = 0;

	cout << "Метод шейкерной сортировки: " << endl;

	while (left < right) 
	{
		for (int i = left; i < right; i++) 
		{
			if (mas[i] > mas[i + 1]) 
			{
				temp = mas[i + 1];
				mas[i + 1] = mas[i];
				mas[i] = temp;
			}
			for (int k = 0; k < N; k++)
			{
				cout << mas[k] << " ";
			}
			cout << endl;
			count++;
		}
		right--;

		for (int i = right; i > left; i--) 
		{
			if (mas[i] < mas[i - 1]) 
			{
				temp = mas[i - 1];
				mas[i - 1] = mas[i];
				mas[i] = temp;
			}
			for (int k = 0; k < N; k++)
			{
				cout << mas[k] << " ";
			}
			cout << endl;
			count++;
		}
		left++;
	}
	cout << "Число cравнений: " << count << endl;
	cout << endl; 
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int massive[N] = { 5, 6, 2, 4, 8, 3, 1, 7, 9, 11, 14, 10, 12, 19, 15, 13, 17, 18, 16, 20};
	int mas[N] = { 5, 6, 2, 4, 8, 3, 1, 7, 9, 11, 14, 10, 12, 19, 15, 13, 17, 18, 16, 20 };

	cout << "Неотсортированные элементы: ";
	for (int i = 0; i < N; i++)
	{
		cout << massive[i] << " ";
	}

	cout << '\n' << '\n';

	shakerSort(massive, N);
	shellSort(mas, N);

	cout << "Метод шейкерной сортировки: " << endl;
	for (int i = 0; i < N; i++) 
	{
		cout << massive[i] << " ";
	}

	cout << endl << "Метод Шелла:" << endl;
	for (int i = 0; i < N; i++) 
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	return 0;
}
