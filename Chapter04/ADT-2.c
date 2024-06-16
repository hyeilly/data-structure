int WhoIsPrecede(LData d1, LData d2) // typedef int LData;
{
  if(d1 < d2)
    return 0; // d1이 정렬 순서상 앞섬(오름차순)
  else
    return 1; // d2가 정렬 순서상 앞서거나 같음(내림차순)
}