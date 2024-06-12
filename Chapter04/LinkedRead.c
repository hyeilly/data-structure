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
}