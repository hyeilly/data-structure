#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv)
{
  int i;
  
  pg->adjList = (List*)malloc(sizeof(List)*nv);
  pg->numV = nv;
  pg->numE = 0;

  for(i = 0; i < nv; i++)
  {
    ListInit(&(pg->adjList[i]));
    SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
  }
  // 정점의 수를 길이로 하여 배열을 할당
  pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
  // 배열의 모든 요소를 0으로 초기화
  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph * pg)
{
  if(pg->adjList != NULL)
    free(pg->adjList);
  // 할당된 배열의 소멸 
  if(pg->visitInfo != NULL)
    free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
  LInsert(&(pg->adjList[fromV]), toV);
  LInsert(&(pg->adjList[toV]), fromV);
  pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
  int i;
  int vx;

  for(i=0; i < pg->numV; i++)
  {
    printf("%c : ", i + 65);

    if(LFirst(&(pg->adjList[i]), &vx))
    {
      printf("%c ", vx + 65);

      while(LNext(&(pg->adjList[i]), &vx))
        printf("%c ", vx + 65);
    }
    printf("\n")
  }
}

int WhoIsPrecede(int data1, int data2)
{
  if(data1 < data2)
    return 0;
  else
    return 1;
}
// 방문한 정점의 정보를 기록 및 출력
int VisitVertex(ALGraph * pg, int visitV)
{
  if(pg->visitInfo[visitV] == 0) // visitV에 처음 방문일 때 '참'인 if 문
  {
    pg->visitInfo[visitV] = 1; // visitV에 방문한 것으로 기록
    printf("%c", visitV + 65); // 방문한 정점의 이름을 출력
    return TRUE; // 방문 성공
  }
  return FALSE; // 방문 실패
}

void DFShowGraphVertex(ALGraph * pg, int startV)
{
  Stack stack;
  int visitV = startV;
  int nextV;

  StackInit(&stack);
  // 초기화 끝남과 동시에 시작 정점 방문 
  VisitVertex(pg, visitV); // 방문한 정점의 정보를 그래프의 멤버 visitInfo 가 가리키는 배열에 등록하는 기능 제공
  SPush(&stack, visitV);

  // 정점에 연결된 vertex 정보들이 연결리스트로 연결
  while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
  { // 연결된 정점의 정보를 얻음 
    int visitFlag = FALSE;
    // 방문을 시도했는데 방문 성공
    if(VisitVertex(pg, nextV) == TRUE)
    {
      // 방문한 정점을 떠나야하니 해당 정보 스택으로 
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = TRUE;
    }
    // 방문을 시도했는데 방문한 적이 있는 곳이라면 
    else
    {
      // 연결된 다른 정점을 찾아서 방문 시도
      while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
      {
        if(VisitVertex(pg, nextV) == TRUE)
        {
          SPush(&stack, visitV);
          visitV = nextV;
          visitFlag = TRUE;
          break;
        }
      }
    }
    // 연결된 정점과의 방문이 모두 완료되었다면
    if(visitFlag == FALSE)
    {
      if(SIsEmpty(&stack) == TRUE)
        // 스택이 비면 종료
        break; 
      else
        // 되돌아가기 위한 POP 연산
        visitV = SPop(&stack);
    }
  }
  memset(pg->visitInfo, 0, sizeof(int) & pg->numV)
}