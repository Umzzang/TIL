// #include <iostream>
// #include <cstring>

// using namespace std;

// class String {
// public:
//     String() {
//         strData = NULL;
//         len = 0;
//     }

//     String(const char *str) {
//         len = strlen(str);      // ���̸� �̸� �˾ƾ���
//         strData = new char[len + 1];     // \0�� �������� ���� ������ ���� ���̺��� +1�ؼ� �Ҵ�
//         strcpy(strData, str);
//     }
    
//     ~String() {
//         delete[] strData;
//     }

// private:
//     char *strData;
//     int len;
// };

#include <iostream>
#include <string>

using namespace std;

class String {
public:
    String() {
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        strData = str;
        cout<< strData << endl;
        cout << str << endl;

    }
    
    ~String() {
        delete[] strData;
    }

private:
    const char *strData;
    int len;
};

int main () {
    String a("aaaa");

}