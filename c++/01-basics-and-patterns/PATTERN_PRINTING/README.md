# 🟣 Pattern Printing — C++

Nested-loop patterns — the first real DSA muscle you build before touching actual problems.

Each function below takes `n` and prints one shape. File: [`pattern.cpp`](./pattern.cpp)

The main goal isn't memorising patterns. It's building **loop-bound intuition** — understanding what `i` controls, what `j` controls, and how expressions like `n - i - 1`, `2 * i + 1`, and `n - i` change the shape.

---

## Pattern 1 — Solid Square

```text
****
****
****
****
```

### Code

```cpp
void print_pattern1(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
```

**Logic:** Both loops run `n + 1` times, so every row has the same number of stars.

---

## Pattern 2 — Right Triangle (Stars)

```text
*
**
***
****
```

### Code

```cpp
void print_pattern2(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
```

**Logic:** `j <= i` means row `i` prints `i + 1` stars.

---

## Pattern 3 — Right Triangle (Increasing Numbers)

```text
1
12
123
1234
```

### Code

```cpp
void print_pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}
```

**Logic:** `j` itself is printed, so every row starts again from `1`.

---

## Pattern 4 — Right Triangle (Repeated Row Number)

```text
1
22
333
4444
```

### Code

```cpp
void print_pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}
```

**Logic:** `i` controls the value, while `j` controls how many times it is printed.

---

## Pattern 5 — Inverted Right Triangle (Stars)

```text
****
***
**
*
```

### Code

```cpp
void print_pattern5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
```

**Logic:** Number of stars is `n - i`.

As `i` increases, the number of stars decreases.

---

## Pattern 6 — Inverted Triangle (Numbers)

```text
1 2 3 4
1 2 3
1 2
1
```

### Code

```cpp
void print_pattern6(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
```

**Logic:** The row width is `n - i + 1`.

---

## Pattern 7 — Pyramid

```text
   *
  ***
 *****
*******
```

### Code

```cpp
void print_pattern7(int n) {
    for (int i = 0; i < n; i++) {

        // spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // stars
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        cout << endl;
    }
}
```

**Important formulas:**

```text
Spaces = n - i - 1
Stars  = 2 * i + 1
```

The spaces decrease while the stars increase.

---

## Pattern 8 — Inverted Pyramid

```text
*******
 *****
  ***
   *
```

### Code

```cpp
void print_pattern8(int n) {
    for (int i = 0; i < n; i++) {

        // spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        // stars
        for (int j = 0; j < ((2 * n) - (2 * i + 1)); j++) {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        cout << endl;
    }
}
```

**Logic:**

```text
Spaces = i
Stars  = 2n - (2i + 1)
```

This is basically Pattern 7 in reverse.

---

## Pattern 9 — Diamond

```text
   *
  ***
 *****
*******
*******
 *****
  ***
   *
```

### Code

```cpp
void print_pattern9(int n) {

    // top half
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }

        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        cout << endl;
    }

    // bottom half
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        for (int j = 0; j < ((2 * n) - (2 * i + 1)); j++) {
            cout << "*";
        }

        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        cout << endl;
    }
}
```

**Logic:** Don't think of a diamond as a completely new pattern.

```text
Diamond = Pyramid + Inverted Pyramid
```

---

## Pattern 10 — Rising & Falling Triangle

```text
*
**
***
****
***
**
*
```

### Code

```cpp
void print_pattern10(int n) {

    for (int i = 1; i <= 2 * n - 1; i++) {

        int star = i;

        if (i > n) {
            star = 2 * n - i;
        }

        for (int j = 1; j <= star; j++) {
            cout << "*";
        }

        cout << endl;
    }
}
```

**Logic:** The number of rows is:

```text
2n - 1
```

Stars increase until `n`, then decrease.

There is **no spacing**, so this is left-aligned rather than a true diamond.

---

## Pattern 11 — Binary Alternating Triangle

```text
1
01
101
0101
```

### Code

