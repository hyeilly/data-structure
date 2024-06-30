#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
  char exp[] = "12+7*";
  BTreeNode * eTree = MakeExpTree(exp);

  printf("전위순회:")
  ShowPrefixTypeExp(eTree);
  printf("\n");

  printf("중위순회:")
  ShowInfixTypeExp(eTree);
  printf("\n");

  printf("후위순회:")
  ShowPostfixTypeExp(eTree);
  printf("\n");
  
  printf("%d \n", EvaluateExpTree(eTree));
  return 0;
}
