// Given an integer x, return true if x is a palindrome, and false otherwise.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = x, reverse = 0;
        while(n){
            int digit = n % 10;
            if(reverse > (INT_MAX / 10)) return false;
            reverse = reverse * 10 + digit;
            n /= 10;
        }
        return reverse == x;
    }
};

int main(){
    Solution sol;
    int x = 121;
    cout << "Is " << x << " a Palindrome: " << sol.isPalindrome(x) << endl;

    x = -121;
    cout << "Is " << x << " a Palindrome: " << sol.isPalindrome(x) << endl;
}