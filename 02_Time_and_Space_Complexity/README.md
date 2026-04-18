# Time and Space Complexity

---

## Table of Contents

1. [Introduction](#1-introduction)
2. [Space Complexity Concepts](#2-space-complexity-concepts)
3. [Space Complexity Examples](#3-space-complexity-examples)
   - [O(1) Space](#o1-space)
   - [O(N) Space](#on-space)
   - [O(N²) Space](#on-space-1)
4. [Time and Space Combined Analysis](#4-time-and-space-combined-analysis)
5. [Prime Number Checking](#5-prime-number-checking)
   - [O(N) Time, O(1) Space — Version 1](#on-time-o1-space--version-1)
   - [O(N) Time, O(1) Space — Version 2](#on-time-o1-space--version-2)
   - [O(sqrt N) Time, O(1) Space](#osqrt-n-time-o1-space)
6. [O(N log N) Example](#6-on-log-n-example)
7. [Recursion Complexity](#7-recursion-complexity)
   - [O(N) Time, O(N) Space — Factorial](#on-time-on-space--factorial)
   - [O(2^N) Time, O(N) Space — Fibonacci](#o2n-time-on-space--fibonacci)
   - [O(N²) Time, O(N²) Space — Recursive with Array](#on-time-on-space--recursive-with-array)
8. [Harmonic Series Proof](#8-harmonic-series-proof)
9. [Geometric Series Proof](#9-geometric-series-proof)
10. [Practice Problems](#10-practice-problems)
11. [Summary](#11-summary)

---

## 1. Introduction

### Recap: Time Complexity

Time complexity describes how the number of operations an algorithm performs grows as the input size `N` increases. It is always analyzed in terms of the dominant term, ignoring constants.

### What is Space Complexity?

**Space complexity** describes how much memory an algorithm uses relative to the input size. There are two components:

| Type            | Description                                                                 |
|-----------------|-----------------------------------------------------------------------------|
| **Input Space** | Memory used to store the input data itself                                  |
| **Auxiliary Space** | Extra memory used by the algorithm beyond the input (variables, stacks, arrays) |

> **Standard convention:** Space complexity refers specifically to **auxiliary space**. Input space is generally excluded because it is considered a requirement of the problem, not the algorithm.

---

## 2. Space Complexity Concepts

### Auxiliary Space

Auxiliary space is the temporary or extra space an algorithm allocates beyond what is needed to hold the input. This includes:

- Local variables and counters
- Temporary arrays or data structures
- The call stack in recursive algorithms

### Why Input Space is Not Counted

The input must exist regardless of which algorithm you use. Counting it would unfairly penalize algorithms based on problem size rather than algorithmic design. Two different algorithms solving the same problem see the same input — only their auxiliary usage differs.

---

## 3. Space Complexity Examples

### O(1) Space

The algorithm uses only a constant number of extra variables, regardless of `N`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;                       // single extra variable
    for (int i = 0; i < n; i++)
        s += a[i];

    cout << s << endl;
    return 0;
}
```

`a[n]` is input space. The only auxiliary variable is `s` → **O(1) auxiliary space**.

---

### O(N) Space

The algorithm allocates an additional array of size `N` as auxiliary storage.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b[n];                        // auxiliary array of size N
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";

    return 0;
}
```

`b[n]` is the auxiliary array → **O(N) space**.

---

### O(N²) Space

The algorithm allocates a 2D array of size `N x N`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][n];                     // N x N auxiliary matrix

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = i + j;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
```

The matrix `a[n][n]` stores `N²` elements → **O(N²) space**.

---

## 4. Time and Space Combined Analysis

Every algorithm has both a time complexity and a space complexity. They are analyzed independently and reported together.

```
Algorithm:  Binary Search
Time:       O(log N)
Space:      O(1)           (iterative version)
```

### The Time-Space Trade-off

Improving time often requires using more space, and reducing space often means doing more work.

| Scenario                        | Effect                              |
|---------------------------------|-------------------------------------|
| Cache intermediate results      | Faster time, more space             |
| Recompute values instead        | Less space, slower time             |
| Use in-place algorithms         | O(1) space, sometimes slower time   |

In interviews, if you are asked to optimize, clarify whether to optimize for **time** or **space** — they are often in conflict.

---

## 5. Prime Number Checking

### O(N) Time, O(1) Space — Version 1

Check every divisor from `2` to `n - 1`.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (isPrime(n) ? "yes" : "no") << endl;
    return 0;
}
```

Checks up to `n - 1` divisors → **O(N) time, O(1) space**.

---

### O(N) Time, O(1) Space — Version 2

Check only up to `n / 2`. If `n` has a divisor larger than `n / 2`, it must be `n` itself.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (isPrime(n) ? "yes" : "no") << endl;
    return 0;
}
```

Halved loop iterations, but still grows linearly → **O(N) time, O(1) space**.

---

### O(sqrt N) Time, O(1) Space

Only check divisors up to `sqrt(N)`.

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << (isPrime(n) ? "yes" : "no") << endl;
    return 0;
}
```

### Why sqrt(N) Works

If `n` is divisible by some integer `d`, then:

```
n = d * (n / d)
```

One of the two factors must be ≤ sqrt(N). If both were greater than sqrt(N), their product would exceed `n` — a contradiction. Therefore, if no divisor exists up to sqrt(N), none exists at all.

This reduces the loop from `N` iterations to `sqrt(N)` iterations → **O(sqrt N) time, O(1) space**.

---

## 6. O(N log N) Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)       // runs N times
    {
        for (int j = 1; j <= n; j *= 2) // runs log₂(N) times
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

- **Outer loop**: runs `N` times → O(N)
- **Inner loop**: `j` doubles each iteration (`1, 2, 4, ..., N`), so it runs `log₂(N)` times → O(log N)
- **Total**: `N * log₂(N)` → **O(N log N)**

---

## 7. Recursion Complexity

> **Key point:** Every recursive call adds a new frame to the **call stack**. The maximum depth of the recursion determines the auxiliary space used.

---

### O(N) Time, O(N) Space — Factorial

```cpp
#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}
```

- Each call reduces `n` by 1 → `N` calls total → **O(N) time**
- Up to `N` frames on the call stack at once → **O(N) auxiliary space**

---

### O(2^N) Time, O(N) Space — Fibonacci

```cpp
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
```

- Each call branches into two → the call tree has approximately `2^N` nodes → **O(2^N) time**
- Maximum call stack depth at any point is `N` → **O(N) auxiliary space**

> This is very inefficient. Memoization (Dynamic Programming) reduces it to O(N) time.

---

### O(N²) Time, O(N²) Space — Recursive with Array

```cpp
#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if (n == 0) return 0;
    int a[n];                        // allocates N elements per call
    for (int i = 0; i < n; i++)
        a[i] = i;
    return a[n - 1] + fun(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}
```

- Loop inside each call runs `n` times. Total work: `N + (N-1) + ... + 1 = N(N+1)/2` → **O(N²) time**
- Each of the `N` active stack frames holds an array (`N, N-1, ..., 1`). Total: `N + (N-1) + ... + 1` → **O(N²) auxiliary space**

---

## 8. Harmonic Series Proof

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)      // outer: N iterations
    {
        for (int j = 1; j <= n / i; j++) // inner: N/i iterations
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

### Analysis

The inner loop runs `N/i` times for each value of `i`. Total iterations:

```
S = N/1 + N/2 + N/3 + N/4 + ... + N/N
S = N * (1 + 1/2 + 1/3 + 1/4 + ... + 1/N)
S = N * H(N)
```

where `H(N)` is the **N-th harmonic number**.

### Proof that H(N) = O(log N)

Group the terms of the harmonic series by powers of 2:

```
H(N) = 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 + 1/8 + ...

Group 0:  1                              = 1
Group 1:  1/2 + 1/3                     < 1
Group 2:  1/4 + 1/5 + 1/6 + 1/7        < 1
Group 3:  1/8 + 1/9 + ... + 1/15       < 1
Group 4:  1/16 + ... + 1/31            < 1
  ...
Group k:  1/2^k + ... + 1/(2^(k+1)-1)  < 1
```

Each group sums to less than 1. The number of groups up to `N` is approximately `log₂(N)`.

```
H(N) < log₂(N) + 1
H(N) = O(log N)
```

Therefore:

```
S = N * H(N) = N * O(log N) = O(N log N)
```

**Conclusion:** The nested loop above has a time complexity of **O(N log N)**.

---

## 9. Geometric Series Proof

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n; i >= 1; i /= 5)    // outer: log₅(N) iterations
    {
        for (int j = 1; j <= i; j++)    // inner: i iterations
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

### Analysis

The outer loop produces values of `i`: `N, N/5, N/25, N/125, ..., 1`

The inner loop runs `i` times for each value. Total iterations:

```
S = N + N/5 + N/25 + N/125 + ...
```

This is a geometric series with:

| Parameter | Value      |
|-----------|------------|
| First term `a` | `N`   |
| Common ratio `r` | `1/5` |
| Number of terms `k` | `log₅(N)` |

### Derivation

Using the geometric series sum formula:

```
S = a * (1 - r^k) / (1 - r)
S = N * (1 - (1/5)^(log₅N)) / (1 - 1/5)
S = N * (1 - 1/N) / (4/5)          [since 5^(log₅N) = N]
S = (5N/4) * (1 - 1/N)
S = (5N/4) - (5/4)
S = O(N)
```

**Conclusion:** Despite the nested structure, the total work is **O(N)**.

---

## 10. Practice Problems

Determine the time and space complexity of each program. Work through the analysis independently before verifying.

### Problem 1

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n; i >= 1; i /= 5)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

*Hint: What values does `i` take? How many outer iterations are there? What does the inner loop sum to?*

---

## 11. Summary

### Common Time and Space Complexities

| Complexity     | Time Description          | Space Description               | Example                         |
|----------------|---------------------------|----------------------------------|---------------------------------|
| O(1)           | Constant time             | Constant auxiliary space         | Formula, hash lookup            |
| O(log N)       | Logarithmic time          | O(1) or O(log N) (recursion)    | Binary search                   |
| O(sqrt N)      | Square root time          | O(1)                            | Optimized prime check           |
| O(N)           | Linear time               | O(1) or O(N)                    | Linear scan, factorial recursion|
| O(N log N)     | Linearithmic time         | O(1) or O(log N)                | Merge sort, harmonic loop       |
| O(N²)          | Quadratic time            | O(1) or O(N²)                   | Nested loops, bubble sort       |
| O(2^N)         | Exponential time          | O(N) (call stack depth)         | Naive Fibonacci                 |

### Key Takeaways

- Space complexity almost always refers to **auxiliary space**, not input space.
- Recursion uses **O(depth)** stack space, even if no explicit arrays are allocated.
- A nested loop does not automatically mean O(N²) — always analyze inner loop bounds carefully.
- The harmonic series `1 + 1/2 + 1/3 + ... + 1/N` sums to `O(log N)`.
- A geometric series with ratio `< 1` always converges to a constant multiple of its first term → **O(first term)**.

### Interview Tips

- Always state **both** time and space complexity when discussing a solution.
- If the interviewer asks to optimize, clarify: optimize for time, space, or both?
- For recursive solutions, remember to account for call stack space.
- Recognize the `i *= 2` and `i /= k` patterns immediately as `O(log N)` loops.
- Recognize the `j <= n / i` inner loop pattern as the harmonic series → `O(N log N)`.
