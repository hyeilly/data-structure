#define TRUE 1
#define FALSE 0

typedef int LData;
// 연결리스트에 필요한 변수들을 구조체로 묶지 않는 것은 옳지 못함
typedef struct _node // 노드의 구조체 표현 
{
  LData data; // typedef int LData
  struct _node * next;
} Node;

typedef struct _linkedList
{
  Node * head; // 더미 노드를 가리키는 멤버
  Node * cur; // 참조 및 삭제를 돕는 멤버
  Node * before; // 삭제를 돕는 멤버
  int numOfData; // 저장된 데이터의 수를 기록하기 위한 멤버
  int (*comp)(LData d1, LData d2); // 정렬의 기준을 등록하기 위한 멤버(설치를 위한 함수포인터 변수)
} LinkedList;

int main()
{
  // 리스트 자료구조는 2개 이상 사용 필요할 수 있음, 동적할당 가능
  LinkedList a;
  LinkedList b;
}

void ListInit(List * plist)
{
  plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드의 생성 
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->numOfData = 0;
}

void LInsert(List * plist, LData data)
{
  if(plist->comp == NULL) // 정렬기준이 마련되지 않았다면
    FInsert(plist, data); // 머리에 노드 추가
  else // 정렬 기준이 마련되었다면
    SInsert(plist, data); // 정렬기준에 근거하여 노드 추가
}

void FInsert(List * plist, LData data)
{
  Node * newNode = (Node*)malloc(sizeof(Node)); //새 노드 생성
  newNode->data = data; // 새 노드에 데이터 저장
  newNode->next = plist->head->next; // 새 노드가 다른 노드를 가리키게 함 
  plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 함
  (plist->numOfData)++; // 저장된 노드의 수를 하나 증가
}


typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));