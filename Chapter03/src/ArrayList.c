#include<stdio.h>
#include "../header/ArrayList.h"

void ListInit(List * plist)
{
  // 구조체 변수 선언
  // 인자로 전달되면 초기화 실행
  // LFirst와 LNext를 어떻게 정의하느냐에 따라 초기화 달라질 수 있음
  (plist->numOfData) = 0;
  (plist->curPosition) = -1; // -1은 아무런 위치도 참조하지 않았음을 의미
}

void LInsert(List * plist, LData data)
{
  if(plist->numOfData > LIST_LEN) // 더이상 저장할 공간이 없다면
  {
    puts("저장이 불가능함");
    return;
  }
  plist->arr[plist->numOfData] = data; // 데이터 저장
  (plist->numOfData)++; // 저장된 데이터의 수 증가
}

int LFirst(List * plist, LData * pdata)
{
  if(plist->numOfData == 0) // 저장된 데이터가 하나도 없다면
    return FALSE
  // 0번째 인덱스에 있는 값까지 참조를 했다
  (plist->curPosition) = 0; // 참조 위치 초기화! 첫 번째 데이터의 참조 의미
  *pdata = plist->arr[0]; // pdata가 가리키는 공간에 데이터 저장
  return TRUE;
}

int LNext(List * plist, LData * pdata)
{
  if(plist->curPosition >= (plist->numOfData)-1) // 저장된 데이터가 하나도 없다면
    return FALSE
  (plist->curPosition)++; // 참조 위치 초기화! 첫 번째 데이터의 참조 의미
  *pdata = plist->arr[plist->curPosition]; // pdata가 가리키는 공간에 데이터 저장
  return TRUE;
}