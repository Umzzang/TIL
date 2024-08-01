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
> 3, string("one"),x+y,&x, x++, 함수값, 임시 객체()





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







#### 범위지정 for 문에 동적할당된 배열은 사용하지 못한다 => 정확한 길이를 모르기 때문에





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
>
> 구조체와 클래스의 선언은 메모리를 할당받지 않는다.



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



* **멤버변수명과 매개변수명이 같을 때, 어떻게 구별할까???**

```c++
#include <iostream>

using namespace std;

class GameWindow {
public:
    void ResizeWindow(int, int); 
    
private:
    int w;
    int h;
};

int GameWindow::GetW() {return w;}
int GameWindow::GetH() {return h;}

void GameWindow::ResizeWindow(int w, int h) {
    if ( w < 800) w = 800;
    else .w = w;
    if ( h < 600) h = 600;
    else h = h;
}

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366,768);

    cout << mainWindow.GetW() << ", " << mainWindow.GetH() << endl;
}
```

=> 이럴 경우 w, h 모두를 ResizeWindow 안에서 매개변수로 인식하게 됨.

```
800, 600
```



* (*this).

```c++
#include <iostream>

using namespace std;

class GameWindow {
public:
    void ResizeWindow(int, int); 
    
private:
    int w;
    int h;
};

int GameWindow::GetW() {return w;}
int GameWindow::GetH() {return h;}

void GameWindow::ResizeWindow(int w, int h) {
    if ( (*this).w < 800) (*this).w = 800;
    else (*this).w = w;
    if ( (*this).h < 600) (*this).h = 600;
    else (*this).h = h;
}

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366,768);

    cout << mainWindow.GetW() << ", " << mainWindow.GetH() << endl;
}
```

* this->

```c++
#include <iostream>

using namespace std;

class GameWindow {
public:
    void ResizeWindow(int, int); 
    
private:
    int w;
    int h;
};

int GameWindow::GetW() {return w;}
int GameWindow::GetH() {return h;}

void GameWindow::ResizeWindow(int w, int h) {
    if ( this->w < 800) this->w = 800;
    else this->w = w;
    if ( this->h < 600) this->h = 600;
    else this->h = h;
}

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366,768);

    cout << mainWindow.GetW() << ", " << mainWindow.GetH() << endl;
}
```

```
1366, 768
```











### static member

> 변하지 않는 멤버 <-> 동적멤버
>
> 클래스에 대한 멤버 : 인스턴스에 대한 멤버가 아님

```c++
#include <iostream>

using namespace std;

class Color {
public:
    Color () : r(0), g(0), b(0) {}
    Color (float r, float g, float b) : r(r), g(g), b(b) {}

    float GetR() {return r;}
    float GetG() {return g;}
    float GetB() {return b;}


private:
    float r;
    float g;
    float b;
};

Color MixClors(Color a, Color b) {
    return Color((a.GetR() + b.GetR())/2, (a.GetG() + b.GetG())/2, (a.GetB() + b.GetB())/2);
}

int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    Color purple = MixClors(blue, red);
    cout << "r=" << purple.GetR() << "g=" << purple.GetG() << "b=" << purple.GetB() << endl;

}
```

=> MixClors 를 class 안으로 넣으면 아래와 같아짐

```c++
#include <iostream>

using namespace std;

class Color {
public:
    Color () : r(0), g(0), b(0) {}
    Color (float r, float g, float b) : r(r), g(g), b(b) {}

    float GetR() {return r;}
    float GetG() {return g;}
    float GetB() {return b;}

    static Color MixClors(Color a, Color b) {
        return Color((a.r + b.r)/2, (a.g + b.g)/2, (a.b + b.b)/2);
    }
private:
    float r;
    float g;
    float b;
};

int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    Color purple = Color::MixClors(blue, red);
    cout << "r=" << purple.GetR() << "g=" << purple.GetG() << "b=" << purple.GetB() << endl;
}
```

