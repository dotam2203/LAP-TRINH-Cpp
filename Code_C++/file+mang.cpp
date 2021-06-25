#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	//Ð?C FILE
	//istream <tên bi?n file>;
	ifstream FileIn;//d?c d? li?u t? file.
	//open(<tên du?ng d?n d?n file c?n m?-d? d?c-dây là m?t cái chu?i>,<ch? d? làm vi?c v?i file>); 
	FileIn.open("input.txt", ios::in);
	if (FileIn.fail() == true) {
		cout << "\nFile ko ton tai ";
		return 0;
	}
	//cout << "\nHello world";
	int x, y;
	FileIn >> x;//cin>>x;
	FileIn >> y;//cin>>y;
	cout << "tong = " << x + y;
	//ÐÓNG FILE SAU KHI X? LÝ:
	FileIn.close();
	//GHI FILE:
	ofstream FileOut;
	FileOut.open("output.txt", ios::out);
	FileOut << x + y;//ghi t?ng vào output.txt;
	//FileOut << 20;
	//FileOut << 21;
	//ÐÓNG FILE SAU KHI X? LÝ:
	FileOut.close();
	return 0;
}
