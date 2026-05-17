# 🧠 Thinking Approach for Recursion Problems

---

## 😎 I am a lazy person

Recursion function is my **slave 🤖**

I will do only a small portion of the work, and give the rest to the slave.
The slave will learn and complete the work by itself by following me.

---

## 🧠 Two ways to understand Recursion

### 1️⃣ Forward Thinking
I do one operation and give it to recursion, and it completes the rest by following that pattern.

### 2️⃣ Backtracking Thinking
It gives me a value (assumed), then I perform my operation using that value. 
👉 **This is called backtracking.**

---

## 🔁 Program Flow Concept

*   **Forward:** The part *before* the recursive call.
*   **Backtracking:** The part *after* the recursive call.

---

## 🔄 4 Ways of Linear Traversal

*   **Forward** (1 → n)
*   **Forward** (n → 1)
*   **Backtrack** (n → 1)
*   **Backtrack** (1 → n)

---

## 🧩 4 Steps to Solve Recursion Problems

### 1️⃣ In which way Traversal
Decide how to traverse the problem. Should the work happen **Forward** (before the recursive call) or while **Backtracking** (after the recursive call)? 
*   **Forward:** Process the current step, then call the slave.
*   **Backtracking:** Call the slave first, then process its result.

### 2️⃣ Relationship (Main Idea)
What recursion (slave) will give me (assumed), and what I will give to recursion (slave).

### 3️⃣ Current Function Behavior
In the function where I am working:
*   What will this function return ?

### 4️⃣ Base Case
When recursion will stop (**Crucial step**).
