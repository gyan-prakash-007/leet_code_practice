<div align="center">

# 🟣 Basic Math

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sheet](https://img.shields.io/badge/Sheet-Striver's%20A2Z-6A0DAD?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Basic%20Math-B19CD9?style=for-the-badge)

</div>

Basic math problems from Striver's A2Z Sheet. These are the small building blocks (digits, reversing, primes, GCD) that show up again and again in bigger problems later. File: [`basic_math.cpp`](./basic_math.cpp)

---

## Number of Digits

**Problem link:** https://www.naukri.com/code360/problems/number-of-digits_4538242

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

---

## Reverse a Number

**Problem link:** https://www.naukri.com/code360/problems/reverse-of-a-number_624652

Pull out the last digit of the number one at a time, and build the reversed number by shifting it left and adding that digit.

```cpp
int revn = 0;
while (n > 0) {
    int last_digit = n % 10;
    n = n / 10;
    revn = (revn * 10) + last_digit;
}
```

---

## Palindrome Number

**Problem link:** https://www.naukri.com/code360/problems/palindrome-number_624662

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

---

## Armstrong Number

**Problem link:** https://www.naukri.com/code360/problems/armstrong-number_1462443

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

---

## Divisors of a Number

**Problem link:** https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188

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

---

## Check Prime

**Problem link:** https://www.naukri.com/code360/problems/check-prime_624934

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

---

<div align="center">

*🟣 Learning in public, one basic math problem at a time.*

</div>