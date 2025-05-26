# C++ STL `stack` 정리

`stack`은 **LIFO (Last In, First Out)** 구조를 따르는 컨테이너 어댑터입니다. 마지막에 넣은 요소가 가장 먼저 나옵니다. 내부적으로 기본 컨테이너로 `deque`를 사용하지만, `vector`나 `list`도 가능하게 설계되어 있습니다.

---

## 📁 헤더

```cpp
#include <stack>
```

- `stack` 사용 시 반드시 `<stack>` 헤더 포함
- 내부 컨테이너로는 `deque`가 기본이며, 다른 컨테이너로 변경 가능

---

## 🛠️ 기본 사용법

```cpp
stack<int> s;
s.push(10);     // 요소 삽입
s.push(20);
s.top();        // 최상단 요소 확인 → 20
s.pop();        // 최상단 요소 제거
s.empty();      // 비었는지 확인
s.size();       // 요소 개수
```

---

## ⚙️ 주요 메서드

| 메서드       | 설명                           |
|--------------|--------------------------------|
| `push(val)`  | 요소 삽입 (맨 위에 추가)        |
| `pop()`      | 최상단 요소 제거                |
| `top()`      | 최상단 요소 반환                |
| `empty()`    | 비어 있는지 여부 반환 (bool)    |
| `size()`     | 요소 개수 반환                  |

---

## 📌 내부 컨테이너 지정

```cpp
stack<int, vector<int>> s1;  // vector 기반
stack<int, list<int>> s2;    // list 기반
```

- 내부 컨테이너는 `back()`/`push_back()`/`pop_back()`을 지원해야 함
- 기본값은 `deque`

---

## 🧾 예시

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<string> s;
  s.push("apple");
  s.push("banana");
  s.push("cherry");

  while (!s.empty()) {
    cout << s.top() << '\n'; // cherry, banana, apple 순 출력
    s.pop();
  }
}
```

---

## 💡 팁

- `stack`은 반복자(iterator)를 지원하지 않음  
- 요소 전체를 순회하려면 pop하면서 출력해야 함  
- 필요시 `vector` 등 다른 컨테이너로 접근하여 순회하는 방식 고려

---

## 🧷 관련 함수/특징

| 특징                         | 설명                                      |
|------------------------------|-------------------------------------------|
| `#include <stack>`           | 필수 헤더                                  |
| LIFO 구조                    | 후입선출 방식                              |
| 반복자 미지원               | `begin()`, `end()` 없음                   |
| 내부 컨테이너 선택 가능      | `deque`, `vector`, `list` 사용 가능       |

---

## ✅ 요약

- `stack`은 LIFO 구조의 컨테이너 어댑터  
- 삽입: `push()`, 삭제: `pop()`, 확인: `top()`  
- 반복자는 지원하지 않음 (전체 순회는 pop 기반)  
- 내부 컨테이너는 `deque`가 기본이며 변경 가능  
- `<stack>` 헤더 필수 포함

---
