#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

//Ham thay doi kich co khung cmd voi tham so truyen vao la chieu cao, chieu rong
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//Ham to mau
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

//Ham dich chuyen con tro den toa do x,y
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Ham xoa man hinh
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

/*Ham lay key tu ban phim
* GetAsynKeyState(VK_ESCAPE) => bat su kien phim ESC
*/

//Ham tu viet - to mau cho chuoi
void ToMau(int x, int y, char* a, int color)//x,y la toa do chuoi
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

int main()
{
	return 0;
}



