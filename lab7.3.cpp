#include <iomanip>
#include <iostream>

using namespace std;

void Input(int** a, const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int row, const int col)
{
	cout << endl;
	for (int i = 0;i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void method(int** a,int k)
{
	int number = -1;
	for (int i = 0; i < k; i++)
	{
		number += 1;
		for (int j = k; j>=i; j--)
			a[i][j] = a[i][j] / a[i][i];
		for (int l = i + 1; l < k; l++) 
			a[l][i] = a[l][i] - a[number][i] * a[l][number];
	}
}

int find(int** a, const int k,const int inequality)
{
	int quantity = 0;
	double avarage;

	for (int i = 0; i < k; i++)
	{
		avarage = 0;
		for (int j = 0; j < k; j++)
		{
			avarage += a[i][j] / k;
		}
		if (avarage < inequality)
			quantity += 1;
	}
	return quantity;
}

int main()
{
	int row, col, inequality;

	cout << "row="; cin >> row;
	cout << "col="; cin >> col;

	int** a = new int* [row];
	for (int i = 0; i < row; i++)
	   a[i] = new int[col];

    Input(a, row, col);

	cout << "Enter the number"; cin >> inequality;
	cout << find(a, row, inequality) << endl;

	if (row == col)
	{
		method(a, col);
	}
    Print(a, row, col);

	return 0;
}