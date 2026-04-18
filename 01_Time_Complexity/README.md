# Time Complexity



---

## Table of Contents

1. [What is Time Complexity?](#1-what-is-time-complexity)
2. [Asymptotic Notations](#2-asymptotic-notations)
3. [Rules of Big O](#3-rules-of-big-o)
4. [Common Time Complexities with Examples](#4-common-time-complexities-with-examples)
   - [O(1) — Constant Time](#o1--constant-time)
   - [O(N) — Linear Time](#on--linear-time)
   - [O(N + M) — Two Independent Loops](#on--m--two-independent-loops)
   - [O(N²) — Quadratic Time](#on--quadratic-time)
   - [O(N³) — Cubic Time](#on--cubic-time)
   - [O(log N) — Logarithmic Time](#olog-n--logarithmic-time)
5. [Mathematical Proof: Why Binary Search is O(log N)](#5-mathematical-proof-why-binary-search-is-olog-n)
6. [Special Pattern: Geometric Series](#6-special-pattern-geometric-series)
7. [Practice Problems](#7-practice-problems)
8. [Summary](#8-summary)

---

## 1. What is Time Complexity?

**Time complexity** describes how the runtime of an algorithm scales as the input size grows. It does not measure actual execution time in seconds — it measures the *rate of growth* of operations relative to input size `N`.

### Why it matters

- **Interviews**: Interviewers almost always ask about the time complexity of your solution. An inefficient solution, even if correct, is often rejected.
- **Competitive Programming**: Online judges enforce strict time limits. Knowing complexity helps you predict whether your solution will pass before submitting.
- **System Design**: Understanding growth rates helps you choose the right algorithm for large-scale problems.

---

## 2. Asymptotic Notations

Asymptotic notations are mathematical tools used to describe the behavior of an algorithm as the input size approaches infinity.

| Notation       | Name        | Describes      |
|----------------|-------------|----------------|
| O (Big O)      | Big O       | Worst case     |
| Θ (Big Theta)  | Big Theta   | Average case   |
| Ω (Big Omega)  | Big Omega   | Best case      |

> **Note:** In interviews and competitive programming, **Big O (worst case)** is the standard. Always analyze and report worst-case complexity unless explicitly asked otherwise.

---

## 3. Rules of Big O

### Rule 1: Ignore Constants

Constants do not affect the rate of growth, so they are dropped.

```
O(2N)    →  O(N)
O(500)   →  O(1)
O(3N²)   →  O(N²)
```

### Rule 2: Drop Non-Dominant Terms

When multiple terms are present, only the fastest-growing term is kept.

```
O(N + N²)       →  O(N²)
O(N² + log N)   →  O(N²)
O(N + 100)      →  O(N)
```

**Rationale:** As `N` approaches infinity, smaller terms become negligible compared to the dominant term.

---

## 4. Common Time Complexities with Examples

### O(1) — Constant Time

The algorithm performs a fixed number of operations regardless of input size.

**Example 1: Formula-based computation**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    cout << sum << endl;
    return 0;
}
```

**Example 2: Fixed-iteration loop**

Even though this loop runs 1,000,000 times, the number of iterations does not depend on `n`. It is still O(1).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 1000000; i++)
    {
        // some operation
    }
    return 0;
}
```

---

### O(N) — Linear Time

The number of operations grows linearly with input size.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
```

The loop runs exactly `N` times → **O(N)**.

---

### O(N + M) — Two Independent Loops

When two separate loops iterate over different input sizes, the total complexity is the sum.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int c[n + m];
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            c[i] = a[i];
        else
            c[i] = b[i - n];
    }

    for (int i = 0; i < n + m; i++)
        cout << c[i] << " ";

    return 0;
}
```

Total operations: `N + M + (N + M) + (N + M)` → simplified to **O(N + M)**.

---

### O(N²) — Quadratic Time

Nested loops where both iterate up to `N` (or `M`) produce quadratic complexity.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << i << " " << j << endl;
        }
    }

    return 0;
}
```

Outer loop: `N` iterations. Inner loop: `M` iterations each. Total: `N * M` → **O(N²)** when `N ≈ M`.

---

### O(N³) — Cubic Time

Three nested loops produce cubic complexity.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, o;
    cin >> n >> m >> o;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < o; k++)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }

    return 0;
}
```

Total: `N * M * O` → **O(N³)** when all dimensions are equal.

---

### O(log N) — Logarithmic Time

The search space is halved on every iteration. Binary search is the canonical example.

```cpp
int bsearch(int a[], int n, int tar)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == tar) return mid;
        if (a[mid] > tar)  r = mid - 1;
        else               l = mid + 1;
    }
    return -1;
}
```

---

## 5. Mathematical Proof: Why Binary Search is O(log N)

Each iteration eliminates half of the remaining search space:

```
Step 0:  N
Step 1:  N / 2
Step 2:  N / 4
Step 3:  N / 8
  ...
Step K:  N / 2^K
```

The algorithm terminates when the search space reaches 1:

```
N / 2^K = 1
→ 2^K = N
→ log₂(2^K) = log₂(N)
→ K = log₂(N)         [since logₐ(aˣ) = x]
```

Therefore, binary search performs at most **K = log₂(N)** iterations → **O(log N)**.

---

## 6. Special Pattern: Geometric Series

Consider the following code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i *= 2)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

### Analysis

- The outer loop runs `log₂(N)` times (since `i` doubles each iteration: `1, 2, 4, 8, ..., N`).
- The inner loop runs `i` times for each value of `i`.

Total inner loop iterations:

```
S = 1 + 2 + 4 + 8 + ... + N
```

This is a **geometric series** with:
- First term `a = 1`
- Common ratio `r = 2`
- Number of terms `k = log₂(N)`

### Geometric Series Sum Formula

```
S = a * (r^k - 1) / (r - 1)
S = 1 * (2^(log₂N) - 1) / (2 - 1)
S = 2^(log₂N) - 1
S = N - 1           [since 2^(log₂N) = N]
```

Dropping the constant:

```
S = N - 1  →  O(N)
```

**Conclusion:** Despite the nested structure, the total work done is **O(N)**, not O(N log N).

---

## 7. Practice Problems

Determine the time complexity of each program. Do not look up the answer — work through it step by step.

### Problem 1

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n / i; j++)
        {
            cout << j << endl;
        }
    }

    return 0;
}
```

*Hint: The inner loop bound decreases as `i` increases. Think about the harmonic series.*

---

### Problem 2

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

*Hint: How many times can you divide `n` by 5 before reaching 1? Think logarithms.*

---

## 8. Summary

### Common Complexities at a Glance

| Complexity   | Name         | Typical Trigger                        | Example                    |
|--------------|--------------|----------------------------------------|----------------------------|
| O(1)         | Constant     | Fixed operations, formula              | Sum formula, hash lookup   |
| O(log N)     | Logarithmic  | Halving search space each step         | Binary search              |
| O(N)         | Linear       | Single loop over input                 | Linear scan, prefix sum    |
| O(N log N)   | Linearithmic | Divide and sort/merge                  | Merge sort, heap sort      |
| O(N²)        | Quadratic    | Nested loops                           | Bubble sort, brute force   |
| O(N³)        | Cubic        | Triple nested loops                    | Matrix multiplication      |
| O(2^N)       | Exponential  | All subsets / recursive branching      | Subset enumeration         |
| O(N!)        | Factorial    | All permutations                       | Brute-force permutations   |

### When to Use Each

- **O(1) / O(log N)**: Preferred for search and lookup operations. Always aim here if possible.
- **O(N) / O(N log N)**: Acceptable for most standard problems. Typical of sorting and single-pass algorithms.
- **O(N²)**: Acceptable only for small inputs (N ≤ 10³). Avoid for large datasets.
- **O(N³) and beyond**: Only feasible for very small inputs (N ≤ 10²). Use with caution.

### General Input Size Guidelines

| Input Size (N)  | Acceptable Complexity |
|-----------------|-----------------------|
| N ≤ 10          | O(N!) or O(2^N)       |
| N ≤ 20          | O(2^N)                |
| N ≤ 100         | O(N³)                 |
| N ≤ 1,000       | O(N²)                 |
| N ≤ 10⁵         | O(N log N)            |
| N ≤ 10⁶         | O(N)                  |
| N ≤ 10⁸         | O(log N) or O(1)      |

---