```
r=0.5g=0b=0.5
```



* static member 변수 사용(id)

```c++
#include <iostream>

using namespace std;

class Color {
public:
    Color () : r(0), g(0), b(0), id(idCounter++) {}
    Color (float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}

    float GetR() {return r;}
    float GetG() {return g;}
    float GetB() {return b;}

    int getId() {return id;}

    static Color MixClors(Color a, Color b) {
        return Color((a.r + b.r)/2, (a.g + b.g)/2, (a.b + b.b)/2);
    }

    static int idCounter;

private:
    float r;
    float g;
    float b;

    int id;
};

int Color::idCounter = 1;

int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);

    Color purple = Color::MixClors(blue, red);
    cout << "r=" << purple.GetR() << "g=" << purple.GetG() << "b=" << purple.GetB() << endl;

    cout << "blue의 id = " << blue.getId() << endl;
    cout << "red의 id = " << red.getId() << endl;
    cout << "purple의 id = " << purple.getId() << endl;
}
```

```
r=0.5g=0b=0.5
blue의 id = 1
red의 id = 2
purple의 id = 3
```

=> 다양한 클래스에 대하여 id 값을 전역변수로 하는 행동보다 클래스 내부에서 static  처리하는 것이 효과적이고 확실하다.



### const

> 실수 방지를 위하여 접근을 제한 하도록 하는 것
>
> 매개변수의 상수화
>
> 메서드의 상수화(멤버 메서드)

```c++
#include <iostream>

using namespace std;

class Account {
public:
    Account() : money(0) {}
    Account(int money) : money(money) {}

    void Deposit(const int d) {
        money += d;
        cout << d << "원 예금" << endl;
    }

    void Draw(const int d) {
        if (money >= d) {
        	money -= d;
        	cout << d << "원 인출" << endl;    
        } 
    }

    int ViewMoney() const {    // const int ViewMoney() 랑은 다름.
        return money;
    }

private:
    int money;
};

int main() {
    Account doodle(200);
    doodle.Deposit(100);
    doodle.Draw(20);

    cout << doodle.ViewMoney() << endl;
}
```



### 정적 vs 동적

* 정적인 것은 클래스에 속한 것
* 동적인 것은 인스턴스로 넘어가는 것





### vector

 ```c++
 # include <iostream>
 
 using namespace std;
 
 
 class Vector2 {
 public:
     Vector2();
     Vector2(float x, float y);
 
     float GetX() const; 
     float GetY() const; 
 
     static Vector2 Sum(Vector2 a, Vector2 b) {    // 정적인 메소드
         return Vector2(a.x + b.x, a.y + b.y);
     }
 
     Vector2 Add(Vector2 rhs) {                     // 동적인 메소드
         return Vector2(x + rhs.x, y + rhs.y);
     }
 
 
 private:
     float x;
     float y;
 };
 
 
 
 int main() {
     Vector2 a(2,3);
     Vector2 b(-1,4);
     Vector2 c = Vector2::Sum(a,b);
     Vector2 d = a.Add(b);
 
     cout << a.GetX() << "," << a.GetY() << endl;
     cout << b.GetX() << "," << b.GetY() << endl;
     cout << c.GetX() << "," << c.GetY() << endl;
     cout << d.GetX() << "," << d.GetY() << endl;
 }
 
 Vector2::Vector2() : x(0), y(0) {}
 Vector2::Vector2(float x, float y) : x(x), y(y) {}
 float Vector2::GetX() const {return x;}
 float Vector2::GetY() const {return y;}
 ```

```
2,3
-1,4
1,7
1,7
```



### 연산자 오버라이딩 (operator)

