# 🌲 C++ `set` 정리

`set`은 **중복을 허용하지 않고**, **자동 정렬되는** 자료구조입니다. 내부적으로 **이진 탐색 트리(Red-Black Tree)** 기반으로 동작합니다.

---

## 📦 헤더

```cpp
#include <set>
```

---

## ✅ 주요 특징

| 특징       | 설명                               |
| -------- | -------------------------------- |
| 중복 허용 X  | 동일한 값은 하나만 저장                    |
| 자동 정렬    | `오름차순`으로 정렬된 상태로 유지 (`< 연산자 기준`) |
| 삽입/삭제/탐색 | 모두 `O(log N)`의 시간 복잡도            |
| 내부 구조    | Red-Black Tree 기반 (Balanced BST) |
| 반복자      | `Bidirectional Iterator` 사용 가능   |

---

## 🛠️ 기본 사용법

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(5); // 중복 → 무시됨
    s.insert(1);

    for (int x : s) cout << x << " "; // 1 3 5
}
```

---

## 🔍 주요 함수

| 함수               | 설명                         |
| ---------------- | -------------------------- |
| `insert(val)`    | 값 삽입 (중복 시 무시)             |
| `erase(val)`     | 값 제거 (없으면 아무 일도 없음)        |
| `find(val)`      | 값의 반복자 반환 (없으면 `end()` 반환) |
| `count(val)`     | 존재하면 1, 없으면 0 반환           |
| `size()`         | 원소 개수 반환                   |
| `empty()`        | 비었는지 확인 (`true/false`)     |
| `clear()`        | 전체 삭제                      |
| `begin(), end()` | 반복자 반환                     |

---

## 🔁 반복자 예시

```cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

---

## ⚠️ 주의할 점

* 정렬 기준은 기본적으로 **오름차순** (`operator<`)
* `insert` 결과는 `pair<iterator, bool>` 반환
  → 성공 여부를 확인할 수 있음

```cpp
auto result = s.insert(10);
if (result.second) cout << "삽입 성공";
else cout << "이미 존재함";
```

---

## 📌 사용자 정의 정렬

```cpp
struct Desc {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

set<int, Desc> s; // 내림차순
```

---

## 🧪 실전 예시: 중복 제거 후 정렬 출력

```cpp
#include <set>
#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 1, 4, 1, 5};
    set<int> s(arr, arr + 5);

    for (int x : s) cout << x << " "; // 1 3 4 5
}
```

---

## 🧷 `multiset`과의 차이

| 컨테이너       | 중복 허용 | 정렬 | 사용처               |
| ---------- | ----- | -- | ----------------- |
| `set`      | ❌     | ⬆️ | 중복 제거 + 정렬 필요할 때  |
| `multiset` | ✅     | ⬆️ | 중복 허용하면서 정렬 필요할 때 |

---

## ⏱️ 시간 복잡도

| 연산                        | 시간 복잡도   |
| ------------------------- | -------- |
| `insert`, `erase`, `find` | O(log N) |
| 순차 탐색 (for)               | O(N)     |

---

## 🧠 정리

* `set`: **중복 없는 정렬된 집합**
* `insert`, `erase`, `find` 모두 **log 시간**
* `multiset`은 중복 허용
* 커스텀 정렬을 위해 비교 함수 전달 가능
* 정렬된 순서대로 원소 접근 가능

---

필요 시 `unordered_set`은 해시 기반이라 삽입/탐색이 평균 O(1)입니다.
`중복 제거 + 정렬`이 필요하면 `set`,
`빠른 탐색`이 목적이면 `unordered_set`을 고려하세요.
