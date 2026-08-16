/*
    C++ STL Notes — Striver's A2Z Sheet
    -------------------------------------
    Notes on the STL containers I use most: pair, vector, list, deque,
    stack, queue, priority_queue, set, multiset, unordered_set, map,
    multimap, unordered_map, and a few algorithm functions.

    Most of these functions are just for reference, not called from
    main(). Point is to remember the syntax, not to actually run them.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <utility>
#include <cmath>
#include <numeric>
#include <tuple>
#include <list>


using namespace std;

// function with no return type 
void print(){
    cout << "gyan";
}
// function with return type 
int sum(int a , int b){
    return a+b;
}

// pair 
void explainPair(){
    pair<int, int> p ={1,3};
    cout << p.first << " " << p.second;

    // a pair can have another pair as its second value too
    pair<int, pair<int, int>> q = {1,{3,4}};
    cout << q.first << " " << q.second.second << q.second.first; // to reach the inner pair use q.second.first / q.second.second

    // array of pairs works the same way, just index normally then use .first / .second
    pair<int, int> arr[] = {{1,2},{2,5},{5,6}};
    cout << arr[1].second;

}

// vectors 
void explainVector(){
    vector<int> v; // creates an empty container 
    v.push_back(1); // push 1 into the empty vector  
    v.emplace_back(2);// dynamically increase the size of vector and put two in it, generally emplace_back is faster than push_back

    vector<pair<int,int>> vec; // vector of pair

    vec.push_back({1,2});// need to put the {} to identify the elements as pair
    vec.emplace_back(1,2);// no need for the {}

    // other ways to make a vector (kept as comments, not real code — writing
    // `vector<int> v(...)` again here would redeclare v and break the build)
    // vector<int> v(5, 100);  -> 5 elements, all set to 100: {100,100,100,100,100}
    // vector<int> v(5);       -> 5 elements, all default 0

    vector<int> v1(5,20);
    vector<int> v2(v1); // create a copy of v1
    // can access the elements in a vector using indexing 
    cout << v[0];

    // iterators 
    // assume v = {20,10,15,6,7} for this section
    vector<int>::iterator it= v.begin();// iterator it is set to the memory address of the first element of the vector 

    it++ ;// move iterator forward
    cout<< *(it)<< " "; //prints 10
    //* is used to access the data stored at a particular memory address
     
    it = it+2;
    cout << *(it) << " "; // print 6

    // other iterator positions (kept as comments, writing `it` again here
    // would redeclare it and break the build)
    // v.end()    -> just after the last element
    // v.rbegin() -> points to the last element, ++ moves backward
    // v.rend()   -> just before the first element
    // (note: v.begin() does NOT point to the last element, that was a typo
    // in my old comment — that description is actually for v.rbegin())

    cout << v.back() << " "; // print the last element of the vector 

    // looping through a vector 
    // (each loop below makes its own `it`, so no clash with the `it` above)

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    } // auto means automatic type deduction

    for(auto it : v){
        cout << it << " ";
    }// for-each loop — here `it` is the element itself, not an iterator 

    // deleting elements from a vector 

    v.erase(v.begin()+1);// argument passed to erase() is an iterator 

    // deleting multiple elements 
    v.erase(v.begin() + 2,v.begin() + 4) ;// deletes elements in range [from, upto) — upto not included

    // Insertion functions 
    vector<int>(2,100); //{100,100} — temporary vector, not stored anywhere
    v.insert(v.begin(),100); // inserts 100 at the start of the vector 
    v.insert(v.begin()+1,2,10); // inserts two 10s starting at index 1

    vector<int> copy(2,50); //{50,50}
    v.insert(v.begin(),copy.begin(),copy.end());// inserts all of copy at the start of v

    cout << v.size(); // returns the size of the vector 

    v.pop_back(); // removes the very last element of the vector 

    // example: v1 -> {10,20}, v2 -> {30,40}
    v1.swap(v2);// swaps the entire contents of v1 and v2 -> v1 becomes {30,40}, v2 becomes {10,20}

    v.clear(); // erases the entire vector 

    cout << v.empty(); // returns true if the vector is empty
}

//  a vector is a dynamic array stored in contiguous memory, while std::list is a doubly-linked list stored in non-contiguous memory.

void explainList(){
    list<int> ls; // creates an empty list

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); //{5,2,4}
    
    ls.emplace_front(1); // needed a value here — added 1, so list is now {1,5,2,4}

    // rest function are same as vectors
    // begin, end, rbegin, rend, clear, insert, size, swap 

}

// std::list is a doubly-linked list providing constant-time insertion anywhere but no random access, while std::deque is a double-ended queue implemented via a directory of small arrays, providing fast O(1) random access and fast insertion at both ends

void explainDeque(){

    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    // rest functions same as vector 
    // begin, end, rbegin, rend, clear, insert, size, swap

}

void explainStack(){
    stack<int> st;
    st.push(1); // {1}
    st.push(2);// {2,1}
    st.push(3);// {3,2,1}
    st.push(3);// {3,3,2,1}
    st.emplace(5);// {5,3,3,2,1}

    cout << st.top(); // print 5 " indicing do not work on stack will throw error"

    st.pop(); //  remove and print item 5 {3,3,2,1}

    cout << st.top(); // 3
    cout << st.size(); // 4

    cout << st.empty();

    stack<int>st1, st2;
    st1.swap(st2);

}

void explainQueue(){
    queue<int> q ;

    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5 ;

    cout << q.back(); // print 9

    // q is {1,2,9}
    cout<< q.front(); 

    q.pop(); //{2,9}

    cout << q.front() ; // prints 2 

    // size swap empty same as stack 
}

void explainPQ(){
    priority_queue<int> pq ;

    // max heap
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); //{10,8,5,2}

    cout << pq.top(); // prints 10 

    pq.pop(); // {8,5,2}

    cout << pq.top(); // prints 8

    // size swap and empty finction same as others

    // min heap — using a new name minHeap here, reusing pq would redeclare it
    // with a different type and break the build
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5); // {5}
    minHeap.push(2); // {2,5}
    minHeap.push(8); // {2,5,8}
    minHeap.emplace(10); //{2,5,8,10}

    cout << minHeap.top(); // prints 2

    // push log(n)
    // top o(1)
    // pop log(n)
}

void explainSet(){
    //an associative container that stores unique elements following a strict weak ordering (automatically sorted in ascending order by default

    set<int> st;

    st.insert(1); // {1}
    st.emplace(2); //{1,2}
    st.insert(2);// {1,2}
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4} 

    // begin() , end(), rbegin(), rend(), size() , empty(), and swap() sane as others 

    //{1, 2, 3, 4, 5}

    auto it = st.find(3); // returns an iterator which points to 3

    auto itNotFound = st.find(6); // renamed so it doesn't clash with `it` above — if not found, find() gives back st.end()

    st.erase(5); // delete 5 and maintain the sorted order 

    int cnt = st.count(1); // return 1 for every exisisting element 

    auto itToErase = st.find(3); // renamed so it doesn't clash with `it`
    st.erase(itToErase); // erase by iterator, takes constant time 

    auto it1 = st.find(2);
    auto it2 = st.find(4);

    st.erase(it1,it2); // after erase {1,2,4,5}

    // lower_bound and upper_bound function works in the same way
    // as in vector does 

    auto itLower = st.lower_bound(2); // renamed so it doesn't clash with `it` — first element >= input value
    auto itUpper = st.upper_bound(3); // renamed so it doesn't clash with `it` — first element strictly greater than input value

}

void explainMultiset(){
    //stores elements in a strict sorted order while allowing duplicate values
    multiset<int> ms;
    ms.insert(1);//{1}
    ms.insert(1);//{1,1}
    ms.insert(1);//{1,1,1}

    ms.erase(1); // all ones are erased
    
    int cn = ms.count(1);

    ms.erase(ms.find(1)); // erase one instance of one using iterator 

    ms.erase(ms.find(1), next(ms.find(1), 2)); // multiset iterators can't do +2 like an array —
                                                // use next() to move an iterator forward instead
    // rest of all the functions same as set 
}


void explainUnorderedSet(){
    unordered_set<int> st;
    //std::unordered_set is an associative container that stores unique elements in no particular order.
    // every function same as the set 
    // all operations have o(1)
    // lower_bound and upper_bound do not work 

}

void explainMap(){

    // key value pair 
    // map<key, value>
    // map stores unique keys in sorted (ascending) order by key

    map<int, int> mpp;

    // other map types, kept as separate variables so this actually builds:
    map<int, pair<int, int>> mppPairValue;   // value itself is a pair
    map<pair<int, int>, int> mppPairKey;     // renamed from `map` — naming a variable
                                              // `map` clashes with the std::map type itself

    mpp[1] = 2;
    mpp.emplace(3,1); // emplace needs the key and value separately, not {3,1} as one block
    
    mpp.emplace(2,4); // same reason as above
    mpp.insert({2,4}); // insert() is fine with {2,4} since it just takes a ready-made pair

    // mpp now looks roughly like: { {1,2}, {2,4}, {3,1} }

    mppPairKey[{2,3}] = 10; // this uses the renamed variable now

    for(auto it: mpp){
        cout<< it.first << " "<< it.second<<endl;

    }

    cout << mpp[1]; // prints 2
    cout << mpp[5]; // 5 doesn't exist as a key, so this adds it with value 0 and prints 0

    auto it = mpp.find(3); // returns an iterator for the key 3 
    cout << it->second; // dereference first, then get .second — it->second does both in one go

    auto itNotFound = mpp.find(5); // renamed so it doesn't clash with `it` — if key not found, returns mpp.end()

    auto itLower = mpp.lower_bound(2); // renamed so it doesn't clash with `it`
    auto itUpper = mpp.upper_bound(3); // renamed so it doesn't clash with `it`

    // erase , swap , size , empty . are same as above
}

void explainMultimap(){
    // same as map but contain duplicate keys
    // only map[key] cannot be used here
}

void explainunordered_map(){
    // same as map but keys are in unordered fashion
}

// comparator: sort pairs by second element ascending;
// if second elements are equal, sort by first element descending
bool comp( pair<int,int> p1,  pair<int,int> p2){
 
    if(p1.second < p2.second ) return true;
    if(p1.second > p2.second) return false; // this used to compare p2.second to itself, always false — fixed to check p1 vs p2
    // they are same 
    
    if(p1.first > p2.first) return true;
    return false ;


}

 void explainAlgo(){
    int a[] = {5, 2, 8, 1, 9};   // was using a and n below without declaring them — added a sample array
    int n = size(a);              // number of elements in a[] (C++17 has size() built in)

    sort(a, a + n);// sort(start, upto not including)
    // same idea for a vector: sort(v.begin(), v.end());
    // (my old line here used an undeclared vector `v` and had a typo — comma
    // instead of a dot — so replaced it with just this note)

    sort(a+2, a+4); // sort the 3rd and 4th element 

    sort(a,a+n, greater<int>()); // needed () here — greater<int> alone is just a type, not something callable; sorts descending


    // sorting according to our own comparator 
    pair<int,int> arr[] = {{1,2},{2,1},{4,1}};
    int arrSize = size(arr);

    // sort by second element ascending; if second element is the same,
    // sort by first element descending (see comp() above)
    sort(arr, arr + arrSize, comp); // was sorting `a` (ints) with comp() which expects pairs — switched to `arr`


    int number = 7 ;
    int cnt = __builtin_popcount(number); // was missing the argument — counts the set bits (1's) in `number`

    long long bigNumber = 1234567890; // renamed from `n` so it doesn't clash with the `n` above

    long long cntll = __builtin_popcountll(bigNumber);// was missing the argument and reusing `cnt` — fixed both


    string s  = "123";

    do{
        cout<< s << endl;
    }while (next_permutation(s.begin(),s.end()));// if you want all permutations start with sorted entry 


    int maxi = *max_element(a,a+n); // return max element
    
    int mini = *min_element(a,a+n); // was reusing `maxi` — renamed to `mini`


 }



int main() {
    print();
    cout << endl;
    int s = sum(2,3);
    
    cout << s;
    return 0;
}