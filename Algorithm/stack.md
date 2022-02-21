# stack

* 후입선출 : 마지막에 삽입된 자료가 가장 먼저 나온다.
* push : 자료 삽입
* pop : 자료 꺼냄
* isEmpty : 스택이 공백인지 확인
* peek : top item 반환

```python
def push(item, size):
    global top
    top += 1
    if top == size:
        print('overflow!')
    else:
        stack[top] = item
        
size = 10
stack = [0] * size
top = -1

push(10, size)
top += 1
stack[top] = 20


def pop():
    global top
    if top == -1:
        print('underflow')
    else:
        top -= 1
        return stack[top + 1]
```



### 괄호 문제

```python
s = input()

stack = [0] * 1000
top = -1
answ = 1
for x in s:
    if x == '(':
        top += 1	#push
        stack[top] = x
    elif x == ')':
        if top == -1:
            ans = 0
        else:
            top -= 1
else:
    if top != -1:
        ans = 0
print(ans)
                
```





## 재귀호출

```python
def fibo(n):
    if n < 2:
        return n
    else:
        return fibo(n-1) + fibo(n-2)
```





# Memoization

* 이전에 계산한 값을 메모리에 저장해서 매번 다시 계산하지 않도록 하여 실행속도를 빠르게 하는 기술

* 동적 계획법의 핵심

  재귀함수로 하면 시간이 오래걸리지만



재귀함수 장점 : 코드에 대한 이해가 쉽고, 유지보수가 쉽다.

```python
def fibo1(n):
    global memo
    if n >= 2 and len(memo) <= n:
        memo.append(fibo(n-1) + fibo1(n-2))
        return memo[n]
    
memo = [0, 1]
```





# DP(Dynamic Programming)

```python
def fibo2(n):
    f = [0, 1]
    
    for i in range(2, n+1):
        f.append(f[i-1] + f[i-2])
        
    return f[n]
```



