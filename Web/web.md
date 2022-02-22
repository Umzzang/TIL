# HTML - Hyper Text Markup Language

* 하이퍼링크를 통해 사용자가 한 문서에서 다른 문서로 즉지 접근할 수 있는 텍스트

* 구글 효과 : 정보 기억이 아닌 정보 저장 장소 기억

  

익스플로러는 브라우저가 아니다!!

```markdown
Visual Studio Code 를 통하여 코드 작성 가능
* Open in Browser
* Auto rename tag
* Highlight Matching Tag
```



## 구조

* html : 문서의 최상위(root) 요소

* head : 문서 메타데이터 요소     * 메타데이터 : 데이터를 위한 데이터 ex) 사진의 위치 시간 정보 등

   ex) 문서 제목, 인코딩, 스타일, 외부 파일 로딩 등

* body : 문서 본문 요소 - 실제 화면 구성과 관련된 내용



### head

* <title>

  </title>

* meta : 문서 레벨 메타데이터 요소

  다른 메타데이터 요소로 나타낼 수 없는 것을 나타냄

  속성 : charset: 인코딩 선언 등등

* link : 외부 리소스 연결 요소

* script : 스크립트 요소

* style : css



### DOM(Document Object Model) 트리

텍스트 파일인 HTML 문서를 브라우저에서 렌더링 하기 위한 구조



### 요소

요소는 태그와 내용(contents)로 구성되어 있음

```html
<h1>
    contents
</h1>
```

* 내용 없는 태그들

  img, input, link, meta, br, hr

** html 문서는 오류를 반환하는 것이 아닌 그냥 레이아웃이 깨진 상태로 출력하기 때문에, 디버깅이 힘듬



### 속성

태그별로 사용할 수 있는 속성은 다르다.

ex) a 태그에서 href 속성 사용

* 속성을 통하여 부가적인 정보 설정
* 요소의 시작 태그에 작성
*  태그와 상관없이 사용 가능한 속성들도 있음  (HTML Global Attribute)



### HTML Global Attribute

* id : 문서 전체에서 유일한 고유 식별자 지정
* class : 공백으로 구분된 해당 요소의 클래스의 목록
* data-* : 페이지에 개인 사용자 정의 데이터를 저장하기 위해 사용
* style : inline 스타일
* title : 요소에 대한 추가 정보 지정
* tabindex : 요소의 탭 순서 - tab 키를 이용한 순서 지정



### 시맨틱 태그

HTML5에서 의미론적 요소를 담은 태그 - div 태그를 대체하여 사용

목록

* header : 머리말 부분
* nav : 내비게이션
* aside : 사이드에 위치한 공간
* section : 문서의 일반적인 구분, 컨텐츠의 그룹
* article : 문서, 페이지, 사이트 안에서 독립적으로 구분되는 영역
* footer : 마지막 부분

** div span 등은 Non semantic        h1, table 태그들도 시맨틱 태그로 볼 수 있다.

-> 코드의 가독성을 높이고 유지보수가 쉬움. 검색엔진최적화, 구역을 나누며 의미 부여



### 텍스트 요소

<a> : href 속성 이용 URL 연결

<b> : 굵은 글씨 강조

<i> : 기울임 글씨

<br>: 줄바꿈

<img> : src속성을 활용하여 이미지 표현

<span>: 의미 없는 인라인 컨테이너



### 그룹 컨텐츠

<p>:paragraph - 하나의 문단</p>

<hr>

```html
<ol>
    순서
</ol>
<ol>
    있는
</ol>
```

ul : 순서 없는 리스트

div : 의미 없는 블록 레벨 컨테이너

blockquote : 들여쓰기 한것으로 표현



### table

thead

​	tr

​		th



tbody

​	tr

​		td

tfoot



### form

정보를 서버에 제출하기 위한 영역

속성 - action: form을 처리할 서버의 URL   method   enctype



### input 

다양한 타입을 가지는 입력 데이터 유형과 위젯

속성 - type: 입력값 종류                     ex) text, password, email, number, file, checkbox, radio

​			name : form에 적용되는 이름  

​           value:form 에 적용되는 값  

​           required autofocus 등등



** label 의 for 속성과 input의 id 속성을 일치시켜 상화연관시킬 수 있음





# CSS

스타일을 지정하기 위한 언어

```css
h1{
    color:blue;
    font-size: 15px;
}
```



css 정의 방법 : 1 인라인  2 내부 참조  3  외부참조



**외부참조가 가장 많이 쓰인다.



개발자 도구

styles : 해당 요소에 선언된 모든 CSS

computed : 해당 요소에 최종 계산된 CSS





### CSS 적용 우선순위

1. !important
2. 인라인 > id > class, 속성, pseudo-class > 요소, pseudo-element
3. CSS 파일 로딩 순서



### CSS 상속

