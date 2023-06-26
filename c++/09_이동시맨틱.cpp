#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char * strData;
    int len;

    void alloc(int len) {
        strData = new char[len+1];
        cout << "strData allocated : " << (void*)strData << endl;
    }
    
    void release() {
        delete[] strData;
        cout << "strData released : " << (void*)strData << endl;
    }


public:
    String() {
        cout << "String() ������ ȣ�� " << this <<  endl;
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        cout << "String(const char*) ������ ȣ�� " << this <<  endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str); //���� ����
    }

    // String(String &rhs) {    //��������� :  ���� �������� ���, ���� Ŭ������ ��ü�� �����ϱ� ������ ������ �־��־�� ��.
    //     strData = rhs.strData;   // strData�� �������̱� ������  => ��������
    //     len = rhs.len;     // int�̱� ������ �ٸ� len�� => ��������
    // }

    String(const String &rhs) {
        cout << "String(const string&) ������ ȣ�� " << this << endl;
        alloc(rhs.len);
        strcpy(strData, rhs.strData); //���� ����
        len = rhs.len;
    }

    String(String &&rhs) {   //  �Ű������� rvalue
        cout << "String(String&&) : " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
    }
    
    ~String() {
        cout << "~String() �Ҹ��� ȣ�� " << this <<  endl;
        release();
        strData = NULL; // ������ �޸𸮿� ���� ������ �������ؼ� ������, �ӽù���
    }

    String &operator=(const String &rhs) {   // ������ ���� �ʰ� �Ǹ� ���ο� String  ��ü�� �����ϰ� �װ��� �����ϴ� �������� �����
        // operator ������� reference��, �ƴϸ� �� ���ο� String ���� �Ͼ
        cout << "String &operator=(const String&) : " << this << endl;
        if (this != &rhs) {   // &rhs�� ���� &rhs�� �ٸ��� . ������ �ּҸ� ��Ÿ�� => �ڱ� �ڽ��� �����ϴ� ��� �����ϱ� ���Ͽ� �б�ó��
            release();
            alloc(rhs.len);
            strcpy(strData, rhs.strData);
            len = rhs.len;
        }
        return *this;        // rhs �� const string �̱� ������ return�� ������ => *this�� ��ü�� �����ִ� �ּҰ� => ��ü ��ü�� ��ȯ
    }

    String &operator=(String &&rhs) {
        cout << "String &operator=(String&&) : " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
        return *this;
    }

    char *GetStrData() const {
        return strData;
    }
    int GetLen() const {
        return len;
    }

    void SetStrData(const char *str) {
        cout << "void SetStrData(const char*) : " << this << ", " << str <<endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
};

String getName() {
    cout << "====2====" << endl;
    String res("Doodle");
    cout << "====3====" << endl;
    return res;
}

int main() {
    String a;
    cout << "====1====" << endl;
    a = getName();
    cout << "====4====" << endl;
}