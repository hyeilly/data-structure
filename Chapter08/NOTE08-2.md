## 이진 트리의 구현

### 이진 트리 구현의 두 가지 방법

- 노드에 번호를 부여하고 그 번호에 해당하는 값을 배열의 인덱스 값으로 활용
- 편의상 배열의 첫 번째 요소는 사용하지 않음

- 배열의 기본적인 장점

  - 접근이 용이하다라는 특성이 트리에서도 그대로 반영
  - 배열을 기반으로 했을 때 완성하기 용이한 트리 관련 연산 존재

- 연결 리스트 기반에서는 트리의 구조와 리스트의 연결 구조가 일치
- 따라서 구현과 관련된 직관적인 이해가 더 좋은 편

### 헤더파일에 정의된 구조체의 이해

- 이진 트리의 노드이자 트리를 표현한 구조체
  ```
  typedef struct _bTreeNode
  {
      BTData data;
      struct _bTreeNode * left;
      struct _bTreeNode * right;
  } BTreeNode;
  ```
- 이진 트리의 모든 노드는 직/간접적으로 연결
- 루트 노드의 주소 값만 기억하면, 이진 트리 전체를 가리키는 것과 다름 없음
- 논리적으로도 하나의 노드는 그 자체로 이진트리
- 따라서 노드를 표현한 구조체는 실제로 이진 트리를 표현한 구조체가 됨

- 만든 후 연결 시 트리의 주소값을 알아야할 때 루트노드의 주소 값이 트리의 주소값을 대표함
  - 루트노드의 주소값을 저장함

### 헤더파일에 선언된

- `BTreeNode * MakeBTreeNode(void);`
  - 하나의 메모리 left, right 는 NULL으로 초기화
  - 나머지는 data
  - 유효한 데이터는 SetData 함수를 통해 채우되 포인터 변수 left와 right는 NULL으로 자동 초기화
- `BTData GetData(BTreeNode * bt);`
  - 노드의 주소값을 인자로 전달
  - 노드에 저장된 데이터를 반환
- `void SetData(BTreeNode * bt, BTData data);`
  - 노드의 주소값과, 노드에 데이터를 저장
- 노드에 직접 접근하는 것보다 함수를 통한 접근이 보다 좋음
- `BTreeNode * GetLeftSubTree(BTreeNode * bt);`
  - 왼쪽 서브 트리의 주소값 반환
- `BTreeNode * GetRightSubTree(BTreeNode * bt);`
  - 오른쪽 서브 트리의 주소값 반환
- 루트 노드를 포함하여 어떠한 노드의 주소 값도 인자로 전달될 수 있음
- 전달된 노드의 왼쪽, 오른쪽 '서브 트리의 루트 노드 주소 값' 또는 그냥 '노드의 주소 값'이 반환
- `void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);`
  - main의 서브 왼쪽 서브 트리로 sub를 연결
- `void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);`
  - main의 오른쪽 서브 트리로 sub를 연결
- 하나의 노드도 일종의 이진 트리
- 위의 함수들은 단순히 노드가 아니라 트리를 대상으로도 결과를 보임