```c++
# include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const; 
    float GetY() const; 

    static Vector2 Sum(Vector2 a, Vector2 b) {
        return Vector2(a.x + b.x, a.y + b.y);
    }

    Vector2 Add(Vector2 rhs) {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    Vector2 operator+(const Vector2 rhs) const;
    Vector2 operator-(const Vector2 rhs) const;
    Vector2 operator*(const float rhs) const;
    Vector2 operator/(const float rhs) const;
    float operator*(const Vector2 rhs) const;

private:
    float x;
    float y;

};

int main() {
    Vector2 a(2,3);
    Vector2 b(-1,4); 
    Vector2 c = a-b;
    Vector2 d = a* 1.6;
    Vector2 e = a/2;
    Vector2 f = a + b;
    float g = a * b;

    cout << a.GetX() << "," << a.GetY() << endl;
    cout << b.GetX() << "," << b.GetY() << endl;
    cout << c.GetX() << "," << c.GetY() << endl;
    cout << d.GetX() << "," << d.GetY() << endl;
    cout << e.GetX() << "," << e.GetY() << endl;
    cout << f.GetX() << "," << f.GetY() << endl;
    cout << f.GetX() << "," << f.GetY() << endl;
    cout << g << endl;
}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const {return x;}
float Vector2::GetY() const {return y;}

Vector2 Vector2::operator+(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
    } 

Vector2 Vector2::operator-(const Vector2 rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
    return Vector2(x*rhs, y*rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
    return Vector2(x/rhs, y/rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
    return x*rhs.x + y*rhs.y;
}
```



###  class 문제

```c++
#include <iostream>

using  namespace std;

class MyClass {
public:
    MyClass() : num(cnt++) {}

    void Check(MyClass *ptr) {
        if (ptr + num == this) {
            cout << num << endl;

        }
    }
    static int cnt;

private:
    int num;
};

int MyClass::cnt = 0;

int main () {
    MyClass obj[5];

    cout << "TEST 1" << endl;

    for (int i = 0; i< 5; i++) {
        obj[i].Check(obj);
    }
    cout << "TEST 2" << endl;
    for (MyClass &i : obj) {
        i.Check(obj);
    }
    cout << MyClass::cnt << endl;
}
```

```
TEST 1
0
1
2
3
4
TEST 2
0
1
2
3
4
5
```











## 객체 생성 & 소멸

> 생성자는 멤버 변수 초기화
>
> 소멸자는 메모리 해제
>
> 둘다 default 값이 존재함
>
> 괄호, 중괄호 초기화는 차이점이 존재한다. => 나중에 확인

```c++
#include <iostream>

using namespace std;

class MyClass {
    public:
    MyClass () { //생성자
        
    }

    ~MyClass () { // 소멸자
        
    }

};
```

=> 이런식으로 default 값 존재



* 생성자, 소멸자도 오바라이딩 가능

```c++
#include<iostream>

using namespace std;

class Complex {
public:
    Complex () {
        real = 0;
        image = 0;
    }

    Complex (int real_, int image_) {
        real = real_;
        image = image_;
    }

    int getReal() {
        return real;
    }
    int getImage() {
        return image;
    }


private:
    int real;
    int image;
};


int main() {
    Complex c1;
    Complex c2 = Complex(2,3);
    Complex c3(5,3);

    cout << "c1 : " << c1.getReal() << ',' << c1.getImage() << endl;
    cout << "c2 : " << c2.getReal() << ',' << c2.getImage() << endl;
    cout << "c3 : " << c3.getReal() << ',' << c3.getImage() << endl;
}
```

```
c1 : 0,0
c2 : 2,3
c3 : 5,3
```



* 다른 방식의 생성자 표현

```c++
#include<iostream>

using namespace std;

class Complex {
public:
    Complex () : real(0), image(0) {}  // 이런식으로도 가능

    Complex (int real, int image) : real(real), image(image) {}   // 멤버변수와 같게 해줘도 상관없음

    int getReal() {
        return real;
    }
    int getImage() {
        return image;
    }

private:
    int real;
    int image;
};
```



