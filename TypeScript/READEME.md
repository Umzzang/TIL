# 타입스크립트



## 타입스크립트를 사용하는 이유

```javascript
5 - '3' => 연산이 가능하다 : javascript는 동적타이핑이 가능하기 때문
						=> 코딩 작성할때는 자유롭게 가능하지만 동적 타이핑은 협업 혹은 리팩토링할때 좋지 않다.
                        
```

```typescript
5 - '3' => 타입이 다르기 때문에 오류 발생 : typescript 는 정적 타이핑
```



* 브라우저는 ts 파일 읽지못한다 => js로 변환이 필요함  

  * ```bash
    tsc -w
    ```

  * tsconfig.json => ts -> js 컴파일시 옵션설정하는 부분

  ```
  {
   "compilerOptions": {
  
    "target": "es5", // 'es3', 'es5', 'es2015', 'es2016', 'es2017','es2018', 'esnext' 가능
    "module": "commonjs", //무슨 import 문법 쓸건지 'commonjs', 'amd', 'es2015', 'esnext'
    "allowJs": true, // js 파일들 ts에서 import해서 쓸 수 있는지 
    "checkJs": true, // 일반 js 파일에서도 에러체크 여부 
    "jsx": "preserve", // tsx 파일을 jsx로 어떻게 컴파일할 것인지 'preserve', 'react-native', 'react'
    "declaration": true, //컴파일시 .d.ts 파일도 자동으로 함께생성 (현재쓰는 모든 타입이 정의된 파일)
    "outFile": "./", //모든 ts파일을 js파일 하나로 컴파일해줌 (module이 none, amd, system일 때만 가능)
    "outDir": "./", //js파일 아웃풋 경로바꾸기
    "rootDir": "./", //루트경로 바꾸기 (js 파일 아웃풋 경로에 영향줌)
    "removeComments": true, //컴파일시 주석제거 
  
    "strict": true, //strict 관련, noimplicit 어쩌구 관련 모드 전부 켜기
    "noImplicitAny": true, //any타입 금지 여부
    "strictNullChecks": true, //null, undefined 타입에 이상한 짓 할시 에러내기 
    "strictFunctionTypes": true, //함수파라미터 타입체크 강하게 
    "strictPropertyInitialization": true, //class constructor 작성시 타입체크 강하게
    "noImplicitThis": true, //this 키워드가 any 타입일 경우 에러내기
    "alwaysStrict": true, //자바스크립트 "use strict" 모드 켜기
  
    "noUnusedLocals": true, //쓰지않는 지역변수 있으면 에러내기
    "noUnusedParameters": true, //쓰지않는 파라미터 있으면 에러내기
    "noImplicitReturns": true, //함수에서 return 빼먹으면 에러내기 
    "noFallthroughCasesInSwitch": true, //switch문 이상하면 에러내기 
   }
  }
  ```

  * target : 타입스크립트파일을 어떤 버전의 자바스크립트로 바꿔줄지 정하는 부분

  * module : 자바스크립트 파일간 import 문법을 구현할 때 어떤 문법을 쓸지 정하는 곳입니다.

    ​			commonjs는 require 문법

    ​			es2015, esnext는 import 문법을 사용합니다. 



### 변수  - 기본 타입

* 기본 변수

> 변수명: 타입

```typescript
let 이름 :string = 'kim';
let 나이 :number = 20;
let 결혼했니 :boolean = false;
let 비워짐: null = null;
let 정의되지않음: undefined = undefined;
```



* 배열

> 타입[]

```typescript
let 회원들 :string[] = ['kim', 'park']
let 회원들 :(string | number)[] = [123, 'park']
```



* 객체(object)

> { 키: 타입 }

```typescript
let 내정보 : { age : number } = { age : 20 }
```



## ###### 굳이 모든 변수에 타입 지정해줄 필요 없음 => 초기값 설정하면 알아서 지정해줌 ###########



### 변수 - Union Type

* 기본 변수

> 변수명: 타입 | 타입 | 타입

