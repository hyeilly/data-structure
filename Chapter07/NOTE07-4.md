## 큐의 활용

### 시뮬레이션 주제

- 점심시간 1시간 동안에는 고객이 15초당 1명씩 주문
- 종류별 햄버거를 만드는데 걸리는 시간 - 치즈버거 12초, 불고기버거 15초, 더블버거 24초
- 이 상황에서 대기실의 크기를 결정하는데 필요한 정보를 추출하는 것이 목적
  - 수용인원이 30명인 공간 - 안정적으로 고객을 수용할 확률 50%
  - 수용인원이 50명인 공간 - 안정적으로 고객을 수용할 확률 70%
  - 수용인원이 100명인 공간 - 안정적으로 고객을 수용할 확률 90%
  - 수용인원이 200명인 공간 - 안정적으로 고객을 수용할 확률 100%

### 시뮬레이션 예제

- 점심시간 1시간, 고객은 15초에 1명씩 주문하는 것으로 간주
- 한 명의 고객은 하나의 버거 만을 주문
- 주문하는 메뉴는 가중치 두지 않음. 모든 고객은 무작위로 메뉴 선택
- 햄버거 만드는 사람은 1명, 동시에 둘 이상의 버거 만들어지지 않음
- 주문한 메뉴 받을 다음 고객은 대기실에서 나와서 대기
