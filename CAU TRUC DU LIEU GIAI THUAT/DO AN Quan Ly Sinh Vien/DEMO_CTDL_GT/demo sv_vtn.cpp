#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


struct Khoa{
	int MaKhoa;
	string TenKhoa;
	
};
struct SinhVien{
	string TenSinhVien;
	int Mssv;
	Khoa Msk;
};

struct data{
	Khoa k;
	SinhVien sv;
};

// CAU TRUC NODE - khoa
struct node{
	data x;
	node *pNext;
};

// khoi tao node khoa
node *KhoiTaoNodeKhoa(data x){
	node *p = new node;
	p->x.k.MaKhoa=x.k.MaKhoa;
	p->x.k.TenKhoa=x.k.TenKhoa;
	p->pNext = NULL;
	return p;
}

// khoi tao node sinh vien
node *KhoiTaoNodeSinhVien(data x){
	node *p= new node;
	p->x.sv.TenSinhVien=x.sv.TenSinhVien;
	p->x.sv.Mssv=x.sv.Mssv;
	p->x.sv.Msk.MaKhoa=x.sv.Msk.MaKhoa;
	p->pNext=NULL;
	return p;
}

// cau truc list
struct list{
	node *pHead;
	node *pTail;	
};

//khoi tao list
void KhoiTaoList(list &l);

// them vao dau danh sach
void ThemVaoDau(list &l,node *p);

// xuat danh sach SINH VIEN
void XuatDanhSachSinhVien(list l);

// xuat danh sach KHOA
void XuatDanhSachKhoa(list l);
//
void SapXepTangDan(list &l);
// tìm kiem sinh vien
void TimKiem(list l);


//check error
bool CheckRepeatKhoa(string a, int b , list l);
bool CheckRepeatKhoaSinhVien( int b , list l);	
bool CheckRepeatMaSinhVien( int b , list l);	
//check number
int CheckNumber();


//menu
void menu();
list khoa;
list sinhvien;

int main(){
	KhoiTaoList(khoa);
	KhoiTaoList(sinhvien);
	menu();
	
	
	
	return 0;
}
void KhoiTaoList(list &l){
	l.pHead=NULL;
	l.pTail=NULL;	
}

