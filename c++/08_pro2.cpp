#include <iostream>

using  namespace std;

class MyClass {
public:
    MyClass() : num(cnt++) {}

    void Check(MyClass *ptr) {
        if (ptr + num == this) {
            cout << num << endl;

        }
    }
    static int cnt;

private:
    int num;
};

int MyClass::cnt = 0;

int main () {
    MyClass obj[5];

    cout << "TEST 1" << endl;

    for (int i = 0; i< 5; i++) {
        obj[i].Check(obj);
    }
    cout << "TEST 2" << endl;
    for (MyClass &i : obj) {
        i.Check(obj);
    }
    cout << MyClass::cnt << endl;
}