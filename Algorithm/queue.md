# Queue

**이름 지을 때 Queue라고 알 수 있도록 짓자!**

## 특성



* 후입선출인 스택과는 달리 선입선출구조 (FIFO : First in First out)
* Front(머리) : 저장된 원소 중 첫 번째
* Rear(꼬리) : 마지막 저장된 원소



### 기본 연산

* 삽입 : enQueue()

  ```python
  def enQueue(item):
      global rear
      if isFull() : print("Queue_Full")
      else:
          rear = rear + 1
          Q[rear] = item
  ```

  

* 삭제 : deQueue()

  ```python
  def deQueue(item):
      if(isEmpty()) then Queue_Empty()
      else:
          front = front + 1
          return Q[front]
  ```

  

* 생성 : createQueue() ; 공백 상태의 큐를 생성

* isEmpty( )     ,  isFull(),       Qpeek() : 큐의 front에서 원소를 삭제 없이 반환하는 연산

  ```python
  def isEmpty():
      return front == rear
  
  def Full():
      return rear == len(Q) - 1
  
  def Qpeek():
      if isEmpty() : print("Queue_Empty")
      else : return Q[front+1]
  ```

  



### 상태 

* 초기상태 : front = rear = -1
* 공백 : front = rear
* 포화 : rear = n-1





## 원형 큐

선형 큐의 단점(잘못된 포화상태 인식, 해결시 큐의 효율성 떨어짐)을 보안하기 위하여 원형 큐 사용



### index 순환

* 나머지 연산자  mod 를 사용함.
* 초기 공백 상태 : front = rear = 0

* front 자리는 항상 빈자리로  -->  공백상태와 포화상태 구분 위해

  |        | 삽입 위치             | 삭제 위치               |
  | ------ | --------------------- | ----------------------- |
  | 선형큐 | rear = rear + 1       | front = front + 1       |
  | 원형큐 | rear = (rear + 1) % n | front = (front + 1) % n |

  

### 기본 연산









## 우선순위 큐(Priority Queue)

* FIFO가 아니라 우선순위가 높은 순서대로 먼저 나감.



#### 적용 분야

* 시뮬레이션 시스템
* 네트워크 트래픽 제어
* 운영체제의 테스크 스케줄링







## 버퍼

* 데이터를 한 곳에서 다른 곳으로 전송하는 동안 일시적으로 그데이터를 보관하는 메모리의 영역





# BFS(Breadth First Search)







준비하는 부분

while

​	실행하는 부분







visited 에 추가하는 타이밍 : 1. 처리했을 때?  2. 줄 세웠을 때?? + 단순히 여부가 아니라 몇번째에 visited 하는지 									구분 가능







덱 공부하기!  왜 더 빠른지    어떻게 구동되는지 







### 미로탐색 큐로 풀기





