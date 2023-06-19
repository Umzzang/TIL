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



### namespace 중첩

```c++
#include <iostream>

using namespace std;

int n;

void set() {
    n = 10;
}

namespace doodle {
    int n;
    void set() {
        n = 20;
    }
    namespace google {
        int n;
        void set() {
            n = 30;
        }
    }
}

int main() {
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n <<endl;
    cout << doodle::n <<endl;
    cout << doodle::google::n <<endl;
}
```

```
10
20 
30
```

```c++
#include <iostream>

using namespace std;


int n;

void set() {
    n = 10;
}

namespace doodle {
    int n;
    void set() {
        n = 20;
    }
    namespace google {
        void set() {
            n = 30;
        }
        int n;
    }
}

int main() {
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n <<endl;
    cout << doodle::n <<endl;
    cout << doodle::google::n <<endl;
}
```

```
10
30
0
```

=> doodle의 int n; 위치를 바꿔줌 => set 이후에 n을 선언했기 때문에 set 안의 n 은 바깥의 n으로 인식



```c++
#include <iostream>

using namespace std;

int n;

void set() {
    n = 10;
}

namespace doodle {
    void set();
    namespace google {
        void set();
        int n;
    }
    int n;
}

int main() {
    ::set();
    doodle::set();
    doodle::google::set();

    cout << ::n <<endl;
    cout << doodle::n <<endl;
    cout << doodle::google::n <<endl;
}

void doodle::set() {
    n = 20;
}

void doodle::google::set() {
    n = 30;
}
```

```
10
20
30
```

=> 함수의 정의를 밖으로 빼면 결과가 또 바뀜







## 변수 



```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int x = 3;
    const int y = x;
    int z = x + y;
    int* p = &x;

    cout << string("one");

    ++x;
    x++;
}
```



### Rvalue

> 단일 표현식 이후에 더 이상 존재하지 않는 임시적인 값
>
> 3, string("one"),x+y,&x, x++, 함수값





### Lvalue

> 단일 표현식 이후에도 없어지지 않고 지속되는 객체
>
> x, y, z, p, ++x



```c++
&(++x);
&(x++);     // error C2102: '&' requires l-value
```



### Rvalue 참조자 &&

```c++
int rvalue()
{
    return 10;
}

int main()
{
    int lvalue = 10;

    int& a = lvalue;
    int& b = rvalue();      // error C2440: 'initializing' : cannot convert from 'int' to 'int &'

    int&& c = lvalue;       // error C2440: 'initializing' : cannot convert from 'int' to 'int &&'
    int&& d = rvalue();
}
```











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



### 포인터(pointer)

> 다른 값의 주소를 보유하는 변수
>
> int *k

![image-20230619125253841](C:\Users\티로보틱스\AppData\Roaming\Typora\typora-user-images\image-20230619125253841.png)







### 참조형(reference)

> 이미 존재하는 변수에 대한 별칭(?)
>
> 참조하는 값과 완벽하게 동일하게 작동함
>
> int &b

![image-20230619125240201](C:\Users\티로보틱스\AppData\Roaming\Typora\typora-user-images\image-20230619125240201.png)



### 포인터, 참조자 차이

* 차이점 ① : 포인터는 NULL 값을 가질 수 있지만, 참조자는 NULL 값을 가질 수 없다. 즉, NULL Reference는 없다.
* 차이점 ② : 초기화시, 참조자는 객체(또는 변수)를 직접 입력받고, 포인터는 객체(또는 변수)의 주소값을 입력받는다.
* 차이점 ③ : 참조자는 한 번 가리킨 대상을 변경할 수 없지만, 포인터는 자신이 가리키는 대상을 언제든지 변경할 수 있다.
*  차이점 ④ : 클래스 멤버 접근시, 참조자는 "."을 사용하고 포인터는 "->"를 사용한다.
*  차이점 ⑤ : 접근 비용의 차이가 있다. 포인터를 사용하면 포인터를 위한 메모리 공간도 필요하다.





## for



```c++
#include <iostream>


using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i=0; i<10; i++)
        {    
        cout << arr[i] << "";
        }

        cout << endl;

    for(int elem : arr)
        {
        cout << elem << "";
        }

        cout << endl;

    for(int &elem : arr)
        {
        elem++;
        cout << elem << "";
        }

        cout << endl;
        
    for(int i=0; i<10; i++)
        {    
        cout << arr[i] << "";
        }

        cout << endl;
            
}
```

