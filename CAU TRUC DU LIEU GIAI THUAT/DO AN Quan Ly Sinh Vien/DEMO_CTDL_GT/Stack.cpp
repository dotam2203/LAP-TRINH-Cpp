#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

struct stack
{
	NODE* head;
};
typedef struct stack STACK;

NODE* KhoiTaoNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat! ";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void KhoiTaoStack(STACK& s)
{
	s.head = NULL;
}

bool Check_IsEmpty(STACK& s)
{
	if (s.head == NULL)
	{
		return true;
	}
	return false;
}

bool Add_Push(STACK& s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}
	if (Check_IsEmpty(s) == true)
	{
		s.head = p;
	}
	else
	{
		p->next = s.head;
		s.head = p;
	}
	return true;
}

bool Out_Pop(STACK &s,int &x)
{
	if (Check_IsEmpty(s) == true)
	{
		return false;
	}
	else
	{   //xuất lần lượt phần tử đầu ra khỏi danh sách và xóa đi
		NODE* p = s.head;
		x = p->data;
		s.head = s.head->next;
		delete p;
	}
	return true;
}

//xuất lần 1 phần tử đầu ra khỏi danh sách 
bool Out_Top(STACK &s,int &x)
{
	if (Check_IsEmpty(s) == true)
	{
		return false;
	}
	x = s.head->data;
	return true;
}

void Xuat(STACK s)
{   //Xuất danh sách theo kiểu pop để xóa dữ liệu:
	while (Check_IsEmpty(s) == false)
	{
		int x;
		Out_Pop(s, x);
		cout << x <<"   ";
	}
}

void menu()
{
	STACK s;
	KhoiTaoStack(s);
	int lc,x;
	do
	{
		system("cls");
		cout << "\n\n\t\t============================================ MENU ============================================";
		cout << "\n\t\t1.Them 1 phan tu vao Stack - Push: ";
		cout << "\n\t\t2.Xuat danh sach trong Stack va xoa - Pop: ";
		cout << "\n\t\t3.Xuat phan tu dau Stack: ";
		cout << "\n\t\t0.EXIT! ";
		cout << "\n\t\t============================================ END  ============================================";
		cout << "\n\t\tNhap lua chon cua ban: ";
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			cout << "\nNhap so nguyen can them vao Stack: ";
			cin >> x;
			NODE* p = KhoiTaoNode(x);
			Add_Push(s, p);
			break;
		}
		case 2:
		{
			Xuat(s);
			system("pause");
			break;
		}
		case 3:
		{
			Out_Top(s, x);
			cout <<"\nPhan tu dau Stack la: "<<x<<endl;
			system("pause");
			break;
		}
		case 0: break;
		default: "EXIT!";
		
		}
	} while (lc != 0);
}
int main()
{
	menu();
	return 0;
}
