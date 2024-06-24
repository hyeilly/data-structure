int main(void)
{
  Queue q;
  QueueInit(&q);
  
  // 데이터 넣기
  Enqueue(&q, 1);
  Enqueue(&q, 2);
  Enqueue(&q, 3);
  Enqueue(&q, 4);
  Enqueue(&q, 5);
  
  // 데이터 꺼내기
  while(!QIsEmpty(&q))
    printf("%d ", Dequeue(&q));
  return 0;
}