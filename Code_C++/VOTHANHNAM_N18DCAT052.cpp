#include <iostream>
#include <cstdlib>
using namespace std;

//================== khai bao function =======================//

/* ---function phu---- */

void menu();
void menu_phu();
void nhap_mang(int a[],int n);
void xuat_mang(int a[], int n);
void swap (int &a ,int &b);
/* ---function chinh---- */

void select_sort();
void insert_sort();


//==================== main function ==========================//
int main(){
	menu();	
	return 0;
}



//====================Contents function ======================//

void menu(){
	int number;
	cout << "\n\t================================================MENU====================================================\n";
	cout << "\t\t\t\t\t\tbai tap ve nha tuan 2" << endl;
	cout << "\t |1. Select sort.\n";
	cout << "\t |2. Insert sort.\n";
	cout << "\t |SO KHAC :  EXIT! \n" ;
	cout << "\t=========================================================================================================\n";
	cout << "\n bam phim chon tuong ung:";
	cin >> number;
	switch(number){
		case 1:{
			select_sort();
			cout << "\n\n\n<==================== HAY NHAN ENTER DE SELECT CAC BAI TAP KHAC!=====================> \n\n\n\n\n\n\n";
			system("pause");
			system("cls");
			menu();
			break;
		}
		case 2:{
			insert_sort();
			cout << "\n\n\n<==================== HAY NHAN ENTER DE SELECT CAC BAI TAP KHAC!=====================> \n\n\n\n\n\n\n";
			system("pause");
			system("cls");
			menu();
			break;
		}
		default:{
			cout << "Exit!";
			break;
		}
	}
}
void menu_phu(){
	cout << "\n\t================================================MENU-PHU====================================================\n";
	cout << "\t\t\t\t\t\tbai tap ve nha tuan 2" << endl;
	cout << "\t |1. Tang dan.\n";
	cout << "\t |2. Giam dan.\n";
	cout << "\t |SO KHAC :  EXIT! \n" ;
	cout << "\t=========================================================================================================\n";
	cout << "\n bam phim chon tuong ung:";	
}



void nhap_mang(int a[],int n){
	for(int i=0; i<n; i++ ){
		cout << "\na["<<i<<"]= ";
		cin >> a[i];
	}
}
void xuat_mang(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i]<<"  ";
	}
}
void swap (int &a ,int &b){
	int temp;
	temp = a;
	a=b;
	b=temp;
}


void select_sort(){
	int a[100],temp,n,number;
	cout << "\nHay nhap so luong phan tu cua mang: ";
	cin >> n;
	nhap_mang(a,n);
	menu_phu();
	cin >> number;
	switch(number){
		case 1:{
			cout << "\n>===============Mang chua duoc sap xep:================<\n";
			xuat_mang(a,n);
			cout << "\n*Cac buoc giai:\n";
			for(int i=0;i<n-1;i++){			
				for(int j=i+1;j<n;j++){
					if(a[i]>a[j]){
						swap(a[i],a[j]);
						cout<<"\nChuyen doi vi tri "<<i+1<<" va "<<j+1<<" thanh :\n";
						xuat_mang(a,n);
					}
				}
			}
			cout << "\n<===============Mang da duoc sap xep la:===============>\n";
			xuat_mang(a,n);
			break;
		}
		case 2:{
			cout << "\n>===============Mang chua duoc sap xep:================<\n";
			xuat_mang(a,n);
			cout << "\n*Cac buoc giai:\n";
			for(int i=0;i<n-1;i++){
				
				for(int j=i+1;j<n;j++){
					if(a[i]<a[j]){
						
						swap(a[i],a[j]);
						cout<<"\nChuyen doi vi tri "<<i+1<<" va "<<j+1<<" thanh :\n";
						xuat_mang(a,n);
					}
				}
			}
			cout << "\n<===============Mang da duoc sap xep la:===============>\n";
			xuat_mang(a,n);
			
			break;
		}
		default:{
			cout << "Exit!";
			break;
		}
	}
}

void insert_sort(){
	int a[100],temp,n,number,j,k;
	cout << "\nHay nhap so luong phan tu cua mang: ";
	cin >> n;
	nhap_mang(a,n);
	menu_phu();
	cin >> number;
	switch(number){
		case 1:{
			cout << "\n>===============Mang chua duoc sap xep:================<\n";	
			xuat_mang(a,n);
			cout << "\n*Cac buoc giai:\n";
			for(int i=0;i<n-1;i++){
				int dem=0;
				j=i ;
				k=a[j+1];
				while( a[j]>k && j >= 0){	
					a[j+1]=a[j];
					j--;
					dem++;
				}
				a[j+1]=k;
				if(dem != 0){
					cout<<"\nChuyen doi quay lui ve trai "<<dem<<" lan tu vi tri thu "<<i+2<<":\n";
					xuat_mang(a,n);	
				}		
			}
			cout << "\n<===============Mang da duoc sap xep GIAM DAN la:===============>\n";
			xuat_mang(a,n);
			break;
		}
		case 2:{
			cout << "\n>===============Mang chua duoc sap xep:================<\n";
			
			xuat_mang(a,n);
			cout << "\n*Cac buoc giai:\n";
			for(int i=0;i<n-1;i++){
				int dem=0;
				j=i ;
				k=a[j+1];
				// kiem tra de quay lui //
				while( a[j]<k){
					
					a[j+1]=a[j];
					j--;
					dem++;
				}
				a[j+1]=k;
				if(dem != 0){
					cout<<"\nChuyen doi quay lui ve trai "<<dem<<" lan tu vi tri thu "<<i+2<<":\n";
					xuat_mang(a,n);	
				}		
			}
			cout << "\n<===============Mang da duoc sap xep GIAM DAN la:===============>\n";
			xuat_mang(a,n);
			break;
		}
	}
}
