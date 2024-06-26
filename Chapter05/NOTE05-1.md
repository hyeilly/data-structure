# 원형 리스트

- 시스템 레벨, 운영체제 레벨에서 사용되는 자료구조들
- 메모리를 순환적 구조로 사용할 수 있는 모델
- ex) 하드웨어의 메모리를 컨트롤하기 위한 소프트웨어

## 원형 연결 리스트의 이해

- 단순 연결 리스트의 마지막 노드는 NULL을 가리킴
  - head->2->4->6->8
- 원형 연결 리스트의 마지막 노드는 첫 번째 노드를 가리킴
  - head->2->4->6->8->2...

### 원형 연결 리스트의 노드 추가

- head 또는 tail 에 노드 추가
  - head->1->2->4->6->8->1...
  - head->2->4->6->8->1->2...
- 모든 노드가 원의 형태를 이루면서 연결되어 있기 때문에 원형 연결 리스트에서는 사실상 **머리와 꼬리의 구분이 없음**
  - 같다 = 두 경우의 노드 연결 순서가 같다
  - 다르다 = head가 가리키는 노드가 다르다

### 원형 연결 리스트의 대표적인 장점

- 단순 연결 리스트처럼 머리와 꼬리를 가리키는 포인터 변수를 각각 두지 않아도, 하나의 포인터 변수만 있어도 머리 또는 꼬리에 노드를 간단히 추가 가능

- 앞서 소개한 모델을 기반으로는 위의 장점 살리기 어려움
- 변형된, 보다 일반적으로 인식되고 있는 원형 연결 리스트 구현
- 2->4->6->8->1(new node)<-(tail)
  - 꼬리를 가리키는 포인터 변수는? **tail**
  - 머리를 가리키는 포인터 변수는? **tail->next**
- 리스트의 꼬리와 머리 주소 값을 쉽게 확인할 수 있기 때문에 연결 리스트를 가리키는 포인터 변수는 하나만 있으면 됨

## 변형된 원형 연결 리스트의 구현범위

- 조회관련
  - LFirst : 이전에 구현한 연결 리스트와 기능 동일
  - LNext : 원형 연결 리스트를 계속해서 순환하는 형태로 변경!
- 삭제관련
  - LRemove : 이전에 구현한 연결 리스트와 기능 동일
- 삽입관련 : 앞과 뒤에 삽입이 가능하도록 두 개의 함수 정의
- 정렬관련 : 정렬과 관련된 부분 전부 제거
- 이외의 부분 : 이전에 구현한 연결 리스트와 기능 동일

- 원형 연결 리스트는 그 구조상 끝이 존재. 따라서 LNext 함수는 계속해서 호출이 가능하고, 이로 인해 리스트를 순환하면서 저장된 값을 반환하도록 구현

### 원형 연결 리스트 구현 : 첫 번째 노드 삽입

- 첫 번째 노드는 그 자체로 머리이자 꼬리이기 때문에 노드를 뒤에 추가하건 앞에 추가하건 결과 동일

#### 앞과 뒤의 삽입 과정 비교1

- 노드를 머리에 추가한 결과
  - 7->4->-2<-tail
  - tail 은 바뀌지 않고 새로운 7 들어옴
- 노드를 꼬리에 추가한 결과
  - 4->2->7<-tail
  - 새로 들어온 7을 가리키는 tail

### 조회 LFirst

- before는 cur 왼쪽에 있는 노드를 가리킴
  - 삭제 과정에서 필요하기 떄문
- cur : tail 의 next가 가리키는 값을 저장
- before : cur 의 왼쪽인 tail 값 저장

### 노드의 삭제

#### 더미 노드 기반 연결 리스트의 삭제 과정

- 핵심연산 1
  - 삭제할 노드의 이전 노드가 삭제할 노드의 다음 노드를 가리킴
- 핵심연산 2
  - 포인터 변수 cur을 한 칸 뒤로 이동

#### 원형 연결 리스트

- 더미노드가 없으므로 삭제 과정에서 달라짐
- ex) 삭제할 노드가 tail이 가리키는 노드인 경우
  - 그 왼쪽에 있는 노드가 tail이 되어야함
- ex) 삭제할 노드가 head이자 tail인 경우 NULL 저장 필요
