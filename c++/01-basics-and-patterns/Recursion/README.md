<div align="center">

# Recursion Basics

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
```

Here `cnt` is a global variable, so every call to `print()` shares the exact same `cnt`, there is no separate copy for each call like there was with `i` in the earlier example. The base case is `if (cnt == 3) return`.

Output is `0`, `1`, `2`, each on its own line, same straight-chain shape as `f()`.

A quick side note on something from the original code: the block that used to sit below it (`#ifndef ONLINE_JUDGE ... freopen(...)`) is a competitive programming trick, not part of recursion itself. It redirects `cin` and `cout` to read from `input.txt` and write to `output.txt` on your own machine, but skips that redirection automatically when the code runs on an online judge (since online judges usually define `ONLINE_JUDGE` for you). Handy for testing locally without typing input by hand every time, but unrelated to how the recursion actually works.

---

## Printing Numbers, Forwards and Backwards

Two small variations on the same idea as `f()`, just printing numbers instead of a name.

### Print 1 to n

```cpp
void count(int i, int n){
    if(i>n) return ;
    cout << i << endl;
    count(i+1,n); 
}
```

`i` starts at 1 and climbs up to `n`. Print first, then recurse, same shape as `f()`. Called as `count(1, n)`.

### Print n down to 1

```cpp
void count2(int i , int n){
    if(n<i) return ;
    cout << n << endl;
    count2(i,n-1);
}
```

This time `i` stays fixed as the stopping point, and `n` is the one that shrinks each call. Called as `count2(1, n)`, it prints `n, n-1, n-2, ... 1`.

**Time complexity:** O(n) for both. **Space complexity:** O(n) for both, same reasoning as `f()`.

---

## Backtracking Style Recursion

So far, every example printed something and then made the recursive call. What happens if you flip that order, and make the recursive call first, then print afterward?

The print statement ends up running on the way back up the call stack, once calls start returning, not on the way down while calls are still being made. This is usually called **backtracking style** recursion, and it is a genuinely useful trick: it lets you print things in an order that the loop variable itself never actually moves in.

### Print 1 to n without ever doing i + 1

```cpp
void count3(int i , int n){
    if(i<1) return ;
    count3(i-1,n);
    cout << i << endl;
}
```

Called as `count3(n, n)`. Notice `i` only ever decreases here (`i - 1`), yet the output comes out as `1, 2, 3, ... n`, in increasing order. That is only possible because the `cout` happens after the recursive call.

### Tracing count3(3, 3)

```
count3(3, 3)  -> calls count3(2, 3) first, before printing
   count3(2, 3)  -> calls count3(1, 3) first, before printing
      count3(1, 3)  -> calls count3(0, 3) first, before printing
         count3(0, 3)  -> i < 1, base case hit, return
      <- now count3(1,3) prints 1
   <- now count3(2,3) prints 2
<- now count3(3,3) prints 3
```

The deepest call hits the base case first, and printing only starts once the unwinding begins, smallest value first.

### Print n down to 1 without ever doing i - 1

```cpp
void count4(int i , int n){
    if(i>n) return;
    count4(i+1,n);
    cout<< i << endl;
}
```

Called as `count4(1, n)`. Same backtracking idea, mirrored: `i` only ever increases, but the output comes out as `n, n-1, ... 1`, because again, printing happens on the way back up.

**Time complexity:** O(n) for both. **Space complexity:** O(n) for both.

---

## Two Ways to Build Up an Answer

There are two common styles for carrying a running answer through a recursive function, and both show up in this file for two different problems, sum of n numbers, and factorial.

### Style 1: Pass the answer forward as a parameter

```cpp
void sum1(int i , int sum){
    if(i<1){
        cout << sum << endl;
        return;
    }
    sum1(i-1,sum+i);
}
```

Called as `sum1(n, 0)`. The running total (`sum`) is built up on the way down, added to at every call, and by the time the base case is hit, the answer is already sitting there ready to print. Nothing needs to happen on the way back up.

### Style 2: Let the answer build on the way back up

```cpp
int sum2(int n){
    if(n==0){
        return 0 ;
    }
    return n + sum2(n-1);
}
```

Here, each call waits for the call below it to return a value, then adds its own contribution (`n +`) before returning that upward. The base case just returns `0`, and the actual addition happens while unwinding, one level at a time.

The exact same two styles are used for factorial:

```cpp
// style 2: builds the answer on the way back up
int fact(int n ){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

// style 1: carries the answer forward, with a default parameter
void fact2(int i , int n = 1){
    if(i == 1){
        cout<< n << endl; 
        return ;
    }
    fact2(i-1 ,n*i );
}
```

`fact2` also shows something handy, a default parameter (`int n = 1`). It lets you call `fact2(5)` without passing the accumulator explicitly the first time, since `n` already starts at 1 on its own.

