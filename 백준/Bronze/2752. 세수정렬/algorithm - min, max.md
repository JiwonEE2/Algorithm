# `<algorithm>`의 `min`, `max`, `minmax` 함수 정리

`<algorithm>` 헤더에는 최소, 최대값을 구할 수 있는 다양한 함수들이 포함되어 있습니다. 이 문서에서는 자주 사용되는 `min`, `max`, `minmax`, `min_element`, `max_element` 함수들의 사용법과 특징을 정리합니다.

> ✅ 모든 함수는 `<algorithm>` 헤더에 정의되어 있으므로 반드시 `#include <algorithm>` 선언이 필요합니다.

---

## 🟢 `min`, `max`

### 두 값 비교

```cpp
#include <algorithm>

int a = std::min(1, 2); // a = 1
int b = std::max(1, 2); // b = 2
```

### 세 값 이상 비교

중괄호 초기화 리스트를 이용하면 세 개 이상의 값을 비교할 수 있습니다.

```cpp
int a = std::min({3, 7, 2}); // a = 2
int b = std::max({3, 7, 2}); // b = 7
```

> ⚠️ 중괄호 `{}` 없이 `min(min(a, b), c)` 처럼 중첩해서도 가능하지만, 가독성이 떨어지고 실수가 발생할 수 있습니다.

---

## 🟡 `minmax`

### 정의

`std::minmax`는 최소값과 최대값을 동시에 구하고, 결과를 `std::pair<T, T>`로 반환합니다.

### 예시

```cpp
#include <algorithm>
#include <utility>

auto result = std::minmax({1, 3, 2, 5, 4});

// result.first = 1 (최소값)
// result.second = 5 (최대값)
```

> 📌 `#include <utility>`는 `std::pair`를 사용하기 위해 필요할 수 있습니다.

---

## 🔵 `min_element`, `max_element`

### 정의

컨테이너(예: `std::vector`, `std::array`, C-style 배열 등)에 대해 최솟값 또는 최댓값을 가진 **iterator**를 반환합니다.

### 예시

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> vec = {5, 2, 8, 1, 3};

auto min_it = std::min_element(vec.begin(), vec.end());
auto max_it = std::max_element(vec.begin(), vec.end());

std::cout << "최솟값: " << *min_it << std::endl; // 1
std::cout << "최댓값: " << *max_it << std::endl; // 8
```

> 📝 반환값은 **값이 아닌 iterator**이므로 `*` 연산자로 값을 꺼내야 합니다.

---

## 📌 참고 사항 및 팁

- `std::min`, `std::max`, `std::minmax`는 **초기화 리스트 `{}`**를 통해 여러 값을 비교할 수 있음.
- `std::minmax_element` 함수도 있으며, 이는 `min_element`, `max_element`를 한 번에 처리하는 함수입니다.
- 사용자 정의 비교 함수도 인자로 전달할 수 있습니다.

### 사용자 정의 비교 함수 예시

```cpp
std::min(1, 2, [](int a, int b) { return a > b; }); // 최대값 반환 (내림차순 기준)
```

---

## ✅ 정리 요약

| 함수명             | 반환값 타입            | 특징 및 용도                         |
|------------------|---------------------|----------------------------------|
| `std::min(a, b)` | 값                  | 두 값 중 작은 값 반환              |
| `std::max(a, b)` | 값                  | 두 값 중 큰 값 반환              |
| `std::min({})`   | 값                  | 여러 값 중 작은 값 반환            |
| `std::max({})`   | 값                  | 여러 값 중 큰 값 반환            |
| `std::minmax({})`| `std::pair`         | 최소, 최대값을 한 번에 반환         |
| `min_element`    | iterator            | 컨테이너 내 최소값의 위치 반환       |
| `max_element`    | iterator            | 컨테이너 내 최대값의 위치 반환       |
| `minmax_element` | `pair<iterator, iterator>` | 컨테이너에서 최소/최대 iterator 반환 |

---

## 🔚 마무리

- 복잡한 비교를 반복하거나, 값의 수가 많을 때는 `min_element`, `max_element`, `minmax`를 적절히 활용하는 것이 가독성과 성능 측면에서 유리합니다.
- 중첩된 `min(min(...))` 같은 패턴은 지양하고, 리스트 초기화를 적극 활용하는 것이 좋습니다.
