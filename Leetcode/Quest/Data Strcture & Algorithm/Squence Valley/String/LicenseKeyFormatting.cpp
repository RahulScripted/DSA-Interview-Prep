// You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k. We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase. Return the reformatted license key.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int length = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (length > 0 && length % k == 0) ans += "-";
            ans += toupper(s[i]);
            ++length;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "5F3Z-2e-9-w";
    int k = 4;

    cout<<"In License "<<s<<" will be : "<<sol.licenseKeyFormatting(s,k)<<endl;
}