One thing worth watching for in both `fact` and `fact2`, the base case only checks for exactly `n == 1` (or `i == 1`). If either function is ever called with `0`, it will keep decreasing past `1` into negative numbers and never hit that exact check, which means infinite recursion. Worth keeping in mind if these get reused or extended later.

**Time complexity:** O(n) for all four versions. **Space complexity:** O(n) for all four, one stack frame per call until the base case.

---

## Reversing an Array Using Recursion

```cpp
void swapping(int i , int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    swapping(i+1,arr,n);
}
```

This is the classic two pointer idea (swap the outermost pair, move inward) done through recursion instead of a loop. `i` starts at the front, `n - i - 1` is always the mirrored position from the back. Once `i` reaches the halfway point (`n / 2`), everything has already been swapped, so that is the base case.

Called as `swapping(0, arr, n)`.

**Time complexity:** O(n), roughly `n / 2` swaps, each O(1).

**Space complexity:** O(n) for the recursion stack, even though the actual swapping itself only needs O(1) extra space. This is one of those cases where a plain loop would actually be more space efficient than the recursive version, since a loop would not need any extra call stack frames at all.

---

## Checking a Palindrome Using Recursion

```cpp
bool palindorme(int i , string &s){
    if(i>=s.size()/2) return true ;
    if(s[i] != s[s.size()-i-1]) return false;

    return palindorme(i+1,s);
}
```

Same mirrored-pointer idea as the array reversal above, but comparing instead of swapping. It checks the character at `i` against its mirror position from the end, if they ever do not match, it returns `false` immediately without checking anything further. If it reaches the halfway point without ever mismatching, everything checked out fine, so it returns `true`.

The string is passed by reference (`string &s`), which avoids making a full copy of the string on every single recursive call, only a small detail but a useful habit for anything bigger than a toy example.

Called as `palindorme(0, s)`.

**Time complexity:** O(n), where n is the length of the string, since in the worst case it checks about half the characters.

**Space complexity:** O(n) for the recursion stack.

---

## A Branching Example: Fibonacci

Every example so far has been a straight chain, one call leading to exactly one more call. A recursion tree really starts to look like an actual tree once a function makes more than one recursive call inside itself, and the Fibonacci function is the classic example of that.

```cpp
int fib(int n){
    if(n<=1){
        return n;
    }
    int last = fib(n-1);
    int slast = fib(n-2);

    return last + slast ;
}
```

The base case is `n <= 1` (fib(0) is 0, fib(1) is 1). Every other call branches into two more calls, `fib(n-1)` and `fib(n-2)`.

### The recursion tree for fib(4)

```
fib(4)
├── fib(3)
│    ├── fib(2)
│    │    ├── fib(1) -> 1
│    │    └── fib(0) -> 0
│    └── fib(1) -> 1
└── fib(2)
     ├── fib(1) -> 1
     └── fib(0) -> 0
```

Working from the leaves back up: the left `fib(2)` gives `1 + 0 = 1`, so `fib(3) = fib(2) + fib(1) = 1 + 1 = 2`. The right `fib(2)` gives `1 + 0 = 1` again. So `fib(4) = fib(3) + fib(2) = 2 + 1 = 3`.

Notice `fib(2)` gets computed twice here, completely from scratch both times, and `fib(1)` gets computed three times. For small numbers like this it does not matter, but this repeated work is exactly why naive recursive Fibonacci gets painfully slow for bigger `n`, and it is the whole motivation behind memoization and dynamic programming later on, storing an answer the first time it is computed instead of recalculating it from scratch every time it is needed again.

**Time complexity:** O(2^n), since the number of calls roughly doubles with every increase in `n`, and there is a huge amount of repeated work.

**Space complexity:** O(n), which might look surprising given how wide the tree gets. The call stack only ever holds one path down through the tree at a time, not the whole tree at once, so the recursion depth (and therefore the space used) is only as deep as `n`, even though the total number of calls made along the way is exponential.

---

## Notes to self

- Always write the base case first, before the recursive call. If the recursive call runs before the base case is checked, it is easy to accidentally skip the stopping condition and loop forever.
- Every recursive call adds a new frame to the call stack. That is the O(n) or worse space cost that a loop version of the same logic would not have.
- Whether a function prints or returns on the way down or on the way back up entirely depends on whether that statement comes before or after the recursive call. Before the call means it runs immediately, going down. After the call means it waits until that call (and everything below it) has fully returned. That single ordering choice is the whole idea behind `count3` and `count4`.
- If a function makes only one recursive call inside itself, the recursion tree is just a straight chain. If it makes two or more, like `fib`, it actually branches out into a wide tree, and that is usually a sign the same subproblem is getting recomputed multiple times, worth checking whether memoization would help.
- Recursion is not always the most efficient option, but it usually makes the logic much easier to read and reason about, especially for problems that are naturally recursive like trees, backtracking, and divide and conquer.

---

<div align="center">

*Learning in public, one call stack at a time.*

</div>