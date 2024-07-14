#include <stdio.h>
int ISearch(int ar[], int first, int last, int target)
{
  int mid;

  // 탐색 대상이 없을 때 바뀌도록 작성한 코드
  // if(first > last)
  //   return -1; // -1의 반환은 탐색의 실패를 의미
  if(ar[first] > target || ar[last] < target)
    return -1;
  
  mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

  if(ar[mid] == target)
    return mid; // 탐색된 타겟의 인덱스 값 반환
  else if(target < ar[mid])
    return ISearch(ar, first, mid - 1, target);
  else
    return ISearch(ar, mid + 1, last, target); // 이전 호출과 동일한 인자 전달
}

int main(void)
{
  // 탐색 대상이 존재하지 않는 경우 오동작으로 무한 루프
  int arr[] = {1, 3, 5, 7, 9};
  int idx;
  
  idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
  if(idx == -1)
    printf("")
  else 
    printf("")
  
  idx = ISearch(arr, 0, sizeof(arr)/sizeof(int) - 1, 2);
  
  if(idx == -1)
    printf("\n");
  else
    printf("%d \n", idx);
  
  return 0;
}