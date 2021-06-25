#include<iostream>
using namespace std;
void nhapmang(int a[100],int n){
	for(int i=0;i<=n;i++){
		cout<<"\nnhap a["<<i<<"]=";
		cin>>a[i];
	}
}
void sxmang(int a[100],int n){
	for(int i=0;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				    a[i]=a[j];
				    a[j]=temp;
			}
		}
	}
	/*for(int i=0;i<=n;i++){
		cout<<"\na["<<i<<"]=";
	}*/
}
void xuatmang(int a[100],int n){
	for(int i=0;i<=n;i++){
		cout<<"\na["<<i<<"]="<<a[i];
	}
}
int main(){
	int a[100],n;
	cout<<"nhap n=";
	cin>>n;
	nhapmang(a,n);
	sxmang(a,n);
	xuatmang(a,n);
   return 0;
}

