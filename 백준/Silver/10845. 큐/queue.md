# C++ STL: `queue` 정리

`queue`는 선입선출(First-In-First-Out, FIFO) 방식의 컨테이너 어댑터입니다. 가장 먼저 들어온 데이터가 가장 먼저 나갑니다.

---

## 📁 헤더

```cpp
#include <queue>
```

---

## 🛠️ 기본 사용법

```cpp
queue<int> q;

q.push(10);     // 뒤에 삽입
q.push(20);
q.pop();        // 앞에서 제거 (10 제거)

cout << q.front(); // 20
```

---

## ⚙️ 주요 멤버 함수

| 함수        | 설명                              |
| ----------- | --------------------------------- |
| `push(val)` | 큐 뒤에 요소 삽입                 |
| `pop()`     | 큐 앞 요소 제거                   |
| `front()`   | 큐 앞 요소 참조                   |
| `back()`    | 큐 뒤 요소 참조                   |
| `empty()`   | 큐가 비었는지 확인 (`true/false`) |
| `size()`    | 큐에 포함된 요소 개수 반환        |

---

## 🧾 예시

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<string> q;
  q.push("apple");
  q.push("banana");
  q.push("cherry");

  while (!q.empty()) {
    cout << q.front() << '\n';
    q.pop();
  }
}
```

**출력:**

```
apple
banana
cherry
```

---

## 📌 특징

- **선입선출 구조 (FIFO)**
- 내부적으로 `deque`를 기반으로 구현됨
- 임의 접근 불가능 (`q[1]` 불가)
- 반복자 사용 불가 (`begin()`, `end()` 없음)
- 삽입/삭제는 항상 양 끝(front/back)에서만 가능

---

## 💡 팁

- `queue`는 반복문으로 순회하려면 `pop()`을 사용해 직접 제거하며 접근해야 함
- 큐에 남은 데이터를 확인만 하고 싶을 땐 `front()`만 사용
- 반복자 필요 시 `deque` 또는 `list`를 사용하는 것이 적절함

---

## 🧷 요약

- `std::queue`는 FIFO 방식의 컨테이너 어댑터
- `push`, `pop`, `front`, `back` 등 핵심 함수만 제공
- 반복자, 인덱스 접근 불가
- 순차적인 데이터 처리, 이벤트 큐 등에 적합
