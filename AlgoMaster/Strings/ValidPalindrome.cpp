// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a palindrome, or false otherwise.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filter = "";
        for(char ch : s){
            if(isalnum(ch)) filter += tolower(ch);
        }

        int left = 0, right = filter.size() - 1;
        while(left < right){
            if(filter[left++] != filter[right--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << s << " is a palindrome? => " << (sol.isPalindrome(s) ? "True" : "False") << endl;
    return 0;
}