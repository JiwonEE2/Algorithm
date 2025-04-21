# C++ STL Iterator 정리

Iterator는 C++의 표준 템플릿 라이브러리(STL)에서 컨테이너를 순회(iterate)하기 위한 객체입니다. 포인터처럼 동작하며, 컨테이너의 요소를 접근하거나 조작할 수 있게 해줍니다.

---

## 📦 헤더

```cpp
#include <vector>   // vector 컨테이너
#include <list>     // list 컨테이너
#include <iterator> // 반복자 관련 유틸리티 함수 사용 시 필요
```

- 대부분의 경우 `vector`, `list` 등의 컨테이너 헤더를 포함하면 해당 반복자 타입도 함께 정의됩니다.
- `std::advance`, `std::next`, `std::prev` 등 반복자 유틸리티를 사용할 경우 `<iterator>` 헤더가 필요합니다.

---

## 🔁 기본 사용법

```cpp
vector<int> v = {1, 2, 3, 4};

// 일반 반복자
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
  cout << *it << ' ';
}

// C++11 이후 범위 기반 for 문 (내부적으로 iterator 사용)
for (int x : v) {
  cout << x << ' ';
}
```

---

## ✅ 주요 메서드

| 메서드           | 설명                              |
|------------------|-----------------------------------|
| `begin()`        | 시작 요소를 가리키는 반복자 반환   |
| `end()`          | 마지막 요소의 다음을 가리킴       |
| `rbegin()`       | 역순 반복 시작                     |
| `rend()`         | 역순 반복 종료                     |
| `cbegin()`       | const 반복자 (C++11)              |
| `cend()`         | const end 반복자 (C++11)          |

---

## 📌 반복자 종류

| 종류             | 설명                                     |
|------------------|------------------------------------------|
| Input Iterator   | 한 번만 읽을 수 있음 (입력 스트림 등)     |
| Output Iterator  | 한 번만 쓸 수 있음 (출력 스트림 등)       |
| Forward Iterator | 여러 번 읽고 쓸 수 있음, 순방향 이동만 가능 |
| Bidirectional    | 앞뒤로 이동 가능 (`list`, `set` 등)       |
| Random Access    | 임의 접근 가능 (`vector`, `deque` 등)     |

---

## 🧪 예시

### vector에서의 반복자

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {10, 20, 30};

  vector<int>::iterator it = v.begin();
  cout << *it << endl;   // 10

  ++it;
  cout << *it << endl;   // 20
}
```

### list에서의 반복자

```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
  list<string> fruits = {"apple", "banana", "cherry"};

  for (list<string>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
    cout << *it << '\\n';
  }
}
```

---

## 🧠 팁

- `*it`은 반복자가 가리키는 값
- `++it`로 다음 요소로 이동
- 범위 기반 for문이 간편하고 안전함
- `auto` 키워드로 반복자 타입 생략 가능

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
  cout << *it << ' ';
}
```

---

## 🧷 관련 함수들 (`<iterator>` 필요)

- `std::advance(it, n)`: `it`을 n만큼 이동
- `std::distance(a, b)`: a부터 b까지 거리
- `std::next(it, n)`: it + n 반복자 반환
- `std::prev(it, n)`: it - n 반복자 반환

---

## ✅ 요약

- 반복자는 포인터처럼 컨테이너 내부 요소를 접근하는 도구
- `begin()` ~ `end()`를 통해 범위를 정함
- 다양한 종류의 반복자 존재
- `auto`와 범위 기반 for문으로 사용 간소화
- `<iterator>`는 반복자 유틸 함수 사용 시에만 명시 필요

---

이제 `vector`와 `list` 모두 예시가 포함되어 있습니다. 필요하시면 제가 나중에 파일 형태로도 다시 제공해드릴 수 있습니다.
