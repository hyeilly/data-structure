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

// 우선 순위가 높은 자식의 인덱스 값 반환
// 완전 이진트리의 특성을 기반으로 작성된 함수
int GetHiPriChildIDX(Heap * ph, int idx)
{
  // 자식 노드가 존재하지 않는 다면, 완전이진트리임
  // 마지막 노드의 인덱스 값인 numOfData
  if(GetLChildIDX(idx) > ph->numOfData)
    return 0; // 자식노드 없으면 0 반환
  // 자식 노드가 왼쪽 자식 노드 하나만 존재한다면
  else if(GetHiPriChildIDX(idx) == ph->numOfData)
    // 자식 노드가 하나 존재하면 이는 왼쪽 자식 노드. -> 완전 이진 트리 이므로
    return GetLChildIDX(idx);
  // 자식 노드가 둘 다 존재한다면,
  else
  {
    // 오른쪽 자식 노드의 우선순위가 높다면
    if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
      // 오른쪽 자식 노드의 인덱스 값 반환
      return GetRChildIDX(idx);
    // 왼쪽 자식 노드의 우선순위가 높다면
    else
      // 왼쪽 자식 노드의 인덱스 값 반환
      return GetLChildIDX(idx);
  }
}