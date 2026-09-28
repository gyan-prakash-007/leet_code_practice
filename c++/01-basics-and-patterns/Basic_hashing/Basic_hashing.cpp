#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

// unordered map hashing
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
} // time complexity is o(1), worst case o(n)

// inside main you can only declare an array of size 10^6 else segmentation fault
// if declared globally then till 10^7
// there is no complication in character hashing as there are only 256 characters

// first preference is unordered_map, if time limit exceeds then use regular map