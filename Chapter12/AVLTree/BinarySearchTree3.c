#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void BASTMakeAndInit(BTreeNode ** pRoot)
{
  *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
  return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
  // 루트노드의 주소 값을 가지고 있는 포인터 변수의 주소 값을 전달받음 pRoot => 값 직접 변경 가능하도록
  BTreeNode * pNode = NULL; //parent node
  BTreeNode * cNode = *pRoot; //current node
  BTreeNode * nNode = NULL; // new node

  while(cNode != NULL)
  {
    if(data == GetData(cNdoe))
      return;

    pNode = cNode;
    
    if(GetData(cNode) > data)
      cNode = GetLeftSubTree(cNode);
    else
      cNode = GetRightSubTree(cNode);
  }
  nNode = MakeBTreeNode();
  SetData(nNode, data);

  if(pNode != NULL)
  {
    if(data < GetData(pNode))
      MakeLeftSubTree(pNode, nNode);
    else
      MakeRightSubTree(pNode, nNode);
  }
  else
  {
    *pRoot = nNode;
  }

  // 루트노드 변경된 정보를 반영하기 위한 문장
  // *pRoot = Rebalance(pRoot);

  Rebalance(pRoot); // 노드 추가 후 리밸런싱
  // 리밸런싱의 과정에서 루트 노드가 변경될 수 있음
  
}

BTreeNode * BSSearch(BTreeNode * bst, BSTData target)
{
  BTreeNode * cNode = bst; //current node
  BSTData cd; // current data

  while(cNode != NULL)
  {
    cd = GetData(cNode);

    if(target == cd)
      return cNode;
    else if(target < cd)
      cNode = GetLeftSubTree(cNode);
    else
      cNode = GetRightSubTree(cNode);
  }
  return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
  BTreeNode * pVRoot = MakeBTreeNode();

  BTreeNode * pNode = pVRoot; // parent node
  BTreeNode * cNode = *pRoot // current node
  BTreeNode * dNode; // delete node

  ChangeRightSubTree(pVRoot, *pRoot);

  while(cNode != NULL && GetData(cNode) != target)
  {
    pNode = cNode;

    if(target < GetData(cNode))
      cNode = GetLeftSubTree(cNode);
    else
      cNode = GetRightSubTree(cNode);
  }

  if(cNode == NULL)
    return NULL;
  
  dNode = cNode;

  if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
  {
    if(GetLeftSubTree(pNode) == dNode)
      RemoveLeftSubTree(pNode);
    else
      RemoveRightSubTree(pNode);
  }
  else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
  {
    BTreeNode * dcNode;

    if(GetLeftSubTree(dNode) != NULL)
      dcNode = GetLeftSubTree(dNode);
    else
      dcNode = GetRightSubTree(dNode);

    if(GetLeftSubTree(pNode) == dNode)
      ChangeLeftSubTree(pNode, dcNode);
    else
      ChangeRightSubTree(pNode, dcNode);
  }
  else
  {
    BTreeNode * mNode = GetRightSubTree(dNode); 
    BTreeNode * mpNode = dNode;
    int delData;

    while(GetLeftSubTree(mNode) != NULL)
    {
      mpNode = mNode;
      mNode = GetLeftSubTree(mNode);
    }
    delData = GetData(dNode);
    SetData(dNode, GetData(mNode));

    if(GetLeftSubTree(mpNode) == mNode)
      ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
    else
      ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

    dNode = mNode;
    SetData(dNode, delData);
  }

  if(GetRightSubTree(pVRoot) != *pRoot)
    *pRoot = GetRightSubTree(pVRoot);
  
  free(pVRoot);
  // *pRoot = Rebalance(pRoot);
  Rebalance(pRoot); // 노드 제거 후 리밸런싱
  return dNode;
}

void ShowIntData(int data)
{
  printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
  InorderTraverse(bst, ShowIntData);
}