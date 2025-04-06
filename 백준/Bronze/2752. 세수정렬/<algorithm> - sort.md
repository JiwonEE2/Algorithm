# `<algorithm>`의 `sort` 함수 정리

C++ 표준 라이브러리의 `std::sort`는 정렬을 위한 대표적인 함수로, 빠르고 유연한 동작으로 많은 상황에서 사용됩니다. 이 문서에서는 `std::sort`의 기본적인 사용법과 커스텀 비교 함수, 관련 함수들을 정리합니다.

> ✅ `std::sort`를 사용하려면 반드시 `#include <algorithm>`을 선언해야 합니다.

---

## 🟢 기본 사용법

### 오름차순 정렬

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5};
std::sort(v.begin(), v.end()); // 오름차순 정렬
```

---

## 🟡 내림차순 정렬

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5};
std::sort(v.begin(), v.end(), std::greater<>()); // 내림차순 정렬
```

> 📌 `#include <functional>`이 필요할 수 있습니다.

---

## 🔵 사용자 정의 비교 함수

### 구조체나 복합 자료형 정렬 시 유용합니다.

```cpp
#include <algorithm>
#include <vector>

struct Person {
    std::string name;
    int age;
};

std::vector<Person> people = {
    {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}
};

// 나이 오름차순 정렬
std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
    return a.age < b.age;
});
```

---

## 🟣 정렬 범위

- `std::sort`는 `[first, last)` 범위의 요소들을 정렬합니다.
- 이 범위는 **반열린 구간**으로, `last`는 포함되지 않습니다.

```cpp
std::sort(arr + 1, arr + 4); // 1번 인덱스부터 3번 인덱스까지 정렬
```

---

## ⚠️ 주의 사항

- `std::sort`는 **`RandomAccessIterator`**를 요구합니다.
  - `std::list`는 지원하지 않음 → 대신 `list::sort()` 사용
- 내부적으로 `IntroSort`(Quick + Heap + Insertion)를 사용하여 평균 시간 복잡도는 `O(N log N)`입니다.

---

## ✅ 관련 함수

| 함수명               | 특징 및 용도                                 |
|--------------------|--------------------------------------------|
| `std::sort`        | 빠른 일반 정렬, 커스텀 비교 가능                   |
| `std::stable_sort` | 안정 정렬 (원래 순서 유지), 약간 느림               |
| `std::partial_sort`| 일부만 정렬, 가장 앞의 K개만 정렬됨               |
| `std::nth_element` | 전체 정렬 없이 n번째 원소가 정렬된 위치에 오도록 정리 |

---

## 🔚 마무리

- 단순 정렬은 `std::sort`, 안정성이 필요하면 `std::stable_sort`, 특정 위치만 필요하면 `std::nth_element` 등을 활용합니다.
- 복잡한 구조체 정렬에서는 람다식을 적극적으로 활용하세요.
