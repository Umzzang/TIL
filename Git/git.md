# Git

> **Version Control Systems**

1. 버전 관리

​	

2. 협업



### Github vs Git

> Github : 단순히 git을 인터넷에서 사용할 수 있게 서버를 제공해주는 서비스
>
> Git : 실제 버전 관리 시스템



### Git 의 차별성

> Git은 데이터를 파일로 처리x
>
> 파일 시스템의 스냅샷의 연속으로 취급
>
> 이전 상태의 파일에 대한 링크만 저장하기 때문에 크기가 작음

### 스냅샷 : 스**냅샷**은 마치 사진 찍듯이 특정 시점에 스토리지의 파일 시스템을 포착해 보관하는 기술



### Git 상태

![image-20220309150223500](git.assets/image-20220309150223500.png)

* Modified : 파일이 수정중인 상태. local에서의 변화
* Staged : commit이 되기 이전 상태.
* Committed : 수정사항들이 local git환경에 저장되있는 상태.



### add 와 commit 을 나눠놓은 이유 

### * commit 시기를 놓쳤을 때 원하는 파일만 commit하기 위해 *







### branch & merge



![git-branches-merge](git.assets/git-branches-merge.png)







## Git 설치

1. git-scm.com 

![image-20220309130233420](git.assets/image-20220309130233420.png)



2. Download for WIndows





## 명령어

* pwd : 위치 알려줌
* cd
* ls -al : 현재 파일 정보
* cp : copy
* cat



## git  명령어 -> https://git-scm.com/docs/git

* git init
* git status
* git add
* git config
* git status
* git log
* git diff
* git reset
* git revert
* git branch
* git stash
* git switch
* git restore





## git help

```bash
$ git 명령어 --help  ==> 명령어에 대한 옵션등 다양한 정보 나옴.
```



## git init

> Create an empty Git repository or reinitialize an existing one
>
> local 저장소로 설정

* .git 생성



## git add

> git이 track할 파일을 추가하는 명령어.

```bash
$ git add 파일명

```





## git config

> Get and set repository or global options
>
>



## git log

* git log
* git log -p : commit과 commit 사이의 source 차이를 확인 가능
  * -가 이전버전
  * +가 이후 버전
* git log --oneline
* git log --oneline --all



## git diff

* git diff commit1주소 .. commit2주소 => commit1과 commit2의 차이를 알려줌





## git reset vs git revert

```bash
$ git reset commit주소 --hard  => commit주소의 상태로 돌아감 (이후의 버전을 지운것은 아니다.)
						
```



## ##reset은 local에서만 !!! push한 폴더에서는 reset 금지!!!##



```bash
revert는 commit을 취소하면서 새로운 버전 형성
```



## Gistory

```bash
$ pip install gistory

$ cd .git

$ gistory


## add 할 때마다 index 와 objects가 변함.
=> git은 파일을 저장하는 것이 아니라 주소를 저장한다.

## commit을 하면 objects 안에 commit 한 사람의 정보(config)가 들어간다.

## status 는 objects와 실제 파일을 비교해서 알려줌.
```





## branch

> 새로운 가지를 만드는 과정

* git 의 branch 기능은 다른 서버관리툴보다 가볍고, 쓰기 편하다.



* `git branch` : 목록
* `git branch 브랜치이름` : 생성
* `git branch -d 브랜치이름` : 삭제
* `git branch -D 브랜치이름` : 합병 없어도 삭제
* `git switch 브랜치이름` : 이동
* `git switch -c 브랜치이름` : 생성 후 이동 



### branch 만들기

```bash
a.txt
b.txt

$ git branch
* master

$ git branch exp
 exp
* master

$ git checkout exp
Switched to branch 'exp'

$ git branch
* exp
  master
=> branch가 exp로 바뀜  master와 exp가 같은 상태

a.txt 수정

$ git add a.txt

$ git commit -m '3'

$ git log  ---------- 1

$ git checkout master

$ git log   --------- 2

1 과 2의 로그 상태는 '3'의 유무로 다르다
폴더 내 파일 상태도 다르다.



```



### branch 정보확인

```bash
$ git log -- branches
```

```bash
=> checkout이 아닌 branch 들의 로그를 보여줌
```





```bash
$ git log --branches --decorate --graph
```

![image-20220309231847130](git.assets/image-20220309231847130.png)



```bash
$ git log --branches --decorate --graph --oneline
```

![image-20220309231953061](git.assets/image-20220309231953061.png)



```bash
$ git log master..exp
=> master 에는 없고 exp 에만 있는 로그를 보여줌

$ git log exp..master
=> exp에는 없고 master에만 있는 로그를 보여줌

$ git diff master..exp
=> -가 master + 가 exp
```

![image-20220309232524441](git.assets/image-20220309232524441.png)



### branch merge

* exp  => master 하려면 일단 checkout master

```bash
$ git merge exp
```

![image-20220309233212450](git.assets/image-20220309233212450.png)



```bash
$ git log --branches --decorate --graph --oneline
```

![image-20220309233238816](git.assets/image-20220309233238816.png)



=> master는 1 2 5 3 log 를 다 갖고 있다.

   exp는 1 2 3 을 갖고 있다.

```bash
$ git checkout exp
$ git merge master
$ git log --branches --decorate --graph --oneline
```

![image-20220309234048938](git.assets/image-20220309234048938.png)



```bash
$ git checkout master
$ git branch -d exp  # exp 브랜치 삭제
$ git log --branches --decorate --graph --oneline
```

![image-20220309234225408](git.assets/image-20220309234225408.png)







### git stash

> 숨겨놓는(?) 감추다(?)
>
> branch 작업 안끝남 -> 다른 branch 가야 할 상황이 생김ㅁ
>
> commit하기도 애매하고 그럴 때 stash로 잠깐 숨겨놓는다.

master branch 에서 작업하던 것을 commit 하지 않고 

exp branch로 넘어왔을 때 master 수정본이 문제가 됨.

=> stash로 숨겨주면 됨



```bash
$ git stash => 숨겨줌

$ git stash apply => 숨겨준거 다시 보여줌

$ git stash drop => list에 있는 최신 stash 제거

$ git stash apply ; git stash drop => 동시에 적용 = $ git stash pop
```





