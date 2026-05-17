# Queue Implementation

A queue is a linear data structure that follows the **FIFO (First In First Out)** principle. The first element added is the first one to be removed.

## Concept

Think of a queue like a line of people:
- People join at the back (enqueue/push)
- People leave from the front (dequeue/pop)
- First person in line is served first

```
Front                    Back
[10] -> [20] -> [30] -> [40]
 ↑                       ↑
 |                       |
Remove here          Add here
```

## Implementation

This implementation uses a **singly linked list** as the underlying data structure.

### Node Structure

```cpp
class Node {
    public:
        int val;
        Node* next;
};
```

Singly linked list is sufficient since we only need to:
- Add at tail (back of queue)
- Remove from head (front of queue)

### Queue Class

```cpp
class MyQueue {
    private:
        LinkedList list;
        int sz;
    public:
        void push(int val);
        void pop();
        int front();
        int size();
        bool empty();
};
```

## Operations

### 1. Push (Enqueue)

Add an element to the back of the queue.

**Implementation:**
- Insert at tail of the linked list
- Increment size counter

```cpp
void push(int val) {
    list.insertAtTail(val);
    sz++;
}
```

**Time:** O(1) - direct access via tail pointer  
**Space:** O(1)

---

### 2. Pop (Dequeue)

Remove the front element from the queue.

**Implementation:**
- Delete at head of the linked list
- Decrement size counter

```cpp
void pop() {
    list.deleteAtHead();
    if (sz) sz--;
}
```

**Time:** O(1) - direct access via head pointer  
**Space:** O(1)

**Edge Case:** Popping from empty queue is handled by checking if head is NULL.

---

### 3. Front

Get the value of the front element without removing it.

```cpp
int front() {
    return list.head->val;
}
```

**Time:** O(1)  
**Space:** O(1)

**Important:** Should check if queue is empty before calling front.

---

### 4. Size

Return the number of elements in the queue.

```cpp
int size() {
    return sz;
}
```

**Time:** O(1)  
**Space:** O(1)

---

### 5. Empty

Check if the queue is empty.

```cpp
bool empty() {
    return list.head == NULL;
}
```

**Time:** O(1)  
**Space:** O(1)

---

## Why Singly Linked List?

A singly linked list is perfect for queue implementation:
- **O(1) push:** Insert at tail (have tail pointer)
- **O(1) pop:** Delete at head (have head pointer)
- **O(1) front:** Direct access via head pointer
- **No need for prev pointer:** We never delete from tail

This is more memory-efficient than using a doubly linked list.

## Complexity Summary

| Operation | Time | Space |
|-----------|------|-------|
| push      | O(1) | O(1)  |
| pop       | O(1) | O(1)  |
| front     | O(1) | O(1)  |
| size      | O(1) | O(1)  |
| empty     | O(1) | O(1)  |

**Overall Space:** O(n) where n is the number of elements

## Usage Example

```cpp
MyQueue q;
q.push(10);
q.push(20);
q.push(30);

cout << q.front();  // Output: 10
q.pop();
cout << q.front();  // Output: 20
cout << q.size();   // Output: 2
```

## FIFO Behavior

```
Initial: []

push(10): [10]
push(20): [10, 20]
push(30): [10, 20, 30]

front(): 10
pop():   [20, 30]

front(): 20
pop():   [30]

front(): 30
```

## Common Use Cases

- Task scheduling (CPU, printer queues)
- Breadth-First Search (BFS) in graphs
- Level-order traversal in trees
- Request handling (web servers)
- Buffer for data streams
- Message queues in systems

## Stack vs Queue

| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO | FIFO |
| Add | Top | Back |
| Remove | Top | Front |
| Access | Top only | Front only |
| Use Case | Undo/Redo | Task scheduling |

## Key Points

- FIFO: First In, First Out
- All operations are O(1)
- Always check `empty()` before `front()` or `pop()`
- Implemented using singly linked list (efficient)
- Size is tracked separately for O(1) access
- Elements are added at back and removed from front
