void HanoiTowerMove(int num, char from, char by, char to)
{
  // 원반 num의 수에 해당하는 원반을 from 에서 to로 이동시키되 그 과정에서 by 사용
  if(num == 1) // 이동할 원반의 수가 1개라면 
  {
    printf("원반1을 %c에서 %c로 이동 \n", from, to);
  }
  else
  {
    HanoiTowerMove(num - 1, from, to, by);
    printf("원반%d을 %c에서 %c로 이동 \n", num, from, to);
    HanoiTowerMove(num - 1, by, from, to);
  }
}

int main(void)
{
  // 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
  HanoiTowerMove(3, 'A', 'B', 'C');
  return 0;
}