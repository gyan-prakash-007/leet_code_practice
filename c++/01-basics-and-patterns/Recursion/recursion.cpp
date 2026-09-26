#include<iostream>
using namespace std;

// print name n times
void f(int i, int n){
    if(i>n) return;
    cout<<"Gyan"<<endl;
    f(i+1,n);
}

// print linearly, 1 to n
void count(int i, int n){
    if(i>n) return ;
    cout << i << endl;
    count(i+1,n); 
}

// print in descending order, n to 1
void count2(int i , int n){
    if(n<i) return ;
    cout << n << endl;
    count2(i,n-1);
}

// backtracking: print 1 to n without ever doing i+1
void count3(int i , int n){
    if(i<1) return ;
    count3(i-1,n);
    cout << i << endl;
}

// backtracking: print n to 1 without ever doing i-1
void count4(int i , int n){
    if(i>n) return;
    count4(i+1,n);
    cout<< i << endl;
}

// sum of n numbers, parameterized way (accumulator passed forward)
void sum1(int i , int sum){
    if(i<1){
        cout << sum << endl;
        return;
    }

    sum1(i-1,sum+i);
}

// sum of n numbers, without an accumulator parameter
int sum2(int n){
    if(n==0){
        return 0 ;
    }
    return n + sum2(n-1);
}

// factorial
int fact(int n ){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

// factorial, parameterized way with a default parameter
void fact2(int i , int n= 1){
    if(i == 1){
        cout<< n << endl; 
        return ;
    }
    fact2(i-1 ,n*i );
}

// reversing an array using recursion
void swapping(int i , int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    swapping(i+1,arr,n);
}

// checking palindrome using recursion
bool palindorme(int i , string &s){
    if(i>=s.size()/2) return true ;
    if(s[i] != s[s.size()-i-1]) return false;

    return palindorme(i+1,s);
}

// nth fibonacci number
int fib(int n){
    if(n<=1){
        return n;
    }
    int last = fib(n-1);
    int slast = fib(n-2);

    return last + slast ;
}

int main(){
    int n= 3;
    cin >> n;

    cout<< fib(n)<< endl;

    int arr[n];
    for(int i = 0;i < n; i++){
        cin >> arr[i];
    }
    swapping(0,arr,n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    string s = "madam";
    cout<< palindorme(0,s)<<endl;
    return 0;
}
// time complexity o(n)
// space complexity o(n)