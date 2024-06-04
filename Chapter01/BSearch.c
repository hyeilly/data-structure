// 이진 탐색 알고리즘의 구현
#include<stdio.h>


int BSearch(int arr[], int len, int target);

int main(){
  int arr[3] = {1, 2, 3};
  int result = 0;
  result = BSearch(arr, 3, 3);
  printf("%d\n", result);
  return 0;
  
}

int BSearch(int arr[], int len, int target){
  int first = 0; // 탐색 대상의 시작 인덱스 값
  int last = len - 1; // 탐색 대상의 마지막 인덱스 값
  int mid;
  while(first <= last){
    mid = (first + last) / 2; // 탐색 대상의 중앙을 찾음
    if(target == arr[mid]) // 중앙에 저장된 것이 타겟
    {
      return mid; // 탐색 완료
    }
    else // 타겟이 아니라면 탐색 대상을 반으로 줄임
    {
      if(target < arr[mid])
        last = mid - 1;
      else
        first = mid + 1;
    }
  }
  return -1; // 찾지 못했을 때 반환되는 값 
}