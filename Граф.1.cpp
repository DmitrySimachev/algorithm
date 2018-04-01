#include "stdafx.h"
#include "iostream"
#include <locale.h> 
using namespace std;

struct vertex 
{int color = 0;};

struct edge 
{
	vertex *from, *to;
	int weigth;
	bool enter = false;
};

void repaint(int a, int b, vertex* v, int n1)
{
	for (int i = 1; i <= n1; i++) 
	{
		if (v[i].color == a) 
		v[i].color = b;
	}
}

void main() 
{
//////////////////////////////////////////////////////////////////////////////
	setlocale(LC_ALL, "RUS");

	short int n = 20, k, i, j, Fr, T;
	int G[50][50] = { };
	int N[50][50], Sequence[50][50] = { };
	int E[50], F[50][50];
	int R = 200000, D = 0;
	int f = (n / 1.24), number = 1;
	edge e[50], temp;
	vertex v[50];
	G[3][1] = 3; G[10][1] = 6;
	G[1][2] = 2; 
	G[1][3] = 1; G[14][3] = 7;
	G[1][4] = 5; G[2][4] = 3;
	G[3][5] = 2; G[5][6] = 2;
	G[2][7] = 4;
	G[3][8] = 4; G[12][8] = 5;
	G[8][9] = 3; 
	G[7][10] = 2; G[20][10] = 5;
	G[7][11] = 1; 
	G[8][12] = 3;
	G[20][13] = 1;
	G[6][14] = 8; G[9][14] = 6; G[12][14] = 1; G[15][14] = 2;
	G[4][15] = 7; G[12][15] = 3; G[13][15] = 5;
	G[14][16] = 1;
	G[18][17] = 2;
	G[13][18] = 6; G[15][18] = 4;
	G[16][19] = 3; G[17][19] = 1;
	G[11][20] = 6; G[19][20] = 8;


	cout << "Ориентированый граф" << "\n";
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (G[i][j] == 0) 
			{
				G[i][j] = 10000;
				cout << " " << ".";
			}
			else cout << " " << G[i][j];
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			Sequence[i][j] = j;
		}
	}

	cout << "\n" << "Не ориентированый граф" << "\n";
	for (int i = 1; i <= n; i++) 
	{
		for (int j = i; j <= n; j++) 
		{
			if (G[i][j] <= G[j][i]) 
				N[j][i] = N[i][j] = G[i][j];
			else N[j][i] = N[i][j] = G[j][i];
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (N[i][j] == 10000) 
				cout << " " << ".";
			else cout << " " << N[i][j];
		}
		cout << endl;
	}
//////////////////////////////////////////////////////////////////////////////
//Алгоритм Флойда-Уоршала
	for (k = 1; k <= n; k++) 
	{
		for (j = 1; j <= n; j++) 
		{
			for (i = 1; i <= n; i++) 
			{
				if ((i != k) && (j != k)) 
				{
					if (G[i][j] > G[i][k] + G[k][j]) 
					{
						G[i][j] = G[i][k] + G[k][j];
						Sequence[i][j] = Sequence[i][k];
					}
				}
			}
		}
	}
//////////////////////////////////////////////////////////////////////////////
//Алгоритм Крускала
	for (int i = 1; i <= n; i++) 
	{  
		v[i].color = i;
	}                             

	for (int i = 1; i <= n; i++) 
	{          
		for (int j = i; j <= n; j++) 
		{
			if (N[i][j] != 10000) 
			{
				e[number].from = &v[i];
				e[number].to = &v[j];
				e[number].weigth = N[i][j];
				number++;
			}
		}
	}                                      

	for (int i = 1; i < number; i++) 
	{           
		for (int j = 1; j + f < number; j++) 
		{
			if (e[j].weigth > e[j + f].weigth) 
			{
				temp = e[j + f];
				e[j + f] = e[j];
				e[j] = temp;
			}
		}
		f = f / 1.24;
	}                                            

	cout << endl;
	for (int i = 1; i < number; i++) 
	{          
		if (e[i].from->color != e[i].to->color) 
		{
			repaint(e[i].to->color, e[i].from->color, v, n);
			e[i].enter = true;
		}
	}                                            
//////////////////////////////////////////////////////////////////////////////
	cout << endl << "Кротчайший путь между двумя вершинами\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) 
		{
			if (G[i][j] > 9)
			cout << " " << G[i][j];
			else 
			cout << "  " << G[i][j];
		}
		cout << "\n";
	}
	cout << "Введите начальную вершину графа :"; cin >> Fr;
	cout << "Введите конечную вершину графа :"; cin >> T;
	cout << Fr;
	do {
		cout << "->" << Sequence[Fr][T];
		Fr = Sequence[Fr][T];
	} while (Fr != T);

	cout << endl << "Остомное дерево" << endl;
	for (int i = 1; i <= number; i++) 
	{
		if (e[i].enter) 
			cout << e[i].from - v << "-" << e[i].to - v << " ";
	}
	cout << "\n";
//////////////////////////////////////////////////////////////////////////////
}
