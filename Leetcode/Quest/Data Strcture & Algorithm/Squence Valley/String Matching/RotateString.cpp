// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};

int main() {
    Solution sol;
    string s = "abcde", goal = "cdeab";
    cout << "Result: " << sol.rotateString(s, goal) << endl;
    return 0;
}