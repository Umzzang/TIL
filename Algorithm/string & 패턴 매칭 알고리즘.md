# String

## 문자열

글자를 메모리에 저장하는 방법

글자 -> 숫자 -> 메모리



미국에서 만든 문자 표기 표준안

### ASCII(American Standard Code for Information Interchange)

* 7bit 인코딩
* 128문자 표현
* 33개의 출력 불가능 95개의 출력 가능



### 확장 아스키

* 8bit
* 표준 아스키와 다르게 일반적으로 통용 x



### 유니 코드

국가간 다국어 처리를 위해 준비한 표준

* Character Set 으로 다시 분류 된다. - 저장하는 변수의 크기
* but, 바이트 순서에 대해서 표준화 x

#### big-endian, little-endian 



# 패턴 매칭 알고리즘

* 고지식    O(MN)
* 카프-라빈
* KMP    O(M+N)
* 보이어-무어

## KMP 알고리즘

```python
def kmp(t,p):
    N = len(t)
    M = len(p)
    lps = [0] * (M + 1)
    
    j = 0
    lps[0] = -1
    for i in range(1, M):
        lps[i] = j
        if p[i] == p[j]:
            j += 1
        else:
            j = 0
    lps[M] = j                          # p 속에 패턴을 찾는과정 인듯?
    
    
    i = 0
    j = 0
    while i < N and j <= M:
        if j == -1 or t[i] == p[j]:
            i += 1
            j += 1
        else:
            j = lps[j]
        if j == M:
            print(i-M, end=' ')
            j = lps[j]
    
```



## 보이어-무어 알고리즘

* 대부분의 상용 소프트웨어에서 채택하고 있는 알고리즘
* 끝 부분을 비교 비교당하는 T의 문자가 패턴안에 있다면 그 칸수만큼 점프하여 비교  없다면 패턴 길이만큼 점프







## 문자열 암호화

