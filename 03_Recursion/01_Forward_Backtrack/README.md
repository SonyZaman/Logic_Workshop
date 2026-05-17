# Forward vs Backtrack in Recursion

Understanding the difference between forward and backtrack recursion is crucial for solving recursive problems.

## Concept

The key difference is **when you do your work** relative to the recursive call:

- **Forward:** Do work **before** the recursive call
- **Backtrack:** Do work **after** the recursive call

## Forward Recursion

Work is done **before** making the recursive call. You process the current state, then recurse.

```cpp
void forward(int n) {
    if (n == 0) return;
    cout << n << " ";        // Work done BEFORE recursion
    forward(n - 1);          // Then recurse
}
```

**Call stack visualization for forward(3):**
```
forward(3) → print 3 → forward(2) → print 2 → forward(1) → print 1 → forward(0) → return
Output: 3 2 1
```

## Backtrack Recursion

Work is done **after** the recursive call returns. You recurse first, then process when coming back.

```cpp
void backtrack(int n) {
    if (n == 0) return;
    backtrack(n - 1);        // Recurse FIRST
    cout << n << " ";        // Work done AFTER recursion returns
}
```

**Call stack visualization for backtrack(3):**
```
backtrack(3) → backtrack(2) → backtrack(1) → backtrack(0) → return
                                                           ← print 1
                                              ← print 2
                               ← print 3
Output: 1 2 3
```

## Four Patterns Implemented

### 1. Forward: 1 to n

Print numbers from 1 to n in ascending order.

```cpp
void forward_1_to_n(int i, int n) {
    if (i > n) return;
    cout << i << " ";           // Print current
    forward_1_to_n(i + 1, n);   // Recurse with i+1
}
```

**Call:** `forward_1_to_n(1, 5)`  
**Output:** `1 2 3 4 5`

**How it works:**
- Start with i=1, print 1, recurse with i=2
- i=2, print 2, recurse with i=3
- Continue until i > n

---

### 2. Forward: n to 1

Print numbers from n to 1 in descending order.

```cpp
void forward_n_to_1(int n) {
    if (n == 0) return;
    cout << n << " ";           // Print current
    forward_n_to_1(n - 1);      // Recurse with n-1
}
```

**Call:** `forward_n_to_1(5)`  
**Output:** `5 4 3 2 1`

**How it works:**
- Start with n=5, print 5, recurse with n=4
- n=4, print 4, recurse with n=3
- Continue until n = 0

---

### 3. Backtrack: n to 1

Print numbers from n to 1 using backtracking.

```cpp
void backtrack_n_to_1(int i, int n) {
    if (i > n) return;
    backtrack_n_to_1(i + 1, n);  // Recurse FIRST
    cout << i << " ";             // Print AFTER returning
}
```

**Call:** `backtrack_n_to_1(1, 5)`  
**Output:** `5 4 3 2 1`

**How it works:**
- Go deep: 1 → 2 → 3 → 4 → 5 → base case
- Come back printing: 5, 4, 3, 2, 1

---

### 4. Backtrack: 1 to n

Print numbers from 1 to n using backtracking.

```cpp
void backtrack_1_to_n(int n) {
    if (n == 0) return;
    backtrack_1_to_n(n - 1);     // Recurse FIRST
    cout << n << " ";             // Print AFTER returning
}
```

**Call:** `backtrack_1_to_n(5)`  
**Output:** `1 2 3 4 5`

**How it works:**
- Go deep: 5 → 4 → 3 → 2 → 1 → 0 (base case)
- Come back printing: 1, 2, 3, 4, 5

---

## Visual Comparison

For n = 3:

### Forward 1 to n:
```
Call: f(1,3)
  Print 1
  Call: f(2,3)
    Print 2
    Call: f(3,3)
      Print 3
      Call: f(4,3) → return
Output: 1 2 3
```

### Backtrack 1 to n:
```
Call: b(3)
  Call: b(2)
    Call: b(1)
      Call: b(0) → return
      Print 1
    Print 2
  Print 3
Output: 1 2 3
```

## Key Differences

| Aspect | Forward | Backtrack |
|--------|---------|-----------|
| Work timing | Before recursion | After recursion |
| Traversal | Top to bottom | Bottom to top |
| Use case | Process while going down | Process while coming back |
| Example | Print while descending | Print while ascending |

## When to Use Which?

### Use Forward when:
- You need to process data while going deeper
- Building something from top to bottom
- Passing information down the recursion
- Example: Printing in descending order

### Use Backtrack when:
- You need to process data while returning
- Building something from bottom to top
- Collecting results from deeper calls
- Example: Calculating sum, finding max, checking sorted

## Time and Space Complexity

Both patterns:
- **Time:** O(n) - each number processed once
- **Space:** O(n) - recursion call stack

## Important Notes

- Forward: work → recurse
- Backtrack: recurse → work
- Both achieve different outputs with same input
- Backtracking is powerful for collecting results from recursive calls
- Understanding this is key to solving tree and graph problems

## Real-World Analogy

**Forward (Going down stairs):**
- Count steps as you go down: 1, 2, 3, 4, 5

**Backtrack (Coming up stairs):**
- Go all the way down first
- Count steps as you come back up: 1, 2, 3, 4, 5

## Practice Tip

Try both patterns for the same problem to understand the difference. Notice how the output changes based on when you do the work.
