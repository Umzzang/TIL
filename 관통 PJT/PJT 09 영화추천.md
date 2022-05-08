# PJT 09



## 영화 추천

```python
# movies/views.py

@require_safe
def recommended(request, movie_pk):#87
    movie = get_object_or_404(Movie, pk=movie_pk)  # movie 객체
    movies = get_list_or_404(Movie)
    # movie_id, 구했음
    # movie_id => genre_id, 구함
    genre_pk = movie.genres.all()       # 87 번 영화의 모든 장르 pk
    new_movies = []
    recommend_movies=[]
    for i in genre_pk:      #i.pk 가 87번 영화의 장르 pk
        new_movies.append(i.pk)         
        genre = get_object_or_404(Genre, pk=i.pk)       # 각 장르의 객체
        genres = genre.movies.all()     # 그 장르 pk를 갖는 영화
        genre_name = Genre.objects.filter(pk=i.pk).values('name')
        for m in movies:
            m_genres = m.genres.all()
            if len(m_genres.filter(pk=i.pk)) > 0:
                m_genres_movie = m_genres.filter(pk=i.pk).values('movies')
                print(m_genres_movie)
                m_genres_movie[0]['movies']
                recommend_movies.append(movies[m_genres_movie[0]['movies']-1].title)
        
    
    # for recommended_movie in recommend_movies:
    #     print(recommended_movie)
    #     recommended_movie[0]['movies']
    #     recommend_movies = movies[recommended_movie[0]['movies']-1].title
        # recommended_movies = Movie.objects.filter(genres.id==i.pk).values('title')
        # 
        
    # genre_id => genre_name, 구함
    genres = get_list_or_404(Genre)
    context = {
        'recommend_movies' : recommend_movies
        }    
    return render(request, 'movies/recommended.html', context)
```



```python
# detail movie의 pk 를 받아옴
@require_safe
def recommended(request, movie_pk):  
    movie = get_object_or_404(Movie, pk=movie_pk)
    print(movie)
    print(movie.title)
    print(movie.genres)
    print(type(movie.genres))

```

```
Movie object (99)				
드래곤 길들이기: 홈커밍
movies.Genre.None
<class 'django.db.models.fields.related_descriptors.create_forward_many_to_many_manager.<locals>.ManyRelatedManager'>

```

```
movie는 Movie 클래스의 객체(object) ==> movie.objects는 사용 할 수 없음
movie.title 은 잘 나오는데 genres는 None으로 나옴 => 하나의 값이 아니기 때문
```

### movie의 genre 하나만 뽑아 내기

```python
# for
for genre in movie_genres:
    print(genre)
    
# all()
print(movie.genres.all())

# .values().all()
movie_genres = movie.genres.values('pk').all()
print(movie_genres)

```

```py
# for
TypeError: 'ManyRelatedManager' object is not iterable
 => 순회 불가능
 
 # all()
 <QuerySet [<Genre: Genre object (12)>, <Genre: Genre object (14)>, <Genre: Genre object (16)>, <Genre: Genre object (28)>, <Genre: Genre object (10751)>]>
  => 장르도 클래스로 정의되어 있고 여러개의 장르가 나오기 때문에 쿼리셋으로 출력
  => movie.title 의 type 은 그냥 str
  
  # .values().all()
  <QuerySet [{'pk': 12}, {'pk': 14}, {'pk': 16}, {'pk': 28}, {'pk': 10751}]>
```



###  movie 의 genre 객체에서 pk 만뽑아 내기

* object로 

```python
movie_genres = movie.genres.all()
for genre in movie_genres:
    # print(genre['pk'])
    # print(genre['name'])
    print(genre)
    print(genre.name)
    print(genre.pk)
```

```
movie_genres 는 장르 오브젝트들을 갖고 있는 쿼리셋, 즉 genre는 Genre object
주석 처럼 접근하면 TypeError: 'Genre' object is not subscriptable
.dot 으로 접근 가능
```

* dict로

```python
movie_genres = movie.genres.values('pk','name').all()
for genre in movie_genres:
    print(genre['pk'])
    print(genre['name'])
```

```
.values() 사용시 movie_genres 는 딕셔너리로 이루어진 쿼리셋
즉, genre 는 딕셔너리 하나
.dot으로 접근 불가능
key값으로 접근
```



### movie의 genre와 같은 genre를 갖는 다른 movie 찾기

```python
# value 사용 => dict
movie_genres = movie.genres.values('pk','name').all()
new_movies = []
for genre in movie_genres:
    genre_ob = get_object_or_404(Genre, pk=genre['pk'])

    for new in genre_ob.movies.all():
        new_movies.append(new.title)
        
# value 없이 ==> object

movie_genres = movie.genres.all()
new_movies = []
for genre in movie_genres:
    for new in genre.movies.all():
        new_movies.append(new.title)
    print(new_movies)
        
```



### 장르 많이 겹치는 순서로 정렬

```python
movie_genres = movie.genres.all()
new_movies = {}
for genre in movie_genres:
    for new in genre.movies.all():
        if new.title in new_movies:
            new_movies[new.title] += 1
        else:
            new_movies[new.title] = 1
new_movies.pop(f'{movie.title}')	# 원래 영화 제거
new_movies = dict(sorted(new_movies.items(), key = lambda x: x[1], reverse=True)) # value로 sort
```



```
이런식으로 하면 영화 제목만 context로 보내기 때문에 html 에서 할 수 있는 것이 한정적
```





#### views.py 에서 title만 넘기는 것이 아니라 객체를 넘겨야 함

```python
# views.py
@require_safe
def recommended(request, movie_pk):  # detail movie의 pk 를 받아옴
    movie = get_object_or_404(Movie, pk=movie_pk)
    
    movie_genres = movie.genres.all()
    new_movies = {}
    for genre in movie_genres:
        for new in genre.movies.all():
            if new in new_movies:
                new_movies[new] += 1
            else:
                new_movies[new] = 1
    
    new_movies.pop(movie)
    new_movies = dict(sorted(new_movies.items(), key = lambda x: x[1], reverse=True))
    
    movies_title = []
    
    for title in new_movies:
        movies_title.append(title)
    
    context = {
        'movies_title' : movies_title
    }
    return render(request, 'movies/recommended.html', context)
```

```
객체로 넘기고 조작은 html 에서 dtl 로
```