### 생성자

> 객체가 생성될 때 자동으로 호출되는 함수



* 생성자 위임

> 같은 부분이 존재하는 생성자들을 간단하게 표현하기 위한 방법

``` c++
#include <iostream>

using namespace std;

class Time {
public:
    Time() :h(0), m(0), s(0) {}

    Time (int s_) : Time() {
        s = s_;
    }

    Time (int s_, int m_) : Time(s_) {
        m = m_;
    }

    Time (int s_, int m_, int h_) : Time(s_, m_) {
        h = h_;
    }

    int h;
    int m;
    int s;
};

int main() {
    Time t1;
    Time t2(5);
    Time t3(3, 16);
    Time t4(2, 42, 15);

    cout << "t1 : " << t1.h << ":" << t1.m << ":" << t1.s << endl;
    cout << "t2 : " << t2.h << ":" << t2.m << ":" << t2.s << endl;
    cout << "t3 : " << t3.h << ":" << t3.m << ":" << t3.s << endl;
    cout << "t4 : " << t4.h << ":" << t4.m << ":" << t4.s << endl;
}
```

```
t1 : 0:0:0
t2 : 0:0:5
t3 : 0:16:3
t4 : 15:42:2
```





### 소멸자

> 객체가 소멸될 때 자동으로 호출되는 함수



```c++
#include <iostream>

using namespace std;

class MyClass {
    public:
    MyClass () { //생성자
        cout << "생성자가 호출" << endl;
    }

    ~MyClass () { // 소멸자
        cout << "생성자가 소멸" << endl;
    }

};

MyClass globalObj;

void testLocalObj () {
    cout << "testLocalObj 함수 시작" << endl;
    MyClass localObj;
    cout << "testLocalObj 함수 끝" << endl;
}

int main () {
    cout << "main 함수 시작" << endl;
    testLocalObj();
    cout << "main 함수 끝" << endl;
}
```

```
생성자가 호출
main 함수 시작
testLocalObj 함수 시작
생성자가 호출
testLocalObj 함수 끝
생성자가 소멸
main 함수 끝
생성자가 소멸
```





## 동적 할당 & 객체 복사

> 정적 할당은 컴파일 단계, 동적 할당은 런타임중에 일어난다.

### 정적 할당

> int a;

  

### 동적 할당

> 프로그램 실행 중에 변수를 메모리에 할당하는 것



```c++
#include <iostream>

using namespace std;

int main() {
    int *a = new int(5);

    cout << a << endl;
    cout << *a << endl;

    *a = 10;

    cout << a << endl;
    cout << *a << endl;

    //delete a;

    cout << a << endl;
    cout << *a << endl;
}
```

```
0x691750
5
0x691750
10
0x691750
10
```

```
//delete a 했을 때
0xe61750
5
0xe61750
10
0xe61750
15080128
```





* 배열 동적 할당

```c++
#include <iostream>

using namespace std;

int main() {
    int *arr;
    int len;

    cout << "길이:";
    cin >> len;

    arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = len - i;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    cout<< arr[0] << endl;
    cout<< arr << endl;
    cout<< *arr << endl;
    delete[] arr;                  // 배열 메모리 해제는 반드시 delete 뒤에 [] 붙어야함.
    cout<< arr[0] << endl;
    cout<< arr << endl;
    cout<< *arr << endl;
}
```

```
길이:3
3
2
1
3
0xf31750
3
15932096
0xf31750
15932096
```



* 객체