CSS는 상속을 통해 부모 요소의 속성을 자식에게 상속한다.

* 상속 되는것 : font, clor, text-align, visibilty 등

* 상속 되지 않는 것 : Box model 관련 (width, height, padding 등)           

  ​                                 position 관련 (position, z-index)





* px

* %

* em  :  바로 위 부모의 상속 영향 받음

* rem  : 최상위 요소(html)의 사이즈를 기준으로 배수 단위 1rem = 16px?
* viewport : 디바이스에 따라 상대적인 사이즈가 결정됨.\



### 색상 단위

* RGB
* HSL
* 색상 키워드





### 결합자

* 자손 : 하위 모든 요소                           div span
* 자식 : 바로 아래 요소                          div > span
* 일반 형제 : 형제 요소 중 뒤쪽 위치           p ~ span
* 인접 형제 : 형제 요소 중 바로 뒤쪽 위치      p + span



### CSS 원칙

모든 요소는 박스모델

위에서 아래로   왼에서 오른으로

* content (내용)
* padding (테두리 안쪽의 내부 여백, 배경색, 이미지는 padding 까지)
* border (테두리)
* margin (테두리 바깥 외부 여백) 배경색 지정 x



Q. 보라색 width : 100px 로 해도

  padding 값    border 값에 따라서 눈에 보이는 너비는 다를 수 있음
	box-sizing 은 content-box로



### display

display : box

display : inline

블록에서 너비 줄이면 마진값 자동적으로 부여

* 블록 요소 : div, ul ol li, p ,hr, form

* 인라인 요소 : a, img, input, label, span, b em i strong

    

  

  Q . margin-left:auto;

  ​    ->   오른쪽 정렬

  

  Q. display : none   vs visibility:hiiden

  none 은 공간조차 부여 x             hidden은 공간 차지함

  

  

### CSS position

* static

* relative - normal flow 유지

* absolute - normal flow 벗어남       static이 아닌 가장 가가이 있는 부모/조상 요소를 기준으로 이동(없으면 body)

* fixed - viewport 기준으로 이동- 스크롤시에도 항상 같은 곳 위치

  



# CSS layout



## Float

박스를 왼쪽 혹은 오른쪽으로 이동시켜 인라인요소들이 주변을 wrapping 하도록



** 요소가 Normal flow를 벗어남



### 속성

* none: 기본값

* left : 왼쪽으로

* right : 오른쪽으로



float 2개 하면 겹치는가??  no

빨간 박스 float 시키고 파란박스 길게 만들면 빨간박스 아래로 들어가서 파란박스 작아보임



글자는 아래로 안들어가고 글자 없는 박스는 들어간다.

### ::after

클래스의 자손 클래스들에게 속성 부여

Q. clearfix::after  할 때content="" 하는 이유???

-> 컨텐트가 없으면 높이가 0으로 되기 때문에 컨텐트를 빈칸으로 하고 높이 생성



float -> flexbox -> grid

float 은 왼쪽 오른쪽 만지정

​              값 부여 없이 수직 정렬 힘듬

​              아이템의 너비와 높이 혹은 간격을 동일하게 배치 힘듬

flexbox는 한 축으로 지정 가능

grid 는 두 축으로 더 자유롭게 선택 가능





## Flexible box

main 축

cross 축 으로 구성



Container 과 item 으로 구성

* flex-direction : row  or    column->
* felx-wrap : nowrap  or   wrap    or wrap-revers
* justify-content : center  or   start   or   end  or  space-between   or  space-around   -  main axis 에서 정렬
* align-content : center  or   end    or    start    - cross axis 에서 정렬
* order :  1 or -1 or 0  -   기본값은 0이다  코드에 상관없이 order값이 작은 것 먼저 배치

* flex-flow: row nowrap;   - flex-direction 과 flex-wrap을 같이 쓰는 속성
* flex-start    flex-end     center    space-between    space-around    space-evenly - 간격을 균일하게 분배
* baseline - 텍스트 baseline에 기준선을 맞춤,  stretch  - 컨테이너를 가득 채움
* flex-grow  : 남은 영역을 아이템에 분배

Q. order -1   

​     order 지정 x

​     order 1                    순서가 어떻게 될까?

 

Q. align-content   vs   align-items

content 는 라인을 정렬     items 는 아이템을 정렬

즉, nowrap 인 경우는  allign-content가 소용이 없다. (라인이 하나기 때문에)



Q. flex-flow 는 어떤 속성들의 값을 부여하는건가?



Q. space-between 과 space-evenly 의 차이점?

between 은 아티메 사이 간격 균일          evenly 는 전체 영역 간격 균일





## Grid system

Container 안에 row 와 column

12개의 column 과 6개의 grid breakpoints



Q. ? 개의 column 과 ? 개의 grid breakpoints 로 이루어져 있다.

​    ? 안의 값은?











