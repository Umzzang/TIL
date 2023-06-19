#include <iostream>


using namespace std;

int main() {
    int a(10);
    
    
    //a(5);  //이렇게는 변수 선언 할 수 없음 => 함순지 변순지 알수 없음

    int b(a);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}