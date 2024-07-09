#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
  int fIdx = left;
  int rIdx = mid + 1;
  int i;

  int * sortArr = (int*)malloc(sizeof(int) * (right + 1)); // 병합 결과를 담을 메모리 공간 할당
  int sIdx = left;

  // 병합할 두 영역의 데이터를 비교하여 배열 sortArr에 담음
  while(fIdx <= mid && rIdx <= right)
  {
    if(arr[fIdx] <= arr[rIdx])
      sortArr[sIdx] = arr[fIdx++];
    else
      sortArr[sIdx] = arr[rIdx++];
    
    sIdx++;
  }
  
  // 배열의 앞 부분이 sortArr로 모두 이동되어서 배열 뒷부분에 남은 데이터를 모두 sortArr로 이동
  if(fIdx > mid)
  {
    for(i = rIdx; i <= right; i++, sIdx++)
      sortArr[sIdx] = arr[i];
  }
  // 배열의 뒷 부분이 sortArr로 모두 이동되어서 배열 앞부분에 남은 데이터를 모두 sortArr로 이동
  else
  {
    for(i = fIdx; i <= mid; i++, sIdx++)
      sortArr[sIdx] = arr[i];
  }
  
  // 병합 결과를 옮겨 담음
  // (rIdx가 끝까지 갔지만, fIdx가 더 안간다면 차례대로 남아있는 데이터 옮기기)
  for(i = left; i <= right; i++)
    arr[i] = sortArr[i];
  // 동적 할당 메모리 공간 소멸
  free(sortArr);
}

// 둘로 나눌 수 없을 때까지 재귀적으로 호출 

void MergeSort(int arr[], int left, int right)
{
  int mid;
// left가 작다는 것은 더 나눌 수 있다는 뜻
// 데이터 2개 인덱스 0, 1. 데이터가 한개만 남은 경우 left right 모두 0 =>함수 종료
  if(left < right) 
  {
    // 2개로 나누어서 중간지점을 계산 
    mid = (left + right) / 2;

    // 둘로 나눠서 각각을 정렬
    MergeSort(arr, left, mid); // left ~ mid에 위치한 데이터 정렬
    MergeSort(arr, mid + 1, right); // mid + 1 ~ right 에 위치한 데이터 정렬

    // 정렬된 두 배열을 병합
    MergeTwoArea(arr, left, mid, right); 
  }
}

int main(void)
{
  int arr[7] = {3, 2, 4, 1, 7, 6, 5};
  int i;

  MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

  for(i = 0; i < 7; i++)
    printf("%d ", arr[i]);
  
  printf("\n");
  return 0;
}