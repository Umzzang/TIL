// ������(�Ͻ���) ����ȯ  implicit conversion
// ����� ����ȯ explicit conversion


#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num): num(num) {   // ��ȯ ������
        cout << "Item(int)" << endl;
    }

    Item(string name) : name(name) {
        cout << "Item(string)" << endl;
    }

    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }

    //int ���� ����ȯ ������ �����ε�
    operator int() const {
        return num;
    }
    // string������ ����ȯ ������ �����ε�
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
    i3 = 3;        // ������ ����ȯ

    Item i4 = (Item)4;   // ��ȯ �����ڸ� ���Ͽ� ���� , ����� ����ȯ

    Item i5("stone");
    Item i7 = (string)"stone";
    Item i6(5);
    i6 = string("stone");

    Item i8(1,"glass");
    Item i9 = {2, "dirt"};
    i9 = {2, "clean"}; // ������ ����ȯ

    int itemNum1 = (int)i8;    // �����
    int itemNum2 = i9;   //������
    cout << itemNum1 << endl;
    cout << itemNum2 << endl;

    printIn(string(i8)); // �����
    printIn(i8);   // ������
}