```typescript
let 이름: string | number = 'kim';
let 나이: (string | number) = 100;
```



* 배열, 객체

```typescript
var 어레이: (number | string)[] = [1,'2',3]
// var 어레이: number | string[] = [1,'2',3] 과는 다른 것임 => 123 or ['kim']
var 오브젝트: {data : (number | string) } = { data : '123' }
```



* any

> 모든 타입 다가능 (사실상 js) => 사용 안하는게 좋음

* unknown

>  모든 타입 다가능 ,  any 보다 안전 => any는 아예 타입지정을 없애는 느낌이고, unknown은 그렇지 않음.



### 함수 타입

> function 함수명( x: number) :number(return되는 값의 타입) {}

```typescript
function 내함수(x :number) :number { 
  return x * 2 
} 
```



* return이 없을 때 void type 사용
* **타입 지정된 파라미터는 필수!!!!!!! => 자바스크립트와 다른점**

> ? 사용하면 옵션 파라미터 지정 가능  => x : number | undefined 와 완전 같음

```typescript
function 내함수(x? :number) { 

}
내함수(); //가능
내함수(2); //가능


// ****
function 내함수(x? :number) :number { 
  return x * 2 
}  

// => x : number | undefined  => union type이기 때문에 에러 발생
```





## 타입 확정하기 (Narrowing & Assertion)

* type narrowing

> 분기처리로 타입 나눠주면 됨.
>
> instanceof 같은 것 사용 

```typescript
function 내함수(x :number | string){
  if (typeof x === 'number') {
    return x + 1
  } 
  else if (typeof x === 'string') {
    return x + 1
  }
  else {
    return 0
  }
}
```



* type assertion

> as 사용
>
> 함부로 사용 x
>
> 1. narrowing 할때 사용(여러개 중에 하나로 좁힐 때) 	2. 무슨 타입이 들어올지 100% 확실할 때 사용

```typescript
function 내함수(x :number | string){
    let array : number[] = [];
    array[0] = x as number;
}
```





## type alias (타입 변수)

```typescript
type Animall = string | number | undefined;

let 동물 :Animall = 123;

// object
type 사람 = {
  name : string,
  age : number,
}

let teacher :사람 = { name : 'john', age : 20 } 
```



## readonly

> const 는 재할당만 금지! object value 수정은 가능

```typescript
const 여친 = {
  name : '엠버'
}
여친.name = '유라';  //const 변수지만 에러안남



////// readonly  //////
type Girlfriend = {
  readonly name : string,
}

let 여친 :Girlfriend = {
  name : '엠버'
}

여친.name = '유라' //readonly라서 에러남
```



## ?

> 하나의 타입을 여러개의 object에게 할당하고 싶을 때

```typescript
type Square = {
  color? : string,
  width : number,
}

let 네모2 :Square = { 
  width : 100 
}

let 네모1: Square = {
  color : 'blue',
  width : 100,
}
```



## type 합성(extend)

> **type 키워드는 재정의가 불가능!!!!!!!**

```typescript
type Name = string;
type Age = number;
type NewOne = Name | Age;   // type NewOne = string | number;
```



```typescript
type PositionX = { x: number };
type PositionY = { y: number };
type XandY = PositionX & PositionY
let 좌표 :XandY = { x : 1, y : 2 }
```



## Literal Types

> 타입만 지정하는 것이 아니러 정확한 값을 지정

```typescript
let john :'대머리';
let kim :'솔로';

let 방향: 'left' | 'right';
방향 = 'left';

//function
function 함수(a : 'hello') : 1 | 0 | -1 {
  return 1 
}
```



## as const

```typescript
var 자료 = {
  name : 'kim'
}

function 내함수(a : 'kim') {

}
내함수(자료.name)
// => 에러 발생   
// 자료.name 의 타입이 string이라서


////해결 방안
1. object 만들 때 타입을 잘 미리 정하든가 

2. 예전에 배웠던 assertion을 쓰시든가 (as 'kim' 이런걸 붙이는 겁니다)

3. 아니면 as const 라는걸 애초에 object 자료에 붙일 수 있습니다. 


var 자료 = {
  name : 'kim'
} as const;

function 내함수(a : 'kim') {

}
내함수(자료.name)

1. 타입을 object의 value로 바꿔줍니다. (타입을 'kim'으로 바꿔줍니다)

2. object안에 있는 모든 속성을 readonly로 바꿔줍니다 (변경하면 에러나게)
```



