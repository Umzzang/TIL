# JavaScript

> 브라우저를 조작할 수 있는 유일한 언어
>
> 브라우저 화면을 '동적'으로



## 브라우저 (browser)

> HTML 문서, 그림, 멀티미디어 파일 등 다양한 인터넷 컨텐츠를 검색 및 열람하기 위한 프로그램

> URL 로 웹(WWW)을 탐색, 서버와 통신, HTML문서나 파일을 출력하는 GUI 기반의 소프트웨어

> Google Chrome, Mozilla Firefox, Microsoft Edge, Safri, Opera



### DOM 조작(Document Object Model) - 문서조작

> HTML, XML 과 같은 문서를 다루기 위한 프로그래밍 인터페이스

![image-20220425204119250](JavaScript.assets/image-20220425204119250.png)



* 파싱(해석)
  * 구문 분석, 해석
  * 브라우저가 문자열을 해석해 DOM Tree로 만드는 과정
* 조작
  * 구문 변경
  * ex) title 변경 



### BOM(Browser Object Model)

> 자바스크립트가 브라우저와 소통하기 위한 모델



### Java Script Core(ECMAScript)

> 브라우저(DOM&BOM)을 조작하기 위한 명령어 약속

![image-20220425204654037](JavaScript.assets/image-20220425204654037.png)



## 변수와 식별자 

### 식별자

> 자바스크립트 이름 명명할때 사용하는 단어
>
> 변수명, 함수명, 속성명, 메소드명

* 식별자는 반드시 문자, 달러($), 밑줄(_)로 시작

  * ```js
    identifier
    identifier10
    _identifier
    $identifier
    Identifier
    ```

* 키워드 x, 숫자 시작 x, 공백 x

  * ```
    break
    123identifier
    has space
    ```

* 대소문자 구분
* 클래스명 외에는 모두 소문자



### camelCase

* 변수, 객체, 함수

* ```javascript
  //변수
  let dog
  let variableName
  //객체
  const userInfo = {name:'TOM'}
  //함수
  function add() {}
  function getName() {}
  ```

  

### PascalCase

* 클래스, 생성자

* ```javascript
  //클래스
  class User {	
  }
  //생성자
  function User(){
      
  }
  ```

  

### SNAKE_CASE

* 상수(const)

* ```javascript
  //상수
  const PI = Math.PI
  const API_KEY = 'my-key'
  ```

  

### let vs const vs var

| 키워드 | 재선언 | 재할당 | 스코프      | 비고            |
| ------ | ------ | ------ | ----------- | --------------- |
| let    | X      | O      | 블록 스코프 | ES6             |
| const  | X      | X      | 블록 스코프 | ES6             |
| var    | O      | O      | 함수 스코프 | 사용하지 말 것. |



|        |                 |             |
| ------ | --------------- | ----------- |
| 선언   | 변수 생성       | let foo     |
| 할당   | 변수에 값 저장  | foo = 11    |
| 초기화 | (선언) + 재할당 | let bar = 0 |



### 블록 스코프

> if, for 등의 중괄호 내부
>
> 블록 스코프를 가지는 변수는 블록 바깥에서 접근 불가능

```javascript
let x = 1
if (x === 1) {
    let x = 2
    console.log(x) // 2
}
console.loge(x) // 1
```



### 함수스코프

> 함수 내부
>
> 함수에서 선언한 변수들은 해당 함수 내에서만 접근 가능 



### var

> 재선언 및 재할당 모두 가능 
>
> 함수 스코프

**호이스팅* 특성으로 사용 하지말자**

* 호이스팅
  * 변수를 선언 이전에 참조 가능
  * 변수 선언 이전의 위치에서 접근시 undefined => 에러가 아님 





## 데이터 타입

![image-20220425211434311](JavaScript.assets/image-20220425211434311.png)





### 원시 타입(Primitve type)

* 객체가 아닌 기본 타입
* 변수에 해당 타입의 '값'이 담김
* 다른 변수에 복사할 때 **실제 값**이 복사됨

```javascript
let message = '안녕'

let greeting = message
console.log(greeting)  // '안녕'

message = 'hello'
console.log(greeting) //'안녕'
```

* 숫자타입 (Infinity, -Infinity, -0, NaN)
* 문자열타입
* undefined
* null
* Bollean



### undefined vs null

* undefined
  * 빈 값 표현
  * 개발자의 의도가 아니라, 자동으로 할당
  * typeof 결과 undefined
* null
  * 빈 값 표현
  * 개발자가 의도적으로 할당
  * typeof 결과 object 





### 참조 타입(Reference type)

* 객체타입의 자료형
* 변수에 해당 객체의 **참조 값**이 담김
* 다른 변수에 복사할 때 **참조 값**이 복사됨

```javascript
const message = ['안녕']

const greeting = message
console.log(greeting)  // '안녕'

message[0] = 'hello'
console.log(greeting) //'hello'
```

* 함수, 배열, 객체(dict 개념)





## 연산자

* ++, -- 존재

### 동등 비교 연산자(==) vs 일치 비교 연산자(===)

```javascript
const a = 1004
const b = '1004'
console.log(a === b)  // false => 암묵적 타입 변환

console.log(a == b)  // True => 엄격한 비교 
```



* 논리 연산자
  * &&
  * ||
  * !

```java
// 단축평가
console.log(1 && 2 && 3 && 4 )   // 4

console.log(1 || 2 || 3 || 4 )   // 1
```



* 삼항 연산자

```javascript
console.log(true ? 1:2 )  //1
console.log(false ? 1:2 )  // 2
//=> ? 앞이 참이면 : 앞  ? 앞이 거짓이면 : 뒤를 출력 
```

```python
1 if True else 0  # 파이썬 이것과 비슷 
```



## 조건문

| 데이터 타입 | 거짓       | 참               |
| ----------- | ---------- | ---------------- |
| Undefined   | 항상 거짓  | x                |
| Null        | 항상 거짓  | x                |
| Number      | 0, -0, NaN | 나머지 모든 경우 |
| String      | 빈 문자열  | 나머지 모든 경우 |
| Object      | x          | 항상 참          |

=> **if [] 도 참!!!!!**



### if statement

```javascript
if (condition) {
    // do something
} else if (condition) {
    // do something
} else {
    // do something
}
```



### switch statement

```javascript
const nation = 'Korea'

switch(nation) {
    case 'Korea':{
        console.log('안녕')
        break
    }
    case 'France':{
        console.log('봉주르')
        break
    }
    default :{
        console.log('hello')
        
    }
}
```





## 반복문



### while

```javascript
let i = 0
while (i<6) {
    console.log(i)
    i += 1
}    // 0, 1, 2, 3, 4, 5
```



### for

```javascript
for (let i = 0; i<6;i++) {
    console.log(i)
}   // 0, 1, 2, 3, 4, 5
```



### for  in 

> 객체의 속성(key)들을 순회할 때 사용
>
> 배열은 순회 가능하지만 하지말자! => 키 접근이기 때문에 인덱스가 나옴 + str 취급

```javascript
const capitals = {
    korea:'seoul',
    france:'paris'
}

for (let capital in capitals) {
    console.log(capital)
}    // korea, france
```



### for of

> 반복 가능한 객체를 순회하며 값을 꺼냄 => dict 불가능

```javascript
const fruits = ['딸기', '바나나']

for (let fruit of fruits) {
    fruit = fruit + '!'
    console.log(fruit)
}   // 딸기!, 바나나!
```





















