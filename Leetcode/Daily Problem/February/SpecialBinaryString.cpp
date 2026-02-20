// Special binary strings are binary strings with the following two properties:

//     1 - The number of 0's is equal to the number of 1's.
//     2 - Every prefix of the binary string has at least as many 1's as 0's.

// You are given a special binary string s. A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string. Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};

int main(){
    Solution sol;
    string s = "11011000";
    cout<<"Lexicographically largest resulting string : "<<sol.makeLargestSpecial(s);
}