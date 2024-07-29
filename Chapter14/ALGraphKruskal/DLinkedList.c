#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
  plist->head = (Node*)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  newNode->next = plist->head->next;
  plist->head->next = newNode;

  (plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
  Node * newNode = (Node*)malloc(sizeof(Node));
  Node * pred = plist->head;
  newNode->data = data;

  while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
  {
    pred = pred->next;
  }

  newNode->next = pred->next;
  pred->next = newNode;

  (plist->numOfData)++;
}