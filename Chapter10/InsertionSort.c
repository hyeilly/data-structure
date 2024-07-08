#include <stdio.h>

void InsertionSort(int arr[], int n)
{
  int i, j;
  int insData;

  for(i = 1; i < n; i++) // 정렬 대상 저장
  {
    insData = arr[i];

    // 비교 대상 뒤로 한 칸 밀기 
    for(j = i - 1; j >= 0; j--)
    {
      if(arr[j] > insData)
        arr[j+1] = arr[j];
      else
        break;
    }
    // 찾은 위치에 정렬대상 삽입
    arr[j + 1] = insData;
  }
}

int main(void)
{
  int arr[5] = {5, 3, 2, 4, 1};
  int i;

  InsertionSort(arr, sizeof(arr) / sizeof(int));
  for (i=0; i<5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}