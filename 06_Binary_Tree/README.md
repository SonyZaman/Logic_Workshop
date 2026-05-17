# Binary Tree

A binary tree is a hierarchical data structure where each node has at most two children, referred to as the left child and the right child.

## What is a Binary Tree?

Unlike linear data structures (arrays, linked lists, stacks, queues), trees are hierarchical. They represent relationships with a parent-child structure.

```
        1          <- Root
       / \
      2   3        <- Level 1
     / \   \
    4   5   6      <- Level 2 (Leaves)
```

## Basic Terminology

- **Node:** Basic unit containing data and pointers to children
- **Root:** Topmost node (no parent)
- **Parent:** Node with children
- **Child:** Node connected below another node
- **Siblings:** Nodes with the same parent
- **Leaf:** Node with no children
- **Internal Node:** Node with at least one child
- **Edge:** Connection between two nodes
- **Path:** Sequence of nodes connected by edges
- **Height:** Longest path from root to any leaf
- **Depth:** Distance from root to a node
- **Level:** All nodes at the same depth

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

## Types of Binary Trees

### 1. Full Binary Tree
Every node has either 0 or 2 children (no node has only 1 child).

```
        1
       / \
      2   3
     / \
    4   5
```

### 2. Complete Binary Tree
All levels are filled except possibly the last, which is filled from left to right.

```
        1
       / \
      2   3
     / \  /
    4  5 6
```

**Use case:** Heap data structure

### 3. Perfect Binary Tree
All internal nodes have 2 children, and all leaves are at the same level.

```
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

**Properties:**
- Total nodes = 2^(h+1) - 1
- Leaf nodes = 2^h

### 4. Balanced Binary Tree
Height difference between left and right subtrees is at most 1 for every node.

**Use case:** AVL trees, Red-Black trees

### 5. Degenerate (Skewed) Tree
Every parent has only one child. Essentially a linked list.

```
    1
     \
      2
       \
        3
         \
          4
```

**Time complexity:** O(n) for operations (worst case)

## Tree Traversal Methods

### Depth-First Search (DFS)

Goes deep into the tree before backtracking.

**Three orders:**

1. **Preorder (Root → Left → Right)**
   - Visit root first
   - Then left subtree
   - Then right subtree
   - **Use:** Copy tree, prefix expressions

2. **Inorder (Left → Root → Right)**
   - Visit left subtree first
   - Then root
   - Then right subtree
   - **Use:** Get sorted order in BST

3. **Postorder (Left → Right → Root)**
   - Visit left subtree first
   - Then right subtree
   - Then root
   - **Use:** Delete tree, postfix expressions

### Breadth-First Search (BFS)

Also called **Level-Order Traversal**. Visits nodes level by level.

**Use:** Shortest path, level-wise operations

## DFS vs BFS

| Aspect | DFS | BFS |
|--------|-----|-----|
| Data Structure | Stack (recursion) | Queue |
| Memory | O(h) | O(w) |
| Order | Depth-first | Level-first |
| Implementation | Recursive | Iterative |
| Use Case | Path finding, backtracking | Shortest path, level-wise |

Where h = height, w = maximum width

## Properties of Binary Trees

### For a tree with n nodes:

- **Minimum height:** log₂(n+1) - 1 (complete tree)
- **Maximum height:** n - 1 (skewed tree)
- **Maximum nodes at level L:** 2^L
- **Maximum nodes with height h:** 2^(h+1) - 1

### Relationships:

- **Edges = Nodes - 1** (for any tree)
- **Leaf nodes in full binary tree:** (n + 1) / 2

## Common Operations

| Operation | Average | Worst |
|-----------|---------|-------|
| Search | O(n) | O(n) |
| Insert | O(n) | O(n) |
| Delete | O(n) | O(n) |
| Traversal | O(n) | O(n) |

*For Binary Search Tree (BST), search/insert/delete can be O(log n) on average*

## Applications

### General Binary Trees:
- Expression trees (compilers)
- Huffman coding (compression)
- Decision trees (AI/ML)
- File system hierarchy

### Binary Search Trees:
- Databases (indexing)
- Priority queues
- Symbol tables
- Autocomplete

### Balanced Trees (AVL, Red-Black):
- Standard library implementations (map, set)
- Database indexing
- File systems

## Advantages

- **Hierarchical structure:** Natural for representing hierarchical data
- **Fast search:** O(log n) in balanced BST
- **Dynamic size:** Can grow/shrink as needed
- **Efficient insertion/deletion:** O(log n) in balanced trees

## Disadvantages

- **No random access:** Must traverse from root
- **Extra memory:** Pointers for each node
- **Can become unbalanced:** Degrades to O(n) operations
- **Complex implementation:** Compared to arrays

## Binary Tree vs Other Structures

| Feature | Array | Linked List | Binary Tree |
|---------|-------|-------------|-------------|
| Access | O(1) | O(n) | O(n) |
| Search | O(n) | O(n) | O(n) or O(log n)* |
| Insert | O(n) | O(1) | O(n) or O(log n)* |
| Delete | O(n) | O(1) | O(n) or O(log n)* |
| Memory | Contiguous | Scattered | Scattered |
| Structure | Linear | Linear | Hierarchical |

*O(log n) for balanced BST

## Directory Structure

### `01_Implementation/`
Basic binary tree operations:
- Node creation
- DFS traversal (preorder, inorder, postorder)
- BFS traversal (level-order)
- Level tracking
- Tree input methods

### `02/`
(Empty - to be added)

## When to Use Binary Trees

**Use binary trees when:**
- Data has hierarchical relationships
- Need efficient search in sorted data (BST)
- Implementing priority queues (heap)
- Expression evaluation
- Decision-making processes

**Don't use when:**
- Need random access by index
- Data is purely linear
- Memory is very limited
- Simple sequential processing

## Common Interview Problems

1. **Traversals:** Implement all DFS and BFS traversals
2. **Height/Depth:** Calculate tree height
3. **Diameter:** Longest path between any two nodes
4. **Balanced:** Check if tree is balanced
5. **Mirror:** Create mirror image of tree
6. **Level-wise:** Print nodes level by level
7. **Path Sum:** Find if path exists with given sum
8. **LCA:** Lowest Common Ancestor
9. **Views:** Left view, right view, top view, bottom view
10. **Serialize/Deserialize:** Convert tree to string and back

## Important Concepts to Master

1. **Recursion:** Most tree problems use recursion
2. **Base cases:** Always handle NULL nodes
3. **Return values:** What to return from recursive calls
4. **Level-order:** Master BFS with queue
5. **Tree construction:** Build tree from traversals
6. **BST properties:** Understand BST invariants

## Next Steps

1. Start with `01_Implementation/` to learn basics
2. Master all traversal methods
3. Understand recursion deeply
4. Practice tree construction
5. Move to Binary Search Trees
6. Learn balanced trees (AVL, Red-Black)
7. Practice interview problems

## Key Takeaways

- Binary tree: each node has at most 2 children
- Three DFS orders: preorder, inorder, postorder
- BFS: level-order traversal using queue
- Height matters: balanced trees are efficient
- Recursion is natural for tree problems
- Always check for NULL before accessing nodes
- BST adds ordering property for faster operations
