#include <stdio.h>
#include "../header/ArrayList.h"

int main(void)
{
  // Array List 의 생성 및 초기화
  List list; // 리스트의 생성. (리스트형 변수의 선언)
  int data;
  ListInit(&list); // 리스트의 초기화

  // 5개의 데이터 저장
  LInsert(&list, 11);
  LInsert(&list, 11);
  LInsert(&list, 22);
  LInsert(&list, 22);
  LInsert(&list, 33);

  // 저장된 데이터의 전체 출력
  printf("현재 데이터의 수: %d \n", LCount(&list));

  // 데이터 참조의 새로운 시작을 위해서 LFirst 함수의 호출을 요구
  if (LFirst(&list, &data)) // 첫 번째 데이터 조회
  {
    printf("%d ", data);
    while (LNext(&list, &data)) // 두 번째 이후의 데이터 조회
    {
      printf("%d ", data)
    }
  }
  print("\n\n");
  // 숫자 22를 탐색하여 모두 삭제
  if(LFirst(&list, &data))
  {
    if(data == 22)
    {
      LRemove(&list); // 위의 LFirst함수를 통해 참조한 데이터 삭제!
    }
    while(LNext(&list, &data))
    {
      if(data == 22)
      {
        LRemove(&list); // 위의 LNext 함수를 통해 참조한 데이터 삭제
      }
    }
  }
}