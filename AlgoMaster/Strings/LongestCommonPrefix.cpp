// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string ans = "";
        string first = strs[0], last = strs[n - 1];

        for(int i = 0;i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]) return ans;
            ans += first[i];
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << "Longest Common Prefix : " << s.longestCommonPrefix(strs) << endl;
    return 0;
}