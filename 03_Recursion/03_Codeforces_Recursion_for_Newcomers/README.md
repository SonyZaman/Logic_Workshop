# Codeforces Recursion for Newcomers

Collection of 26 recursion problems from Codeforces, progressing from basic to advanced concepts.

## Problem Categories

### Basic Recursion (1-6)

#### 1. Print Recursion (`01_Print_Recursion.cpp`)
Print a message n times using recursion.

**Concept:** Basic recursion with forward traversal.

**Time:** O(n) | **Space:** O(n)

---

#### 2. Print 1 to N (`02_Print_1_to_N.cpp`)
Print numbers from 1 to N.

**Approach:** Forward recursion or backtracking.

**Time:** O(n) | **Space:** O(n)

---

#### 3. Print N to 1 (`03_Print_N_to_1.cpp`)
Print numbers from N to 1.

**Approach:** Forward recursion.

**Time:** O(n) | **Space:** O(n)

---

#### 4. Print Digits (`04_Print_Digits.cpp`)
Print digits of a number from left to right.

**Algorithm:**
1. Traverse from last to first digit (easy to get last digit with n%10)
2. Use backtracking to print from first to last
3. Recurse with n/10, then print n%10

```cpp
void printDigits(long long n) {
    if (n == 0) return;
    printDigits(n / 10);      // Recurse first
    cout << n % 10 << " ";    // Print after
}
```

**Example:**
```
Input: 12345
Output: 1 2 3 4 5
```

**Time:** O(d) where d = number of digits  
**Space:** O(d)

**Key Insight:** Backtracking reverses the natural right-to-left digit extraction.

---

#### 5. Base Conversion (`05_Base_Converssion.cpp`)
Convert a number to different base.

**Time:** O(log n) | **Space:** O(log n)

---

#### 6. Print Even Indices Reverse (`06_Print_Even_Indices_Reverse.cpp`)
Print elements at even indices in reverse order.

**Time:** O(n) | **Space:** O(n)

---

### Pattern Printing (7-8)

#### 7. Pyramid (`07_Pyramid.cpp`)
Print pyramid pattern using recursion.

**Time:** O(n²) | **Space:** O(n)

---

#### 8. Inverted Pyramid (`08_Inverted_Pyramid.cpp`)
Print inverted pyramid pattern.

**Time:** O(n²) | **Space:** O(n)

---

### String/Array Processing (9-14)

#### 9. Count Vowels (`09_Count_Vowels.cpp`)
Count vowels in a string using recursion.

**Algorithm:**
1. Base case: reached end of string, return 0
2. Recurse to count vowels in rest of string
3. Check if current character is vowel
4. Add 1 if vowel, else add 0

```cpp
int countVowels(string s, int idx) {
    if (s.length() == idx) return 0;
    
    int count_from_rest = countVowels(s, idx + 1);
    bool is_vowel = (s[idx]=='a' || s[idx]=='e' || s[idx]=='i' || 
                     s[idx]=='o' || s[idx]=='u' || 
                     s[idx]=='A' || s[idx]=='E' || s[idx]=='I' || 
                     s[idx]=='O' || s[idx]=='U');
    
    return is_vowel ? count_from_rest + 1 : count_from_rest;
}
```

**Time:** O(n) | **Space:** O(n)

---

#### 10. Factorial (`10_Factorial.cpp`)
Calculate n! using recursion.

**Formula:** n! = n × (n-1)!

```cpp
long long factorial(long long n) {
    if (n == 0 || n == 1) return 1;
    
    long long prev_factorial = factorial(n - 1);
    long long current_factorial = n * prev_factorial;
    
    return current_factorial;
}
```

**Example:**
```
5! = 5 × 4!
   = 5 × 4 × 3!
   = 5 × 4 × 3 × 2 × 1
   = 120
```

**Time:** O(n) | **Space:** O(n)

---

#### 11. Max Number (`11_Max_Number.cpp`)
Find maximum element in array.

**Time:** O(n) | **Space:** O(n)

---

#### 12. Summation (`12_Summation.cpp`)
Calculate sum of array elements.

**Algorithm:**
1. Base case: last element, return it
2. Get sum of rest from recursion
3. Add current element to that sum

```cpp
long long summation(vector<int>& v, int idx) {
    if ((v.size() - 1) == idx) return v[idx];
    
    long long sum_from_rest = summation(v, idx + 1);
    long long total_sum = sum_from_rest + v[idx];
    
    return total_sum;
}
```

**Time:** O(n) | **Space:** O(n)

---

#### 13. Suffix Sum (`13_Suffix_Sum.cpp`)
Calculate sum from index to end.

**Time:** O(n) | **Space:** O(n)

---

#### 14. Sum Matrix (`14_Sum_Matrix.cpp`)
Calculate sum of 2D matrix elements.

**Time:** O(n×m) | **Space:** O(n×m)

---

### Mathematical Recursion (15-20)

#### 15. Fibonacci (`15_fibonacci.cpp`)
Calculate nth Fibonacci number.

**Formula:** F(n) = F(n-1) + F(n-2)

```cpp
int fibonacci(int n) {
    if (n == 1 || n == 2) return n - 1;
    
    int second_last = fibonacci(n - 2);
    int last = fibonacci(n - 1);
    int current = second_last + last;
    
    return current;
}
```

**Sequence:** 0, 1, 1, 2, 3, 5, 8, 13, 21...

**Time:** O(2^n) - exponential (inefficient)  
**Space:** O(n)

**Note:** This naive approach is slow. Use memoization or DP for better performance.

---

#### 16. Log2 (`16_log2.cpp`)
Calculate floor(log₂(n)) using recursion.

**Time:** O(log n) | **Space:** O(log n)

---

