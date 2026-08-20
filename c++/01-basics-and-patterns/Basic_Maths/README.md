<div align="center">

# 🟣 Basic Math

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sheet](https://img.shields.io/badge/Sheet-Striver's%20A2Z-6A0DAD?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Basic%20Math-B19CD9?style=for-the-badge)

</div>

Basic math problems from Striver's A2Z Sheet. These are the small building blocks (digits, reversing, primes, GCD) that show up again and again in bigger problems later. File: [`basic_math.cpp`](./basic_math.cpp)

---

## Number of Digits

[Problem Link](https://www.naukri.com/code360/problems/number-of-digits_4538242)

Count how many digits a number has.

**Method 1:** keep dividing the number by 10 until it becomes 0, counting each division.

```cpp
int countDigit(long long x) {
    int count = 0;
    while (x > 0) {
        count += 1;
        x = x / 10;
    }
    return count;
}
```

**Method 2:** use `log10`. For any number, `log10(x) + 1` gives the digit count directly, no loop needed.

```cpp
int countDigit(long long x) {
    int count = (int)(log10(x) + 1);
    return count;
}
```

**Time complexity:** Method 1 is O(d) where d is the number of digits. Method 2 is O(1).

**Notes:**
- Method 1 is O(number of digits), method 2 is O(1) but depends on floating point math, which can be slightly off for edge cases like exact powers of 10. Method 1 is safer, method 2 is faster.
- `long long` is used here instead of `int` since digit counting is often tested with really big numbers that overflow a normal int.
- This same loop pattern (pull last digit, divide by 10) shows up in reverse number, palindrome check, and Armstrong number below. Once this clicks, the rest get easier.

---

## Reverse a Number

[Problem Link](https://www.naukri.com/code360/problems/reverse-of-a-number_624652)

Pull out the last digit of the number one at a time, and build the reversed number by shifting it left and adding that digit.

```cpp
int revn = 0;
while (n > 0) {
    int last_digit = n % 10;
    n = n / 10;
    revn = (revn * 10) + last_digit;
}
```

**Time complexity:** O(d) where d is the number of digits in n. Space is O(1).

**Notes:**
- `n % 10` gives the last digit, `n / 10` removes it. This pair of operations is the base building block for a lot of digit manipulation problems.
- Watch out for overflow if the original number is close to the int limit, since the reversed number can end up bigger than expected in some edge cases (like numbers ending in large digits).
- This code lives inside `main()` directly rather than being its own function, so keep that in mind while reading through the file.

---

## Palindrome Number

[Problem Link](https://www.naukri.com/code360/problems/palindrome-number_624662)

A number is a palindrome if it reads the same forwards and backwards, like `121` or `1221`. The check is simple: reverse the number, then compare it to the original.

```cpp
bool palindrome(int n) {
    int rev = 0;
    int og = n;

    while (og > 0) {
        int last_digit = og % 10;
        og = og / 10;
        rev = (rev * 10) + last_digit;
    }

    return rev == n;
}
```

**Time complexity:** O(d) where d is the number of digits in n. Space is O(1).

**Notes:**
- This is basically the reverse-a-number logic wrapped in a comparison. Good example of how the same small building block gets reused across different problems.
- Storing the original value in `og` before modifying `n` is important, otherwise there is nothing left to compare against at the end.
- Negative numbers are not handled here. A negative number is technically never a palindrome (because of the minus sign), so that is worth thinking about if the input can be negative.

---

## Armstrong Number

[Problem Link](https://www.naukri.com/code360/problems/armstrong-number_1462443)

A number is an Armstrong number if the sum of its own digits, each raised to the power of the total digit count, equals the number itself. Example: `153 = 1³ + 5³ + 3³`.

```cpp
bool isArmstrong(int num) {
    int arm = 0;
    int og = num;

    // first, count how many digits the number has
    int digits = 0;
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // then raise each digit to that power and add it up
    temp = num;
    while (temp > 0) {
        int last_digit = temp % 10;
        temp /= 10;
        arm += pow(last_digit, digits);
    }

    return arm == og;
}
```

**Time complexity:** O(d) where d is the number of digits, since there are two passes over the digits, each O(d). Space is O(1).

**Notes:**
- Two separate loops here, first to count digits, then to actually build the sum. The digit count has to be known upfront since it is used as the power in the second loop.
- `pow()` returns a double, so `arm += pow(...)` involves an implicit conversion back to int. Fine for small numbers, but worth knowing this is happening under the hood.
- Classic Armstrong examples to test against: 153, 371, 9474.

---

## Divisors of a Number

[Problem Link](https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188)

Find every number that divides `n` exactly.

**Method 1:** check every number from 1 to n. Simple, but O(n), slow for big numbers.

```cpp
int* printDivisors(int n, int &size) {
    size = 0;
    int* ans = new int[n];

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans[size] = i;
            size++;
        }
    }

    return ans;
}
```

**Method 2:** only check up to `sqrt(n)`. Divisors come in pairs (`i` and `n / i`), so once you find one you get the other for free. Much faster, O(sqrt(n)).

```cpp
int* printDivisors(int n, int &size) {
    int* ans = new int[n];
    size = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans[size] = i;
            size++;

            if (i != n / i) {
                ans[size] = n / i;
                size++;
            }
        }
    }
    sort(ans, ans + size);
    return ans;
}
```

**Time complexity:** Method 1 is O(n). Method 2 is O(sqrt(n) log(sqrt(n))) because of the extra sort at the end, or just O(sqrt(n)) if you don't count the sort. Space for both is O(number of divisors).

**Notes:**
- The `i != n / i` check matters most for perfect squares, otherwise the square root itself would get added twice (example: for n = 16, i = 4 and n / i = 4 are the same divisor).
- Method 2 finds divisors out of order (small ones and big ones mixed together), which is why it needs a `sort()` at the end. Method 1 already comes out sorted naturally.
- Both functions return a raw pointer allocated with `new`, so whoever calls this needs to `delete[]` it later to avoid a memory leak. Worth remembering once vectors get used instead of raw arrays.

---

## Check Prime

[Problem Link](https://www.naukri.com/code360/problems/check-prime_624934)

A number is prime if it has exactly two divisors, 1 and itself. This uses the same sqrt(n) divisor-pair trick as above: count divisors up to sqrt(n), and if the total divisor count is exactly 2, it's prime.

```cpp
bool isPrime(int n) {
    int count = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }

    return count == 2;
}
```

**Time complexity:** O(sqrt(n)). Space is O(1).

**Notes:**
- `i * i <= n` does the same job as `i <= sqrt(n)`, but avoids calling `sqrt()` and its floating point rounding issues. Slightly safer version of the same idea.
- 1 is not a prime number, and this function handles that correctly since 1 only has one divisor (itself), so count never reaches 2.
- This same "count divisors up to sqrt(n)" pattern is the backbone for a lot of number theory problems, worth having memorized cold.

---

## GCD (Greatest Common Divisor)

No problem link attached to this one in the original notes.

Keep shrinking the bigger of the two numbers by taking the remainder, until one of them hits 0. Whatever is left is the GCD. This is the classic Euclidean algorithm.

```cpp
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) return b;
    else return a;
}
```

**Time complexity:** O(log(min(a, b))). Space is O(1).

**Notes:**
- The core idea, `gcd(a, b) = gcd(b, a % b)`, comes up again in problems involving fractions, ratios, or simplifying values. Worth remembering as a concept, not just code.
- This version is O(log(min(a, b))), way faster than checking every number up to the smaller value.
- C++17 and later actually has `std::gcd()` built into `<numeric>`, so this is a good one to know how to write by hand, but also good to know it exists as a library function for actual use.

---

<div align="center">

*🟣 Learning in public, one basic math problem at a time.*

</div>