void SelectionSort(int arr[], int n)
{
  int i, j;
  int maxIdx;
  int tepm;

  for(i = 0; i< n - 1; i++)
  {
    maxIdx = i;

    for(j = i + 1; j < n ; j++)
    {
      if(arr[j] < arr[maxIdx])
        maxIdx = j;// 스캔해가며 최솟값 탐색. 
    }
    temp = arr[i];
    arr[i] = arr[maxIdx];
    arr[maxIdx] = temp;
  }
}

int main(void)
{
  int arr[4] = {3, 4, 2, 1}
  int i; 
  SelectionSort(arr, sizeof(arr) / sizeof(int));

  for(i = 0; i < 4; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}