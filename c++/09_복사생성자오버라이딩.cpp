#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char * strData;
    int len;
public:
    String() {
        cout << "String() 생성자 호출" << endl;
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        cout << "String(const char*) 생성자 호출" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData 할당:" << (void*)strData << endl;
        strcpy(strData, str); //깊은 복사
    }

    // String(String &rhs) {    //복사생성자 :  복사 생성자의 경우, 같은 클래스의 객체를 복사하기 때문에 참조로 넣어주어야 함.
    //     strData = rhs.strData;   // strData는 포인터이기 때문에  => 얕은복사
    //     len = rhs.len;     // int이기 때문에 다른 len임 => 깊은복사
    // }

    String(const String &rhs) {
        cout << "String(const &rhs) 생성자 호출" << endl;
        strData = new char[rhs.len + 1];
        cout << "strData 할당:" << (void*)strData << endl;
        strcpy(strData, rhs.strData); //깊은 복사
        len = rhs.len;
    }
    
    ~String() {
        cout << "~String() 소멸자 호출" << endl;
        delete[] strData;
        cout << "strData 해제됨:" << (void*)strData << endl;
        strData = NULL; // 해제된 메모리에 대한 접근을 막기위해서 하지만, 임시방편
    }

    char *GetStrData() const {
        return strData;
    }
    int GetLen() const {
        return len;
    }
};


int main() {
    String s1("안녕");
    String s2(s1);   // 복사 생성자

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
}