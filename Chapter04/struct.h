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

// 삽입2
void FInsert(List * plist, LData data)
{
  Node * newNode = (Node*)malloc(sizeof(Node)); //새 노드 생성
  newNode->data = data; // 새 노드에 데이터 저장
  newNode->next = plist->head->next; // 새 노드가 다른 노드를 가리키게 함 
  plist->head->next = newNode; // 더미 노드가 새 노드를 가리키게 함
  (plist->numOfData)++; // 저장된 노드의 수를 하나 증가
}

// 참조1 
// 노드의 삭제를 위해 쓰는 before 
int LFirst(List * plist, LData * pdata)
{
  if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킨다면
    return FALSE; // 반환할 데이터가 없음
  // before는 삭제와 관련있음 
  plist->before = plist->head; // before는 더미 노드를 가리키게 함
  plist->cur = plist->head->next; // cur은 첫 번째 노드를 가리키게 함
  *pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달()\\
  return TRUE; // 데이터 반환 성공
}

// cur과 before 한칸씩 이동 시키기
int LNext(List * plist, LData * pdata)
{
  if(plist->cur->next == NULL) // 더미노드가 NULL을 가리킨다면
    return FALSE; // 반환할 데이터 없음
  plist->before = plist->cur; // cur이 가리키던 것을 before가 가리킴
  plist->cur = plist->cur->next; // cur은 그 다음 노드를 가리킴 

  *pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 전달
  return TRUE; // 데이터 반환 성공
}

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);
// 삭제 는 참조의 과정에서 이루어짐. LRemove함수 실행시 LFirst, LNext 참조가 이루어진 노드를 삭제하므로 
int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));