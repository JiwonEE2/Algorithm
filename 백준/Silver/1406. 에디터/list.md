# C++ `std::list` 요약 정리

---

## 📁 헤더

```cpp
#include <list>
```

- `std::list`는 이중 연결 리스트(doubly linked list) 컨테이너입니다.  
- 삽입/삭제에 최적화되어 있으며 임의 접근은 지원하지 않습니다.

---

## 🛠️ 기본 사용법

```cpp
list<int> lst = {1, 2, 3};
lst.push_back(4);
lst.push_front(0);
```

- 앞뒤로 빠르게 삽입/삭제 가능  
- `push_front`, `push_back`, `pop_front`, `pop_back` 사용 가능

---

## ⚙️ 특징

- 이중 연결 리스트  
- 임의 접근 불가 (`lst[2]` X)  
- 반복자: Bidirectional Iterator 사용  
- 중간 삽입/삭제 효율적 (`insert`, `erase`)

---

## 🔁 반복자와 함께 사용

```cpp
list<int> lst = {10, 20, 30};

// 기본 반복자
for (auto it = lst.begin(); it != lst.end(); ++it) {
  cout << *it << ' ';
}

// 역순 반복자
for (auto rit = lst.rbegin(); rit != lst.rend(); ++rit) {
  cout << *rit << ' ';
}
```

- `list`는 `Bidirectional Iterator` 지원 → `++`, `--` 가능  
- `std::advance`, `std::next`, `std::prev`와 함께 사용 가능

---

## 🧾 예시

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> lst = {1, 2, 3};

  auto it = lst.begin();
  ++it;                 // 2
  lst.insert(it, 100);  // 1 100 2 3

  for (auto x : lst)
    cout << x << ' ';
}
```

---

## 💡 팁

- `list`는 중간 삽입/삭제에 매우 효율적  
- 반복자 무효화 문제에 강함 (삭제 시 주의)  
- `auto` 사용으로 반복자 선언 간소화  
- `std::list<T>::iterator`는 `vector`처럼 랜덤 접근 불가

---

## 🧷 요약

- `std::list`는 이중 연결 리스트 컨테이너  
- 앞뒤 삽입/삭제에 최적화, 랜덤 접근 불가  
- 반복자는 Bidirectional Iterator → `++`, `--` 가능  
- `insert`, `erase`와 반복자 조합 필수 사용  
- `auto`, 범위 기반 for문으로 반복 간소화 가능
---
