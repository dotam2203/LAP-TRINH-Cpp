#include<iostream>
using namespace std;
void nhap_mang(int a[][100],int m,int n);
void xuat_mang(int a[][100],int m,int n);
int main(){
	int a[100][100],m,n;
	cout<<"nhap so hang cua mang: ";
	cin>>m;
	cout<<"nhap so cot cua mang: ";
	cin>>n;
	/*for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			*(*(a+i)+j)=i+j;
		}
	}*/
	nhap_mang(a,m,n);
	xuat_mang(a,m,n);
   return 0;
}
void nhap_mang(int a[][100],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"nhap a["<<i<<"]["<<j<<"]= ";
			cin>>a[i][j];
		}
	}
}
void xuat_mang(int a[][100],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"\t"<<a[i][j];
		}
		cout<<"\n\n";
	}
}

