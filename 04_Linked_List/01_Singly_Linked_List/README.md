# Singly Linked List

A singly linked list is a linear data structure where each element (node) contains data and a pointer to the next node. The last node points to NULL.

## Structure

```
[data|next] -> [data|next] -> [data|next] -> NULL
```

Each node has:
- `val`: stores the data
- `next`: pointer to the next node

## Key Concepts

- **Head**: pointer to the first node
- **Tail**: pointer to the last node
- **Node**: basic unit containing data and next pointer
- **NULL**: marks the end of the list

## Operations Implemented

### 1. Node Creation (`01_Node_Pointer_Basic.cpp`, `02_Node_Class.cpp`)

Basic node structure and pointer concepts.

```cpp
class Node {
    public:
        int val;
        Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
```

**Key Points:**
- `Node* ptr = new Node(10)` creates a node in heap memory
- `ptr` stores the address of the node
- Always initialize `next` to NULL

**Time:** O(1)  
**Space:** O(1)

---

### 2. Insert at Tail (`03_Insert_At_Tail.cpp`)

Add a new node at the end of the list.

**Algorithm:**
1. Create a new node
2. If list is empty, set both head and tail to new node
3. Otherwise, link current tail's next to new node
4. Update tail to point to new node

```cpp
void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
```

**Time:** O(1) - direct access via tail pointer  
**Space:** O(1)

**Edge Cases:**
- Empty list: both head and tail become the new node
- Single node: tail pointer ensures O(1) insertion

---

### 3. Print List (`04_Print_List.cpp`)

Traverse and print all elements.

**Algorithm:**
1. Start from head
2. Print current node's value
3. Move to next node
4. Stop when reaching NULL

```cpp
void printList(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
```

**Time:** O(n) - visit each node once  
**Space:** O(1) - only uses a temporary pointer

---

### 4. Insert at Head (`05_Insert_At_Head.cpp`)

Add a new node at the beginning.

**Algorithm:**
1. Create a new node
2. If list is empty, set both head and tail to new node
3. Otherwise, link new node's next to current head
4. Update head to point to new node

```cpp
void insertAtHead(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
```

**Time:** O(1)  
**Space:** O(1)

**Important:** Must link new node to old head before updating head pointer, otherwise you lose the list.

---

### 5. Insert at Index (`06_Insert_At_Index.cpp`)

Insert a node at a specific position.

**Algorithm:**
1. If index is 0, use insertAtHead
2. Traverse to node at position (index - 1)
3. Create new node
4. Link new node's next to current node's next
5. Link current node's next to new node

```cpp
void insertAtIndex(Node* &head, Node* &tail, int val, int idx) {
    if (idx == 0) {
        insertAtHead(head, tail, val);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
```

**Time:** O(n) - may need to traverse to index  
**Space:** O(1)

**Edge Cases:**
- Index 0: handled by insertAtHead
- Invalid index: may cause segmentation fault (needs validation)

---

### 6. Delete at Head (`07_Delete_At_Head.cpp`)

Remove the first node.

**Algorithm:**
1. If list is empty, return
2. If only one node, set head and tail to NULL
3. Otherwise, save head in temp, move head to next node, delete temp

```cpp
void deleteAtHead(Node* &head, Node* &tail) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}
```

**Time:** O(1)  
**Space:** O(1)

**Edge Cases:**
- Empty list: do nothing
- Single node: update both head and tail to NULL
- Must use `delete` to free memory

---

### 7. Delete at Any Position (`08_Delete_At_Any.cpp`)

Remove a node at a specific index.

**Algorithm:**
1. Handle empty list and single node cases
2. Traverse to node at position (index - 1)
3. Save the node to delete
4. Link current node's next to the node after the one being deleted
5. Delete the saved node

```cpp
void deleteAtAny(Node* &head, Node* &tail, int idx) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
```

**Time:** O(n) - traverse to index  
**Space:** O(1)

**Edge Cases:**
- Deleting last node: tail pointer needs update (not handled in basic version)
- Invalid index: needs bounds checking

---

### 8. Reverse List (`09_Reverse.cpp`)

Reverse the entire linked list using recursion.

**Algorithm:**
1. Base case: if only one node, return it
2. Recursively reverse the rest of the list
3. Make the next node point back to current node
4. Set current node's next to NULL
5. Return the new head

```cpp
Node* reverseWithoutReference(Node* head, Node* tail) {
    if (head->next == NULL) return head;
    Node* newHead = reverseWithoutReference(head->next, tail);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
```

**Time:** O(n) - visit each node once  
**Space:** O(n) - recursion stack

**Key Insight:** The trick is `head->next->next = head` which makes the next node point back to current node, effectively reversing the link.

---

## Common Patterns

### Traversal Pattern
```cpp
Node* temp = head;
while (temp != NULL) {
    // process temp
    temp = temp->next;
}
```

### Insertion Pattern
1. Create new node
2. Link new node to existing nodes
3. Update pointers (head/tail if needed)

### Deletion Pattern
1. Find the node to delete
2. Update links to bypass it
3. Use `delete` to free memory

---

## Important Notes

- Always check if list is empty before operations
- Use `delete` to prevent memory leaks
- Pass head and tail by reference (`Node* &head`) to modify them
- `new` allocates memory in heap
- NULL/nullptr marks the end of the list
