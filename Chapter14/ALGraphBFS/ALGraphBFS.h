#ifndef __AL_GRAPH_BFS__
#define __AL_GRAPH_BFS__

#include "DlinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J }; // 정점의 이름들을 상수화

typedef struct _ual
{
  int numV; // 정점의 수
  int numE; // 간선의 수
  List * adjList; // 간선의 정보
  int * visitInfo;
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 그래프의 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// 그래프의 모든 정점 정보를 출력하는 함수
// BFS를 기반으로 정의가 된 함수 
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif