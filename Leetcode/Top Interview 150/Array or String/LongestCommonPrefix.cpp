// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() - 1;
        sort(strs.begin(), strs.end());

        string first = strs[0], last = strs[n];
        string result = "";
        for(int i = 0;i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]) return result;
            result += first[i];
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << "Longest common prefix : " << sol.longestCommonPrefix(strs);
}