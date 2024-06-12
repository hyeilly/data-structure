#include "Point.h"

// 매크로 선언 
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE    1
#define FALSE   0

// ArrayList의 정의
#define LIST_LEN    100
typedef Point * LData; // 저장할 대상의 자료형 변경을 위한 typedef 선언

typedef struct __ArrayList // 배열기반 리스트를 정의한 구조체
{
  LData arr[LIST_LEN]; // 리스트의 저장소인 배열
  int numOfData; // 저장된 데이터의 수
  int curPosition; // 데이터 참조위치를 기록
} ArrayList; // 배열 기반 리스트를 의미하는 구조체

// ArrayList와 관련된 연산들
typedef ArrayList List; // 리스트의 변경을 용이하게 하기 위한 typedef 선언 

void ListInit(List * plist); // 초기화
void LInsert(List * plist, Ldata data); // 데이터 저장

int LFirst(List * plist, LData * pdata); // 첫 데이터 참조
int LNext(List * plist, LData * pdata); // 두 번째 이후 데이터 참조

LData LRemove(List * plist); // 참조한 데이터 삭제
int LCount(List * plist); // 저장된 데이터의 수 반환

#endif