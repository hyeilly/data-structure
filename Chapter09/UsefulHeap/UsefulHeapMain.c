#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
  // 아스키 코드 값이 작은 문자의 우선순위가 더 높음
  return ch2-ch1;
  // return ch1-ch2;
}

int main(void)
{
  Heap heap;
  HeapInit(&heap, DataPriorityComp);

  HInsert(&heap, 'A');
  HInsert(&heap, 'B');
  HInsert(&heap, 'C');
  printf("%c \n", HDelete(&heap));

  HInsert(&heap, 'A');
  HInsert(&heap, 'B');
  HInsert(&heap, 'C');
  printf("%c \n", HDelete(&heap));

  while(!HIsEmpty(&heap))
    printf("%c \n", HDelete(&heap));
  return 0;
}


