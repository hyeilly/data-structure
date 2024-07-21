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
