# Stack and Queue

Two fundamental linear data structures with opposite access patterns.

## Overview

Both stacks and queues are **abstract data types** that restrict how elements are added and removed, unlike arrays or linked lists where you can access any element.

## Stack (LIFO)

**Last In, First Out** - like a stack of plates.

```
    [30]  <- top (add/remove here)
    [20]
    [10]
```

**Operations:**
- `push(x)`: Add element to top
- `pop()`: Remove element from top
- `top()`: View top element
- `empty()`: Check if empty
- `size()`: Get number of elements

**All operations:** O(1)

## Queue (FIFO)

**First In, First Out** - like a line of people.

```
Front                    Back
[10] -> [20] -> [30] -> [40]
 ↑                       ↑
Remove here          Add here
```

**Operations:**
- `push(x)`: Add element to back
- `pop()`: Remove element from front
- `front()`: View front element
- `empty()`: Check if empty
- `size()`: Get number of elements

**All operations:** O(1)

## Key Differences

| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO | FIFO |
| Add | Top | Back |
| Remove | Top | Front |
| Access | Top only | Front only |
| Real-world | Stack of plates | Line at store |

## Implementation Choices

### Stack
- **Array-based:** Simple, fixed size
- **Linked list-based:** Dynamic, uses doubly linked list for O(1) pop
- **STL:** `std::stack`

### Queue
- **Array-based:** Circular array to avoid shifting
- **Linked list-based:** Singly linked list is sufficient
- **STL:** `std::queue`

## Why Linked List Implementation?

### Stack (Doubly Linked List)
```cpp
class MyStack {
    LinkedList list;  // doubly linked
    // push: insertAtTail - O(1)
    // pop: deleteAtTail - O(1) with prev pointer
    // top: access tail - O(1)
};
```

### Queue (Singly Linked List)
```cpp
class MyQueue {
    LinkedList list;  // singly linked
    // push: insertAtTail - O(1)
    // pop: deleteAtHead - O(1)
    // front: access head - O(1)
};
```

## Common Use Cases

### Stack Applications
- **Function calls:** Call stack in recursion
- **Undo/Redo:** Text editors
- **Expression evaluation:** Postfix, infix conversion
- **Backtracking:** Maze solving, DFS
- **Browser history:** Back button
- **Parentheses matching:** Compiler syntax checking

### Queue Applications
- **Task scheduling:** CPU, printer queues
- **BFS:** Breadth-first search in graphs
- **Level-order traversal:** Binary trees
- **Request handling:** Web servers
- **Buffer:** Data streams, IO operations
- **Message queues:** Distributed systems

## Complexity Comparison

| Operation | Stack | Queue | Array | Linked List |
|-----------|-------|-------|-------|-------------|
| Add | O(1) | O(1) | O(1)* | O(1) |
| Remove | O(1) | O(1) | O(n) | O(1)** |
| Access | O(1) top | O(1) front | O(1) any | O(n) |
| Search | O(n) | O(n) | O(n) | O(n) |

*Amortized for dynamic arrays  
**At head/tail with proper pointers

## Directory Structure

### `01_Stack/`
Stack implementation using doubly linked list:
- Push, pop, top operations
- Size tracking
- Empty check

### `02_Queue/`
Queue implementation using singly linked list:
- Push (enqueue), pop (dequeue)
- Front access
- Size tracking

## When to Use Which?

### Use Stack When:
- Need to reverse order
- Implementing recursion iteratively
- Need to backtrack
- Processing nested structures
- LIFO behavior is natural

### Use Queue When:
- Need to maintain order
- Processing in arrival order
- Level-by-level processing
- Buffering data
- FIFO behavior is natural

## Example Scenarios

### Stack Example: Undo Feature
```
Action: Type "A"  -> Stack: [A]
Action: Type "B"  -> Stack: [A, B]
Action: Type "C"  -> Stack: [A, B, C]
Undo:             -> Stack: [A, B]  (removed C)
Undo:             -> Stack: [A]     (removed B)
```

### Queue Example: Print Queue
```
Job1 arrives -> Queue: [Job1]
Job2 arrives -> Queue: [Job1, Job2]
Job3 arrives -> Queue: [Job1, Job2, Job3]
Process      -> Queue: [Job2, Job3]  (Job1 done)
Process      -> Queue: [Job3]        (Job2 done)
```

## Stack vs Queue in Algorithms

### Stack (DFS - Depth First)
Goes deep into one path before backtracking.
```
    1
   / \
  2   3
 / \
4   5

Visit order: 1 -> 2 -> 4 -> 5 -> 3
```

### Queue (BFS - Breadth First)
Explores level by level.
```
    1
   / \
  2   3
 / \
4   5

Visit order: 1 -> 2 -> 3 -> 4 -> 5
```

## Important Notes

- Both restrict access to one end (stack) or two ends (queue)
- All basic operations are O(1)
- Always check `empty()` before accessing elements
- Linked list implementation provides dynamic sizing
- STL provides ready-to-use implementations

## STL Usage

### Stack
```cpp
#include <stack>
stack<int> st;
st.push(10);
st.top();    // 10
st.pop();
st.empty();
```

### Queue
```cpp
#include <queue>
queue<int> q;
q.push(10);
q.front();   // 10
q.pop();
q.empty();
```

## Next Steps

1. Understand the LIFO and FIFO principles
2. Implement both using linked lists
3. Practice with STL versions
4. Solve problems using stacks and queues
5. Learn when to use which data structure
