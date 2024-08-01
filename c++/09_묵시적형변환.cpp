// 묵시적(암시적) 형변환  implicit conversion
// 명시적 형변환 explicit conversion


#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num): num(num) {   // 변환 생성자
        cout << "Item(int)" << endl;
    }

    Item(string name) : name(name) {
        cout << "Item(string)" << endl;
    }

    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }

    //int 로의 형변환 연산자 오버로딩
    operator int() const {
        return num;
    }
    // string으로의 형변환 연산자 오버로딩
    operator string() const {
        string str = to_string(num) + " : " + name;
        return str;
    }


    void print() {
        cout << num << " : " << name << endl;
    }

private:
    int num;
    string name;
};

void printIn(string s) {
    cout << s << endl;
}

int main() {
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;        // 묵시적 형변환

    Item i4 = (Item)4;   // 변환 생성자를 통하여 생성 , 명시적 형변환

    Item i5("stone");
    Item i7 = (string)"stone";
    Item i6(5);
    i6 = string("stone");

    Item i8(1,"glass");
    Item i9 = {2, "dirt"};
    i9 = {2, "clean"}; // 묵시적 형변환

    int itemNum1 = (int)i8;    // 명시적
    int itemNum2 = i9;   //묵시적
    cout << itemNum1 << endl;
    cout << itemNum2 << endl;

    printIn(string(i8)); // 명시적
    printIn(i8);   // 묵시적
}