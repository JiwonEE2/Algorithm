# C++ STL Iterator 정리

C++ STL에서 반복자는 컨테이너 내부를 순회하고 요소에 접근할 수 있는 포인터 유사 객체입니다. 컨테이너와 범위 기반 for문, `auto`, 그리고 반복자 유틸 함수들과 함께 자주 쓰입니다.

---

## 📁 헤더

```cpp
#include <vector>   // vector 컨테이너
#include <list>     // list 컨테이너
#include <iterator> // 반복자 유틸 함수 사용 시 필요
```

- 컨테이너 헤더에 반복자 타입 포함  
- 반복자 유틸 함수(`advance`, `next`, `prev`)는 `<iterator>` 필요

---

## 🛠️ 기본 사용법

```cpp
vector<int> v = {1, 2, 3, 4};

// 명시적 반복자 사용
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
  cout << *it << ' ';
}

// auto 키워드로 반복자 타입 생략
for (auto it = v.begin(); it != v.end(); ++it) {
  cout << *it << ' ';
}

// 범위 기반 for문 (C++11 이상)
for (int x : v) {
  cout << x << ' ';
}
```

---

## ⚙️ 주요 메서드

| 메서드       | 설명                           |
|--------------|--------------------------------|
| `begin()`    | 첫 요소를 가리키는 반복자       |
| `end()`      | 마지막 요소의 다음을 가리킴     |
| `rbegin()`   | 역순 반복 시작                  |
| `rend()`     | 역순 반복 종료                  |
| `cbegin()`   | const 반복자 (C++11)            |
| `cend()`     | const end 반복자 (C++11)        |

---

## 📌 반복자 종류

| 종류             | 설명                                       |
|------------------|--------------------------------------------|
| Input Iterator   | 한 번만 읽기 가능 (`istream_iterator` 등)   |
| Output Iterator  | 한 번만 쓰기 가능 (`ostream_iterator` 등)   |
| Forward Iterator | 여러 번 읽고 쓰기 가능, 순방향 이동         |
| Bidirectional    | 순방향 + 역방향 이동 가능 (`list`, `set`)   |
| Random Access    | 임의 접근 가능 (`vector`, `deque`)          |

---

## 🧾 예시

### ✅ vector 반복자

```cpp
vector<int> v = {10, 20, 30};
auto it = v.begin();
cout << *it << endl;  // 10
++it;
cout << *it << endl;  // 20
```

### ✅ list 반복자

```cpp
list<string> fruits = {"apple", "banana", "cherry"};

for (auto it = fruits.begin(); it != fruits.end(); ++it) {
  cout << *it << endl;
}
```

---

## 💡 팁

- 반복자는 컨테이너 요소를 가리키며 `*it`로 값 접근  
- `++it`로 다음 요소, `--it`로 이전 요소 이동 (Bidirectional 이상)  
- `auto` 사용 시 타입 작성 생략 가능  
- `range-based for`는 내부적으로 반복자를 사용

---

## 🧷 반복자 관련 함수 (`<iterator>` 필요)

| 함수                    | 설명                              |
|-------------------------|-----------------------------------|
| `std::advance(it, n)`   | `it`를 n만큼 전진 또는 후퇴        |
| `std::distance(a, b)`   | 두 반복자 사이 거리 계산           |
| `std::next(it, n)`      | `it`의 n칸 뒤 반복자 반환           |
| `std::prev(it, n)`      | `it`의 n칸 앞 반복자 반환           |

---

## ✅ 요약

- 반복자는 포인터처럼 작동하며, 컨테이너 요소 접근에 사용됨  
- `begin()` ~ `end()` 범위로 순회  
- 반복자 종류에 따라 이동 능력 달라짐  
- `auto`, 범위 기반 for문, 유틸 함수와 함께 쓰면 코드 간결해짐  
- `<iterator>`는 반복자 함수 사용 시에만 필요

---
