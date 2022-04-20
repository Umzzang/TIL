# REST API

## HTTP



### HTTP request methods

* GET
* HEAD
* POST
* PUT
* DELETE
* CONNECT
* OPTIONS
* TRACE
* PATCH



### HTTP response status

* Informational responses
* Successful 
* Redirection messages
* Client error
* Server error



### URL vs URN

* URL(Uniform Resource Locator)
  * 통합 자원 위치
  * 웹 주소, 링크
* URN(Uniform Resource Name)
  * 통합 자원 이름
  * URL 과 달리 자원의 위치에 영향을 받지않는 유일한 이름 역할
  * ex) ISBN(국제표준도서번호)



### URI (Uniform Resource Identifier)

> 통합 자원 식별자
>
> 인터넷의 자원을 식별하는 유일한 주소
>
> URL과 URN이 하위 개념이지만, URN 사용 비중이 매우 적어 URL로 같은 의미로 사용됨.

```
https://www.example.com:80/path/to/myfile.html/?key=value#quick-startk
```



* Scheme(protocol)
  * http(s), data, file, ftp, mailto
  *  **https://**
* Host(Domain name)
  * 웹 서버의 이름 (naver, google)
  * IP address를 편히 사용하기 위해
  *  **www.example.com**

* Port
  * 웹 서버 상의 리소스에 접근하는데 사용되는 gate
  * HTTP 80, HTTPS 443
  * :80
* Path
  * 웹 서버 상의 리소스 경로
  * 과거에는 실제 파일 위치 경로, 오늘날은 추상화 형태의 구조
  * path/to/myfile.html
* Query
  * 추가적인 매개 변수
  * &로 구분되는 key-value 목록
  * ?key=value
* Fragment
  * 자원 안의 북마크
  * 브라우저에게 해당 문서의 특정 부분을 보내주기 위한 방법
  * ex) 부트스트랩 문서 or 장고 문서
  * '#' 뒤의 부분은 요청이 서버에 보내지지 않음
  * #quick-start



## RESTful API



### API

> Application Programming Interface
>
> 애플리캐이션과 프로그래밍으로 소통하는 방법
>
> CLI는 명령줄, GUI 는 그래픽(아이콘), API 는 프로그래밍을 통해 기능 수행



### REST

> REpresentational State Transfer

* 소프트웨어 설계 방법론
* 자원을 정의하는 방법에 대한 고민

| 자원 | 행위        | 표현 |
| ---- | ----------- | ---- |
| URI  | HTTP Method | JSON |



### Microservice Architecture vs Monolithic Architecture

![Monolithic Architecture versus Microservices Architecture. (image taken...  | Download Scientific Diagram](https://www.researchgate.net/profile/Anna-Rozeva/publication/337245580/figure/fig1/AS:837788945625095@1576755858555/Monolithic-Architecture-versus-Microservices-Architecture-image-taken-from.png)

* 기능이 늘어나면 한번에 관리하는 것보다 각 각 관리하는것. => 그래서 json 으로 넘겨주고 선택적으로 출력
* 결국 장고는 백앤드만, html 은 프론트앤드에서, => return, redirect 사용 안하게 됨. 



## Response

### django-seed

> 테스트를 위해 임의로 테스트데이터를 생성해줌.

```bash
$ pip install django-seed==0.3.1
```

```python
# project/settings.py
INSTALLED_APPS=[
    'django_seed',
]
```

```bash
$ python manage.py migrate
$ python manage.py seed app_name --number=원하는데이터갯수
```



### url

```python
# project/urls.py

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/v1/', include('articles.urls')),
]
```

```
=> api/v1 : 자주쓰는 url 패턴
```

```python
# app/urls.py

urlpatterns = [
    path('html/', views.article_html),
    path('json-1/', views.article_json_1),
    path('json-2/', views.article_json_2),
    path('json-3/', views.article_json_3),
]
```

?? - redirect 할필요가없어서 url name 지정안하나??



### Response -HTML

> render, redirect 사용
>
> templates 폴더 안에 html 파일 만들어서 진행



### Response - JsonResponse

> HttpResponse 를 상속받음.
>
> 인자가 딕셔너리가 아니면 safe=False 필요 
>
> safe default값 True

```python
# django/http/response/JsonResponse
class JsonResponse(HttpResponse):    
    def __init__(
        self,
        data,
        encoder=DjangoJSONEncoder,
        safe=True,
        json_dumps_params=None,
        **kwargs,
    ):
        if safe and not isinstance(data, dict):
            raise TypeError(
                "In order to allow non-dict objects to be serialized set the "
                "safe parameter to False."
            )
        if json_dumps_params is None:
            json_dumps_params = {}
        kwargs.setdefault("content_type", "application/json")
        data = json.dumps(data, cls=encoder, **json_dumps_params)
        super().__init__(content=data, **kwargs)
```



```python
# app/views.py

from django.http.response import JsonResponse

def article_json_1(request):
    articles = Article.objects.all()
    articles_json = []

    for article in articles:
        articles_json.append(
            {
                'id': article.pk,
                'title': article.title,
                'content': article.content,
                'created_at': article.created_at,
                'updated_at': article.updated_at,
            }
        )
    return JsonResponse(articles_json, safe=False)
```



### Serialization

> 데이터 구조나 객체 상태를 재구성할 수 있는 포맷으로 변환하는 과정



### Response - Django Serializer

> 주어진 모델 정보를 활용하기 때문에 필드 개별적으로 만들 필요 없음.

```python
from django.http.response import HttpResponse
from django.core import serializers

def article_json_2(request):
    articles = Article.objects.all()
    data = serializers.serialize('json', articles)
    return HttpResponse(data, content_type='application/json')
```



### Response - Django REST Framework

>An HttpResponse that allows its data to be rendered into arbitrary media types.
>
>        Alters the init arguments slightly.
>        For example, drop 'template_name', and instead use 'data'.
>        Setting 'renderer' and 'media_type' will typically be deferred,
>        For example being set automatically by the `APIView`.

```bash
$ pip install djangorestframework
```

```python
class Response(SimpleTemplateResponse):
   

    def __init__(self, data=None, status=None,
                 template_name=None, headers=None,
                 exception=False, content_type=None):
     
        super().__init__(None, status=status)

        if isinstance(data, Serializer):
            msg = (
                'You passed a Serializer instance as data, but '
                'probably meant to pass serialized `.data` or '
                '`.error`. representation.'
            )
            raise AssertionError(msg)

        self.data = data
        self.template_name = template_name
        self.exception = exception
        self.content_type = content_type
```



```python
# project/settings.py
INSTALLED_APPS = [
    'rest_framework',
]
```

```python
# app/serializers.py

from rest_framework import serializers
from .models import Article

class ArticleSerializer(serializers.ModelSerializer):

    class Meta:
        model = Article
        fields = '__all__'
```

```
모델폼과 거의 유사함.
```



```python
# app/views.py

from rest_framework.decorators import api_view
from rest_framework.response import Response
from .serializers import ArticleSerializer

# @api_view(['GET'])
@api_view()
def article_json_3(request):
    articles = Article.objects.all()
    serializer = ArticleSerializer(articles, many=True)
    return Response(serializer.data)
```



### ModelSerializer

> 모델폼과 비슷한 형식. 모델에 있는 class를 쉽게 serialize할 수 있는 shortcut
>
> 모델 정보에 맞게 자동 필드 생성
>
> 유효성 검사
>
> .create() & .update() 의 간단한 기본 구현



### 'many' argument

> default : many=True
>
> 단일 인스턴스가 아닌 QuerySet 을 직렬화하기 위해서는 many=True



























