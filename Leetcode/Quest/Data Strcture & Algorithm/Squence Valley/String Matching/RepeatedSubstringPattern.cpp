// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string concatenated = s + s;
        return concatenated.substr(1, concatenated.length() - 2).find(s) != string::npos;
    }
};

int main() {
    Solution solution;
    string s = "abcabc";
    bool result = solution.repeatedSubstringPattern(s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}