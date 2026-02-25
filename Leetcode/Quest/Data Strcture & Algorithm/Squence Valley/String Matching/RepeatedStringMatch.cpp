// Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible b to be a substring of a after repeating it, return -1.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        const int n = ceil((double)b.length() / a.length());
        string s;
        
        for (int i = 0; i < n; ++i) s += a;
        if (s.find(b) != string::npos) return n;
        if ((s + a).find(b) != string::npos) return n + 1;
        return -1;
    }
};

int main() {
    Solution sol;
    string a = "abcd", b = "cdabcdab";
    cout << "Minimum number of repetitions required: " << sol.repeatedStringMatch(a, b) << endl;
    return 0;
}