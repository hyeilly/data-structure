# 스택

## 스택의 이해와 ADT 정의

### 스택의 이해

- 먼저 들어간 것이 나중에 나오는 자료구조
- LIFO(Last-in, First-out)
- 스택의 기본연산 `push` 삽입 `pop` 추출 + 삭제 `peek` 데이터 추출 가능. 삭제 개념은 존재하지 않음

### 스택의 ADT 정의

- ADT를 대상으로 배열 기반의 스택 또는 연결리스트 기반의 스택 구현 가능

- `void StackInit(Stack * pstack);`

  - 스택의 초기화 진행
  - 스택 생성 후 제일 먼저 호출되어야하는 함수

- `int SIsEmpty(Stack * pstack);`
  - 스택이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환
- `void SPush(Stack * pstack, Data data);`

  - 스택에 데이터를 저장. 매개변수 data로 전달된 값을 저장

- `Data SPop(Stack * pstack);`

  - 마지막에 저장된 요소를 삭제
  - 삭제된 데이터는 반환
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 **보장**되어야 함

- `Data SPeek(Stack * pstack);`
  - 마지막에 저장된 요소를 반환하되 삭제하지 않음
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야함
