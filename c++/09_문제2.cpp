#include<iostream>

using namespace std;

int main() {
    int a = 10, b = 20, c = 30;
    int *p = &a;    // p�� a���ּҸ� ����Ŵ
    int &r = b;      // r �� b�� ����
    int **pp = &p;    // pp�� p�� �ּҸ� ����Ŵ
    int* (&rp) = p;   // int * �� ����Ű�� ���۷��� : p �� int pointer

    r = c / *p;     // 3
    rp = &c;  // rp �� �����͸� ����Ű�� ���۷����� ������ �ּҰ� �־���
    *(*pp) = 40;  // *pp = *p  **pp = &p
    *p = 50;
    *pp = &a;
    *rp = 60;   // rp �� p �� ����

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << *p << endl;
    cout << r << endl;
    cout << **pp << endl;
    cout << *rp << endl;
}