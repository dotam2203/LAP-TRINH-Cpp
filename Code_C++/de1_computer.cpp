#include <iostream>
#include <string>
using namespace std;
class Computer
{
	protected:
		string ms,nh;
		int td,ram;
	public:
		void setms(string t) { ms=t; }
		string getms() { return ms;}
		void setnh(string t) { nh=t; }
		string getnh() { return nh;}
		void settd(int t) { td=t; }
		int gettd() { return td;}
		void setram(int t) { ram=t; }
		int getram() { return ram;}	
		virtual void settl(float t) {};
		virtual float gettl() {return 0;};	
		virtual void setmh(string t) {};
		virtual string getmh() {return " ";};
};
class Laptop: public Computer
{
	protected:
		float tl;
	public:
		void settl(float t) { tl=t; }
		float gettl() { return tl;}		
};
class PC: public Computer
{
	protected:
		string mh;
	public:
		void setmh(string t) { mh=t; }
		string getmh() { return mh;}		
};
int main()
{
	int n,i,temp;
	float d;
	string t;
	cout<<"Hay nhap n: ";
	cin>>n;
	Computer *m[10];	
	for(i=0;i<n;i++)
	{
		cout<<"MAY THU "<<i+1<<endl;
		cout<<"Nhap ma so: "; cin>>t;
		if(t[0]=='L')
		{
			m[i]= new Laptop;
			m[i]->setms(t);
			cout<<"Nhap nhan hieu: "; cin>>t; m[i]->setnh(t);
			cout<<"Nhap toc do: "; cin>>temp; m[i]->settd(temp);
			cout<<"Nhap dung luong RAM: "; cin>>temp; m[i]->setram(temp);
			cout<<"Nhap trong luong: "; cin>>d; m[i]->settl(d);
			cout<<"-------------------------------------"<<endl;
		}
		else if (t[0]=='P')
		{
			m[i]= new PC;
			m[i]->setms(t);
			cout<<"Nhap nhan hieu: "; cin>>t; m[i]->setnh(t);
			cout<<"Nhap toc do: "; cin>>temp; m[i]->settd(temp);
			cout<<"Nhap dung luong RAM: "; cin>>temp; m[i]->setram(temp);
			cout<<"Nhap loai man hinh: "; cin>>t; m[i]->setmh(t);
			cout<<"-------------------------------------"<<endl;
		}
	}
	cout<<"CAC MAY DU TIEU CHUAN: "<<endl;
	for(i=0;i<n;i++)
	{
		if (m[i]->getms()[0]=='L' && m[i]->gettl()<2.5)
		{
			cout<<"Ma so: "<<m[i]->getms()<<endl;
			cout<<"Nhan hieu: "<<m[i]->getnh()<<endl;
			cout<<"Toc do xu ly: "<<m[i]->gettd()<<endl;
			cout<<"Dung luong RAM: "<<m[i]->getram()<<endl;
			cout<<"Trong luong: "<<m[i]->gettl()<<endl;
			cout<<"-------------------------------------"<<endl;
		}
		else if (m[i]->getms()[0]=='P' && m[i]->getram()>=2 && m[i]->getmh()=="LCD")
		{
			cout<<"Ma so: "<<m[i]->getms()<<endl;
			cout<<"Nhan hieu: "<<m[i]->getnh()<<endl;
			cout<<"Toc do xu ly: "<<m[i]->gettd()<<endl;
			cout<<"Dung luong RAM: "<<m[i]->getram()<<endl;
			cout<<"Man hinh: "<<m[i]->getmh()<<endl;
			cout<<"-------------------------------------"<<endl;	
		}
	}
	delete m;
	return 0;
}



