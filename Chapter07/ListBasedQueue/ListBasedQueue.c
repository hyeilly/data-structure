void QueueInit(Queue * pq)
{
  // 포인터 변수에 NULL으로 초기화 
  // front가 NULL이면 rear를 보지않아도 ok
  pq->front = NULL;
  pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
  // F, R 둘다 NULL로 세팅한다면 하나만 NULL 이어도 됨
  if(pq->front == NULL)
    return TRUE;
  else
    return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
  // F,R은 첫번째 노드 가리킴
  // 새 노드가 등장하면 마지막 노드가 가리키게 하고, R 도 가리켜야함 
  // F -> NULL
  // R -> NULL 여기에 NULL 꼭 넣지 않아도 되도록 QIsEmpty 로 Front 가지고 체크 
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;
  if(QIsEmpty(pq))
  {
    pq->front = newNode;
    pq->rear = newNode;
  }
  else
  {
    pq->rear->next = newNode;
    pq->rear = newNode;
  }
}

// 데이터의 반환
Data Dequeue(Queue * pq)
{
  Node * delNode;
  Data retData;
  if(QIsEmpty(pq))
  {
    printf("Queue Memory Error!");
    exit(-1);
  }
  delNode = pq->front;
  retData = delNode->data;
  pq->front = pq->front->next; // 이동
  free(delNode); // 삭제
  return retData;
}