```c++
#include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2() : x(0), y(0) {
        cout << this << " : Vector2()" << endl;
    }

    Vector2(const float x , const float y) : x(x), y(y) {
        cout << this << " : Vector2(const float x , const float y)" << endl;
    }

    ~Vector2() {
        cout << this << " : Vector2()" << endl;
    }

    float GetX() const {return x;}
    float GetY() const {return y;}

private:
    float x;
    float y;
};

int main() {
    Vector2 s1 = Vector2();
    Vector2 s2 = Vector2(3,2);

    Vector2 *d1 = new Vector2();
    Vector2 *d2 = new Vector2(3,2);

    cout << "(" << d1->GetX() << "," << d1->GetY() << ")" << endl;
    cout << "(" << d2->GetX() << "," << d2->GetY() << ")" << endl;

    delete d1;
    delete d2;
}
```

```
0x61fdf8 : Vector2()
0x61fdf0 : Vector2(const float x , const float y)
0xde1750 : Vector2()
0xde1770 : Vector2(const float x , const float y)
(0,0)
(3,2)
0xde1750 : Vector2()
0xde1770 : Vector2()
0x61fdf0 : Vector2()
0x61fdf8 : Vector2()
```





### 깊은복사 & 얕은 복사

> 깊은 복사는 '값' 을 복사 => 즉, 여러개의 주소가 필요
>
> 얕은 복사는 '주소'를 복사





```c++
int main() {
    int *a = new int(5);
    int *b = new int(3);
    
    a = b;    //얕은 복사 (참조를 복사)
    
    delete a;
    delete b;
}
```

![image-20230626083547817](C:\Users\티로보틱스\AppData\Roaming\Typora\typora-user-images\image-20230626083547817.png)

* 100번지 주소가 해제되지 않음
* delete a 후에 delete b를 하면 에러 발생 (이미 delete 된 주소를 또 delete할 수 없음.)

* 아래처럼 해야함

```c++
int main() {
    int *a = new int(5);
    int *b = new int(3);
    
    *a = *b;   // 깊은 복사 (값을 복사)
    
    delete a;
    delete b;
}
```





#### #######\<cstring> vs \<string> #########

> cstring은 c언어에서 string.h 헤더 파일을 c++형태로 바꾼것 이라고 생각
>
> string  은 기존 cstring의  불편한점 을 개선하기 위하여 탄생한 것



1. Flexible storage capacity
   * 매번 사이즈 선언 필요없음
   * 파이썬처럼 좀더 자유로움
2. No need to worry about memory
   * 메모리 걱정 ㄴ, 문자열 재할당 할 필요도 없음

3. Boundary issues are handled for me, with or without a null character
4. using = operator rather than strcpy
5. using == operator rather than strcmp

```c++
#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    String() {
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        len = strlen(str);      // 길이를 미리 알아야함
        strData = new char[len + 1];     // \0이 마지막에 들어가기 때문에 실제 길이보다 +1해서 할당
        strcpy(strData, str);
    }
    
    ~String() {
        delete[] strData;
    }

private:
    char *strData;
    int len;
};
```

* \<string> 사용

```c++
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

    }
    
    ~String() {
        delete[] strData;
    }

private:
    const char *strData;
    int len;
};
```







### 복사 생성자 오버라이딩

 ```c++
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
 ```

```
String(const char*) 생성자 호출
strData 할당:0x651770
안녕
안녕
~String() 소멸자 호출
strData 해제됨:0x651770
~String() 소멸자 호출
```

=> 생성자 호출 한번만 됨

=> strData에 할당 한번만 됨

=> 얕은 복사가 일어남.



```c++
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

    String(const String &rhs) {    // 복사하는 값이 변하면 안되기 때문에 const 박자
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
```

```
String(const char*) 생성자 호출
strData 할당:0xee1770
String(const &rhs) 생성자 호출
strData 할당:0xee1790
안녕
안녕
~String() 소멸자 호출
strData 해제됨:0xee1790
~String() 소멸자 호출
strData 해제됨:0xee1770
```

=> 깊은 복사로 실행됨





#### #######void*#######

> 단순히 주소값만 저장하는 포인터
>
> 어떤 자료형인지 몇바이튼지에 대한 정보는 없음
>
> 따라서 수정 불가

