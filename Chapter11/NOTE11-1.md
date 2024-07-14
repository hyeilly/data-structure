# 탐색의 이해와 보간 탐색

## 탐색의 이해

- 효율적인 탐색을 위해서 저장방법을 고민하기
- 효율적인 탐색이 가능한 대표적인 자료구조는 이진트리

## 보간 탐색

- 이진 탐색과 보간 탐색 모두 정렬이 완료된 데이터를 대상으로 탐색을 진행하는 알고리즘
- 배열을 대상으로 정수 12를 찾는다고 가정
  - 알고리즘 별 탐색 위치의 선택 방법
  - [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
    - 이진 탐색 : 무조건 중간에 위치한 데이터를 탐색의 위치로 결정
    - 보간 탐색 : 대상에 비례하여 탐색의 위치를 결정(정렬이 되어있을 때)
  - 보간 탐색은 단번에 탐색 대상을 찾을 확률이 어느 정도 존재

### 보간 탐색: 비례식 구성

- 탐색 대상이 저장된 인덱스 값 S
- low, high 는 시작과 끝의 인덱스 값
- [10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
  - 10이 low로 지정, 30이 high로 지정
  - s - low `Q = arr[s] - arr[low]`
  - high - low `A = arr[high] - arr[low]`
- 비례식 구성
  1. A:Q = (high - low) : (s - low)
  2. s = Q / A (high - low) + low
  3. `s = x - arr[low] / arr[high] - arr[low] (high - low) + low`
     탐색 위치의 인덱스 값 계산식(x는 내가 찾고자 하는 값)
- 보간 탐색

  ```
  int BSearchRecur(int ar[], int first, int last, int target)
  {
    int mid;
    if(first > last)
      return -1;
    mid = ((double)(target-ar[first]) / ar[last] - ar[first]) * (last-first)) + first;

    if(ar[mid] == target)
      return mid;
    else if(target < ar[mid])
      return BSearchRecur(ar, first, mid - 1, target);
    else
      return BSearchRecur(ar, mid + 1, last, target);
  }
  ```

### 탐색 키와 탐색 데이터

```
typedef Key int; // 탐색 키에 대한 typedef 선언
typedef Data double; // 탐색 데이터에 대한 typedef 선언
typedef struct item
{
  Key searchKey; // 탐색 키(search key)
  Data searchData; // 탐색 데이터(search data)
} Item;
```

- 실제 프로그램 개발에 있어서 탐색의 대상은 '데이터'가 아닌 '키(key)'
