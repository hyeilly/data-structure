## 이진트리 순회하는 방법

1. 중위 순회

- 루트노드는 가운데
- 왼쪽에 있는 것이 노드가 아닌 트리인 경우
  - 그것을 기점으로 다시 중위 순회 시작... 반복
- 다 끝나면 오른쪽 노드로
- 중위 순회의 한가지 방법으로 돌면 모든 노드에 접근 가능해짐
- 중위 순회를 재귀적으로 구현하면 어떤 트리간에 이 트리를 구성하는 모든 노드에 접근하는 코드를 간단하게 만들 수 있음

2. 후위 순회

- 왼쪽 > 오른쪽 > 중앙

3. 전위 순회

- 중앙 > 왼쪽 > 오른쪽

## 순회의 재귀적 표현

- 1단계 왼쪽 서브 트리의 순회
- 2단계 루트노드의 방문
- 3단계 오른쪽 서브 트리의 순회
- 노드가 단말 노드인 경우, 단말 노드의 자식 노드는 NULL
- ```
  void InorderTraverse(BTreeNode * bt)
  {
    if(bt == NULL)
      return;
    InorderTraverse(bt->left);
    printf("%d \n", bt->data);
    InorderTraverse(bt->right);
  }
  ```
-

### 함수 포인터 선언

- `typedef void VisitFuncPtr(BTData data);`

  - `typedef void (*VisitFuncPtr)` 으로 대신 가능
  - **함수 포인터형** VisitFuncPtr의 정의

- action이 가리키는 함수를 통해서 방문을 진행

```
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt == NULL)
    return;
  InorderTraverse(bt->left, action);
  action(bt->data); // 노드의 방문
  InorderTraverse(bt->right, action);
}
```

- action 이 가리키는 함수를 통해서 방문을 진행
- BTreeNode의 인자 값 전달 받고, 함수의 주소값을 인자로 전달받음
- 함수 만들기. 이름은 상관없지만 void 반환, 매개변수는 BTData여야함

- VisitFuncPtr형을 기준으로 정의된 함수

```
void ShowIntData(int data)
{
  printf("%d ", data);
}
```
