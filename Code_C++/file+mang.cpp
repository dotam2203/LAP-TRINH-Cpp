#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	//�?C FILE
	//istream <t�n bi?n file>;
	ifstream FileIn;//d?c d? li?u t? file.
	//open(<t�n du?ng d?n d?n file c?n m?-d? d?c-d�y l� m?t c�i chu?i>,<ch? d? l�m vi?c v?i file>); 
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
	//��NG FILE SAU KHI X? L�:
	FileIn.close();
	//GHI FILE:
	ofstream FileOut;
	FileOut.open("output.txt", ios::out);
	FileOut << x + y;//ghi t?ng v�o output.txt;
	//FileOut << 20;
	//FileOut << 21;
	//��NG FILE SAU KHI X? L�:
	FileOut.close();
	return 0;
}
