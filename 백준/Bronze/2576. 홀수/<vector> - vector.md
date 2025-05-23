# C++ STL: `vector` 간단 정리

`vector`는 C++ STL에서 가장 널리 쓰이는 동적 배열 컨테이너입니다. 크기를 동적으로 조절할 수 있으며, 배열과 유사한 방식으로 인덱스를 통해 접근 가능합니다.

---

## 📦 헤더
```cpp
#include <vector>
```

---

## 🔧 기본 사용법
```cpp
vector<int> v;             // 빈 벡터 생성
v.push_back(10);           // 요소 추가
v[0] = 20;                 // 인덱스 접근 및 수정
int x = v.at(0);           // 범위 체크 포함 접근
```
---

## 🧩 주요 멤버 함수

| 함수                         | 설명                                  |
| -------------------------- | ----------------------------------- |
| `push_back(val)`           | 맨 뒤에 요소 추가                          |
| `pop_back()`               | 맨 뒤 요소 제거                           |
| `insert(pos, val)`         | `pos` 위치에 `val` 삽입 (반복자 필요)         |
| `insert(pos, n, val)`      | `pos` 위치에 `val`을 `n`번 삽입            |
| `insert(pos, first, last)` | `pos` 위치에 `[first, last)` 범위의 요소 삽입 |
| `size()`                   | 현재 요소 개수 반환                         |
| `empty()`                  | 비어 있는지 확인 (`true/false`)            |
| `clear()`                  | 모든 요소 제거                            |
| `begin(), end()`           | 반복자 반환 (for-each, sort 등 사용)        |
| `at(i)`                    | 인덱스 접근 (예외 검사 포함)                   |

---

## ✍️ `insert` 사용 예시

```cpp
vector<int> v = {1, 2, 4};

// 3을 두 번째 위치에 삽입
v.insert(v.begin() + 2, 3);  // → {1, 2, 3, 4}

// 0을 맨 앞에 2번 삽입
v.insert(v.begin(), 2, 0);   // → {0, 0, 1, 2, 3, 4}

// 다른 컨테이너에서 복사 삽입
vector<int> extra = {7, 8};
v.insert(v.end(), extra.begin(), extra.end()); // → {0, 0, 1, 2, 3, 4, 7, 8}
```

* `insert`는 **위치 반복자**가 반드시 필요합니다.
* `v.begin() + i` 형태로 사용하여 원하는 위치를 지정할 수 있습니다.
* 벡터는 **연속된 메모리 공간**을 유지하기 때문에 `insert` 시 기존 요소들의 이동이 발생합니다.

---

## 🌀 반복자 사용 예시
```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
  cout << *it << " ";
}
```

또는
```cpp
for (int x : v) {
  cout << x << " ";
}
```

---

## ⚙️ sort와 함께 사용
```cpp
#include <algorithm>
sort(v.begin(), v.end());
```

---

## 🧠 주의사항
- `[]`는 예외를 발생시키지 않음 (범위 벗어나도 컴파일됨)
- 메모리 재할당이 발생할 수 있으므로 반복적 `push_back` 시 성능 고려 필요

---

## ✅ 요약
- **vector**는 동적 배열 컨테이너
- 크기 자동 조절, 인덱스 접근, 반복자 사용 가능
- 알고리즘 라이브러리와 함께 매우 유용함