```
12345678910
12345678910
234567891011
234567891011
```



### 2중 배열

```c++
#include <iostream>

using namespace std;

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};

    for (int(&ln)[3] : arr) {
        for (int &col : ln) {
            cout << col << ' ';
        }
        cout << endl;
    }
}
```

```
1 2 3 
4 5 6
```



```c++
#include <iostream>

using namespace std;

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};

    for (auto &ln : arr) {
        for (auto &col : ln) {
            cout << col << ' ';
        }
        cout << endl;
    }
}
```











## 함수



### overload(다중 정의)

> 같은 이름의 함수를 여러번 정의가 가능함.
>
> 단, 각 함수마다 받는 매개변수의 형태가 달라야 함.

```c++
#include <iostream>

using namespace std;

int inventory[64] = {0};
int score = 0;

void getItem(int itemId) {
    inventory[itemId]++;
}

void getItem(int itemId, int cnt) {
    inventory[itemId] += cnt;
}

void getItem(int itemId, int cnt, int sc) {
    inventory[itemId] += cnt;
    score += sc;
}

int main() {
    getItem(6,5);
    getItem(3,2);
    getItem(3);
    getItem(11,34,7000);

    cout<<score<<endl;
    for (int i =0;i<16;i++) {
        cout<<inventory[i]<<' ';
    }
    cout<<endl;
}
```

```
7000
0 0 0 3 0 0 5 0 0 0 0 34 0 0 0 0
```

=> 함수 이름 같지만, 전혀 문제되지 않음



* default 변수값 (항상 오른쪽에서부터 넣어야 함)

```c++
#include <iostream>

using namespace std;

int inventory[64] = {0};
int score = 0;

void getItem(int itemId, int cnt = 1, int sc = 0) {
    inventory[itemId] += cnt;
    score += sc;
}

int main() {
    getItem(6,5);
    getItem(3,2);
    getItem(3);
    getItem(11,34,7000);

    cout<<score<<endl;
    for (int i =0;i<16;i++) {
        cout<<inventory[i]<<' ';
    }
    cout<<endl;
}
```

```
7000
0 0 0 3 0 0 5 0 0 0 0 34 0 0 0 0
```







## Class

> 클래스 = 자료 저장 + 자료 처리 = 변수 + 함수 를 모아 둔 틀(자료형)
>
> 객체(오브젝트) : 틀(클래스)를 이용하여 찍어낸 객체(변수, 메모리 상의 공간)



### struct

```c++
#include <iostream>

using namespace std;

struct TV {

    private:  // 밖에서는 접근 불가
    bool powerOn;
    int channel;
    int volume;
    public:    // 밖에서 접근 가능

    void on() {
        powerOn = true;
        cout << "TV를 켰습니다" << endl;
    }

    void off() {
        powerOn = false;
        cout << "TV를 껐습니다" << endl;
    }

    void setChannel(int cnl) {
        if (cnl >= 1 && cnl <=100) {
            channel = cnl;
            cout << "채널을" << cnl << "으로 바꿨습니다" << endl;
        }
    }

    void setVolume(int vol) {
        if (vol >= 0 && vol <=100) {
            volume = vol;
            cout << "볼륨을" << vol << "으로 바꿨습니다" << endl;
        }
    }
};


int main() {
    TV lg;
    lg.on();
    //lg.powerOn = true;
    lg.setChannel(30);
    //lg.channel = 10;
    lg.setVolume(50);
    //lg.volume = 400; //이런식으로 하면 문제가 될 수 있음
}
```

```
TV를 켰습니다
채널을30으로 바꿨습니다
볼륨을50으로 바꿨습니다
```



* class의 경우 기본값이 private으로 지정
* public을 지정해줘야함



### this

> 객체 지향 프로그래밍에서 가장 많은 질문 중 하나는 "클래스의 멤버 함수를 호출할 때 C++는 어떻게 호출할 객체(인스턴스)를 찾는가?"
>
> => 숨겨진 매개변수 this pointer를 사용함.

```c++
#include <iostream>

using namespace std;

class MyClass {
    public:
    void PrintThis() {
        cout << "나의 주소는 " << this << endl;
    }
};


int main() {
    MyClass a, b;
    cout << "a의 주소는" << &a << endl;
    cout << "b의 주소는" << &b << endl;

    a.PrintThis();
    b.PrintThis();
}
```

=> 숨겨진 변수의 주소가 매개변수로 주어지게 됨.























