#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


using namespace std;

void main()
{

	int n, s = 0;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Nhap lai so nguyen duong n: ";
		cin >> n;
	}
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && i % 2 == 0)
		{
			s += i;

		}
	}
	cout << "Tong uoc chan cua " << n << " la: " << s<<endl;
	system("pause");
}