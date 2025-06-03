# 🧩 C++ `std::pair` 정리

---

## 🟢 1. 개요

* `std::pair`는 **서로 다른 타입 두 개의 값을 묶어 저장**할 수 있는 구조체입니다.
* `<utility>` 헤더에 정의되어 있습니다.

```cpp
#include <utility>
std::pair<int, std::string> p = {1, "Hello"};
```

---

## 🛠️ 2. 생성 방법

### ✅ 기본 생성

```cpp
std::pair<int, int> p(3, 5);
```

### ✅ `make_pair()` 사용

```cpp
auto p = std::make_pair(3, 5); // 타입 자동 추론됨
```

### ✅ 구조 분해 (C++17 이상)

```cpp
auto [a, b] = p;
```

---

## 📁 3. 멤버 변수

```cpp
p.first  // 첫 번째 값
p.second // 두 번째 값
```

---

## 📦 4. 주요 사용 예시

### ✔️ 배열로 사용

```cpp
std::pair<int, int> arr[3] = {{1, 2}, {3, 1}, {2, 4}};
```

### ✔️ vector에 저장

```cpp
std::vector<std::pair<int, int>> v;
v.emplace_back(1, 2);
v.emplace_back(3, 1);
v.emplace_back(2, 4);
```

---

## 🧮 5. 정렬

### ✅ 기본 정렬 (first → second 순)

```cpp
std::sort(v.begin(), v.end()); 
// 기본 정렬 기준: first 오름차순 → 같으면 second 오름차순
```

예시:

```cpp
입력: {(2, 3), (1, 5), (2, 1)}
결과: {(1, 5), (2, 1), (2, 3)}
```

---

### 🔧 사용자 정의 기준 정렬

#### 🟡 second 기준 정렬

```cpp
std::sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});
```

#### 🟠 second 기준 내림차순, 같으면 first 기준 오름차순

```cpp
std::sort(v.begin(), v.end(), [](auto& a, auto& b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
});
```

---

## ⚠️ 6. 주의 사항

* `std::pair`는 단순 자료 구조로, **의미 부여가 부족하면 가독성이 떨어질 수 있습니다.**
* 실제 프로덕션 코드에서는 `struct` 또는 `tuple`을 쓰는 것이 더 명확할 수 있습니다.

---

## 🧷 7. 요약 정리

| 항목    | 내용                               |
| ----- | -------------------------------- |
| 헤더    | `#include <utility>`             |
| 생성    | `{a, b}`, `std::make_pair(a, b)` |
| 접근    | `pair.first`, `pair.second`      |
| 정렬 기준 | 기본은 `first → second`, 커스텀 가능     |
| 사용 예  | 배열, `vector<pair>`, `map`의 요소 등  |

---

## 🔚 마무리

* `pair`는 알고리즘 문제 풀이에서 **좌표(x, y)**, **값-인덱스**, **거리-노드** 형태로 자주 사용됩니다.
* `vector<pair<>>`와 `sort()`를 조합하면 **조건 기반 정렬**을 간편하게 구현할 수 있습니다.
