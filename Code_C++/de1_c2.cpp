#include<iostream>
#include<string.h>
using namespace std;
class Computer
{
protected:
	string Maso;
	string Nhanhieu;
	float Tocdoxuly;
	int DungluongRAM;
public:
	void setmaso(string MS)
	{
		Maso = MS;
	}
	string getmaso();
	void setnhanhieu(string);
	string getnhanhieu();
	void settocdo(float);
	float gettocdo();
	void setdungluong(int);
	int getdungluong();
	void show()
	{
		cout << "\nMa so: " << Maso;
		cout << "\nNhan hieu: " << Nhanhieu;
		cout << "\nToc do xu ly: " << Tocdoxuly;
		cout << "\nDung luong RAM: " << DungluongRAM;
	}
	virtual void settrongluong(float TL)
	{
	}
	virtual float gettrongluong()
	{
		return 0;
	}
	virtual void setmanhinh(string MH)
	{
	}
	virtual string getmanhinh()
	{
		return "";
	}
};

string Computer::getmaso()
{
	return Maso;
}
void Computer::setnhanhieu(string NH)
{
	Nhanhieu = NH;
}
string Computer::getnhanhieu()
{
	return Nhanhieu;
}
void Computer::settocdo(float TD)
{
	Tocdoxuly = TD;
}
float Computer::gettocdo()
{
	return Tocdoxuly;
}
void Computer::setdungluong(int DL)
{
	DungluongRAM = DL;
}
int Computer::getdungluong()
{
	return DungluongRAM;
}


class Laptop :public Computer
{
	float Trongluong;
public:
	void settrongluong(float);
	float gettrongluong();
};
void Laptop::settrongluong(float TL)
{
	Trongluong = TL;
}
float Laptop::gettrongluong()
{
	return Trongluong;
}



class PC :public Computer
{
	string Manhinh;
public:
	void setmanhinh(string);
	string getmanhinh();
};
void PC::setmanhinh(string MH)
{
	Manhinh = MH;
}
string PC::getmanhinh()
{
	return Manhinh;
}



int main()
{
	int n;
	cout << "Nhap so computer: ";
	cin >> n;
	Computer* a[100];
	string MS;
	string NH, MH;
	float TD, TL;
	int DL;
	for (int i = 1; i <= n; i++)
	{
		do
		{
			cout << "\nNhap thong tin Computer thu " << i;
			cout << "\nMa so: ";
			cin >> MS;
		} while (MS[0] != 'L' && MS[0] != 'P');
		if (MS[0] == 'L')
		{
			a[i] = new Laptop;
			a[i]->setmaso(MS);
			cout << "Nhan hieu: ";
			cin >> NH;
			a[i]->setnhanhieu(NH);
			cout << "Toc do xu ly: ";
			cin >> TD;
			a[i]->settocdo(TD);
			cout << "Dung luong RAM: ";
			cin >> DL;
			a[i]->setdungluong(DL);
			cout << "Trong luong: ";
			cin >> TL;
			a[i]->settrongluong(TL);

		}
		else
		{
			a[i] = new PC;
			a[i]->setmaso(MS);
			cout << "Nhan hieu: ";
			cin >> NH;
			a[i]->setnhanhieu(NH);
			cout << "Toc do xu ly: ";
			cin >> TD;
			a[i]->settocdo(TD);
			cout << "Dung luong RAM: ";
			cin >> DL;
			a[i]->setdungluong(DL);
			cout << "Loai man hinh: ";
			fflush(stdin);
			cin >> MH;
			a[i]->setmanhinh(MH);
		}
	}
	cout << "\nCac Computer duoc chon: ";
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		MS = a[i]->getmaso();
		if (MS[0] == 'L')
		{
			if (a[i]->gettrongluong() < 2.5)
			{
				cout << "\nComputer thu " << i << ": ";
				a[i]->show();
				cout << "\nTrong luong: " << a[i]->gettrongluong();
			}
		}
		else
		{
			if (a[i]->getdungluong() >= 2 && a[i]->getmanhinh() == "LCD")
			{
				cout << "\nComputer thu " << i << ": ";
				a[i]->show();
				cout << "\nMan hinh: " << a[i]->getmanhinh();
			}
		}

	}
	cout << endl;
	system("pause");
	return 0;
}

