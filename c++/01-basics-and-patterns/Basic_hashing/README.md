<div align="center">

# Hashing Basics

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sheet](https://img.shields.io/badge/Sheet-Striver's%20A2Z-6A0DAD?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Hashing-B19CD9?style=for-the-badge)

</div>

Notes on hashing, the four ways to count how many times something appears (array hashing, character hashing, map, unordered map), and when to pick which one. File: [`hashing.cpp`](./hashing.cpp)

---

## What is hashing

Hashing means storing information in advance so that you can look it up fast later, instead of searching for it again every time.

The most common use is counting frequency. Say you have an array and you get many questions like "how many times does 3 appear?". There are two ways to answer:

- **Brute force:** for every question, loop through the whole array and count. That is O(n) per question. With `q` questions, it becomes O(n * q), which is too slow when both are large.
- **Hashing:** loop through the array once at the start, store the count of every element, then answer each question by just looking it up. Work done in advance is called **precomputation**.

Every example below follows the same three steps: precompute, then for each query, fetch the answer.

A few words you will see:
- **Key:** the thing you are counting (like the number 3).
- **Value:** how many times it appeared.
- **Hash function:** the rule that decides where a key gets stored. In array hashing the rule is simply "use the number itself as the index".
- **Collision:** when two different keys end up wanting the same storage spot. Array hashing and character hashing never have this problem, but the map versions handle it internally.

---

## Example used in the notes

To keep things easy to follow, all examples use this input:

```
array   = [1, 3, 2, 1, 3]
queries = 1, 4, 2
```

Expected answers: `1` appears 2 times, `4` appears 0 times, `2` appears 1 time.

---

## 1. Array Hashing (Number Hashing)

Use the number itself as an index into an array, and store the count at that index.

```cpp
int main(){
    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i<n;i++){
        cin>> arr[i];
    }

    // precomputation
    int hash[13] = {};

    for(int i = 0 ; i<n; i++){
        hash[arr[i]] +=1 ;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number ;
        // fetch
        cout << hash[number] << endl;
    }
    return 0 ;
}
```

**What each part does:**
- `int hash[13] = {};` makes an array of 13 slots, all set to 0. Slot 0 to 12, so this only works when every number in the input is between 0 and 12.
- `hash[arr[i]] += 1;` reads each number and adds one to its slot. If the number is 3, slot 3 goes up by 1.
- `cout << hash[number];` answers a query by just reading that slot.

**Tracing it with the example:**

```
start:            hash = [0, 0, 0, 0, ...]
read 1  ->        hash[1] = 1
read 3  ->        hash[3] = 1
read 2  ->        hash[2] = 1
read 1  ->        hash[1] = 2
read 3  ->        hash[3] = 2

final:            hash[1] = 2, hash[2] = 1, hash[3] = 2, everything else 0

query 1 -> prints 2
query 4 -> prints 0
query 2 -> prints 1
```

**Time complexity:** precomputation is O(n), each query is O(1). Total O(n + q).

**Space complexity:** O(largest value), because the array has to be big enough to reach the biggest number.

**Watch out:** if a number is bigger than the array size (say 20 in a size 13 array), it writes outside the array and can crash or give garbage. Array hashing only works when you know the maximum value is small.

---

## 2. Character Hashing

Same idea, but the keys are characters. Every character has a number behind it (its ASCII value), so a character can be used directly as an index.

```cpp
int main(){
    string s;
    cin >> s;

    // precomputations
    int hash[256] = {0};
    for(int i= 0;i<s.size();i++){
        hash[s[i]] += 1 ;
    }

    int q ;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout<< hash[c] << endl;
    }

    return 0;
}
```

**What each part does:**
- `int hash[256]` has one slot for every possible character. There are only 256 characters in total, so the size is small and fixed, which is why there is no size problem here.
- `hash[s[i]] += 1;` uses the character as the index. For `'a'`, the index is 97.
- `hash[c]` answers a query for character `c`.

**Tracing it with s = "abcdabc":**

```
after precomputation:  hash['a'] = 2, hash['b'] = 2, hash['c'] = 2, hash['d'] = 1

query 'a' -> prints 2
query 'd' -> prints 1
query 'z' -> prints 0
```

**Time complexity:** O(n) to precompute, O(1) per query.

**Space complexity:** O(256), which is a constant, so effectively O(1).

**Small tip:** if the string is only lowercase letters, you can use `hash[26]` and index with `s[i] - 'a'` to save space. The 256 version is the safe choice when you are not sure what characters will show up.

---

## 3. Map

Array hashing breaks down when numbers are huge (like 10^9) because you cannot make an array that big. A `map` solves that, since it only stores keys that actually appear.

```cpp
int main(){
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>> arr[i];
    }
    // pre computation
    map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]] += 1;
    }
    // iteration in the map
    for(auto it : mpp){
        cout<< it.first<<"->" << it.second<< endl;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin >> number;
        // fetching
        cout << mpp[number]<< endl;
    }
    return 0;
}
```

**What each part does:**
- `map<int,int> mpp;` is a collection of key and value pairs. Key is the number, value is its count.
- `mpp[arr[i]] += 1;` if the key is new, the map creates it with value 0 first, then adds 1. So no separate "does it exist" check is needed.
- `for(auto it : mpp)` walks through every pair. `it.first` is the key, `it.second` is the value.
- `mpp[number]` fetches the count for a query.

**Tracing it with the example:** iterating prints the keys in sorted order, because a `map` always keeps keys sorted.

```
1->2
2->1
3->2
```

Then the queries print `2`, `0`, `1`.

**Time complexity:** O(log n) for each store and each fetch, so O((n + q) log n) overall.

**Space complexity:** O(number of different keys).

**Watch out:** `mpp[number]` on a key that does not exist quietly adds that key with value 0. In the query loop above, asking for `4` actually inserts `4->0` into the map. That is harmless here, but it makes the map grow, so use `mpp.find(number)` if you want to check without inserting.

---

## 4. Unordered Map

Works exactly like `map`, but does not keep the keys sorted, and in return it is faster.

```cpp
int main(){
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>> arr[i];
    }
    // pre computation
    unordered_map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]] += 1;
    }
    // iteration in the map
    for(auto it : mpp){
        cout<< it.first<<"->" << it.second<< endl;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin >> number;
        // fetching
        cout << mpp[number]<< endl;
    }
    return 0;
}
```

The code is the same as the map version, only the type changed from `map` to `unordered_map`.

**Tracing it with the example:** the pairs are all there, but the order is not guaranteed. Running it on one machine printed:

```
2->1
3->2
1->2
```

Your machine may print a different order. The queries still print `2`, `0`, `1`.

**Time complexity:** O(1) on average for each store and fetch. Worst case is O(n) per operation.

**Space complexity:** O(number of different keys).

**Why is there a worst case?** Internally it uses a hash function to decide where each key goes. If many different keys land in the same spot (a collision), they pile up and the lookup slows down. That is rare in normal use.

---

## Comparison

| Method | Store and fetch | Keys sorted | Works for large values | Best for |
|---|---|---|---|---|
| Array hashing | O(1) | Yes, by index | No, needs small range | Small numbers, known max |
| Character hashing | O(1) | Yes, by index | Not needed | Strings, letter counting |
| `map` | O(log n) | Yes | Yes | When sorted order matters, or as a safe fallback |
| `unordered_map` | O(1) average, O(n) worst | No | Yes | Default choice for large or unknown values |

---

## Array size limits

- Inside `main()`, an array can safely go up to about 10^6 elements. Bigger than that and the program can crash with a segmentation fault, because local variables live on the stack, which has limited space.
- Declared globally (outside `main()`), an array can go up to about 10^7, because global variables live in a different, larger memory area.
- So if array hashing needs a big array, declare it globally.

---

## Notes to self

- First choice is `unordered_map`. If a problem gives Time Limit Exceeded because of it, switch to the regular `map`, since its O(log n) is guaranteed and does not have the bad worst case.
- Character hashing has no size trouble at all, since there are only 256 possible characters.
- Always do the precomputation before answering queries. Doing the counting inside the query loop would bring back the slow O(n * q) brute force.
- `int arr[n]` with a size taken from input (used in the code above) works in g++ but is not standard C++. `vector<int> arr(n)` is the safer habit.
- Hashing is the base idea behind many later problems, like two sum, longest subarray with a given sum, and finding duplicates.

---

<div align="center">

*Learning in public, one frequency count at a time.*

</div>