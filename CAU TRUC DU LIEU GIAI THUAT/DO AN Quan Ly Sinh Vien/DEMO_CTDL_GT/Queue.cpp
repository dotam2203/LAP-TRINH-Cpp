#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

struct queue
{
	NODE* head;
	NODE* tail;
};
typedef struct queue QUEUE;

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

void KhoiTaoQueue(QUEUE& q)
{
	q.head = NULL;
	q.tail = NULL;
}

bool Check_IsEmpty(QUEUE& q)
{
	if (q.head == NULL)
	{
		return true;
	}
	return false;
}

bool Add_Push(QUEUE& q, NODE* p)
{
	if (p == NULL)
	{
		return false;
	}
	if (Check_IsEmpty(q) == true)
	{
		q.head = q.tail = p;
	}
	else
	{
		q.tail->next = p;
		q.tail = p;
	}
	return true;
}

bool Out_Pop(QUEUE& q, int& x)
{
	if (Check_IsEmpty(q) == true)
	{
		return false;
	}
	else
	{   //xuất lần lượt phần tử đầu ra khỏi danh sách và xóa đi
		NODE* p = q.head;
		x = p->data;
		q.head = q.head->next;
		delete p;
	}
	return true;
}

//xuất lần 1 phần tử đầu ra khỏi danh sách 
bool Out_Top(QUEUE& q, int& x)
{
	if (Check_IsEmpty(q) == true)
	{
		return false;
	}
	x = q.head->data;
	return true;
}

void Xuat(QUEUE q)
{   //Xuất danh sách theo kiểu pop để xóa dữ liệu:
	while (Check_IsEmpty(q) == false)
	{
		int x;
		Out_Pop(q, x);
		cout << x << "   ";
	}
}

void menu()
{
	QUEUE q;
	KhoiTaoQueue(q);
	int lc, x;
	do
	{
		system("cls");
		cout << "\n\n\t\t============================================ MENU ============================================";
		cout << "\n\t\t1.Them 1 phan tu vao Queue - Push: ";
		cout << "\n\t\t2.Xuat danh sach trong Queue va xoa - Pop: ";
		cout << "\n\t\t3.Xuat phan tu dau Queue: ";
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
			Xuat(q);
			system("pause");
			break;
		}
		case 3:
		{
			Out_Top(q, x);
			cout << "\nPhan tu dau Queue la: " << x << endl;
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