# `<algorithm>`의 `std::sort` 함수 정리

C++ 표준 라이브러리의 `std::sort`는 빠르고 유연한 정렬 함수입니다. 오름차순, 내림차순, 구조체/배열 등 다양한 데이터에 사용할 수 있으며, 람다식 또는 함수 객체를 이용해 정렬 기준을 사용자 정의할 수도 있습니다.

> ✅ `std::sort`를 사용하려면 반드시 `#include <algorithm>`을 선언해야 합니다.

---

## 📁 헤더

```cpp
#include <algorithm>
```

내림차순 정렬을 위한 비교 함수 객체 사용 시:

```cpp
#include <functional>
```

---

## 🟢 기본 사용법

### 오름차순 정렬

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};
std::sort(v.begin(), v.end()); // {1, 1, 3, 4, 5}
```

---

## 🟡 내림차순 정렬

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};
std::sort(v.begin(), v.end(), std::greater<>()); // {5, 4, 3, 1, 1}
```

---

## 🔵 사용자 정의 비교 함수

### 📌 구조체 정렬 (람다 사용)

```cpp
struct Person {
    std::string name;
    int age;
};

std::vector<Person> people = {
    {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}
};

// 나이 오름차순
std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
    return a.age < b.age;
});
```

---

### 📌 `pair` 또는 2차원 배열 정렬

#### 기본적으로 `pair`는 **first → second** 순으로 비교됩니다:

```cpp
std::vector<std::pair<int, int>> v = {{2, 3}, {1, 5}, {2, 2}, {1, 3}};
std::sort(v.begin(), v.end());  // (1,3), (1,5), (2,2), (2,3)
```

#### second 기준으로 정렬:

```cpp
std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
});
```

#### first가 같을 때 second는 내림차순:

```cpp
std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
});
```

---

## 🟣 정렬 범위

`std::sort`는 `[first, last)` 형태의 **반열린 구간**에서 동작합니다.
즉, 마지막 인덱스는 포함되지 않습니다.

```cpp
int arr[] = {9, 3, 5, 1, 7};
std::sort(arr + 1, arr + 4); // arr[1]~arr[3] 정렬됨 → {9,1,3,5,7}
```

---

## ⚙️ 시간 / 공간 복잡도

| 항목             | 설명                                                  |
| ---------------- | ----------------------------------------------------- |
| 평균 시간 복잡도 | `O(N log N)`                                          |
| 최악 시간 복잡도 | `O(N log² N)` (정확히는 IntroSort의 구현에 따라 다름) |
| 공간 복잡도      | `O(log N)` (재귀 호출에 의한 스택 사용량 기준)        |

- 내부 정렬 알고리즘은 **IntroSort**: QuickSort + HeapSort + InsertionSort의 하이브리드입니다.

---

## ⚠️ 주의 사항

### 1. `std::sort`는 Random Access Iterator가 필요합니다.

- `std::vector`, `std::deque`, C 배열(`int arr[]`)은 지원
- 하지만 **`std::list`는 사용 불가능** → 대신 `list.sort()` 사용

```cpp
std::list<int> L = {3, 1, 2};
std::sort(L.begin(), L.end());  // ❌ 컴파일 에러
L.sort();                       // ✅ list 전용 멤버 함수
```

### 2. 반복자 범위를 잘못 지정하면 런타임 에러 발생

```cpp
std::sort(v.end(), v.begin()); // 잘못된 범위 → 동작 미정
```

### 3. 비교 함수에서 대칭성과 일관성이 없으면 Undefined Behavior

```cpp
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a % 2 == 0; // ❌ 잘못된 비교 함수 (일관성 없음)
});
```

---

## ✅ 관련 함수 비교

| 함수명              | 특징 및 용도                                                 |
| ------------------- | ------------------------------------------------------------ |
| `std::sort`         | 비안정 정렬 (기본 정렬), 가장 빠름                           |
| `std::stable_sort`  | 안정 정렬 (같은 값이면 원래 순서 유지), 느리지만 보존성 있음 |
| `std::partial_sort` | 일부만 정렬 (`앞의 K개만 정렬`)                              |
| `std::nth_element`  | n번째 원소가 정렬된 위치에 오도록 재배열, 전체 정렬 아님     |

---

## ✅ 요약

- `std::sort(begin, end)`는 빠르고 범용적인 정렬 함수
- **람다식을 사용해 구조체, pair, 2차원 배열 등 복잡한 기준 정렬 가능**
- `std::list`에는 사용 불가 → `list.sort()`로 대체
- 비교 함수는 일관성과 대칭성을 지켜야 함
- 시간 복잡도는 `O(N log N)`, 공간 복잡도는 `O(log N)` 수준
