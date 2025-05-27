# C++ STL 유틸리티 함수 정리 (`swap`, `reverse` 등)

`<algorithm>` 또는 `<utility>` 헤더에 정의된 유용한 STL 함수들은 컨테이너나 변수의 값을 쉽게 조작할 수 있도록 도와줍니다.

---

## 📦 헤더
```cpp
#include <algorithm>
#include <utility>  // swap
```

---

## 🔁 `swap(a, b)`
두 변수의 값을 맞바꿉니다.

```cpp
int a = 5, b = 10;
swap(a, b); // a = 10, b = 5
```

컨테이너 내부 요소도 swap 가능:
```cpp
vector<int> v = {1, 2, 3, 4};
swap(v[0], v[3]); // v = {4, 2, 3, 1}
```

---

## 🔄 `reverse(begin, end)`
범위를 거꾸로 뒤집습니다.

```cpp
vector<int> v = {1, 2, 3, 4};
reverse(v.begin(), v.end()); // v = {4, 3, 2, 1}
```

---

## 🔍 `find(begin, end, value)`
특정 값을 찾아 반복자를 반환합니다. 없으면 `.end()` 반환.

```cpp
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) cout << "Found!";
```

---

## 🔢 `count(begin, end, value)`
값이 등장하는 횟수를 셉니다.

```cpp
int c = count(v.begin(), v.end(), 3);
```

---

## ⬆️ `sort(begin, end)`
기본 오름차순 정렬. 내림차순은 `greater<>()` 사용.

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>()); // 내림차순
```

---

## 🔁 `rotate(begin, middle, end)`
지정한 middle을 앞으로 당김.

```cpp
vector<int> v = {1, 2, 3, 4, 5};
rotate(v.begin(), v.begin() + 2, v.end()); // v = {3, 4, 5, 1, 2}
```

---

## 🚀 `next_permutation(begin, end)`
다음 순열로 바꿔줌. 더 이상 없으면 false 반환.

```cpp
vector<int> v = {1, 2, 3};
do {
  // 사용
} while (next_permutation(v.begin(), v.end()));
```

---

## ✅ 요약

| 함수                  | 설명                             |
|----------------------|----------------------------------|
| `swap(a, b)`         | 두 값 교환                         |
| `reverse(b, e)`      | 순서 반전                         |
| `find(b, e, val)`    | 특정 값 위치 탐색                   |
| `count(b, e, val)`   | 특정 값 개수 세기                   |
| `sort(b, e)`         | 정렬                              |
| `rotate(b, m, e)`    | 중간 요소 앞으로 회전                 |
| `next_permutation`   | 사전순 다음 순열 생성                |

> 모두 반복자 기반으로 사용됩니다. `begin(), end()`는 vector, string 등 대부분의 STL 컨테이너에서 지원됩니다.
