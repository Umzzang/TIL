# Authentication System

* django.contrib.auth : 인증 프레임워크 핵심
* django.contrib.contenttypes : 모델과 권한 연결



* Authentication(인증)
  * 신원 확인
  * 사용자가 자신이 누구인지 확인하는 것
* Authorization (권환, 허가)
  * 권한 부여
  * 인증된 사용자가 수행할 수 있는 작업을 결정



### 인증시스템은 두번째 앱을 통하여 관리함.

```bash
$ python manage.py startapp accounts
```

=> django내부적으로 accounts라는 이름을 사용하고 있기 때문에 accounts로 지정하는 것을 권장.





## 쿠키와 세션

> 클라이언트와 서버의 지속적인 관계를 유지하기 위해 쿠키와 세션이 존재



### HTTP(Hyper Text Transfer Protocol)

> HTML 문서와 같은 리소스들을 가져올 수 있도록 해주는 프로토콜

* 비연결지향

​	: 서버는 요청에 대한 응답을 보낸 후 연결끊음. => 연결되어 있는 것처럼 보임.

* 무상태

​	: 연결을 끊는 순간 클라이언트와 서버 간의 통신이 끝나고 상태 정보(ex)로그인)가 유지되지 않음.



### 쿠키

> 서버가 사용자의 웹 브라우저에 전송하는 작은 데이터 조각
>
> 클라이언트는 쿠키를 로컬에 KEY-VALUE의 데이터 형식으로 저장 후
>
> 동일한 서버에 재 요청 시 저장된 쿠키를 함께 전송

* 로그인 상태 유지시켜줌(매 요청마다 쿠키를 함께 서버에 보냄)



1. 세션 관리

   : 로그인, 아이디 자동 완성, 공지 7일동안 안보기, 장바구니, 팝업 체크 등

2. 개인화

   : 사용자 선호, 테마 등의 설정

3. 트래킹

   : 사용자 행동을 기록 및 분석 => 내가 흥미있는 것을 광고로 보여줌



**장바구니 페이지 - 검사 - network - cartView.pang - Headers - Set-cookie - Cookies**



### **쿠키 lifetime**

* Session cookies
  * 현재 세션 종료되면 삭제됨. - 삭제 시기는 브라우저 설정에 따라 다름
* Persistent cookies
  * Expires 속성에 지정된 날짜 혹은 Max-age 속성에 지정된 기간이 지나면 삭제됨.



?? - 쿠키는 여러 서버에서 공유가 되나?

?? - 세션 종료라는 것은 브라우저를 전부 종료해야 하는건가?? - 세션 설정값에 따라 다름

?? - super()설명 필

인터넷 사용하다보면 여러 홈페이지에서 제가 관심있는 분야의 광고가 나오는데 쿠키는 여러 서버에서 공유가 되는건가요?

=> 



### 세션

> 사이트와 특정 브라우저 사이의 '상태'를 유지시키는 것

클라이언트  -> 서버 접속  ->  서버가 session id를 발급  ->  클라이언트는 발급 받은 id를 쿠키에 저장

id는 세션을 구별하기 위해 필요하며, 쿠키에는 id만 저장함.

세션은 서버와 브라우저간의 데이터 주고받는 형태이기 때문에 사용자가 많아지면 서버 과부화



### 세션 vs 쿠키

쿠키의 경우 브라우저에 키와 밸류 저장됨

세션(로그인)의 경우 서버에 밸류값이 저장되고 클라이언트는 키값만 갖게 됨



## 로그인

> 로그인은 session을 생성하는 로직과 같음.
>
> django는 인증에 관한 built-in forms 제공



### AuthenticationForm

> 사용자 로그인을 위한 form
>
> request를 첫 번째 인자로 취함.

* ModelForm 이 아니라 Form의 상속을 받음. => DB에 저장되는 것이 아니기 때문에 form

* 로그인 인증 절차만 할 뿐, 실제 로그인을 해주지는 않는다 => login함수로

* login 함수

  login(request, user, backend=None)

  인증된 사용자가 있는 경우 login()함수 필요

  

```python
# views.py
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import import login as auth_login
def login(request):
    if request.method == 'POST':
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            #로그인ㄹ
            auth_login(request, form.get_user())
            return redirect('articles:index')
            
    else:
        form = AuthenticationForm()
    context = {
        'form' : form,
    }
    return render(request, 'accounts/login.html', context)
```



### Authentication data in templates

> context로 넘겨주지 않아도 django template에서 알아서 인식함.

* context processors
  * settings.py  TEMPLATES를 보면 자동으로 호출 가능한 context 데이터 목록
* Users
  * 로그인한 사용자를 나타내는 auth.User 인스턴스는 {{user}}에 저장됨
  * 비로그인자 AnonymousUser



