#include <stdio.h>
#include "BinaryTree3.h"

// LL 회전
BTreeNode * RotateLL(BTreeNode * bst)
{
  BTreeNode * pNode;
  BTreeNode * cNode;

  pNode = bst;
  cNode = GetLeftSubTree(pNode);

  // 실제 LL회전을 담당하는 두개 문장 
  ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
  ChangeRightSubTree(cNode, pNode);
  return cNode;
}

// RR 회전
BTreeNode * RotateRR(BTreeNode * bst) // RR회전을 담당하는 함수
{
  BTreeNode * pNode; // parent node
  BTreeNode * cNode; // child node

  // pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 함
  pNode = bst;
  cNode = GetRightSubTree(pNode);

  // 실제 RR회전을 담당하는 두개 문장 
  ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
  ChangeLeftSubTree(cNode, pNode);
  // RR 회전으로 인해서 변경된 루트 노드의 주소 값 반환 
  return cNode;
}

// RL 회전
// 부분적 LL회전에 이어서 RR 회전을 진행
BTreeNode * RotateRL(BTreeNode * bst)
{
  BTreeNode * pNode;
  BTreeNode * cNode;

  // pNode와 cNode가 RL회전을 위해 적절한 위치를 가리킴 
  pNode = bst;
  cNode = GetRightSubTree(pNode);

  ChangeRightSubTree(pNode, RotateLL(cNode));
  return RotateRR(pNode);
}

// 부분적 RR회전에 이어서 LL회전을 진행
BTreeNode * RotateLR(BTreeNode * bst) // LR회전을 담당하는 함수
{
  BTreeNode * pNode; // parent node
  BTreeNode * cNode; // child node

  // pNode와 cNode가 LR회전을 위해 적절한 위치를 가리키게 함 
  pNode = bst;
  cNode = GetLeftSubTree(pNode);

  // 실제 LR회전을 담당하는 두 개의 문장
  ChangeLeftSubTree(pNode, RotateRR(cNode));
  return RotateLL(pNode);
}

int GetHeight(BTreeNode * bst)
{
  int leftH;
  int rightH;

  if(bst == NULL)
    return 0;

  leftH = GetHeight(GetLeftSubTree(bst));

  rightH = GetHeight(GetRightSubTree(bst));

  if(leftH > rightH)
    return leftH + 1;
  else
    return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
  int lsh; // left sub tree height
  int rsh; // right sub tree height

  if(bst == NULL)
    return 0;

  lsh = GetHeight(GetLeftSubTree(bst));
  rsh = GetHeight(GetRightSubTree(bst));

  return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
  int hDiff = GetHeightDiff(*pRoot); // 균형 인수 계산

  // 균형 인수 +2 이상이면 LL상태 또는 LR 상태
  if(hDiff > 1) // 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면 
  {
    // 왼쪽으로 더 긴지, 오른쪽으로 더 긴지 묻기 위한 함수 호출
    // 값이 0보다 크면 LL상태 그렇지 않으면 LR 상태
    if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
      *pRoot = RotateLL(*pRoot);
    else
      *pRoot = RotateLR(*pRoot);
  }
  // 균형 인수가 +2 이상이면 왼쪽으로 길게 불균형을 이룬 상태이므로 LL 또는 LR 상태 

  // 균형 인수가 -2 이하이면 RR상태 또는 RL 상태
  if(hDiff < -1) // 오른쪽 서브 트리 방향으로 2 이상 크다면 
  {
    // 값이 0보다 작으면 RR상태 그렇지 않으면 RL 상태
    if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
      *pRoot = RotateRR(*pRoot);
    else
      *pRoot = RotateRL(*pRoot);
  }
  // 균형 인수가 -2 이하이면 오른족으로 길게 불균형을 이룬 상태이므로 RR 또는 RL 상태 
  return *pRoot;
}