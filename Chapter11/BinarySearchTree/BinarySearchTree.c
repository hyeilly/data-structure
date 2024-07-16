#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
  *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
  // 이진탐색트리에서 랩핑하는 함수를 추가한 이유
  // 이진탐색트리를 사용하는 사람은 BinarySearchTree.h 파일만 오픈
  return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
  BTreeNode * pNode = NULL // parent node
  BTreeNode * cNode = *pRoot; // current node
  BTreeNode * nNode = NULL // new node

  // 새로운 노드가(새 데이터가 담긴 노드가) 추가될 위치를 찾음
  while(cNode != NULL)
  {
    if(data == GetData(cNode))
      return; // 데이터(키)의 중복을 허용하지 않음 

    // 이동하기 전에 백업 시켜둠 
    pNode = cNode;
    // 작으면 왼쪽, 크면 오른쪽 노드로 
    if(GetData(cNode) > data)
      cNode = GetLeftSubTree(cNode);
    else
      cNode = GetRightSubTree(cNode);
  }

  nNode = makeBTreeNode();
  SetData(nNode, data);

  // pNode의 자식 노드로 새 노드를 추가
  if(pNode != NULL) // 새 노드가 루트 노드가 아니라면
  {
    if(data < GetData(pNode))
      MakeLeftSubTree(pNode, nNode);
    else
      MakeRightSubTree(pNode, nNode);
  }
  else // 새 노드가 루트 노드라면 
  {
    *pRoot = nNode;
  }

}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
  BTreeNode * cNode = bst; // current node
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
  return NULL; // 탐색 대상이 저장되어 있지 않음 
}