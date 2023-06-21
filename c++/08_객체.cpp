#include <iostream>

using namespace std;

class MyClass {
    public:
    MyClass () { //생성자
        cout << "생성자가 호출" << endl;
    }

    ~MyClass () { // 소멸자
        cout << "생성자가 소멸" << endl;
    }

};

MyClass globalObj;

void testLocalObj () {
    cout << "testLocalObj 함수 시작" << endl;
    MyClass localObj;
    cout << "testLocalObj 함수 끝" << endl;
}

int main () {
    cout << "main 함수 시작" << endl;
    testLocalObj();
    cout << "main 함수 끝" << endl;
}