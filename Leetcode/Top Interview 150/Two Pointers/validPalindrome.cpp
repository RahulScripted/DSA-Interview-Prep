// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a palindrome, or false otherwise.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for(char ch : s){
            if(isalnum(ch)) filtered += tolower(ch);
        }

        int left = 0, right = filtered.size() - 1;
        while(left < right){
            if(filtered[left] != filtered[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    if(sol.isPalindrome(s)) cout << "\"" << s << "\" is a palindrome." << endl;
    else cout << "\"" << s << "\" is not a palindrome." << endl;

    return 0;
}