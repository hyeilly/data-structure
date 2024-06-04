#include<stdio.h>
int LSearch(int arr[], int len, int target);

int main(){
  int arr[3] = {1, 2, 3};
  int result = 0;
  result = LSearch(arr, 3, 3);
  printf("%d\n", result);
  return 0;
}

// 순차 탐색 알고리즘 적용된 함수
int LSearch(int arr[], int len, int target){
  int i;
  for(i = 0; i < len; i++){
    if(arr[i] == target){
      // 찾은 대상의 인덱스 값 반환
      return i;
    }else{
      // 찾지 못했음을 의미하는 반환
      continue;
    }
  };
  return i;
}