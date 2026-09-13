

#include<iostream>
using namespace std;
 
// print name n times using recursion
void f(int i, int n){
    if(i>n) return;
    cout<<"Gyan"<<endl;
    f(i+1,n);
}
 
int main(){
    int n;
    cin >> n;
 
    f(1, n);
 
    return 0;
}
// time complexity o(n)
// space complexity o(n)
 
