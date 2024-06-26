## 덱(Deque)의 이해와 구현

### 덱의 이해

- 덱은 앞으로도 뒤로도 넣을 수 있고, 앞으로도 뒤로도 뺄 수 있는 자료구조
- 덱의 4가지 연산! 모든 연산은 Pair를 이루지 않음. 개별적으로 연산 가능!
  - 앞으로 넣기
  - 앞에서 빼기
  - 뒤로 넣기
  - 뒤에서 빼기
- Deque는 double ended queue
  - 양쪽 방향으로 모두 입출력이 가능함을 의미
  - 스택과 큐의 특성을 모두 지니고 있음
  - 덱을 스택으로도 큐로도 활용이 가능함

### 덱의 ADT

- void DequeInit(Deque \* pdeq);
  - 덱의 초기화를 진행
  - 덱 생성 후 제일 먼저 호출되어야 하는 함수
- int DQIsEmpty(Deque \* pdeq);
  - 덱이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환
- void DQAddFirst(Deque \* pdeq, Data data);
  - 앞으로 넣기
  - 덱의 머리에 데이터를 저장
  - data로 전달된 값을 저장
- void DQAddLast(Deque \* pdeq, Data data);
  - 뒤로 넣기
  - 덱의 꼬리에 데이터를 저장
  - data로 전달된 값을 저장
- Data DQRemoveFirst(Deque \* pdeq);
  - 앞에서 빼기
  - 덱의 머리에 위치한 데이터를 반환 및 소멸
- Data DQRemoveLast(Deque \* pdeq);
  - 뒤로 빼기
  - 덱의 꼬리에 위치한 데이터를 반환 및 소멸
- Data DQGetFirst(Deque \* pdeq);
  - 앞에서 PEEK
  - 덱의 머리에 위치한 데이터를 소멸하지 않고 반환
- Data DQGetLast(Deque \* pdeq);
  - 뒤에서 PEEK
  - 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환

### 덱의 구현에 가장 어울리는 자료구조는 양방향 연결 리스트

- 한쪽 방향으로만 연결되어있을 때 이전 노드의 주소값을 아는 것이 불가능
- 양방향으로 연결하면 마지막 노드 삭제해도 이전 노드의 주소갑솓 가지고 있음

### 덱의 구현 : 함수의 정의

- 이전에 구현한 양방향 연결리스트 구조에 tail 만 추가하면 됨
