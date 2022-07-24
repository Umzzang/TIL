## 1952. 수영장

> 12개월동안 계획에 맞게 수영장을 갈 때 가장 적게 요금을 내는 방법 => 요금 구하기
>
> 일일 이용권, 월, 분기, 년



### 접근









## 2105. 디저트 카페

>갈 수 있는 모든 루트 중에 가장 많은 디저트를 먹을 수 있는 루트를 구하는 문제 => 디저트의 수를 구하기
>
>대각선 방향으로 사각형 모양을 그리며 진행
>
>같은 종류의 디저트 접근 불가
>
>첫 카페로 복귀 해야함.



### 접근



```python
def DFS(n, ci, cj, v, cnt):
    global si, sj, ans
    if n>3: # 종료조건
        return
    if n==3 and ci==si and cj==sj and ans<cnt:  # 정답 갱신
        ans = cnt
        return
 
    for k in range(n, n+2):
        ni,nj = ci+di[k], cj+dj[k]
        if 0<=ni<N and 0<=nj<N and arr[ni][nj] not in v:
            DFS(k, ni, nj, v+[arr[ni][nj]], cnt+1)
 
di,dj = (1,1,-1,-1,1),(-1,1,1,-1,-1)
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = -1
    for si in range(N):
        for sj in range(N):
            DFS(0, si, sj, [], 0)
    print(f'#{test_case} {ans}')
    
    
    
    
def DFS(n, ci, cj, v, cnt):
    global si, sj, ans
    if n>3: # 종료조건
        return
    if n==3 and ci==si and cj==sj and ans<cnt:  # 정답 갱신
        ans = cnt
        return
 
    for k in range(n, n+2):
        ni,nj = ci+di[k], cj+dj[k]
        if 0<=ni<N and 0<=nj<N and arr[ni][nj] not in v:
            DFS(k, ni, nj, v+[arr[ni][nj]], cnt+1)
 
di,dj = (1,1,-1,-1,1),(-1,1,1,-1,-1)
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = -1
    for si in range(0, N-2):
        for sj in range(1,N-1):
            DFS(0, si, sj, [], 0)
    print(f'#{test_case} {ans}')
    
    
    
    
    
def DFS(n, ci, cj, v, cnt):
    global si, sj, ans
    if n>3: # 종료조건
        return
    if n==3 and ci==si and cj==sj and ans<cnt:  # 정답 갱신
        ans = cnt
        return
 
    for k in range(n, n+2):
        ni,nj = ci+di[k], cj+dj[k]
        if 0<=ni<N and 0<=nj<N and arr[ni][nj] not in v:
            v.append(arr[ni][nj])
            DFS(k, ni, nj, v, cnt+1)
            v.pop()
 
di,dj = (1,1,-1,-1,1),(-1,1,1,-1,-1)
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = -1
    for si in range(0, N-2):
        for sj in range(1,N-1):
            DFS(0, si, sj, [], 0)
    print(f'#{test_case} {ans}')

    
    
    
    
def DFS(n, ci, cj, v, cnt):
    global si, sj, ans
    if n==2 and ans>=cnt*2:
        return
    if n>3: # 종료조건
        return
    if ci==si and cj==sj and n==3 and ans<cnt:  # 정답 갱신
        ans = cnt
        return
 
    for k in range(n, n+2):
        ni,nj = ci+di[k], cj+dj[k]
        if 0<=ni<N and 0<=nj<N and arr[ni][nj] not in v:
            v.append(arr[ni][nj])
            DFS(k, ni, nj, v, cnt+1)
            v.pop()
 
di,dj = (1,1,-1,-1,1),(-1,1,1,-1,-1)
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = -1
    for si in range(0, N-2):
        for sj in range(1,N-1):
            DFS(0, si, sj, [], 0)
    print(f'#{test_case} {ans}')
    
    
    
    
    
def DFS(n, ci, cj, v):
    global si, sj, ans
    if n==2 and ans>=len(v)*2:
        return
    if n>3: # 종료조건
        return
    if ci==si and cj==sj and n==3 and ans<len(v):  # 정답 갱신
        ans = len(v)
        return
 
    for k in range(n, n+2):
        ni,nj = ci+di[k], cj+dj[k]
        if 0<=ni<N and 0<=nj<N and arr[ni][nj] not in v:
            v.append(arr[ni][nj])
            DFS(k, ni, nj, v)
            v.pop()
 
di,dj = (1,1,-1,-1,1),(-1,1,1,-1,-1)
T = int(input())
for test_case in range(1, T + 1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = -1
    for si in range(0, N-2):
        for sj in range(1,N-1):
            DFS(0, si, sj, [])
    print(f'#{test_case} {ans}')
```







## 4366. 정식이의 은행업무















## 2382. 미생물 격리

> m초 후에 남아있는 미생물 수의 총합을 구하는 문제
>
> 







## 2117. 홈 방범 서비스

> 손해보지 않고, 운영하는 집의 최대 수를 구하는 문제
>
> 완전탐색 해야 할듯