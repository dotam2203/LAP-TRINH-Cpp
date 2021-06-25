#include<iostream> 
#include<string> 
 using namespace std;
/* �?nh nghia l?p Car */ 
class Car{ 
private: 
 int  speed;   // T?c d? 
 char  mark[20];   // Nh�n hi?u 
 float price;   // Gi� xe 
public: 
 void  setSpeed(int);  // G�n t?c d? cho xe 
 int  getSpeed();   // �?c t?c d? xe 
 void  setMark(char);  // G�n nh�n cho xe 
 char[] getMark();   // �?c nh�n xe 
 void  setPrice(float);  // G�n gi� cho xe 
 float getPrice();   // �?c gi� xe 
// Kh?i t?o th�ng tin v? xe 
Car(int speedIn, char markIn[]�, float priceIn); 
 void  show();
 ~Car();   // Gi?i thi?u xe 
}; 
 
/* Khai b�o phuong th?c b�n ngo�i l?p */ 
Car::Car(int speedIn, char markIn[], float priceIn){ 
 speed = speedIn; 
 strcpy(mark, markIn); 
 price = priceIn; 
} 
Car::~Car(){
}
 
void Car::setSpeed(int speedIn){ // G�n t?c d? cho xe 
 speed = speedIn; 
} 
int Car::getSpeed(){   // �?c t?c d? xe 
 return speed; 
} 
void Car::setMark(char markIn){ // G�n nh�n cho xe 
 strcpy(mark, markIn); 
} 
char[] Car::getMark(){   // �?c nh�n xe 
 return mark; 
} 
void Car::setPrice(float priceIn){ // G�n gi� cho xe 
 price = priceIn; 
} 
float Car::getPrice(){   // �?c gi� xe 
 return price; 
} 
 
void Car::show(){    // Phuong th?c gi?i thi?u xe 
cout << �This is a � << mark << � having a speed of � 
<< speed << �km/h and its price is $� << price << endl; 
 return; 
} 
 
// H�m main, chuong tr�nh ch�nh 
void main(){ 
 clrscr(); 
 int length;    // Chi?u d�i m?ng 
 float maxPrice = 0;  // Gi� d?t nh?t 
int index = 0;   // Ch? s? c?a xe d?t nh?t 
 Car *cars;    // Khai b�o m?ng d?i tu?ng 
 
 // Nh?p s? lu?ng xe, t?c l� chi?u d�i m?ng 
 cout << �So luong xe: �; 
 cin >> length; 
 
 // C?p ph�t b? nh? d?ng cho m?ng 
 cars = new Car[length]; 
  
 // Kh?i t?o c�c d?i tu?ng trong m?ng 
 for(int i=0;i<length; i++){ 
  int speed;   // (Bi?n t?m) t?c d? 
  char mark[20];  // (Bi?n t?m) nh�n hi?u 
  float price;  // (Bi?n t?m) gi� xe 
  cout << �Xe thu � << i << �: � <<endl; 
  cout << �Toc do (km/h): �;  
cin >> speed;// cars[i].setSpeed(speed); // Nh?p t?c d? 
cout << �Nhan hieu : �; 
cin >> mark; //cars[i].setMark(mark);  // Nh?p nh�n xe 
cout << �Gia ($): �; 
cin >> price;// cars[i].setPrice(price); // Nh?p gi� xe 
 
if(maxPrice < price){ 
 maxPrice = price; 
 index = i; 
} 
 } 
 
// T�m xe d?t nh?t 
for(int i=0; i<length; i++) 
 if(i == index){ 
  cars[i].show(); // Gi?i thi?u xe d?t nh?t 
  break; 
 } 
 
// Gi?i ph�ng b? nh? c?a m?ng 
delete [] cars; 
return;
}