```cpp
void print_pattern11(int n) {

    int start = 1;

    for (int i = 0; i < n; i++) {

        if (i % 2 == 0)
            start = 1;
        else
            start = 0;

        for (int j = 0; j <= i; j++) {
            cout << start;
            start = 1 - start;
        }

        cout << endl;
    }
}
```

**Logic:** `start = 1 - start` toggles:

```text
1 → 0 → 1 → 0
```

The starting value changes depending on whether the row index is even or odd.

---

## Pattern 12 — Number Butterfly

```text
1      1
12    21
123  321
12344321
```

### Code

```cpp
void print_pattern12(int n) {

    int space = 2 * (n - 1);

    for (int i = 1; i <= n; i++) {

        // left numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // middle spaces
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }

        // right numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << endl;

        space -= 2;
    }
}
```

**Logic:**

```text
Left  → 1 to i
Gap   → decreases by 2
Right → i to 1
```

---

## Pattern 13 — Continuous Number Triangle

```text
1
2 3
4 5 6
7 8 9 10
```

### Code

```cpp
void print_pattern13(int n) {

    int start = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {
            cout << start << " ";
            start++;
        }

        cout << endl;
    }
}
```

**Important:** `start` is declared **outside both loops**.

Therefore, it doesn't reset after every row.

---

## Pattern 14 — Alphabet Right Triangle

```text
A
AB
ABC
ABCD
```

### Code

```cpp
void print_pattern14(int n) {

    for (int i = 1; i <= n; i++) {

        char start = 'A';

        for (int j = 1; j <= i; j++) {
            cout << start;
            start++;
        }

        cout << endl;
    }
}
```

**Logic:** Every row starts from `A` and prints one additional letter.

---

## Pattern 15 — Inverted Alphabet Triangle

```text
ABCD
ABC
AB
A
```

### Code

```cpp
void print_pattern15(int n) {

    for (int i = 1; i <= n; i++) {

        char start = 'A';

        for (int j = 0; j <= n - i; j++) {
            cout << start;
            start++;
        }

        cout << endl;
    }
}
```

**Logic:** Number of letters:

```text
n - i + 1
```

---

## Pattern 16 — Repeated Letter Triangle

```text
A
B B
C C C
D D D D
```

### Code

```cpp
void print_pattern16(int n) {

    char start = 'A';

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            cout << start << " ";
        }

        cout << endl;
        start++;
    }
}
```

**Logic:** `start` changes only after completing the entire row.

---

## Pattern 17 — Alphabet Pyramid

```text
   A
  ABA
 ABCBA
ABCDCBA
```

### Code

```cpp
void print_pattern17(int n) {

    for (int i = 0; i < n; i++) {

        // spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        char start = 'A';
        int break_point = (2 * i + 1) / 2;

        // letters
        for (int j = 0; j < 2 * i + 1; j++) {

            cout << start;

            if (j < break_point)
                start++;
            else
                start--;
        }

        // spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        cout << endl;
    }
}
```

**Logic:** This combines two ideas:

```text
Pyramid spacing
+
Increasing then decreasing letters
```

For example:

```text
ABCBA
```

The letters go:

```text
A → B → C → B → A
```

---

## Pattern 18 — Reverse Alphabet Run

```text
E
D E
C D E
B C D E
```

### Code

```cpp
void print_pattern18(int n) {

    for (int i = 0; i < n; i++) {

        for (char j = 'E' - i; j <= 'E'; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
}
```

**Logic:** The starting letter moves backwards:

```text
E
D
C
B
```

while the ending letter remains `E`.

---

## Pattern 19 — Full Star Butterfly

```text
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
```

### Code

```cpp
void print_pattern19(int n) {

    int spaces = 0;

    // top half
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i; j++) {
            cout << '*';
        }

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++) {
            cout << '*';
        }

        spaces += 2;

        cout << endl;
    }

    // bottom half
    int spaces2 = 2 * (n - 1);

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {
            cout << '*';
        }

        for (int j = 0; j < spaces2; j++) {
            cout << " ";
        }

        for (int j = 0; j < i; j++) {
            cout << '*';
        }

        spaces2 -= 2;

        cout << endl;
    }
}
```

