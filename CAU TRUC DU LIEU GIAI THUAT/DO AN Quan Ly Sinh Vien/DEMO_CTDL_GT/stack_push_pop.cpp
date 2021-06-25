#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

struct stack
{
	NODE *front;
};
typedef struct stack STACK;

NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void KhoiTaoStack(STACK &s)
{
	s.front = NULL;
}

void Add_Push(STACK &s, NODE *p)
{
	if(p == NULL)
	{
		cout<<"\nStack rong! ";
	}
	if(s.front == NULL)
	{
		s.front = p;
	}
	else
	{
		p->next = s.front;
		s.front = p;
	}
}

int Delete_Pop(STACK &s, int &x)
{
	if(s.front == NULL)
	{
		cout<<"\nStack rong";
		return 0;
	}
	else
	{
		NODE *p = s.front;
		x = p->info;
		s.front = s.front->next;
		delete p;
	}
	return 1;
}

void Xuat(STACK s)
{
	while(s.front != NULL)
		{
			int x;
			Delete_Pop(s,x);
			cout<<x<<"  ";
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
		case 0: break;
		default: "EXIT!";
		
		}
	} while (lc != 0);
}

int main()
{
	menu();
	system("pause");
   return 0;
}

