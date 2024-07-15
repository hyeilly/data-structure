#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
  BTreeNode * bstRoot; // bstRoot는 BST의 루트 노드를 가리킴 
  BTreeNode * sNode; // search node

  BSTMakeAndInit(&bstRoot); // Binary Search Tree 의 생성 및 초기화 

  BSTInsert(&bstRoot, 9); // bstRoot에 9를 저장
  BSTInsert(&bstRoot, 1);
  BSTInsert(&bstRoot, 6);
  BSTInsert(&bstRoot, 2);
  BSTInsert(&bstRoot, 8);
  // BSTInsert(&bstRoot, 4);
  BSTInsert(&bstRoot, 3);
  BSTInsert(&bstRoot, 5);
  // BSTInsert(&bstRoot, 7);

  // 탐색. 1이 저장된 노드를 찾아 
  sNode = BSTSearch(bstRoot, 1);
  if(sNode == NULL)
    printf("탐색 실패\n");
  else
    printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

  
  sNode = BSTSearch(bstRoot, 4);
  if(sNode == NULL)
    printf("탐색 실패\n");
  else
    printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));


  sNode = BSTSearch(bstRoot, 6);
  if(sNode == NULL)
    printf("탐색 실패\n");
  else
    printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

  
  sNode = BSTSearch(bstRoot, 7);
  if(sNode == NULL)
    printf("탐색 실패\n");
  else
    printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));
  // 이진 탐색 트리의 사용자 입장에서는 단순히 데이터를 저장하고 탐색하면 됨
  // 어떤 형태로 트리가 구성되는지 알 필요 없음
  return 0;
}