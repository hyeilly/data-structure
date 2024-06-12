#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data; // 데이터를 담을 공간
  // 구조체 변수 포인터 선언
  // 구조체 노드의 변수를 가리킴
	struct _node * next; // 연결의 도구
} Node;

int main(void)
{
  // 연결 리스트의 핵심으로 연결을 추가 및 유지하기 위한 것
  Node * head = NULL;
  Node * tail = NULL;
  // 참조 및 조회를 위한 것
  Node * cur = NULL;

  Node * newNode = NULL;
  int readData;

  while(1)
  {
    printf("자연수 입력: ");
    scanf("%d", &readData);
    if(readData < 1)
      break;

    // 노드의 추가 과정
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = readData;
    newNode->next = NULL;

    // 노드를 추가하는 과정이 나뉘어짐 
    if(head == NULL)
      // 첫번째 노드가 저장되는 케이스
      head = newNode;
    else:
      // 두번째 이후의 노드가 저장되는 케이스
      tail->next = newNode;
      // tail->next는 tail이 가리키는 노드의 멤버 next 
    
    tail = newNode; 
  }

  // 전체 데이터의 출력 과정(조회)
  if(head == NULL)
  {
    prinf("저장된 자연수가 존재하지 않습니다 \n");
  }
  else
  {
    // 첫번째 노드를 참조
    cur = head; // 첫번째 노드 가리킴 
    printf("%d", cur->data); 
    // 두번째 이후 노드를 참조
    while(cur->next != NULL)
    {
      // 첫번째 노드에서 가지고 있는 두번째 노드의 주소값을 cur에 저장
      cur = cur->next;
      printf("%d ", cur->data);
    }
  }
}