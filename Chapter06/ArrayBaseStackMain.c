#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
  // Stack의 생성 및 초기화
  // Pop 단순한 삭제이기 전에 참조. 참조 후 삭제
  Stack stack;
  StackInit(&stack);

  // 데이터 넣기
  SPush(&stack, 1);
  SPush(&stack, 2);
  SPush(&stack, 3);
  SPush(&stack, 4);
  SPush(&stack, 5);

  // 데이터 꺼내기
  while(!SIsEmpty(&stack))
    printf("%d ", SPop(&stack));

  return 0;
}