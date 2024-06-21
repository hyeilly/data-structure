int GetOpPrec(char op) // 연산자의 연산 우선순위 정보를 반환
{
  // 숫자는 임의로 정한 것. 우선순위 판단을 위해 대소 비교 하도록 정의 
  
// 연산자의 우선순위에 대응하는 값을 반환. 값이 클 수록 우선순위 높음
// (연산자는 )연산자가 증장할 때까지 쟁반에 남아 있어야하기 때문에 가장 낮은 우선순위 부여
  switch(op)
  {
    case '*':
    case '/':
      return 5; // 가장 높은 연산자의 우선순위
    case '+':
    case '-':
      return 3;
    case '(':
      return 1;
  }
  return -1; // 등록되지 않은 연산자임을 알림
}

// 두 연산자의 우선순위 비교 결과를 반환
int WhoPrecOp(char op1, char op2)
{
  int op1Prec = GetOpPrec(op1);
  int op2Prec = GetOpPrec(op2);
  if(op1Prec > op2Prec) // op1 우선순위 더 높음
    return 1;
  else if(op1Prec < op2Prec) // op2 우선순위 더 높음
    return -1;
  else // 두개 우선순위 같음
    return 0;
}

