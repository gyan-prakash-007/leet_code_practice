// when a function calles itself is called recursion its called recursion.
// until a specific condition is met .
// else segmentation error or stack overflow 
// condion to stop a recursive statement is called base case 

#include<iostream>;
using namespace std;
// int cnt = 0 ;
// void print(){
//     if(cnt==3) return;
//     cout << cnt << endl;
//     cnt ++;
//     print();
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif

//     print();
//     return 0;
// } // draw recursion tree for this code 

// Questions 
// print name n times 
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




