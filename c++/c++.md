# C++



## MinGW

> **MinGW**(과거 이름: **mingw32**)는 [마이크로소프트 윈도우](https://ko.wikipedia.org/wiki/마이크로소프트_윈도우)로 포팅한 GNU 소프트웨어 도구 모음이다.



## namespace

> 함수 이름, 구조체 이름 등이 같아지게 되면 이름 충돌이 발생하는데, 이를 방지하기 위해 만들어진 것이 namespace
>
> **namespace는 함수나 구조체 혹은 변수 이름 등의 소속**을 정해주는 것

```
namespace [네임스페이스 이름]
{
  함수, 구조체, 변수, 클래스 등등등
}
```



```c++
#include <iostream>
using namespace std;
 
void printAll() {
    cout << "printAll 함수" << endl;
}
 
void printAll() {
    cout << "printAll 함수" << endl;
}
 
int main(void)
{
    //printAll 함수 호출
    printAll();
 
    return 0;
}
```

=> 충돌 발생



```c++
#include <iostream>
using namespace std;
 
namespace A {
    void printAll() {
        cout << "A의 printAll 함수" << endl;
    }
}
 
namespace B {
    void printAll() {
        cout << "B의 printAll 함수" << endl;
    }
}
 
 
int main(void)
{
    //printAll 함수 호출
    A::printAll();
    B::printAll();
 
    return 0;
}

```

=> 충돌 해결



### namespace 접근

* **네임스페이스이름::요소**

```c++
#include <iostream>
using namespace std;
 
namespace A {
    void printAll() {
        cout << "A의 printAll 함수" << endl;
    }
}
 
namespace B {
    void printAll() {
        cout << "B의 printAll 함수" << endl;
    }
}
 
 
int main(void)
{
    //printAll 함수 호출 :: 이용하여 접근
    A::printAll();
    B::printAll();
 
    return 0;
}
```



* **using 네임스페이스이름::요소;**

```c++
#include <iostream>
using namespace std;
 
namespace ABC {
    int MAX_CNT = 10;
    
    void init() {
        cout << "ABC의 init() 함수" << endl;
    }
 
    void print() {
        cout << "ABC의 print() 함수" << endl;
    }
}
 
using ABC::init;
 
int main(void)
{
    init();         // 가능
 
    ABC::init(); // 가능
    
 
    ABC::print();
    cout << ABC::MAX_CNT << endl;
    //print();                    호출 불가
    //cout << MAX_CNT << endl;  호출 불가    
 
    return 0;
}

```

```
ABC의 init() 함수
ABC의 init() 함수
ABC의 print() 함수
10
```



* **using namespace 네임스페이스이름;**

```c++
#include <iostream>
using namespace std;
 
namespace ABC {
    int MAX_CNT = 10;
    
    void init() {
        cout << "ABC의 init() 함수" << endl;
    }
 
    void print() {
        cout << "ABC의 print() 함수" << endl;
    }
}
 
using namespace ABC; //ABC 이름공간 제약없이 접근 가능
 
int main(void)
{
    init();
    print();                    
    cout << MAX_CNT << endl;
 
    return 0;
}

```

```
ABC의 init() 함수
ABC의 print() 함수
10
```



* 함수 내부 using 선언

```c++
#include <iostream>
using namespace std;
 
namespace QWERTY {
    
    void go() {
        cout << "QWERTY 이름공간의 go() 함수" << endl;
    }
 
    void back() {
        cout << "QWERTY 이름공간의 back() 함수" << endl;
    }
}
 
int main(void)
{
    QWERTY::go();
    //go(); // 불가능
 
    using QWERTY::go; // 여기 아래부터는 main 함수 내부에서는 go() 그냥 사용 가능
    go(); //가능!
 
    return 0;
}
 
// 다른 함수
void example() {
    //go(); 불가능
    QWERTY::go(); //가능
}

```



* 함수 내부 using 지시어

```c++
#include <iostream>
using namespace std;
 
namespace QWERTY {
    
    void go() {
        cout << "QWERTY 이름공간의 go() 함수" << endl;
    }
 
    void back() {
        cout << "QWERTY 이름공간의 back() 함수" << endl;
    }
}
 
int main(void)
{
    QWERTY::go();
    QWERTY::back();
 
    //go();   불가능
    //back(); 불가능
 
    using namespace QWERTY; 
    // 여기 아래부터는 QWERTY 이름공간 내부요소 그냥 접근가능
    
    go(); //가능!
    back(); //가능!
    
    return 0;
}
 
// 다른 함수
void example() {
    //go(); 불가능
    //back(); 불가능
    QWERTY::go(); //가능
    QWERTY::back(); //가능
}
```



* 전역 네임스페이스

> **::요소**

```c++
#include <iostream>
using namespace std;
 
namespace Car {
    void drive() {
        cout << "Car 이름공간 drive() 함수 호출 " << endl;
    }
}
 
void drive() { cout << "글로벌 이름공간 drive() 함수 호출" << endl; }
 
int main(void)
{
    drive();        // 글로벌 1
    ::drive();        // 글로벌 2
    Car::drive();   // Car 이름공간
 
    return 0;
}
```

```
글로벌 이름공간 drive() 함수 호출
글로벌 이름공간 drive() 함수 호출
Car 이름공간 drive() 함수 호출
```



### std

> c++의 모든 표준 요소를 std 이름 공간에 만들어져 있음

* using namespace std; 없이 사용할 때

```c++
#include <iostream>
int main(void)
{
    std::cout << "출력" << std::endl;
    return 0;
}
```





## 변수 

### 초기화

* 복사 초기화

```c++
int Value = 5;
```

* 직접 초기화

```c++
int Value(5);
```







```c++
int main() {
    int a(10);
    
    
    a(5);  //이렇게는 변수 선언 할 수 없음 => 함순지 변순지 알수 없음
}
```

