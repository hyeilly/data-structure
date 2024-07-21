# 탐색2

## 균형 잡힌 이진 탐색 트리: AVL 트리의 구현

- 파일
  - `BinaryTree3.h` 이진 트리의 헤더파일
  - `BinaryTree3.c` 이진 트리 구성하는데 필요한 도구들 모임
  - `BinarySearchTree2.h` 이진 탐색 트리의 헤더파일
  - `BinarySearchTree2.c` 이진 탐색 트리의 구현
  - `AVLRebalance.h` 리밸런싱 관련 함수들의 선언
  - `AVLRebalance.c` 리밸런싱 관련 함수들의 정의
- AVL 트리도 이진 탐색 트리의 일종

### 리밸런싱 도구 : 균형을 이루고 있는지?

```
// 두 서브 트리의 '높이의 차(균형 인수)'를 반환
int GetHeightDiff(BTreeNode * bst)
{
  int lsh; // left sub tree height
  int rsh; // right sub tree height

  if(bst == NULL)
    return 0;

  lsh = GetHeight(GetLeftSubTree(bst));
  rsh = GetHeight(GetRightSubTree(bst));
  return lsh - rsh; // 균형 인수 계산결과 반환
}
```

- 모든 경로의 높이를 비교하기 위한 재귀적인 구성

```
// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst)
{
  int leftH; // left height
  int rightH; // right height
  if(bst == NULL)
    return 0;
  leftH = GetHeight(GetLeftSubTree(bst));
  rightH = GetHeight(GetRightSubTree(bst));

  // 큰 값의 높이를 반환
  if(leftH > rightH)
    return leftH + 1;
  else
    return rightH + 1;
}
```

### AVL 트리 삽입 과정에서의 리밸런싱 기능에 대한 완성

- 모든 상황에서 완벽히 균형을 유지해주지 못함
- EX) 3의 왼쪽 자식노드 2, 2의 왼쪽 자식노드 1, 3의 오른쪽 자식노드 4, 4의 오른쪽 자식노드 5

  - 5의 오른쪽 자식노드에 6을 추가할 때 => 4, 5, 6 노드 균형 잡기 위해 `rebalance` 함수 호출
  - rebalance 함수 호출 과정
    - 6 > 5 > 4 > 3 역순으로 호출
    - 재귀적으로 구현

- 루트 노드를 대상으로 하여 데이터 저장 시도(함수 호출 시작)
  1. 루트 노드에 저장된 데이터와 새 데이터 비교
  2. 비교해 새 데이터 값 작으면 왼쪽 자식 노드를 루트 노드로 하여 데이터 저장 시도
  3. 비교해 새 데이터 값이 크면 오른쪽 자식 노드를 루트 노드로 하여 데이터 저장 시도
  4. 저장 완료되면 해당 루트 노드를 기준으로 리밸런싱
