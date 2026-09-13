<div align="center">

# 🟣 Recursion Basics

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sheet](https://img.shields.io/badge/Sheet-Striver's%20A2Z-6A0DAD?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Recursion-B19CD9?style=for-the-badge)

</div>

Notes on recursion, how it works, why it needs a base case, and how to trace through it using a recursion tree. File: [`recursion_basics.cpp`](./recursion_basics.cpp)

---

## What is recursion

Recursion is just a function calling itself. It keeps calling itself again and again until some condition tells it to stop.

That stopping condition is called the **base case**. Without one, the function keeps calling itself forever, and the program crashes with a stack overflow or segmentation fault, since every function call takes up memory on the call stack, and that memory runs out eventually.

So every recursive function needs two things:
1. A base case, the condition that stops the recursion
2. A recursive call, where the function calls itself again, usually moving a little closer to the base case each time

---

## Example: Print a Name n Times

```cpp
void f(int i, int n){
    if(i>n) return;
    cout<<"Gyan"<<endl;
    f(i+1,n);
}

int main(){
    int n;
    cin >> n;

    f(1, n);

    return 0;
}
```

Here `i` keeps track of which call we are on, and `n` is the total number of times we want to print. The base case is `if (i > n) return`, once `i` goes past `n`, the recursion stops.

### Tracing it with n = 3

Call it as `f(1, 3)`. Here is what happens step by step:

```
f(1, 3)  -> prints "Gyan", calls f(2, 3)
   f(2, 3)  -> prints "Gyan", calls f(3, 3)
      f(3, 3)  -> prints "Gyan", calls f(4, 3)
         f(4, 3)  -> i (4) > n (3), base case hit, return
      <- returns
   <- returns
<- returns
```

Since each call only makes one more call (not two or three), this is a straight chain rather than a branching tree, more like a stack of calls piling up and then unwinding back down. Output ends up being "Gyan" printed 3 times.

**Time complexity:** O(n), one function call per value of `i` from 1 to n.

**Space complexity:** O(n), because each active call sits on the call stack until it returns, and there are n calls stacked up at the deepest point.

---

## A Branching Example (Recursion Tree)

The example above is a straight line because each call only makes one more call. A recursion tree really starts to look like a tree once a function makes more than one recursive call inside itself, like this:

```cpp
void solve(int n){
    if(n == 0) return; // base case
    solve(n - 1);
    solve(n - 1);
}
```

Calling `solve(2)` branches out like this:

```
solve(2)
├── solve(1)
│      ├── solve(0)   -> base case, return
│      └── solve(0)   -> base case, return
└── solve(1)
       ├── solve(0)   -> base case, return
       └── solve(0)   -> base case, return
```

Each call spawns two more calls, until it hits the base case (`n == 0`) and stops branching. This is why it is called a recursion "tree", every call is a node, and every recursive call inside it is a branch going one level deeper.

---

## Notes to self

- Always write the base case first, before the recursive call. If the recursive call runs before the base case is checked, it is easy to accidentally skip the stopping condition and loop forever.
- Every recursive call adds a new frame to the call stack. That is the O(n) or worse space cost that a loop version of the same logic would not have.
- If a function makes only one recursive call inside itself, the recursion tree is just a straight chain (like the name-printing example). If it makes two or more, it actually branches out into a tree shape.
- Recursion is not always the most efficient option, but it usually makes the logic much easier to read and reason about, especially for problems that are naturally recursive like trees, backtracking, and divide and conquer.

---

<div align="center">

*🟣 Learning in public, one call stack at a time.*

</div>