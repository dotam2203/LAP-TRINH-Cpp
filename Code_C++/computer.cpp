#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Computer {
protected:
	string maso,nhanhieu;
	float tocdoxuly;
	int dungluongRam;
public:
	virtual void Nhap();
	virtual void Xuat();
	Computer();
	~Computer();
};
void Computer::Nhap() {
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maso);
	//cin.ignore();
	cout << "Nhap nhan hieu: ";
	getline(cin, nhanhieu);
	cout << "Nhap toc do xu ly: ";
	cin >> tocdoxuly;
	cout << "Nhap dung luong Ram: ";
	cin >> dungluongRam;
}
void Computer::Xuat() {
	cout << "\nMa so: "<<maso;
	cout << "\nNhan hieu: "<<nhanhieu;
	cout << "\nToc do xu ly: "<< tocdoxuly;
	cout << "\nDung luong Ram: "<<dungluongRam;
}
Computer::Computer() {};
Computer::~Computer() {};
class Laptop :public Computer {
	float trongluong;
public:
	void Nhap();
	void Xuat();
	Laptop();
	~Laptop();
};
void Laptop::Nhap() {
Computer:: Nhap();
	cout << "\nNhap trong luong Laptop: ";
	cin >> trongluong;
}
void Laptop::Xuat() {
Computer:: Xuat();
	cout << "\nTrong luong Laptop: "<<trongluong;
}
Laptop::Laptop() {}
Laptop::~Laptop() {}
class PC : public Computer {
	string loaimanhinh;
public:
	void Nhap();
	void Xuat();
	PC();
	~PC();
};
void PC::Nhap() {
Computer:: Nhap();
	//cin.ignore();
	cout << "\nNhap loai man hinh PC: ";
	getline(cin, loaimanhinh);
}
void PC::Xuat() {
Computer:: Xuat();
	cout << "\nLoai man hinh PC: " << loaimanhinh;
}
PC::PC() {}
PC::~PC() {}
class Maytinh {
private:
	vector<Computer*>ds_computer;
public:
	void Nhap();
	void Xuat();
	Maytinh();
	~Maytinh();
};
void Maytinh::Nhap() {
	int luachon;
	while (true) {
		cout << "\n\n\t\tDanh sach Computer";
		cout << "\n1.Laptop";
		cout << "\n2.PC";
		cout << "\n0.Thoat";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		Computer *n;
		if (luachon == 1) {
			n = new Laptop;
			n->Nhap();
			ds_computer.push_back(n);
		}
		else if (luachon == 2) {
			n = new PC;
			n->Nhap();
			ds_computer.push_back(n);
		}
		else if (luachon == 0) {
			break;
		}
	}
}
void Maytinh::Xuat() {
	cout << "\n\n\t\tDanh sach Computer";
	for (int i = 0; i < ds_computer.size(); i++) {
		cout << "\nThong tin computer thu " << i + 1 << ": ";
		ds_computer[i]->Xuat();
	}
}
Maytinh::Maytinh() {}
Maytinh::~Maytinh() {}
int main() {
	Maytinh *n = new Maytinh;
	n->Nhap();
	n->Xuat();
	delete n;
	system("pause");
	return 0;
}