## 로그아웃(세션 삭제)

> session을 Delete하는 간단한 로직



### logout 함수

* logout(request)
  * request 인자로 받고 return은 없음
  * 사용자가 로그인을 하지 않은 경우에도 오류 발생 x
  * 클라이언트의 쿠키에서도 삭제, DB에서도 완전히 삭제



```python
# views.py
from django.contrib.auth import logout as auth_logout

def logout(request):
    auth_logout(request)
    return edirect('articles:index')
```





## 로그인 사용자에 대한 접근 권한

> 로그인시 로그아웃, 로그아웃상태시 로그인만 보이게 하기 위해



1. The raw way
   * is_authenticated. attribute(속성)
2. The login_required decorator



* is_authenticated 속성
  * 사용자가 인증 되었는지 여부를 알 수 있는 방법
  * 권한과는 관련 없으며, 인증여부만 판단 



```django
{% if request.user.is_authenticated %}	# 로그인 되어 있으면
  안녕~
  로그아웃 버튼
{% else %}			# 로그인 안되어 있으면 
  로그인 버튼
  
```



```python
def login(request):
    if request.user.is_authenticated:
        return redirect('articles:index')
```



* **login_required** decorator
  * 사용자가 로그인되어 있지 않으면, settings.LOGIN_URL에 설정된 문자열 기반 절대 경로로 redirect함.
  * 사용자가 로그인되어 있으면 정상적으로 view함수 실행
  * 인증 성공 시 사용자가 redirect 되어야 하는 경로를 next로 저장해줌









# Authentication System 2



## 회원가입



### UserCreationForm

> username 과 password로 권한이 없는 새  user를 생성하는 **ModelForm**

* username
* password1
* password2(비밀번호 재확인)  => 3개의 필드를 가짐



```python
# views.py

def signup(request):
    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        if form.is_valid():
            user = form.save()
            auth_login(request, user)
            return redirect('articles:index')
    else:
        form = UserCreationForm()
    context = {
        'form' : form
    }
    return render(request, 'accounts/signup.html', context)
```



휴면 계정 => 계정을 비활성화시킴









## 회원탈퇴

> DB에서 사용자를 삭제하는 것과 같음 => 간단



```python
# views.py

@require_POST
def delete(request):
    if request.user.is_authenticated:
        request.user.delete()
        auth_logout(request)
    return redirect('articles:index')
```



### 탈퇴를 했다고 바로 session이 지워지지 않음. => 탈퇴하면서 바로 로그아웃시켜야함.

* 지우고 로그아웃 순서로 해야함.





## 회원정보 수정



### UserChangeForm

> 사용자의 정보 및 권한을 변경하기 위해 admin 인터페이스에서 사용하는 ModelForm



```python
# views.py

from django.contrib.auth.forms import UserChangeForm

def update(request):
    if request.method=='POST':
        pass
    else:
        form = UserChangeForm(instance=request.user)
    context = {
        'form' : form
    }
    return render(request, 'accounts/update.html', context)
```



=> UserChangeForm 그대로 사용할 수 없음 . 스스로 슈퍼계정 혹은 관리자가 될 수 있어서



```python
#forms.py

from django.contrib.auth.forms import UserChangeForm
from django.contrib.auth import get_user_model

class CustomUserChangeForm(UserChangeForm):
    
    class Meta:
        model = get_user_model()
        fields = 
```





### get_user_model()



?? -  form을 갖고와서 사용하면 장고가 다 해주는 느낌이 강한데 만약 장고를 사용하지 않는 회사에 들어간다면 다른프레임워크들도 이렇게 편한지 아니면 더 어려운지 공부를 더해야하는지 그런것들도 궁금합니다.

?? - forms.py 에서 필드들 속성 변경 할때 html 에 lable 부분은 수정이 불가능한지 궁금합니다.! ex) 줄바꾸기 



## 비밀번호 변경



### PasswordChangeForm

> 사용자가 비밀번호를 변경할 수 있도록 하는 Form
>
> 이전 비밀번호를 입력하여야 변경 가능



```python
from django.contrib.auth.forms import PasswordChangeForm 
from django.contrib.auth import update_session_auth_hash

def change_password(request):
    if request.method == 'POST':
        form = PasswordChangeForm(request.user, request.Post)
        is form.is_valid():
            form.save()
            update_session_auth_hash(request, form.user)
            return redirect('articles:index')
    else:
        form = PasswordChangeForm()
    context = {
        'form':form
    }
    return render(request, 'accounts/change_password.html', context)
```





### update_session_auth_hash(request, user)

> 암호 변경 시 세션 무효화 방지
>
> 비밀번호 변경시 기존 세션과의 회원 인증정보가 일치하지 않아 로그인 상태 유지 불가 => 이를 위해 존재













