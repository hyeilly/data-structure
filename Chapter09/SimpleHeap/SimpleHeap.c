#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
  ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
  if(ph->numOfData == 0)
    return TRUE;
  else
    return FALSE;
}

int GetParentIDX(int idx)
{
  // 부모 노드의 인덱스 값 반환
  return idx / 2;
}

int GetLChildIDX(int idx)
{
  // 왼쪽 자식 노드의 인덱스 값 반환
  return idx * 2;
}

int GetRChildIDX(int idx)
{
  // 오른쪽 자식 노드의 인덱스 값 반환
  return GetLChildIDX(idx) + 1;
}

