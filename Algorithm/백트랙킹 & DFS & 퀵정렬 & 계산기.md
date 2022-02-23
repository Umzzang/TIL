# DFS(Depth-First Search)

* 깊이 우선 탐색 -> **비선형구조**의 그래프 구조를 검색할 때 사용

* 모든 노드를 검색

* 미로에서 한방향으로만 쭉 갔다가 되돌아오는 과정과 비슷

* BFS 보다 쉽지만, 오래 걸린다.

* **어떤 노드를 방문했는지 여부 검사 필수** -> 무한루프 조심

  

```python
def dfs(graph, start_node):
 
    ## 기본은 항상 두개의 리스트를 별도로 관리해주는 것
    stack, visited = list(), list()
 
    ## 시작 노드를 시정하기 
    stack.append(start_node)
    
    ## 만약 아직도 방문이 필요한 노드가 있다면,
    while stack:
 
        ## 그 중에서 가장 마지막 데이터를 추출 (스택 구조의 활용)
        node = stack.pop()
        
        ## 만약 그 노드가 방문한 목록에 없다면
        if node not in visited:
 
            ## 방문한 목록에 추가하기 
            visited.append(node)
 
            ## 그 노드에 연결된 노드를 
            stack.extend(graph[node])
            
    return visited
```





# 계산기

### 중위표기법 (infix notation)

: 연산자를 피연산자의 가운데 표기하는 방법

ex) A + B



### 후위표기법 (postfix notation)

: 연산자를 피연산자 뒤에 표기하는 방법

ex) AB +



#### 후위표기법 사용 이유

컴퓨터 내부구조에서 후위표기법을 사용하는 것이 더 효율적이기 때문

중위표기법 수식은

중위  -->  후위 --> 계산



### 중위 --> 후위

```
1. 피연산자는 스택에 넣지않고 그대로 출력
2. 연산자
   - 스택이 비어있을경우 push
   - 스택이 비어있지 않을경우 스택의 연산자와 우선순위를 비교, 
     stack top 연산자가 현재 연산자의 우선순위보다 낮을때 까지 pop 후 출력
     현재연산자 stack push

3. 왼쪽 괄호 `(` 를 만나면 stack push
4. 오른쪽 괄호 `)` 를 만나면 왼쪽 괄호 `(`가 나올때까지 모든 연산자 pop 후 출력 ->  `(` 삭제
5. 표기식에 문자가 남지 않았다면 stack 을 비운다 pop 후 출력
```



### 후위 --> 계산

```python
1. 피연산자를 만나면 스택 push
2. 연산자를 만나면 필요한 만큼의 피연산자를 스택에서 pop하여 연산하고, 연산결과를 다시 스택에 push
3. 수식이 끝나면, 마지막으로 스택을 pop하여 출력
```





# 백트래킹 - 막히면 돌아간다.

* 최적화 문제
* 결정 문제  :  해의 존재 여부 파악문제  

​	ex) 미로, n-Queen, Map coloring, Subset Sum

* Prunning (가지치기)   --> 해결책이 아닐 것 같으면 시도하지 않음.

```
1. 상태 공간 트리의 깊이 우선 검색
2. 각 노드의 상태 점검
3. 노드가 답을 주지 않을 것 같으면 부모 노드로 back
```



## 부분집합



```python
def f(i, N, K):
    global cnt
    cnt += 1
    if i==N:    # 한 개의 부분집합이 완성된 경우
        # print(bit)
        s = 0   # 부분집합 원소의 합
        for j in range(N):
            if bit[j]:
                s += a[j]   # bit[j]가 1이면  a[j]가 부분집합에 포함
        if s==K:
            for j in range(N):
                if bit[j]:
                    print(a[j], end = ' ')
            print()
    else:
        bit[i] = 1
        f(i+1, N, K)
        bit[i] = 0
        f(i+1, N, K)
    return



def f(i, N, K, S):
    if i == N:
        if S == K:
            for j in range(N):
                if bit[j]:
                    print(a[j], end = ' ')
                    
        return
    elif S > K:
        return
    else:
        bit[i] = 1
        f(i+1, N, K, S+a[i])
        bit[i] = 0
        f(i+1, N, K, S)
    return
    
    

def f(i, N, K, S):  # S i-1원소까지 고려한 합
    global cnt
    cnt += 1
    if K==S:
        for j in range(N):
            if bit[j]:
                print(a[j], end=' ')
        print()
    elif i==N:    # 한 개의 부분집합이 완성된 경우
        return
    elif S >K:
        return
    else:
        bit[i] = 1
        f(i+1, N, K, S+a[i])
        bit[i] = 0
        f(i+1, N, K, S)
    return



def f(i, N, K, S, RS):  # S i-1원소까지 고려한 합
    global cnt
    cnt += 1
    if K==S:
        for j in range(N):
            if bit[j]:
                print(a[j], end=' ')
        print()
    elif i==N:    # 한 개의 부분집합이 완성된 경우
        return
    elif S>K:
        return
    elif S + RS < K:
        return
    else:
        bit[i] = 1
        f(i+1, N, K, S+a[i], RS - a[i])
        bit[i] = 0
        f(i+1, N, K, S, RS - a[i])
    return


N = 10
a = [x for x in range(1, N + 1)]
bit = [0] * N
K = 10

f(0, N, K, 0)
```



백트랙킹을 사용해도 항상 연산이 줄어드는 것은 아니다.



## ################함수 안 리스트##############

```python
def f1():
    a[0] = 2    # 전역. 원소만 수정하는 경우

def f2():
    a = [10, 20, 30]    # global 없는 선언은 전역의 a가 아니라 로컬 a

def f3():
    global a
    a = [10, 20, 30]    # 전역 a에 재 할당 됨

a = [1,2,3]
f1()
print(a)
f2()
print(a)
f3()
print(a)
```

```
[2, 2, 3]
[2, 2, 3]   
[10, 20, 30]
```

????? - 리스트만?? 



## 순열 nPr 

* 순서 상관 있음

```python
```





# 분할정복 알고리즘

```
1. 분할 : 문제를 여러 개의 작은 부분으로 분할
2. 정복 : 나눈 작은 문제를 각각 해결
3. 통합 : (필요하다면) 해결된 해답을 통합
```

```
ex) 거듭제곱
O(n)  - >  O(log2n)
```





### 합병 정렬(merge sort) vs 퀵 정렬 (quick sort)



## 퀵정렬 - 최악의 경우 느리지만, 평균적으로 빠르다.

```python
def quicksort(a, begin, end):
    if begin < end:
        p = partition(a,begin,end)
        quicksort(a,begin,p-1)
        quicksort(a,p+1,end)
        
def partition(a, begin, end):
    pivot = (begin + end) // 2
    L = begin
    R = end
    while L < R:
        while(L < R and a[L] < a[pivot]) : L += 1
        while(L < R and a[R] >= a[pivot]) : R -= 1
       	if L < R:
            if L == pivot : pivot = R
                a[L], a[R] = a[R], a[L]
    a[pivot], a[R] = a[R], a[pivot]
    return R
```



?????? - 함수 밖의 리스트 함수안에서 호출 가능??????