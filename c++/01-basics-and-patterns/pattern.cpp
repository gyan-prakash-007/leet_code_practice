/*
    Pattern Printing — DSA Foundations
    -----------------------------------
    A collection of classic square/triangle/pyramid/diamond/hollow
    patterns built using nested loops. These are the base patterns
    every DSA beginner grinds through before touching real problems —
    the goal is loop-bound intuition: read the `for` conditions and
    predict the shape before running the code.

    Each function takes `n` (size factor) and prints one pattern to
    stdout. See README.md in this folder for sample outputs of every
    pattern.
*/

#include <iostream>

using namespace std;

// Pattern 1: Solid square of stars, (n+1) x (n+1)
// Outer loop -> rows, Inner loop -> columns, both run 0..n inclusive
void print_pattern1(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Pattern 2: Right-angled triangle, stars increase each row
// Row i prints (i + 1) stars -> 1, 2, 3, ... n+1
void print_pattern2(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Pattern 3: Right-angled triangle of increasing numbers
// Row i prints 1, 2, 3, ... i (counting up to current row number)
void print_pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

// Pattern 4: Right-angled triangle, row number repeated
// Row i prints the value `i`, repeated `i` times
void print_pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

// Pattern 5: Inverted right-angled triangle of stars
// Row i prints (n - i) stars -> starts at n, shrinks down to 1
void print_pattern5(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Pattern 6: Inverted triangle of increasing numbers
// Row i prints 1, 2, ... (n - i + 1) -> row width shrinks each time
void print_pattern6(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Pattern 7: Centered pyramid of stars
// Each row = (left spaces) + (stars) + (right spaces)
// Spaces shrink and stars grow symmetrically as i increases
void print_pattern7(int n) {
    for (int i = 0; i < n; i++) {
        // left spacing to center the pyramid
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // stars: grows as 1, 3, 5, 7... (2*i + 1)
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        // right spacing (mirrors left spacing)
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// Pattern 8: Centered inverted pyramid of stars
// Mirror image of pattern 7 — spaces grow, stars shrink
void print_pattern8(int n) {
    for (int i = 0; i < n; i++) {
        // left spacing grows each row
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        // stars shrink as: (2n - 1), (2n - 3), ... down to 1
        for (int j = 0; j < ((2 * n) - (2 * i + 1)); j++) {
            cout << "*";
        }
        // right spacing mirrors left spacing
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// Pattern 9: Full diamond of stars
// Just pattern 7 (pyramid) stacked directly on top of pattern 8 (inverted pyramid)
void print_pattern9(int n) {
    // top half — pyramid (same logic as print_pattern7)
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

    // bottom half — inverted pyramid (same logic as print_pattern8)
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

// Pattern 10: Left-aligned star triangle (rises then falls)
// Runs for (2n - 1) rows. Star count climbs 1 -> n, then falls n -> 1.
// No spacing involved, so it reads as an arrow shape rather than a diamond.
void print_pattern10(int n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
        int star = i;
        if (i > n) {
            star = 2 * n - i;  // mirror the count once past the midpoint
        }
        for (int j = 1; j <= star; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Pattern 11: Binary alternating triangle
// Row i starts with 1 if i is even, 0 if i is odd, then flips the
// digit after every character printed in that row.
void print_pattern11(int n) {
    int start = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) start = 1;
        else start = 0;

        for (int j = 0; j <= i; j++) {
            cout << start;
            start = 1 - start;  // toggle between 0 and 1
        }

        cout << endl;
    }
}

// Pattern 12: Number butterfly (hollow, no stars)
// Left side counts up 1..i, middle gap shrinks by 2 each row,
// right side counts back down i..1 — like pattern 19 but with numbers.
void print_pattern12(int n) {
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++) {
        // ascending numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        // middle gap
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        // descending numbers
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
        space -= 2;  // gap shrinks as the triangle widens
    }
}

// Pattern 13: Continuous number triangle
// Numbers keep counting up across the WHOLE pattern, not resetting per row
// Row i has i numbers, continuing from wherever the last row left off
void print_pattern13(int n) {
    int start = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << start << " ";
            start += 1;
        }
        cout << endl;
    }
}

// Pattern 14: Alphabet right triangle
// Row i prints letters A, B, C... up to the i-th letter
void print_pattern14(int n) {
    for (int i = 1; i <= n; i++) {
        char start = 'A';
        for (int j = 1; j <= i; j++) {
            cout << start;
            start += 1;
        }
        cout << endl;
    }
}

// Pattern 15: Inverted alphabet triangle
// Row i prints (n - i + 1) letters starting from A -> triangle shrinks going down
void print_pattern15(int n) {
    for (int i = 1; i <= n; i++) {
        char start = 'A';
        for (int j = 0; j <= n - i; j++) {
            cout << start;
            start += 1;
        }
        cout << endl;
    }
}

// Pattern 16: Repeated-letter triangle
// Row i prints the i-th letter of the alphabet, repeated i times
void print_pattern16(int n) {
    char start = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << start << " ";
        }
        cout << endl;
        start += 1;  // move to next letter for the next row
    }
}

// Pattern 17: Alphabet pyramid (grows then mirrors back)
// Same shape as pattern 7 (star pyramid), but the middle letters
// climb from A up to a peak, then fall back down to A.
void print_pattern17(int n) {
    for (int i = 0; i < n; i++) {
        // left spacing to center the pyramid
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // letters: climb up to the midpoint of the row, then descend
        char start = 'A';
        int break_point = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << start;
            if (j < break_point) start++;
            else start--;
        }
        // right spacing (mirrors left spacing)
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

// Pattern 18: Reverse alphabet run ending at E
// Row i prints letters from ('E' - i) up to 'E' — each row grows leftward
void print_pattern18(int n) {
    for (int i = 0; i < n; i++) {
        for (char j = 'E' - i; j <= 'E'; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Pattern 19: Full star butterfly
// Two halves: top half (stars shrink, middle gap grows) stacked over
// bottom half (stars grow, middle gap shrinks) — a mirrored hourglass.
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

    // bottom half (mirror of top)
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

// Pattern 20: Star sandglass (hollow hourglass)
// Star count rises then falls (like pattern 10), but each row also has a
// shrinking-then-growing gap in the middle, forming a hollow hourglass/X.
void print_pattern20(int n) {
    int spaces = 2 * n - 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n) stars = 2 * n - i;  // mirror star count past the midpoint

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
        if (i < n) spaces -= 2;   // gap shrinks going into the middle
        else spaces += 2;         // gap grows coming out of the middle
    }
}

// Pattern 21: Hollow square
// Only print '*' on the border (first/last row, first/last column),
// everything else inside is blank space.
void print_pattern21(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Pattern 22: Concentric number square (diamond-in-a-square)
// For every cell, find the distance to the nearest edge (top/bottom/left/right)
// and use that to pick the number — smaller distance = outer ring = bigger number.
void print_pattern22(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            // distance to closest edge decides which "ring" this cell belongs to
            cout << (n - min(min(top, down), min(left, right)));
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;  // number of test cases
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        print_pattern22(n);
        cout << endl;
    }

    return 0;
}