// them vao dau danh sach
void ThemVaoDau(list &l,node *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

// xuat danh sach SINH VIEN
void XuatDanhSachSinhVien(list l){
	for(node *p = l.pHead; p!= NULL ; p=p->pNext  ){
		
		
		cout<< "\n------ Ten sv: "<< p->x.sv.TenSinhVien <<"\t   Ma sv :  "<<p->x.sv.Mssv << "\t   Ma khoa:   "<<p->x.sv.Msk.MaKhoa<<endl;
	}	
}

// sap xep select sort
void SapXepTangDan(list &l){
	for(node *p = l.pHead; p!= NULL ; p=p->pNext  ){
		data flag;
		// chuyen doi data , KO chuyen doi pNext
		for(node *k = p->pNext; k!=NULL ;k=k->pNext ){
			if(p->x.sv.Msk.MaKhoa > k->x.sv.Msk.MaKhoa){
				// swap 
				flag=p->x;
				p->x=k->x;
				k->x=flag;
			}
		}		
	}	
	
}
// xuat danh sach KHOA
void XuatDanhSachKhoa(list l){
	for(node *p = l.pHead; p!= NULL ; p=p->pNext  ){	
		cout<< "\n------ Ten khoa: "<< p->x.k.TenKhoa<<"\t   Ma khoa :  "<<p->x.k.MaKhoa<<endl;
	}	
}

//check thong bao loi
bool CheckRepeatKhoa(string a, int b , list l){
	int flag=0;
	for(node *p=l.pHead; p != NULL; p=p->pNext){
		if(a == p->x.k.TenKhoa || b== p->x.k.MaKhoa){
			flag++;
		}	
	}
	if (flag!=0){
		return true;
	}
	return false;
}
bool CheckRepeatKhoaSinhVien( int b ,list l){
	int flag=0;
	for(node *p=l.pHead; p != NULL; p=p->pNext){
		if( b== p->x.k.MaKhoa){
			flag=1;
		}
	
	}

	if(flag !=0){
		return false;
	}
	return true;
}
bool CheckRepeatMaSinhVien( int b , list l){
	int flag=0;
	for(node *p=l.pHead; p != NULL; p=p->pNext){
		if( b== p->x.sv.Mssv){
			flag=1;
		}
	
	}

	if(flag !=0){
		return true;
	}
	return false;
	
	
}

//check number
int CheckNumber(){
	int num,flag1=0;
	char term;
	
	while(scanf("%d%c", &num, &term) != 2 || term != '\n'){
		flag1++;
		
		if(flag1>1)  {
			cout<<"\nVui long nhap so ban ei!";
			cin.ignore();
		}		
	}
	return num;
}

// tim kiem sinh vien
void TimKiem(list l  ){
	int number;
	
	cout << "\n\t====================================================================================================\n";	
	cout << "\t |1. Tim kiem theo ma so sinh vien.\n";
	cout << "\t |2. Tim kiem theo ten sinh vien.\n";
	cout << "\t |3. Tim kiem sinh vien cung 1 khoa.\n";
	cout << "\t |SO KHAC :  EXIT! \n" ;
	cout << "\t=========================================================================================================\n";
	cout << "\n bam phim chon tuong ung:";
	cin >> number;
	switch(number){
		case 1:{
			int mssv,flag=0;
			cout << "\n Nhap ma so sinh vien ban muon tim: ";
			mssv=CheckNumber();
			for (node *p=l.pHead;p!=NULL;p=p->pNext ){
				if (mssv == p->x.sv.Mssv ){
					flag=1;
					cout << "\n------->Ten sinh vien: "<<p->x.sv.TenSinhVien;
					cout << "\n------->Ma so sinh vien: "<<p->x.sv.Mssv;
					cout << "\n------->Ma khoa: "<<p->x.sv.Msk.MaKhoa;
					break;
				}
			}
			if(flag ==0) cout <<"\n * KHONG TIM THAY KET QUA \n";
			break;
		}
		case 2:{
			string ten;
			int flag=0;
			cout << "\n Nhap ten sinh vien ban muon tim: ";
			cin.ignore();
			getline(cin,ten);
			for (node *p=l.pHead;p!=NULL;p=p->pNext ){
				if (ten == p->x.sv.TenSinhVien){
					flag = 1;
					cout << "\n------->Ten sinh vien: "<<p->x.sv.TenSinhVien;
					cout << "\n------->Ma so sinh vien: "<<p->x.sv.Mssv;
					cout << "\n------->Ma khoa: "<<p->x.sv.Msk.MaKhoa;
					cout<<endl;
					cout<<endl;
				}
			}
			if(flag ==0) cout <<"\n * KHONG TIM THAY KET QUA \n";
			break;
		}
		case 3:{
			int msk,flag=0;
			cout << "\n Nhap ma so khoa ban muon tim: ";
			msk=CheckNumber();
			for (node *p=l.pHead;p!=NULL;p=p->pNext ){
				if( msk == p->x.sv.Msk.MaKhoa){
					flag=1;
					cout << "\n------->Ten sinh vien: "<<p->x.sv.TenSinhVien;
					cout << "\n------->Ma so sinh vien: "<<p->x.sv.Mssv;
					cout << "\n------->Ma khoa: "<<p->x.sv.Msk.MaKhoa;
					cout<<endl;
					cout<<endl;
				}				
			}
			if(flag ==0) cout <<"\n * KHONG TIM THAY KET QUA \n";
			break;
		}
	}
	
}

//menu
void menu(){
	int number;
	
	cout << "\n\t================================================MENU====================================================\n";
	cout << "\t\t\t\t\t\tbai tap ve nha tuan 4" << endl;
	cout << "\t |1. Them thong tin vao danh sach khoa.\n";
	cout << "\t |2. Them thong tin sinh vien.\n";
	cout << "\t |3. Xuat ra danh sach sinh vien va khoa .\n";
	cout << "\t |4. Tim kiem sinh vien .\n";
	cout << "\t |SO KHAC :  EXIT! \n" ;
	cout << "\t=========================================================================================================\n";
	cout << "\n bam phim chon tuong ung:";
	cin >> number;
	switch(number){
		case 1:{
			int flag=0;
			data khoa1;
			
			cout << "\n========================Hay nhap thong tin khoa:================================\n";
			
			//---------kiem tra trung lap du lieu----------//
			do{
				flag++;
				if(flag>1){
					system("cls");
					cout << "\n******* Du lieu da ton tai\n";
				}
				cout << "---------->Ten khoa: ";
				cin.ignore();
				getline(cin,khoa1.k.TenKhoa);				
				//kiem tra  number
				cout<<"\n----------->Hay nhap ma khoa: "  ;
				khoa1.k.MaKhoa=CheckNumber();								
			}while(CheckRepeatKhoa(khoa1.k.TenKhoa, khoa1.k.MaKhoa , khoa));
			// khoi tao node
			node *khoa2= KhoiTaoNodeKhoa(khoa1);
			// them du lieu vao danh sach
			ThemVaoDau(khoa,khoa2);
			
			menu();
			break;
		}
		case 2:{
		
			data sinhvien1;
			int flag=0;
			cout << "\n=========================Hay nhap thong tin sinh vien :=========================\n";
			cout << "-----------> Ho ten sinh vien: ";
			cin.ignore();
			getline(cin,sinhvien1.sv.TenSinhVien);
			
			//--------------kiem tra du lieu co trung khong
			do{
				flag++;
				
				if (flag>1){
					system("cls");
					cout << "\n******* Du lieu da ton tai\n";
				}
				cout << "\n---------->Ma so sinh vien: ";
				// kiem tra so or chu
				sinhvien1.sv.Mssv=CheckNumber();
				
				cout << "\n---------->Ma khoa: ";
				// kiem tra so or chu
				sinhvien1.sv.Msk.MaKhoa=CheckNumber();
				
			}while( CheckRepeatKhoaSinhVien( sinhvien1.sv.Msk.MaKhoa  , khoa)==true ||CheckRepeatMaSinhVien( sinhvien1.sv.Mssv  , sinhvien)==true  );
			
			// khoi tao node 
			node *sinhvien2= KhoiTaoNodeSinhVien(sinhvien1);
			ThemVaoDau(sinhvien,sinhvien2);
			menu();
			break;
		}
		case 3:{
			SapXepTangDan(sinhvien);
			cout<<"\ndanh sach khoa : \n";
			XuatDanhSachKhoa(khoa);
			cout << endl;
			cout<<"\ndanh sach sinh vien : \n";
			XuatDanhSachSinhVien(sinhvien);
			
			
			menu();
			break;
		}
		case 4 :{
			TimKiem(sinhvien  );
			menu();
			break;
		}
	}
		
}


