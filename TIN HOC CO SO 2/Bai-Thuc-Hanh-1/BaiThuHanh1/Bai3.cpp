#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void main()
{
	int h;
	cout << "Nhap chieu cao h: ";
	cin >> h;
	while (h <= 0)
	{
		cout << "Nhap lai chieu cao h>0: ";
		cin >> h;
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= (2 * h - 1); j++) 
		{
			if ((j >= h - i + 1) && (j <= h + i - 1))
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	system("pause");
}