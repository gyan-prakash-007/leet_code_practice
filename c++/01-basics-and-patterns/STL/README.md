# C++ STL Notes

Quick reference notes on the STL containers and functions I use the most, following Striver's A2Z Sheet. Each topic below is its own block with a short explanation and an example. File: [`stl_notes.cpp`](./stl_notes.cpp)

Most functions in the file are just for practice and reference, they are not called from `main()`. The point here is to remember syntax fast, not to run the whole file top to bottom.

---

## Pair

A pair holds two values together, `first` and `second`. Useful when you need to store two related things as one unit, like a coordinate or a key with a value.

```cpp
pair<int, int> p = {1, 3};
cout << p.first << " " << p.second; // 1 3
```

You can also nest a pair inside another pair:

```cpp
pair<int, pair<int, int>> q = {1, {3, 4}};
cout << q.second.first; // 3
```

---

## Vector

A vector is a dynamic array. It grows automatically and lets you access any element by index in O(1) time.

```cpp
vector<int> v;
v.push_back(1);
v.emplace_back(2);
cout << v[0]; // 1
```

Some common vector operations:

```cpp
vector<int> v(5, 100);   // 5 elements, all set to 100
v.erase(v.begin() + 1);  // remove element at index 1
v.insert(v.begin(), 50); // insert 50 at the start
v.size();                // number of elements
v.clear();               // empty the vector
```

`emplace_back` is generally a bit faster than `push_back` since it builds the element in place instead of copying it.

---

## List

A list is a doubly linked list. Unlike a vector, it does not support direct indexing, but inserting or removing elements anywhere is fast.

```cpp
list<int> ls;
ls.push_back(2);
ls.push_front(1);
// ls is now {1, 2}
```

Use a list when you are doing a lot of insertions and deletions in the middle of the sequence, and a vector when you need fast random access.

---

## Deque

A deque (double ended queue) lets you push and pop from both the front and the back in O(1) time, while still giving you random access like a vector.

```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
// dq is now {2, 1}

dq.pop_back();
dq.pop_front();
```

---

## Stack

A stack follows LIFO, last in first out. You can only access the top element.

```cpp
stack<int> st;
st.push(1);
st.push(2);
cout << st.top(); // 2
st.pop();
cout << st.top(); // 1
```

---

## Queue

A queue follows FIFO, first in first out. You add at the back and remove from the front.

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.front(); // 1
q.pop();
cout << q.front(); // 2
```

---

## Priority Queue

A priority queue (heap) always keeps the biggest (or smallest) element on top. By default it is a max heap.

```cpp
priority_queue<int> pq;
pq.push(5);
pq.push(10);
pq.push(2);
cout << pq.top(); // 10
```

For a min heap, pass `greater<int>` as the comparator:

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(5);
minHeap.push(2);
cout << minHeap.top(); // 2
```

---

## Set

A set stores unique elements in sorted order automatically. Duplicate inserts are just ignored.

```cpp
set<int> st;
st.insert(3);
st.insert(1);
st.insert(3); // ignored, 3 is already there
// st is now {1, 3}
```

Finding and erasing:

```cpp
auto it = st.find(3); // iterator to 3, or st.end() if not found
st.erase(3);          // erase by value
```

---

## Multiset

Same as a set, but duplicate values are allowed.

```cpp
multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(1);
// ms is now {1, 1, 1}

ms.erase(1);          // erases ALL occurrences of 1
ms.erase(ms.find(1)); // erases just ONE occurrence
```

---

## Unordered Set

Same idea as a set (unique values only), but there is no sorting, and most operations run in O(1) on average instead of O(log n).

```cpp
unordered_set<int> st;
st.insert(5);
st.insert(2);
// order is not guaranteed here
```

Use a set when you need sorted order or `lower_bound` / `upper_bound`, and unordered_set when you just need fast lookups and don't care about order.

---

## Map

A map stores key value pairs with unique keys, sorted by key automatically.

```cpp
map<int, int> mpp;
mpp[1] = 10;
mpp.emplace(2, 20);
mpp.insert({3, 30});

for (auto it : mpp) {
    cout << it.first << " " << it.second << endl;
}
```

Looking things up:

```cpp
auto it = mpp.find(2);
cout << it->second; // 20

cout << mpp[5]; // key 5 does not exist, this adds it with value 0 and prints 0
```

---

## Multimap

Same as a map, but keys can repeat. One difference is you cannot use `mpp[key]` style access here like you can with map.

---

## Unordered Map

Same idea as map (key value pairs), but no sorting and operations are O(1) on average instead of O(log n). Good when you just need fast key lookups.

---

## Useful Algorithm Functions

A few functions from `<algorithm>` that come up constantly:

```cpp
sort(a, a + n);                    // sort ascending
sort(a, a + n, greater<int>());    // sort descending

int cnt = __builtin_popcount(7);   // count of set bits (1s) in 7 -> 3

int maxi = *max_element(a, a + n); // largest element in range
int mini = *min_element(a, a + n); // smallest element in range

string s = "123";
do {
    cout << s << endl;
} while (next_permutation(s.begin(), s.end())); // prints every permutation, string must start sorted
```

You can also sort with your own comparator function when the default ordering is not enough, for example sorting a list of pairs by a custom rule.

---

## Notes to self

- Vector for random access, list for lots of middle insertions/deletions, deque when you need both ends fast.
- Set and map keep things sorted automatically, unordered versions trade that sorting for speed.
- `emplace` builds the element in place and is usually a little faster than `insert` or `push`, but `insert` is sometimes needed when you already have a ready made pair or object.
- Multiset and multimap are just the "allow duplicates" versions of set and map.