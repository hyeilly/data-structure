#include <stdio.h>

typedef struct _empInfo
{
    int empNum; // 직원의 고유번호(key)
    int age; // 직원의 나이(value)
} EmpInfo;

int main(void)
{
    EmpInfo empInfoArr[1000];

    EmpInfo ei;
    int eNum;

    printf("사번과 나이 입력: ");
    scanf("%d %d", &(ei.empNum), &(ei.age));
    // key에 해당하는 직원의 고유번호를 배열의 인덱스 값으로 활용하여 단번에 저장 가능
    empInfoArr[ei.empNum] = ei;
    
    printf("확인하고싶은 직원의 사번 입럭: ");
    scanf("%d", &eNum);

    ei = empInfoArr[eNum]; // 단번에 탐색!
    pritnf("사번 %d, 나이 %d \n", ei.empNum, ei.age);
    return 0;
}