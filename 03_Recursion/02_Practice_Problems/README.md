# Recursion Practice Problems

Collection of problems to practice recursion concepts, focusing on backtracking patterns.

## Problems

### 1. Check if Array is Sorted (`01_Check_Sorted.cpp`)

Check if an array is sorted in non-decreasing order using recursion.

**Approach:**
- Use backtracking: recurse first, then check
- Base case: reached last element (sorted by default)
- Check if current element ≤ next element
- Combine result with recursive call using AND

```cpp
bool checkSort(int n, int i, vector<int>& v) {
    if (i == (n - 1)) return true;  // Last element, sorted
    
    bool recursion_result = checkSort(n, i + 1, v);  // Check rest
    bool my_result = (v[i] <= v[i + 1]);             // Check current
    
    return recursion_result && my_result;             // Both must be true
}
```

**Example:**
```
Input: [1, 4, 6, 9, 11]
Output: true

Input: [1, 4, 6, 9, 11, 10]
Output: false
```

**Time:** O(n) - check each pair once  
**Space:** O(n) - recursion stack

**Key Insight:** Backtracking allows us to check from the end and combine results as we return.

---

### 2. Count Zeros in a Number (`02_Count_Zero_In_Number.cpp`)

Count how many zeros are in a given number using recursion.

**Approach:**
- Use backtracking: recurse first with n/10, then check last digit
- Base case: n == 0, return 0
- Extract last digit using n % 10
- If last digit is 0, add 1 to recursive result

```cpp
int countZero(int n) {
    if (n == 0) return 0;
    
    int recursion_result = countZero(n / 10);  // Count in rest
    int last_digit = n % 10;
    
    return (last_digit == 0) ? recursion_result + 1 : recursion_result;
}
```

**Example:**
```
Input: 102030
Process: 102030 → 10203 → 1020 → 102 → 10 → 1 → 0
Zeros found: at 10203(0), 102(0), 1(0) = 3 zeros
Output: 3

Input: 12345
Output: 0
```

**Time:** O(d) where d is number of digits  
**Space:** O(d) - recursion stack

**Edge Case:** Input is 0 → output should be 1 (handled separately in main)

**Key Insight:** Process digits from right to left by dividing by 10 each time.

---

### 3. Find Maximum Number in Array (`03_Find_Max_Number.cpp`)

Find the maximum element in an array using recursion.

**Approach:**
- Use backtracking: recurse first, then compare
- Base case: reached last element, return it
- Get max from rest of array recursively
- Compare current element with recursive result
- Return the larger one

```cpp
int findMax(vector<int>& v, int index) {
    if (index == v.size() - 1) return v[index];  // Last element
    
    int max_from_rest = findMax(v, index + 1);   // Max from rest
    int current_max = (v[index] >= max_from_rest) ? v[index] : max_from_rest;
    
    return current_max;
}
```

**Example:**
```
Input: [5, 2, 20, 6, 3, 7]
Process:
  findMax([5,2,20,6,3,7], 0)
    findMax([2,20,6,3,7], 1)
      findMax([20,6,3,7], 2)
        findMax([6,3,7], 3)
          findMax([3,7], 4)
            findMax([7], 5) → return 7
          compare 3 vs 7 → return 7
        compare 6 vs 7 → return 7
      compare 20 vs 7 → return 20
    compare 2 vs 20 → return 20
  compare 5 vs 20 → return 20
Output: 20
```

**Time:** O(n) - visit each element once  
**Space:** O(n) - recursion stack

**Key Insight:** Build the answer from the end, comparing as we return from recursive calls.

---

## Common Pattern: Backtracking

All three problems use the **backtracking pattern**:

```cpp
returnType solve(parameters) {
    // Base case
    if (base_condition) return base_value;
    
    // Recurse FIRST (go deep)
    returnType recursive_result = solve(modified_parameters);
    
    // Do work AFTER recursion returns (coming back)
    returnType my_result = process_current();
    
    // Combine and return
    return combine(recursive_result, my_result);
}
```

## Why Backtracking?

These problems need information from the **rest** of the data structure before making a decision about the current element:

- **Check Sorted:** Need to know if rest is sorted
- **Count Zeros:** Need count from rest of digits
- **Find Max:** Need max from rest of array

## Recursion Visualization

### Check Sorted [1, 4, 6]:
```
checkSort(0)
  checkSort(1)
    checkSort(2) → return true (base case)
    1 <= 4? true
  return true && true = true
  4 <= 6? true
return true && true = true
```

### Count Zeros in 102:
```
countZero(102)
  countZero(10)
    countZero(1)
      countZero(0) → return 0 (base case)
      1 % 10 = 1 (not 0)
    return 0
    10 % 10 = 0 (is 0!)
  return 0 + 1 = 1
  102 % 10 = 2 (not 0)
return 1
```

### Find Max [5, 20, 3]:
```
findMax(0)
  findMax(1)
    findMax(2) → return 3 (base case)
    20 vs 3 → return 20
  5 vs 20 → return 20
```

## Time and Space Complexity

| Problem | Time | Space | Reason |
|---------|------|-------|--------|
| Check Sorted | O(n) | O(n) | Visit each element, n recursive calls |
| Count Zeros | O(d) | O(d) | d digits, d recursive calls |
| Find Max | O(n) | O(n) | Visit each element, n recursive calls |

Where n = array size, d = number of digits

## Key Takeaways

1. **Backtracking pattern:** Recurse first, process after
2. **Base case:** Always define when to stop
3. **Combine results:** Use AND, OR, +, max, etc. to combine
4. **Trust recursion:** Assume recursive call works correctly
5. **Build from end:** Results are built as we return from calls

## Common Mistakes

1. **Forgetting base case:** Leads to infinite recursion
2. **Wrong base case:** Returns incorrect value
3. **Not combining results:** Forgetting to use recursive result
4. **Index out of bounds:** Not checking array boundaries
5. **Stack overflow:** Too deep recursion for large inputs

## Practice Tips

1. Draw the recursion tree for small inputs
2. Trace the call stack manually
3. Identify the base case first
4. Think: "What do I need from the rest?"
5. Combine your work with recursive result

## Extension Ideas

Try these variations:
- Check if array is sorted in descending order
- Count specific digit (not just zeros)
- Find minimum instead of maximum
- Find second maximum
- Check if array is strictly increasing (no equals)

## When to Use Recursion

**Good for:**
- Problems with recursive structure (trees, graphs)
- Divide and conquer problems
- Backtracking problems
- When solution depends on subproblems

**Not ideal for:**
- Simple loops (overhead of function calls)
- Very deep recursion (stack overflow risk)
- When iterative solution is simpler
