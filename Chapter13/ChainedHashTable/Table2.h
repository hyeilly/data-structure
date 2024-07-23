#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL   100

typedef int HashFunc(Key k);

typedef struct _table
{
  // 연결리스트 기반이므로.
  // 해시 값 별로 연결리스트 구성 필요
  // 노드의 데이터 부분이 슬롯이 되게함. => 연결 리스트를 그대로 활용하는 좋은 모델
  List tbl[MAX_TBL];
  HashFunc * hf;
} Table;

// 테이블의 초기화
void TBLInit(Table * pt, HashFunc * f);
// 테이블에 키와 값을 저장
void TBLInsert(Table * pt, Key k, Value v);
// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table * pt, Key k);
// 키를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table * pt, Key k);

#endif