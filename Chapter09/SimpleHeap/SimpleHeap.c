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

// 삭제 과정에서는 완전 이진트리로 쓰지 않음 
HData HDelete(Heap * ph)
{
  // 인덱스는 1 => 
  HData retData = (ph->heapArr[1]).data; // 반환을 위해서 삭제할 데이터 저장
  HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장
  
  // 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담김
  int parentIdx = 1; // 루트 노드가 위치해야 할 인덱스 값 저장
  int childIdx;

  // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
  while(childIdx = GetHiPriChildIDX(ph, parentIdx))
  {
    if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
      break; // 마지막 노드의 우선순위가 높으면 반복문 탈출
    
    // 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 올림
    ph->heapArr[parentIdx] = ph->heapArr[childIdx];
    // 마지막 노드가 저장될 위치정보를 한 레벨 내림
    parentIdx = childIdx;
  } // 반복문 탈출하면 parentIdx에는 마지막 노드의 위치정보가 저장됨
  ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
  ph->numOfData -= 1;
  return retData;
}