```c++
char *strData;

// 1.
char *ptr = strData;
*ptr = 'A'; // 가능

// 2.
void *ptr = strData;
*ptr = 'A'; // 불가능
```





### 대입 연산자 오버로딩

> 선언과 동시에 값을 넣는 것이아니라 
>
> 선언 후에 값을 넣을 때는 복사 생성자로 불가능 => 연산자 오버로딩

```c++
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

    String &operator=(const String &rhs) {   // 참조를 하지 않게 되면 새로운 String  객체를 생성하고 그것을 대입하는 형식으로 진행됨
        // operator 결과값도 reference로, 아니면 또 새로운 String 복사 일어남
        if (this != &rhs) {   // &rhs는 위의 &rhs와 다르다 . 이줄은 주소를 나타냄 => 자기 자신을 대입하는 경우 방지하기 위하여 분기처리
        delete[] strData;
        strData = new char[rhs.len + 1];
        cout << "strData 할당:" << (void*)strData << endl;
        strcpy(strData, rhs.strData);
        len = rhs.len;
        }
        return *this;        // rhs 는 const string 이기 때문에 return할 수없음 => *this는 객체가 속해있는 주소값 => 객체 자체를 반환
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
    String s3("Hello");
    s3 = s1;

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    cout << s3.GetStrData() << endl;
}
```

```
String(const char*) 생성자 호출
strData 할당:0x721770
String(const &rhs) 생성자 호출
strData 할당:0x721790
String(const char*) 생성자 호출
strData 할당:0x721ae0
Hello
strData 할당:0x721ae0
안녕
안녕
안녕
~String() 소멸자 호출
strData 해제됨:0x721ae0
~String() 소멸자 호출
strData 해제됨:0x721790
~String() 소멸자 호출
strData 해제됨:0x721770
```





### 임시 객체

```c++
String getName() {
    String res("doodle");
    return res;
}

int main() {
    String a;
    a = getName();
}
```

=> 위와 같은 코드를 작성할 때,  getName()은 res를 리턴하지만 결국 getName이 리턴 될때 함수가 종료되므로 res는 메모리상에서 소멸된다.

=> 그렇다면 a에 반환되는 값은 무엇인가??

=> 임시 객체

=> a에 임시 객체가 넘어가면 임시객체 소멸

#### 결론적으로 깊은복사가 2번일어남, 불필요한 깊은복사 2번

#### => 소멸자가 한번만 일어나도록 얕은복사를 이용



### 이동 시멘틱

> 깊은 복사 2번을 없애고 얕은 복사로 효율을 높이기 위한 방법
>
> 이동 생성자 & 이동 대입연산자 



#### 임시 객체는 r-value!! => &&(rvalue 참조자) 로 참조 가능



``` c++
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
        cout << "String() 생성자 호출 " << this <<  endl;
        strData = NULL;
        len = 0;
    }

    String(const char *str) {
        cout << "String(const char*) 생성자 호출 " << this <<  endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str); //깊은 복사
    }

    // String(String &rhs) {    //복사생성자 :  복사 생성자의 경우, 같은 클래스의 객체를 복사하기 때문에 참조로 넣어주어야 함.
    //     strData = rhs.strData;   // strData는 포인터이기 때문에  => 얕은복사
    //     len = rhs.len;     // int이기 때문에 다른 len임 => 깊은복사
    // }

    String(const String &rhs) {
        cout << "String(const string&) 생성자 호출 " << this << endl;
        alloc(rhs.len);
        strcpy(strData, rhs.strData); //깊은 복사
        len = rhs.len;
    }

    String(String &&rhs) {   //  매개변수가 rvalue
        cout << "String(String&&) : " << this << endl;
        len = rhs.len;
        strData = rhs.strData;
        rhs.strData = NULL;
    }
    
    ~String() {
        cout << "~String() 소멸자 호출 " << this <<  endl;
        release();
        strData = NULL; // 해제된 메모리에 대한 접근을 막기위해서 하지만, 임시방편
    }

    String &operator=(const String &rhs) {   // 참조를 하지 않게 되면 새로운 String  객체를 생성하고 그것을 대입하는 형식으로 진행됨
        // operator 결과값도 reference로, 아니면 또 새로운 String 복사 일어남
        cout << "String &operator=(const String&) : " << this << endl;
        if (this != &rhs) {   // &rhs는 위의 &rhs와 다르다 . 이줄은 주소를 나타냄 => 자기 자신을 대입하는 경우 방지하기 위하여 분기처리
            release();
            alloc(rhs.len);
            strcpy(strData, rhs.strData);
            len = rhs.len;
        }
        return *this;        // rhs 는 const string 이기 때문에 return할 수없음 => *this는 객체가 속해있는 주소값 => 객체 자체를 반환
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
```





