# 🟣 Pattern Printing — C++

Nested-loop patterns — the first real DSA muscle you build before touching actual problems. Each function below takes `n` and prints one shape. File: [`pattern.cpp`](./pattern.cpp)

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

### Pattern 12 — Number Butterfly (Hollow)
```
1      1
12    21
123  321
12344321
```

### Pattern 13 — Continuous Number Triangle
```
1
2 3
4 5 6
7 8 9 10
```

### Pattern 14 — Alphabet Right Triangle
```
A
AB
ABC
ABCD
```

### Pattern 15 — Inverted Alphabet Triangle
```
ABCD
ABC
AB
A
```

### Pattern 16 — Repeated Letter Triangle
```
A
B B
C C C
D D D D
```

### Pattern 17 — Alphabet Pyramid
```
   A
  ABA
 ABCBA
ABCDCBA
```

### Pattern 18 — Reverse Alphabet Run (to E)
```
E
D E
C D E
B C D E
```

### Pattern 19 — Full Star Butterfly
```
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
```

### Pattern 20 — Star Sandglass (Hollow Hourglass)
*(n = 3 shown, since it needs an odd middle row to read clearly)*
```
*     *
**   **
*** ***
**   **
*     *
```

### Pattern 21 — Hollow Square
```
****
*  *
*  *
****
```

### Pattern 22 — Concentric Number Square
*(n = 3 shown)*
```
33333
32223
32123
32223
33333
```

---

## 💡 Notes to self

- Patterns 7–9 (and 17, 19, 20) are the ones that actually matter — spacing math (`n - i - 1`) shows up again later in tree-printing and matrix problems.
- Pattern 10 looks like a diamond but isn't — no spacing means it's left-aligned. Don't confuse the loop logic with Pattern 9.
- Pattern 11 is the first one where state (`start`) carries across the inner loop instead of resetting — good one to revisit before bit-manipulation problems.
- Pattern 13 is the first "continuous counter" pattern — the counter variable lives outside both loops instead of resetting every row. This idea shows up again in matrix traversal problems.
- Pattern 17 combines the pyramid spacing logic (pattern 7) with a rise-and-fall counter (like pattern 20) — good one to revisit if pattern 7 or pattern 20 individually feel shaky.
- Pattern 22 is the first one that isn't really "row by row" thinking — it's a distance-to-nearest-edge formula applied to every cell. Worth revisiting before matrix/grid BFS problems, since "distance from boundary" is a recurring idea there.