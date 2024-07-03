// 힙을 위한 헤더 파일 - 우선순위 큐 처럼 구현됨
#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE  1
#define FALSE 0

#define HEAP_LEN  100

typedef char HData;

// 우선순위 큐와 관련이 됨 
typedef struct _heapElem
{
  Priority pr; // 값이 작을수록 높은 우선순위. 우선순위 정보를 저장할 수 있는 멤버
  HData data;
} HeapElem;

typedef struct _heap
{
  int numOfData;
  HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph); 
int HIsEmpty(Heap * ph);

// 루트 노드를 삭제하는 것이 우선순위 큐. => 우선순위 큐 deque와 일치하게 정의할 것
void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);


