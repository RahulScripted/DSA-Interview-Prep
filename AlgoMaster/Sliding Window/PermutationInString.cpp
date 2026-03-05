// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise. In other words, return true if one of s1's permutations is the substring of s2.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26);
        int required = s1.length();

        for (const char c : s1) ++count[c - 'a'];

        for (int l = 0, r = 0; r < s2.length(); ++r) {
            if (--count[s2[r] - 'a'] >= 0) --required;
            while (required == 0) {
                if (r - l + 1 == s1.length()) return true;
                if (++count[s2[l++] - 'a'] > 0) ++required;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";
    cout << "Is " << s1 << " a permutation of " << s2 << "? " << (sol.checkInclusion(s1, s2) ? "Yes" : "No") << endl;
    return 0;
}