#### 17. 3n+1 Sequence (`17_3n+1_Sequence.cpp`)
Collatz conjecture sequence.

**Time:** O(log n) average | **Space:** O(log n)

---

#### 18. Palindrome (`18_Palindrome.cpp`)
Check if array/string is palindrome.

**Algorithm:**
1. Use two pointers: start (i) and end (j)
2. Base case: i > j, return true
3. Recurse with i+1 and j-1
4. Check if elements at i and j are equal
5. Return true only if both current match AND rest is palindrome

```cpp
bool palindrome(vector<int>& v, int i, int j) {
    if (i > j) return true;
    
    bool rest_is_palindrome = palindrome(v, i + 1, j - 1);
    bool current_match = (v[i] == v[j]);
    
    return current_match && rest_is_palindrome;
}
```

**Example:**
```
[1, 2, 3, 2, 1]
Check: 1==1? Yes, recurse
Check: 2==2? Yes, recurse
Check: 3==3? Yes (base case)
Result: true
```

**Time:** O(n) | **Space:** O(n)

---

#### 19. Array Average (`19_Array_Average.cpp`)
Calculate average of array elements.

**Time:** O(n) | **Space:** O(n)

---

#### 20. nCr (`20_nCr.cpp`)
Calculate binomial coefficient C(n,r) = n!/(r!(n-r)!)

**Formula:** C(n,r) = C(n-1,r-1) × n / r

```cpp
long long nCr(int n, int r) {
    if (r == 0) return 1;
    
    long long rec_result = nCr(n - 1, r - 1);
    long long result = (rec_result * n) / r;
    
    return result;
}
```

**Example:**
```
C(5,2) = 5!/(2!×3!) = 10
```

**Time:** O(r) | **Space:** O(r)

---

### Advanced Problems (21-26)

#### 21. Knapsack (`21_Knapsack.cpp`)
0/1 Knapsack problem - maximize value within capacity.

**Concept:** For each item, decide to pick or not pick.

**Time:** O(2^n) | **Space:** O(n)

---

#### 22. Creating Expression (`22_Creating_Expression1.cpp`)
Create target value using +/- operators.

**Time:** O(2^n) | **Space:** O(n)

---

#### 23. Reach Value (`23_Reach_Value.cpp`)
Check if target can be reached using specific operations.

**Time:** O(log n) | **Space:** O(log n)

---

#### 24. Maximum Path Sum (`24_The_Maximum_Path-Sum.cpp`)
Find maximum sum path in grid/matrix.

**Time:** O(2^(n+m)) | **Space:** O(n+m)

---

#### 25. Number of Ways (`25_Number_of_Ways.cpp`)
Count ways to reach destination.

**Time:** O(2^n) | **Space:** O(n)

---

#### 26. Left Max (`26_Left_Max.cpp`)
Find maximum element to the left.

**Time:** O(n) | **Space:** O(n)

---

## Common Patterns

### 1. Forward Recursion
Do work before recursive call.
```cpp
void forward(int n) {
    if (n == 0) return;
    cout << n;           // Work first
    forward(n - 1);      // Then recurse
}
```

### 2. Backtracking
Do work after recursive call.
```cpp
void backtrack(int n) {
    if (n == 0) return;
    backtrack(n - 1);    // Recurse first
    cout << n;           // Work after
}
```

### 3. Divide and Conquer
Split problem into subproblems.
```cpp
int solve(int l, int r) {
    if (l == r) return base;
    int mid = (l + r) / 2;
    return combine(solve(l, mid), solve(mid+1, r));
}
```

### 4. Multiple Recursive Calls
Like Fibonacci, tree problems.
```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Two calls
}
```

## Complexity Patterns

| Pattern | Time | Space | Example |
|---------|------|-------|---------|
| Linear recursion | O(n) | O(n) | Factorial, Sum |
| Binary recursion | O(2^n) | O(n) | Fibonacci |
| Logarithmic | O(log n) | O(log n) | Binary search |
| Nested loops | O(n²) | O(n) | Matrix problems |

## Key Concepts

1. **Base Case:** When to stop recursing
2. **Recursive Case:** How to break down the problem
3. **Trust the Recursion:** Assume recursive call works
4. **Combine Results:** How to use recursive result
5. **Stack Space:** Each call uses memory

## Common Mistakes

1. **Missing base case** → infinite recursion
2. **Wrong base case** → incorrect result
3. **Not using recursive result** → incomplete solution
4. **Stack overflow** → too deep recursion
5. **Inefficient recursion** → exponential time (like naive Fibonacci)

## Optimization Techniques

1. **Memoization:** Cache results to avoid recomputation
2. **Tail Recursion:** Last operation is recursive call
3. **Iterative Conversion:** Convert to loop when possible
4. **Dynamic Programming:** Bottom-up approach

## Practice Strategy

**Beginner (1-10):**
- Master basic recursion
- Understand forward vs backtrack
- Practice with simple problems

**Intermediate (11-20):**
- Array/string processing
- Mathematical recursion
- Multiple base cases

**Advanced (21-26):**
- Decision problems (pick/not pick)
- Path finding
- Optimization problems

## Tips for Success

1. **Draw recursion tree** for small inputs
2. **Trace execution** manually
3. **Identify pattern** (forward/backtrack/divide)
4. **Start with base case**
5. **Trust the recursion** - don't overthink
6. **Practice daily** - recursion needs repetition

## When to Use Recursion

**Good for:**
- Tree/graph traversal
- Divide and conquer
- Backtracking
- Mathematical sequences

**Avoid when:**
- Simple iteration works
- Very deep recursion
- Performance critical
- Stack space limited

## Next Steps

1. Solve problems in order (1-26)
2. Understand each pattern
3. Practice similar problems
4. Learn memoization/DP
5. Move to tree/graph recursion
