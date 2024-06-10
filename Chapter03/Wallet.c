int TakeOutMoney(Wallet * pw, int coinNum, int billNum); // 돈꺼내는 연산 = 연산과 관련된 함수 작성
void PutMoney(Wallet * ps, int coinNum, int billNum); // 돈 넣는 연산 = 연산과 관련된 함수 작성

typedef struct _wallet
{
  /* data */
  // 구조체와 관련한 연산들.
  int coin100Num; // 100원짜리 동전의 수
  int bill5000Num; // 5000원짜리 지폐의 수
}Wallet;


int main()
{
  Wallet myWallet; // 지갑 하나 장만 했음!
  //...
  PutMoney(&myWallet, 5, 10); // 돈을 넣는다
  //...
  ret = TakeOutMoney(&myWallet, 2, 5); // 돈을 꺼냄
  
}