
Basic math · CPP
// Number of Digits
 
#include <iostream> 
int countDigit(long long x) {
    int count = 0 ;
    while(x>0){
 
        count += 1;
 
        x = x/10 ;
 
    }
 
 
    return count ;
}
 
// method 2 
int countDigit(long long x) {
    int count = (int)(log10(x)+1);
    return count;
 
    return count ;
}
 
 
// Reverse a number 
 
#include<iostream>
using namespace std;
 
int main() {
	int n ;
	cin >> n ;
 
	int revn = 0;
 
	while(n>0){
		int last_digit = n%10;
		n = n /10;
		revn = (revn*10)+last_digit;
	}
 
	cout << revn;
	
}
 
// palindrome number 
 
 
 
bool palindrome(int n)
{
    int rev = 0;
    int og = n;
 
    while(og>0){
 
        int last_digit = og%10;
        og = og/10;
        rev = (rev*10)+last_digit;
    }
 
    return rev == n ;
}
 
// armstrong number
using namespace std;
 
bool isArmstrong(int num) {
    int arm = 0;
    int og = num;
 
 
    int digits = 0;
    int temp = num;
 
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
 
 
    temp = num;
 
    while (temp > 0) {
        int last_digit = temp % 10;
        temp /= 10;
 
        arm += pow(last_digit, digits);
    }
 
    return arm == og;
}
 
// divisors of a number
 
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
 
// method 2
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
 
 
// Check prime 
bool isPrime(int n)
{
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
 
// GCD
int gcd(int a , int b){
    while(a >0 && b >0){
        if(a>b){
            a = a % b;
        }
        else {
            b = b % a;
        }
        
    }
 
    if(a==0) return b;
    else return a;
}
 
