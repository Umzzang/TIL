#include <iostream>

using namespace std;

class MyClass {
    public:
    MyClass () { //������
        cout << "�����ڰ� ȣ��" << endl;
    }

    ~MyClass () { // �Ҹ���
        cout << "�����ڰ� �Ҹ�" << endl;
    }

};

MyClass globalObj;

void testLocalObj () {
    cout << "testLocalObj �Լ� ����" << endl;
    MyClass localObj;
    cout << "testLocalObj �Լ� ��" << endl;
}

int main () {
    cout << "main �Լ� ����" << endl;
    testLocalObj();
    cout << "main �Լ� ��" << endl;
}