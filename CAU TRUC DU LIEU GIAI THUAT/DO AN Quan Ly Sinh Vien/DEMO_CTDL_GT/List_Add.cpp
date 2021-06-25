#include<iostream>
using namespace std;

int n = 0;//biến toàn cục.
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

struct list
{
	NODE* head, * tail;
};
typedef struct list LIST;

NODE* khoitaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho! ";
		return NULL;
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}

void khoitaoList(LIST &l)
{
	l.head = l.tail = NULL;
}

//Thêm vào đầu
void Add_first(LIST& l, NODE* p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

//Thêm vào cuối
void Add_last(LIST& l, NODE* p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

//Xuất danh sách
void Xuat(LIST l)
{
	for (NODE* p = l.head; p != NULL; p = p->next)
	{
		cout << p->data << "    ";
	}
}

//Sắp xếp tăng dần
void Quicksort(LIST& l)
{
	int temp;
	for (NODE* p = l.head; p != NULL; p = p->next)
	{
		for (NODE* k = p->next; k != NULL; k = k->next)
		{
			if (p->data > k->data)
			{
				temp = p->data;
				p->data = k->data;
				k->data = temp;
			}
		}
	}
	/*LIST l1, l2; 
	NODE *tag = new NODE;
	NODE* p;
	Xuat(l);
	if (l.head == l.tail == NULL) return;
	khoitaoList(l1); khoitaoList(l2);
	tag = l.head;
	l.head = l.head->next;
	tag->next = NULL;
	while (l.head != NULL)
	{
		p = l.head;
		l.head = l.head->next;
		p->next = NULL;
		if (p->data <= tag->data)
		{
			Add_first(l1, p);
		}
		else Add_last(l2, p);
	}
	Quicksort(l1);
	Quicksort(l2);
	if (l1.head != NULL)
	{
		l.head = l1.head;
		l1.tail->next = tag;
	}
	else l.head = tag;
	tag->next = l2.head;
	if (l2.head != NULL)
	{
		l.tail = l2.tail;
	}
	else l.tail = tag;*/
}

//Thêm node p sau node q
void AddNode_p_last_q(LIST& l, NODE* p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE* q = khoitaoNode(x);
	if (q->data == l.head->data && l.head->next == NULL)
	{
		Add_last(l, p);
	}
	else
	{
		for (NODE* k = l.head; k != NULL; k = k->next)
		{
			if (q->data == k->data)
			{
				/*Cach 1: danh sach ton tai 1 q:
				NODE *t = k->next;
				p->next = t;
				k->next = p;*/
				//Cach 2: danh sach ton tai nhieu q:
				NODE* h = khoitaoNode(p->data);
				NODE* t = k->next;
				h->next = t;
				k->next = h;
			}
		}
	}
}

//Thêm node p trước node q
void AddNode_p_first_q(LIST& l, NODE* p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE* q = khoitaoNode(x);
	if (q->data == l.head->data && l.head->next == NULL)
	{
		Add_first(l, p);
	}
	else
	{
		NODE* t = new NODE;
		for (NODE* k = l.head; k != NULL; k = k->next)
		{
			if (q->data == k->data)
			{
				/*Cach 1: danh sach ton tai 1 q:
				p->next = k;
				t->next = p;*/
				//Cach 2: danh sach ton tai nhieu q: 
				NODE* h = khoitaoNode(p->data);
				h->next = k;
				t->next = h;
			}
			t = k ;
		}
	}
}

//Thêm một node vào vị trí bất kì
void AddNode_p_VaoViTriBatKi(LIST &l, NODE* p, int vt)
{
	NODE* q = khoitaoNode(vt);
	if (vt == 1 || l.head == NULL)
	{
		Add_first(l, p);
	}
	else if (vt == n + 1)
	{
		Add_last(l, p);
	}
	else
	{
		int dem = 0;
		NODE* t = new NODE;
		for (NODE* k = l.head; k != NULL; k = k->next)
		{
			dem++;//duyệt từ đầu danh sách để tăng.
			if (dem == vt)
			{
				NODE* h = khoitaoNode(p->data);
				h->next = k;
				t->next = h;
				break;
			}
			t = k;
		}
	}
}

//Xóa node đầu
void Delete_first(LIST l)
{
	if (l.head == NULL)
	{
		return;
	}
	else
	{
		NODE* p = l.head;
		l.head = l.head->next;
		delete p;
	}

}

//Xóa node cuối:
void Delete_last(LIST l)
{
	if (l.head == NULL)
	{
		return;
	}
	else if (l.head->next == NULL)
	{
		Delete_last(l);
	}
	else
	{
		for (NODE* k = l.head; k != NULL; k = k->next)
		{
			if (k->next == l.tail)
			{
				delete l.tail;
				k->next = NULL;
				l.tail = k;
				return;
			}
		}
	}

}

//Xoá 1 node sau node q:
void Delete_node_sau_q(LIST l, NODE* q)
{
	if (l.head == NULL)
	{
		return;
	}
	else if (l.head->next == NULL)
	{
		Delete_first(l);
		return;
	}
	else
	{
		for (NODE* k = l.head; k != NULL; k = k->next)
		{
			if (q->data = k->data)
			{
				NODE* t = k->next;
				k->next = t->next;
				delete t;
			}
		}
	}
}

//Xóa node ở vị trí bất kì:
void Delete_ViTriBatKi(LIST l, int x)
{
	NODE* t = new NODE;
	if (l.head == NULL)
	{
		return; 
	}
	if (l.head->data == x)
	{
		Delete_first(l);
		return;
	}
	if (l.tail->data == x)
	{
		Delete_last(l);
		return;
	}
	for (NODE* k = l.head; k != NULL; k = k->next)
	{
		if (k->data == x)
		{
			t->next = k->next;
			delete k;
			return;
		}
		t = k;
	}
}

//Giải phóng bộ nhớ cho danh sách liên kết đơn:
void Delete(LIST& l)
{
	NODE* k = NULL;
	while (l.head != NULL)
	{
		k = l.head;
		l.head = l.head->next;
		delete k;
	}
}

void menu()
{
	LIST l;
	int lc,x;
	khoitaoList(l);
	do
	{   
		system("cls");
		cout << "\n\t________________________________________MENU________________________________________";
		cout << "\n\t\t1.Them vao dau danh sach: ";
		cout << "\n\t\t2.Them vao cuoi danh sach: ";
		cout << "\n\t\t3.Xuat danh sach: ";
		cout << "\n\t\t4.Sap xep danh sach tang dan: ";
		cout << "\n\t\t5.Them vao sau: ";
		cout << "\n\t\t6.Them vao truoc: ";
		cout << "\n\t\t7.Them vao vi tri bat ki: ";
		cout << "\n\t\t8.Xoa node dau: ";
		cout << "\n\t\t9.Xoa node cuoi: ";
		cout << "\n\t\t10.Xoa node sau node q: ";
		cout << "\n\t\t11.Xoa node bat ki: ";
		cout << "\n\t\t0.EXIT! ";
		cout << "\n\t________________________________________END_________________________________________";
		cout << "\n\t\tNhan phim bat ki de tiep tuc nhap!";
		cout << "\n\n\tLua chon cua ban: ";
		cin >> lc;
		switch (lc)
		{
		    case 1:
			{
				n++;
				cout << "\nNhap x: ";
				cin >> x;


				NODE* p = khoitaoNode(x);
				Add_first(l, p);
				break;
			}
			case 2:
			{
				n++;
				cout << "\nNhap x: ";
				cin >> x;
				NODE* p = khoitaoNode(x);
				Add_last(l, p);
				break;
			}
			case 3:
			{
				Xuat(l);
				system("pause");
				break;
			}
			case 4:
			{
				Quicksort(l);
				Xuat(l);
				system("pause");
				break;
			}
			case 5:
			{
				int x;
				cout << "\nNhap gia tri node p can them vao sau node q: ";
				cin >> x;
				NODE* p = khoitaoNode(x);
				AddNode_p_last_q(l, p);
				break;
			}
			case 6:
			{

				int x;
				cout << "\nNhap gia tri node p can them vao truoc node q: ";
				cin >> x;
				NODE* p = khoitaoNode(x);
				AddNode_p_first_q(l, p);

				break;
			}
			case 7:
			{
				int x, vt;
				/*for (NODE* k = l.head; k != NULL; k = k->next)
				{
					n++;
				}*///vì n là biến toàn cục nên ko cần for.
				cout << "\nNhap gia tri node p can them: ";
				cin >> x;
				NODE* p = khoitaoNode(x);
				do
				{
					cout << "\nNhap vi tri can them: ";
					cin >> vt;
					if (vt < 1 || vt > n + 1)
					{
						cout << "\nVi tri can them phai nam trong doan [1;" << n + 1 << "] ";
						system("pause");
					}
				} while (vt < 1 || vt > n + 1);//use do while vì xét điều kiện trước.
				AddNode_p_VaoViTriBatKi(l, p, vt);
				n++;
				break;
			}
			case 8:
			{
				Delete_first(l);
			}
			case 9:
			{
				Delete_last(l);
			}
			case 10:
			{
				int x;
				cout << "\nNhap node can xoa sau: ";
				cin >> x;
				NODE* q = khoitaoNode(x);
				Delete_node_sau_q(l,q);
			}case 11:
			{
				
				int x;
				//NODE* p = khoitaoNode(x);
				cout << "\nNhap vao so nguyen can xoa: ";
				cin >> x;
				Delete_ViTriBatKi(l, x);
			}
			case 0: break;
			default: "ENTER";
		
		}
	} while (lc != 0);
}
int main()
{
	LIST l;
	menu();
	Delete(l);
	system("pause");
	return 0;
}