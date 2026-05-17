# Linked List Practice Problems

Collection of LeetCode problems focused on linked list manipulation and algorithms.

## Problems Solved

### 1. Design Linked List (`01_Designed_Linked_List.cpp`)

Implement a custom linked list class with basic operations.

**Operations:** insert, delete, get value at index

**Time:** Varies by operation (O(1) for head operations, O(n) for index-based)  
**Space:** O(1) per operation

---

### 2. Middle of the Linked List (`02_Middle_Of_The_Linked_List.cpp`)

[LeetCode Problem](https://leetcode.com/problems/middle-of-the-linked-list/)

Find the middle node of a linked list. If there are two middle nodes, return the second one.

**Algorithm (Two Pointer / Slow-Fast):**
1. Use two pointers: slow and fast
2. Slow moves one step, fast moves two steps
3. When fast reaches the end, slow is at the middle

```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```

**Time:** O(n) - traverse list once  
**Space:** O(1) - only two pointers

**Key Technique:** Slow-fast pointer pattern (tortoise and hare)

---

### 3. Swapping Nodes in a Linked List (`03_Swapping_Nodes.cpp`)

Swap values of two nodes at specific positions.

**Time:** O(n)  
**Space:** O(1)

---

### 4. Merge Nodes Between Zeros (`04_Merge_Nodes.cpp`)

Merge nodes between zeros in a linked list.

**Time:** O(n)  
**Space:** O(1) or O(n) depending on approach

---

### 5. Delete Node in a Linked List (`05_Delete_Node.cpp`)

Delete a node when you only have access to that node (not the head).

**Trick:** Copy the next node's value to current node, then delete the next node.

```cpp
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}
```

**Time:** O(1)  
**Space:** O(1)

**Important:** This only works if the node is not the last node.

---

### 6. Reverse Linked List (`06_Reverse_List.cpp`)

[LeetCode Problem](https://leetcode.com/problems/reverse-linked-list/)

Reverse a singly linked list using recursion.

**Algorithm:**
1. Base case: if head is NULL or single node, return head
2. Recursively reverse the rest of the list
3. Make next node point back to current node
4. Set current node's next to NULL
5. Return new head

```cpp
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

**Time:** O(n)  
**Space:** O(n) - recursion stack

**Alternative:** Iterative approach with O(1) space

---

### 7. Linked List Cycle (`07_Has_Cycle.cpp`)

[LeetCode Problem](https://leetcode.com/problems/linked-list-cycle/)

Detect if a linked list has a cycle.

**Algorithm (Floyd's Cycle Detection):**
1. Use two pointers: slow (moves 1 step) and fast (moves 2 steps)
2. If they meet, there's a cycle
3. If fast reaches NULL, no cycle

```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}
```

**Time:** O(n)  
**Space:** O(1)

**Why it works:** If there's a cycle, fast pointer will eventually catch up to slow pointer inside the cycle.

**Edge Cases:**
- Empty list: no cycle
- Single node: no cycle
- Two nodes pointing to each other: cycle detected

---

### 10. Remove Duplicates from Sorted List (`10_Remove_Dupliates_From_Sorted_List.cpp`)

[LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

Remove duplicate values from a sorted linked list.

**Algorithm:**
1. Traverse the list
2. If current value equals next value, delete next node
3. Otherwise, move to next node
4. Repeat until end

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    if (temp == NULL || temp->next == NULL) return head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            ListNode* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}
```

**Time:** O(n)  
**Space:** O(1)

**Key Point:** Don't move pointer when deleting, because the new next node might also be a duplicate.

**Edge Cases:**
- Empty list: return NULL
- Single node: return as is
- All duplicates: keep only one

---

### 11. Remove Nth Node From End of List (`11_Remove_Nth_Node_From_Last.cpp`)

Remove the nth node from the end of the list.

**Algorithm (Two Pointer):**
1. Use two pointers with n gap between them
2. Move both until first reaches end
3. Second pointer is now at (n-1)th node from end
4. Delete the nth node

**Time:** O(n) - single pass  
**Space:** O(1)

---

## Common Patterns Used

### 1. Two Pointer Technique
- **Slow-Fast Pointers:** Find middle, detect cycle
- **Gap Pointers:** Find nth from end
- **Time:** O(n), **Space:** O(1)

### 2. Recursion
- **Use Case:** Reverse list, tree-like operations
- **Trade-off:** Clean code but O(n) space for call stack

### 3. In-place Modification
- **Technique:** Modify links without extra space
- **Examples:** Remove duplicates, delete nodes

### 4. Dummy Node
- **Use Case:** Simplify edge cases (head deletion)
- **Pattern:** Create dummy node pointing to head

---

## Key Takeaways

- Always check for NULL before accessing `next`
- Two-pointer technique is powerful for linked lists
- Slow-fast pointers can solve many problems in O(1) space
- When deleting, save the node first, update links, then delete
- Recursion is elegant but uses O(n) space
- For sorted lists, leverage the ordering property
