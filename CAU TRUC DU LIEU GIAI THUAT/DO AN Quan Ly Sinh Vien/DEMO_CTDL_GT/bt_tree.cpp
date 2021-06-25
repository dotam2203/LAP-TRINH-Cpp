#include<iostream>
using namespace std;

//khoi tao node trong Tree:
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node NODE;
typedef NODE *TREE;//khong co ham struct Tree b/c tree la node goc,  gan tree = null;

void KhoiTaoTree(TREE &t)
{
	t = NULL;
}

//them so nguyen vao cay:
void Add_Tree(TREE &t, int &x)
{
	NODE *p = new NODE;
	if( t == NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if(t->info > x)
		{
			Add_Tree(t->left, x);
		}
		else
		{
			Add_Tree(t->right, x);
		}
	}
}

//xuat cac phan tu trong cay theo kieu NLR:
void Xuat_NLR(TREE t)
{
	if(t != NULL)
	{
		cout<<t->info<<"   ";
	    Xuat_NLR(t->left);
	    Xuat_NLR(t->right);
	}
}

void Xuat_LNR(TREE t)
{
	if(t != NULL)
	{
		Xuat_LNR(t->left);
	    cout<<"  "<<t->info<<"   ";
	    Xuat_LNR(t->right);
	}
}

void Xuat_LRN(TREE t)
{
	if(t != NULL)
	{
		Xuat_LRN(t->left);
	    Xuat_LRN(t->right);
	    cout<<"  "<<t->info<<endl;
	}
	
}
int Seach(TREE &t, int &x)
{
	if(t == NULL)
	{
		return 0;
	}
	else if(t->info == x || t->left->info == x || t->right->info == x)
	{
		cout<<"\nTim kiem thanh cong! "<<t->info;
	}
	
	else
	{
		cout<<"\nTim kiem that bai!";
	}
}

void menu()
{
	TREE t;
	KhoiTaoTree(t);
	int lc;
	do
	{
		system("cls");
		cout<<"\n\n\t\t==================================== MENU ====================================";
	    cout<<"\n\t\t1.Xuat theo kieu NLR - Tree, left, right ";
	    cout<<"\n\t\t2.Xuat theo kieu LNR - left, Tree, right ";
	    cout<<"\n\t\t3.Xuat theo kieu LRN - left, right, Tree";
	    cout<<"\n\n\t\t==================================== EXIT ====================================";
	    cout<<"\n\t\tNhap lua chon cua ban: ";
	    cin>>lc;
	    
	    switch(lc)
	    {
	    	case 1:
	    	{
	    		Xuat_NLR(t);
	    		system("pause");
	    		break;
			}
			case 2:
	    	{
	    		Xuat_LNR(t);
	    		system("pause");
	    		break;
			}
			case 3:
	    	{
	    		Xuat_LRN(t);
	    		system("pause");
	    		break;
			}
	    	case 0: break;
			default: "EXIT!";	
		}
	
	}while(lc != 0);
}

void MENU()
{
	TREE t;
	KhoiTaoTree(t);
	int LC,x;
	do
	{
		system("cls");
		cout<<"\n\n=========================================== MENU ===========================================";
	    cout<<"\n\t1.Them phan tu cho cay ";
	    cout<<"\n\t2.Xuat cay ";
	    cout<<"\n\t3.Tim kiem cay ";
	    cout<<"\n\n=========================================== EXIT ===========================================";
	    cout<<"\nNhap lua chon cua ban: ";
	    cin>>LC;
	    
	    switch(LC)
	    {
	    	case 1:
	    	{
	    		cout<<"\nThem phan tu cho cay: ";
	    		cin>> x;
	    		Add_Tree(t,x);
	    		break;
			}
			case 2:
	    	{
	    		menu();
	    		system("pause");
	    		break;
			}
			case 3:
	    	{
	    		cout<<"\nNhap so nguyen can tim kiem trong cay: ";
	    		cin>>x;
	    		Seach(t,x);
	    		system("pause");
	    		break;
			}
	    	case 0: break;
			default: "EXIT!";	
		}
	
	}while(LC != 0);
}

int main()
{
	MENU();
	system("pause");
   return 0;
}

