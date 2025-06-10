# 📚 `std::map` 정리

`std::map`은 **자동 정렬되는 키-값(key-value) 쌍을 저장하는 컨테이너**입니다. 내부적으로 \*\*균형 이진 탐색 트리(Red-Black Tree)\*\*를 사용하여 정렬을 유지하며, \*\*삽입/탐색/삭제 모두 O(log N)\*\*의 시간복잡도를 가집니다.

```cpp
#include <map>
```

---

## 🔸 기본 사용법

```cpp
#include <map>
#include <string>

std::map<std::string, int> m;
m["apple"] = 3;
m["banana"] = 2;

std::cout << m["apple"]; // 3
```

> 존재하지 않는 키를 `[]`로 접근하면 새로 삽입되며 기본값(0, "")이 들어감

---

## 🧩 특징 요약

| 항목       | 설명                                |
| -------- | --------------------------------- |
| 내부 구조    | Red-Black Tree (균형 이진 탐색 트리)      |
| 정렬       | 키 기준 **오름차순 자동 정렬**               |
| 중복 키     | ❌ 허용 안 됨 (`multimap`은 허용)         |
| 탐색 시간복잡도 | O(log N)                          |
| 정렬 기준 변경 | 사용자 정의 비교 함수 (예: greater<>) 사용 가능 |
| 키 순회     | iterator 사용 시 **정렬된 순서**로 순회됨     |

---

## 🟢 주요 함수

```cpp
std::map<int, std::string> m;

m[1] = "one";
m.insert({2, "two"});
m.emplace(3, "three");

m.find(1);        // key가 있으면 iterator, 없으면 m.end()
m.count(2);       // key가 있으면 1, 없으면 0
m.erase(3);       // key 삭제
m.clear();        // 전체 삭제
m.size();         // 요소 개수
m.empty();        // 비어있는지 확인
```

---

## 🟡 반복자 사용 예시

```cpp
for (const auto& [key, value] : m) {
    std::cout << key << ": " << value << "\n";
}
```

> 항상 **정렬된 순서**로 출력됨

---

## 🔵 사용자 정의 정렬 기준

```cpp
std::map<int, std::string, std::greater<>> m; // 내림차순 정렬
```

또는 사용자 정의 비교 함수 사용 가능:

```cpp
struct CustomCmp {
    bool operator()(const int& a, const int& b) const {
        return a > b; // 내림차순
    }
};

std::map<int, std::string, CustomCmp> m;
```

---

## ⚠️ 주의 사항

* `m[key]`는 존재하지 않아도 기본값으로 자동 삽입됩니다. 읽기만 할 경우 `find()`를 사용하는 것이 안전합니다.
* 트리 구조이므로 순서가 중요하지 않은 경우에는 `unordered_map`이 더 빠를 수 있습니다.
* `map`은 키의 `operator<`가 반드시 정의되어 있어야 합니다. (사용자 정의 자료형은 오버로딩 필요)

---

## 🆚 `map` vs `unordered_map`

| 항목       | `map`          | `unordered_map`      |
| -------- | -------------- | -------------------- |
| 내부 구조    | Red-Black Tree | Hash Table           |
| 자동 정렬    | 🔼 오름차순        | ❌ 없음                 |
| 평균 탐색 시간 | O(log N)       | O(1)                 |
| 순회 순서    | 정렬된 순서         | 불확실                  |
| 키 조건     | `operator<` 필요 | `std::hash`, `==` 필요 |
| 메모리 사용량  | 적음             | 상대적으로 큼              |
| 충돌 위험    | 없음             | 충돌 가능성 있음            |

---

## ✅ 요약

* 키를 자동으로 **정렬된 상태로 유지**하고 싶다면 `map`을 사용하세요.
* 삽입/삭제/탐색 모두 O(log N)으로 균형 잡힌 성능.
* 순서가 필요 없다면 `unordered_map`이 더 빠르고, 중복된 키를 허용하려면 `multimap` 사용.