### 묵시적 형변환

```c++
// 묵시적(암시적) 형변환  implicit conversion
// 명시적 형변환 explicit conversion


#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num): num(num) {   // 변환 생성자
        cout << "Item(int)" << endl;
    }

    Item(string name) : name(name) {
        cout << "Item(string)" << endl;
    }

    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }

    void print() {
        cout << num << " : " << name << endl;
    }

private:
    int num;
    string name;
};

int main() {
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;        // 묵시적 형변환

    Item i4 = (Item)4;   // 변환 생성자를 통하여 생성 , 명시적 형변환

    Item i5("stone");
    Item i7 = (string)"stone";
    Item i6(5);
    i6 = string("stone");

    Item i8(1,"glass");
    Item i9 = {2, "dirt"};
    i9 = {2, "clean"}; // 묵시적 형변환

    i1.print();
    i2.print();
    i3.print();
    i4.print();
    i5.print();
    i6.print();
    i7.print();
    i8.print();
    i9.print();
}
```

```
Item(int)
Item(int)
Item(int)
Item(int)
Item(int)
Item(string)
Item(string)
Item(int)
Item(string)
Item(int, string)
Item(int, string)
Item(int, string)
1 :
2 :
3 :
4 :
0 : stone
15532032 : stone
1876032832 : stone
1 : glass
2 : clean
```



* int or stirng 형변환 연산자

```c++
// 묵시적(암시적) 형변환  implicit conversion
// 명시적 형변환 explicit conversion


#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num): num(num) {   // 변환 생성자
        cout << "Item(int)" << endl;
    }

    Item(string name) : name(name) {
        cout << "Item(string)" << endl;
    }

    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }

    //int 로의 형변환 연산자 오버로딩
    operator int() const {
        return num;
    }
    // string으로의 형변환 연산자 오버로딩
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
    i3 = 3;        // 묵시적 형변환

    Item i4 = (Item)4;   // 변환 생성자를 통하여 생성 , 명시적 형변환

    Item i5("stone");
    Item i7 = (string)"stone";
    Item i6(5);
    i6 = string("stone");

    Item i8(1,"glass");
    Item i9 = {2, "dirt"};
    i9 = {2, "clean"}; // 묵시적 형변환

    int itemNum1 = (int)i8;    // 명시적
    int itemNum2 = i9;   //묵시적
    cout << itemNum1 << endl;
    cout << itemNum2 << endl;

    printIn(string(i8));  //명시적
    printIn(i8);   //묵시적
}
```

```
Item(int)
Item(int)
Item(int)
Item(int)
Item(int)
Item(string)
Item(string)
Item(int)
Item(string)
Item(int, string)
Item(int, string)
Item(int, string)
1
2
1 : glass
1 : glass
```



* explicit 사용하면 명시적만 가능 => 묵시적 형변환 무시하게 됨







#### ########## 문자열 관련 헷갈리는 부분 ########### #########

```c++
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
```

```
Hello
H
Hello
H
0x61fe12
```





