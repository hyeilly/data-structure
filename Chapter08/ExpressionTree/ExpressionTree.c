#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

// 피연산자 정보를 담고있는 노드 주소값이 전달되었을때는 못받음
BTreeNode * MakeExpTree(char exp[])
{
  Stack stack;
  BTreeNode * pnode;

  int expLen = strlen(exp);
  int i;

  StackInit(&stack);
  
  for(i=0; i<expLen; i++)
  {
    pnode = MakeBTreeNode();
    if(isdigit(exp[i]))
    {
      SetData(pnode, exp[i]-'0');
    }
    else
    {
      MakeRightSubTree(pnode, SPop(&stack));
      MakeLeftSubTree(pnode, SPop(&stack));
      SetData(pnode, exp[i])
    }
    SPush(&stack, pnode);
  }
  return SPop(&stack);
}

// 전달된 주소값이 단순히 노드를 가리킨다면 노드에 저장된 주소값 반환만 해주면 됨 
int EvaluateExpTree(BTreeNode * bt)
{
  int op1, op2;
  if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // 단말노드
    return GetData(bt);
  op1 = EvaluateExpTree(GetLeftSubTree(bt));
  op2 = EvaluateExpTree(GetRightSubTree(bt));

  switch(GetData(bt))
  {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
  }
  return 0;
}

void ShowNodeData(int data)
{
  if(0 <= data && data <= 9)
    printf("%d ", data);
  else
    printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
  PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
  InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
  PostorderTraverse(bt, ShowNodeData);
}