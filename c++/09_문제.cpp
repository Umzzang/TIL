#include <iostream>

using namespace std;

int main() {
    char str[] = "Hello";
    char *p_str = str;
    

    cout<< str<< endl;
    cout<< *str<< endl;   //*str = str[0]

    cout << p_str << endl;
    cout << *p_str << endl;

    cout << &str << endl;    
    
}