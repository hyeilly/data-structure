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

