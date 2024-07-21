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
  return cNode;
}

// RL 회전
BTreeNode * RotateRL(BTreeNode * bst)
{
  BTreeNode * pNode;
  BTreeNode * cNode;

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
  int hDiff = GetHeightDiff(*pRoot);

  if(hDiff > 1)
  {
    if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
      *pRoot = RotateLL(*pRoot);
    else
      *pRoot = RotateLR(*pRoot);
  }
  if(hDiff < -1)
  {
    if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
      *pRoot = RotateRR(*pRoot);
    else
      *pRoot = RotateRL(*pRoot);
  }
  return *pRoot;
}