#include<iostream>
using namespace std;

//Khởi tạo node của cây:
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node NODE;
typedef NODE* TREE;
//Gán con trỏ TREE  trỏ tới địa chỉ của t-node gốc
void KhoitaoTree(TREE& t)// có thể thay TREE &t = NODE *&t;
{
	t = NULL;
}

//Thêm node vào cây:
void Add_Tree(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;//gán node mới là p- tức là ta đang thêm node x vào:
		p->data = x;
		p->left = NULL;
		p->right = NULL;
		t = p;//x ta nhập vào chính là node gốc:
	}
	else// sử dụng Đệ Qui-Hàm trong hàm- đệ qui duyệt hàm từ trên xuống sau đó lại duyệt ngược lại từ dưới lên
	{
		if (t->data > x)
		{
			Add_Tree(t->left, x);
		}
		else
		{
			Add_Tree(t->right, x);
		}
	}
}

//Xuất cây nhị phân theo NLR - gốc, trái, phải:
void Xuat_NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "  ";
		Xuat_NLR(t->left);
		Xuat_NLR(t->right);
	}
}

//Xuất cây nhị phân theo LNR - trái, gốc, phải;
void Xuat_LNR(TREE t)
{
	if (t != NULL)
	{
		Xuat_LNR(t->left);
		cout << "  " << t->data << "  ";
		Xuat_LNR(t->right);
	}
}

//Xuat cay nhi phan theo LRN-trai,phai,goc:
void Xuat_LRN(TREE t)
{
	if (t != NULL)
	{
		Xuat_LRN(t->left);
		Xuat_LRN(t->right);
		cout << "  " << t->data<<"  ";
	}
}

//Tạo Menu để chọn chức năng - use switch_case trong vòng lặp do_while:
void Menu()
{
	TREE t;
	KhoitaoTree(t);
	int lc;
	do
	{
		system("cls");
		cout << "\n\n\t\t==================================== MENU ====================================";
		cout << "\n\t\t1.Them vao cay: ";
		cout << "\n\t\t2.Xuat cay theo NLR-goc,trai,phai: ";
		cout << "\n\t\t3.Xuat cay theo LNR-trai,goc,phai: ";
		cout << "\n\t\t4.Xuat cay theo LRN-trai,phai,goc: ";
		cout << "\n\t\t0. EXIT! ";
		cout << "\n\n\t\t==================================== END =====================================";
		cout << "\n\n\t\tNhap lua chon cua ban : ";
		cin >> lc;
		switch(lc)
		{
		    case 1:
			{
				int x;
				cout << "\nNhap node cho cay: ";
				cin >> x;
				Add_Tree(t, x);
				break;
			}
			case 2:
			{
				Xuat_NLR(t);
				system("pause");
				break;
			}
			case 3:
			{
				Xuat_LNR(t);
				system("pause");
				break;
			}
			case 4:
			{
				Xuat_LRN(t);
				system("pause");
				break;
			}
			case 0: break;
			default: "ENTER" ;
		}

	} while (lc != 0);
}

int main()
{
	Menu();
	return 0;
}