int LSearch(int ar[], int len, int target)
{
  int i;
  // 주변에 존재하는 연산자 연산 횟수는 중심이 되는 연산자의 연산 횟수에 의존적임
  for(i = 0; i<len; i++){
    if(ar[i] == target){
      return i;
    }
  }
  return -1;
}