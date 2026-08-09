/*
    Pattern Printing — DSA Foundations
    -----------------------------------
    A collection of classic square/triangle/pyramid/diamond patterns
    built using nested loops. These are the base patterns every DSA
    beginner grinds through before moving to actual problems — the
    goal here is to get comfortable reading loop bounds and predicting
    output shape before writing any code.

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

int main() {
    int t;
    cin >> t;  // number of test cases
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        print_pattern11(n);
        cout << endl;
    }

    return 0;
}
