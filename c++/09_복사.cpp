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
//         len = strlen(str);      // 길이를 미리 알아야함
//         strData = new char[len + 1];     // \0이 마지막에 들어가기 때문에 실제 길이보다 +1해서 할당
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