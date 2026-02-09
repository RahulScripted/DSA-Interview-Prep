// Given an integer x, return true if x is a palindrome, and false otherwise.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int number = x, palindrome = 0;
        while(number){
            int digit = (number % 10);
            if(palindrome > (INT_MAX / 10)) return false;
            palindrome = palindrome * 10 + digit;
            number /= 10;
        } 

        return x == palindrome;
    }
};

int main(){
    Solution sol;
    int x = 121;
    cout << "Is Palindrome? " << (sol.isPalindrome(x) ? "Yes" : "No") << endl;
}