#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
  int temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
  int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽 
  int low = left + 1;
  int high = right;

  // 교차되지 않을 때까지 반복. 항상 '참'일 수 밖에 없는 상황! 
  while(low <= high) 
  {
    // 피벗보다 큰 값을 찾는 과정(경계 검사도 추가되어야함)
    while(pivot >= arr[low] && low <= right) 
      low ++; // low를 오른쪽으로 이동
    // 피벗보다 작은 값을 찾는 과정
    while(pivot <= arr[high] && high >= (left + 1)) 
      high--; // high를 왼쪽으로 이동
    // 교차되지 않은 상태라면 Swap 실행
    if(low <= high)
      Swap(arr, low, high);
  }
  Swap(arr, left, high); // 피벗과 high가 가리키는 대상 교환
  return high; // 옮겨진 피벗의 위치정보 반환
}

void QuickSort(int arr[], int left, int right)
{
  if(left <= right)
  {
    int pivot = Partition(arr, left, right); // 둘로 나눠서
    QuickSort(arr, left, pivot-1); // 왼쪽 영역을 정렬
    QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬
  }
}

int main(void)
{
  int arr[3] = {3, 3, 3};
  
  int len = sizeof(arr) / sizeof(int);
  int i;

  QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

  for(i=0; i<len; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}