## 함수 타입

```typescript
type NumOut = (x : number, y : number ) => number 
let ABC :NumOut = function(x,y){
  return x + y
}

type Member = {
  name : string,
  age : number,
  plusOne : ( x :number ) => number,
  changeName : () => void
}

let 회원정보: Member = {
  name : 'kim',
  age : 30,
  plusOne (x){
    return x + 1
  },
  changeName : () => {
    console.log('안녕')
  }
}
```



## HTML과 사용하기

> html 요소 가져올때는 실제로 렌더링된 페이지에 있는지 없는지 확실하지 않기 때문에 | null  즉,  Union 타입으로 가져옴

```typescript
let 제목 = document.querySelector('#title');  // 실제로 id가 title인 element가 없을 수도 있음 => Element | null => narrowing 필요

1. narrowing 첫번째
if (제목 !== null) {
    제목.innerHTML = '반가워요'
}

2. 두 번째
if (제목 instanceof Element) {
    제목.innerHTML = '반가워요'
}

3. as 키워드 => 비추
let 제목 = document.querySelector('#title') as Element;
제목.innerHTML = '반가워요'

4. optional chaining
if (제목?.innerHTML) {
    제목.innerHTML = '반가워요'
}
// 1.제목에 innerHTML 이 있으면 출력  2. 없으면 undefined

5. tsconfig.json 설정 변경

```



```typescript
let 버튼 = document.getElementById('button');
버튼?.addEventListener('click', function(){
  console.log('안녕')
}) 
```



## class

```typescript
class Car {
  model :string;
  price :number;
  constructor(a :string, b :number){
    this.model = a;
    this.price = b;
  }

  tax() :number{
    return this.price * 0.1
  }
}
```



## interface

> interface는 중복선언 가능, type 은 중복선언 불가능

```typescript
interface Square { 
  color :string, 
  width :number, 
} 

let 네모 :Square = { color : 'red', width : 100 } 
```



* extends 가능 (중복속성있으면 에러)

```typescript
interface Student {
  name :string,
}
interface Teacher extends Student {
  age :number
}
```



* & (중복속성있으면 never type으로 취급할수도 있음) 

```typescript
interface Student {
  name :string,
}
interface Teacher {
  age :number
}

let 변수 :Student & Teacher = { name : 'kim', age : 90 }
```



## narrowing skills

* && (and)

```typescript
function printAll(strs: string | undefined) {
  if (strs && typeof strs === "string") {  
    console.log(s);
  } 
}
```

* 속성 in object

```typescript
type Fish = { swim: string };
type Bird = { fly: string };
function 함수(animal: Fish | Bird) {
  if ("swim" in animal) {
    return animal.swim
  }
  return animal.fly
} 
```

* literal type

```typescript
type Car = {
  wheel : '4개',
  color : string
}
type Bike = {
  wheel : '2개',
  color : string
}

function 함수(x : Car | Bike){
  if (x.wheel === '4개'){
    console.log('이 차는 ' + x.color)
  } else {
    console.log('이 바이크는 ' + x.color)
  }
}
```



## public, private, protected, static

* public

> **public이 붙은 속성은 자식 object들이 마음대로 사용하고 수정가능합니다.**
>
> public은 default 

```typescript
class User {
  public name: string;

  constructor(){
    this.name = 'kim';
  }
}

let 유저1 = new User();
유저1.name = 'park';  //가능
```



* private

> 무조건 class { } 중괄호 안에서만 수정 및 사용가능
>
> 심지어 class로 부터 생산된 자식 object에서도 private 붙은건 사용불가능
>
> **private 붙은 속성들은 오직 class { } 안에서만 수정이 가능**
>
> 외부에서 수정할수 없도록 하기위해 

