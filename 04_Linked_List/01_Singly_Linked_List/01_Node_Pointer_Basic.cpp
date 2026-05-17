/*
---

# 🔹 Assume this Node class

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
```

---

# 🔹 1. `Node a;`

```cpp
Node a;
```

✅ Object in **stack**
❌ Error if no default constructor

---

# 🔹 2. `Node a(10);`

```cpp
Node a(10);
```

✅ Object with value 10 (stack)

---

# 🔹 3. `Node* a;`

```cpp
Node* a;
```

⚠️ Pointer (uninitialized, garbage)

---

# 🔹 4. `Node* a = new Node(10);`

```cpp
Node* a = new Node(10);
```

✅ Heap object
✅ `a` stores address

---

# 🔹 5. `Node *a, b;`

```cpp
Node *a, b;
```

* `a` → pointer
* `b` → object

---

# 🔹 6. `Node a = b;`

```cpp
Node b(10);
Node a = b;
```

✅ Copy  (different objects)

---

# 🔹 7. `Node* a = &b;`

```cpp
Node b(10);
Node* a = &b;
```

✅ `a` points to `b`

---

# 🔹 8. `Node& a = b;`

```cpp
Node b(10);
Node& a = b;
```

✅ Same object (alias)

---

# 🔹 9. `Node* a = NULL;`

```cpp
Node* a = NULL;
```

✅ points to nothing

---

# 🔹 10. `Node* a = nullptr;`

```cpp
Node* a = nullptr;
```

✅ modern version

---

# 🔥 NEW CASE 1

## `Node* a = new Node(10); Node* b = NULL; a = b;`

```cpp
Node* a = new Node(10);
Node* b = NULL;

a = b;
```

### 🔍 Step-by-step:

1. `a` → points to heap node (10)
2. `b` → NULL
3. `a = b;` → now `a` becomes NULL

### ⚠️ Important:

* ❌ The node created by `new Node(10)` is now **lost (memory leak)**
* ❌ No pointer is pointing to it anymore

### 📌 Final state:

```cpp
a = NULL
b = NULL
```

---

# 🔥 NEW CASE 2

## `Node* a = new Node(10); Node* b = NULL; b = a;`

```cpp
Node* a = new Node(10);
Node* b = NULL;

b = a;
```

### 🔍 Step-by-step:

1. `a` → points to node (10)
2. `b` → NULL
3. `b = a;` → now `b` also points to same node

### 📌 Final state:

```cpp
a ─┐
   ├──> [10 | NULL]
b ─┘
```

### 💡 Meaning:

* Two pointers → **same node**
* No copy created

---

# 🔥 VERY IMPORTANT DIFFERENCE

| Case                 | Result                             |
| -------------------- | ---------------------------------- |
| `a = b;` (b is NULL) | ❌ lose original node (memory leak) |
| `b = a;`             | ✅ both point to same node          |

---

# 🔥 Bonus (VERY IMPORTANT for interviews)

```cpp
Node* a = new Node(10);
Node* b = a;
```

👉 Same as:

```cpp
b = a;
```

✔ both point same memory
✔ no new node created

---

# 🎯 FINAL GOLDEN RULES

* `a = b;` → pointer copy (address copy)
* `new` → creates memory in heap
* Losing pointer → 💥 memory leak
* Multiple pointers can point to same node

---

# 🧠 Simple analogy

Think:

* Node = house
* Pointer = address

👉 `b = a;`
➡️ both people now know same house

👉 `a = b;` (b is NULL)
➡️ you forgot the house location 😅


*/