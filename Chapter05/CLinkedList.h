typedef int Data;

typedef struct _node
{
  Data data;
  struct _node * next;
} Node;

typedef struct _CLL
{
  Node * tail;
  Node * cur;
  Node * before;
  int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data); // 노드를 꼬리에 추가
void LInsertFront(List * plist, Data data); // 노드를 머리에 추가

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);


void ListInit(List * plist)
{
  plist->tail = NULL;
  plist->cur = NULL; // 참조를 위한 것 
  plist->before = NULL; // 삭제를 위한 것
  plist->numOfData = 0;
}

// 원형 리스트 구현 : 첫 번째 노드 삽입
void LInsert(List * plist, Data data)
{
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  
  if(plist->tail == NULL)
  {
    // 첫 번째 노드라면
    plist->tail = newNode;
    newNode->next = newNode;
  }
  else
  {
    // 두 번째 이후 노드라면
    // tail 이 새 노드를 가리키도록
    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    plist->tail = newNode;
  }
  (plist->numOfData)++;
}

void LInsertFront(List * plist, Data data)
{
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  
  if(plist->tail == NULL)
  {
    // 첫 번째 노드라면
    plist->tail = newNode;
    newNode->next = newNode;
  }
  else
  {
    // 두 번째 이후 노드라면
    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    
  }
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
  if(plist->tail == NULL)
    return false;
  plist->before = plist->tail;
  plist->cur = plist->tail->next;

  *pdata = plist->cur->data;
  rturn true;
}

int LNext(List * plist, Data * pdata)
{
  if(plist->tail == NULL)
    return false;
  plist->before = plist->cur;
  plist->cur = plist->cur->next;

  *pdata = plist->cur->data;
  return true;
}

LData LRemove(List * plist)
{
  Node * rpos = plist->cur;
  Data rdata = rpos->data;

  // 꼬리라면 tail 위치 조정 필요
  if(rpos == plist->tail)
  {
    if(plist->tail == plist->tail->next)
      plist->tail = NULL;
    else
      plist->tail = plist->before;
  }
  plist->before->next = plist->cur->next;
  plist->cur = plist->before;

  free(rpos);
  (plist->numOfData)--;
  return rdata;
}