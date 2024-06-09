int BSearchRecur(int ar[], int first, int last, int target)
{
  int mid;
  if(first > last) // first와 last는 각각 탐색의 시작과 끝을 나타내는 변수
    return -1; // -1 반환은 탐색의 실패를 의미
  
  mid = (first + last) / 2; // 탐색의 대상에서 중심에 해당하는 인덱스 값 계산
  if(ar[mid] == target)
    return mid;
  else if (target < ar[mid])
    // 앞부분을 대상으로 재 탐색
    return BSearchRecur(ar, first, mid - 1, target);
  else
    // 뒷부분을 대상으로 재 탐색
    return BSearchRecur(ar, mid + 1, last, target);
}