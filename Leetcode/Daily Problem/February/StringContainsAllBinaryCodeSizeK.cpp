// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for (int i = 0; i + k <= s.size(); i++) st.insert(s.substr(i, k));
        return st.size() == (int)pow(2, k);
    }
};

int main() {
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << "Output: " << sol.hasAllCodes(s, k) << endl;
    return 0;
}