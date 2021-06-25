#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int n = 5;
	int a[n] = { 3,2,4,1,5 };
	for (int i = 0; i < n - 1; i++) {
		int dc = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				dc = 1;
			}
		}
		if (dc == 0)
			break;
	}
	for (int i = 0; i < n; i++)
		cout << "a[i]" << ",";
	return 0;
}
