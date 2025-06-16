# 📘 C++ `unordered_set` 정리

---

## 📦 헤더

```cpp
#include <unordered_set>
```

---

## 🛠️ 기본 사용법

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> uset;

    uset.insert(10);
    uset.insert(20);
    uset.insert(10); // 중복 삽입 → 무시됨

    for (int x : uset)
        cout << x << " "; // 출력 순서는 일정하지 않음
}
```

---

## ✅ 주요 특징

| 특성       | 설명                                                |
| -------- | ------------------------------------------------- |
| 순서 없음    | 내부적으로 **해시 테이블** 사용 → **삽입 순서 유지 X**              |
| 중복 허용 X  | 동일한 값은 한 번만 저장됨                                   |
| 평균 연산 속도 | 삽입, 삭제, 탐색 모두 **O(1)** (해시 충돌 시 예외적으로 O(n))       |
| 키 기반     | `set`과 달리 **정렬 기준이 아닌 해시**를 기반으로 동작               |
| 반복자      | `unordered_set<int>::iterator` 사용 가능 (단, 순서는 무작위) |

---

## 📋 주요 멤버 함수

| 함수            | 설명                         |
| ------------- | -------------------------- |
| `insert(val)` | 값 추가 (중복이면 무시됨)            |
| `erase(val)`  | 특정 값 제거                    |
| `find(val)`   | 해당 값의 반복자 반환 (없으면 `end()`) |
| `count(val)`  | 존재 여부 확인 (0 또는 1 반환)       |
| `clear()`     | 모든 요소 삭제                   |
| `size()`      | 현재 원소 개수 반환                |
| `empty()`     | 비어있는지 확인                   |

---

## 🧪 예시

```cpp
unordered_set<string> uset = {"apple", "banana", "cherry"};

if (uset.count("banana")) {
    cout << "banana exists!\n";
}

uset.erase("banana");

for (auto it = uset.begin(); it != uset.end(); ++it) {
    cout << *it << " ";
}
```

---

## 🆚 `set` vs `unordered_set`

| 항목          | `set`                         | `unordered_set`  |
| ----------- | ----------------------------- | ---------------- |
| 내부 구조       | **이진 탐색 트리 (Red-Black Tree)** | **해시 테이블**       |
| 정렬 여부       | 자동 정렬됨 (오름차순 등)               | 정렬 없음 (무작위 순서)   |
| 탐색/삽입/삭제 속도 | O(log n)                      | 평균 O(1), 최악 O(n) |
| 중복 허용 여부    | ❌ 중복 허용 안 함                   | ❌ 중복 허용 안 함      |

---

## ⚠️ 주의 사항

* `unordered_set`은 **사용되는 키 타입에 대해 해시 함수가 정의되어 있어야** 합니다.

  * 기본형(int, string 등)은 정의되어 있음
  * 커스텀 구조체를 key로 쓰려면 `hash 함수`를 직접 정의해야 함
* **순서가 중요할 경우 사용하지 말 것.**

---

## 🔚 요약

* `unordered_set`은 **중복 없는 데이터**를 **빠르게 삽입/탐색/삭제**할 때 유용함
* **순서가 중요하지 않고**, 성능이 중요할 때 선택
* **정렬 필요** 시 `set`을 사용하고, **빠른 접근**이 필요하면 `unordered_set`을 사용하세요.