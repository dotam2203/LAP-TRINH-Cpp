/* INPUT OUTPUT mới kiểm tra nhập số và nhập chữ version 1. Có input output mật khẩu */

#include <string>
#include<iostream>
#include <cstring>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<io.h>
#define MAX 50
using namespace std;

string ErrorInput(char *in,char type)
{
		string Error ="";
		switch (type)
	{

		case 'N':
			{
				for(int i =0;i<strlen(in);i++)
				{
					if(!((int)in[i]>=65&&(int)in[i]<=90)&&!((int)in[i]>=97&&(int)in[i]<=122)&&in[i]!=' ')
					{
							return Error ="Ten ban nhap khong hop le";
					}
				}
		
				
			}break;
		
		case 'I':
			{
				for(int i =0;i<strlen(in);i++)
				{
					if((int)in[i]<48||(int)in[i]>57)
				return Error ="So ban nhap khong hop le";
						
				}
			
				
			}break;
	
		
	}
	return Error;
}

char *input(char type)
{
	fflush(stdin);
	char *in;
	string Error = "Sai";
	in = new char[255];
	int i=0;
	while(Error!="")
	{
	
		switch (type)
		{
	
		case 'N':
			{
				cin.getline(in,255);
				Error =  ErrorInput(in,type);
			}break;
	
		case 'I':
			{
					cin.getline(in,255);
				Error =  ErrorInput(in,type);
			}
			break;
		//getch();
		case 'P':
			{
		
				while(!kbhit())
				{
					char mn=getch();
					if (mn!='\r')
					{
						cout << "*";
						in[i]=mn;
						i++;
					}
					else
					break;
					
				}
				Error =  ErrorInput(in,type);	
				
			}break;
		}
		cout << Error;
	}
		return in;
}

int main()
{
	//Name *SV;
//	int n;
	cout << "Nhap ten:";
	char *Name = input('N');
		cout << "Nhap sdt:";
	char *Phone = input('I');
		cout << "Nhap Matkhau:";
	char *Pass = input('P');
	cout << Pass;
	getch();
	return 0;
}
