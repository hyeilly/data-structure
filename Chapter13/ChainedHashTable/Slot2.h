#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key; // 주민등록번호
typedef Person * Value;

// 체이닝 기반에서는 슬롯의 상태 정보를 유지않아도 되므로 삭제
// enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
  Key key;
  Value val;
} Slot;

#endif