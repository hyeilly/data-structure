void ConvToRPNExp(char exp[])
{
  Stack stack;
  int expLen = strlen(exp);
  char * convExp = (char*)malloc(expLen + 1); // 변환된 수식을 담을 공간 마련
  int i, idx = 0;
  char tok, popOp;
  memset(convExp, 0, sizeof(char)*expLen + 1); // 마련한 공간 0으로 초기화
  StackInit(&stack);
  for(i = 0; i<expLen;i++){
    // 일련의 변환 과정을 이 반복문 안에서 수행
    tok = exp[i];
    if(isdigit(tok)) // 10진수인지 먼저 확인
    {
      convExp[idx++] = tok;
    }
    else
    {
      // tok에 저장된 문자가 연산자라면
      switch(tok)
      {
        // 연산자일때의 처리 루틴을 switch 문에 담음
        case '(':
          SPush(&stack, tok); // 스택에 쌓기
          break;
        case ')': // 닫는 소괄호는 전부다 빼서 원위치 
          while(1)
          {
            popOp = SPop(&stack); // 스택에서 연산자를 꺼내어,
            if(popOp == '(')
              break;
            convExp[idx++] = popOp; // 배열에 convExp 에 저장
          }
          break;
        case '+': 
        case '-':
        case '*':
        case '/':
          while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
            // 우선순위가 같다면 먼저 들어온 것이 우선순위가 더 높음
            convExp[idx++] = SPop(&stack);
          SPush(&stack, tok);
          break;
      }
    }
  }
  while(!SIsEmpty(&stack))
    convExp[idx++] = SPop(&stack); // 스택에 남아 있는 모든 연산자를 이동시키는 반복문
  strcpy(exp, convExp); // 변환된 수식 반환
  free(convExp);
}

int main(void)
{
  char exp[] = "3-2+4"; // 중위 표기법 수식을 배열에 담아 함수의 인자로 전달
  ConvToRPNExp(exp); // 호출 완료 후 exp에는 변환된 수식이 담김 
}