# Stack Implementation

A stack is a linear data structure that follows the **LIFO (Last In First Out)** principle. The last element added is the first one to be removed.

## Concept

Think of a stack like a pile of plates:
- You add plates on top (push)
- You remove plates from the top (pop)
- You can only see the top plate

```
    [30]  <- top (most recent)
    [20]
    [10]  <- bottom (oldest)
```

## Implementation

This implementation uses a **doubly linked list** as the underlying data structure.

### Node Structure

```cpp
class Node {
    public:
        int val;
        Node* next;
        Node* prev;
};
```

Uses doubly linked list for O(1) deletion at tail.

### Stack Class

```cpp
class MyStack {
    private:
        LinkedList list;
        int sz;
    public:
        void push(int val);
        void pop();
        int top();
        int size();
        bool empty();
};
```

## Operations

### 1. Push

Add an element to the top of the stack.

**Implementation:**
- Insert at tail of the linked list
- Increment size counter

```cpp
void push(int val) {
    list.insertAtTail(val);
    sz++;
}
```

**Time:** O(1)  
**Space:** O(1)

---

### 2. Pop

Remove the top element from the stack.

**Implementation:**
- Delete at tail of the linked list
- Decrement size counter

```cpp
void pop() {
    list.deleteAtTail();
    if (sz) sz--;
}
```

**Time:** O(1) - thanks to tail pointer and prev link  
**Space:** O(1)

**Edge Case:** Popping from empty stack is handled by checking size.

---

### 3. Top

Get the value of the top element without removing it.

```cpp
int top() {
    return list.tail->val;
}
```

**Time:** O(1)  
**Space:** O(1)

**Important:** Should check if stack is empty before calling top.

---

### 4. Size

Return the number of elements in the stack.

```cpp
int size() {
    return sz;
}
```

**Time:** O(1)  
**Space:** O(1)

---

### 5. Empty

Check if the stack is empty.

```cpp
bool empty() {
    return list.head == NULL;
}
```

**Time:** O(1)  
**Space:** O(1)

---

## Why Doubly Linked List?

Using a doubly linked list allows:
- **O(1) push:** Insert at tail
- **O(1) pop:** Delete at tail (using prev pointer)
- **O(1) top:** Direct access via tail pointer

With a singly linked list, deleting at tail would be O(n) because you'd need to traverse to find the second-to-last node.

## Complexity Summary

| Operation | Time | Space |
|-----------|------|-------|
| push      | O(1) | O(1)  |
| pop       | O(1) | O(1)  |
| top       | O(1) | O(1)  |
| size      | O(1) | O(1)  |
| empty     | O(1) | O(1)  |

**Overall Space:** O(n) where n is the number of elements

## Usage Example

```cpp
MyStack st;
st.push(5);
st.push(10);
st.push(15);

cout << st.top();  // Output: 15
st.pop();
cout << st.top();  // Output: 10
cout << st.size(); // Output: 2
```

## Common Use Cases

- Function call stack (recursion)
- Undo/Redo operations
- Expression evaluation (postfix, infix)
- Backtracking algorithms
- Browser history (back button)
- Parentheses matching

## Key Points

- LIFO: Last In, First Out
- All operations are O(1)
- Always check `empty()` before `top()` or `pop()`
- Implemented using doubly linked list for efficiency
- Size is tracked separately for O(1) access
