#include <stdio.h>
#include<stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
  // F와 R이 같은 위치를 가리킴 - empty 정의
  pq->front = 0;
  pq->rear = 0;
  // ex) 배열의 길이가 3이상이라 가정 시 1이나 2를 저장
  // 같은 값으로 정의만 하면 상관없음
  // F, R 이 첫번째 요소를 가리켜도 빈 상태 => 회전하므로 어디서 시작을 해도 ok
}

void QIsEmpty(Queue * pq)
{
  if(pq->front == pq->rear)
    return TRUE;
  else
    return FALSE;
}

int NextPosIdx(int pos)
{
  // 배열의 마지막 요소의 인덱스 값. F나 R이 배열 첫번째 요소 인덱스 값을 갖도록 정의 
  if(pos == QUE_LEN - 1) 
    return 0;
  else
    return pos + 1;
}

// 꽉 찼는지 아닌지 확인
void Enqueue(Queue * pq, Data data)
{
  // rear을 이동시키고 (NextPostIdx 함수의 호출을 통해), 그 위치에 데이터 저장
  // R이 다음 위치를 얻게됨 (인덱스)
  if(NextPosIdx(pq->rear) == pq->front)
  {
    printf("Queue Memory Error!");
    exit(-1); // 꽉 찬 경우 라는 것을 간단하게 구현하기 이ㅜ해 
  }
  pq->rear = NextPosIdx(pq->rear);
  pq->queArr[pq->rear] = data;
}

void Dequeue(Queue * pq)
{
  // front를 이동시키고 (NextPosIdx 함수의 호출을 통해) 그위치의 데이터 반환.
  if(QIsEmpty(pq))
  {
    printf("Queue Memory Error!");
    exit(-1);
  }
  pq->front = NextPosIdx(pq->front);
  return pq->queArr[pq->front];
}
// Enqueue 연산과 Dequeue연산 모두 rear와 front를 우선 이동시키는 구조

Data QPeek(Queue * pq)
{
  if(QIsEmpty(pq))
  {
    printf("Queue Memory Error!");
    exit(-1);
  }
  return pq->queArr[NextPosIdx(pq->front)];
}