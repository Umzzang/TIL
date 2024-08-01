#include<iostream>

using namespace std;

int main() {
    int a = 10, b = 20, c = 30;
    int *p = &a;    // p는 a의주소를 가르킴
    int &r = b;      // r 은 b와 같음
    int **pp = &p;    // pp는 p의 주소를 가르킴
    int* (&rp) = p;   // int * 를 가르키는 레퍼런스 : p 가 int pointer

    r = c / *p;     // 3
    rp = &c;  // rp 는 포인터를 가르키는 레퍼런스기 때문에 주소값 넣어줌
    *(*pp) = 40;  // *pp = *p  **pp = &p
    *p = 50;
    *pp = &a;
    *rp = 60;   // rp 는 p 와 같다

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << *p << endl;
    cout << r << endl;
    cout << **pp << endl;
    cout << *rp << endl;
}