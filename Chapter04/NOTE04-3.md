## 연결 리스트의 정렬 삽입의 구현

- 메인함수에서 선언한 리스트에 정렬 기준이 되는 것을 설정
  - 등록된 정보(=함수) 새로운 데이터를 저장하는 과정에서 함수 호출 통해 데이터 저장될 위치를 찾아 정렬된 상태로 노드 추가

### 정렬기준 설정과 관련된 부분

- 단순 연결 리스트의 정렬 관련 요소 세 가지

  1. 정렬기준이 되는 함수를 등록하는 SetSortRule 함수
  2. SetSortRule 함수 통해 전달된 함수정보 저장을 위한 LinkedList의 멤버 comp(정의한 멤버 comp의 초기화를 담당)
  3. comp에 등록된 정렬기준을 근거로 데이터를 저장하는 SInsert 함수
     => SetSortRule함수가 호출되면서 정렬의 기준이 리스트의 멤버 comp에 등록되면, SInsert 함수 내에서는 comp에 등록된 정렬의 기준을 근거로 데이터를 정렬하여 저장

- comp에 등록할 함수의 정의 기준, SInsert에서 어떻게 활용이 되는가

### SetSortRule 함수와 멤버 comp

1. SetSortRule 함수의 호출을 통해

```
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
  plist->comp = comp;
}
```

2. 멤버 comp가 초기화되면

```
typedef struct _linkedList
{
  ...
  int (*comp)(LData d1, LData d2);
} LinkedList;
```

3. 정렬 관련 SInsert 함수가 호출

```
void LInsert(List * plist, LData data)
{
  if(plist->comp == NULL)
    FInsert(plist, data);
  else
    SInsert(plist, data);
}
```

### SInsert

- 새로 생성된 노드를 어디에 저장할 것인지

  - 현재 존재하는 노드들과 값을 비교해야함.
  - pred 는 처음 DMY를 가리킴.
  - DMY노드와 노드 사이에 저장을 위해서는 DMY 주소값과 노드 주소값 가져와야함

- 새 노드가 들어갈 위치를 찾기 위한 반복문

  - `pred->next != NULL`은 더이상 찾아갈 노드가 없는 경우 => 연결리스트의 끝
    - pred가 리스트의 마지막 노드를 가리키는지 묻기 위한 연산
  - `plist->comp(data, pred->next->data) != 0`
    - comp (정렬 기준으로 등록된 함수) 호출하며 pred 다음 노드의 data
      - comp가 0을 반환한다는 것은 첫 번째 인자인 data가 정렬 순서상 앞서기 때문에 head에 가까워야한다는 의미
    - 0이 아닌 값을 반환 시 pred는 다음 노드로 계속 이동
    - 0을 가리키면 pred가 가리키는 노드와 다음 노드 사이에 새 노드를 추가해야함
    - 새 데이터와 pred의 다음 노드에 저장된 데이터의 우선순위 비교를 위한 함수호출

- comp 의 반환값과 그 의미 정리
  - comp가 0을 반환
    - 첫 번째 인자인 data가 정렬 순서상 앞서서 head에 가까워야 하는 경우
  - comp가 1을 반환
    - 두 번째 인자인 pred->next->data가 정렬 순서상 앞서서 head에 더 가까워야 하는 경우
