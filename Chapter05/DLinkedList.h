typedef int Data;

typedef struct _node
{
  Data data;
  struct _node * next; // 오른쪽 노드 참조
  struct _node * prev; // 왼쪽 노드 참조
} Node;

//ListInit 함수의 정의에 참조해야 하는 구조체의 정의
typedef struct _dbLinkedList
{
  Node * head;
  Node * cur;
  int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);

// 멤버 cur은 조회의 과정에서 초기화되는 멤버이니 head와 numOfData만 초기화하면 됨
void ListInit(List * plist)
{
  plist->head = NULL;
  plist->numOfData = 0;
}

int LNext(List * plist, Data * pdata)
{
  if(plist->cur->next == NULL)
    return false;
  
  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;

  return true;
}

void LInsert(List * plist, Data data)
{
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  // 새노드 생성하고 head->newNode에 prev, next를 NULL 넣을 수 있음
  // newNode->next = NULL으로 가능하지만 2번째 이후의 노드 추가 시를 고려했을 때 새 노드와 기존 노드 연결로써 작성 
  newNode->next = plist->head; // head->4<->2(newNode)에서 2가 4를 가리키는 연결
  if (plist->head != NULL)
    plist->head->prev = newNode;

  newNode->prev = NULL;
  plist->head = newNode;
  (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
  if(plist->head == NULL)
    return false;
  plist->cur = plist->head;
  *pdata = plist->cur->data;
  return true;
}
int LNext(List * plist, Data * pdata)
{
  if(plist->cur->next == NULL)
    return false;
  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;
  return true;
}
int LPrevious(List * plist, Data * pdata)
{
  if(plist->cur->prev == NULL)
    return false;
  // 왼쪽으로 이동 
  plist->cur = plist->cur->prev;
  *pdata = plist->cur->data;
  return true;
}