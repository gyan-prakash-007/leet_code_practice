# 🟣 Pattern Printing — C++

Nested-loop patterns — the first real DSA muscle you build before touching actual problems. Each function below takes `n` and prints one shape. File: [`pattern_printing.cpp`](./pattern_printing.cpp)

The whole point of grinding these is loop-bound intuition — once you can predict a shape's output just by reading the `for` conditions, sliding window and two-pointer bounds stop feeling scary.

---

### Pattern 1 — Solid Square
```
****
****
****
****
```

### Pattern 2 — Right Triangle (Stars)
```
*
**
***
****
```

### Pattern 3 — Right Triangle (Increasing Numbers)
```
1
12
123
1234
```

### Pattern 4 — Right Triangle (Repeated Row Number)
```
1
22
333
4444
```

### Pattern 5 — Inverted Right Triangle (Stars)
```
****
***
**
*
```

### Pattern 6 — Inverted Triangle (Numbers)
```
1 2 3 4
1 2 3
1 2
1
```

### Pattern 7 — Pyramid
```
   *
  ***
 *****
*******
```

### Pattern 8 — Inverted Pyramid
```
*******
 *****
  ***
   *
```

### Pattern 9 — Diamond
```
   *
  ***
 *****
*******
*******
 *****
  ***
   *
```

### Pattern 10 — Rising & Falling Triangle
```
*
**
***
****
***
**
*
```

### Pattern 11 — Binary Alternating Triangle
```
1
01
101
0101
```

---

## 💡 Notes to self

- Patterns 7–9 are the ones that actually matter — spacing math (`n - i - 1`) shows up again later in tree-printing and matrix problems.
- Pattern 10 looks like a diamond but isn't — no spacing means it's left-aligned. Don't confuse the loop logic with Pattern 9.
- Pattern 11 is the first one where state (`start`) carries across the inner loop instead of resetting — good one to revisit before bit-manipulation problems.