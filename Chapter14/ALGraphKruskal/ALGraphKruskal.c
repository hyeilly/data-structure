#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

void GraphInit(ALGraph * pg, int nv)
{
  int i;
  
  pg->adjList = (List*)malloc(sizeof(List)*nv);
  pg->numV = nv;
  pg->numE = 0;

  for(i=0; i<nv; i++)
  {
    ListInit(&(pg->adjList[i]));
    SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
  }

  pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
  // 우선순위 큐의 초기화
  PQueueInit(&(pg->pqueue), PQWeightComp); // 추가된 문장 
}

void GraphDestroy(ALGraph * pg)
{
  if(pg->adjList != NULL)
    free(pg->adjList);
  
  if(pg->visitInfo != NULL)
    free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
  Edge edge = {fromV, toV, weight}; //간선의 가중치 정보를 담음

  LInsert(&(pg->adjList[fromV]), toV);
  LInsert(&(pg->adjList[toV]), fromV);
  pg->numE += 1;

  // 간선의 가중치 정보를 우선순위 큐에 저장
  PEnqueue(&(pg->pqueue), edge);
}

// 삭제된 간선을 다시 삽입
// AddEdge 함수와 달리 간선의 가중치 정보를 별도로 저장하지 않음
void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
  LInsert(&(pg->adjList[fromV]), toV);
  LInsert(&(pg->adjList[toV]), fromV);
  (pg->numE)++;
}

// 한쪽 방향의 간선 소멸
// RemoveEdge 함수 완성을 돕는 RemoveWayEdge 함수를 별도로 정의하면 방향 그래프 구현을 위한 확장 용이
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
  int edge;

  if(LFirst(&(pg->adjList[fromV]), &edge))
  {
    if(edge == toV)
    {
      LRemove(&(pg->adjList[fromV]));
      return;
    }
    while(LNext(&(pg->adjList[fromV]), &edge))
    {
      if(edge == toV)
      {
        LRemove(&(pg->adjList[fromV]));
        return;
      }
    }
  }
}

// 그래프에서 간선을 삭제
// 인접 리스트 기반 무방향 그래프인 관계로 하나의 간선을 완전히 소멸하기 위해서는 두 개의 간선 정보를 소멸시켜야함 
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
  RemoveWayEdge(pg, fromV, toV);
  RemoveWayEdge(pg, toV, fromV);
  (pg->numE)--;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
  int i;
  int vx;

  foor(i = 0; i< pg->numV; i++)
  {
    printf("%c ", i+65);

    if(LFirst(&(pg->adjList[i]), &vx))
    {
      printf("%c ", vx + 65);
      while(LNext(&(pg->adjList[i]), &vx))
        printf("%c ", vx + 65);
    }
    printf("\n");
  }
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
  PQueue copyPQ = pg->pqueue;
  Edge edge;

  while(!PQIsEmpty(&copyPQ))
  {
    edge = PDequeue(&copyPQ);
    printf("(%c-%c), w: %d \n", edge.v1+65, edge.v2+65, edge.weight);
  }
}

int WhoIsPrecede(int data1, int data2)
{
  if(data1 < data2)
    return 0;
  else
    return 1;
}

// 가중치 기준 내림차순으로 간선 정보를 꺼내기 위한 정의
int PQWeightComp(Edge d1, Edge d2)
{
  return d1.weight - d2.weight;
}

int VisitVertex(ALGraph * pg, int visitV)
{
  if(pg->visitInfo[visitV] == 0)
  {
    pg->visitInfo[visitV] = 1;
    return TRUE;
  }
  return FALSE;
}

void DFShowGraphVertex(ALGraph * pg, int startV)
{
  Stack stack;
  int visitV = startV;
  int nextV;

  StackInit(&stack);
  VisitVertex(pg, visitV);
  SPush(&stack, visitV);

  while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
  {
    int visitFlag = FALSE;

    if(VisitVertex(pg, nextV) == TRUE)
    {
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = TRUE;
    }
    else
    {
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
    if(visitFlag == FALSE)
    {
      if(SIsEmpty(&stack) == TRUE)
        break;
      else
        visitV = SPop(&stack);
    }
  }
  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 두 정점이 연결되어 있는지 확인 
// 인자로 전달된 두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
  Stack stack;
  int visitV = v1;
  int nextV;

  StackInit(&stack);
  VisitVertex(pg, visitV);
  SPush(&stack, visitV);

  while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
  {
    int visitFlag = FALSE;
    // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE 반환
    if(nextV == v2)
    {
      // 함수가 반환하기 전에 초기화 진행
      memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
      return TRUE;// 목표를 찾았으니 TRUE 반환
    }

    if(VisitVertex(pg, nextV) == TRUE)
    {
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = TRUE;
    }
    else
    {
      while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
      {
        // 정점을 돌아다니는 도중에 목표를 찾는다면 TRUE를 반환
        if(nextV == v2)
        {
          // 함수가 반환하기 전에 초기화를 진행
          memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
          return TRUE; // 목표를 찾았으니 TRUE를 반환 
        }

        if(VisitVertex(pg, nextV) == TRUE)
        {
          SPush(&stack, visitV);
          visitV = nextV;
          visitFlag = TRUE;
          break;
        }
      }
    }
    if(visitFlag == FALSE)
    {
      if(SIsEmpty(&stack) == TRUE)
        break;
      else
        visitV = SPop(&stack);
    }
  }
  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
  return FALSE; // 목표를 찾지 못함 = v2로 정점에 도달하지 못함 
}


void ConKruskalMST(ALGraph * pg) // 크루스칼 알고리즘 기반 MST 의 구성
{
  Edge RecoverEdge[20]; // 복원할 간선의 정보 저장
  Edge edge;
  int eidx = 0;
  int i;

  // MST를 형성할 때 까지 아래의 while문 반복
  while(pg->numE + 1 > pg->numV) // MST 간선의 수 + 1 == 정점의 수(최소비용 신장 트리 완성될 때까지)
  {
    // 가중치 순서대로 간선정보를 획득
    edge = PDequeue(&(pq->pqueue));
    // 획득한 정보의 간선을 실제로 삭제
    RemoveEdge(pg, edge.v1, edge.v2);
    
    // 삭제 후 두 정점 연결 경로가 있는 지 확인
    if(!IsConnVertex(pg, edge.v1, edge.v2))
    {
      // 연결 경로가 없으면 간선을 복원
      RecoverEdge(pg, edge.v1, edge.v2, edge.weight); 
      recvEdge[eidx++] = edge;
    }
  }

  // 우선순위 큐에서 삭제된 간선의 정보를 회복
  for(i = 0; i < eidx; i++)
    PEnqueue(&(pg->pqueue), recvEdge[i]);
}