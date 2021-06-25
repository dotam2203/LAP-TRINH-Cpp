#include <iostream>
#include <cmath>
using namespace std;
class diem
{
private:
	int x, y;
public:
	void setx(int x0) { x = x0; }
	int getx() { return x; }
	void sety(int y0) { y = y0; }
	int gety() { return y; }
	diem() { x = 0; y = 0; }
	diem(int a, int b) { x = a; y = b; }
	double show(diem h)
	{
		float a, b, c, d;
		a = x;
		b = y;
		c = h.x;
		d = h.y;
		return sqrt((a - c) * (a - c) + (b - d) * (b - d));
	}
};
int main()
{
	diem m[10];
	double t[10];
	int n, i, j, a, b;
	cout << "Nhap n: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Nhap toa do diem thu " << i + 1 << ": ";
		cin >> a >> b;
		m[i].setx(a);
		m[i].sety(b);
		t[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			t[i] += m[i].show(m[j]);
		}
	}
	double min = t[0];
	j = 0;
	for (i = 1; i < n; i++)
	{
		if (min > t[i])
		{
			min = t[i];
			j = i;
		}
	}
	cout << "Toa do diem ron: " << m[j].getx() << " " << m[j].gety();
	return 0;
}
