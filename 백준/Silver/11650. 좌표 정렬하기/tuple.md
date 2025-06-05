# 🧱 C++ STL `tuple` 정리

`std::tuple`은 서로 다른 타입의 **복수의 값을 하나로 묶기 위한 컨테이너**입니다. `pair`의 일반화된 형태로, **2개 이상(1\~N개)의 값**을 저장할 수 있습니다.

---

## 📦 헤더

```cpp
#include <tuple>
```

---

## 🔧 기본 사용법

```cpp
std::tuple<int, std::string, double> t(1, "apple", 3.14);
```

또는 `make_tuple` 사용:

```cpp
auto t = std::make_tuple(1, "apple", 3.14);
```

---

## 🛠️ 요소 접근

```cpp
int i = std::get<0>(t);       // 1
std::string s = std::get<1>(t); // "apple"
double d = std::get<2>(t);      // 3.14
```

- `std::get<N>(tuple)`은 **컴파일 타임 상수** `N`이 필요합니다.

---

## 🧩 구조 분해 (C++17 이상)

```cpp
auto [id, name, score] = t;
```

---

## 🔄 값 수정

```cpp
std::get<1>(t) = "banana";
```

---

## 🟦 비교 연산 지원

튜플은 `==`, `<`, `>` 등의 비교 연산을 자동으로 지원합니다.
→ \*\*사전식 순서(lexicographical order)\*\*로 비교됩니다.

```cpp
std::tuple<int, int> a = {1, 2};
std::tuple<int, int> b = {1, 3};

bool result = a < b; // true
```

---

## 🔁 정렬 예시

```cpp
#include <vector>
#include <tuple>
#include <algorithm>

std::vector<std::tuple<int, int, int>> v = {
    {1, 2, 3}, {1, 1, 5}, {0, 9, 8}
};

std::sort(v.begin(), v.end()); // 자동으로 첫 번째 → 두 번째 → 세 번째 순 정렬
```

---

## ⚖️ pair vs tuple 차이

| 항목        | `pair`                          | `tuple`                             |
| ----------- | ------------------------------- | ----------------------------------- |
| 헤더        | `<utility>`                     | `<tuple>`                           |
| 저장 개수   | **2개**                         | **2개 이상 가능 (1\~N개)**          |
| 생성 방식   | `std::make_pair(a, b)`          | `std::make_tuple(a, b, c, ...)`     |
| 접근 방식   | `.first`, `.second`             | `std::get<N>(t)`, 구조 분해 (C++17) |
| 사용 목적   | 간단한 쌍 묶기                  | 다양한 값 묶기                      |
| 정렬 기준   | `.first → .second` 순 자동 정렬 | 사전식 순서 자동 정렬               |
| 코드 가독성 | 상대적으로 높음                 | 요소가 많아질수록 가독성 낮아짐     |

---

## 🧠 활용 예

- 그래프에서 `(비용, 현재 노드, 이전 노드)`처럼 여러 정보를 함께 저장
- 여러 리턴값 반환

  ```cpp
  std::tuple<int, int> getMinMax() {
      return {1, 100};
  }

  auto [minVal, maxVal] = getMinMax();
  ```

---

## ⚠️ 주의 사항

- `std::get<N>(tuple)`은 컴파일 타임 상수가 필요
- 가독성이 떨어질 경우 \*\*구조체(struct)\*\*를 사용하는 것이 더 낫습니다

---

## ✅ 요약

- `tuple`은 다양한 타입의 여러 값을 묶는 데 유용
- `pair`보다 범용성이 높지만, 의미 없는 숫자 인덱스로 접근해야 하므로 **가독성은 떨어짐**
- C++17 이상이라면 **구조 분해**를 적극 활용하세요
