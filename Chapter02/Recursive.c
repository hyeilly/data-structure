void Recursive(int num)
{
  if(num <= 0) // 재귀의 탈출 조건
    return; // 재귀의 탈출!
  printf("Recursive call!! %d \n", num);
  Recursive(num - 1);
}

int main(void)
{
  Recursive(3);
  return 0;
}