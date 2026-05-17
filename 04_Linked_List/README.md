# Linked List

A linked list is a linear data structure where elements are stored in nodes. Each node contains data and a reference (pointer) to the next node in the sequence.

## What is a Linked List?

Unlike arrays where elements are stored in contiguous memory locations, linked list elements are scattered in memory and connected through pointers.

```
Array:     [10][20][30][40]  (contiguous memory)

Linked List:  [10|•]-->[20|•]-->[30|•]-->[40|NULL]  (scattered memory)
```

## Types of Linked Lists

### 1. Singly Linked List
Each node points to the next node only.
```
[data|next] -> [data|next] -> [data|next] -> NULL
```

### 2. Doubly Linked List
Each node has pointers to both next and previous nodes.
```
NULL <- [prev|data|next] <-> [prev|data|next] <-> [prev|data|next] -> NULL
```

### 3. Circular Linked List
Last node points back to the first node instead of NULL.

## Key Concepts

- **Node:** Basic unit containing data and pointer(s)
- **Head:** Pointer to the first node
- **Tail:** Pointer to the last node
- **NULL/nullptr:** Marks the end of the list

## Advantages

- **Dynamic size:** Can grow or shrink at runtime
- **Efficient insertion/deletion:** O(1) at head/tail with proper pointers
- **No memory waste:** Allocate only what you need
- **Easy to implement:** Stacks, queues, and other structures

## Disadvantages

- **No random access:** Must traverse from head to reach an element
- **Extra memory:** Each node needs space for pointer(s)
- **Cache unfriendly:** Nodes scattered in memory
- **Traversal overhead:** O(n) to access elements

## Array vs Linked List

| Feature | Array | Linked List |
|---------|-------|-------------|
| Memory | Contiguous | Scattered |
| Size | Fixed | Dynamic |
| Access | O(1) | O(n) |
| Insert at end | O(1) | O(1) with tail |
| Insert at start | O(n) | O(1) |
| Delete at start | O(n) | O(1) |
| Memory overhead | None | Pointer per node |

## Directory Structure

### `01_Singly_Linked_List/`
Basic singly linked list operations:
- Node creation and pointer basics
- Insert (head, tail, index)
- Delete (head, any position)
- Print and reverse

### `02_Doubly_Linked_List/`
Doubly linked list implementation (empty - to be added)

### `03_Practice_Problems/`
LeetCode problems:
- Middle of linked list (slow-fast pointers)
- Reverse linked list
- Cycle detection (Floyd's algorithm)
- Remove duplicates
- And more...

## Common Patterns

### 1. Two Pointer Technique
Use two pointers moving at different speeds or with a gap.
- **Slow-Fast:** Find middle, detect cycle
- **Gap Pointers:** Find nth from end

### 2. Dummy Node
Create a dummy node before head to simplify edge cases.

### 3. Recursion
Natural fit for linked lists due to their recursive structure.

### 4. In-place Modification
Modify pointers without using extra space.

## When to Use Linked Lists

**Use linked lists when:**
- Frequent insertions/deletions at beginning
- Size is unknown or changes frequently
- Don't need random access
- Implementing stacks, queues, or hash tables

**Use arrays when:**
- Need random access
- Size is known and fixed
- Memory locality is important
- Frequent access by index

## Important Notes

- Always check for NULL before dereferencing pointers
- Use `delete` to free memory and prevent leaks
- Pass head/tail by reference to modify them
- `new` allocates memory in heap
- Keep track of both head and tail for O(1) operations at both ends

## Time Complexity Summary

| Operation | Singly LL | Doubly LL |
|-----------|-----------|-----------|
| Access | O(n) | O(n) |
| Search | O(n) | O(n) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(1)* | O(1) |
| Delete at head | O(1) | O(1) |
| Delete at tail | O(n) | O(1) |

*With tail pointer

## Next Steps

1. Start with `01_Singly_Linked_List/` to learn basics
2. Practice common operations
3. Move to `03_Practice_Problems/` for interview prep
4. Learn advanced techniques (two pointers, recursion)
