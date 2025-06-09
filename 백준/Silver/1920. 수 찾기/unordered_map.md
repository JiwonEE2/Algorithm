# 📚 `unordered_map` 정리

`unordered_map`은 **해시 기반**의 연관 컨테이너로, 키(key) → 값(value) 쌍을 저장하며, \*\*검색/삽입/삭제가 평균 O(1)\*\*인 매우 빠른 자료구조입니다.

```cpp
#include <unordered_map>
```

---

## 🔸 기본 문법

```cpp
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> umap;
umap["apple"] = 5;
umap["banana"] = 2;

std::cout << umap["apple"]; // 5
```

---

## 🧩 특징 요약

| 항목          | `unordered_map`            |
| ----------- | -------------------------- |
| 내부 구조       | 해시 테이블                     |
| 정렬 여부       | ❌ 순서 없음                    |
| 키 탐색 시간     | 평균 O(1), 최악 O(N) (충돌 심할 때) |
| 중복 키        | ❌ 허용 안 함                   |
| iterator 순서 | 저장 순서 불확실                  |
| 헤더          | `#include <unordered_map>` |

---

## 🟢 주요 함수

```cpp
unordered_map<int, string> um;

um.insert({1, "one"});
um[2] = "two";

um.find(1);       // 존재하면 iterator 반환, 없으면 end()
um.count(3);      // key 3이 있으면 1, 없으면 0
um.erase(2);      // key 2 제거
um.clear();       // 전체 삭제
um.size();        // 요소 개수
um.empty();       // 비어있는지 확인
```

---

## 🔵 반복자 사용 예시

```cpp
for (auto& [key, value] : umap) {
    std::cout << key << ": " << value << "\n";
}
```

> 정렬되어 있지 않으므로, 순서가 계속 바뀔 수 있음

---

## 🔶 해시 충돌과 커스텀 키

* `unordered_map`은 **키에 대한 해시 함수를 사용**하여 내부 버킷에 저장
* 복합 키(pair, struct 등)를 사용할 경우 커스텀 해시 함수가 필요

```cpp
struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second << 1);
    }
};

std::unordered_map<std::pair<int, int>, int, PairHash> myMap;
```

---

## ⚠️ 주의 사항

* 순서가 보장되지 않기 때문에 정렬이 필요한 경우 `map` 또는 `vector + sort` 조합을 써야 함
* 키 타입은 반드시 `==` 연산자와 `std::hash<T>`가 정의되어 있어야 함
* 성능은 충돌이 적을 때만 O(1)이며, 충돌이 많아지면 최악의 경우 O(N)

---

## 🆚 `map` vs `unordered_map`

| 항목         | `map` (`<map>`)      | `unordered_map` (`<unordered_map>`) |
| ---------- | -------------------- | ----------------------------------- |
| 내부 구조      | Red-Black Tree (BST) | Hash Table                          |
| 정렬         | 🔼 자동 정렬             | ❌ 순서 없음                             |
| 탐색/삽입/삭제   | O(log N)             | 평균 O(1), 최악 O(N)                    |
| 메모리 사용량    | 상대적으로 적음             | 더 큼                                 |
| 키 정렬 필요 여부 | 필요할 때 유리             | 필요 없으면 유리                           |

---

## ✅ 요약

* **빠른 키 기반 탐색**이 필요한 경우 `unordered_map`을 사용하세요.
* **정렬된 순서로 접근**하거나, 최악의 시간복잡도가 중요한 상황에서는 `map`이 더 적합할 수 있습니다.
* **복합 자료형 키**를 쓸 경우 `hash`와 `==`를 커스터마이징 해야 함.
