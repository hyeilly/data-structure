#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

// 정점의 이름들을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
  int numV; // 정점의 수
  int numE; // 간선의 수
  List * adjList; // 간선의 정보
  int * visitInfo; // 탐색과정에서 탐색이 진행된 정점 정보를 담기 위한 멤버 추가
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// 그래프의 모든 정점 정보를 출력하는 함수
// DFS를 기반으로 정의가 된 함수
// 정점의 정보 출력 DFS 기반
void DFShowGraphVertex(ALGraph * pg, int startV);

#endif
