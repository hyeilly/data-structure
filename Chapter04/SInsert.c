void SInsert(List * plist, LData data)
{
  // 새 노드 생성 후 pred DMY를 가리킴. 
  Node * newNode = (Node*)malloc(sizeof(Node));
  Node * pred = plist->head;
  newNode->data = data;

  // 새 노드가 들어갈 위치를 찾기 위한 반복문
  while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
  {
    pred = pred->next; // 다음 노드로 이동
  }
  newNode->next = pred->next;
  pred->next = newNode;
  (plist->numOfData)++;
}

// head->DMY->2->4->6 
// SInsert(&slit, 5)