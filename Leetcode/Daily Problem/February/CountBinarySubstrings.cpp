// Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively. Substrings that occur multiple times are counted the number of times they occur.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        const int n = s.size();
        int prev = 0, cur = 1, cnt = 0;
        for(int i = 1; i < n; i++){
            bool same = s[i] == s[i - 1];
            prev = (-same & prev) + (-!same & cur);
            cur = (-same & (cur+1)) + (-!same & 1);
            cnt += cur <= prev;
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    string s = "00110011";
    cout<<"Occurence of substring are  : "<<sol.countBinarySubstrings(s)<<endl;
}