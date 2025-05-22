# C++ 문자열, 정수, 문자 간 변환 정리

---

## 📌 1. string ↔ int

### 🔹 string → int

```cpp
#include <string>
#include <iostream>
using namespace std;

string s = "123";
int n = stoi(s);     // 123
```

| 함수      | 설명                    |
| ------- | --------------------- |
| `stoi`  | string → int 변환       |
| `stol`  | string → long 변환      |
| `stoll` | string → long long 변환 |

> 예외: 문자열이 숫자가 아니거나 범위를 초과하면 `invalid_argument`, `out_of_range` 예외 발생

---

### 🔹 int → string

```cpp
int n = 456;
string s = to_string(n);  // "456"
```

| 함수          | 설명              |
| ----------- | --------------- |
| `to_string` | int → string 변환 |

---

## 📌 2. string ↔ char

### 🔹 string → char (한 글자 추출)

```cpp
string s = "abc";
char c = s[0];  // 'a'
```

### 🔹 char → string

```cpp
char c = 'x';
string s(1, c);  // "x"
```

또는

```cpp
string s = string(1, c);
```

---

## 📌 3. int ↔ char

### 🔹 int → char (숫자 '0' \~ '9')

```cpp
int n = 7;
char c = '0' + n;  // '7'
```

### 🔹 char → int (숫자 문자 → 정수)

```cpp
char c = '8';
int n = c - '0';   // 8
```

> 주의: 반드시 `'0'`\~`'9'` 범위 내인지 확인해야 함

---

## ✅ 요약

| 변환            | 방법                      |
| ------------- | ----------------------- |
| string → int  | `stoi`, `stol`, `stoll` |
| int → string  | `to_string(n)`          |
| string → char | `s[i]`                  |
| char → string | `string(1, c)`          |
| int → char    | `'0' + n`               |
| char → int    | `c - '0'`               |
