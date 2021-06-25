#include<iostream>
#include<cmath>
using namespace std;

void main()
{
	float n, x, s = 0;
	cout << "Nhap so duong n: ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Nhap lai so duong n: ";
		cin >> n;
	}

	
	for (int i = 0; i < n; i++)
	{
		s = sqrt(n + s);
	}
	cout << "Tong S("<<n<<") co "<<n<<" dau can la: "<<s<<endl;

	system("pause");
}