#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char * strData;
    int len;
public:
    String() {
        cout << "String() ������ ȣ��" << endl;
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        cout << "String(const char*) ������ ȣ��" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData �Ҵ�:" << (void*)strData << endl;
        strcpy(strData, str); //���� ����
    }

    // String(String &rhs) {    //��������� :  ���� �������� ���, ���� Ŭ������ ��ü�� �����ϱ� ������ ������ �־��־�� ��.
    //     strData = rhs.strData;   // strData�� �������̱� ������  => ��������
    //     len = rhs.len;     // int�̱� ������ �ٸ� len�� => ��������
    // }

    String(const String &rhs) {
        cout << "String(const &rhs) ������ ȣ��" << endl;
        strData = new char[rhs.len + 1];
        cout << "strData �Ҵ�:" << (void*)strData << endl;
        strcpy(strData, rhs.strData); //���� ����
        len = rhs.len;
    }
    
    ~String() {
        cout << "~String() �Ҹ��� ȣ��" << endl;
        delete[] strData;
        cout << "strData ������:" << (void*)strData << endl;
        strData = NULL; // ������ �޸𸮿� ���� ������ �������ؼ� ������, �ӽù���
    }

    char *GetStrData() const {
        return strData;
    }
    int GetLen() const {
        return len;
    }
};


int main() {
    String s1("�ȳ�");
    String s2(s1);   // ���� ������

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
}