**Logic:**

Top half:

```text
stars ↓
spaces ↑
```

Bottom half:

```text
stars ↑
spaces ↓
```

---

## Pattern 20 — Star Sandglass / Hollow Hourglass

```text
*     *
**   **
*** ***
**   **
*     *
```

### Code

```cpp
void print_pattern20(int n) {

    int spaces = 2 * n - 1;

    for (int i = 1; i <= 2 * n - 1; i++) {

        int stars = i;

        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << endl;

        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}
```

**Logic:** The star count rises and then falls, while the middle gap does the opposite.

---

## Pattern 21 — Hollow Square

```text
****
*  *
*  *
****
```

### Code

```cpp
void print_pattern21(int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i == 0 ||
                j == 0 ||
                i == n - 1 ||
                j == n - 1) {

                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        cout << endl;
    }
}
```

**Logic:** Print `*` only when the current cell lies on the border.

```text
first row
last row
first column
last column
```

Everything else becomes a space.

---

## Pattern 22 — Concentric Number Square

For `n = 3`:

```text
33333
32223
32123
32223
33333
```

### Code

```cpp
void print_pattern22(int n) {

    for (int i = 0; i < 2 * n - 1; i++) {

        for (int j = 0; j < 2 * n - 1; j++) {

            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;

            cout << (
                n - min(
                    min(top, down),
                    min(left, right)
                )
            );
        }

        cout << endl;
    }
}
```

**Logic:** This pattern is different from the others.

Instead of thinking row-by-row, think about **each cell's distance from the nearest edge**.

```text
distance to top
distance to bottom
distance to left
distance to right
```

Take the minimum distance and subtract it from `n`.

---

# 💡 Notes to Self

### 1. `i` usually controls the row

```cpp
for (int i = 0; i < n; i++)
```

Think:

```text
i = current row
```

### 2. `j` usually controls what happens inside that row

```cpp
for (int j = 0; j < something; j++)
```

Think:

```text
j = current position / column
```

### 3. The important formulas

```text
Increasing stars:
    i + 1

Decreasing stars:
    n - i

Pyramid spaces:
    n - i - 1

Pyramid stars:
    2 * i + 1

Inverted pyramid stars:
    2 * n - (2 * i + 1)
```

### 4. The `n - i - 1` pattern

This appears constantly in centered patterns:

```cpp
for (int j = 0; j < n - i - 1; j++)
```

As `i` increases:

```text
i = 0 → n - 1 spaces
i = 1 → n - 2 spaces
i = 2 → n - 3 spaces
...
```

So the shape gradually moves toward the center.

### 5. The `2 * i + 1` pattern

For pyramids:

```cpp
for (int j = 0; j < 2 * i + 1; j++)
```

The number of stars becomes:

```text
i = 0 → 1
i = 1 → 3
i = 2 → 5
i = 3 → 7
```

So every row adds **2 more characters**.

### 6. The `n - i` pattern

For inverted patterns:

```cpp
for (int j = 0; j < n - i; j++)
```

The number of characters becomes:

```text
i = 0 → n
i = 1 → n - 1
i = 2 → n - 2
...
```

So every row loses **one character**.

### 7. Patterns worth revisiting

**Patterns 7–9, 17, 19, 20 and 22** are the most useful for developing loop-bound intuition.

They introduce:

```text
spacing
symmetry
increasing/decreasing bounds
mirroring
state variables
cell-distance calculations
```

These ideas come back later in matrix problems, two pointers, sliding windows, and other DSA patterns.

---

# 🚀 The Real Goal

Pattern printing isn't really about printing stars.

It's about looking at:

```cpp
for (int j = 0; j < n - i - 1; j++)
```

and immediately understanding:

> "The number of iterations decreases by one every row."

Or seeing:

```cpp
for (int j = 0; j < 2 * i + 1; j++)
```

and knowing:

> "The number of characters increases by two every row."

Once you can predict the output **before running the code**, you've built the loop-bound intuition these exercises are meant to teach.