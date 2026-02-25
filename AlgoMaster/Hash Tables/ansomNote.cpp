// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26);
        for (const char c : magazine) ++count[c - 'a'];

        for (const char c : ransomNote) {
            if (count[c - 'a'] == 0) return false;
            --count[c - 'a'];
        }
        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "a", magazine = "b";
    cout << "Result: " << (sol.canConstruct(ransomNote, magazine) ? "True" : "False") << endl;
}