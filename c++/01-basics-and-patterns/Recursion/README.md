]<div align="center">

# 🟣 Recursion Basics

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sheet](https://img.shields.io/badge/Sheet-Striver's%20A2Z-6A0DAD?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Recursion-B19CD9?style=for-the-badge)

</div>

Notes on recursion, how it works, why it needs a base case, and how to trace through it using a recursion tree. File: [`recursion.cpp`](./recursion.cpp)

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

## Example: Counter with a Global Variable

This was the first example in the original notes, using a global counter instead of passing values as parameters.

```cpp
int cnt = 0;
void print(){
    if(cnt==3) return;
    cout << cnt << endl;
    cnt++;
    print();
}

int main(){
    print();
    return 0;
}
```

Here `cnt` is a global variable, so every call to `print()` shares the exact same `cnt`, there is no separate copy for each call like there was with `i` in the earlier example. The base case is `if (cnt == 3) return`.

### Tracing it

```
print()  [cnt = 0]  -> prints 0, cnt becomes 1, calls print()
   print()  [cnt = 1]  -> prints 1, cnt becomes 2, calls print()
      print()  [cnt = 2]  -> prints 2, cnt becomes 3, calls print()
         print()  [cnt = 3]  -> base case hit, return
      <- returns
   <- returns
<- returns
```

Output is `0`, `1`, `2`, each on its own line. Just like the name-printing example, this is a straight chain, not a branching tree, since each call only makes one more call.

**Time complexity:** O(1) in terms of the constant it counts to here (it always stops at `cnt == 3`), but if that stopping value were `n` instead of a fixed `3`, it would be O(n), same as the earlier example.

**Space complexity:** O(number of calls), since each call sits on the stack until it returns.

A quick side note on something from the original code: the block below it (`#ifndef ONLINE_JUDGE ... freopen(...)`) is a competitive programming trick, not part of recursion itself. It redirects `cin` and `cout` to read from `input.txt` and write to `output.txt` on your own machine, but skips that redirection automatically when the code runs on an online judge (since online judges usually define `ONLINE_JUDGE` for you). Handy for testing locally without typing input by hand every time, but worth knowing it is unrelated to how the recursion actually works.

---

## A Branching Example (Recursion Tree)

Both examples above are straight lines because each call only makes one more call. A recursion tree really starts to look like a tree once a function makes more than one recursive call inside itself, like this:

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