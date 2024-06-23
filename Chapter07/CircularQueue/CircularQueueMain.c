#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
  // Queue 의 생성 및 초기화
  Queue q;
  QueueInit(&q);
  
  // 데이터 넣기
  Enqueu(&q, 1);
  Enqueu(&q, 2);
  Enqueu(&q, 3);
  Enqueu(&q, 4);
  Enqueu(&q, 5);
  
  // 데이터 꺼내기
  while(!QIsEmpty(&q))
    printf("%d ", Dequeue(&q));

  return 0;

}