#include<iostream> 
#include<string> 
 using namespace std;
/* Ð?nh nghia l?p Car */ 
class Car{ 
private: 
 int  speed;   // T?c d? 
 char  mark[20];   // Nhãn hi?u 
 float price;   // Giá xe 
public: 
 void  setSpeed(int);  // Gán t?c d? cho xe 
 int  getSpeed();   // Ð?c t?c d? xe 
 void  setMark(char);  // Gán nhãn cho xe 
 char[] getMark();   // Ð?c nhãn xe 
 void  setPrice(float);  // Gán giá cho xe 
 float getPrice();   // Ð?c giá xe 
// Kh?i t?o thông tin v? xe 
Car(int speedIn, char markIn[]”, float priceIn); 
 void  show();
 ~Car();   // Gi?i thi?u xe 
}; 
 
/* Khai báo phuong th?c bên ngoài l?p */ 
Car::Car(int speedIn, char markIn[], float priceIn){ 
 speed = speedIn; 
 strcpy(mark, markIn); 
 price = priceIn; 
} 
Car::~Car(){
}
 
void Car::setSpeed(int speedIn){ // Gán t?c d? cho xe 
 speed = speedIn; 
} 
int Car::getSpeed(){   // Ð?c t?c d? xe 
 return speed; 
} 
void Car::setMark(char markIn){ // Gán nhãn cho xe 
 strcpy(mark, markIn); 
} 
char[] Car::getMark(){   // Ð?c nhãn xe 
 return mark; 
} 
void Car::setPrice(float priceIn){ // Gán giá cho xe 
 price = priceIn; 
} 
float Car::getPrice(){   // Ð?c giá xe 
 return price; 
} 
 
void Car::show(){    // Phuong th?c gi?i thi?u xe 
cout << “This is a ” << mark << “ having a speed of ” 
<< speed << “km/h and its price is $” << price << endl; 
 return; 
} 
 
// Hàm main, chuong trình chính 
void main(){ 
 clrscr(); 
 int length;    // Chi?u dài m?ng 
 float maxPrice = 0;  // Giá d?t nh?t 
int index = 0;   // Ch? s? c?a xe d?t nh?t 
 Car *cars;    // Khai báo m?ng d?i tu?ng 
 
 // Nh?p s? lu?ng xe, t?c là chi?u dài m?ng 
 cout << “So luong xe: ”; 
 cin >> length; 
 
 // C?p phát b? nh? d?ng cho m?ng 
 cars = new Car[length]; 
  
 // Kh?i t?o các d?i tu?ng trong m?ng 
 for(int i=0;i<length; i++){ 
  int speed;   // (Bi?n t?m) t?c d? 
  char mark[20];  // (Bi?n t?m) nhãn hi?u 
  float price;  // (Bi?n t?m) giá xe 
  cout << “Xe thu ” << i << “: ” <<endl; 
  cout << “Toc do (km/h): ”;  
cin >> speed;// cars[i].setSpeed(speed); // Nh?p t?c d? 
cout << “Nhan hieu : ”; 
cin >> mark; //cars[i].setMark(mark);  // Nh?p nhãn xe 
cout << “Gia ($): ”; 
cin >> price;// cars[i].setPrice(price); // Nh?p giá xe 
 
if(maxPrice < price){ 
 maxPrice = price; 
 index = i; 
} 
 } 
 
// Tìm xe d?t nh?t 
for(int i=0; i<length; i++) 
 if(i == index){ 
  cars[i].show(); // Gi?i thi?u xe d?t nh?t 
  break; 
 } 
 
// Gi?i phóng b? nh? c?a m?ng 
delete [] cars; 
return;
}

