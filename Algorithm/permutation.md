# 순열 만들기

```python
g = [1, 2, 3]
cnt = 0		# 갯수 세기 위해
def com(i, n):
    if i == n:			# n 번까지 끝났을 때
        print(g)
        cnt += 1
    else:
        for j in range(i,n):		# i 가 0 이면 모든 자리와 앞자리 바꾸기
            g[i], g[j] = g[j], g[i] 
            com(i+1, n)				# 맨 앞자리 납두고 그 다음 자리 진행
            g[i], g[j] = g[j], g[i]
            
p(0, len(g))
print(cnt)
```

```
[1, 2, 3]
[1, 3, 2]
[2, 1, 3]
[2, 3, 1]
[3, 2, 1]
[3, 1, 2]
6        			=> 3 * 2 출력
```







## 처음에 잘못 생각한 부분

```python
g = [1, 2, 3]
for i in range(3):
    for j in range(i, 3):
        g[i], g[j] = g[j], g[i] 
        print(g)			
        g[i], g[j] = g[j], g[i]
```

```
[1, 2, 3]
[2, 1, 3]
[3, 1, 2]
[3, 1, 2]
[3, 2, 1]
[3, 2, 1]

=> 맨 앞자리 고정하고 뒤에것만 움직이기 때문에 안됨.  3+2+1 번 출력
```

