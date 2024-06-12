int main(void)
{
  List list;
  Point compPos;
  Point * ppos;

  ListInit(&list);

  // 4개의 주소값 데이터 저장
  ppos = (Point*)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 1);
  LInsert(&list, ppos);

  ppos = (Point*)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 2);
  LInsert(&list, ppos);

  ppos = (Point*)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 1);
  LInsert(&list, ppos);

  ppos = (Point*)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 2);
  LInsert(&list, ppos);

  // 저장된 데이터의 출력
  printf("현재 데이터의 수: %d \n", LCount(&list));

  if(LFirst(&list, &ppos))
  {
    ShowPointPos(ppos);
    while(LNext(&list, &ppos))
      ShowPointPos(ppos);
  }
  printf("\n");

  // xpos가 2인 모든 데이터의 삭제
  compPos.xpos = 2;
  compPos.ypos = 0;

  if(LFirst(&list, &ppos)){
    if(PointComp(ppos, &compPos) == 1){
      ppos = LRemove(&list); // 동적할당한 메모리까지 소멸되진 않음
      free(ppos);
    }
    while(LNext(&list, &ppos)){
      if(PointComp(ppos, &compPos) == 1){
        ppos = LRemove(&list);
        free(ppos);
      }
    }
  }
}