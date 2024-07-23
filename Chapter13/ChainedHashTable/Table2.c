#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

// 연결 리스트 각각에 대해서 초기화를 진행
void TBLInit(Table * pt, HashFunc * f)
{
  int i;

  for(i = 0; i < MAX_TBL; i++)
    ListInit(&(pt->tbl[i]));

  pt->hf = f;
}

// 테이블에 저장되는 데이터의 키 값은 유일해야함
// 중복 여부를 확인하고 삽입을 진행
void TBLInsert(Table * pt, Key k, Value v)
{
  int hv = pt->hf(k);
  Slot ns = {k, v};

  if(TBLSearch(pt, k) != NULL) // 키가 중복되었다면(해시 값은 중복될 수 있지만 키는 중복될 수 없음)
  {
    printf("키 중복 오류 발생 \n");
    return;
  }
  else
  {
    // 해시값 기반 삽입
    LInsert(&(pt->tbl[hv]), ns);
  }
}

Value TBLDelete(Table * pt, Key k)
{
  // 해시 값 가져오기
  int hv = pt->hf(k);
  Slot cSlot;
  // 첫 번째 노드 데이터 가지고 key 비교 
  if(LFirst(&(pt->tbl[hv]), &cSlot))
  {
    // 맞다면 삭제하고 끝냄
    if(cSlot.key == k)
    {
      LRemove(&(pt->tbl[hv]));
      return cSlot.val;
    }
    else
    {
      // 키를 계속 뽑아내어 비교
      while(LNext(&(pt->tbl[hv]), &cSlot))
      {
        if(cSlot.key == k)
        {
          LRemove(&(pt->tbl[hv]));
          return cSlot.val;
        }
      }
    }
  }
  return NULL;
}


Value TBLSearch(Table * pt, Key k)
{
  // 1 해시 값 가져와서 어떤 연결리스트 찾아야할지 구분 후 
  int hv = pt->hf(k);
  Slot cSlot;

  if(LFirst(&(pt->tbl[hv]), &cSlot))
  {
    if(cSlot.key == k)
    {
      return cSlot.val;
    }
    else
    {
      while(LNext(&(pt->tbl[hv]), &cSlot))
      {
        if(cSlot.key == k)
          return cSlot.val;
      }
    }
  }
  return NULL;
}