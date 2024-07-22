#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
  // default hash function 이 등록되어있을 수 있음
  int i;
  
  // 모든 슬롯 초기화
  for(i=0; i<MAX_TBL; i++)
    (pt->tbl[i]).status = EMPTY;

  pt->hf = f; // 해시 함수 등록
}

void TBLInsert(Table * pt, Key k, Value v)
{
  int hv = pt->hf(k); // 해시 값을 얻음 
  pt->tbl[hv].val = v;
  pt->tbl[hv].key = k;
  pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table * pt, Key k)
{
  int hv = pt->hf(k); // 해시 값을 얻음
  
  if((pt->tbl[hv]).status != INUSE)
  {
    return NULL;
  }
  else
  {
    (pt->tbl[hv]).status = DELETED;
    return (pt->tbl[hv]).val; // 삭제되는 데이터 반환
  }
}

Value TBLSearch(Table * pt, Key k)
{
  int hv = pt->hf(k);

  if((pt->tbl[hv]).status != INUSE)
    return NULL;
  else
    return (pt->tbl[hv]).val; // 탐색 대상 반환
}