```typescript
class User {
  public name :string;
  private familyName :string;  

  constructor(){
    this.name = 'kim';
    let hello = this.familyName + '안뇽'; //가능
  }
}

let 유저1 = new User();
유저1.name = 'park';  //가능
유저1.familyName = 456; //에러남
```



* protected

> 1. private 이거랑 똑같은데 2. extends 된 class 안에서도 사용가능

```typescript
class User {
  protected x = 10;
}

class NewUser extends User {
  doThis(){
    this.x = 20;
  }
}
```



* static

> instance에서 사용 불가능한 변수지정

```typescript
class User {
  x = 10;
  y = 20;
}

let john = new User();
john.x //가능
User.x //불가능

//static
class User {
  static x = 10;
  y = 20;
}

let john = new User();
john.x //불가능
User.x //가능
```



## namespace

> 타입변수를 숨기기 위해 object 안에 감싸는 것

```typescript
(a.ts)

namespace MyNamespace {
  export interface PersonInterface { age : number };
  export type NameType = number | string;
} 

(b.ts)

/// <reference path="./a.ts" />

let 이름 :MyNamespace.NameType = '민수';
let 나이 :MyNamespace.PersonInterface = { age : 10 };

type NameType = boolean; //사용 가능
interface PersonInterface {} //사용 가능 
```





## Generic

> 타입을 파라미터로 입력받는 것이 가능

```typescript
function 함수(x: unknown[]) {
  return x[0];
}

let a = 함수([4,2])
console.log(a + 1) 

// 위에서 a 가 4가 나왔기 때문에 문제 없을거라 생각할수 있지만 타입이 unknown이기 때문에 에러 발생

function 함수<MyType>(x: MyType[]) :MyType {
  return x[0];
}

let a = 함수<number>([4,2])
let b = 함수<string>(['kim', 'park'])
//function에서 MyType을 파라미터로 받아서 원하는 부분에 타입지정이 가능


function 함수<MyType>(x: MyType) {
  return x - 1
}

let a = 함수<number>(100)
// 위에 코드에서 MyType에 number가 아닌 다른 타입이 들어올 수 있기 때문에 에러가 발생함 => 파라미터로 들어오는 타입도 제한이 가능


function 함수<MyType extends number>(x: MyType) {
  return x - 1
}

let a = 함수<number>(100) //잘됩니다
//extends로 타입을 제한해서 number만 받아오기 때문에 에러가 발생하지 않음.


function 함수<MyType>(x: MyType) {
  return x.length
}

let a = 함수<string>('hello')
// 에러 발생

interface lengthCheck {
  length : number
}
function 함수<MyType extends lengthCheck>(x: MyType) {
  return x.length
}

let a = 함수<string>('hello')  //가능
let a = 함수<number>(1234) //에러남
// custom type으로 해결 가능
```





## react-typescript

* jsx

```react
let 박스 :JSX.Element = <div></div>
let 버튼 :JSX.Element = <button></button>
```

* component

```react
type AppProps = {
  name: string;
}; 

function App (props: AppProps) :JSX.Element {
  return (
    <div>{message}</div>
  )
}
```

* useState

> 알아서 타입 지정되지만, union으로 하고 싶으면 Generic문법

```react
 const [user, setUser] = useState<string | null>('kim');
```





## redux

```react
import { Provider } from 'react-redux';
import { createStore } from 'redux';

interface Counter {
  count : number
}

const 초기값 :Counter  = { count: 0 };

function reducer(state = 초기값, action :any) {
  if (action.type === '증가') {
    return { count : state.count + 1 }
  } else if (action.type === '감소'){
    return { count : state.count - 1 }
  } else {
    return initialState
  }
}

const store = createStore(reducer);

// store의 타입 미리 export 해두기 
export type RootState = ReturnType<typeof store.getState>

ReactDOM.render(
  <React.StrictMode>
    <Provider store={store}>
      <App />
    </Provider>
  </React.StrictMode>,
  document.getElementById('root')
) 
```























