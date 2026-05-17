# Binary Tree Implementation

A binary tree is a hierarchical data structure where each node has at most two children: left and right.

## Structure

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

Each node contains:
- `val`: the data
- `left`: pointer to left child
- `right`: pointer to right child

## Node Structure

```cpp
class Node {
    public:
        int val;
        Node* left;
        Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
```

## Key Concepts

- **Root:** The topmost node (node 1 in example)
- **Parent:** Node with children
- **Child:** Node connected below another node
- **Leaf:** Node with no children (nodes 4, 5, 6)
- **Subtree:** A node and all its descendants
- **Height:** Longest path from root to leaf
- **Level:** Distance from root (root is level 0)

## Tree Creation (`01_Create_Node.cpp`)

Manual tree construction by creating nodes and linking them.

```cpp
Node* root = new Node(1);
Node* two = new Node(2);
Node* three = new Node(3);

root->left = two;
root->right = three;

Node* four = new Node(4);
two->left = four;
```

**Time:** O(n) - create n nodes  
**Space:** O(n) - store n nodes

---

## Tree Traversal

Two main approaches: **DFS (Depth-First Search)** and **BFS (Breadth-First Search)**

### DFS Traversal (`02_DFS_Traversal.cpp`)

Visit nodes by going deep into the tree before backtracking.

**Basic DFS (Preorder):**
```cpp
void dfs(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    dfs(root->left);
    dfs(root->right);
}
```

**Time:** O(n) - visit each node once  
**Space:** O(h) - recursion stack, where h is height

**For the example tree:**
```
Output: 1 2 4 5 3 6
```

---

### DFS Orders (`03_Order.cpp`)

Three ways to traverse using DFS, differing in when you process the current node.

#### 1. Preorder (Root → Left → Right)

Process root first, then left subtree, then right subtree.

```cpp
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";  // Process root first
    preorder(root->left);
    preorder(root->right);
}
```

**Output:** `1 2 4 5 3 6`

**Use case:** Create a copy of the tree, prefix expression evaluation

---

#### 2. Inorder (Left → Root → Right)

Process left subtree first, then root, then right subtree.

```cpp
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";  // Process root in middle
    inorder(root->right);
}
```

**Output:** `4 2 5 1 6 3`

**Use case:** Get sorted order in BST, infix expression evaluation

---

#### 3. Postorder (Left → Right → Root)

Process left subtree first, then right subtree, then root.

```cpp
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";  // Process root last
}
```

**Output:** `4 5 2 6 3 1`

**Use case:** Delete tree, postfix expression evaluation, calculate tree height

---

### Visual Comparison

```
Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Preorder:  1 → 2 → 4 → 5 → 3 → 6  (Root first)
Inorder:   4 → 2 → 5 → 1 → 6 → 3  (Root middle)
Postorder: 4 → 5 → 2 → 6 → 3 → 1  (Root last)
```

---

### BFS Traversal (`04_BFS_Traversal.cpp`)

Visit nodes level by level, left to right. Uses a **queue**.

**Algorithm:**
1. Start with root in queue
2. While queue is not empty:
   - Dequeue front node
   - Print its value
   - Enqueue its left child (if exists)
   - Enqueue its right child (if exists)

```cpp
void bfs(Node* root) {
    if (root == NULL) return;
    queue<Node*> que;
    que.push(root);
    
    while (!que.empty()) {
        Node* cur = que.front();
        que.pop();
        cout << cur->val << " ";
        
        if (cur->left != NULL) que.push(cur->left);
        if (cur->right != NULL) que.push(cur->right);
    }
}
```

**Output:** `1 2 3 4 5 6` (level by level)

**Time:** O(n) - visit each node once  
**Space:** O(w) - queue size, where w is maximum width

**Use case:** Level-order traversal, shortest path in unweighted tree, find nodes at distance k

---

### BFS with Level Tracking (`05_BFS_Traversal_with_Level.cpp`)

Track which level each node belongs to.

**Algorithm:**
- Store pairs of (node, level) in queue
- Increment level when adding children

```cpp
void bfs(Node* root) {
    if (root == NULL) return;
    queue<pair<Node*, int>> que;
    que.push({root, 0});
    
    while (!que.empty()) {
        pair<Node*, int> p = que.front();
        Node* currentNode = p.first;
        int level = p.second;
        que.pop();
        
        cout << "level: " << level << " - value: " << currentNode->val << ", ";
        
        if (currentNode->left != NULL) {
            que.push({currentNode->left, level + 1});
        }
        if (currentNode->right != NULL) {
            que.push({currentNode->right, level + 1});
        }
    }
}
```

**Output:**
```
level: 0 - value: 1,
level: 1 - value: 2, level: 1 - value: 3,
level: 2 - value: 4, level: 2 - value: 5, level: 2 - value: 6,
```

**Use case:** Print level-wise, find depth, zigzag traversal

---

### Tree Input (`06_Tree_Input.cpp`)

Template for taking tree input (implementation varies by problem).

Common input formats:
- **Level-order with -1 for NULL:** `1 2 3 -1 -1 4 -1 -1 5`
- **Parent-child pairs:** `1 2 L, 1 3 R, 2 4 L`
- **Array representation:** `[1, 2, 3, 4, 5, null, 6]`

---

## DFS vs BFS

| Feature | DFS | BFS |
|---------|-----|-----|
| Data Structure | Stack (recursion) | Queue |
| Memory | O(h) height | O(w) width |
| Order | Deep first | Level by level |
| Use Case | Search, backtrack | Shortest path, level-wise |
| Implementation | Recursive (simple) | Iterative (queue) |

### When to Use Which?

**Use DFS when:**
- Tree is very wide
- Need to visit all nodes
- Searching for a path
- Backtracking problems

**Use BFS when:**
- Tree is very deep
- Need level-wise processing
- Finding shortest path
- Need nodes at specific distance

---

## Complexity Summary

| Operation | Time | Space |
|-----------|------|-------|
| Create node | O(1) | O(1) |
| DFS traversal | O(n) | O(h) |
| BFS traversal | O(n) | O(w) |
| Preorder | O(n) | O(h) |
| Inorder | O(n) | O(h) |
| Postorder | O(n) | O(h) |

Where:
- n = number of nodes
- h = height of tree
- w = maximum width of tree

---

## Common Patterns

### Recursive Pattern (DFS)
```cpp
void traverse(Node* root) {
    if (root == NULL) return;  // Base case
    // Process current node
    traverse(root->left);      // Recurse left
    traverse(root->right);     // Recurse right
}
```

### Iterative Pattern (BFS)
```cpp
void traverse(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        // Process current node
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
```

---

## Important Notes

- Always check if node is NULL before accessing
- DFS uses recursion (implicit stack)
- BFS uses explicit queue
- Preorder is same as basic DFS
- Inorder gives sorted order in BST
- Postorder is useful for deletion
- BFS is level-order traversal

---

## Memory Trick for Orders

**Preorder:** **Pre**-process root (before children)  
**Inorder:** Process root **in** the middle  
**Postorder:** **Post**-process root (after children)

Or remember: **Root's position**
- Preorder: Root at start
- Inorder: Root in middle
- Postorder: Root at end
