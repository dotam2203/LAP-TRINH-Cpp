#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

struct queue
{
	NODE *front;
	NODE *after;
};
typedef struct queue QUEUE;

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

void KhoiTaoQueue(QUEUE &q)
{
	q.front = q.after = NULL;
}

void Add_Push(QUEUE &q, NODE *p)
{
	if(p == NULL)
	{
		cout<<"\nDanh sach rong!";
	}
	else if(q.front == NULL)
	{
		q.front = q.after = p;
	}
	else 
	{
		q.after->next = p;
		q.after = p;
	}
}

int Pop(QUEUE &q, int &x)
{
	if(q.front == NULL)
	{
		return 0;
	}
	else
	{
		NODE *p = q.front;
		x = p->info;
		q.front = q.front->next;
		delete p;
	}
	return 1;
}

int Top(QUEUE &q, int &x)
{
	x = q.front->info;
	cout<<"\nPhan tu dau Queue: "<<x<<endl;
}

void Xuat_Pop(QUEUE q)
{
	int x;
	while(q.front != NULL)
	{
		Pop(q,x);
		cout<<x<<"   ";
	}
}

void menu()
{
	QUEUE q;
	KhoiTaoQueue(q);
	int x, lc;
	do
	{
		system("cls");
		cout << "\n\n\t\t============================================ MENU ============================================";
		cout << "\n\t\t1.Them 1 phan tu vao Queue - Push: ";
		cout << "\n\t\t2.Xuat danh sach trong Queue va xoa - Pop: ";
		cout << "\n\t\t2.Xuat phan tu dau Queue - Top: ";
		cout << "\n\t\t0.EXIT! ";
		cout << "\n\t\t============================================ END  ============================================";
		cout << "\n\t\tNhap lua chon cua ban: ";
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			cout << "\nNhap so nguyen can them vao Queue: ";
			cin >> x;
			NODE* p = KhoiTaoNode(x);
			Add_Push(q, p);
			break;
		}
		case 2:
		{
			Xuat_Pop(q);
			system("pause");
			break;
		}
		case 3:
		{
			Top(q,x);
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

