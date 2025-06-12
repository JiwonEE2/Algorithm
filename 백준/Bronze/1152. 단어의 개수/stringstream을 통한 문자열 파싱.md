# 📦 `stringstream`을 이용한 문자열 파싱

`std::stringstream`은 `#include <sstream>`에 포함되어 있으며, 문자열을 마치 입력 스트림처럼 다룰 수 있게 해줍니다.

---

## ✅ 기본 사용법

```cpp
#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::string input = "10 20 30";
    std::stringstream ss(input);

    int a, b, c;
    ss >> a >> b >> c;

    std::cout << a << ' ' << b << ' ' << c << '\n';
}
```

* `"10 20 30"` 문자열을 공백 기준으로 나눠 각각 변수에 저장

---

## 🧩 반복적으로 분할하기 (공백 기준)

```cpp
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::string input = "apple banana cherry";
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> result;

    while (ss >> word) {
        result.push_back(word);
    }

    for (const auto& w : result) {
        std::cout << w << '\n';
    }
}
```

---

## 📌 쉼표(,) 등 구분자가 있는 경우 → `getline()` 사용

```cpp
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::string input = "1,2,3,4,5";
    std::stringstream ss(input);
    std::string token;
    std::vector<int> nums;

    while (std::getline(ss, token, ',')) {
        nums.push_back(std::stoi(token));
    }

    for (int n : nums) {
        std::cout << n << ' ';
    }
}
```

* `getline(stream, 변수, 구분자)` 형식 사용

---

## 🔁 실전 예시: 한 줄에 숫자가 여러 개 주어질 때 처리

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    int num;
    std::vector<int> numbers;

    while (ss >> num) {
        numbers.push_back(num);
    }

    for (int n : numbers) std::cout << n << ' ';
}
```

* 한 줄에 `"10 23 55"` 입력하면 `[10, 23, 55]` 벡터로 저장됨

---

## 📎 요약

| 용도            | 방법/함수                         |
| ------------- | ----------------------------- |
| 문자열을 스트림처럼 사용 | `std::stringstream ss(str)`   |
| 공백 기준 분할      | `ss >> 변수`                    |
| 특정 구분자 기준 분할  | `std::getline(ss, 변수, 구분자)`   |
| 문자열 → 숫자 변환   | `std::stoi`, `std::stod` 등 사용 |
