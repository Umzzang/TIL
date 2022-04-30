# django 끝

문제 없이 스스로 모델링하기 너무 어렵다.





gitignore 만들기

 gitignore.io 사이트 들어가서 

windows django database venv 하면 알아서 다만들어줌





**static vs media**

static : 개발자가 준비해두는 파일



media : 이용자가 업로드하는 파일 

root
  파일의 저장 경로를 설정
  os.path.join(BASE_DIR,"media")

url
  저장 경로의 url 지정 
  "/media/"


  venv 폴더 위치 변경했더는 pip list 내용이 다바뀜

### 이미지는 POST로 받는 것이 아니라 FILES로 받아야 된다.... 하루를 버렸네

### media 폴더는 app 별로가 아니라 프로젝트 단위로 관리하는 듯 


AuthenticationForm 은 모델폼이 아니라 그냥 폼이기 때문에 request 넣어주어야함!!!!!



form.get_user() => 반드시 is_valid()를 통과해야 원하는 값이 나옴

def get_user(self):
     return self.user_cache

캐시값을 반환하는데 캐시값은 clean 으로부터 오고, clean은 valid를 통과해야 생성됨.

즉, None 에서 valid를 통과하는 순간 user 값을 갖고옴


passwordchangeform  = > request.user 가 필수 ,  request.POST가 추가 


비밀번호 변경 후 바로 로그인상태로 바꾸려면 update_session_auth_hash(request, user) => 첫번째 request, 두번째 user



PasswordChangeForm 의 부모인 SetPasswordForm
    def __init__(self, user, *args, **kwargs):
        self.user = user
        super().__init__(*args, **kwargs)

  form.user 로 사용 가능 




api 랑 일반 출력 url 같이 지정하면 안되나??


through 공부 하고 


# 프로젝트 github에 올렸는데 메일을 받음 = > SECRET_KEY

settings.py => SCRET_KEY

github 에 key는 올리면 안된다~!!!

gitignore 에 django를 추가해도 secret key는 settings에 추가되서 자연스럽게 올라감.
=> 분리해줄 필요가 있음 

새로운 key 는 Django Secret Key Generator 로 생성해서 넣어줌 

```python```
# settings.py

secret_file = os.path.join(BASE_DIR, 'secrets.json')

with open(secret_file) as f:
    secrets = json.loads(f.read())

def get_secret(setting, secrets=secrets):
    try:
        return secrets[setting]
    except KeyError:
        error_msg = "Set the {} environment variable".format(setting)
        raise ImproperlyConfigured(error_msg)

SECRET_KEY = get_secret("SECRET_KEY")


