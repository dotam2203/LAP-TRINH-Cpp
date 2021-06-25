#include<iostream>
#include<cmath>
using namespace std;

void main()
{
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Nhap so lai nguyen duong n: ";
        cin >> n;
    }

    if (n == 2 || n == 3)
    {
        cout << n << " la so nguyen to!"<<endl;
    }
    else
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i != 0)
            {
                break;
            }
        }
        cout << n << " khong phai so nguyen to!"<<endl;
    }
    
    system("pause");
}